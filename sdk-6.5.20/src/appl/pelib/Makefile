# $Id: Makefile,v 1.3 2011/03/25 18:46:45 morrier Exp $
# This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
# 
# Copyright 2007-2020 Broadcom Inc. All rights reserved.
#
# Makefile for Broadcom PE-LIB Mode Tests
#

LOCALDIR = src/appl/pelib

CFGFLAGS += -DSOURCE_CHECK_LIBAPPL
CFGFLAGS += -DPEMODE_BCM_BUILD
#CFGFLAGS += -DMDIO_DRY_RUN
CFGFLAGS += -I$(SDK)/src/appl/pelib/include

subdirs+=src
include ${SDK}/make/Make.subdirs

include ${SDK}/make/Make.config

lib = libpelib
include ${SDK}/make/Make.lib

include ${SDK}/make/Make.depend
