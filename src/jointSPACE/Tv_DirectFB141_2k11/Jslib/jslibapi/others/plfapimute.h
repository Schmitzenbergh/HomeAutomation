
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


#if !defined(_PLFAPIMUTE_H_)
#define _PLFAPIMUTE_H_

#if !defined(_PLFAPIMUTE_DD_)
#include "plfapimute_types.h"
#endif

extern int  plfapimute_Init( int arg, char * argv[] );
extern void plfapimute_Exit( void );

/*  Symbols for plfapimuteMethodID */
extern int idmuteitfGetAvailableInterfaces;  /* 0 */
extern int idvmtGetActualMute;  /* 1 */
extern int idvmtGetActualMuteColor;  /* 2 */
extern int idvmtGetAutoMute;  /* 3 */
extern int idvmtGetMute;  /* 4 */
extern int idvmtGetMuteColor;  /* 5 */
extern int idvmtIsAutoMuteSupported;  /* 6 */
extern int idvmtIsMuteColorSupported;  /* 7 */
extern int idvmtIsMuteSupported;  /* 8 */
extern int idvmtSetAutoMute;  /* 9 */
extern int idvmtSetMute;  /* 10 */
extern int idvmtSetMuteColor;  /* 11 */
extern int idvvmtGetActualMute;  /* 12 */
extern int idvvmtGetActualMuteColor;  /* 13 */
extern int idvvmtGetAutoMute;  /* 14 */
extern int idvvmtGetMute;  /* 15 */
extern int idvvmtGetMuteColor;  /* 16 */
extern int idvvmtIsAutoMuteSupported;  /* 17 */
extern int idvvmtIsMuteColorSupported;  /* 18 */
extern int idvvmtIsMuteSupported;  /* 19 */
extern int idvvmtSetAutoMute;  /* 20 */
extern int idvvmtSetMute;  /* 21 */
extern int idvvmtSetMuteColor;  /* 22 */
extern int plfapimuteMethodID_Last;  /* 23 */

/*  Symbols for plfapimuteNotificationID */
extern int idmuteitfNOnAvailabilityChanged;  /* 0 */
extern int idvmtNOnActualMuteChanged;  /* 1 */
extern int idvmtNOnActualMuteColorChanged;  /* 2 */
extern int idvvmtNOnActualMuteChanged;  /* 3 */
extern int idvvmtNOnActualMuteColorChanged;  /* 4 */
extern int plfapimuteNotificationID_Last;  /* 5 */

/*  Functions clients can call, implemented by the supplier. */
#define plfapimute_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapimute_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapimute_errid_Ok  ((FResult)0)
#define plfapimute_errid_Ok_CONSTANT  0
#define plfapimute_errid_Other  ((FResult)-1)
#define plfapimute_errid_Other_CONSTANT  -1
#define plfapimute_errid_ResourceNotOwned  ((FResult)1)
#define plfapimute_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapimute_muteitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids );
#define plfapimute_muteitfid_vmt  ((Nat32)1)
#define plfapimute_muteitfid_vmt_CONSTANT  1
#define plfapimute_muteitfid_vvmt  ((Nat32)2)
#define plfapimute_muteitfid_vvmt_CONSTANT  2
extern FResult plfapimute_vmt_GetActualMute( int winid, Bool * retval );
extern FResult plfapimute_vmt_GetActualMuteColor( int winid, int * red, int * green, int * blue );
extern FResult plfapimute_vmt_GetAutoMute( int winid, Bool * retval );
extern FResult plfapimute_vmt_GetMute( int winid, Bool * retval );
extern FResult plfapimute_vmt_GetMuteColor( int winid, int * red, int * green, int * blue );
extern FResult plfapimute_vmt_IsAutoMuteSupported( int winid, Bool * retval );
extern FResult plfapimute_vmt_IsMuteColorSupported( int winid, int red, int green, int blue, Bool * retval );
extern FResult plfapimute_vmt_IsMuteSupported( int winid, Bool * retval );
extern FResult plfapimute_vmt_SetAutoMute( int winid, Bool mode );
extern FResult plfapimute_vmt_SetMute( int winid, Bool mode, Bool * retval );
extern FResult plfapimute_vmt_SetMuteColor( int winid, int red, int green, int blue );
#define plfapimute_vmt_MaxColor  ((int)255)
#define plfapimute_vmt_MaxColor_CONSTANT  255
#define plfapimute_vmt_MinColor  ((int)0)
#define plfapimute_vmt_MinColor_CONSTANT  0
extern FResult plfapimute_vvmt_GetActualMute( int winid, Bool * retval );
extern FResult plfapimute_vvmt_GetActualMuteColor( int winid, int * red, int * green, int * blue );
extern FResult plfapimute_vvmt_GetAutoMute( int winid, Bool * retval );
extern FResult plfapimute_vvmt_GetMute( int winid, Bool * retval );
extern FResult plfapimute_vvmt_GetMuteColor( int winid, int * red, int * green, int * blue );
extern FResult plfapimute_vvmt_IsAutoMuteSupported( int winid, Bool * retval );
extern FResult plfapimute_vvmt_IsMuteColorSupported( int winid, int red, int green, int blue, Bool * retval );
extern FResult plfapimute_vvmt_IsMuteSupported( int winid, Bool * retval );
extern FResult plfapimute_vvmt_SetAutoMute( int winid, Bool mode );
extern FResult plfapimute_vvmt_SetMute( int winid, Bool mode, Bool * retval );
extern FResult plfapimute_vvmt_SetMuteColor( int winid, int red, int green, int blue );
#define plfapimute_vvmt_MaxColor  ((int)255)
#define plfapimute_vvmt_MaxColor_CONSTANT  255
#define plfapimute_vvmt_MinColor  ((int)0)
#define plfapimute_vvmt_MinColor_CONSTANT  0

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapimute_muteitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids );
extern void plfapimute_vmtN_OnActualMuteChanged( void );
extern void plfapimute_vmtN_OnActualMuteColorChanged( void );
extern void plfapimute_vvmtN_OnActualMuteChanged( void );
extern void plfapimute_vvmtN_OnActualMuteColorChanged( void );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapimute_EnableNotification_muteitfN( void );
extern void plfapimute_DisableNotification_muteitfN( void );
extern void plfapimute_EnableNotification_vmtN( void );
extern void plfapimute_DisableNotification_vmtN( void );
extern void plfapimute_EnableNotification_vvmtN( void );
extern void plfapimute_DisableNotification_vvmtN( void );
extern void plfapimute_EnableNotification( int notificationId );
extern void plfapimute_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapimute_call_stubs */
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

extern void plfapimute_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapimute_RegisterHook_errid( IpcHookFunction callback );
extern void plfapimute_RegisterHook_muteitf( IpcHookFunction callback );
extern void plfapimute_RegisterHook_muteitfid( IpcHookFunction callback );
extern void plfapimute_RegisterHook_vmt( IpcHookFunction callback );
extern void plfapimute_RegisterHook_vvmt( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapimute_RegisterHook_muteitfN( IpcHookFunction callback );
extern void plfapimute_RegisterHook_vmtN( IpcHookFunction callback );
extern void plfapimute_RegisterHook_vvmtN( IpcHookFunction callback );

#endif /* _PLFAPIMUTE_H_ */

