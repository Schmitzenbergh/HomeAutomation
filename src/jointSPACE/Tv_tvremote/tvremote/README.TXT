tvremote
========

Instructions:
-------------
Run tvremote.exe.
It will discover all the jointSPACE TVs on the local network.
By Default it will control the first TV discovered.

"Swipe" the panels using the mouse:
- The first panels offers the standard functionalities of a remote control, including a 4 directions "swipe pad"
  for the navigation...  
- The last panel lists the jointSPACE remote applications discovered on the local network servers and 
  allows starting an application on the TV from a simple click.

<ESC> to exit.



Notes:
----- 
- The application server and "tvremote" cannot run from the same machine,
  unless you use multiple virtual machines running on the same OS.
- In addition to the jointSPACE SDK and DirectFB, the tvremote application makes use
  of libpng, freetype, libjpeg and zlib for the local GUI.


Building instructions
---------------------
Assuming you start from the source package and that the SK1.2.1beta2 "DirectFB_Voodoo" SDK directory 
is located next to the "tvremote" directory

DIRECTFB_VOODOO=../DirectFB_Voodoo make

Cygwin version only for the moment.


History:
-------
V1.2: Add automatic jump to RC menu at first device discovery.

V1.1: Updated discovery procedure code.
      Based on SDK 1.2.1beta3. 

V1.0: Initial release.
      Based on SDK 1.2.1beta2. 













          
