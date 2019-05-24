#-------------------------------------------------------------------------
#
# Makefile for src/bin (client programs)
#
# Portions Copyright (c) 1996-2018, PostgreSQL Global Development Group
# Portions Copyright (c) 1994, Regents of the University of California
#
# src/bin/Makefile
#
#-------------------------------------------------------------------------

subdir = src/bin
top_builddir = ../..
include $(top_builddir)/src/Makefile.global

SUBDIRS = \
	initdb \
	zq_archivecleanup \
	zq_basebackup \
	zq_config \
	zq_controldata \
	zq_ctl \
	zq_dump \
	zq_resetwal \
	zq_rewind \
	zq_test_fsync \
	zq_test_timing \
	zq_upgrade \
	zq_verify_checksums \
	zq_waldump \
	zqbench \
	zql \
	scripts

ifeq ($(PORTNAME), win32)
SUBDIRS += zqevent
else
ALWAYS_SUBDIRS += zqevent
endif

$(recurse)
$(recurse_always)
