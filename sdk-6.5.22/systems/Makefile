# $Id: Makefile,v 1.3 Broadcom SDK $
# This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
# 
# Copyright 2007-2021 Broadcom Inc. All rights reserved.
#
# Top level Makefile for Systems
#

include ${SDK}/make/Make.tools
-include ${SDK}/make/Make.local

ifeq ($(HOSTTYPE),i386-linux)
linux_dir=linux
endif

subdirs := vxworks sim ${linux_dir}
include ${SDK}/make/Make.subdirs

reldirs := vxworks sim
release: ${reldirs}
