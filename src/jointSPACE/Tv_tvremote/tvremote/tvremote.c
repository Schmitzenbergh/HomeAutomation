#include <directfb.h>

#include <direct/debug.h>
#include <direct/interface.h>
#include <direct/mem.h>
#include <direct/messages.h>
#include <direct/util.h>

#include <voodoo/play.h>
#include <voodoo/ivoodooplayer.h>


#include <pngdec.h>
#include <ttfdec.h>
#include <mem.h>
#include <gui.h>
#include <widgets.h>
#include <keyboard.h>
#include <ttfdec.h>
#include <console.h>
#include <std.h>
#include <pthread.h>


#define JSLIBRC 1
#define PLAYER  1
//#define DFB    1

#define DFBCHECK(x...)                           \
do {                                             \
  DFBResult err;                                 \
  err = x;                                       \
  if (err != DFB_OK) {                           \
    printf ("Fail!! err!=DFB_OK");               \
    DirectFBError (#x, err);                     \
  }                                              \
} while(0);

#ifdef __WIN32__
#include <windows.h>
#endif

/**************************************
* Local macros/typedef
**************************************/
#define DEFAULT_FNT      "./decker.ttf"
#define WIN_W            320
#define WIN_H            428//480//428
#define WIN_PIXFORMAT    DSPF_ARGB  //DSPF_RGB16   // DSPF_ARGB4444


/***************************************
* Local data
***************************************/
#ifdef __WIN32__
static HINSTANCE              m_hInstance;
static HWND                   m_hwnd;
static HDC                    m_window_dc;
static HDC                    m_bitmap_dc;
static HBITMAP                m_bitmap;
static DFBSurfacePixelFormat  m_format=WIN_PIXFORMAT;
static GuiBitmap              frontbuffer;
#endif
#ifdef DFB
static IDirectFB              *dfb = NULL;;
static IDirectFBEventBuffer   *events = NULL;
static IDirectFBSurface       *gsurface = NULL;
#endif
#ifdef PLAYER
static VoodooPlayer           *player = NULL;
static VoodooPlayInfo         info;
#define PLAYERRENDERENAME     "PhilipsTV"
#define MAXPLAYERS            8
#define MAXPLAYERNAMESIZE     VOODOO_PLAYER_NAME_LENGTH
#define MAXIPSIZE             16
//VOODOO_PLAYER_NAME_LENGTH
//VOODOO_PLAYER_MODEL_LENGTH
//VOODOO_PLAYER_VENDOR_LENGTH
#define MAXUUIDSIZE           33
#define MAXAPPLICATIONS       16
#define MAXAPPLICATIONNAMESIZE  VOODOO_APP_DESCRIPTION_NAME_LENGTH
#define DISCOVERED_MAXCNT     3
static char                   players[MAXPLAYERS][MAXIPSIZE];                         //xyz.xyz.xyz.xyz
static char                   playersuuid[MAXPLAYERS][MAXUUIDSIZE];                   //32 chars
static int                    playernb=0; 
static char                   applications[MAXAPPLICATIONS][MAXAPPLICATIONNAMESIZE]; 
static char                   applicationsuuid[MAXAPPLICATIONS][MAXUUIDSIZE];         //32 chars
static char                   applicationsip[MAXAPPLICATIONS][MAXIPSIZE];             //xyz.xyz.xyz.xyz
static int                    applicationnb=0; 
static char                   discovered[MAXPLAYERS][MAXIPSIZE];
static char                   discoveredcnt[MAXPLAYERS];
static int                    discoverednb=0;
static unsigned char          m_launch_app_uuid[16];
static unsigned char          m_launch_player_uuid[16];
static unsigned char          instance_uuid[16];
static pthread_mutex_t        wait_mutex;
static pthread_t              threadId;

#endif
static void                   *m_pixels;
static int                    m_pitch;
static int                    m_depth;
static int                    m_resolutionWidth;
static int                    m_resolutionHeight;
static GuiBitmap              backbuffer;
static int                    mx,my,mb;
static int                    quit = 0;
static int                    updated = 1;

//static GTTFnt                 fontsmall;
static char                   stdbuffer1[512];
static char                   stdbuffer2[512];
static int                    menu,node1,node2,node3,node4,node5;

#ifdef JSLIBRC
#include <jslibrc_client.h>

static int rc6Codes[]=
{
rc6S0Standby,			// ICON_STANDBY          
rc6S0MenuOn,			// ICON_HOME             
rc6S0PreviousProgram,	// ICON_BACK             
rc6S0EpgGuide,			// ICON_BROWSE           
rc6S0ContextualOptions,	// ICON_OPTIONS          
rc6S0Red,				// ICON_RED              
rc6S0Green,				// ICON_GREEN            
rc6S0Yellow,			// ICON_YELLOW           
rc6S0Cyan,				// ICON_BLUE             
rc6S0VolumeUp,			// ICON_VOLUMEUP         
rc6S0VolumeDown,		// ICON_VOLUMEDOWN       
rc6S0MuteDemute,		// ICON_MUTE             
rc6S0Next,				// ICON_PROGRAMUP        
rc6S0Previous,			// ICON_PROGRAMDOWN      
rc6S0Digit0,			// ICON_0                
rc6S0Digit1,			// ICON_1                
rc6S0Digit2,			// ICON_2                
rc6S0Digit3,			// ICON_3                
rc6S0Digit4,			// ICON_4                
rc6S0Digit5,			// ICON_5                
rc6S0Digit6,			// ICON_6                
rc6S0Digit7,			// ICON_7                
rc6S0Digit8,			// ICON_8                
rc6S0Digit9,			// ICON_9                
rc6S0Play,				// ICON_PLAY             
rc6S0Stop,				// ICON_STOP             
rc6S0ScanReverse,		// ICON_BACKWARD         
rc6S0FastForward,		// ICON_FORWARD          
-1,						// ICON_TELETEXT         
-1,						// ICON_NETTV            
-1,						// ICON_USB              
-1,						// ICON_DLNA             
rc6S0AmbLightMode,		// ICON_EXPERIENCE             
rc6S0Acknowledge,		// ICON_TOUCHPAD         
};
#endif


#define ICON_STANDBY          0
#define ICON_HOME             2
#define ICON_BACK             4
#define ICON_BROWSE           6
#define ICON_OPTIONS          8
#define ICON_RED              10
#define ICON_GREEN            12
#define ICON_YELLOW           14
#define ICON_BLUE             16
#define ICON_VOLUMEUP         18
#define ICON_VOLUMEDOWN       20
#define ICON_MUTE             22
#define ICON_PROGRAMUP        24
#define ICON_PROGRAMDOWN      26
#define ICON_0                28
#define ICON_1                30
#define ICON_2                32
#define ICON_3                34
#define ICON_4                36
#define ICON_5                38
#define ICON_6                40
#define ICON_7                42
#define ICON_8                44
#define ICON_9                46
#define ICON_PLAY             48
#define ICON_STOP             50
#define ICON_BACKWARD         52
#define ICON_FORWARD          54
#define ICON_TELETEXT         56
#define ICON_NETTV            58
#define ICON_USB              60
#define ICON_DLNA             62
#define ICON_EXPERIENCE       64
#define ICON_TOUCHPAD         66
#define ICON_PROGRAM          68
#define ICON_NEXT             70
#define ICON_PREVIOUS         72


static char * bmpTable[] = {
"iPhone_power_OFF.png",
"iPhone_power_ON.png",
"iPhone_home_OFF.png",
"iPhone_home_ON.png",
//"bmp_power_OFF.png",
//"bmp_power_ON.png",
//"bmp_home_OFF.png",
//"bmp_home_ON.png",

"iPhone_back_OFF.png",
"iPhone_back_ON.png",
"iPhone_browse_OFF.png",
"iPhone_browse_ON.png",
"iPhone_options_OFF.png",
"iPhone_options_ON.png",

"iPhone_red_OFF.png",
"iPhone_red_ON.png",
"iPhone_green_OFF.png",
"iPhone_green_ON.png",
"iPhone_yellow_OFF.png",
"iPhone_yellow_ON.png",
"iPhone_blue_OFF.png",
"iPhone_blue_ON.png",

//"bmp_red_OFF.png",
//"bmp_red_ON.png",
//"bmp_green_OFF.png",
//"bmp_green_ON.png",
//"bmp_yellow_OFF.png",
//"bmp_yellow_ON.png",
//"bmp_blue_OFF.png",
//"bmp_blue_ON.png",


"iPhone_bar_+_OFF.png",
"iPhone_bar_+_ON.png",
"iPhone_bar_-_OFF.png",
"iPhone_bar_-_ON.png",
"iPhone_bar_volume_OFF.png",
"iPhone_bar_volume_ON.png",
"iPhone_bar_+_OFF.png",
"iPhone_bar_+_ON.png",
"iPhone_bar_-_OFF.png",
"iPhone_bar_-_ON.png",

"iPhone_0_OFF.png",
"iPhone_0_ON.png",
"iPhone_1_OFF.png",
"iPhone_1_ON.png",
"iPhone_2_OFF.png",
"iPhone_2_ON.png",
"iPhone_3_OFF.png",
"iPhone_3_ON.png",
"iPhone_4_OFF.png",
"iPhone_4_ON.png",
"iPhone_5_OFF.png",
"iPhone_5_ON.png",
"iPhone_6_OFF.png",
"iPhone_6_ON.png",
"iPhone_7_OFF.png",
"iPhone_7_ON.png",
"iPhone_8_OFF.png",
"iPhone_8_ON.png",
"iPhone_9_OFF.png",
"iPhone_9_ON.png",

"iPhone_play_OFF.png",
"iPhone_play_ON.png",
"iPhone_stop_OFF.png",
"iPhone_stop_ON.png",
"iPhone_backward_OFF.png",
"iPhone_backward_ON.png",
"iPhone_forward_OFF.png",
"iPhone_forward_ON.png",

"iPhone_teletext_OFF.png",
"iPhone_teletext_ON.png",
"iPhone_NetTV_OFF.png",
"iPhone_NetTV_ON.png",
"iPhone_USB_OFF.png",
"iPhone_USB_ON.png",
"iPhone_DLNA_OFF.png",
"iPhone_DLNA_ON.png",
"iPhone_experinence_OFF.png",
"iPhone_experinence_ON.png",

"iPhone_touchpad.png",
"iPhone_touchpad.png", // double!
"iPhone_bar_zap_OFF.png",
"iPhone_bar_zap_ON.png",

"iPhone_next_OFF.png",
"iPhone_next_ON.png",
"iPhone_prev_OFF.png",
"iPhone_prev_ON.png",



"knoppen_text_OFF.png",
"knoppen_text_ON.png",
"backspace.png",
"brushed-metal.png",
"goBack.png",
"iPhone_bar_zap_OFF.png",
"iPhone_bar_zap_ON.png",
"iPhone_nosound_OFF.png",
"iPhone_nosound_ON.png",
"iPhone_point_OFF.png",
"iPhone_point_ON.png",
"iPhone_sound_OFF.png",
"iPhone_sound_ON.png",
"iPhone_volume-line.png",
"searchfortv.png",
"tabbar_basic.png",
"tabbar_cursors.png",
"tabbar_custom.png",
"tabbar_digits.png",
"tabbar_help.png",
"tabbar_keyboard.png",
"tabbar_menu.png",
"tabbar_pictureframe.png",
"tabbar_play.png",
NULL
};

static const char      *VoodooRendererListDataDefault = "Searching TVs ...";
static const char      *VoodooApplicationListDataDefault = "Searching applications ...";
static int             VoodooRendererListIndex;
static int             VoodooRendererListSize;
static int             VoodooApplicationListIndex;
static int             VoodooApplicationListSize;
static char            *VoodooRendererListData[MAXPLAYERS];
static char            *VoodooApplicationListData[MAXAPPLICATIONS];


/***************************************
* Local procedures
***************************************/
#ifdef __WIN32__
/**********************************************************************************************************************/
static LRESULT CALLBACK WndProc( HWND hwnd,        // handle to window
								 UINT uMsg,        // message identifier
								 WPARAM wParam,    // first message parameter
								 LPARAM lParam )   // second message parameter
{
     RECT r;

     switch (uMsg) {
          case WM_MOUSEMOVE:
			   mx = (int)(lParam&0xFFFF);
			   my = (int)(lParam>>16);
//printf("%d, %d => %d\n", (int)(lParam&0xFFFF),(int)(lParam>>16),(int)mb);
			   key_OnMouseMove(mx, my, mb);
			   break;

		  case WM_LBUTTONDOWN:
			   mb = 1;
			   key_OnMouseMove(mx, my, mb);
               break;

          case WM_LBUTTONUP:
			   mb = 0;
			   key_OnMouseMove(mx, my, mb);
               break;

          case WM_KEYDOWN:
//printf( "Key 0x%x\n", wParam );
               switch (wParam) 
			   {
                    case VK_ESCAPE:   
						quit = 1; 
						break;
                    case VK_UP:
//						butAdd();
						key_OnKeyDown(SOURCE_KEYB, KEY_UP);
						break;
                    case VK_DOWN:
						key_OnKeyDown(SOURCE_KEYB, KEY_DOWN);
						break;
                    case VK_LEFT:
						key_OnKeyDown(SOURCE_KEYB, KEY_LEFT);
						break;
                    case VK_RIGHT:
						key_OnKeyDown(SOURCE_KEYB, KEY_RIGHT);
						break;
                    case VK_SPACE:
						key_OnKeyDown(SOURCE_KEYB, KEY_SPACE);
						break;
			   };
               break;

          case WM_SYSCOMMAND:
               printf( "SysCommand 0x%x\n", wParam );
               break;

          case WM_PAINT:
               if (GetUpdateRect( hwnd, &r, FALSE )) 
			   {
                    PAINTSTRUCT paint;
                    HDC         hdc;

                    hdc = BeginPaint( hwnd, &paint );

                    BitBlt( m_window_dc, r.left, r.top, r.right - r.left, r.bottom - r.top,
                            m_bitmap_dc, r.left, r.top, SRCCOPY );

                    EndPaint( hwnd, &paint );
               }
               break;

          case WM_TIMER:
               break;

          case WM_CLOSE:
               DestroyWindow( hwnd );
               break;

          case WM_DESTROY:
               PostQuitMessage( 0 );
               break;
     }

     return DefWindowProc( hwnd, uMsg, wParam, lParam );
}

/**********************************************************************************************************************/
static void * System_Init()
{
     m_hInstance = GetModuleHandle( NULL );


     WNDCLASSEX wndClass;

     ZeroMemory( &wndClass, sizeof(wndClass) );

     wndClass.cbSize        = sizeof(wndClass);
     wndClass.style         = CS_HREDRAW | CS_VREDRAW;
     wndClass.lpfnWndProc   = WndProc;
     wndClass.cbClsExtra    = 0;
     wndClass.cbWndExtra    = 0;
     wndClass.hInstance     = m_hInstance;
     wndClass.hIcon         = NULL;
     wndClass.hIconSm       = NULL;
     wndClass.hCursor       = LoadCursor( NULL, IDC_CROSS );
     wndClass.hbrBackground = (HBRUSH) GetStockObject( NULL_BRUSH );
     wndClass.lpszMenuName  = NULL;
     wndClass.lpszClassName = "Philips RC";

     if (!RegisterClassEx( &wndClass )) {
          D_ERROR( "SaWMan/Updates: RegisterClassEx() failed!\n" );
          return NULL;
     }

     RECT r = { 0, 0, m_resolutionWidth, m_resolutionHeight };

     AdjustWindowRect( &r, WS_CAPTION | WS_BORDER | WS_SYSMENU, FALSE );

     m_hwnd = CreateWindowEx( 0,
                                "Philips RC",
                                "Philips RC",
                                WS_CAPTION | WS_BORDER | WS_SYSMENU,
                                CW_USEDEFAULT,
                                CW_USEDEFAULT,
                                r.right  - r.left,
                                r.bottom - r.top,
                                NULL,
                                NULL,
                                m_hInstance,
                                NULL );

     ShowWindow( m_hwnd, SW_SHOW );




     m_window_dc  = GetDC( m_hwnd );
     m_bitmap_dc  = CreateCompatibleDC( m_window_dc );

     BITMAPINFO bitmap_info = {{
          biSize:           sizeof(BITMAPINFOHEADER),
          biWidth:          m_resolutionWidth,
          biHeight:         m_resolutionHeight,
          biPlanes:         1,
          biBitCount:       DFB_BITS_PER_PIXEL(m_format),
          biCompression:    BI_RGB,
          biSizeImage:      0,
          biXPelsPerMeter:  0,
          biYPelsPerMeter:  0,
          biClrUsed:        0,
          biClrImportant:   0,
     }};

     m_bitmap  = CreateDIBSection( m_window_dc, &bitmap_info, DIB_RGB_COLORS, &m_pixels, NULL, 0 );


     BITMAP bitmap;

     GetObject( m_bitmap, sizeof(BITMAP), &bitmap );

     m_pitch = bitmap.bmWidthBytes;

     SelectObject( m_bitmap_dc, m_bitmap );

     gui_BitmapCreate(GUIBIF_PREALLOCATED, m_resolutionWidth, m_resolutionHeight, m_pitch, GUIPFM_ARGB8888, m_pixels, &frontbuffer);

     return (void*)(long) m_hwnd;
}

/**********************************************************************************************************************/
static void System_Finalize( void *ctx )
{
     gui_BitmapDestroy(&frontbuffer);

     DeleteDC( m_window_dc );
     DeleteDC( m_bitmap_dc );
     DeleteObject( m_bitmap );
}

/**********************************************************************************************************************/
static int System_GetCommand( void *ctx )
{
     MSG msg;

     if( PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ) )
     {
       if( !GetMessage( &msg, NULL, 0, 0 ) )
       {
         return msg.wParam;
       }
       TranslateMessage(&msg);
       DispatchMessage(&msg);
     }

     return -1;
}
#endif


