This package includes the jointSPACE remote application SDK in source format.
It allows you to port the SDK to new architectures or simply recompile it for the supported ones.

Architecture currently supported are:
- linux (X86 or other platforms)
- cygwin (X86)
- macos (Apple Mac)
- dslinux (NDS) 
- Apple iOS (iPhone, iPod, iPad...)
- Android 

The SDK includes all what you need to create native TV Remote Applications on remote devices:
header and librarie files.


Building
--------
Compile the SDK libraries (libdirectfb.o...):
  make -f makefile.voodoo.<architecture>

For Android and iPhone, don't do the above but use the dedicated build script instead:
e.g. for Android : 
1) set the variable NDK_PATH inside "build_for_android.sh" to the absolute location where your android NDK is installed.
2) Insure that the line containing -DVOODOO_PLAY_FAKE=1 is uncommented.
   Some phones are unable to receive UDP message which makes the jointSPACE
   discovery mechanism not working at all. This patch allows at least to detect
   directfb capable device (e.g. jointSPACE TV) but won't allow to identify
   the device as such (friendly name). We hope that can be fixed soon.  
   Some Android devices don't have that issue and don't need  that change (best is to try with and without)   
3)./build_for_android.sh



Create the "DirectFB_Voodoo" package containing the SDK libraries and header files.
  make -f makefile.voodoo.<architecture> package




Typical issues:
- $CC or $LD not reachable: adapt your $PATH
- pthread development files not installed
- incompatible shell: build-package.sh rely on bash being installed as /bin/sh.
- wrong permissions: chmod a+rwx build-package.sh.
- problems to generate DirectFB_Voodoo.tar.gz: this step might fail if your system does not support tar ball generation.


Installing
----------
Copy "DirectFB_Voodoo" (generated directory) where your remote application samples will be developped (typically you will
create a subdirectory next to "DirectFB_Voodoo" for each sample you will create) 

For Android, refer to this directory from the SDK jni makefile (Android.mk)


History:
-------
V1.2.1_beta6: 2011-03-03
Changes:
  - Solved devices caching issue in discovery 
    (a device disapearing from the network e.g. powered off will 
    be removed from the list)
  - removed VOODOO_PLAY_FAKE for Android 
    (obsolete; you need latest directfb voodoo fix in jni class)


V1.2.1_beta5: 2011-02-05
Changes:
  - added rc5 commands macros for key injection
  - minor update ofjsApi (test SW)
  - updated macos/iphone makefiles (clean)

V1.2.1_beta4: 2011-01-15
Changes:
  - extended jslibclient with few plfapi client libraries to allow plfApi remote calls (test SW)

V1.2.1_beta3: 2010-12-17
Changes:
  - Fix Android discovery
  - Add support for multiple directfb connections to multiple TVs at a time 
  - Fix coma notifications

V1.2.1_beta2: 2010-11-22
Changes:
  - add new voodoo API to support application server model
  - add voodoolay_server and voodoo_client tools in directfb/tools.
  - various DirectFB fixes
  - add jslibrc, jointSPACE Remote Control library and remco tool to ease key injection from remote application.

V1.2.1_beta1: 2010-09-13
Changes:
  - add support for Android (native code part).
  - note that the discovery mechanism has been temporary hacked for Android due to some phone not able to receive UDP messages.

V1.2: 2010-08-26
Changes:
  - updated DirectFB version to 2k11
  - support for fusiondale over voodoo

V1.1: 2010-06-06
Changes:
  - updated DirectFB version to 2k10H2


V1.0: 2010-04-11
Initial release based on 2k9 DirectFB (1.4)




          
