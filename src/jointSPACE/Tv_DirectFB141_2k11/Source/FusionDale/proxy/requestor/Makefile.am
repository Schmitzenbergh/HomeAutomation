## Makefile.am for FusionDale/proxy/requestor

INTERFACES_DIR = $(MODULEDIR)/interfaces

ifusiondaledir = $(INTERFACES_DIR)/IFusionDale

INCLUDES = \
	-I$(top_builddir)/include	\
	-I$(top_srcdir)/include		\
	-I$(top_builddir)/lib		\
	-I$(top_srcdir)/lib		\
	-I$(top_srcdir)/proxy/dispatcher	\
	$(DIRECTFB_INTERNAL_CFLAGS)		\
	-DDATADIR=\"${RUNTIME_SYSROOT}@DATADIR@\"

LIBS = \
	$(top_builddir)/lib/libfusiondale.la	\
	-lvoodoo				\
	$(DIRECTFB_LIBS)


ifusiondale_LTLIBRARIES = \
	libifusiondale_requestor.la

if BUILD_STATIC
ifusiondale_DATA              = libifusiondale_requestor.o
endif

libifusiondale_requestor_la_SOURCES = ifusiondale_requestor.c
libifusiondale_requestor_la_LDFLAGS = -avoid-version -module
libifusiondale_requestor_la_LIBADDD = $(LIBS)


include $(top_srcdir)/rules/libobject.make