/**********************************************************************************************************************/
static void DirectFB_Init(void)
{
#ifdef DFB
    char                          fontname[128];
    char                          text[256];
    int                           tw,th;
    IDirectFBDisplayLayer         *layer;
    DFBWindowDescription          wdesc;
    IDirectFBWindow               *gwindow;
    DFBFontDescription            fontdesc;
    IDirectFBFont                 *font;
#endif
#ifdef JSLIBRC
    jslibrc_Init( NULL, NULL );
#endif
#ifdef DFB
    DFBCHECK(DirectFBCreate( &dfb ));

    /* Obtain the layer */
    DFBCHECK(dfb->GetDisplayLayer(dfb, DLID_PRIMARY, &layer));

    /* Setup the Graphical window */
    wdesc.flags  = (DFBWindowDescriptionFlags)( DWDESC_POSX | DWDESC_POSY | DWDESC_WIDTH | DWDESC_HEIGHT 
                    | DWDESC_OPTIONS | DWDESC_PIXELFORMAT | DWDESC_STACKING);
    wdesc.posx   = 0;
    wdesc.posy   = 0;
	wdesc.width  = m_resolutionWidth;
	wdesc.height = m_resolutionHeight;
	if (m_depth == 4)
	{
	    wdesc.pixelformat = DSPF_ARGB;
	}
	else
	{
	    wdesc.pixelformat = DSPF_RGB16;
	}
    wdesc.stacking  = DWSC_MIDDLE;
    wdesc.options   = DWOP_NONE;
    DFBCHECK(layer->CreateWindow(layer, &wdesc, &gwindow));
    DFBCHECK(gwindow->GetSurface(gwindow, &gsurface));
    DFBCHECK(gsurface->Clear( gsurface, 0x00, 0x00, 0x00, 0x00 ));
//  DFBCHECK(gwindow->SetColorKey(gwindow, 0x00, 0x00, 0x00));

    /* Create event buffer and request focus */
    DFBCHECK(gwindow->CreateEventBuffer( gwindow, &events ));
    DFBCHECK(gwindow->SetOpacity( gwindow, 0xFF ));
    DFBCHECK(gwindow->RequestFocus( gwindow )); 
    DFBCHECK(gsurface->Flip( gsurface, NULL, DSFLIP_NONE ));

    /* Create font */
    strncpy (fontname, DEFAULT_FNT, sizeof(fontname) );
    strncpy (text, "Hello Voodoo World !", sizeof(text) );
    fontdesc.flags       = DFDESC_HEIGHT | DFDESC_ATTRIBUTES;
    fontdesc.attributes  = DFFA_NONE;
    fontdesc.height      = 20;
    DFBCHECK(dfb->CreateFont(dfb, fontname, &fontdesc, &font));

    DFBCHECK(gsurface->SetFont (gsurface, font));
    DFBCHECK(font->GetHeight  (font, &th));
    DFBCHECK(font->GetStringWidth  (font, text, -1, &tw));
#endif
}


