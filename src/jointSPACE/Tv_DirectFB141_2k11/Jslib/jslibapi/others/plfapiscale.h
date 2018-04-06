
/*
 * (c) 2010 Koninklijke Philips Electronics N.V., All rights reserved
 * 
 * This source code and any compilation or derivative thereof is the
 * proprietary information of Koninklijke Philips Electronics N.V. and is
 * confidential in nature.
 * Under no circumstances is this software to be exposed to or placed under an
 * Open Source License of any type without the expressed written permission of
 * Koninklijke Philips Electronics N.V.
 */


#if !defined(_PLFAPISCALE_H_)
#define _PLFAPISCALE_H_

#if !defined(_PLFAPISCALE_DD_)
#include "plfapiscale_types.h"
#endif

extern int  plfapiscale_Init( int arg, char * argv[] );
extern void plfapiscale_Exit( void );

/*  Symbols for plfapiscaleMethodID */
extern int idscaleitfGetAvailableInterfaces;  /* 0 */
extern int idvscConvertVideoToGraphicsPosition;  /* 1 */
extern int idvscGetMaxHorScalingFactor;  /* 2 */
extern int idvscGetMaxVerScalingFactor;  /* 3 */
extern int idvscGetMinHorScalingFactor;  /* 4 */
extern int idvscGetMinInputHeight;  /* 5 */
extern int idvscGetMinInputWidth;  /* 6 */
extern int idvscGetMinOutputHeight;  /* 7 */
extern int idvscGetMinOutputWidth;  /* 8 */
extern int idvscGetMinVerScalingFactor;  /* 9 */
extern int idvscIsVideoPositionAllowed;  /* 10 */
extern int idvscIsVideoPositionSupported;  /* 11 */
extern int idvscSetVideoPosition;  /* 12 */
extern int plfapiscaleMethodID_Last;  /* 13 */

/*  Symbols for plfapiscaleNotificationID */
extern int idscaleitfNOnAvailabilityChanged;  /* 0 */
extern int idvscNOnVideoPositionAllowedChanged;  /* 1 */
extern int idvscNOnVideoPositionChanged;  /* 2 */
extern int plfapiscaleNotificationID_Last;  /* 3 */

/*  Functions clients can call, implemented by the supplier. */
#define plfapiscale_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapiscale_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapiscale_errid_Ok  ((FResult)0)
#define plfapiscale_errid_Ok_CONSTANT  0
#define plfapiscale_errid_Other  ((FResult)-1)
#define plfapiscale_errid_Other_CONSTANT  -1
#define plfapiscale_errid_ResourceNotOwned  ((FResult)1)
#define plfapiscale_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapiscale_scaleitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids );
#define plfapiscale_scaleitfid_vsc  ((Nat32)1)
#define plfapiscale_scaleitfid_vsc_CONSTANT  1
extern FResult plfapiscale_vsc_ConvertVideoToGraphicsPosition( int winid, int videox, int videoy, int * graphicsx, int * graphicsy );
extern FResult plfapiscale_vsc_GetMaxHorScalingFactor( int winid, int * retval );
extern FResult plfapiscale_vsc_GetMaxVerScalingFactor( int winid, int * retval );
extern FResult plfapiscale_vsc_GetMinHorScalingFactor( int winid, int * retval );
extern FResult plfapiscale_vsc_GetMinInputHeight( int winid, int * retval );
extern FResult plfapiscale_vsc_GetMinInputWidth( int winid, int * retval );
extern FResult plfapiscale_vsc_GetMinOutputHeight( int winid, int * retval );
extern FResult plfapiscale_vsc_GetMinOutputWidth( int winid, int * retval );
extern FResult plfapiscale_vsc_GetMinVerScalingFactor( int winid, int * retval );
extern FResult plfapiscale_vsc_IsVideoPositionAllowed( int winid, int inputx, int inputy, int inputwidth, int inputheight, int outputx, int outputy, int outputwidth, int outputheight, int wss, int action, Bool * retval );
extern FResult plfapiscale_vsc_IsVideoPositionSupported( int winid, int inputx, int inputy, int inputwidth, int inputheight, int outputx, int outputy, int outputwidth, int outputheight, int wss, int action, Bool * retval );
extern FResult plfapiscale_vsc_SetVideoPosition( int winid, int inputx, int inputy, int inputwidth, int inputheight, int outputx, int outputy, int outputwidth, int outputheight, int wss, int action, Bool * retval );
#define plfapiscale_vsc_DefaultAction  ((int)1)
#define plfapiscale_vsc_DefaultAction_CONSTANT  1
#define plfapiscale_vsc_UseWindowSettings  ((int)2)
#define plfapiscale_vsc_UseWindowSettings_CONSTANT  2
#define plfapiscale_vsc_UseWindowSettingsAndWss  ((int)3)
#define plfapiscale_vsc_UseWindowSettingsAndWss_CONSTANT  3
#define plfapiscale_vsc_UseWindowSettingsOnly  ((int)4)
#define plfapiscale_vsc_UseWindowSettingsOnly_CONSTANT  4
#define plfapiscale_vsc_Wss16by9  ((int)2)
#define plfapiscale_vsc_Wss16by9_CONSTANT  2
#define plfapiscale_vsc_Wss4by3  ((int)1)
#define plfapiscale_vsc_Wss4by3_CONSTANT  1

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapiscale_scaleitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids );
extern void plfapiscale_vscN_OnVideoPositionAllowedChanged( void );
extern void plfapiscale_vscN_OnVideoPositionChanged( void );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapiscale_EnableNotification_scaleitfN( void );
extern void plfapiscale_DisableNotification_scaleitfN( void );
extern void plfapiscale_EnableNotification_vscN( void );
extern void plfapiscale_DisableNotification_vscN( void );
extern void plfapiscale_EnableNotification( int notificationId );
extern void plfapiscale_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapiscale_call_stubs */
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

extern void plfapiscale_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapiscale_RegisterHook_errid( IpcHookFunction callback );
extern void plfapiscale_RegisterHook_scaleitf( IpcHookFunction callback );
extern void plfapiscale_RegisterHook_scaleitfid( IpcHookFunction callback );
extern void plfapiscale_RegisterHook_vsc( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapiscale_RegisterHook_scaleitfN( IpcHookFunction callback );
extern void plfapiscale_RegisterHook_vscN( IpcHookFunction callback );

#endif /* _PLFAPISCALE_H_ */

