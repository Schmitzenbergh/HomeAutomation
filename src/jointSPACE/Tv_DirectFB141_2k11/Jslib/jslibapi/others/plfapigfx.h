
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


#if !defined(_PLFAPIGFX_H_)
#define _PLFAPIGFX_H_

#if !defined(_PLFAPIGFX_DD_)
#include "plfapigfx_types.h"
#endif

extern int  plfapigfx_Init( int arg, char * argv[] );
extern void plfapigfx_Exit( void );

/*  Symbols for plfapigfxMethodID */
extern int idgfxctrlOptimiseGraphics;  /* 0 */
extern int idgfxitfGetAvailableInterfaces;  /* 1 */
extern int plfapigfxMethodID_Last;  /* 2 */

/*  Symbols for plfapigfxNotificationID */
extern int idgfxitfNOnAvailabilityChanged;  /* 0 */
extern int plfapigfxNotificationID_Last;  /* 1 */

/*  Functions clients can call, implemented by the supplier. */
#define plfapigfx_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapigfx_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapigfx_errid_Ok  ((FResult)0)
#define plfapigfx_errid_Ok_CONSTANT  0
#define plfapigfx_errid_Other  ((FResult)-1)
#define plfapigfx_errid_Other_CONSTANT  -1
#define plfapigfx_errid_ResourceNotOwned  ((FResult)1)
#define plfapigfx_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapigfx_gfxctrl_OptimiseGraphics( int winid, Bool optimise );
extern FResult plfapigfx_gfxitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids );
#define plfapigfx_gfxitfid_gfxctrl  ((Nat32)1)
#define plfapigfx_gfxitfid_gfxctrl_CONSTANT  1

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapigfx_gfxitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapigfx_EnableNotification_gfxitfN( void );
extern void plfapigfx_DisableNotification_gfxitfN( void );
extern void plfapigfx_EnableNotification( int notificationId );
extern void plfapigfx_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapigfx_call_stubs */
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

extern void plfapigfx_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapigfx_RegisterHook_errid( IpcHookFunction callback );
extern void plfapigfx_RegisterHook_gfxctrl( IpcHookFunction callback );
extern void plfapigfx_RegisterHook_gfxitf( IpcHookFunction callback );
extern void plfapigfx_RegisterHook_gfxitfid( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapigfx_RegisterHook_gfxitfN( IpcHookFunction callback );

#endif /* _PLFAPIGFX_H_ */