/**********************************************************************************************************************/
static void DirectFB_Finalize( void )
{
#ifdef JSLIBRC
	jslibrc_Exit();
#endif
#ifdef DFB
    if (events)
	{
        DFBCHECK(events->Release( events ));
		events = NULL;
	}
    if (dfb)
	{
        DFBCHECK(dfb->Release( dfb ));
		dfb = NULL;
	}
#endif
}


/**********************************************************************************************************************/
#ifdef PLAYER 
static DirectEnumerationResult player_callback( void                    *ctx,
												const VoodooPlayInfo    *info,
												const VoodooPlayVersion *version,
												const char              *address,
												unsigned int             ms_since_last_seen )
{
    IVoodooPlayer *player;
    DirectResult  ret;
    char          buf[MAXUUIDSIZE];
	int           i,j;
    VoodooAppDescription apps[MAXAPPLICATIONS];
    unsigned int  num;
    unsigned char uuid[16];
	unsigned int a,b,c,d;
	buf[32] = 0;
    DirectFBSetOption( "remote", address );
    ret = VoodooPlayerCreate( &player );
    if (ret) /* Could NOT create a player, it is a renderer ...*/
	{
		if (     (!std_strcmp(info->name, "Unknown")) 
			  && (!std_strcmp(info->vendor, "Unknown")) 
			  && (!std_strcmp(info->model, "Unknown")) )
		{
			/* You must fake the UUI based on the IP address */
			/* Old TV combinaison with Android, no way to get valid parameters */
			uuid[0] = 0xf0;uuid[1] = 0xf0;uuid[2] = 0xf0;uuid[3] = 0xf0;
			uuid[4] = 0xf0;uuid[5] = 0xf0;uuid[6] = 0xf0;uuid[7] = 0xf0;
			uuid[8] = 0xf0;uuid[9] = 0xf0;uuid[10] = 0xf0;uuid[11] = 0xf0;
//			sscanf( address, "%d.%d.%d.%d", &uuid[12], &uuid[13], &uuid[14], &uuid[15]);
			sscanf( address, "%u.%u.%u.%u", &a, &b, &c, &d);
            uuid[12]=(unsigned char)a; uuid[13]=(unsigned char)b; uuid[14]=(unsigned char)c; uuid[15]=(unsigned char)d;
			snprintf( buf, sizeof(buf), "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
               uuid[0], uuid[1], uuid[2], uuid[3], uuid[4],
               uuid[5], uuid[6], uuid[7], uuid[8], uuid[9],
               uuid[10], uuid[11], uuid[12], uuid[13], uuid[14],
               uuid[15] );
		}
		else
		{
			/* All parameters should be valid */
			snprintf( buf, sizeof(buf), "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
               info->uuid[0], info->uuid[1], info->uuid[2], info->uuid[3], info->uuid[4],
               info->uuid[5], info->uuid[6], info->uuid[7], info->uuid[8], info->uuid[9],
               info->uuid[10], info->uuid[11], info->uuid[12], info->uuid[13], info->uuid[14],
               info->uuid[15] );
		}
		for (i=0; i<playernb; i++ )
		{
			if (!std_strcmp(buf, playersuuid[i])) break;
		}
		if ( (i == playernb) && (playernb != MAXPLAYERS) )
		{

			std_strcpy(playersuuid[playernb], buf);
			std_strcpy(players[playernb], address);
			// set first discovered as default renderer!!! 
			if (!playernb) 
			{
				DFBCHECK(DirectFBSetOption( "remote", address ));
				DirectFB_Init();
				key_OnKeyDown(SOURCE_KEYB, KEY_RIGHT);
			}
			playernb++;
			VoodooRendererListIndex = 0;
			VoodooRendererListSize= 0;
			for (i=0; i<playernb; i++ )
			{
				VoodooRendererListData[i] =  players[i];
//printf("JJJJJJJ=>%s/%d\n",VoodooRendererListData[i],playernb);
			}
			VoodooRendererListSize = playernb;
			updated = 1;
		}
	}
	else /* Could create a player, it must be a application server ...*/
	{
        ret = player->GetApps( player, MAXAPPLICATIONS, &num, apps );
        if (ret) {
            D_DERROR( ret, "Voodoo/Play/Client: IVoodooPlayer::GetApps() failed!\n" );
            player->Release( player );
            return DENUM_OK;
		}
        for (i=0; i<num; i++) 
		{
			if ( (applicationnb != MAXAPPLICATIONS) )
			{
                snprintf( buf, sizeof(buf), "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                    apps[i].uuid[0], apps[i].uuid[1], apps[i].uuid[2], apps[i].uuid[3], apps[i].uuid[4],
                    apps[i].uuid[5], apps[i].uuid[6], apps[i].uuid[7], apps[i].uuid[8], apps[i].uuid[9],
                    apps[i].uuid[10], apps[i].uuid[11], apps[i].uuid[12], apps[i].uuid[13], apps[i].uuid[14],
                    apps[i].uuid[15] );

				for (j=0; j<applicationnb; j++ )
				{
					if (!std_strcmp(buf, applicationsuuid[j])) break;
				}
			    if (j == applicationnb)
				{
					std_strcpy(applications[applicationnb], apps[i].name);
					std_strcpy(applicationsip[applicationnb], address);
					std_strcpy(applicationsuuid[applicationnb], buf);
					applicationnb++;
				}
			}
		}
//		VoodooApplicationListIndex = 0;
//		VoodooApplicationListSize= 0;
		for (i=0; i<applicationnb; i++ )
		{
			  VoodooApplicationListData[i] =  applications[i];
		}
		VoodooApplicationListSize = applicationnb;
		updated = 1;
        player->Release( player );
	}


	/* Discovery table update */
	pthread_mutex_lock(&wait_mutex);
	for (i=0; i<discoverednb; i++ )
	{
		if (!std_strcmp(address, discovered[i]))
		{
			discoveredcnt[i] = DISCOVERED_MAXCNT;
			break;
		}
	}
	if ( (i == discoverednb) && (discoverednb != MAXPLAYERS) )
	{
		std_strcpy(discovered[discoverednb], address);
		discoveredcnt[discoverednb] = DISCOVERED_MAXCNT;
		discoverednb++;
	}
	pthread_mutex_unlock(&wait_mutex);

    return DENUM_OK;
}
#endif



