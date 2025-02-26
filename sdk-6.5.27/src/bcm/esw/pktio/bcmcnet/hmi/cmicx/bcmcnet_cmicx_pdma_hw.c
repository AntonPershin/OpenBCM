/*! \file bcmcnet_cmicx_pdma_hw.c
 *
 * Utility routines for handling BCMCNET hardware (CMICx).
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#include <bcmcnet/bcmcnet_core.h>
#include <bcmcnet/bcmcnet_dev.h>
#include <bcmcnet/bcmcnet_rxtx.h>
#include <bcmcnet/bcmcnet_cmicx.h>

/*!
 * Read 32-bit register
 */
static inline void
cmicx_pdma_reg_read32(struct pdma_hw *hw, uint32_t addr, uint32_t *data)
{
    if (hw->dev->dev_read32) {
        hw->dev->dev_read32(hw->dev, addr, data);
    } else {
        DEV_READ32(&hw->dev->ctrl, addr, data);
    }
}

/*!
 * Write 32-bit register
 */
static inline void
cmicx_pdma_reg_write32(struct pdma_hw *hw, uint32_t addr, uint32_t data)
{
    if (hw->dev->dev_write32) {
        hw->dev->dev_write32(hw->dev, addr, data);
    } else {
        DEV_WRITE32(&hw->dev->ctrl, addr, data);
    }
}

/*!
 * Enable interrupt for a channel
 */
static inline void
cmicx_pdma_intr_enable(struct pdma_hw *hw, int cmc, int chan, uint32_t mask)
{
    uint32_t reg, irq_mask;

    hw->dev->ctrl.grp[cmc].irq_mask |= mask;
    irq_mask = hw->dev->ctrl.grp[cmc].irq_mask;
    if (cmc == 0) {
        reg = CMICX_PDMA_IRQ_RAW_STAT0;
    } else {
        if (chan < 4) {
            reg = CMICX_PDMA_IRQ_RAW_STAT1;
            hw->dev->ctrl.grp[cmc].irq_mask <<= CMICX_IRQ_MASK_SHIFT;
        } else {
            reg = CMICX_PDMA_IRQ_RAW_STAT2;
            hw->dev->ctrl.grp[cmc].irq_mask >>= 32 - CMICX_IRQ_MASK_SHIFT;
        }
    }

    hw->dev->intr_unmask(hw->dev, cmc, chan, reg & 0xfff, 0);
    hw->dev->ctrl.grp[cmc].irq_mask = irq_mask;
}

/*!
 * Disable interrupt for a channel
 */
static inline void
cmicx_pdma_intr_disable(struct pdma_hw *hw, int cmc, int chan, uint32_t mask)
{
    uint32_t reg, irq_mask;

    hw->dev->ctrl.grp[cmc].irq_mask &= ~mask;
    irq_mask = hw->dev->ctrl.grp[cmc].irq_mask;
    if (cmc == 0) {
        reg = CMICX_PDMA_IRQ_RAW_STAT0;
    } else {
        if (chan < 4) {
            reg = CMICX_PDMA_IRQ_RAW_STAT1;
            hw->dev->ctrl.grp[cmc].irq_mask <<= CMICX_IRQ_MASK_SHIFT;
        } else {
            reg = CMICX_PDMA_IRQ_RAW_STAT2;
            hw->dev->ctrl.grp[cmc].irq_mask >>= 32 - CMICX_IRQ_MASK_SHIFT;
        }
    }

    hw->dev->intr_mask(hw->dev, cmc, chan, reg & 0xfff, 0);
    hw->dev->ctrl.grp[cmc].irq_mask = irq_mask;
}

/*!
 * Release Packet DMA credits to EP.
 */
