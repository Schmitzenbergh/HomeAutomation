## Makefile.am for FusionDale/proxy/dispatcher

INTERFACES_DIR = $(MODULEDIR)/interfaces

ifusiondaledir = $(INTERFACES_DIR)/IFusionDale

INCLUDES = \
	-I$(top_builddir)/include	\
	-I$(top_srcdir)/include		\
	-I$(top_builddir)/lib		\
	-I$(top_srcdir)/lib		\
	-I$(top_srcdir)/proxy/requestor	\
	$(DIRECTFB_INTERNAL_CFLAGS)	\
	-DDATADIR=\"${RUNTIME_SYSROOT}@DATADIR@\"

LIBS = \
	$(top_builddir)/lib/libfusiondale.la	\
	-lvoodoo				\
	$(DIRECTFB_LIBS)


ifusiondale_LTLIBRARIES = \
	libifusiondale_dispatcher.la

if BUILD_STATIC
ifusiondale_DATA              = libifusiondale_dispatcher.o
endif

libifusiondale_dispatcher_la_SOURCES = ifusiondale_dispatcher.c ifusiondale_dispatcher.h
libifusiondale_dispatcher_la_LDFLAGS = -avoid-version -module
libifusiondale_dispatcher_la_LIBADDD = $(LIBS)


include $(top_srcdir)/rules/libobject.make