/**********************************************************************************************************************/
static int VoodooRendererCallback(int command, int data)
{
    int retval = 0;

	switch (command)
	{
		case WIDCALL_UNDEFINED:
			return ((int)(VoodooRendererListDataDefault));
			break;
		case WIDCALL_PROPDATA:
			return ((int)(VoodooRendererListData));
			break;
		case WIDCALL_PROPLEN:
			return (VoodooRendererListSize);
			break;
		case WIDCALL_PROPNEXT:
			if (VoodooRendererListIndex < (VoodooRendererListSize-1))
			{
                VoodooRendererListIndex++;
			    retval = 1;
			}
			break;
		case WIDCALL_PROPPREV:
			if (VoodooRendererListIndex)
			{
                VoodooRendererListIndex--;
			    retval = 1;
			}
			break;
		case WIDCALL_PROPGET:
			retval = VoodooRendererListIndex;
			break;
		case WIDCALL_PROPSET:
			VoodooRendererListIndex = data;
			if (VoodooRendererListSize) 
			{
				DirectFB_Finalize();
				DFBCHECK(DirectFBSetOption( "remote", VoodooRendererListData[VoodooRendererListIndex] ));
//printf("Switching device to %s...\n",VoodooRendererListData[VoodooRendererListIndex]);
				DirectFB_Init();
			}
			break;
	}

	return(retval);
}


