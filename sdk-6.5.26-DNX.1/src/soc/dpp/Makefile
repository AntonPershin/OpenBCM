#
# $Id: Makefile,v 1.4 Broadcom SDK $
# This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
# 
# Copyright 2007-2022 Broadcom Inc. All rights reserved.
#
# Makefile for dpp subdirectory
#

LOCALDIR = src/soc/dpp

include ${SDK}/make/Make.config

subdirs = auto_generated

include ${SDK}/make/Make.subdirs

#
# If this is compilation for SLK-ALL then optimize for code
# size. This is added to temporarily overcome the code size
# issue on SLK compiler.
#
ifeq ($(findstring OPTIMIZE_CODE,$(MAKE_CUSTOM_CODE_SIZE)),OPTIMIZE_CODE)
CFGFLAGS += -Os
endif

export CFGFLAGS

subdirs := PPC          \
	SAND/Management \
	SAND/SAND_FM    \
	SAND/Utils      \
	PPD             \
	TMC             \
#
# Include the various ARAD directories for any of the following
# chips:
#   ARAD_A0
#   ARAD_B0
#   ARAD_PLUS_A0
#
INCUDE_ARAD_SUBDIRS=0
ifdef BCM_88660_A0
INCUDE_ARAD_SUBDIRS=1
endif

ifneq ($(INCUDE_ARAD_SUBDIRS),0)
subdirs += ARAD ARAD/ARAD_PP DRC PORT ARAD/NIF
endif

ifdef BCM_88470_A0
subdirs += QAX
endif

ifdef BCM_88270_A0
subdirs += QUX
endif

ifdef BCM_88675_A0
subdirs += JER DRC 
endif

ifdef BCM_88680_A0
subdirs += JERP
endif

include ${SDK}/make/Make.subdirs

INCDIR += -I${SDK}/include/shared

lib = libsoc_dpp

include ${SDK}/make/Make.lib

include ${SDK}/make/Make.depend

