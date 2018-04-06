#
# Global setup
TOP    = .
SOURCE = $(TOP)/Source
KERNEL = $(TOP)/Kernel

CONFIG ?= tv550

NM ?= nm

#
# Version definition
MAJOR   = 1
MINOR   = 1
TINY    = 1
VERSION = $(MAJOR).$(MINOR).$(TINY)

FD_MAJOR = 0
FD_MINOR = 1
FD_TINY  = 1

# Default target
default: all

#
# Compiler flags
CFLAGS += -fpic -pipe -O2 -Wall

#
# Linker flags
LDFLAGS += -L.

#
# Configuration header files
INCLUDES += -I$(TOP)/Config_$(CONFIG)

#
# Fusion Kernel module headers
INCLUDES += -I$(KERNEL)/linux-fusion/linux/include

#
# Preprocessor flags
CPPFLAGS += \
	-DHAVE_CONFIG_H							\
	-DHAVE_STDBOOL_H						\
	-D_GNU_SOURCE							\
	-D_REENTRANT							\
	-DVERSION=\"$(VERSION)\"					\
        -DBUILDTIME="\"$(buildtime)\""

#
# Debug option
ifeq ($(DEBUG),yes)
  CPPFLAGS += -DENABLE_DEBUG=1
  CFLAGS   += -g3
else
  CPPFLAGS += -DENABLE_DEBUG=0
endif

#
# Trace option
ifeq ($(TRACE),yes)
  CFLAGS   += -finstrument-functions
  CPPFLAGS += -DENABLE_TRACE=1
else
  CPPFLAGS += -DENABLE_TRACE=0
endif

#
# Include the specific configuration #########################
-include $(TOP)/Config_$(CONFIG)/makefile

#
# Installation paths
prefix     ?= /opt/directfb
bindir     ?= $(prefix)/bin
datadir    ?= $(prefix)/share
libdir     ?= $(prefix)/lib
moddir     ?= $(libdir)/directfb
sysconfdir ?= $(prefix)/etc

CPPFLAGS += \
	-DDATADIR=\"$(datadir)\"	\
	-DMODULEDIR=\"$(moddir)\"	\
	-DSYSCONFDIR=\"$(sysconfdir)\"

buildtime = $(shell sh -c date -u +%Y-%m-%d %H:%M)

#
# libvoodoo object files
LIB_VOODOO_OBJECTS = \
	$(SOURCE)/DirectFB/lib/voodoo/client.o				\
	$(SOURCE)/DirectFB/lib/voodoo/conf.o				\
	$(SOURCE)/DirectFB/lib/voodoo/interface.o			\
	$(SOURCE)/DirectFB/lib/voodoo/ivoodooplayer.o			\
	$(SOURCE)/DirectFB/lib/voodoo/ivoodooplayer_dispatcher.o	\
	$(SOURCE)/DirectFB/lib/voodoo/ivoodooplayer_requestor.o		\
	$(SOURCE)/DirectFB/lib/voodoo/manager.o				\
	$(SOURCE)/DirectFB/lib/voodoo/play.o				\
	$(SOURCE)/DirectFB/lib/voodoo/play_server.o			\
	$(SOURCE)/DirectFB/lib/voodoo/server.o

#
# libdirect object files
LIB_DIRECT_OBJECTS = \
	$(SOURCE)/DirectFB/lib/direct/clock.o				\
	$(SOURCE)/DirectFB/lib/direct/conf.o				\
	$(SOURCE)/DirectFB/lib/direct/debug.o				\
	$(SOURCE)/DirectFB/lib/direct/direct.o				\
	$(SOURCE)/DirectFB/lib/direct/hash.o				\
	$(SOURCE)/DirectFB/lib/direct/interface.o			\
	$(SOURCE)/DirectFB/lib/direct/log.o				\
	$(SOURCE)/DirectFB/lib/direct/list.o				\
	$(SOURCE)/DirectFB/lib/direct/mem.o				\
	$(SOURCE)/DirectFB/lib/direct/memcpy.o				\
	$(SOURCE)/DirectFB/lib/direct/messages.o			\
	$(SOURCE)/DirectFB/lib/direct/modules.o				\
	$(SOURCE)/DirectFB/lib/direct/signals.o				\
	$(SOURCE)/DirectFB/lib/direct/stream.o				\
	$(SOURCE)/DirectFB/lib/direct/system.o				\
	$(SOURCE)/DirectFB/lib/direct/thread.o				\
	$(SOURCE)/DirectFB/lib/direct/trace.o				\
	$(SOURCE)/DirectFB/lib/direct/tree.o				\
	$(SOURCE)/DirectFB/lib/direct/utf8.o				\
	$(SOURCE)/DirectFB/lib/direct/util.o