/**********************************************************************************************************************/
static int VoodooApplicationCallback(int command, int data)
{
    int retval = 0;
    IVoodooPlayer *player;
    DirectResult ret;

	switch (command)
	{
		case WIDCALL_UNDEFINED:
			return ((int)(VoodooApplicationListDataDefault));
			break;
		case WIDCALL_PROPDATA:
			return ((int)(VoodooApplicationListData));
			break;
		case WIDCALL_PROPLEN:
			return (VoodooApplicationListSize);
			break;
		case WIDCALL_PROPNEXT:
			if (VoodooApplicationListIndex < (VoodooApplicationListSize-1))
			{
                VoodooApplicationListIndex++;
			    retval = 1;
			}
			break;
		case WIDCALL_PROPPREV:
			if (VoodooApplicationListIndex)
			{
                VoodooApplicationListIndex--;
			    retval = 1;
			}
			break;
		case WIDCALL_PROPGET:
			retval = VoodooApplicationListIndex;
			break;
		case WIDCALL_PROPSET:
			VoodooApplicationListIndex = data;
#ifdef PLAYER
			if (VoodooApplicationListSize) 
			{
                DFBCHECK(DirectFBSetOption( "remote", applicationsip[VoodooApplicationListIndex] ));
                ret = VoodooPlayerCreate( &player );
                if (ret) 
				{
                    D_DERROR( ret, "Voodoo/Play/Client: VoodooPlayerCreate() failed!\n" );
                    return retval;
				}
			    sscanf( applicationsuuid[VoodooApplicationListIndex], "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                       (unsigned int*)&m_launch_app_uuid[0], (unsigned int*)&m_launch_app_uuid[1], (unsigned int*)&m_launch_app_uuid[2], (unsigned int*)&m_launch_app_uuid[3], (unsigned int*)&m_launch_app_uuid[4],
                       (unsigned int*)&m_launch_app_uuid[5], (unsigned int*)&m_launch_app_uuid[6], (unsigned int*)&m_launch_app_uuid[7], (unsigned int*)&m_launch_app_uuid[8], (unsigned int*)&m_launch_app_uuid[9],
                       (unsigned int*)&m_launch_app_uuid[10], (unsigned int*)&m_launch_app_uuid[11], (unsigned int*)&m_launch_app_uuid[12], (unsigned int*)&m_launch_app_uuid[13], (unsigned int*)&m_launch_app_uuid[14],
                       (unsigned int*)&m_launch_app_uuid[15] );
                sscanf( playersuuid[VoodooRendererListIndex], "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                       (unsigned int*)&m_launch_player_uuid[0], (unsigned int*)&m_launch_player_uuid[1], (unsigned int*)&m_launch_player_uuid[2], (unsigned int*)&m_launch_player_uuid[3], (unsigned int*)&m_launch_player_uuid[4],
                       (unsigned int*)&m_launch_player_uuid[5], (unsigned int*)&m_launch_player_uuid[6], (unsigned int*)&m_launch_player_uuid[7], (unsigned int*)&m_launch_player_uuid[8], (unsigned int*)&m_launch_player_uuid[9],
                       (unsigned int*)&m_launch_player_uuid[10], (unsigned int*)&m_launch_player_uuid[11], (unsigned int*)&m_launch_player_uuid[12], (unsigned int*)&m_launch_player_uuid[13], (unsigned int*)&m_launch_player_uuid[14],
                       (unsigned int*)&m_launch_player_uuid[15] );
                ret = player->LaunchApp( player, m_launch_app_uuid, m_launch_player_uuid, instance_uuid );
//printf("JJJJJJJJJJJ=>Launch %s on %s\n", applicationsuuid[VoodooApplicationListIndex], playersuuid[VoodooRendererListIndex]);
				if (!ret)
				{
				}
                player->Release( player );
				DirectFB_Finalize();
				DFBCHECK(DirectFBSetOption( "remote", VoodooRendererListData[VoodooRendererListIndex] ));
				DirectFB_Init();
			}
#endif

			break;
	}

	return(retval);
}

