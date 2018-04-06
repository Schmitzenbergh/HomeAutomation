
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


#if !defined(_PLFAPISETUP_H_)
#define _PLFAPISETUP_H_

#if !defined(_PLFAPISETUP_DD_)
#include "plfapisetup_types.h"
#endif

extern int  plfapisetup_Init( int arg, char * argv[] );
extern void plfapisetup_Exit( void );

/*  Symbols for plfapisetupMethodID */
extern int idblkEnableBlanking;  /* 0 */
extern int idblkIsBlanked;  /* 1 */
extern int idblkIsBlankingEnabled;  /* 2 */
extern int idblkSetBlanked;  /* 3 */
extern int idblkSetBlankingColor;  /* 4 */
extern int iddstAttachClient;  /* 5 */
extern int iddstDetachClient;  /* 6 */
extern int iddstSetDestination;  /* 7 */
extern int iddstSetVideoCoordinates;  /* 8 */
extern int iddstSetVideoOutputMode;  /* 9 */
extern int iddst2ApplyDestinationSettings;  /* 10 */
extern int iddst2AttachClient;  /* 11 */
extern int iddst2DetachClient;  /* 12 */
extern int iddst2SetDestination;  /* 13 */
extern int iddst2SetVideoCoordinates;  /* 14 */
extern int idgfxscctrlForceNativeMode;  /* 15 */
extern int idgfxscctrlForcePrecompensationMode;  /* 16 */
extern int idkeyDisable;  /* 17 */
extern int idkeyEnable;  /* 18 */
extern int idkeySetWakeupMode;  /* 19 */
extern int idlgcDisable;  /* 20 */
extern int idlgcEnable;  /* 21 */
extern int idlgcIsEnabled;  /* 22 */
extern int idpowGetAutomaticRestarts;  /* 23 */
extern int idpowGetMuteScreen;  /* 24 */
extern int idpowGetTvPower;  /* 25 */
extern int idpowGetWakeupInfo;  /* 26 */
extern int idpowIsInProtection;  /* 27 */
extern int idpowIsTvPowerSupported;  /* 28 */
extern int idpowRestart;  /* 29 */
extern int idpowSetAutomaticRestarts;  /* 30 */
extern int idpowSetMuteScreen;  /* 31 */
extern int idpowSetTvPower;  /* 32 */
extern int idpowStartHotboot;  /* 33 */
extern int idpowStopHotboot;  /* 34 */
extern int idpowTransitionActive;  /* 35 */
extern int idresSetClientResourceAllocation;  /* 36 */
extern int idresSetResourceAllocation;  /* 37 */
extern int plfapisetupMethodID_Last;  /* 38 */

/*  Symbols for plfapisetupNotificationID */
extern int idblkNOnBlankedChanged;  /* 0 */
extern int idblkNOnEnableBlankingChanged;  /* 1 */
extern int iddst2NOnDestinationSettingsApplied;  /* 2 */
extern int iddstNOnVideoCoordinatesSet;  /* 3 */
extern int iddstNOnVideoOutputModeSet;  /* 4 */
extern int idpowNOnTvPowerChanged;  /* 5 */
extern int idpowNOnTvPowerNotChanged;  /* 6 */
extern int plfapisetupNotificationID_Last;  /* 7 */

