
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


#if !defined(_PLFAPIXRAY_H_)
#define _PLFAPIXRAY_H_

#if !defined(_PLFAPIXRAY_DD_)
#include "plfapixray_types.h"
#endif

extern int  plfapixray_Init( int arg, char * argv[] );
extern void plfapixray_Exit( void );

/*  Symbols for plfapixrayMethodID */
extern int idadcConfigureMonitor;  /* 0 */
extern int idadcContainsAnalogueValue;  /* 1 */
extern int idadcGetAnalogueValue;  /* 2 */
extern int idadcGetMaxValue;  /* 3 */
extern int idadcGetMaxVoltage;  /* 4 */
extern int idadcGetMonitorConfiguration;  /* 5 */
extern int idadcIsBeingMonitored;  /* 6 */
extern int idadcStartMonitor;  /* 7 */
extern int idadcStopMonitor;  /* 8 */
extern int idhalGet;  /* 9 */
extern int idhalGetAx;  /* 10 */
extern int idhalGetAxBx;  /* 11 */
extern int idhalGetEx;  /* 12 */
extern int idhalSet;  /* 13 */
extern int idhalSetAx;  /* 14 */
extern int idhalSetAxBx;  /* 15 */
extern int idhalSetEx;  /* 16 */
extern int idhalUnpack;  /* 17 */
extern int idhalUpdate;  /* 18 */
extern int idhal5xx0Get;  /* 19 */
extern int idhal5xx0GetAx;  /* 20 */
extern int idhal5xx0GetAxBx;  /* 21 */
extern int idhal5xx0GetEx;  /* 22 */
extern int idhal5xx0Set;  /* 23 */
extern int idhal5xx0SetAx;  /* 24 */
extern int idhal5xx0SetAxBx;  /* 25 */
extern int idhal5xx0SetEx;  /* 26 */
extern int idhal5xx0Unpack;  /* 27 */
extern int idhal5xx0Update;  /* 28 */
extern int idhwreglogI2cLogging;  /* 29 */
extern int idhwreglogMmioLogging;  /* 30 */
extern int idpwm0Start;  /* 31 */
extern int idpwm0Stop;  /* 32 */
extern int idpwm1Start;  /* 33 */
extern int idpwm1Stop;  /* 34 */
extern int idudmaRead;  /* 35 */
extern int idudmaWrite;  /* 36 */
extern int idxrayGetDeviceName;  /* 37 */
extern int idxrayGetDeviceRegisterName;  /* 38 */
extern int idxrayGetDeviceRegisterValue;  /* 39 */
extern int idxrayGetNumberOfDeviceRegisters;  /* 40 */
extern int idxrayGetNumberOfDevices;  /* 41 */
extern int idxraySetDeviceRegisterValue;  /* 42 */
extern int idxrayitfGetAvailableInterfaces;  /* 43 */
extern int plfapixrayMethodID_Last;  /* 44 */

/*  Symbols for plfapixrayNotificationID */
extern int idhwreglogNOnI2cAccessed;  /* 0 */
extern int idhwreglogNOnMmioAccessed;  /* 1 */
extern int idxrayitfNOnAvailabilityChanged;  /* 2 */
extern int plfapixrayNotificationID_Last;  /* 3 */