static int
cmicx_pdma_credits_release(struct pdma_hw *hw)
{
    int credits;
    uint32_t val;

#if PKTIO_IMPL
    if (hw->warmboot) {
        /*
         * For the credit release behavior of pktio mode, we rely this H/W
         * value to avoid PDMA driver to double release credit.
         * For SDK release before 6.5.23, this value is not programmed to 1.
         * Credit release has been done on coldboot, so we set it to 1 to avoid
         * double credit release.
         */
        hw->hdls.reg_rd32(hw, CMICX_EPINTF_RELEASE_CREDITS, &val);
        if (!val) {
            hw->hdls.reg_wr32(hw, CMICX_EPINTF_RELEASE_CREDITS, 1);
        }
    } else
#endif /* PKTIO_IMPL */
    {
        /*
         * Since only 6 bits of iproc_cmic_to_ep_credits[5:0] are being used,
         * so we have to set the max credits value twice in order to release
         * 64 credits to EP.
         * Only do this once when HW is initialized.
         */
        hw->hdls.reg_rd32(hw, CMICX_EPINTF_RELEASE_CREDITS, &val);
        if (!val) {
            credits = 63;
            hw->hdls.reg_wr32(hw, CMICX_EPINTF_MAX_CREDITS, (0x1 << 8) | credits);
            hw->hdls.reg_wr32(hw, CMICX_EPINTF_RELEASE_CREDITS, 1);

            hw->hdls.reg_wr32(hw, CMICX_EPINTF_RELEASE_CREDITS, 0);
            credits = 1;
            hw->hdls.reg_wr32(hw, CMICX_EPINTF_MAX_CREDITS, (0x1 << 8) | credits);
            hw->hdls.reg_wr32(hw, CMICX_EPINTF_RELEASE_CREDITS, 1);
        }
    }

    return SHR_E_NONE;
}

/*!
 * Initialize HW
 */
static int
cmicx_pdma_hw_init(struct pdma_hw *hw)
{
    dev_mode_t mode = DEV_MODE_MAX;
    uint32_t val;

    /* Temporarily upgrade work mode to get HW information in VNET mode. */
    if (hw->dev->mode == DEV_MODE_VNET) {
        mode = DEV_MODE_VNET;
        hw->dev->mode = DEV_MODE_UNET;
    }

    /* Release Packet DMA credits to EP. */
    cmicx_pdma_credits_release(hw);

    hw->info.name = CMICX_DEV_NAME;
    hw->info.dev_id = hw->dev->dev_id;
    hw->info.num_cmcs = CMICX_PDMA_CMC_MAX;
    hw->info.cmc_chans = CMICX_PDMA_CMC_CHAN;
    hw->info.num_chans = CMICX_PDMA_CMC_MAX * CMICX_PDMA_CMC_CHAN;
    hw->info.rx_dcb_size = CMICX_PDMA_DCB_SIZE;
    hw->info.tx_dcb_size = CMICX_PDMA_DCB_SIZE;
    hw->hdls.reg_rd32(hw, CMICX_EP_TO_CPU_HEADER_SIZE, &val);
    hw->info.rx_ph_size = (val & 0xf) * 8;
    hw->info.tx_ph_size = CMICX_TX_PKT_HDR_SIZE;
    hw->info.intr_start_num = CMICX_IRQ_START_NUM;
    hw->info.intr_num_offset = CMICX_IRQ_NUM_OFFSET;
    hw->info.intr_mask_shift = CMICX_IRQ_MASK_SHIFT;

    /* Restore work mode to VNET. */
    if (mode == DEV_MODE_VNET) {
        hw->dev->mode = DEV_MODE_VNET;
    }

    return SHR_E_NONE;
}

/*!
 * Configure HW
 */