/*  Functions clients can call, implemented by the supplier. */
extern FResult plfapisetup_blk_EnableBlanking( int winid, Bool mode );
extern FResult plfapisetup_blk_IsBlanked( int winid, Bool * retval );
extern FResult plfapisetup_blk_IsBlankingEnabled( int winid, Bool * retval );
extern FResult plfapisetup_blk_SetBlanked( int winid, Bool blanked );
extern FResult plfapisetup_blk_SetBlankingColor( int winid, int color );
#define plfapisetup_blk_BlankingColorBlack  ((int)1)
#define plfapisetup_blk_BlankingColorBlack_CONSTANT  1
#define plfapisetup_blk_BlankingColorBlue  ((int)0)
#define plfapisetup_blk_BlankingColorBlue_CONSTANT  0
#define plfapisetup_blk_BlankingColorGrey  ((int)2)
#define plfapisetup_blk_BlankingColorGrey_CONSTANT  2
#define plfapisetup_blk_MaxBlankingColor  ((int)2)
#define plfapisetup_blk_MaxBlankingColor_CONSTANT  2
#define plfapisetup_blk_MinBlankingColor  ((int)0)
#define plfapisetup_blk_MinBlankingColor_CONSTANT  0
extern FResult plfapisetup_dst_AttachClient( int destid, int windowid, Bool IsBorder );
extern FResult plfapisetup_dst_DetachClient( int destid, int windowid );
extern FResult plfapisetup_dst_SetDestination( int destid, int windowid, Bool IsBorder );
extern FResult plfapisetup_dst_SetVideoCoordinates( int streamid, int ul_x, int ul_y, int lr_x, int lr_y, Bool * retval );
extern FResult plfapisetup_dst_SetVideoOutputMode( int mode, Bool * retval );
#define plfapisetup_dst_DestinationAudioHeadPhone  ((int)3)
#define plfapisetup_dst_DestinationAudioHeadPhone_CONSTANT  3
#define plfapisetup_dst_DestinationAudioSpeaker  ((int)2)
#define plfapisetup_dst_DestinationAudioSpeaker_CONSTANT  2
#define plfapisetup_dst_DestinationVideoMain  ((int)0)
#define plfapisetup_dst_DestinationVideoMain_CONSTANT  0
#define plfapisetup_dst_DestinationVideoSub  ((int)1)
#define plfapisetup_dst_DestinationVideoSub_CONSTANT  1
#define plfapisetup_dst_NoWindowId  ((int)-1)
#define plfapisetup_dst_NoWindowId_CONSTANT  -1
#define plfapisetup_dst_VideoOutputModeDual  ((int)1)
#define plfapisetup_dst_VideoOutputModeDual_CONSTANT  1
#define plfapisetup_dst_VideoOutputModeSingle  ((int)0)
#define plfapisetup_dst_VideoOutputModeSingle_CONSTANT  0
#define plfapisetup_dst_VideoStream1  ((int)0)
#define plfapisetup_dst_VideoStream1_CONSTANT  0
#define plfapisetup_dst_VideoStream2  ((int)1)
#define plfapisetup_dst_VideoStream2_CONSTANT  1
extern FResult plfapisetup_dst2_ApplyDestinationSettings( Bool * retval );
extern FResult plfapisetup_dst2_AttachClient( int destid, int windowid, Bool IsBorder );
extern FResult plfapisetup_dst2_DetachClient( int destid, int windowid );
extern FResult plfapisetup_dst2_SetDestination( int destid, int destprop, int windowid, Bool IsBorder );
extern FResult plfapisetup_dst2_SetVideoCoordinates( int destid, int ul_x, int ul_y, int lr_x, int lr_y );
#define plfapisetup_dst2_DestinationAudioHeadPhone  ((int)3)
#define plfapisetup_dst2_DestinationAudioHeadPhone_CONSTANT  3
#define plfapisetup_dst2_DestinationAudioSpeaker  ((int)2)
#define plfapisetup_dst2_DestinationAudioSpeaker_CONSTANT  2
#define plfapisetup_dst2_DestinationPropertyMain  ((int)1)
#define plfapisetup_dst2_DestinationPropertyMain_CONSTANT  1
#define plfapisetup_dst2_DestinationPropertyNone  ((int)0)
#define plfapisetup_dst2_DestinationPropertyNone_CONSTANT  0
#define plfapisetup_dst2_DestinationPropertySub  ((int)2)
#define plfapisetup_dst2_DestinationPropertySub_CONSTANT  2
#define plfapisetup_dst2_DestinationVideoStream1  ((int)0)
#define plfapisetup_dst2_DestinationVideoStream1_CONSTANT  0
#define plfapisetup_dst2_DestinationVideoStream2  ((int)1)
#define plfapisetup_dst2_DestinationVideoStream2_CONSTANT  1
#define plfapisetup_dst2_NoWindowId  ((int)-1)
#define plfapisetup_dst2_NoWindowId_CONSTANT  -1
#define plfapisetup_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapisetup_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapisetup_errid_Ok  ((FResult)0)
#define plfapisetup_errid_Ok_CONSTANT  0
#define plfapisetup_errid_Other  ((FResult)-1)
#define plfapisetup_errid_Other_CONSTANT  -1
#define plfapisetup_errid_ResourceNotOwned  ((FResult)1)
#define plfapisetup_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapisetup_gfxscctrl_ForceNativeMode( Bool force );
extern FResult plfapisetup_gfxscctrl_ForcePrecompensationMode( int layers, Bool force );
#define plfapisetup_gfxscctrl_Layer0  ((int)1)
#define plfapisetup_gfxscctrl_Layer0_CONSTANT  1
#define plfapisetup_gfxscctrl_Layer1  ((int)2)
#define plfapisetup_gfxscctrl_Layer1_CONSTANT  2
#define plfapisetup_gfxscctrl_Layer2  ((int)4)
#define plfapisetup_gfxscctrl_Layer2_CONSTANT  4
extern FResult plfapisetup_key_Disable( void );
extern FResult plfapisetup_key_Enable( void );
extern FResult plfapisetup_key_SetWakeupMode( RemoteControlKey * key, int size );
extern FResult plfapisetup_lgc_Disable( void );
extern FResult plfapisetup_lgc_Enable( void );
extern FResult plfapisetup_lgc_IsEnabled( Bool * retval );
extern FResult plfapisetup_pow_GetAutomaticRestarts( Bool * retval );
extern FResult plfapisetup_pow_GetMuteScreen( int winid, Bool * retval );
extern FResult plfapisetup_pow_GetTvPower( int * retval );
extern FResult plfapisetup_pow_GetWakeupInfo( int * src, int * sys, int * cmd );
extern FResult plfapisetup_pow_IsInProtection( Bool * retval );
extern FResult plfapisetup_pow_IsTvPowerSupported( int mode, Bool * retval );
extern FResult plfapisetup_pow_Restart( int appl );
extern FResult plfapisetup_pow_SetAutomaticRestarts( Bool enable );
extern FResult plfapisetup_pow_SetMuteScreen( int winid, Bool enable );
extern FResult plfapisetup_pow_SetTvPower( int mode );
extern FResult plfapisetup_pow_StartHotboot( int winid );
extern FResult plfapisetup_pow_StopHotboot( int winid );
extern FResult plfapisetup_pow_TransitionActive( Bool * retval );
#define plfapisetup_pow_ApplicationSwDownload  ((int)1)
#define plfapisetup_pow_ApplicationSwDownload_CONSTANT  1
#define plfapisetup_pow_ApplicationTvCold  ((int)0)
#define plfapisetup_pow_ApplicationTvCold_CONSTANT  0
#define plfapisetup_pow_PowerCadStandby  ((int)1)
#define plfapisetup_pow_PowerCadStandby_CONSTANT  1
#define plfapisetup_pow_PowerDataAcquisition  ((int)4)
#define plfapisetup_pow_PowerDataAcquisition_CONSTANT  4
#define plfapisetup_pow_PowerMax  ((int)4)
#define plfapisetup_pow_PowerMax_CONSTANT  4
#define plfapisetup_pow_PowerMin  ((int)0)
#define plfapisetup_pow_PowerMin_CONSTANT  0
#define plfapisetup_pow_PowerOff  ((int)0)
#define plfapisetup_pow_PowerOff_CONSTANT  0
#define plfapisetup_pow_PowerOn  ((int)3)
#define plfapisetup_pow_PowerOn_CONSTANT  3
#define plfapisetup_pow_PowerSemiPowerOff  ((int)1)
#define plfapisetup_pow_PowerSemiPowerOff_CONSTANT  1
#define plfapisetup_pow_PowerSemiStandby  ((int)2)
#define plfapisetup_pow_PowerSemiStandby_CONSTANT  2
#define plfapisetup_pow_PowerStandby  ((int)0)
#define plfapisetup_pow_PowerStandby_CONSTANT  0
#define plfapisetup_pow_PowerUnknown  ((int)-1)
#define plfapisetup_pow_PowerUnknown_CONSTANT  -1
extern FResult plfapisetup_res_SetClientResourceAllocation( int resid, int nbrclients, int * winid );
extern FResult plfapisetup_res_SetResourceAllocation( int resid, int nbrclients, int * winid );
#define plfapisetup_res_AllClients  ((int)-1)
#define plfapisetup_res_AllClients_CONSTANT  -1
#define plfapisetup_res_ResourceAudioFeaturing  ((int)0)
#define plfapisetup_res_ResourceAudioFeaturing_CONSTANT  0
#define plfapisetup_res_ResourceConnectivity  ((int)1)
#define plfapisetup_res_ResourceConnectivity_CONSTANT  1
#define plfapisetup_res_ResourceFrontend  ((int)2)
#define plfapisetup_res_ResourceFrontend_CONSTANT  2
#define plfapisetup_res_ResourceGeneral  ((int)3)
#define plfapisetup_res_ResourceGeneral_CONSTANT  3
#define plfapisetup_res_ResourceGfx  ((int)9)
#define plfapisetup_res_ResourceGfx_CONSTANT  9
#define plfapisetup_res_ResourceInfrastructure  ((int)4)
#define plfapisetup_res_ResourceInfrastructure_CONSTANT  4
#define plfapisetup_res_ResourceMute  ((int)10)
#define plfapisetup_res_ResourceMute_CONSTANT  10
#define plfapisetup_res_ResourceScale  ((int)8)
#define plfapisetup_res_ResourceScale_CONSTANT  8
#define plfapisetup_res_ResourceSource  ((int)5)
#define plfapisetup_res_ResourceSource_CONSTANT  5
#define plfapisetup_res_ResourceVideoFeaturing  ((int)6)
#define plfapisetup_res_ResourceVideoFeaturing_CONSTANT  6
#define plfapisetup_res_ResourceXray  ((int)7)
#define plfapisetup_res_ResourceXray_CONSTANT  7

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapisetup_blkN_OnBlankedChanged( void );
extern void plfapisetup_blkN_OnEnableBlankingChanged( void );
extern void plfapisetup_dst2N_OnDestinationSettingsApplied( void );
extern void plfapisetup_dstN_OnVideoCoordinatesSet( int streamid );
extern void plfapisetup_dstN_OnVideoOutputModeSet( int mode );
extern void plfapisetup_powN_OnTvPowerChanged( void );
extern void plfapisetup_powN_OnTvPowerNotChanged( void );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapisetup_EnableNotification_blkN( void );
extern void plfapisetup_DisableNotification_blkN( void );
extern void plfapisetup_EnableNotification_dst2N( void );
extern void plfapisetup_DisableNotification_dst2N( void );
extern void plfapisetup_EnableNotification_dstN( void );
extern void plfapisetup_DisableNotification_dstN( void );
extern void plfapisetup_EnableNotification_powN( void );
extern void plfapisetup_DisableNotification_powN( void );
extern void plfapisetup_EnableNotification( int notificationId );
extern void plfapisetup_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapisetup_call_stubs */
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

extern void plfapisetup_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapisetup_RegisterHook_blk( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_dst( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_dst2( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_errid( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_gfxscctrl( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_key( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_lgc( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_pow( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_res( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapisetup_RegisterHook_blkN( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_dst2N( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_dstN( IpcHookFunction callback );
extern void plfapisetup_RegisterHook_powN( IpcHookFunction callback );

#endif /* _PLFAPISETUP_H_ */

