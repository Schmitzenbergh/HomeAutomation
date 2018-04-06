/* 
 * Copyright © 2009, Koninklijke Philips Electronics N.V.
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 * -	Redistributions of source code must retain the above copyright notice, 
 *      this list of conditions and the following disclaimer.
 * -	Redistributions in binary form must reproduce the above copyright 
 *      notice, this list of conditions and the following disclaimer in the 
 *      documentation and/or other materials provided with the distribution.
 * -	Neither the name of the Koninklijke Philips Electronics N.V. nor the 
 *      names of its contributors may be used to endorse or promote products 
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <jslibrc_client.h>
#include <divine.h>



#define DFBCHECK(x...)                           \
do {                                             \
  DFBResult err;                                 \
  err = x;                                       \
  if (err != DFB_OK) {                           \
    printf ("Fail!! err!=DFB_OK");               \
    DirectFBError (#x, err);                     \
  }                                              \
} while(0);


#define HK_HOMESCREEN           DIKS_CUSTOM36
#define HK_MEDIA                DIKS_CUSTOM20
#define HK_TELETEXT             DIKS_CUSTOM17
#define HK_HTML                 DIKS_CUSTOM19
#define HK_DFU                  DIKS_CUSTOM49
#define HK_REMOTEAPP            DIKS_CUSTOM97

#define DFB_RAW_KEY             DIKS_CUSTOM31
#define DFB_AMBILIGHT           DIKS_CUSTOM33

#define NOTRCSOURCEMASK         0x20

typedef enum{
    MEDIA_USB,
    MEDIA_Network,
    MEDIA_Scenea,
    MEDIA_DRM
} EnumMediaStart;


static IDiVine                 *divine = NULL;
static DFBInputDeviceKeySymbol Rc6TranslateTable[0x100] =
{
    /****************************************************************************************************************************************************************************/
    /*      *   0x00 / 0x08         0x01 / 0x09         0x02 / 0x0A         0x03 / 0x0B         0x04 / 0x0C         0x05 / 0x0D         0x06 / 0x0E         0x07 / 0x0F         */
    /****************************************************************************************************************************************************************************/
    /* 0x00 */  DIKS_0,             DIKS_1,             DIKS_2,             DIKS_3,             DIKS_4,             DIKS_5,             DIKS_6,             DIKS_7,
    /*      */  DIKS_8,             DIKS_9,             DIKS_PREVIOUS,      DFB_RAW_KEY,        DIKS_POWER,         DIKS_MUTE,          DFB_RAW_KEY,        DIKS_INFO,
    /* 0x10 */  DIKS_VOLUME_UP,     DIKS_VOLUME_DOWN,   DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_CHANNEL_UP,    DIKS_CHANNEL_DOWN,
    /* 0x20 */  DIKS_CHANNEL_UP,    DIKS_CHANNEL_DOWN,  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DIKS_FASTFORWARD,   DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_REWIND,        DIKS_PLAYPAUSE,     DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /* 0x30 */  DFB_RAW_KEY,        DIKS_STOP,          DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_STOP,          DIKS_RECORD,
    /*      */  DIKS_NEXT,          DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_TEXT,          DIKS_POWER2,        DFB_RAW_KEY,        DIKS_TUNER,
    /* 0x40 */  DIKS_OPTION,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_SUBTITLE,      DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /* 0x50 */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_MENU,          DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DIKS_CURSOR_UP,     DIKS_CURSOR_DOWN,   DIKS_CURSOR_LEFT,   DIKS_CURSOR_RIGHT,  DIKS_OK,            DIKS_MODE,          DFB_RAW_KEY,        DFB_RAW_KEY,
    /* 0x60 */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_RED,           DIKS_GREEN,         DIKS_YELLOW,
    /* 0x70 */  DIKS_BLUE,          DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_SUBTITLE,      DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /* 0x80 */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_AMBILIGHT,
    /* 0x90 */  DFB_AMBILIGHT,      DFB_AMBILIGHT,      DFB_AMBILIGHT,      DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_TUNER,
    /* 0xA0 */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /* 0xB0 */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        HK_HTML,            DFB_RAW_KEY,
    /* 0xC0 */  DFB_RAW_KEY,        DIKS_PLAYPAUSE,     DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_EPG,           DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /* 0xD0 */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DIKS_PERIOD,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /* 0xE0 */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,
    /* 0xF0 */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DIKS_ZOOM,          DFB_RAW_KEY,        DFB_RAW_KEY,
    /*      */  DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY,        DFB_RAW_KEY
    /****************************************************************************************************************************************************************************/
};