#
# libfusion object files
LIB_FUSION_OBJECTS = \
	$(SOURCE)/DirectFB/lib/fusion/arena.o				\
	$(SOURCE)/DirectFB/lib/fusion/call.o				\
	$(SOURCE)/DirectFB/lib/fusion/conf.o				\
	$(SOURCE)/DirectFB/lib/fusion/fusion.o				\
	$(SOURCE)/DirectFB/lib/fusion/hash.o				\
	$(SOURCE)/DirectFB/lib/fusion/lock.o				\
	$(SOURCE)/DirectFB/lib/fusion/object.o				\
	$(SOURCE)/DirectFB/lib/fusion/property.o			\
	$(SOURCE)/DirectFB/lib/fusion/reactor.o				\
	$(SOURCE)/DirectFB/lib/fusion/ref.o				\
	$(SOURCE)/DirectFB/lib/fusion/shmalloc.o			\
	$(SOURCE)/DirectFB/lib/fusion/vector.o

LIB_FUSION_OBJECTS_SINGLE = \
	$(SOURCE)/DirectFB/lib/fusion/shm/fake.o

LIB_FUSION_OBJECTS_MULTI = \
	$(SOURCE)/DirectFB/lib/fusion/shm/heap.o			\
	$(SOURCE)/DirectFB/lib/fusion/shm/pool.o			\
	$(SOURCE)/DirectFB/lib/fusion/shm/shm.o

#
# New surface core object files
SURFACE_CORE_OBJECTS_NEW = \
	$(SOURCE)/DirectFB/src/core/local_surface_pool.o		\
	$(SOURCE)/DirectFB/src/core/prealloc_surface_pool.o		\
	$(SOURCE)/DirectFB/src/core/surface_pool_bridge.o		\
	$(SOURCE)/DirectFB/src/core/shared_surface_pool.o		\
	$(SOURCE)/DirectFB/src/core/surface.o				\
	$(SOURCE)/DirectFB/src/core/surface_buffer.o			\
	$(SOURCE)/DirectFB/src/core/surface_core.o			\
	$(SOURCE)/DirectFB/src/core/surface_pool.o

#