/**********************************************************************************************************************/

static int ButtonCallback(int command, int data)
{
    int index,cmd;
	int retval = 0;

	if (command == WIDCALL_PROPSET)
	{
		
#ifdef JSLIBRC
		index = data >> 1;
		if (index < sizeof(rc6Codes)/sizeof(int) )
		{
		  cmd = rc6Codes[index];
		  if (cmd != -1)
		  {
			  jslibrc_KeyDown(keySourceRc6, 0, cmd);
			  jslibrc_KeyUp(keySourceRc6, 0, cmd);
			  retval = 1;
		  }
		}
#endif
	}
	else if (command == WIDCALL_PROPGET)
	{
#ifdef JSLIBRC
		if ( (data >> 16) == ICON_TOUCHPAD ) switch (data & 0xffff)
		{
			case TOUCH_SWIPE_LEFT:
				jslibrc_KeyDown(keySourceRc6, 0, rc6S0StepLeft);
				jslibrc_KeyUp(keySourceRc6, 0, rc6S0StepLeft);
				retval = 1;
				break;
			case TOUCH_SWIPE_RIGHT:
				jslibrc_KeyDown(keySourceRc6, 0, rc6S0StepRight);
				jslibrc_KeyUp(keySourceRc6, 0, rc6S0StepRight);
				retval = 1;
				break;
			case TOUCH_SWIPE_UP:
				jslibrc_KeyDown(keySourceRc6, 0, rc6S0StepUp);
				jslibrc_KeyUp(keySourceRc6, 0, rc6S0StepUp);
				retval = 1;
				break;
			case TOUCH_SWIPE_DOWN:
				jslibrc_KeyDown(keySourceRc6, 0, rc6S0StepDown);
				jslibrc_KeyUp(keySourceRc6, 0, rc6S0StepDown);
				retval = 1;
				break;
		}
#endif
	}

	return retval;
}


/**********************************************************************************************************************/
static int OnKeyDown( int aSource, int aKey )
{
//std_vprintf(stdbuffer2,"Mouse %d %d\n",aKey & 0xffff, aKey>>16);
  if ( aSource == SOURCE_TOUCH)
  {
		switch (aKey & 0xffff)
		{
			case TOUCH_SWIPE_RIGHT:
//std_vprintf(stdbuffer2,"Mouse swipe RIGHT %d\n",aKey>>16);
				break;
			case TOUCH_SWIPE_LEFT:
//std_vprintf(stdbuffer2,"Mouse swipe LEFT %d\n",aKey>>16);
				break;
			case TOUCH_SWIPE_UP:
//std_vprintf(stdbuffer2,"Mouse swipe UP %d\n",aKey>>16);
				break;
			case TOUCH_SWIPE_DOWN:
//std_vprintf(stdbuffer2,"Mouse swipe DOWN %d\n",aKey>>16);
				break;
			default:
				break;
		}		
  }
  if ( aSource == SOURCE_TOUCH)
      return(wid_SendEvent(menu, WIDEVENT_SWIPE, aKey));
  else
      return(wid_SendEvent(menu, WIDEVENT_KEYDOWN, aKey));
}

