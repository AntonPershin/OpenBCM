#
# $Id: Makefile,v 1.4 Broadcom SDK $
# This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
# 
# Copyright 2007-2021 Broadcom Inc. All rights reserved.
# 
# Makefile for dbal_init 
#


LOCALDIR = src/soc/dnx/dbal/dbal_init/

include ${SDK}/make/Make.config

#subdirs := auto_generated

#
# If this is compilation for SLK then optimize this library for code
# size. Use PARTIAL_OPT_CODE for doing only partial code size optimization
#
ifeq ($(findstring PARTIAL_OPT_CODE,$(MAKE_CUSTOM_SLK_CODE_SIZE)),PARTIAL_OPT_CODE)
CFGFLAGS += -Os
endif
ifeq ($(findstring OPTIMIZE_CODE,$(MAKE_CUSTOM_SLK_CODE_SIZE)),OPTIMIZE_CODE)
CFGFLAGS += -Os
endif

INCDIR += -I${SDK}/include/soc/dnx

include ${SDK}/make/Make.subdirs

lib = libsoc_dnxdbal_dbalinit

include ${SDK}/make/Make.lib

include ${SDK}/make/Make.depend