static int
cmicx_pdma_hw_config(struct pdma_hw *hw)
{
    struct dev_ctrl *ctrl = &hw->dev->ctrl;
    struct pdma_rx_queue *rxq = NULL;
    struct pdma_tx_queue *txq = NULL;
    uint32_t val, que_ctrl;
    int grp, que;
    uint32_t qi;
    int ip_if_hdr_endian = 0;

    for (qi = 0; qi < ctrl->nb_rxq; qi++) {
        rxq = (struct pdma_rx_queue *)ctrl->rx_queue[qi];
        grp = rxq->group_id;
        que = rxq->chan_id % CMICX_PDMA_CMC_CHAN;
        que_ctrl = ctrl->grp[grp].que_ctrl[que];

        hw->hdls.reg_wr32(hw, CMICX_PDMA_IRQ_STAT_CLR(grp), CMICX_PDMA_IRQ_MASK(que));
        val = 0;
        if (que_ctrl & PDMA_PKT_BYTE_SWAP) {
            val |= CMICX_PDMA_PKT_BIG_ENDIAN;
        }
        if (que_ctrl & PDMA_OTH_BYTE_SWAP) {
            val |= CMICX_PDMA_DESC_BIG_ENDIAN;
        }
        if (que_ctrl & PDMA_HDR_BYTE_SWAP) {
            val |= CMICX_PDMA_HDR_BIG_ENDIAN;
        }
        if (!(hw->dev->flags & PDMA_CHAIN_MODE)) {
            val |= CMICX_PDMA_CONTINUOUS;
        }
        if (hw->dev->flags & PDMA_DESC_PREFETCH) {
            val |= CMICX_PDMA_CONTINUOUS_DESC;
        }
        val |= CMICX_PDMA_INTR_ON_DESC;
        hw->hdls.reg_wr32(hw, CMICX_PDMA_CTRL(grp, que), val);
    }

    for (qi = 0; qi < ctrl->nb_txq; qi++) {
        txq = (struct pdma_tx_queue *)ctrl->tx_queue[qi];
        grp = txq->group_id;
        que = txq->chan_id % CMICX_PDMA_CMC_CHAN;
        que_ctrl = ctrl->grp[grp].que_ctrl[que];

        hw->hdls.reg_wr32(hw, CMICX_PDMA_IRQ_STAT_CLR(grp), CMICX_PDMA_IRQ_MASK(que));
        val = 0;
        if (que_ctrl & PDMA_PKT_BYTE_SWAP) {
            val |= CMICX_PDMA_PKT_BIG_ENDIAN;
            val |= CMICX_PDMA_HDR_BIG_ENDIAN;
            ip_if_hdr_endian = 1;
        }
        if (que_ctrl & PDMA_OTH_BYTE_SWAP) {
            val |= CMICX_PDMA_DESC_BIG_ENDIAN;
        }
        if (que_ctrl & PDMA_HDR_BYTE_SWAP) {
            ip_if_hdr_endian = 1;
        }
        if (!(hw->dev->flags & PDMA_CHAIN_MODE)) {
            val |= CMICX_PDMA_CONTINUOUS;
        }
        if (hw->dev->flags & PDMA_DESC_PREFETCH) {
            val |= CMICX_PDMA_CONTINUOUS_DESC;
        }
        val |= CMICX_PDMA_INTR_ON_DESC | CMICX_PDMA_DIR;
        hw->hdls.reg_wr32(hw, CMICX_PDMA_CTRL(grp, que), val);
    }
    hw->hdls.reg_rd32(hw, CMICX_TOP_CONFIG, &val);
    if (ip_if_hdr_endian == 1) {
        val |= 0x80;
    } else {
        val &= ~0x80;
    }
    hw->hdls.reg_wr32(hw, CMICX_TOP_CONFIG, val);

    return SHR_E_NONE;
}

/*!
 * Reset HW
 */
static int
cmicx_pdma_hw_reset(struct pdma_hw *hw)
{
    int gi, qi;

    for (gi = 0; gi < hw->dev->num_groups; gi++) {
        if (!hw->dev->ctrl.grp[gi].attached) {
            continue;
        }
        for (qi = 0; qi < CMICX_PDMA_CMC_CHAN; qi++) {
            if (1 << qi & hw->dev->ctrl.grp[gi].bm_rxq ||
                1 << qi & hw->dev->ctrl.grp[gi].bm_txq) {
                hw->hdls.reg_wr32(hw, CMICX_PDMA_CTRL(gi, qi), 0);
            }
        }
    }

    return SHR_E_NONE;
}

/*!
 * Start a channel
 */
static int
cmicx_pdma_chan_start(struct pdma_hw *hw, int chan)
{
    uint32_t val;
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    hw->hdls.reg_rd32(hw, CMICX_PDMA_CTRL(grp, que), &val);
    val |= CMICX_PDMA_ENABLE;
    hw->hdls.reg_wr32(hw, CMICX_PDMA_CTRL(grp, que), val);

    MEMORY_BARRIER;

    return SHR_E_NONE;
}

/*!
 * Stop a channel
 */