#
# DirectFB object files
DIRECTFB_OBJECTS = \
	$(SURFACE_CORE_OBJECTS_NEW)					\
	$(SOURCE)/DirectFB/src/core/clipboard.o				\
	$(SOURCE)/DirectFB/src/core/colorhash.o				\
	$(SOURCE)/DirectFB/src/core/core.o				\
	$(SOURCE)/DirectFB/src/core/core_parts.o			\
	$(SOURCE)/DirectFB/src/core/fonts.o				\
	$(SOURCE)/DirectFB/src/core/gfxcard.o				\
	$(SOURCE)/DirectFB/src/core/input.o				\
	$(SOURCE)/DirectFB/src/core/layer_context.o			\
	$(SOURCE)/DirectFB/src/core/layer_control.o			\
	$(SOURCE)/DirectFB/src/core/layer_region.o			\
	$(SOURCE)/DirectFB/src/core/layers.o				\
	$(SOURCE)/DirectFB/src/core/palette.o				\
	$(SOURCE)/DirectFB/src/core/screen.o				\
	$(SOURCE)/DirectFB/src/core/screens.o				\
	$(SOURCE)/DirectFB/src/core/state.o				\
	$(SOURCE)/DirectFB/src/core/system.o				\
	$(SOURCE)/DirectFB/src/core/windows.o				\
	$(SOURCE)/DirectFB/src/core/windowstack.o			\
	$(SOURCE)/DirectFB/src/core/wm.o				\
	$(SOURCE)/DirectFB/src/directfb.o				\
	$(SOURCE)/DirectFB/src/display/idirectfbdisplaylayer.o		\
	$(SOURCE)/DirectFB/src/display/idirectfbpalette.o		\
	$(SOURCE)/DirectFB/src/display/idirectfbscreen.o		\
	$(SOURCE)/DirectFB/src/display/idirectfbsurface.o		\
	$(SOURCE)/DirectFB/src/display/idirectfbsurface_layer.o		\
	$(SOURCE)/DirectFB/src/display/idirectfbsurface_window.o	\
	$(SOURCE)/DirectFB/src/gfx/clip.o				\
	$(SOURCE)/DirectFB/src/gfx/convert.o				\
	$(SOURCE)/DirectFB/src/gfx/generic/generic.o			\
	$(SOURCE)/DirectFB/src/gfx/util.o				\
	$(SOURCE)/DirectFB/src/idirectfb.o				\
	$(SOURCE)/DirectFB/src/input/idirectfbinputbuffer.o		\
	$(SOURCE)/DirectFB/src/input/idirectfbinputdevice.o		\
	$(SOURCE)/DirectFB/src/media/idirectfbdatabuffer.o		\
	$(SOURCE)/DirectFB/src/media/idirectfbdatabuffer_file.o		\
	$(SOURCE)/DirectFB/src/media/idirectfbdatabuffer_memory.o	\
	$(SOURCE)/DirectFB/src/media/idirectfbdatabuffer_streamed.o	\
	$(SOURCE)/DirectFB/src/media/idirectfbfont.o			\
	$(SOURCE)/DirectFB/src/media/idirectfbimageprovider.o		\
	$(SOURCE)/DirectFB/src/media/idirectfbvideoprovider.o		\
	$(SOURCE)/DirectFB/src/misc/conf.o				\
	$(SOURCE)/DirectFB/src/misc/gfx_util.o				\
	$(SOURCE)/DirectFB/src/misc/util.o				\
	$(SOURCE)/DirectFB/src/windows/idirectfbwindow.o

#
# DirectFB requestor object files
DIRECTFB_OBJECTS += $(SOURCE)/DirectFB/proxy/requestor/idirectfb_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbdatabuffer_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbdisplaylayer_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbeventbuffer_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbfont_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbimageprovider_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbinputdevice_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbpalette_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbscreen_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbsurface_requestor.o \
	$(SOURCE)/DirectFB/proxy/requestor/idirectfbwindow_requestor.o

#
# DirectFB dispatcher object files
DIRECTFB_OBJECTS += $(SOURCE)/DirectFB/proxy/dispatcher/idirectfb_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbdatabuffer_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbdisplaylayer_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbeventbuffer_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbfont_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbimageprovider_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbinputdevice_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbpalette_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbscreen_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbsurface_dispatcher.o \
	$(SOURCE)/DirectFB/proxy/dispatcher/idirectfbwindow_dispatcher.o	

#
# DirectFB header files
DIRECTFB_INCLUDES += \
	-I$(SOURCE)/DirectFB/include					\
	-I$(SOURCE)/DirectFB/lib					\
	-I$(SOURCE)/DirectFB/src					\
	-I$(SOURCE)/DirectFB/proxy/requestor					\
	-I$(SOURCE)/DirectFB/proxy/dispatcher					\
	-I$(SOURCE)/DirectFB/systems


#
# DiVine object files
DIVINE_OBJECTS = \
	$(SOURCE)/DiVine/driver/divine.o				\
	$(SOURCE)/DiVine/lib/divine.o					\
	$(SOURCE)/DiVine/lib/idivine.o					\
	$(SOURCE)/DiVine/proxy/dispatcher/idivine_dispatcher.o		\
	$(SOURCE)/DiVine/proxy/requestor/idivine_requestor.o

#
# FusionDale header files and defines
DIVINE_INCLUDES += \
	-I$(SOURCE)/DiVine/include					\
	-I$(SOURCE)/DiVine/lib						\
	-I$(SOURCE)/DiVine/proxy/dispatcher

CPPFLAGS += -DDIVINE_MAJOR_VERSION=0 -DDIVINE_MINOR_VERSION=0