static int OnKeyUp( int aSource, int aKey )
{
  return(wid_SendEvent(menu, WIDEVENT_KEYUP, aKey));
}




/**********************************************************************************************************************/
#define CAN_W   (m_resolutionWidth)
#define CAN_H   (m_resolutionHeight)
#define STP_W   (CAN_W/12)
#define STP_H   (CAN_H/12)
#define ICO_W   (CAN_W/5)//64
#define ICO_H   ((CAN_H/6)-8)
//#define ICO_W            64//44//64
//#define ICO_H            64//43//64


#define W1_3    (0*CAN_W+(CAN_W-3*ICO_W)/2)/3
#define W2_3    (1*CAN_W+(CAN_W-3*ICO_W)/2)/3
#define W3_3    (2*CAN_W+(CAN_W-3*ICO_W)/2)/3
#define W1_4    (0*CAN_W+(CAN_W-4*ICO_W)/2)/4
#define W2_4    (1*CAN_W+(CAN_W-4*ICO_W)/2)/4
#define W3_4    (2*CAN_W+(CAN_W-4*ICO_W)/2)/4
#define W4_4    (3*CAN_W+(CAN_W-4*ICO_W)/2)/4
#define W1_5    (0*CAN_W+(CAN_W-5*ICO_W)/2)/5
#define W2_5    (1*CAN_W+(CAN_W-5*ICO_W)/2)/5
#define W3_5    (2*CAN_W+(CAN_W-5*ICO_W)/2)/5
#define W4_5    (3*CAN_W+(CAN_W-5*ICO_W)/2)/5
#define W5_5    (4*CAN_W+(CAN_W-5*ICO_W)/2)/5

void appInit(void)
{
//	ttf_FontCreate("decker.ttf", 10, 10, 10, backbuffer.format, 0xff, 0xff,0xff,0xff, &fontsmall );

    /* Menu creation */
    menu =  wid_CreateParent(WIDTYPE_MENU, "Menu",WIDATTR_FULLWIDTH|WIDATTR_FULLHEIGHT, 0,5,0,WIDPARAM_NULL,0);
    node1 = wid_AddChild(WIDTYPE_LIST, "Panel1",WIDATTR_UNDEFINED, 0,0,VoodooRendererCallback,WIDPARAM_1(8),0);
    node2 = wid_AddChild(WIDTYPE_PANEL,"Panel2",WIDATTR_UNDEFINED, 0,10,0,WIDPARAM_NULL,0);
    node3 = wid_AddChild(WIDTYPE_PANEL,"Panel3",WIDATTR_UNDEFINED, 0,13,0,WIDPARAM_NULL,0);
    node4 = wid_AddChild(WIDTYPE_PANEL,"Panel4",WIDATTR_UNDEFINED, 0,18,0,WIDPARAM_NULL,0);
    node5 = wid_AddChild(WIDTYPE_LIST, "Panel5",WIDATTR_UNDEFINED, 0,0,VoodooApplicationCallback,WIDPARAM_1(6),0);
            wid_SelectParent(node2);
            wid_AddChild(WIDTYPE_BUTTON,"standby",WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_STANDBY,    W1_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"vol-",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_VOLUMEDOWN, W3_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"mute",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_MUTE,       W4_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"vol+",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_VOLUMEUP,   W5_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"home",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_HOME,       W2_3,2*STP_H, ICO_W,ICO_H),0);
			wid_AddChild(WIDTYPE_BUTTON,"browse", WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_BROWSE,     W1_3,3*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"options",WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_OPTIONS,    W3_3,3*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"pad",    WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_TOUCHPAD,   (CAN_W-10*STP_W)/2,5*STP_H,10*STP_W,4*STP_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"back",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_BACK,       W1_3,10*STP_H,ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"Exper",  WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_EXPERIENCE, W3_3,10*STP_H,ICO_W,ICO_H),0);
            wid_SelectParent(node3);
            wid_AddChild(WIDTYPE_BUTTON,"standby",WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_STANDBY,    W1_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"vol-",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_VOLUMEDOWN, W3_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"mute",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_MUTE,       W4_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"vol+",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_VOLUMEUP,   W5_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"prog-",  WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_PROGRAMDOWN,W2_5,3*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"prog",   WIDATTR_UNDEFINED, 0,0,0,             WIDPARAM_5(ICON_PROGRAM,    W3_5,3*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"prog+",  WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_PROGRAMUP,  W4_5,3*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"stop",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_STOP,       W2_4,6*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"play",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_PLAY,       W3_4,6*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"prev",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_PREVIOUS,   W1_4,8*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"backwrd",WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_BACKWARD,   W2_4,8*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"forward",WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_FORWARD,    W3_4,8*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"next",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_NEXT,       W4_4,8*STP_H, ICO_W,ICO_H),0);
            wid_SelectParent(node4);
            wid_AddChild(WIDTYPE_BUTTON,"standby",WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_STANDBY,    W1_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"vol-",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_VOLUMEDOWN, W3_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"mute",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_MUTE,       W4_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"vol+",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_VOLUMEUP,   W5_5,0*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"red",    WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_RED,        W1_4,2*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"green",  WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_GREEN,      W2_4,2*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"yellow", WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_YELLOW,     W3_4,2*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"blue",   WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_BLUE,       W4_4,2*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"1",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_1,          W1_3,4*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"2",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_2,          W2_3,4*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"3",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_3,          W3_3,4*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"4",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_4,          W1_3,6*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"5",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_5,          W2_3,6*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"6",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_6,          W3_3,6*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"7",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_7,          W1_3,8*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"8",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_8,          W2_3,8*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"9",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_9,          W3_3,8*STP_H, ICO_W,ICO_H),0);
            wid_AddChild(WIDTYPE_BUTTON,"0",      WIDATTR_UNDEFINED, 0,0,ButtonCallback,WIDPARAM_5(ICON_0,          W2_3,10*STP_H,ICO_W,ICO_H),0);


    key_SubscribeKeyUp(OnKeyUp);
    key_SubscribeKeyDown(OnKeyDown);
}