static int SendKeyDown(int keyname,int src,int sys,int cmd )
{
   DFBInputEvent event;
   unsigned long key_code;
   if (divine)
   {
       src |= NOTRCSOURCEMASK;
       key_code = (((unsigned int)src & 0xff) << 24) | (((unsigned int)sys & 0xff) << 16) | ((unsigned int)cmd & 0xffff);

       event.clazz = DFEC_INPUT;
       event.type = DIET_KEYPRESS;
       event.key_code = key_code;
       event.key_symbol = keyname;
       event.flags = DIEF_KEYCODE | DIEF_KEYSYMBOL;

       DFBCHECK(divine->SendEvent (divine, &event));
   }

   return 1;
}

static int SendKeyUp(int keyname,int src,int sys,int cmd )
{
   DFBInputEvent event;
   unsigned long key_code;
   if (divine)
   {
       src |= NOTRCSOURCEMASK;
       key_code = (((unsigned int)src & 0xff) << 24) | (((unsigned int)sys & 0xff) << 16) | ((unsigned int)cmd & 0xffff);

       event.clazz = DFEC_INPUT;
       event.type = DIET_KEYRELEASE;
       event.key_code = key_code;
       event.key_symbol = keyname;
       event.flags = DIEF_KEYCODE | DIEF_KEYSYMBOL;

       DFBCHECK(divine->SendEvent (divine, &event));
   }

   return 1;
}

static int SendKeyHK(int keyname,int src,int sys,int cmd )
{
    unsigned long key_code;
	DFBInputEvent event;
	int dfb_ret;
    int ret = 0;
    if (divine)
	{
        src |= NOTRCSOURCEMASK;
        key_code = (((unsigned int)src & 0xff) << 24) | (((unsigned int)sys & 0xff) << 16) | ((unsigned int)cmd & 0xffff);

	    event.clazz = DFEC_INPUT;
	    event.type = DIET_KEYPRESS;
	    event.key_code = key_code;
	    event.key_symbol = keyname;
		event.flags = DIEF_KEYCODE | DIEF_KEYSYMBOL;

	    dfb_ret = divine->SendEvent (divine, &event);
        printf("ReturnKey retval = %d\n", dfb_ret );
        ret = 1;
    }

    return ret;
}





int
jslibrc_Init( int *argc, char **argv[] )
{
    DFBResult ret;

    ret = DiVineInit( argc, argv );
    if (ret) {
        return ret;
    }

    ret = DiVineCreate( &divine );
    if (ret) {
        return ret;
    }

    return 0;
}

void
jslibrc_Exit( void )
{
    if (divine) {
        divine->Release(divine);
        divine = NULL;
    }
}

void
jslibrc_KeyDown( int src, int sys, int cmd )
{
    if ( (cmd >= 0) && (cmd <= 0xff) ) SendKeyDown(Rc6TranslateTable[cmd], keySourceRc6, 0, cmd);
}

void
jslibrc_KeyUp( int src, int sys, int cmd )
{
	 if ( (cmd >= 0) && (cmd <= 0xff) ) SendKeyUp(Rc6TranslateTable[cmd], keySourceRc6, 0, cmd);
}

int
jslibrc_RequestActivity( amLib_EnumActivityId act, amLib_EnumActivation mode, int cookie )
{
    switch(act)
	{
        case amLib_ACT_HomeScreen:
            SendKeyHK(HK_HOMESCREEN, 0, 0, mode);
            break;                    
        case amLib_ACT_WatchTV:
//            key_KeyDown( source, system, command );
            SendKeyHK(DIKS_TUNER, 3, 0, mode);
            break;                    
        case amLib_ACT_BrowseUSB:
            SendKeyHK(HK_MEDIA, MEDIA_USB,0,mode);
            break;
        case amLib_ACT_BrowseDLNA:
            SendKeyHK(HK_MEDIA, MEDIA_Network,0,mode);
            break;        
        case amLib_ACT_NetTV:
            SendKeyHK(HK_HTML, 0, 0, mode);
            break;
        case amLib_ACT_Dfu:
            SendKeyHK(HK_DFU, 0, 0, mode);
            break;
        case amLib_ACT_Teletext:
            SendKeyHK(HK_TELETEXT, 0, 0, mode);
            break;
        case amLib_ACT_RemoteApp:
            SendKeyHK(HK_REMOTEAPP, 0, 0, mode);
            break;
        default:
            break;
	}
}