#
# SaWMan object files
SAWMAN_OBJECTS = \
	$(SOURCE)/SaWMan/src/isawman.o					\
	$(SOURCE)/SaWMan/src/isawmanmanager.o				\
	$(SOURCE)/SaWMan/src/sawman.o					\
	$(SOURCE)/SaWMan/src/sawman_config.o				\
	$(SOURCE)/SaWMan/src/sawman_draw.o				\
	$(SOURCE)/SaWMan/wm/sawman/sawman_wm.o

#
# SaWMan header files
SAWMAN_INCLUDES += \
	-I$(SOURCE)/SaWMan/include					\
	-I$(SOURCE)/SaWMan/src

CPPFLAGS += -DSAWMAN_VERSION=\"0.8.15\"

#
# FusionDale object files
FUSIONDALE_OBJECTS = \
	$(SOURCE)/FusionDale/src/ifusiondale.o				\
	$(SOURCE)/FusionDale/src/fusiondale.o				\
	$(SOURCE)/FusionDale/src/messenger/ifusiondalemessenger.o	\
	$(SOURCE)/FusionDale/src/core/dale_core.o			\
	$(SOURCE)/FusionDale/src/core/messenger.o			\
	$(SOURCE)/FusionDale/src/core/messenger_port.o			\
	$(SOURCE)/FusionDale/src/coma/coma.o				\
	$(SOURCE)/FusionDale/src/coma/component.o			\
	$(SOURCE)/FusionDale/src/coma/icoma.o				\
	$(SOURCE)/FusionDale/src/coma/icomacomponent.o			\
	$(SOURCE)/FusionDale/src/coma/policy.o        			\
	$(SOURCE)/FusionDale/src/coma/thread.o        			\
	$(SOURCE)/FusionDale/src/misc/dale_config.o			\
	$(SOURCE)/FusionDale/proxy/dispatcher/ifusiondale_dispatcher.o	\
	$(SOURCE)/FusionDale/proxy/dispatcher/icoma_dispatcher.o	\
	$(SOURCE)/FusionDale/proxy/dispatcher/icomacomponent_dispatcher.o	\
	$(SOURCE)/FusionDale/proxy/requestor/ifusiondale_requestor.o	\
	$(SOURCE)/FusionDale/proxy/requestor/icoma_requestor.o		\
	$(SOURCE)/FusionDale/proxy/requestor/icomacomponent_requestor.o

#
# FusionDale header files
FUSIONDALE_INCLUDES += \
	-I$(SOURCE)/FusionDale/include					\
	-I$(SOURCE)/FusionDale/src					\
	-I$(SOURCE)/FusionDale/proxy/dispatcher


#
# Build list of all objects
OBJECTS += \
	$(LIB_VOODOO_OBJECTS)						\
	$(LIB_DIRECT_OBJECTS)						\
	$(LIB_FUSION_OBJECTS)						\
	$(LIB_FUSION_OBJECTS_MULTI)					\
	$(DIRECTFB_OBJECTS)						\
	$(DIVINE_OBJECTS)						\
	$(SAWMAN_OBJECTS)						\
	$(FUSIONDALE_OBJECTS)

#
# Build complete include path
INCLUDES += \
	$(DIRECTFB_INCLUDES)						\
	$(DIVINE_INCLUDES)						\
	$(SAWMAN_INCLUDES)						\
	$(FUSIONDALE_INCLUDES)



#
# All libraries
LIBS += \
	-lrt								\
	-lm								\
	-lpthread							\
	-ldl \
	-lz


#
# All tools and tests
TOOLS += \
	$(SOURCE)/DirectFB/tools/dfbinfo				\
	$(SOURCE)/DirectFB/tools/dfbdump				\
	$(SOURCE)/DirectFB/tools/dfbproxy				\
	$(SOURCE)/DirectFB/tools/fusion_bench				\
	$(SOURCE)/DirectFB/tools/voodooplay_client			\
	$(SOURCE)/DirectFB/tools/voodooplay_server			\
	$(SOURCE)/DirectFB/tests/fusion_reactor				\
	$(SOURCE)/SaWMan/tools/swmdump

#
# List of generated header files
GEN_HEADERS = \
#	$(SOURCE)/DirectFB/include/directfb_keynames.h			\
#	$(SOURCE)/DirectFB/include/directfb_strings.h			\
#	$(SOURCE)/DirectFB/include/directfb_version.h			\
#	$(SOURCE)/FusionDale/include/fusiondale_version.h


