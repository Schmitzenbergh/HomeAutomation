#set INCLUDES=-I$(NDK_PATH)/build/platforms/android-8/arch-arm/usr/include
export NDK_PATH=/opt/android/android-ndk-r4b
export NDK_TOOLCHAIN=$NDK_PATH/build/prebuilt/windows/arm-eabi-4.4.0/bin 
make -f makefile.voodoo.android libdirectfb.o
make -f makefile.voodoo.android package