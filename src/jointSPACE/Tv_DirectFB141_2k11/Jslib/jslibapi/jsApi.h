
/*
 * (c) 2011 Koninklijke Philips Electronics N.V., All rights reserved
 * 
 * This source code and any compilation or derivative thereof is the
 * proprietary information of Koninklijke Philips Electronics N.V. and is
 * confidential in nature.
 * Under no circumstances is this software to be exposed to or placed under an
 * Open Source License of any type without the expressed written permission of
 * Koninklijke Philips Electronics N.V.
 */


#if !defined(_JSAPI_H_)
#define _JSAPI_H_

#if !defined(_JSAPI_DD_)
#include "jsApi_types.h"
#endif

extern int  jsApi_Init( int arg, char * argv[] );
extern void jsApi_Exit( void );

/*  Symbols for jsApiMethodID */
extern int idjsAmbiGetConfiguration;  /* 0 */
extern int idjsAmbiGetMode;  /* 1 */
extern int idjsAmbiGetNbrOfPixelsPerSide;  /* 2 */
extern int idjsAmbiGetPixel;  /* 3 */
extern int idjsAmbiGetPixelArray;  /* 4 */
extern int idjsAmbiGetRawPixel;  /* 5 */
extern int idjsAmbiGetRawPixelArray;  /* 6 */
extern int idjsAmbiIsModeSupported;  /* 7 */
extern int idjsAmbiSetMode;  /* 8 */
extern int idjsAmbiSetPixel;  /* 9 */
extern int idjsAmbiSetPixelArray;  /* 10 */
extern int idjsAudioGetBass;  /* 11 */
extern int idjsAudioGetTreble;  /* 12 */
extern int idjsAudioGetVolume;  /* 13 */
extern int idjsAudioSetBass;  /* 14 */
extern int idjsAudioSetTreble;  /* 15 */
extern int idjsAudioSetVolume;  /* 16 */
extern int jsApiMethodID_Last;  /* 17 */

/*  Symbols for jsApiNotificationID */
extern int jsApiNotificationID_Last;  /* 0 */

/*  Functions clients can call, implemented by the supplier. */
extern FResult jsApi_js_AmbiGetConfiguration( int * topology, int * nbrofsegmentsx, int * nbrofsegmentsy, int * nbrofsegmentsz, int * version );
extern FResult jsApi_js_AmbiGetMode( int * mode );
extern FResult jsApi_js_AmbiGetNbrOfPixelsPerSide( int side, int * nbrofpixels );
extern FResult jsApi_js_AmbiGetPixel( int side, int index, int * red, int * green, int * blue );
extern FResult jsApi_js_AmbiGetPixelArray( int side, int startindex, int size, int * red, int * green, int * blue );
extern FResult jsApi_js_AmbiGetRawPixel( int side, int index, int * red, int * green, int * blue );
extern FResult jsApi_js_AmbiGetRawPixelArray( int side, int startindex, int size, int * red, int * green, int * blue );
extern FResult jsApi_js_AmbiIsModeSupported( int mode, Bool * retval );
extern FResult jsApi_js_AmbiSetMode( int mode );
extern FResult jsApi_js_AmbiSetPixel( int side, int index, int red, int green, int blue );
extern FResult jsApi_js_AmbiSetPixelArray( int side, int startindex, int size, int * red, int * green, int * blue );
extern FResult jsApi_js_AudioGetBass( int value );
extern FResult jsApi_js_AudioGetTreble( int value );
extern FResult jsApi_js_AudioGetVolume( int value );
extern FResult jsApi_js_AudioSetBass( int value );
extern FResult jsApi_js_AudioSetTreble( int value );
extern FResult jsApi_js_AudioSetVolume( int value );
#define jsApi_js_ModeAuto  ((int)0)
#define jsApi_js_ModeAuto_CONSTANT  0
#define jsApi_js_ModeManualNative  ((int)2)
#define jsApi_js_ModeManualNative_CONSTANT  2
#define jsApi_js_ModeManualProcessed  ((int)1)
#define jsApi_js_ModeManualProcessed_CONSTANT  1
#define jsApi_js_SideAll  ((int)4)
#define jsApi_js_SideAll_CONSTANT  4
#define jsApi_js_SideBottom  ((int)3)
#define jsApi_js_SideBottom_CONSTANT  3
#define jsApi_js_SideLeft  ((int)0)
#define jsApi_js_SideLeft_CONSTANT  0
#define jsApi_js_SideRight  ((int)1)
#define jsApi_js_SideRight_CONSTANT  1
#define jsApi_js_SideTop  ((int)2)
#define jsApi_js_SideTop_CONSTANT  2
#define jsApi_js_Topology2Sided  ((int)0)
#define jsApi_js_Topology2Sided_CONSTANT  0
#define jsApi_js_Topology3Sided  ((int)1)
#define jsApi_js_Topology3Sided_CONSTANT  1
#define jsApi_js_Topology4Sided  ((int)2)
#define jsApi_js_Topology4Sided_CONSTANT  2

/* Functions called by supplier (notifications raised to clients), implemented by clients. */

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void jsApi_EnableNotification( int notificationId );
extern void jsApi_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the jsApi_call_stubs */
typedef void (*ComaCallStub)( void *ctx, void *arg, unsigned int callcookie );


typedef enum {
  // Client
  ipchtCall                   = 0x01,
  ipchtCallDone               = 0x02,
  ipchtNotificationReceived   = 0x03,
  ipchtNotificationHandled    = 0x04,
  ipchtNotificationDiscarded  = 0x05,

  // Supplier
  ipchtCallDecoupled        = 0x10,		// only used when decoupled in the supplier, only for global hook
  ipchtCallReceived         = 0x20,
  ipchtCallHandled          = 0x30,
  ipchtNotificationCalled   = 0x40,
  ipchtNotificationPosted   = 0x50,
  ipchtNotificationDone     = 0x60,
} IpcHookType;  

typedef void ( *IpcHookFunction)( IpcHookType h, int methodID, void *data);
#endif

extern void jsApi_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void jsApi_RegisterHook_js( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */

#endif /* _JSAPI_H_ */