static int
cmicx_pdma_chan_stop(struct pdma_hw *hw, int chan)
{
    uint32_t val;
    int grp, que;
    int retry = CMICX_HW_RETRY_TIMES;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    hw->hdls.reg_rd32(hw, CMICX_PDMA_CTRL(grp, que), &val);
    val |= CMICX_PDMA_ENABLE | CMICX_PDMA_ABORT;
    hw->hdls.reg_wr32(hw, CMICX_PDMA_CTRL(grp, que), val);

    MEMORY_BARRIER;

    do {
        val = ~CMICX_PDMA_IS_ACTIVE;
        hw->hdls.reg_rd32(hw, CMICX_PDMA_STAT(grp, que), &val);
    } while ((val & CMICX_PDMA_IS_ACTIVE) && (--retry > 0));

    hw->hdls.reg_rd32(hw, CMICX_PDMA_CTRL(grp, que), &val);
    val &= ~(CMICX_PDMA_ENABLE | CMICX_PDMA_ABORT);
    hw->hdls.reg_wr32(hw, CMICX_PDMA_CTRL(grp, que), val);

    hw->hdls.reg_wr32(hw, CMICX_PDMA_IRQ_STAT_CLR(grp), CMICX_PDMA_IRQ_MASK(que));

    MEMORY_BARRIER;

    return SHR_E_NONE;
}

/*!
 * Setup a channel
 */
static int
cmicx_pdma_chan_setup(struct pdma_hw *hw, int chan, uint64_t addr)
{
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    hw->hdls.reg_wr32(hw, CMICX_PDMA_DESC_LO(grp, que), addr);
    hw->hdls.reg_wr32(hw, CMICX_PDMA_DESC_HI(grp, que), DMA_TO_BUS_HI(addr >> 32));

    MEMORY_BARRIER;

    return SHR_E_NONE;
}

/*!
 * Set halt point for a channel
 */
static int
cmicx_pdma_chan_goto(struct pdma_hw *hw, int chan, uint64_t addr)
{
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    hw->hdls.reg_wr32(hw, CMICX_PDMA_DESC_HALT_LO(grp, que), addr);
    hw->hdls.reg_wr32(hw, CMICX_PDMA_DESC_HALT_HI(grp, que), DMA_TO_BUS_HI(addr >> 32));

    MEMORY_BARRIER;

    return SHR_E_NONE;
}

/*!
 * Clear a channel
 */
static int
cmicx_pdma_chan_clear(struct pdma_hw *hw, int chan)
{
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    hw->hdls.reg_wr32(hw, CMICX_PDMA_IRQ_STAT_CLR(grp), CMICX_PDMA_IRQ_CTRLD_INTR(que));

    MEMORY_BARRIER;

    return SHR_E_NONE;
}

/*!
 * Enable interrupt for a channel
 */
static int
cmicx_pdma_chan_intr_enable(struct pdma_hw *hw, int chan)
{
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    cmicx_pdma_intr_enable(hw, grp, que, CMICX_PDMA_IRQ_CTRLD_INTR(que));

    return SHR_E_NONE;
}

/*!
 * Disable interrupt for a channel
 */
static int
cmicx_pdma_chan_intr_disable(struct pdma_hw *hw, int chan)
{
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    cmicx_pdma_intr_disable(hw, grp, que, CMICX_PDMA_IRQ_CTRLD_INTR(que));

    return SHR_E_NONE;
}

/*!
 * Query interrupt status for a channel
 *
 * In group mode (interrupt processing per CMC), need to query each channel's
 * interrupt status.
 *
 */
static int
cmicx_pdma_chan_intr_query(struct pdma_hw *hw, int chan)
{
    uint32_t val;
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    hw->hdls.reg_rd32(hw, CMICX_PDMA_IRQ_STAT(grp), &val);

    return val & CMICX_PDMA_IRQ_CTRLD_INTR(que);
}

/*!
 * Check interrupt validity for a channel
 *
 * In group mode (interrupt processing per CMC), need to check each channel's
 * interrupt validity based on its interrupt mask.
 *
 */
static int
cmicx_pdma_chan_intr_check(struct pdma_hw *hw, int chan)
{
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    if (!(hw->dev->ctrl.grp[grp].irq_mask & CMICX_PDMA_IRQ_CTRLD_INTR(que))) {
        return 0;
    }

    return cmicx_pdma_chan_intr_query(hw, chan);
}

/*!
 * Coalesce interrupt for a channel
 */