#
# Rules
all: $(GEN_HEADERS) libdirectfb.o libdirectfb.so libdirectfb.so.nm $(TOOLS) $(TEST) $(TOOLS:%=%.nm)

modules:  idirectfbfont_ft2.so idirectfbfont_lino.so idirectfbfont_dgiff.so idirectfbimageprovider_png.so idirectfbimageprovider_jpeg.so idirectfbvideoprovider_gif.so

idirectfbfont_ft2.so: $(FT2MODULEOBJECTS)
	$(CC) -avoid-version -shared $(LDFLAGS) -lfreetype -ldirectfb -o $@ $(FT2MODULEOBJECTS)

idirectfbfont_lino.so: $(ITYPEMODULEOBJECTS)
	$(CC) -avoid-version -shared $(LDFLAGS) -litype -ldirectfb -o $@ $(ITYPEMODULEOBJECTS)

idirectfbfont_dgiff.so: $(DGIFFMODULEOBJECTS)
	$(CC) -avoid-version -shared $(LDFLAGS) -ldirectfb -o $@ $(DGIFFMODULEOBJECTS)

idirectfbimageprovider_png.so: $(PNGMODULEOBJECTS)
	$(CC) -avoid-version -shared $(LDFLAGS) -lpng -ldirectfb -o $@ $(PNGMODULEOBJECTS)

idirectfbimageprovider_jpeg.so: $(JPEGMODULEOBJECTS)
	$(CC) -avoid-version -shared $(LDFLAGS) -ljpeg -ldirectfb -o $@ $(JPEGMODULEOBJECTS)

idirectfbvideoprovider_gif.so: $(GIFMODULEOBJECTS)
	$(CC) -avoid-version -shared $(LDFLAGS) -ldirectfb -o $@ $(GIFMODULEOBJECTS)

libdirectfb.o:  $(GEN_HEADERS) $(OBJECTS)
	$(LD) $(LDFLAGS) -r -o $@ $(OBJECTS)

libdirectfb.so: $(GEN_HEADERS) $(OBJECTS)
	$(CC) -shared -Wl,-soname,libdirectfb.so $(LDFLAGS) $(LIBS) -o $@ $(OBJECTS)

libdirectfb.so.nm: libdirectfb.so
	$(NM) -n libdirectfb.so > libdirectfb.so.nm

%.o: %.c
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $(INCLUDES) -o $@ $<

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $(CPPFLAGS) $(INCLUDES) -o $@ $<

$(SOURCE)/DirectFB/tests/%: $(SOURCE)/DirectFB/tests/%.o libdirectfb.so
	$(CC) $(LDFLAGS) -o $@ $< -ldirectfb $(LIBS)

$(SOURCE)/DirectFB/tools/%: $(SOURCE)/DirectFB/tools/%.o libdirectfb.so
	$(CXX) $(LDFLAGS) -o $@ $< -ldirectfb $(LIBS)

$(SOURCE)/SaWMan/tools/%: $(SOURCE)/SaWMan/tools/%.o libdirectfb.so
	$(CC) $(LDFLAGS) -o $@ $< -ldirectfb $(LIBS)

%.nm: %
	$(NM) -n $< > $@


.PHONY: clean install

clean::
	rm -f libdirectfb.*o* $(TOOLS) $(TEST) $(GEN_HEADERS)
	find -name "*.o" | xargs rm -f
	find -name "*.so" | xargs rm -f
	find -name "*.nm" | xargs rm -f

install:: all
	@(if test -z "$(DESTDIR)"; then echo "**** DESTDIR not set! ****"; exit 1; fi)
	install -d $(DESTDIR)$(bindir)
	install -d $(DESTDIR)$(libdir)
	install -d $(DESTDIR)$(moddir)
	install -d $(DESTDIR)$(moddir)/inputdrivers
	install -d $(DESTDIR)$(moddir)/interfaces
	install -d $(DESTDIR)$(moddir)/gfxdrivers
	install -d $(DESTDIR)$(moddir)/systems
	install -d $(DESTDIR)$(moddir)/wm
	install -c -m 755 $(TEST) $(TOOLS) $(TOOLS:%=%.nm) $(DESTDIR)$(bindir)/
	install -c -m 755 libdirectfb.so $(DESTDIR)$(libdir)/
	install -c -m 644 libdirectfb.so.nm $(DESTDIR)$(libdir)/