/*  Functions clients can call, implemented by the supplier. */
extern FResult plfapixray_adc_ConfigureMonitor( int winid, int channel, int a, int b, FunctionIntInt callback );
extern FResult plfapixray_adc_ContainsAnalogueValue( int winid, int channel, int a, int b, Bool * retval );
extern FResult plfapixray_adc_GetAnalogueValue( int winid, int channel, int * retval );
extern FResult plfapixray_adc_GetMaxValue( int winid, int * retval );
extern FResult plfapixray_adc_GetMaxVoltage( int winid, int * retval );
extern FResult plfapixray_adc_GetMonitorConfiguration( int winid, int channel, int * a, int * b, FunctionIntInt * callback );
extern FResult plfapixray_adc_IsBeingMonitored( int winid, int channel, Bool * retval );
extern FResult plfapixray_adc_StartMonitor( int winid, int channel );
extern FResult plfapixray_adc_StopMonitor( int winid, int channel );
#define plfapixray_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapixray_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapixray_errid_Ok  ((FResult)0)
#define plfapixray_errid_Ok_CONSTANT  0
#define plfapixray_errid_Other  ((FResult)-1)
#define plfapixray_errid_Other_CONSTANT  -1
#define plfapixray_errid_ResourceNotOwned  ((FResult)1)
#define plfapixray_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapixray_hal_Get( int winid, tmRegisterItem_t * item, int * retval );
extern FResult plfapixray_hal_GetAx( int winid, tmRegisterItem_t * item, int ax, int * retval );
extern FResult plfapixray_hal_GetAxBx( int winid, tmRegisterItem_t * item, int ax, int bx, int * retval );
extern FResult plfapixray_hal_GetEx( int winid, tmRegisterItem_t * item, int * retval );
extern FResult plfapixray_hal_Set( int winid, tmRegisterItem_t * item, int val );
extern FResult plfapixray_hal_SetAx( int winid, tmRegisterItem_t * item, int ax, int val );
extern FResult plfapixray_hal_SetAxBx( int winid, tmRegisterItem_t * item, int ax, int bx, int val );
extern FResult plfapixray_hal_SetEx( int winid, tmRegisterItem_t * item, int val );
extern FResult plfapixray_hal_Unpack( int winid, tmRegisterItem_t * item, int val, int * retval );
extern FResult plfapixray_hal_Update( int winid, tmRegisterItem_t * item, int rval, int val, int * retval );
extern FResult plfapixray_hal5xx0_Get( int winid, tmRegisterItem_t * item, int * retval );
extern FResult plfapixray_hal5xx0_GetAx( int winid, tmRegisterItem_t * item, int ax, int * retval );
extern FResult plfapixray_hal5xx0_GetAxBx( int winid, tmRegisterItem_t * item, int ax, int bx, int * retval );
extern FResult plfapixray_hal5xx0_GetEx( int winid, tmRegisterItem_t * item, int * retval );
extern FResult plfapixray_hal5xx0_Set( int winid, tmRegisterItem_t * item, int val );
extern FResult plfapixray_hal5xx0_SetAx( int winid, tmRegisterItem_t * item, int ax, int val );
extern FResult plfapixray_hal5xx0_SetAxBx( int winid, tmRegisterItem_t * item, int ax, int bx, int val );
extern FResult plfapixray_hal5xx0_SetEx( int winid, tmRegisterItem_t * item, int val );
extern FResult plfapixray_hal5xx0_Unpack( int winid, tmRegisterItem_t * item, int val, int * retval );
extern FResult plfapixray_hal5xx0_Update( int winid, tmRegisterItem_t * item, int rval, int val, int * retval );
extern FResult plfapixray_hwreglog_I2cLogging( int winid, Bool enable, Nat32 bus, Nat32 * deviceaddr, Nat32 nrofaddr );
extern FResult plfapixray_hwreglog_MmioLogging( int winid, Bool enable, Nat32 device, Nat32 startaddr, Nat32 stopaddr );
#define plfapixray_hwreglog_Bus0  ((Nat32)1)
#define plfapixray_hwreglog_Bus0_CONSTANT  1
#define plfapixray_hwreglog_Bus1  ((Nat32)2)
#define plfapixray_hwreglog_Bus1_CONSTANT  2
#define plfapixray_hwreglog_Bus2  ((Nat32)4)
#define plfapixray_hwreglog_Bus2_CONSTANT  4
#define plfapixray_hwreglog_Bus3  ((Nat32)8)
#define plfapixray_hwreglog_Bus3_CONSTANT  8
#define plfapixray_hwreglog_PNX5xxx  ((Nat32)1)
#define plfapixray_hwreglog_PNX5xxx_CONSTANT  1
#define plfapixray_hwreglog_PNX85xx  ((Nat32)0)
#define plfapixray_hwreglog_PNX85xx_CONSTANT  0
extern FResult plfapixray_pwm0_Start( int winid, int usecshi, int usecslo );
extern FResult plfapixray_pwm0_Stop( int winid );
extern FResult plfapixray_pwm1_Start( int winid, int usecshi, int usecslo );
extern FResult plfapixray_pwm1_Stop( int winid );
extern FResult plfapixray_udma_Read( int winid, Nat32 from_offset, Nat8 * buffer, int size, FResult * retval );
extern FResult plfapixray_udma_Write( int winid, Nat32 to_offset, Nat8 * buffer, int size, FResult * retval );
#define plfapixray_udma_HardwareFailure  ((FResult)2)
#define plfapixray_udma_HardwareFailure_CONSTANT  2
#define plfapixray_udma_NullPointer  ((FResult)3)
#define plfapixray_udma_NullPointer_CONSTANT  3
#define plfapixray_udma_Ok  ((FResult)0)
#define plfapixray_udma_Ok_CONSTANT  0
#define plfapixray_udma_ReadError  ((FResult)4)
#define plfapixray_udma_ReadError_CONSTANT  4
#define plfapixray_udma_TargetUnknown  ((FResult)1)
#define plfapixray_udma_TargetUnknown_CONSTANT  1
#define plfapixray_udma_WriteError  ((FResult)5)
#define plfapixray_udma_WriteError_CONSTANT  5
extern FResult plfapixray_xray_GetDeviceName( int deviceindex, char * name );
extern FResult plfapixray_xray_GetDeviceRegisterName( int deviceindex, int registerindex, char * name );
extern FResult plfapixray_xray_GetDeviceRegisterValue( int deviceindex, int registerindex, int * val );
extern FResult plfapixray_xray_GetNumberOfDeviceRegisters( int deviceindex, int * wrnr, int * rdnr );
extern FResult plfapixray_xray_GetNumberOfDevices( int * nr );
extern FResult plfapixray_xray_SetDeviceRegisterValue( int deviceindex, int registerindex, int value );
extern FResult plfapixray_xrayitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids );
#define plfapixray_xrayitfid_adc  ((Nat32)1)
#define plfapixray_xrayitfid_adc_CONSTANT  1
#define plfapixray_xrayitfid_hal  ((Nat32)1)
#define plfapixray_xrayitfid_hal_CONSTANT  1
#define plfapixray_xrayitfid_hal5xx0  ((Nat32)1)
#define plfapixray_xrayitfid_hal5xx0_CONSTANT  1
#define plfapixray_xrayitfid_hwreglog  ((Nat32)1)
#define plfapixray_xrayitfid_hwreglog_CONSTANT  1
#define plfapixray_xrayitfid_pwm0  ((Nat32)1)
#define plfapixray_xrayitfid_pwm0_CONSTANT  1
#define plfapixray_xrayitfid_pwm1  ((Nat32)1)
#define plfapixray_xrayitfid_pwm1_CONSTANT  1
#define plfapixray_xrayitfid_udma  ((Nat32)1)
#define plfapixray_xrayitfid_udma_CONSTANT  1
#define plfapixray_xrayitfid_xray  ((Nat32)1)
#define plfapixray_xrayitfid_xray_CONSTANT  1

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapixray_hwreglogN_OnI2cAccessed( Nat32 action, Nat32 bus, Nat32 address, Nat8 * readdata, Nat8 * writedata, Nat32 readlen, Nat32 writelen );
extern void plfapixray_hwreglogN_OnMmioAccessed( Nat32 action, Nat32 device, Nat32 address, Nat32 mmiodata );
#define plfapixray_hwreglogN_Read  ((Nat32)0)
#define plfapixray_hwreglogN_Read_CONSTANT  0
#define plfapixray_hwreglogN_Write  ((Nat32)1)
#define plfapixray_hwreglogN_Write_CONSTANT  1
#define plfapixray_hwreglogN_WriteRead  ((Nat32)2)
#define plfapixray_hwreglogN_WriteRead_CONSTANT  2
extern void plfapixray_xrayitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapixray_EnableNotification_hwreglogN( void );
extern void plfapixray_DisableNotification_hwreglogN( void );
extern void plfapixray_EnableNotification_xrayitfN( void );
extern void plfapixray_DisableNotification_xrayitfN( void );
extern void plfapixray_EnableNotification( int notificationId );
extern void plfapixray_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapixray_call_stubs */
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

extern void plfapixray_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapixray_RegisterHook_adc( IpcHookFunction callback );
extern void plfapixray_RegisterHook_errid( IpcHookFunction callback );
extern void plfapixray_RegisterHook_hal( IpcHookFunction callback );
extern void plfapixray_RegisterHook_hal5xx0( IpcHookFunction callback );
extern void plfapixray_RegisterHook_hwreglog( IpcHookFunction callback );
extern void plfapixray_RegisterHook_pwm0( IpcHookFunction callback );
extern void plfapixray_RegisterHook_pwm1( IpcHookFunction callback );
extern void plfapixray_RegisterHook_udma( IpcHookFunction callback );
extern void plfapixray_RegisterHook_xray( IpcHookFunction callback );
extern void plfapixray_RegisterHook_xrayitf( IpcHookFunction callback );
extern void plfapixray_RegisterHook_xrayitfid( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapixray_RegisterHook_hwreglogN( IpcHookFunction callback );
extern void plfapixray_RegisterHook_xrayitfN( IpcHookFunction callback );

#endif /* _PLFAPIXRAY_H_ */