/**********************************************************************************************************************/
void appFrame(void)
{
    if ( (updated) || (key_OnKeyTimer()) )
	{
		 updated = wid_Show(menu);
	}

#ifdef __WIN32__
//	GuiRect blitrectangle;
//	int x,y,b;
    RECT rect;
//	GuiRect fillrectangle = {100,-200,10000,10000};
	GuiRect clip = {0,0,WIN_W,WIN_H};

//	blitrectangle.x = 0;
//	blitrectangle.y = 0;
//	blitrectangle.h = 40;
//	blitrectangle.w = backbuffer.w;
//	gui_BitmapFillRectangle(&backbuffer, &blitrectangle, 0x00,0x00,0x00, 0xff);
//	key_GetMouseMove(&x,&y,&b);
//	std_vprintf(stdbuffer1, "Mouse: x=%d, y=%d, b=%d", x,y,b);
//	ttf_FontDrawString(0, 0, stdbuffer1, &fontsmall, &backbuffer);
//	ttf_FontDrawString(0, 20,stdbuffer2, &fontsmall, &backbuffer);
      
	rect.left   = backbuffer.dirtyx1;
    rect.top    = backbuffer.dirtyy1;
    rect.right  = backbuffer.dirtyx2-1;
    rect.bottom = backbuffer.dirtyy2-1;
	clip.x      = backbuffer.dirtyx1;
	clip.y      = backbuffer.dirtyy1;
	clip.w      = backbuffer.dirtyx2-backbuffer.dirtyx1;
	clip.h      = backbuffer.dirtyy2-backbuffer.dirtyy1;
	if ( gui_BitmapFlip( &backbuffer ) )
	{
	    gui_BitmapSetClip(&frontbuffer, &clip);
        gui_BitmapBlit(GUIBLF_FLIPUPDOWN, &frontbuffer, &backbuffer, &clip );
        InvalidateRect( m_hwnd, &rect, FALSE );
	    gui_BitmapSetClip(&frontbuffer, NULL);
	}
#endif
}


/**********************************************************************************************************************/
void appFinalize(void)
{
     gui_BitmapDestroy(&backbuffer);
}

/**********************************************************************************************************************/
void appReset(void)
{
#ifdef DFB
	dfb           = NULL;;
	events        = NULL;
	gsurface      = NULL;
#endif
#ifdef PLAYER
	player        = NULL;
#endif
	playernb      = 0; 
	applicationnb = 0;
	discoverednb  = 0;
	quit          = 0;
	updated       = 1;
    VoodooRendererListIndex = 0;
    VoodooRendererListSize = 0;
    VoodooApplicationListIndex = 0;
    VoodooApplicationListSize = 0;
}

/**********************************************************************************************************************/
static void * DiscoveryTask( void* param )
{
	int i;
	int state=0;
	int tickcounter=0;
	int discoverycounter=0;

	direct_snputs( info.name, "pipo", VOODOO_PLAYER_NAME_LENGTH );
    DFBCHECK(voodoo_player_create( &info, &player ));
    while ( !quit ) 
    {
		if (state == 0)
		{
			/* Application server removed? */
/*
			pthread_mutex_lock(&wait_mutex);
			for (i=0; i<discoverednb; i++ )
			{
				if (discoveredcnt[i])
				{
					discoveredcnt[i] -= 1;
				}
				else
				{
					VoodooApplicationListIndex = 0;
					VoodooApplicationListSize= 0;
					applicationnb = 0;
					discoverednb = 0;
					updated = 1;
				}
			}
			pthread_mutex_unlock(&wait_mutex);
*/
			// Stop broadcast after a while
			if (discoverycounter < DISCOVERED_MAXCNT)
			{

				DFBCHECK(voodoo_player_broadcast( player ));
				usleep( 100000 );
				DFBCHECK(voodoo_player_enumerate( player, player_callback, NULL ));
				discoverycounter++;
			}
			tickcounter = 20; // 20x100ms = 2s
			state = 1;
		} 
		else
		{
			usleep( 100000 );
			if (tickcounter)
				tickcounter--;
			else
				state = 0;
		}
	}
	return (NULL);
}


/**************************************
* Main entry point
**************************************/
int main (int argc, char *argv[])
{
    void                          *system;
    struct                        timespec req = { 0,( 10 * 1000000 ) }; /* ms */

	appReset();
#ifdef PLAYER
	pthread_mutex_init(&wait_mutex, NULL);
    /* DirectFB init */
    DFBCHECK(DirectFBInit( (void*)&argc, (void*)&argv ));
    pthread_create( &threadId, NULL, &DiscoveryTask, NULL );
#endif

    m_resolutionWidth =WIN_W;
    m_resolutionHeight=WIN_H;
    m_depth = 4;
    system = System_Init();
	/* Initialize modules */
    mem_Init();
    key_Init();
	ttf_Init();
    gui_BitmapCreate(GUIBIF_FRAMEBUFFER,  m_resolutionWidth, m_resolutionHeight, m_pitch, GUIPFM_ARGB8888, 0, &backbuffer);
	gui_BitmapCacheInit("./assets/",bmpTable);
	wid_Init("./assets/");
	appInit();
	if (system) 
	{
		while (!quit) 
		{
			System_GetCommand( system );
			appFrame();
			nanosleep( &req, NULL );
//			if (countdown-- == 0)
//			{
//				DFBCHECK(voodoo_player_broadcast( player ));
//				usleep( 100000 );
//				DFBCHECK(voodoo_player_enumerate( player, player_callback, NULL ));
//				countdown = 500;
//			}
		}
	};     
	appFinalize();
	System_Finalize( system );
    DirectFB_Finalize();

#ifdef PLAYER
    if (player) 
	{
	    DFBCHECK(voodoo_player_destroy( player ));
        player = NULL;
    }
    pthread_join(threadId, NULL);
    pthread_mutex_destroy(&wait_mutex);
#endif

    return 1;   
}