DFBINC  = $(SOURCE)/DirectFB/include
MKNAMES = $(SOURCE)/DirectFB/include/mknames.sh


$(DFBINC)/directfb_version.h: makefile
	@echo '#ifndef __DIRECTFB_VERSION_H__' > $@
	@echo '#define __DIRECTFB_VERSION_H__' >> $@
	@echo '' >> $@
	@echo '#define DIRECTFB_MAJOR_VERSION  (' $(MAJOR) ')' >> $@
	@echo '#define DIRECTFB_MINOR_VERSION  (' $(MINOR) ')' >> $@
	@echo '#define DIRECTFB_MICRO_VERSION  (' $(TINY) ')' >> $@
	@echo '#define DIRECTFB_BINARY_AGE     (0)' >> $@
	@echo '#define DIRECTFB_INTERFACE_AGE  (0)' >> $@
	@echo '' >> $@
	@echo '' >> $@
	@echo '#endif' >> $@


$(DFBINC)/directfb_keynames.h: $(DFBINC)/directfb_keyboard.h $(MKNAMES) makefile
	@echo '#ifndef __DIRECTFB_KEYNAMES_H__' > $@
	@echo '#define __DIRECTFB_KEYNAMES_H__' >> $@

	$(MKNAMES) DFBInputDeviceKeySymbol DIKS NULL KeySymbol symbol $(DFBINC)/directfb_keyboard.h \
	   | grep -v DIKS_ENTER >> $@

	$(MKNAMES) DFBInputDeviceKeyIdentifier DIKI UNKNOWN KeyIdentifier identifier $(DFBINC)/directfb_keyboard.h \
	   | grep -v DIKI_NUMBER_OF_KEYS | grep -v DIKI_KEYDEF_END >> $@

	@echo '' >> $@
	@echo '#endif' >> $@


