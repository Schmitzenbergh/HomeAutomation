# X11 Config makefile specifics.

# Global setup
PHILIPS = $(TOP)/Philips
DIRECTFBTOP = $(TOP)/../..

DESTDIR = /opt/root520
prefix  = /home
bindir  = /home
datadir = /usr/data
libdir  = /lib
sysconfdir = /etc

#
# Toolchain location
#CC := /cygdrive/c/MontaVista/opt/montavista/pro/devkit/mips/fp_le/bin/mips_fp_le-gcc
#LD := /cygdrive/c/MontaVista/opt/montavista/pro/devkit/mips/fp_le/bin/mips_fp_le-ld
CC := gcc
LD := ld
nm := nm

LIBS += -lXext
LIBS += `pkg-config x11 --libs`
LIBS += `pkg-config xext --libs`
LIBS += `pkg-config freetype2 --libs`
LIBS += `pkg-config libpng --libs`

#
# Configuration
CPPFLAGS += -DHAVE_FUSIONDALE -DLINUX_2_6 -DPAGE_SHIFT=12 -DPIC #-DLINUX_INPUT_USE_FBDEV #-DHAS_CURSOR_BUG  -DDFB_INPUTDRIVER_HAS_SENSITIVITY
#-Werror -DSAWMAN_NO_LAYER_DST_WINDOW 

#
# Compiler flags
ifeq ($(DEBUG),yes)
CFLAGS   += -g -ggdb -O1 -fno-omit-frame-pointer
else
CFLAGS += -g -ggdb -O2 -ffast-math -fno-omit-frame-pointer
#CFLAGS += -g -ggdb -O2 -ffast-math -fomit-frame-pointer -march=r4400
endif
# -Werror

INCLUDES += `pkg-config x11 --cflags`
INCLUDES += `pkg-config xext --cflags`
INCLUDES += `pkg-config freetype2 --cflags`

#
# CE files (temporary)
INCLUDES += -I$(SOURCE)/FusionDale/src/core
INCLUDES += -I$(TOP)/../iType/product/source/common
INCLUDES += -I$(TOP)/../iType/product/source/adf
INCLUDES += -I$(TOP)/../iType/product/source/port/tv543
LDFLAGS  += -L$(TOP)/../iType/product/builds/linux/itype/debug

#
# Different modules, drivers etc.
FT2MODULEOBJECTS = \
	$(SOURCE)/DirectFB/interfaces/IDirectFBFont/idirectfbfont_ft2.o
ITYPEMODULEOBJECTS = \
	$(SOURCE)/DirectFB/interfaces/IDirectFBFont/idirectfbfont_lino.o
DGIFFMODULEOBJECTS = \
	$(SOURCE)/DirectFB/interfaces/IDirectFBFont/idirectfbfont_dgiff.o
PNGMODULEOBJECTS = \
	$(SOURCE)/DirectFB/interfaces/IDirectFBImageProvider/idirectfbimageprovider_png.o
JPEGMODULEOBJECTS = \
	$(SOURCE)/DirectFB/interfaces/IDirectFBImageProvider/idirectfbimageprovider_jpeg.o

OBJECTS = \
	$(SOURCE)/DirectFB/interfaces/IDirectFBFont/idirectfbfont_dgiff.o				\
	$(SOURCE)/DirectFB/interfaces/IDirectFBFont/idirectfbfont_ft2.o				\
	$(SOURCE)/DirectFB/interfaces/IDirectFBImageProvider/idirectfbimageprovider_dfiff.o	\
	$(SOURCE)/DirectFB/interfaces/IDirectFBImageProvider/idirectfbimageprovider_gif.o	\
	$(SOURCE)/DirectFB/inputdrivers/linux_input/linux_input.o				\
	$(SOURCE)/DirectFB/systems/x11/x11.o							\
	$(SOURCE)/DirectFB/systems/x11/x11image.o						\
	$(SOURCE)/DirectFB/systems/x11/xwindow.o						\
	$(SOURCE)/DirectFB/systems/x11/x11input.o						\
	$(SOURCE)/DirectFB/systems/x11/x11_surface_pool.o					\
	$(SOURCE)/DirectFB/systems/x11/vpsmem_surface_pool.o					\
	$(SOURCE)/DirectFB/systems/x11/surfacemanager.o					\
	$(SOURCE)/DirectFB/systems/x11/primary.o

TOOLS = \
	$(SOURCE)/DirectFB/tools/dfbproxy	\
	$(SOURCE)/DirectFB/tools/dfbinput	\
	$(SOURCE)/DirectFB/tools/mkdgifft	\
	$(SOURCE)/DirectFB/tests/dfbtest_font	\
	$(SOURCE)/DirectFB/tests/smiley_test



clean::

install::
	@(if test -z "$(DESTDIR)"; then echo "**** DESTDIR not set! ****"; exit 1; fi)
	install -d $(DESTDIR)$(datadir)
	install -d $(DESTDIR)$(datadir)/df_neo
	install -d $(DESTDIR)$(datadir)/shopfloor
	install -d $(DESTDIR)$(datadir)/quip
	install -d $(DESTDIR)$(sysconfdir)
	install -c -m 644 $(PHILIPS)/Tools/data/*.{gif,jpg,png,ttf} $(DESTDIR)$(datadir)/
	install -c -m 644 $(PHILIPS)/Tools/data/df_neo/*.{jpg,png} $(DESTDIR)$(datadir)/df_neo/
	install -c -m 644 $(PHILIPS)/Tools/data/quip/*.{dfiff,png,quip} $(DESTDIR)$(datadir)/quip/
	install -c -m 644 $(PHILIPS)/Tools/data/shopfloor/*.{png,sfa} $(DESTDIR)$(datadir)/shopfloor/
	install -c -m 644 $(PHILIPS)/Config/directfbrc* $(DESTDIR)$(sysconfdir)
	install -c -m 644 $(PHILIPS)/Config/fusiondalerc* $(DESTDIR)$(sysconfdir)
	install -c -m 644 $(PHILIPS)/Config/sawmanrc $(DESTDIR)$(sysconfdir)