static int
cmicx_pdma_chan_intr_coalesce(struct pdma_hw *hw, int chan, int count, int timer)
{
    uint32_t val;
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    val = CMICX_PDMA_INTR_COAL_ENA |
          CMICX_PDMA_INTR_THRESH(count) |
          CMICX_PDMA_INTR_TIMER(timer);
    hw->hdls.reg_wr32(hw, CMICX_PDMA_INTR_COAL(grp, que), val);

    return SHR_E_NONE;
}

/*!
 * Dump registers for a channel
 */
static int
cmicx_pdma_chan_reg_dump(struct pdma_hw *hw, int chan)
{
    uint32_t val;
    int grp, que;

    grp = chan / CMICX_PDMA_CMC_CHAN;
    que = chan % CMICX_PDMA_CMC_CHAN;

    hw->hdls.reg_rd32(hw, CMICX_PDMA_CTRL(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_CTRL: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_DESC_LO(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_DESC_LO: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_DESC_HI(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_DESC_HI: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_CURR_DESC_LO(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_CURR_DESC_LO: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_CURR_DESC_HI(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_CURR_DESC_HI: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_DESC_HALT_LO(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_DESC_HALT_ADDR_LO: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_DESC_HALT_HI(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_DESC_HALT_ADDR_HI: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_COS_CTRL_RX0(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_COS_CTRL_RX_0: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_COS_CTRL_RX1(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_COS_CTRL_RX_1: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_INTR_COAL(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_INTR_COAL: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_RBUF_THRE(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_RXBUF_THRESHOLD_CONFIG: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_STAT(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_STAT: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_COUNT_RX(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_PKT_COUNT_RXPKT: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_COUNT_TX(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_PKT_COUNT_TXPKT: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_COUNT_RX_DROP(grp, que), &val);
    CNET_PR("CMIC_CMC%d_DMA_CH%d_PKT_COUNT_RXPKT_DROP: 0x%08x\n", grp, que, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_IRQ_STAT(grp), &val);
    CNET_PR("CMIC_CMC%d_IRQ_STAT: 0x%08x\n", grp, val);

    hw->hdls.reg_rd32(hw, CMICX_PDMA_IRQ_STAT_CLR(grp), &val);
    CNET_PR("CMIC_CMC%d_IRQ_STAT_CLR: 0x%08x\n", grp, val);

    val = hw->dev->ctrl.grp[grp].irq_mask;
    CNET_PR("CMIC_CMC%d_IRQ_ENAB: 0x%08x\n", grp, val);

    hw->hdls.reg_rd32(hw, CMICX_EP_TO_CPU_HEADER_SIZE, &val);
    CNET_PR("CMIC_EP_TO_CPU_HEADER_SIZE: 0x%08x\n", val);

    return SHR_E_NONE;
}

/*!
 * Initialize function pointers
 */
int
bcmcnet_cmicx_pdma_hw_hdls_init(struct pdma_hw *hw)
{
    if (!hw) {
        return SHR_E_PARAM;
    }

    hw->hdls.reg_rd32 = cmicx_pdma_reg_read32;
    hw->hdls.reg_wr32 = cmicx_pdma_reg_write32;
    hw->hdls.hw_init = cmicx_pdma_hw_init;
    hw->hdls.hw_config = cmicx_pdma_hw_config;
    hw->hdls.hw_reset = cmicx_pdma_hw_reset;
    hw->hdls.chan_start = cmicx_pdma_chan_start;
    hw->hdls.chan_stop = cmicx_pdma_chan_stop;
    hw->hdls.chan_setup = cmicx_pdma_chan_setup;
    hw->hdls.chan_goto = cmicx_pdma_chan_goto;
    hw->hdls.chan_clear = cmicx_pdma_chan_clear;
    hw->hdls.chan_intr_enable = cmicx_pdma_chan_intr_enable;
    hw->hdls.chan_intr_disable = cmicx_pdma_chan_intr_disable;
    hw->hdls.chan_intr_query = cmicx_pdma_chan_intr_query;
    hw->hdls.chan_intr_check = cmicx_pdma_chan_intr_check;
    hw->hdls.chan_intr_coalesce = cmicx_pdma_chan_intr_coalesce;
    hw->hdls.chan_reg_dump = cmicx_pdma_chan_reg_dump;

    return SHR_E_NONE;
}