$(DFBINC)/directfb_strings.h: $(DFBINC)/directfb.h $(MKNAMES) makefile
	@echo '#ifndef __DIRECTFB_STRINGS_H__' > $@
	@echo '#define __DIRECTFB_STRINGS_H__' >> $@

	$(MKNAMES) DFBSurfacePixelFormat DSPF UNKNOWN PixelFormat format $(DFBINC)/directfb.h >> $@

	$(MKNAMES) DFBInputDeviceTypeFlags DIDTF NONE InputDeviceTypeFlags type $(DFBINC)/directfb.h \
	   | grep -v DIDTF_ALL >> $@

	$(MKNAMES) DFBSurfaceDrawingFlags DSDRAW NOFX SurfaceDrawingFlags flag $(DFBINC)/directfb.h \
	   | grep -v DSDRAW_ALL >> $@

	$(MKNAMES) DFBSurfaceBlittingFlags DSBLIT NOFX SurfaceBlittingFlags flag $(DFBINC)/directfb.h \
	   | grep -v DSBLIT_ALL >> $@

	$(MKNAMES) DFBSurfaceBlendFunction DSBF UNKNOWN SurfaceBlendFunction function $(DFBINC)/directfb.h \
	   >> $@

	@echo FIXME: Use DIMCAPS prefix for DFBImageCapabilities
	$(MKNAMES) DFBInputDeviceCapabilities DICAPS NONE InputDeviceCapabilities capability $(DFBINC)/directfb.h \
	   | grep -v DICAPS_ALL | grep -v DICAPS_ALPHACHANNEL | grep -v DICAPS_COLORKEY >> $@

	$(MKNAMES) DFBDisplayLayerTypeFlags DLTF NONE DisplayLayerTypeFlags type $(DFBINC)/directfb.h \
	   | grep -v DLTF_ALL >> $@

	$(MKNAMES) DFBDisplayLayerCapabilities DLCAPS NONE DisplayLayerCapabilities capability $(DFBINC)/directfb.h \
	   | grep -v DLCAPS_ALL >> $@

	$(MKNAMES) DFBDisplayLayerBufferMode DLBM UNKNOWN DisplayLayerBufferMode mode $(DFBINC)/directfb.h \
	   | grep -v DLBM_DONTCARE | grep -v DLBM_COLOR | grep -v DLBM_IMAGE | grep -v DLBM_TILE >> $@

	$(MKNAMES) DFBWindowCapabilities DWCAPS NONE WindowCapabilities capability $(DFBINC)/directfb.h \
	   | grep -v DWCAPS_ALL >> $@

	$(MKNAMES) DFBWindowOptions DWOP NONE WindowOptions option $(DFBINC)/directfb.h \
	   | grep -v DWOP_ALL >> $@

	$(MKNAMES) DFBScreenCapabilities DSCCAPS NONE ScreenCapabilities capability $(DFBINC)/directfb.h \
	   | grep -v DSCCAPS_ALL >> $@

	$(MKNAMES) DFBScreenEncoderCapabilities DSECAPS NONE ScreenEncoderCapabilities capability $(DFBINC)/directfb.h \
	   | grep -v DSECAPS_ALL >> $@

	$(MKNAMES) DFBScreenEncoderType DSET UNKNOWN ScreenEncoderType type $(DFBINC)/directfb.h \
	   | grep -v DSET_ALL >> $@

	$(MKNAMES) DFBScreenEncoderTVStandards DSETV UNKNOWN ScreenEncoderTVStandards standard $(DFBINC)/directfb.h \
	   | grep -v DSETV_ALL >> $@

	$(MKNAMES) DFBScreenOutputCapabilities DSOCAPS NONE ScreenOutputCapabilities capability $(DFBINC)/directfb.h \
	   | grep -v DSOCAPS_ALL >> $@

	$(MKNAMES) DFBScreenOutputConnectors DSOC UNKNOWN ScreenOutputConnectors connector $(DFBINC)/directfb.h \
	   | grep -v DSOC_ALL >> $@

	$(MKNAMES) DFBScreenOutputSignals DSOS NONE ScreenOutputSignals signal $(DFBINC)/directfb.h \
	   | grep -v DSOS_ALL >> $@

	$(MKNAMES) DFBScreenOutputSlowBlankingSignals DSOSB OFF ScreenOutputSlowBlankingSignals slow_signal $(DFBINC)/directfb.h \
	   | grep -v DSOSB_ALL >> $@

	$(MKNAMES) DFBScreenOutputResolution DSOR UNKNOWN ScreenOutputResolution resolution $(DFBINC)/directfb.h \
	   | grep -v DSOR_ALL >> $@

	$(MKNAMES) DFBScreenMixerCapabilities DSMCAPS NONE ScreenMixerCapabilities capability $(DFBINC)/directfb.h \
	   | grep -v DSMCAPS_ALL >> $@

	$(MKNAMES) DFBScreenMixerTree DSMT UNKNOWN ScreenMixerTree tree $(DFBINC)/directfb.h \
	   | grep -v DSMT_ALL >> $@

	$(MKNAMES) DFBScreenEncoderTestPicture DSETP OFF ScreenEncoderTestPicture test_picture $(DFBINC)/directfb.h \
	   | grep -v DSETP_ALL >> $@

	$(MKNAMES) DFBScreenEncoderScanMode DSESM UNKNOWN ScreenEncoderScanMode scan_mode $(DFBINC)/directfb.h \
	   | grep -v DSESM_ALL >> $@

	$(MKNAMES) DFBAccelerationMask DFXL NONE AccelerationMask mask $(DFBINC)/directfb.h \
	   | grep -v DFXL_ALL >> $@

	@echo '' >> $@
	@echo '#endif' >> $@


$(SOURCE)/FusionDale/include/fusiondale_version.h: makefile
	@echo '#ifndef __FUSIONDALE_VERSION_H__' > $@
	@echo '#define __FUSIONDALE_VERSION_H__' >> $@
	@echo '' >> $@
	@echo '#define FUSIONDALE_MAJOR_VERSION  (' $(FD_MAJOR) ')' >> $@
	@echo '#define FUSIONDALE_MINOR_VERSION  (' $(FD_MINOR) ')' >> $@
	@echo '#define FUSIONDALE_MICRO_VERSION  (' $(FD_TINY) ')' >> $@
	@echo '#define FUSIONDALE_BINARY_AGE     (0)' >> $@
	@echo '#define FUSIONDALE_INTERFACE_AGE  (0)' >> $@
	@echo '' >> $@
	@echo '' >> $@
	@echo '#endif' >> $@

