
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


#include "plfapiinfra.h"
#include "plfapiinfra_internal.h"

#include "string.h"
#include "stdio.h"
#include "direct/messages.h"
#include "fusiondale.h"

static IFusionDale     *dale      = NULL;
static IComa           *coma      = NULL;
static IComaComponent  *component = NULL;

/* Hooks: variables */
static IpcHookFunction plfapiinfra_hookGlobal = NULL;
static IpcHookFunction plfapiinfra_hook_audonly = NULL;
static IpcHookFunction plfapiinfra_hook_audonly2 = NULL;
static IpcHookFunction plfapiinfra_hook_auth = NULL;
static IpcHookFunction plfapiinfra_hook_bffs = NULL;
static IpcHookFunction plfapiinfra_hook_bootloader = NULL;
static IpcHookFunction plfapiinfra_hook_cecack = NULL;
static IpcHookFunction plfapiinfra_hook_cecctrl = NULL;
static IpcHookFunction plfapiinfra_hook_cectx = NULL;
static IpcHookFunction plfapiinfra_hook_clk = NULL;
static IpcHookFunction plfapiinfra_hook_crypt = NULL;
static IpcHookFunction plfapiinfra_hook_dbbrwse = NULL;
static IpcHookFunction plfapiinfra_hook_dbtf = NULL;
static IpcHookFunction plfapiinfra_hook_dbtfci = NULL;
static IpcHookFunction plfapiinfra_hook_dmpctr = NULL;
static IpcHookFunction plfapiinfra_hook_errid = NULL;
static IpcHookFunction plfapiinfra_hook_evlogctr = NULL;
static IpcHookFunction plfapiinfra_hook_fops = NULL;
static IpcHookFunction plfapiinfra_hook_gio = NULL;
static IpcHookFunction plfapiinfra_hook_i2cc = NULL;
static IpcHookFunction plfapiinfra_hook_i2cm = NULL;
static IpcHookFunction plfapiinfra_hook_infraitf = NULL;
static IpcHookFunction plfapiinfra_hook_infraitfid = NULL;
static IpcHookFunction plfapiinfra_hook_isha = NULL;
static IpcHookFunction plfapiinfra_hook_keyi = NULL;
static IpcHookFunction plfapiinfra_hook_led = NULL;
static IpcHookFunction plfapiinfra_hook_ncd = NULL;
static IpcHookFunction plfapiinfra_hook_net = NULL;
static IpcHookFunction plfapiinfra_hook_net2 = NULL;
static IpcHookFunction plfapiinfra_hook_p2pacN = NULL;
static IpcHookFunction plfapiinfra_hook_p2pah = NULL;
static IpcHookFunction plfapiinfra_hook_p2papid = NULL;
static IpcHookFunction plfapiinfra_hook_resmgr = NULL;
static IpcHookFunction plfapiinfra_hook_secsto = NULL;
static IpcHookFunction plfapiinfra_hook_shmem = NULL;
static IpcHookFunction plfapiinfra_hook_uartctl = NULL;
static IpcHookFunction plfapiinfra_hook_uartprint = NULL;
static IpcHookFunction plfapiinfra_hook_uid = NULL;
static IpcHookFunction plfapiinfra_hook_upginf = NULL;
static IpcHookFunction plfapiinfra_hook_upginf2 = NULL;
static IpcHookFunction plfapiinfra_hook_upginf3 = NULL;
static IpcHookFunction plfapiinfra_hook_upgtool = NULL;
static IpcHookFunction plfapiinfra_hook_upgtool2 = NULL;
static IpcHookFunction plfapiinfra_hook_usbdev = NULL;
static IpcHookFunction plfapiinfra_hook_usbdev2 = NULL;
static IpcHookFunction plfapiinfra_hook_vidstor = NULL;
static IpcHookFunction plfapiinfra_hook_vidstor2 = NULL;
static IpcHookFunction plfapiinfra_hook_cecrxntf = NULL;
static IpcHookFunction plfapiinfra_hook_cectxntf = NULL;
static IpcHookFunction plfapiinfra_hook_clkntf = NULL;
static IpcHookFunction plfapiinfra_hook_clkntfx = NULL;
static IpcHookFunction plfapiinfra_hook_fopsN = NULL;
static IpcHookFunction plfapiinfra_hook_infraitfN = NULL;
static IpcHookFunction plfapiinfra_hook_net2exexN = NULL;
static IpcHookFunction plfapiinfra_hook_net2exN = NULL;
static IpcHookFunction plfapiinfra_hook_net2N = NULL;
static IpcHookFunction plfapiinfra_hook_netexexN = NULL;
static IpcHookFunction plfapiinfra_hook_netexN = NULL;
static IpcHookFunction plfapiinfra_hook_netN = NULL;
static IpcHookFunction plfapiinfra_hook_p2pac = NULL;
static IpcHookFunction plfapiinfra_hook_p2pacx = NULL;
static IpcHookFunction plfapiinfra_hook_p2pahN = NULL;
static IpcHookFunction plfapiinfra_hook_upgtoolN = NULL;
static IpcHookFunction plfapiinfra_hook_usbdevexN = NULL;
static IpcHookFunction plfapiinfra_hook_usbdevN = NULL;
static IpcHookFunction plfapiinfra_hook_vidstorN = NULL;

/* Hooks: Implementations */
void plfapiinfra_RegisterHookGlobal( IpcHookFunction callback )
{
    plfapiinfra_hookGlobal = callback;
}

/*  The following function is for the Koala wrapper only */
extern void plfapiinfra_Hook_CallPosted( unsigned int id, void *data )
{
    if (plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDecoupled, id, data );
    }
}

/* HookType: ipchtCallReceived, ipchtCallHandled */
void plfapiinfra_RegisterHook_audonly( IpcHookFunction callback )
{
    plfapiinfra_hook_audonly = callback;
}

void plfapiinfra_RegisterHook_audonly2( IpcHookFunction callback )
{
    plfapiinfra_hook_audonly2 = callback;
}

void plfapiinfra_RegisterHook_auth( IpcHookFunction callback )
{
    plfapiinfra_hook_auth = callback;
}

void plfapiinfra_RegisterHook_bffs( IpcHookFunction callback )
{
    plfapiinfra_hook_bffs = callback;
}

void plfapiinfra_RegisterHook_bootloader( IpcHookFunction callback )
{
    plfapiinfra_hook_bootloader = callback;
}

void plfapiinfra_RegisterHook_cecack( IpcHookFunction callback )
{
    plfapiinfra_hook_cecack = callback;
}

void plfapiinfra_RegisterHook_cecctrl( IpcHookFunction callback )
{
    plfapiinfra_hook_cecctrl = callback;
}

void plfapiinfra_RegisterHook_cectx( IpcHookFunction callback )
{
    plfapiinfra_hook_cectx = callback;
}

void plfapiinfra_RegisterHook_clk( IpcHookFunction callback )
{
    plfapiinfra_hook_clk = callback;
}

void plfapiinfra_RegisterHook_crypt( IpcHookFunction callback )
{
    plfapiinfra_hook_crypt = callback;
}

void plfapiinfra_RegisterHook_dbbrwse( IpcHookFunction callback )
{
    plfapiinfra_hook_dbbrwse = callback;
}

void plfapiinfra_RegisterHook_dbtf( IpcHookFunction callback )
{
    plfapiinfra_hook_dbtf = callback;
}

void plfapiinfra_RegisterHook_dbtfci( IpcHookFunction callback )
{
    plfapiinfra_hook_dbtfci = callback;
}

void plfapiinfra_RegisterHook_dmpctr( IpcHookFunction callback )
{
    plfapiinfra_hook_dmpctr = callback;
}

void plfapiinfra_RegisterHook_errid( IpcHookFunction callback )
{
    plfapiinfra_hook_errid = callback;
}

void plfapiinfra_RegisterHook_evlogctr( IpcHookFunction callback )
{
    plfapiinfra_hook_evlogctr = callback;
}

void plfapiinfra_RegisterHook_fops( IpcHookFunction callback )
{
    plfapiinfra_hook_fops = callback;
}

void plfapiinfra_RegisterHook_gio( IpcHookFunction callback )
{
    plfapiinfra_hook_gio = callback;
}

void plfapiinfra_RegisterHook_i2cc( IpcHookFunction callback )
{
    plfapiinfra_hook_i2cc = callback;
}

void plfapiinfra_RegisterHook_i2cm( IpcHookFunction callback )
{
    plfapiinfra_hook_i2cm = callback;
}

void plfapiinfra_RegisterHook_infraitf( IpcHookFunction callback )
{
    plfapiinfra_hook_infraitf = callback;
}

void plfapiinfra_RegisterHook_infraitfid( IpcHookFunction callback )
{
    plfapiinfra_hook_infraitfid = callback;
}

void plfapiinfra_RegisterHook_isha( IpcHookFunction callback )
{
    plfapiinfra_hook_isha = callback;
}

void plfapiinfra_RegisterHook_keyi( IpcHookFunction callback )
{
    plfapiinfra_hook_keyi = callback;
}

void plfapiinfra_RegisterHook_led( IpcHookFunction callback )
{
    plfapiinfra_hook_led = callback;
}

void plfapiinfra_RegisterHook_ncd( IpcHookFunction callback )
{
    plfapiinfra_hook_ncd = callback;
}

void plfapiinfra_RegisterHook_net( IpcHookFunction callback )
{
    plfapiinfra_hook_net = callback;
}

void plfapiinfra_RegisterHook_net2( IpcHookFunction callback )
{
    plfapiinfra_hook_net2 = callback;
}

void plfapiinfra_RegisterHook_p2pacN( IpcHookFunction callback )
{
    plfapiinfra_hook_p2pacN = callback;
}

void plfapiinfra_RegisterHook_p2pah( IpcHookFunction callback )
{
    plfapiinfra_hook_p2pah = callback;
}

void plfapiinfra_RegisterHook_p2papid( IpcHookFunction callback )
{
    plfapiinfra_hook_p2papid = callback;
}

void plfapiinfra_RegisterHook_resmgr( IpcHookFunction callback )
{
    plfapiinfra_hook_resmgr = callback;
}

void plfapiinfra_RegisterHook_secsto( IpcHookFunction callback )
{
    plfapiinfra_hook_secsto = callback;
}

void plfapiinfra_RegisterHook_shmem( IpcHookFunction callback )
{
    plfapiinfra_hook_shmem = callback;
}

void plfapiinfra_RegisterHook_uartctl( IpcHookFunction callback )
{
    plfapiinfra_hook_uartctl = callback;
}

void plfapiinfra_RegisterHook_uartprint( IpcHookFunction callback )
{
    plfapiinfra_hook_uartprint = callback;
}

void plfapiinfra_RegisterHook_uid( IpcHookFunction callback )
{
    plfapiinfra_hook_uid = callback;
}

void plfapiinfra_RegisterHook_upginf( IpcHookFunction callback )
{
    plfapiinfra_hook_upginf = callback;
}

void plfapiinfra_RegisterHook_upginf2( IpcHookFunction callback )
{
    plfapiinfra_hook_upginf2 = callback;
}

void plfapiinfra_RegisterHook_upginf3( IpcHookFunction callback )
{
    plfapiinfra_hook_upginf3 = callback;
}

void plfapiinfra_RegisterHook_upgtool( IpcHookFunction callback )
{
    plfapiinfra_hook_upgtool = callback;
}

void plfapiinfra_RegisterHook_upgtool2( IpcHookFunction callback )
{
    plfapiinfra_hook_upgtool2 = callback;
}

void plfapiinfra_RegisterHook_usbdev( IpcHookFunction callback )
{
    plfapiinfra_hook_usbdev = callback;
}

void plfapiinfra_RegisterHook_usbdev2( IpcHookFunction callback )
{
    plfapiinfra_hook_usbdev2 = callback;
}

void plfapiinfra_RegisterHook_vidstor( IpcHookFunction callback )
{
    plfapiinfra_hook_vidstor = callback;
}

void plfapiinfra_RegisterHook_vidstor2( IpcHookFunction callback )
{
    plfapiinfra_hook_vidstor2 = callback;
}

/* HookType: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
void plfapiinfra_RegisterHook_cecrxntf( IpcHookFunction callback )
{
    plfapiinfra_hook_cecrxntf = callback;
}

void plfapiinfra_RegisterHook_cectxntf( IpcHookFunction callback )
{
    plfapiinfra_hook_cectxntf = callback;
}

void plfapiinfra_RegisterHook_clkntf( IpcHookFunction callback )
{
    plfapiinfra_hook_clkntf = callback;
}

void plfapiinfra_RegisterHook_clkntfx( IpcHookFunction callback )
{
    plfapiinfra_hook_clkntfx = callback;
}

void plfapiinfra_RegisterHook_fopsN( IpcHookFunction callback )
{
    plfapiinfra_hook_fopsN = callback;
}

void plfapiinfra_RegisterHook_infraitfN( IpcHookFunction callback )
{
    plfapiinfra_hook_infraitfN = callback;
}

void plfapiinfra_RegisterHook_net2exexN( IpcHookFunction callback )
{
    plfapiinfra_hook_net2exexN = callback;
}

void plfapiinfra_RegisterHook_net2exN( IpcHookFunction callback )
{
    plfapiinfra_hook_net2exN = callback;
}

void plfapiinfra_RegisterHook_net2N( IpcHookFunction callback )
{
    plfapiinfra_hook_net2N = callback;
}

void plfapiinfra_RegisterHook_netexexN( IpcHookFunction callback )
{
    plfapiinfra_hook_netexexN = callback;
}

void plfapiinfra_RegisterHook_netexN( IpcHookFunction callback )
{
    plfapiinfra_hook_netexN = callback;
}

void plfapiinfra_RegisterHook_netN( IpcHookFunction callback )
{
    plfapiinfra_hook_netN = callback;
}

void plfapiinfra_RegisterHook_p2pac( IpcHookFunction callback )
{
    plfapiinfra_hook_p2pac = callback;
}

void plfapiinfra_RegisterHook_p2pacx( IpcHookFunction callback )
{
    plfapiinfra_hook_p2pacx = callback;
}

void plfapiinfra_RegisterHook_p2pahN( IpcHookFunction callback )
{
    plfapiinfra_hook_p2pahN = callback;
}

void plfapiinfra_RegisterHook_upgtoolN( IpcHookFunction callback )
{
    plfapiinfra_hook_upgtoolN = callback;
}

void plfapiinfra_RegisterHook_usbdevexN( IpcHookFunction callback )
{
    plfapiinfra_hook_usbdevexN = callback;
}

void plfapiinfra_RegisterHook_usbdevN( IpcHookFunction callback )
{
    plfapiinfra_hook_usbdevN = callback;
}

void plfapiinfra_RegisterHook_vidstorN( IpcHookFunction callback )
{
    plfapiinfra_hook_vidstorN = callback;
}

#if defined(USE_WEAK_NOTIFICATIONS)
void plfapiinfra_cecrxntf_OnReceived( int size, Nat8 * pMsg ) WEAK;
void plfapiinfra_cectxntf_OnTransmitCompleted( FResult result ) WEAK;
void plfapiinfra_clkntf_OnAlarm( void ) WEAK;
void plfapiinfra_clkntf_OnClockChanged( DateTime old, DateTime new ) WEAK;
void plfapiinfra_clkntfx_OnAlarm( void ) WEAK;
void plfapiinfra_clkntfx_OnAlarmCancelled( void ) WEAK;
void plfapiinfra_clkntfx_OnClockChanged( DateTime old, DateTime new ) WEAK;
void plfapiinfra_fopsN_OnPartitionMounted( char * mountpoint ) WEAK;
void plfapiinfra_fopsN_OnPartitionMountFailed( char * mountpoint ) WEAK;
void plfapiinfra_fopsN_OnPartitionUnmounted( char * mountpoint ) WEAK;
void plfapiinfra_infraitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids ) WEAK;
void plfapiinfra_net2exexN_OnDnsStatusChecked( Bool available ) WEAK;
void plfapiinfra_net2exexN_OnInitializationDone( void ) WEAK;
void plfapiinfra_net2exexN_OnNetworkInterfaceConfigStatusChanged( void ) WEAK;
void plfapiinfra_net2exexN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle ) WEAK;
void plfapiinfra_net2exexN_OnWifiManualSsidFound( Bool retval ) WEAK;
void plfapiinfra_net2exexN_OnWifiScanWifiDevicesCompleted( void ) WEAK;
void plfapiinfra_net2exexN_OnWifiSignalFound( void ) WEAK;
void plfapiinfra_net2exexN_OnWifiSignalLost( void ) WEAK;
void plfapiinfra_net2exexN_OnWpsConnectionFinished( Bool success ) WEAK;
void plfapiinfra_net2exN_OnDnsStatusChecked( Bool available ) WEAK;
void plfapiinfra_net2exN_OnInitializationDone( void ) WEAK;
void plfapiinfra_net2exN_OnNetworkInterfaceConfigStatusChanged( void ) WEAK;
void plfapiinfra_net2exN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle ) WEAK;
void plfapiinfra_net2exN_OnWifiManualSsidFound( Bool retval ) WEAK;
void plfapiinfra_net2exN_OnWifiScanWifiDevicesCompleted( void ) WEAK;
void plfapiinfra_net2exN_OnWifiSignalFound( void ) WEAK;
void plfapiinfra_net2exN_OnWifiSignalLost( void ) WEAK;
void plfapiinfra_net2N_OnDnsStatusChecked( Bool available ) WEAK;
void plfapiinfra_net2N_OnInitializationDone( void ) WEAK;
void plfapiinfra_net2N_OnNetworkInterfaceConfigStatusChanged( void ) WEAK;
void plfapiinfra_net2N_OnNetworkInterfacePhysicalStatusChanged( int intfhandle ) WEAK;
void plfapiinfra_net2N_OnWifiManualSsidFound( Bool retval ) WEAK;
void plfapiinfra_net2N_OnWifiSignalFound( void ) WEAK;
void plfapiinfra_net2N_OnWifiSignalLost( void ) WEAK;
void plfapiinfra_netexexN_OnDnsStatusChecked( Bool available ) WEAK;
void plfapiinfra_netexexN_OnIpConfigurationConflict( void ) WEAK;
void plfapiinfra_netexexN_OnNetworkInterfaceConfigStatusChanged( void ) WEAK;
void plfapiinfra_netexexN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle ) WEAK;
void plfapiinfra_netexexN_OnSelectedWifiDeviceDisappeared( void ) WEAK;
void plfapiinfra_netexexN_OnWifiSelectionCompleted( FResult result ) WEAK;
void plfapiinfra_netexN_OnDnsStatusChecked( Bool available ) WEAK;
void plfapiinfra_netexN_OnIpConfigurationConflict( void ) WEAK;
void plfapiinfra_netexN_OnNetworkInterfaceConfigStatusChanged( void ) WEAK;
void plfapiinfra_netexN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle ) WEAK;
void plfapiinfra_netN_OnIpConfigurationConflict( void ) WEAK;
void plfapiinfra_netN_OnNetworkInterfaceConfigStatusChanged( void ) WEAK;
void plfapiinfra_netN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle ) WEAK;
void plfapiinfra_p2pac_WriteASync( int appid, int bus, void * buf, int size ) WEAK;
void plfapiinfra_p2pac_WriteASyncNoRetry( int appid, int bus, void * buf, int size ) WEAK;
void plfapiinfra_p2pac_WriteNoSync( int appid, int bus, void * buf, int size ) WEAK;
void plfapiinfra_p2pac_WriteNoSyncNoRetry( int appid, int bus, void * buf, int size ) WEAK;
void plfapiinfra_p2pacx_WriteASync( int appid, int bus, void * buf, int size ) WEAK;
void plfapiinfra_p2pacx_WriteASyncNoRetry( int appid, int bus, void * buf, int size ) WEAK;
void plfapiinfra_p2pacx_WriteCharASync( int appid, int bus, char * buf, int size ) WEAK;
void plfapiinfra_p2pacx_WriteCharASyncNoRetry( int appid, int bus, char * buf, int size ) WEAK;
void plfapiinfra_p2pacx_WriteCharNoSync( int appid, int bus, char * buf, int size ) WEAK;
void plfapiinfra_p2pacx_WriteCharNoSyncNoRetry( int appid, int bus, char * buf, int size ) WEAK;
void plfapiinfra_p2pacx_WriteNoSync( int appid, int bus, void * buf, int size ) WEAK;
void plfapiinfra_p2pacx_WriteNoSyncNoRetry( int appid, int bus, void * buf, int size ) WEAK;
void plfapiinfra_p2pahN_OnExecutionCompleted( int appid ) WEAK;
void plfapiinfra_p2pahN_OnTransmissionCompleted( int appid, Bool success ) WEAK;
void plfapiinfra_upgtoolN_OnProgrammingMessage( char * message ) WEAK;
void plfapiinfra_upgtoolN_OnUpgradeLoaded( void ) WEAK;
void plfapiinfra_upgtoolN_OnUpgradeProgrammed( void ) WEAK;
void plfapiinfra_upgtoolN_OnUpgradeValidated( void ) WEAK;
void plfapiinfra_usbdevexN_OnDeviceError( int errortype, int devid, int physdevid ) WEAK;
void plfapiinfra_usbdevexN_OnDeviceInfoChanged( int devid, int physdevid ) WEAK;
void plfapiinfra_usbdevexN_OnDeviceRemoved( int devid, int physdevid ) WEAK;
void plfapiinfra_usbdevexN_OnDriveMounted( int devid, char * drivename, int physdevid ) WEAK;
void plfapiinfra_usbdevexN_OnDriveUnmounted( int devid, char * drivename, int physdevid ) WEAK;
void plfapiinfra_usbdevexN_OnInitializationDone( void ) WEAK;
void plfapiinfra_usbdevexN_OnNewDevice( int devid, int physdevid ) WEAK;
void plfapiinfra_usbdevexN_OnPhysicalDeviceConnected( int physdevid ) WEAK;
void plfapiinfra_usbdevexN_OnPhysicalDeviceDisconnected( int physdevid ) WEAK;
void plfapiinfra_usbdevN_OnDeviceError( int errortype, int devid, int physdevid ) WEAK;
void plfapiinfra_usbdevN_OnDeviceInfoChanged( int devid, int physdevid ) WEAK;
void plfapiinfra_usbdevN_OnDeviceRemoved( int devid, int physdevid ) WEAK;
void plfapiinfra_usbdevN_OnDriveMounted( int devid, char * drivename, int physdevid ) WEAK;
void plfapiinfra_usbdevN_OnDriveUnmounted( int devid, char * drivename, int physdevid ) WEAK;
void plfapiinfra_usbdevN_OnNewDevice( int devid, int physdevid ) WEAK;
void plfapiinfra_usbdevN_OnPhysicalDeviceConnected( int physdevid ) WEAK;
void plfapiinfra_usbdevN_OnPhysicalDeviceDisconnected( int physdevid ) WEAK;
void plfapiinfra_vidstorN_OnInitialisationDone( void ) WEAK;
void plfapiinfra_vidstorN_OnSDCardFormatProgress( int progress ) WEAK;
void plfapiinfra_vidstorN_OnSDCardFormatted( Bool success ) WEAK;
void plfapiinfra_vidstorN_OnSDCardInserted( void ) WEAK;
void plfapiinfra_vidstorN_OnSDCardMounted( char * mountpoint ) WEAK;
void plfapiinfra_vidstorN_OnSDCardMountFailed( char * mountpoint ) WEAK;
void plfapiinfra_vidstorN_OnSDCardRemoved( void ) WEAK;
void plfapiinfra_vidstorN_OnSDCardUnmounted( char * mountpoint ) WEAK;
void plfapiinfra_vidstorN_OnSDCardUnmountFailed( char * mountpoint ) WEAK;

void plfapiinfra_cecrxntf_OnReceived( int size, Nat8 * pMsg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 0, NULL );
    }
    if ( plfapiinfra_hook_cecrxntf )
    {
        (*plfapiinfra_hook_cecrxntf)( ipchtNotificationDiscarded, 0, NULL );
    }
    /* do nothing */
    (void)size;
    (void)pMsg;
}

void plfapiinfra_cectxntf_OnTransmitCompleted( FResult result )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 1, NULL );
    }
    if ( plfapiinfra_hook_cectxntf )
    {
        (*plfapiinfra_hook_cectxntf)( ipchtNotificationDiscarded, 1, NULL );
    }
    /* do nothing */
    (void)result;
}

void plfapiinfra_clkntf_OnAlarm( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 2, NULL );
    }
    if ( plfapiinfra_hook_clkntf )
    {
        (*plfapiinfra_hook_clkntf)( ipchtNotificationDiscarded, 2, NULL );
    }
    /* do nothing */
}

void plfapiinfra_clkntf_OnClockChanged( DateTime old, DateTime new )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 3, NULL );
    }
    if ( plfapiinfra_hook_clkntf )
    {
        (*plfapiinfra_hook_clkntf)( ipchtNotificationDiscarded, 3, NULL );
    }
    /* do nothing */
    (void)old;
    (void)new;
}

void plfapiinfra_clkntfx_OnAlarm( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 4, NULL );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationDiscarded, 4, NULL );
    }
    /* do nothing */
}

void plfapiinfra_clkntfx_OnAlarmCancelled( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 5, NULL );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationDiscarded, 5, NULL );
    }
    /* do nothing */
}

void plfapiinfra_clkntfx_OnClockChanged( DateTime old, DateTime new )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 6, NULL );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationDiscarded, 6, NULL );
    }
    /* do nothing */
    (void)old;
    (void)new;
}

void plfapiinfra_fopsN_OnPartitionMounted( char * mountpoint )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 7, NULL );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationDiscarded, 7, NULL );
    }
    /* do nothing */
    (void)mountpoint;
}

void plfapiinfra_fopsN_OnPartitionMountFailed( char * mountpoint )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 8, NULL );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationDiscarded, 8, NULL );
    }
    /* do nothing */
    (void)mountpoint;
}

void plfapiinfra_fopsN_OnPartitionUnmounted( char * mountpoint )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 9, NULL );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationDiscarded, 9, NULL );
    }
    /* do nothing */
    (void)mountpoint;
}

void plfapiinfra_infraitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 10, NULL );
    }
    if ( plfapiinfra_hook_infraitfN )
    {
        (*plfapiinfra_hook_infraitfN)( ipchtNotificationDiscarded, 10, NULL );
    }
    /* do nothing */
    (void)nbrgroups;
    (void)ids;
}

void plfapiinfra_net2exexN_OnDnsStatusChecked( Bool available )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 11, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 11, NULL );
    }
    /* do nothing */
    (void)available;
}

void plfapiinfra_net2exexN_OnInitializationDone( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 12, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 12, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exexN_OnNetworkInterfaceConfigStatusChanged( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 13, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 13, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exexN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 14, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 14, NULL );
    }
    /* do nothing */
    (void)intfhandle;
}

void plfapiinfra_net2exexN_OnWifiManualSsidFound( Bool retval )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 15, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 15, NULL );
    }
    /* do nothing */
    (void)retval;
}

void plfapiinfra_net2exexN_OnWifiScanWifiDevicesCompleted( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 16, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 16, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exexN_OnWifiSignalFound( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 17, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 17, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exexN_OnWifiSignalLost( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 18, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 18, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exexN_OnWpsConnectionFinished( Bool success )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 19, NULL );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationDiscarded, 19, NULL );
    }
    /* do nothing */
    (void)success;
}

void plfapiinfra_net2exN_OnDnsStatusChecked( Bool available )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 20, NULL );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationDiscarded, 20, NULL );
    }
    /* do nothing */
    (void)available;
}

void plfapiinfra_net2exN_OnInitializationDone( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 21, NULL );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationDiscarded, 21, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exN_OnNetworkInterfaceConfigStatusChanged( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 22, NULL );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationDiscarded, 22, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 23, NULL );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationDiscarded, 23, NULL );
    }
    /* do nothing */
    (void)intfhandle;
}

void plfapiinfra_net2exN_OnWifiManualSsidFound( Bool retval )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 24, NULL );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationDiscarded, 24, NULL );
    }
    /* do nothing */
    (void)retval;
}

void plfapiinfra_net2exN_OnWifiScanWifiDevicesCompleted( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 25, NULL );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationDiscarded, 25, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exN_OnWifiSignalFound( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 26, NULL );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationDiscarded, 26, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2exN_OnWifiSignalLost( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 27, NULL );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationDiscarded, 27, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2N_OnDnsStatusChecked( Bool available )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 28, NULL );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationDiscarded, 28, NULL );
    }
    /* do nothing */
    (void)available;
}

void plfapiinfra_net2N_OnInitializationDone( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 29, NULL );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationDiscarded, 29, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2N_OnNetworkInterfaceConfigStatusChanged( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 30, NULL );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationDiscarded, 30, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2N_OnNetworkInterfacePhysicalStatusChanged( int intfhandle )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 31, NULL );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationDiscarded, 31, NULL );
    }
    /* do nothing */
    (void)intfhandle;
}

void plfapiinfra_net2N_OnWifiManualSsidFound( Bool retval )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 32, NULL );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationDiscarded, 32, NULL );
    }
    /* do nothing */
    (void)retval;
}

void plfapiinfra_net2N_OnWifiSignalFound( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 33, NULL );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationDiscarded, 33, NULL );
    }
    /* do nothing */
}

void plfapiinfra_net2N_OnWifiSignalLost( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 34, NULL );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationDiscarded, 34, NULL );
    }
    /* do nothing */
}

void plfapiinfra_netexexN_OnDnsStatusChecked( Bool available )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 35, NULL );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationDiscarded, 35, NULL );
    }
    /* do nothing */
    (void)available;
}

void plfapiinfra_netexexN_OnIpConfigurationConflict( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 36, NULL );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationDiscarded, 36, NULL );
    }
    /* do nothing */
}

void plfapiinfra_netexexN_OnNetworkInterfaceConfigStatusChanged( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 37, NULL );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationDiscarded, 37, NULL );
    }
    /* do nothing */
}

void plfapiinfra_netexexN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 38, NULL );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationDiscarded, 38, NULL );
    }
    /* do nothing */
    (void)intfhandle;
}

void plfapiinfra_netexexN_OnSelectedWifiDeviceDisappeared( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 39, NULL );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationDiscarded, 39, NULL );
    }
    /* do nothing */
}

void plfapiinfra_netexexN_OnWifiSelectionCompleted( FResult result )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 40, NULL );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationDiscarded, 40, NULL );
    }
    /* do nothing */
    (void)result;
}

void plfapiinfra_netexN_OnDnsStatusChecked( Bool available )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 41, NULL );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationDiscarded, 41, NULL );
    }
    /* do nothing */
    (void)available;
}

void plfapiinfra_netexN_OnIpConfigurationConflict( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 42, NULL );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationDiscarded, 42, NULL );
    }
    /* do nothing */
}

void plfapiinfra_netexN_OnNetworkInterfaceConfigStatusChanged( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 43, NULL );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationDiscarded, 43, NULL );
    }
    /* do nothing */
}

void plfapiinfra_netexN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 44, NULL );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationDiscarded, 44, NULL );
    }
    /* do nothing */
    (void)intfhandle;
}

void plfapiinfra_netN_OnIpConfigurationConflict( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 45, NULL );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationDiscarded, 45, NULL );
    }
    /* do nothing */
}

void plfapiinfra_netN_OnNetworkInterfaceConfigStatusChanged( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 46, NULL );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationDiscarded, 46, NULL );
    }
    /* do nothing */
}

void plfapiinfra_netN_OnNetworkInterfacePhysicalStatusChanged( int intfhandle )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 47, NULL );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationDiscarded, 47, NULL );
    }
    /* do nothing */
    (void)intfhandle;
}

void plfapiinfra_p2pac_WriteASync( int appid, int bus, void * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 48, NULL );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationDiscarded, 48, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pac_WriteASyncNoRetry( int appid, int bus, void * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 49, NULL );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationDiscarded, 49, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pac_WriteNoSync( int appid, int bus, void * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 50, NULL );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationDiscarded, 50, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pac_WriteNoSyncNoRetry( int appid, int bus, void * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 51, NULL );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationDiscarded, 51, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pacx_WriteASync( int appid, int bus, void * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 52, NULL );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationDiscarded, 52, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pacx_WriteASyncNoRetry( int appid, int bus, void * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 53, NULL );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationDiscarded, 53, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pacx_WriteCharASync( int appid, int bus, char * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 54, NULL );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationDiscarded, 54, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pacx_WriteCharASyncNoRetry( int appid, int bus, char * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 55, NULL );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationDiscarded, 55, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pacx_WriteCharNoSync( int appid, int bus, char * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 56, NULL );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationDiscarded, 56, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pacx_WriteCharNoSyncNoRetry( int appid, int bus, char * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 57, NULL );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationDiscarded, 57, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pacx_WriteNoSync( int appid, int bus, void * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 58, NULL );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationDiscarded, 58, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pacx_WriteNoSyncNoRetry( int appid, int bus, void * buf, int size )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 59, NULL );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationDiscarded, 59, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)bus;
    (void)buf;
    (void)size;
}

void plfapiinfra_p2pahN_OnExecutionCompleted( int appid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 60, NULL );
    }
    if ( plfapiinfra_hook_p2pahN )
    {
        (*plfapiinfra_hook_p2pahN)( ipchtNotificationDiscarded, 60, NULL );
    }
    /* do nothing */
    (void)appid;
}

void plfapiinfra_p2pahN_OnTransmissionCompleted( int appid, Bool success )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 61, NULL );
    }
    if ( plfapiinfra_hook_p2pahN )
    {
        (*plfapiinfra_hook_p2pahN)( ipchtNotificationDiscarded, 61, NULL );
    }
    /* do nothing */
    (void)appid;
    (void)success;
}

void plfapiinfra_upgtoolN_OnProgrammingMessage( char * message )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 62, NULL );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationDiscarded, 62, NULL );
    }
    /* do nothing */
    (void)message;
}

void plfapiinfra_upgtoolN_OnUpgradeLoaded( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 63, NULL );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationDiscarded, 63, NULL );
    }
    /* do nothing */
}

void plfapiinfra_upgtoolN_OnUpgradeProgrammed( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 64, NULL );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationDiscarded, 64, NULL );
    }
    /* do nothing */
}

void plfapiinfra_upgtoolN_OnUpgradeValidated( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 65, NULL );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationDiscarded, 65, NULL );
    }
    /* do nothing */
}

void plfapiinfra_usbdevexN_OnDeviceError( int errortype, int devid, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 66, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 66, NULL );
    }
    /* do nothing */
    (void)errortype;
    (void)devid;
    (void)physdevid;
}

void plfapiinfra_usbdevexN_OnDeviceInfoChanged( int devid, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 67, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 67, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)physdevid;
}

void plfapiinfra_usbdevexN_OnDeviceRemoved( int devid, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 68, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 68, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)physdevid;
}

void plfapiinfra_usbdevexN_OnDriveMounted( int devid, char * drivename, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 69, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 69, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)drivename;
    (void)physdevid;
}

void plfapiinfra_usbdevexN_OnDriveUnmounted( int devid, char * drivename, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 70, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 70, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)drivename;
    (void)physdevid;
}

void plfapiinfra_usbdevexN_OnInitializationDone( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 71, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 71, NULL );
    }
    /* do nothing */
}

void plfapiinfra_usbdevexN_OnNewDevice( int devid, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 72, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 72, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)physdevid;
}

void plfapiinfra_usbdevexN_OnPhysicalDeviceConnected( int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 73, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 73, NULL );
    }
    /* do nothing */
    (void)physdevid;
}

void plfapiinfra_usbdevexN_OnPhysicalDeviceDisconnected( int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 74, NULL );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationDiscarded, 74, NULL );
    }
    /* do nothing */
    (void)physdevid;
}

void plfapiinfra_usbdevN_OnDeviceError( int errortype, int devid, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 75, NULL );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationDiscarded, 75, NULL );
    }
    /* do nothing */
    (void)errortype;
    (void)devid;
    (void)physdevid;
}

void plfapiinfra_usbdevN_OnDeviceInfoChanged( int devid, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 76, NULL );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationDiscarded, 76, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)physdevid;
}

void plfapiinfra_usbdevN_OnDeviceRemoved( int devid, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 77, NULL );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationDiscarded, 77, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)physdevid;
}

void plfapiinfra_usbdevN_OnDriveMounted( int devid, char * drivename, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 78, NULL );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationDiscarded, 78, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)drivename;
    (void)physdevid;
}

void plfapiinfra_usbdevN_OnDriveUnmounted( int devid, char * drivename, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 79, NULL );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationDiscarded, 79, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)drivename;
    (void)physdevid;
}

void plfapiinfra_usbdevN_OnNewDevice( int devid, int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 80, NULL );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationDiscarded, 80, NULL );
    }
    /* do nothing */
    (void)devid;
    (void)physdevid;
}

void plfapiinfra_usbdevN_OnPhysicalDeviceConnected( int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 81, NULL );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationDiscarded, 81, NULL );
    }
    /* do nothing */
    (void)physdevid;
}

void plfapiinfra_usbdevN_OnPhysicalDeviceDisconnected( int physdevid )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 82, NULL );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationDiscarded, 82, NULL );
    }
    /* do nothing */
    (void)physdevid;
}

void plfapiinfra_vidstorN_OnInitialisationDone( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 83, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 83, NULL );
    }
    /* do nothing */
}

void plfapiinfra_vidstorN_OnSDCardFormatProgress( int progress )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 84, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 84, NULL );
    }
    /* do nothing */
    (void)progress;
}

void plfapiinfra_vidstorN_OnSDCardFormatted( Bool success )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 85, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 85, NULL );
    }
    /* do nothing */
    (void)success;
}

void plfapiinfra_vidstorN_OnSDCardInserted( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 86, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 86, NULL );
    }
    /* do nothing */
}

void plfapiinfra_vidstorN_OnSDCardMounted( char * mountpoint )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 87, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 87, NULL );
    }
    /* do nothing */
    (void)mountpoint;
}

void plfapiinfra_vidstorN_OnSDCardMountFailed( char * mountpoint )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 88, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 88, NULL );
    }
    /* do nothing */
    (void)mountpoint;
}

void plfapiinfra_vidstorN_OnSDCardRemoved( void )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 89, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 89, NULL );
    }
    /* do nothing */
}

void plfapiinfra_vidstorN_OnSDCardUnmounted( char * mountpoint )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 90, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 90, NULL );
    }
    /* do nothing */
    (void)mountpoint;
}

void plfapiinfra_vidstorN_OnSDCardUnmountFailed( char * mountpoint )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationDiscarded, 91, NULL );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationDiscarded, 91, NULL );
    }
    /* do nothing */
    (void)mountpoint;
}

#endif /* USE_WEAK_NOTIFICATIONS */

static void stub_plfapiinfra_cecrxntf_OnReceived( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 0, arg );
    }
    if ( plfapiinfra_hook_cecrxntf )
    {
        (*plfapiinfra_hook_cecrxntf)( ipchtNotificationReceived, 0, arg );
    }
    cecrxntfOnReceived * data = (cecrxntfOnReceived *)arg;
    (void)ctx;
    plfapiinfra_cecrxntf_OnReceived( data->size, (Nat8 *)data->pMsg );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 0, arg );
    }
    if ( plfapiinfra_hook_cecrxntf )
    {
        (*plfapiinfra_hook_cecrxntf)( ipchtNotificationHandled, 0, arg );
    }
    return;
}

static void stub_plfapiinfra_cectxntf_OnTransmitCompleted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 1, arg );
    }
    if ( plfapiinfra_hook_cectxntf )
    {
        (*plfapiinfra_hook_cectxntf)( ipchtNotificationReceived, 1, arg );
    }
    cectxntfOnTransmitCompleted * data = (cectxntfOnTransmitCompleted *)arg;
    (void)ctx;
    plfapiinfra_cectxntf_OnTransmitCompleted( data->result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 1, arg );
    }
    if ( plfapiinfra_hook_cectxntf )
    {
        (*plfapiinfra_hook_cectxntf)( ipchtNotificationHandled, 1, arg );
    }
    return;
}

static void stub_plfapiinfra_clkntf_OnAlarm( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 2, arg );
    }
    if ( plfapiinfra_hook_clkntf )
    {
        (*plfapiinfra_hook_clkntf)( ipchtNotificationReceived, 2, arg );
    }
    (void)ctx;
    plfapiinfra_clkntf_OnAlarm();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 2, arg );
    }
    if ( plfapiinfra_hook_clkntf )
    {
        (*plfapiinfra_hook_clkntf)( ipchtNotificationHandled, 2, arg );
    }
    return;
}

static void stub_plfapiinfra_clkntf_OnClockChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 3, arg );
    }
    if ( plfapiinfra_hook_clkntf )
    {
        (*plfapiinfra_hook_clkntf)( ipchtNotificationReceived, 3, arg );
    }
    clkntfOnClockChanged * data = (clkntfOnClockChanged *)arg;
    (void)ctx;
    plfapiinfra_clkntf_OnClockChanged( data->old, data->new );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 3, arg );
    }
    if ( plfapiinfra_hook_clkntf )
    {
        (*plfapiinfra_hook_clkntf)( ipchtNotificationHandled, 3, arg );
    }
    return;
}

static void stub_plfapiinfra_clkntfx_OnAlarm( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 4, arg );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationReceived, 4, arg );
    }
    (void)ctx;
    plfapiinfra_clkntfx_OnAlarm();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 4, arg );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationHandled, 4, arg );
    }
    return;
}

static void stub_plfapiinfra_clkntfx_OnAlarmCancelled( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 5, arg );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationReceived, 5, arg );
    }
    (void)ctx;
    plfapiinfra_clkntfx_OnAlarmCancelled();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 5, arg );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationHandled, 5, arg );
    }
    return;
}

static void stub_plfapiinfra_clkntfx_OnClockChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 6, arg );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationReceived, 6, arg );
    }
    clkntfxOnClockChanged * data = (clkntfxOnClockChanged *)arg;
    (void)ctx;
    plfapiinfra_clkntfx_OnClockChanged( data->old, data->new );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 6, arg );
    }
    if ( plfapiinfra_hook_clkntfx )
    {
        (*plfapiinfra_hook_clkntfx)( ipchtNotificationHandled, 6, arg );
    }
    return;
}

static void stub_plfapiinfra_fopsN_OnPartitionMounted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 7, arg );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationReceived, 7, arg );
    }
    fopsNOnPartitionMounted * data = (fopsNOnPartitionMounted *)arg;
    (void)ctx;
    plfapiinfra_fopsN_OnPartitionMounted( data->mountpoint );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 7, arg );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationHandled, 7, arg );
    }
    return;
}

static void stub_plfapiinfra_fopsN_OnPartitionMountFailed( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 8, arg );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationReceived, 8, arg );
    }
    fopsNOnPartitionMountFailed * data = (fopsNOnPartitionMountFailed *)arg;
    (void)ctx;
    plfapiinfra_fopsN_OnPartitionMountFailed( data->mountpoint );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 8, arg );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationHandled, 8, arg );
    }
    return;
}

static void stub_plfapiinfra_fopsN_OnPartitionUnmounted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 9, arg );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationReceived, 9, arg );
    }
    fopsNOnPartitionUnmounted * data = (fopsNOnPartitionUnmounted *)arg;
    (void)ctx;
    plfapiinfra_fopsN_OnPartitionUnmounted( data->mountpoint );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 9, arg );
    }
    if ( plfapiinfra_hook_fopsN )
    {
        (*plfapiinfra_hook_fopsN)( ipchtNotificationHandled, 9, arg );
    }
    return;
}

static void stub_plfapiinfra_infraitfN_OnAvailabilityChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 10, arg );
    }
    if ( plfapiinfra_hook_infraitfN )
    {
        (*plfapiinfra_hook_infraitfN)( ipchtNotificationReceived, 10, arg );
    }
    infraitfNOnAvailabilityChanged * data = (infraitfNOnAvailabilityChanged *)arg;
    (void)ctx;
    plfapiinfra_infraitfN_OnAvailabilityChanged( data->nbrgroups, (Nat32 *)data->ids );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 10, arg );
    }
    if ( plfapiinfra_hook_infraitfN )
    {
        (*plfapiinfra_hook_infraitfN)( ipchtNotificationHandled, 10, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnDnsStatusChecked( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 11, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 11, arg );
    }
    net2exexNOnDnsStatusChecked * data = (net2exexNOnDnsStatusChecked *)arg;
    (void)ctx;
    plfapiinfra_net2exexN_OnDnsStatusChecked( data->available );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 11, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 11, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnInitializationDone( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 12, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 12, arg );
    }
    (void)ctx;
    plfapiinfra_net2exexN_OnInitializationDone();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 12, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 12, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnNetworkInterfaceConfigStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 13, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 13, arg );
    }
    (void)ctx;
    plfapiinfra_net2exexN_OnNetworkInterfaceConfigStatusChanged();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 13, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 13, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnNetworkInterfacePhysicalStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 14, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 14, arg );
    }
    net2exexNOnNetworkInterfacePhysicalStatusChanged * data = (net2exexNOnNetworkInterfacePhysicalStatusChanged *)arg;
    (void)ctx;
    plfapiinfra_net2exexN_OnNetworkInterfacePhysicalStatusChanged( data->intfhandle );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 14, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 14, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnWifiManualSsidFound( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 15, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 15, arg );
    }
    net2exexNOnWifiManualSsidFound * data = (net2exexNOnWifiManualSsidFound *)arg;
    (void)ctx;
    plfapiinfra_net2exexN_OnWifiManualSsidFound( data->retval );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 15, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 15, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnWifiScanWifiDevicesCompleted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 16, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 16, arg );
    }
    (void)ctx;
    plfapiinfra_net2exexN_OnWifiScanWifiDevicesCompleted();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 16, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 16, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnWifiSignalFound( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 17, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 17, arg );
    }
    (void)ctx;
    plfapiinfra_net2exexN_OnWifiSignalFound();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 17, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 17, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnWifiSignalLost( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 18, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 18, arg );
    }
    (void)ctx;
    plfapiinfra_net2exexN_OnWifiSignalLost();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 18, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 18, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exexN_OnWpsConnectionFinished( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 19, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationReceived, 19, arg );
    }
    net2exexNOnWpsConnectionFinished * data = (net2exexNOnWpsConnectionFinished *)arg;
    (void)ctx;
    plfapiinfra_net2exexN_OnWpsConnectionFinished( data->success );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 19, arg );
    }
    if ( plfapiinfra_hook_net2exexN )
    {
        (*plfapiinfra_hook_net2exexN)( ipchtNotificationHandled, 19, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exN_OnDnsStatusChecked( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 20, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationReceived, 20, arg );
    }
    net2exNOnDnsStatusChecked * data = (net2exNOnDnsStatusChecked *)arg;
    (void)ctx;
    plfapiinfra_net2exN_OnDnsStatusChecked( data->available );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 20, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationHandled, 20, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exN_OnInitializationDone( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 21, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationReceived, 21, arg );
    }
    (void)ctx;
    plfapiinfra_net2exN_OnInitializationDone();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 21, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationHandled, 21, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exN_OnNetworkInterfaceConfigStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 22, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationReceived, 22, arg );
    }
    (void)ctx;
    plfapiinfra_net2exN_OnNetworkInterfaceConfigStatusChanged();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 22, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationHandled, 22, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exN_OnNetworkInterfacePhysicalStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 23, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationReceived, 23, arg );
    }
    net2exNOnNetworkInterfacePhysicalStatusChanged * data = (net2exNOnNetworkInterfacePhysicalStatusChanged *)arg;
    (void)ctx;
    plfapiinfra_net2exN_OnNetworkInterfacePhysicalStatusChanged( data->intfhandle );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 23, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationHandled, 23, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exN_OnWifiManualSsidFound( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 24, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationReceived, 24, arg );
    }
    net2exNOnWifiManualSsidFound * data = (net2exNOnWifiManualSsidFound *)arg;
    (void)ctx;
    plfapiinfra_net2exN_OnWifiManualSsidFound( data->retval );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 24, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationHandled, 24, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exN_OnWifiScanWifiDevicesCompleted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 25, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationReceived, 25, arg );
    }
    (void)ctx;
    plfapiinfra_net2exN_OnWifiScanWifiDevicesCompleted();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 25, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationHandled, 25, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exN_OnWifiSignalFound( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 26, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationReceived, 26, arg );
    }
    (void)ctx;
    plfapiinfra_net2exN_OnWifiSignalFound();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 26, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationHandled, 26, arg );
    }
    return;
}

static void stub_plfapiinfra_net2exN_OnWifiSignalLost( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 27, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationReceived, 27, arg );
    }
    (void)ctx;
    plfapiinfra_net2exN_OnWifiSignalLost();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 27, arg );
    }
    if ( plfapiinfra_hook_net2exN )
    {
        (*plfapiinfra_hook_net2exN)( ipchtNotificationHandled, 27, arg );
    }
    return;
}

static void stub_plfapiinfra_net2N_OnDnsStatusChecked( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 28, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationReceived, 28, arg );
    }
    net2NOnDnsStatusChecked * data = (net2NOnDnsStatusChecked *)arg;
    (void)ctx;
    plfapiinfra_net2N_OnDnsStatusChecked( data->available );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 28, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationHandled, 28, arg );
    }
    return;
}

static void stub_plfapiinfra_net2N_OnInitializationDone( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 29, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationReceived, 29, arg );
    }
    (void)ctx;
    plfapiinfra_net2N_OnInitializationDone();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 29, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationHandled, 29, arg );
    }
    return;
}

static void stub_plfapiinfra_net2N_OnNetworkInterfaceConfigStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 30, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationReceived, 30, arg );
    }
    (void)ctx;
    plfapiinfra_net2N_OnNetworkInterfaceConfigStatusChanged();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 30, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationHandled, 30, arg );
    }
    return;
}

static void stub_plfapiinfra_net2N_OnNetworkInterfacePhysicalStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 31, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationReceived, 31, arg );
    }
    net2NOnNetworkInterfacePhysicalStatusChanged * data = (net2NOnNetworkInterfacePhysicalStatusChanged *)arg;
    (void)ctx;
    plfapiinfra_net2N_OnNetworkInterfacePhysicalStatusChanged( data->intfhandle );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 31, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationHandled, 31, arg );
    }
    return;
}

static void stub_plfapiinfra_net2N_OnWifiManualSsidFound( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 32, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationReceived, 32, arg );
    }
    net2NOnWifiManualSsidFound * data = (net2NOnWifiManualSsidFound *)arg;
    (void)ctx;
    plfapiinfra_net2N_OnWifiManualSsidFound( data->retval );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 32, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationHandled, 32, arg );
    }
    return;
}

static void stub_plfapiinfra_net2N_OnWifiSignalFound( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 33, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationReceived, 33, arg );
    }
    (void)ctx;
    plfapiinfra_net2N_OnWifiSignalFound();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 33, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationHandled, 33, arg );
    }
    return;
}

static void stub_plfapiinfra_net2N_OnWifiSignalLost( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 34, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationReceived, 34, arg );
    }
    (void)ctx;
    plfapiinfra_net2N_OnWifiSignalLost();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 34, arg );
    }
    if ( plfapiinfra_hook_net2N )
    {
        (*plfapiinfra_hook_net2N)( ipchtNotificationHandled, 34, arg );
    }
    return;
}

static void stub_plfapiinfra_netexexN_OnDnsStatusChecked( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 35, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationReceived, 35, arg );
    }
    netexexNOnDnsStatusChecked * data = (netexexNOnDnsStatusChecked *)arg;
    (void)ctx;
    plfapiinfra_netexexN_OnDnsStatusChecked( data->available );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 35, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationHandled, 35, arg );
    }
    return;
}

static void stub_plfapiinfra_netexexN_OnIpConfigurationConflict( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 36, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationReceived, 36, arg );
    }
    (void)ctx;
    plfapiinfra_netexexN_OnIpConfigurationConflict();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 36, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationHandled, 36, arg );
    }
    return;
}

static void stub_plfapiinfra_netexexN_OnNetworkInterfaceConfigStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 37, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationReceived, 37, arg );
    }
    (void)ctx;
    plfapiinfra_netexexN_OnNetworkInterfaceConfigStatusChanged();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 37, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationHandled, 37, arg );
    }
    return;
}

static void stub_plfapiinfra_netexexN_OnNetworkInterfacePhysicalStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 38, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationReceived, 38, arg );
    }
    netexexNOnNetworkInterfacePhysicalStatusChanged * data = (netexexNOnNetworkInterfacePhysicalStatusChanged *)arg;
    (void)ctx;
    plfapiinfra_netexexN_OnNetworkInterfacePhysicalStatusChanged( data->intfhandle );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 38, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationHandled, 38, arg );
    }
    return;
}

static void stub_plfapiinfra_netexexN_OnSelectedWifiDeviceDisappeared( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 39, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationReceived, 39, arg );
    }
    (void)ctx;
    plfapiinfra_netexexN_OnSelectedWifiDeviceDisappeared();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 39, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationHandled, 39, arg );
    }
    return;
}

static void stub_plfapiinfra_netexexN_OnWifiSelectionCompleted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 40, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationReceived, 40, arg );
    }
    netexexNOnWifiSelectionCompleted * data = (netexexNOnWifiSelectionCompleted *)arg;
    (void)ctx;
    plfapiinfra_netexexN_OnWifiSelectionCompleted( data->result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 40, arg );
    }
    if ( plfapiinfra_hook_netexexN )
    {
        (*plfapiinfra_hook_netexexN)( ipchtNotificationHandled, 40, arg );
    }
    return;
}

static void stub_plfapiinfra_netexN_OnDnsStatusChecked( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 41, arg );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationReceived, 41, arg );
    }
    netexNOnDnsStatusChecked * data = (netexNOnDnsStatusChecked *)arg;
    (void)ctx;
    plfapiinfra_netexN_OnDnsStatusChecked( data->available );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 41, arg );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationHandled, 41, arg );
    }
    return;
}

static void stub_plfapiinfra_netexN_OnIpConfigurationConflict( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 42, arg );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationReceived, 42, arg );
    }
    (void)ctx;
    plfapiinfra_netexN_OnIpConfigurationConflict();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 42, arg );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationHandled, 42, arg );
    }
    return;
}

static void stub_plfapiinfra_netexN_OnNetworkInterfaceConfigStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 43, arg );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationReceived, 43, arg );
    }
    (void)ctx;
    plfapiinfra_netexN_OnNetworkInterfaceConfigStatusChanged();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 43, arg );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationHandled, 43, arg );
    }
    return;
}

static void stub_plfapiinfra_netexN_OnNetworkInterfacePhysicalStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 44, arg );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationReceived, 44, arg );
    }
    netexNOnNetworkInterfacePhysicalStatusChanged * data = (netexNOnNetworkInterfacePhysicalStatusChanged *)arg;
    (void)ctx;
    plfapiinfra_netexN_OnNetworkInterfacePhysicalStatusChanged( data->intfhandle );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 44, arg );
    }
    if ( plfapiinfra_hook_netexN )
    {
        (*plfapiinfra_hook_netexN)( ipchtNotificationHandled, 44, arg );
    }
    return;
}

static void stub_plfapiinfra_netN_OnIpConfigurationConflict( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 45, arg );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationReceived, 45, arg );
    }
    (void)ctx;
    plfapiinfra_netN_OnIpConfigurationConflict();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 45, arg );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationHandled, 45, arg );
    }
    return;
}

static void stub_plfapiinfra_netN_OnNetworkInterfaceConfigStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 46, arg );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationReceived, 46, arg );
    }
    (void)ctx;
    plfapiinfra_netN_OnNetworkInterfaceConfigStatusChanged();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 46, arg );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationHandled, 46, arg );
    }
    return;
}

static void stub_plfapiinfra_netN_OnNetworkInterfacePhysicalStatusChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 47, arg );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationReceived, 47, arg );
    }
    netNOnNetworkInterfacePhysicalStatusChanged * data = (netNOnNetworkInterfacePhysicalStatusChanged *)arg;
    (void)ctx;
    plfapiinfra_netN_OnNetworkInterfacePhysicalStatusChanged( data->intfhandle );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 47, arg );
    }
    if ( plfapiinfra_hook_netN )
    {
        (*plfapiinfra_hook_netN)( ipchtNotificationHandled, 47, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pac_WriteASync( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 48, arg );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationReceived, 48, arg );
    }
    p2pacWriteASync * data = (p2pacWriteASync *)arg;
    (void)ctx;
    plfapiinfra_p2pac_WriteASync( data->appid, data->bus, (void *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 48, arg );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationHandled, 48, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pac_WriteASyncNoRetry( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 49, arg );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationReceived, 49, arg );
    }
    p2pacWriteASyncNoRetry * data = (p2pacWriteASyncNoRetry *)arg;
    (void)ctx;
    plfapiinfra_p2pac_WriteASyncNoRetry( data->appid, data->bus, (void *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 49, arg );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationHandled, 49, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pac_WriteNoSync( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 50, arg );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationReceived, 50, arg );
    }
    p2pacWriteNoSync * data = (p2pacWriteNoSync *)arg;
    (void)ctx;
    plfapiinfra_p2pac_WriteNoSync( data->appid, data->bus, (void *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 50, arg );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationHandled, 50, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pac_WriteNoSyncNoRetry( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 51, arg );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationReceived, 51, arg );
    }
    p2pacWriteNoSyncNoRetry * data = (p2pacWriteNoSyncNoRetry *)arg;
    (void)ctx;
    plfapiinfra_p2pac_WriteNoSyncNoRetry( data->appid, data->bus, (void *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 51, arg );
    }
    if ( plfapiinfra_hook_p2pac )
    {
        (*plfapiinfra_hook_p2pac)( ipchtNotificationHandled, 51, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pacx_WriteASync( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 52, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationReceived, 52, arg );
    }
    p2pacxWriteASync * data = (p2pacxWriteASync *)arg;
    (void)ctx;
    plfapiinfra_p2pacx_WriteASync( data->appid, data->bus, (void *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 52, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationHandled, 52, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pacx_WriteASyncNoRetry( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 53, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationReceived, 53, arg );
    }
    p2pacxWriteASyncNoRetry * data = (p2pacxWriteASyncNoRetry *)arg;
    (void)ctx;
    plfapiinfra_p2pacx_WriteASyncNoRetry( data->appid, data->bus, (void *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 53, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationHandled, 53, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pacx_WriteCharASync( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 54, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationReceived, 54, arg );
    }
    p2pacxWriteCharASync * data = (p2pacxWriteCharASync *)arg;
    (void)ctx;
    plfapiinfra_p2pacx_WriteCharASync( data->appid, data->bus, (char *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 54, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationHandled, 54, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pacx_WriteCharASyncNoRetry( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 55, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationReceived, 55, arg );
    }
    p2pacxWriteCharASyncNoRetry * data = (p2pacxWriteCharASyncNoRetry *)arg;
    (void)ctx;
    plfapiinfra_p2pacx_WriteCharASyncNoRetry( data->appid, data->bus, (char *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 55, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationHandled, 55, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pacx_WriteCharNoSync( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 56, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationReceived, 56, arg );
    }
    p2pacxWriteCharNoSync * data = (p2pacxWriteCharNoSync *)arg;
    (void)ctx;
    plfapiinfra_p2pacx_WriteCharNoSync( data->appid, data->bus, (char *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 56, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationHandled, 56, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pacx_WriteCharNoSyncNoRetry( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 57, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationReceived, 57, arg );
    }
    p2pacxWriteCharNoSyncNoRetry * data = (p2pacxWriteCharNoSyncNoRetry *)arg;
    (void)ctx;
    plfapiinfra_p2pacx_WriteCharNoSyncNoRetry( data->appid, data->bus, (char *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 57, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationHandled, 57, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pacx_WriteNoSync( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 58, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationReceived, 58, arg );
    }
    p2pacxWriteNoSync * data = (p2pacxWriteNoSync *)arg;
    (void)ctx;
    plfapiinfra_p2pacx_WriteNoSync( data->appid, data->bus, (void *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 58, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationHandled, 58, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pacx_WriteNoSyncNoRetry( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 59, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationReceived, 59, arg );
    }
    p2pacxWriteNoSyncNoRetry * data = (p2pacxWriteNoSyncNoRetry *)arg;
    (void)ctx;
    plfapiinfra_p2pacx_WriteNoSyncNoRetry( data->appid, data->bus, (void *)data->buf, data->size );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 59, arg );
    }
    if ( plfapiinfra_hook_p2pacx )
    {
        (*plfapiinfra_hook_p2pacx)( ipchtNotificationHandled, 59, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pahN_OnExecutionCompleted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 60, arg );
    }
    if ( plfapiinfra_hook_p2pahN )
    {
        (*plfapiinfra_hook_p2pahN)( ipchtNotificationReceived, 60, arg );
    }
    p2pahNOnExecutionCompleted * data = (p2pahNOnExecutionCompleted *)arg;
    (void)ctx;
    plfapiinfra_p2pahN_OnExecutionCompleted( data->appid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 60, arg );
    }
    if ( plfapiinfra_hook_p2pahN )
    {
        (*plfapiinfra_hook_p2pahN)( ipchtNotificationHandled, 60, arg );
    }
    return;
}

static void stub_plfapiinfra_p2pahN_OnTransmissionCompleted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 61, arg );
    }
    if ( plfapiinfra_hook_p2pahN )
    {
        (*plfapiinfra_hook_p2pahN)( ipchtNotificationReceived, 61, arg );
    }
    p2pahNOnTransmissionCompleted * data = (p2pahNOnTransmissionCompleted *)arg;
    (void)ctx;
    plfapiinfra_p2pahN_OnTransmissionCompleted( data->appid, data->success );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 61, arg );
    }
    if ( plfapiinfra_hook_p2pahN )
    {
        (*plfapiinfra_hook_p2pahN)( ipchtNotificationHandled, 61, arg );
    }
    return;
}

static void stub_plfapiinfra_upgtoolN_OnProgrammingMessage( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 62, arg );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationReceived, 62, arg );
    }
    upgtoolNOnProgrammingMessage * data = (upgtoolNOnProgrammingMessage *)arg;
    (void)ctx;
    plfapiinfra_upgtoolN_OnProgrammingMessage( data->message );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 62, arg );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationHandled, 62, arg );
    }
    return;
}

static void stub_plfapiinfra_upgtoolN_OnUpgradeLoaded( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 63, arg );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationReceived, 63, arg );
    }
    (void)ctx;
    plfapiinfra_upgtoolN_OnUpgradeLoaded();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 63, arg );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationHandled, 63, arg );
    }
    return;
}

static void stub_plfapiinfra_upgtoolN_OnUpgradeProgrammed( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 64, arg );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationReceived, 64, arg );
    }
    (void)ctx;
    plfapiinfra_upgtoolN_OnUpgradeProgrammed();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 64, arg );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationHandled, 64, arg );
    }
    return;
}

static void stub_plfapiinfra_upgtoolN_OnUpgradeValidated( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 65, arg );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationReceived, 65, arg );
    }
    (void)ctx;
    plfapiinfra_upgtoolN_OnUpgradeValidated();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 65, arg );
    }
    if ( plfapiinfra_hook_upgtoolN )
    {
        (*plfapiinfra_hook_upgtoolN)( ipchtNotificationHandled, 65, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnDeviceError( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 66, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 66, arg );
    }
    usbdevexNOnDeviceError * data = (usbdevexNOnDeviceError *)arg;
    (void)ctx;
    plfapiinfra_usbdevexN_OnDeviceError( data->errortype, data->devid, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 66, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 66, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnDeviceInfoChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 67, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 67, arg );
    }
    usbdevexNOnDeviceInfoChanged * data = (usbdevexNOnDeviceInfoChanged *)arg;
    (void)ctx;
    plfapiinfra_usbdevexN_OnDeviceInfoChanged( data->devid, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 67, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 67, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnDeviceRemoved( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 68, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 68, arg );
    }
    usbdevexNOnDeviceRemoved * data = (usbdevexNOnDeviceRemoved *)arg;
    (void)ctx;
    plfapiinfra_usbdevexN_OnDeviceRemoved( data->devid, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 68, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 68, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnDriveMounted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 69, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 69, arg );
    }
    usbdevexNOnDriveMounted * data = (usbdevexNOnDriveMounted *)arg;
    (void)ctx;
    plfapiinfra_usbdevexN_OnDriveMounted( data->devid, data->drivename, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 69, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 69, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnDriveUnmounted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 70, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 70, arg );
    }
    usbdevexNOnDriveUnmounted * data = (usbdevexNOnDriveUnmounted *)arg;
    (void)ctx;
    plfapiinfra_usbdevexN_OnDriveUnmounted( data->devid, data->drivename, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 70, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 70, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnInitializationDone( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 71, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 71, arg );
    }
    (void)ctx;
    plfapiinfra_usbdevexN_OnInitializationDone();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 71, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 71, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnNewDevice( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 72, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 72, arg );
    }
    usbdevexNOnNewDevice * data = (usbdevexNOnNewDevice *)arg;
    (void)ctx;
    plfapiinfra_usbdevexN_OnNewDevice( data->devid, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 72, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 72, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnPhysicalDeviceConnected( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 73, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 73, arg );
    }
    usbdevexNOnPhysicalDeviceConnected * data = (usbdevexNOnPhysicalDeviceConnected *)arg;
    (void)ctx;
    plfapiinfra_usbdevexN_OnPhysicalDeviceConnected( data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 73, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 73, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevexN_OnPhysicalDeviceDisconnected( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 74, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationReceived, 74, arg );
    }
    usbdevexNOnPhysicalDeviceDisconnected * data = (usbdevexNOnPhysicalDeviceDisconnected *)arg;
    (void)ctx;
    plfapiinfra_usbdevexN_OnPhysicalDeviceDisconnected( data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 74, arg );
    }
    if ( plfapiinfra_hook_usbdevexN )
    {
        (*plfapiinfra_hook_usbdevexN)( ipchtNotificationHandled, 74, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevN_OnDeviceError( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 75, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationReceived, 75, arg );
    }
    usbdevNOnDeviceError * data = (usbdevNOnDeviceError *)arg;
    (void)ctx;
    plfapiinfra_usbdevN_OnDeviceError( data->errortype, data->devid, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 75, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationHandled, 75, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevN_OnDeviceInfoChanged( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 76, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationReceived, 76, arg );
    }
    usbdevNOnDeviceInfoChanged * data = (usbdevNOnDeviceInfoChanged *)arg;
    (void)ctx;
    plfapiinfra_usbdevN_OnDeviceInfoChanged( data->devid, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 76, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationHandled, 76, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevN_OnDeviceRemoved( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 77, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationReceived, 77, arg );
    }
    usbdevNOnDeviceRemoved * data = (usbdevNOnDeviceRemoved *)arg;
    (void)ctx;
    plfapiinfra_usbdevN_OnDeviceRemoved( data->devid, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 77, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationHandled, 77, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevN_OnDriveMounted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 78, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationReceived, 78, arg );
    }
    usbdevNOnDriveMounted * data = (usbdevNOnDriveMounted *)arg;
    (void)ctx;
    plfapiinfra_usbdevN_OnDriveMounted( data->devid, data->drivename, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 78, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationHandled, 78, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevN_OnDriveUnmounted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 79, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationReceived, 79, arg );
    }
    usbdevNOnDriveUnmounted * data = (usbdevNOnDriveUnmounted *)arg;
    (void)ctx;
    plfapiinfra_usbdevN_OnDriveUnmounted( data->devid, data->drivename, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 79, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationHandled, 79, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevN_OnNewDevice( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 80, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationReceived, 80, arg );
    }
    usbdevNOnNewDevice * data = (usbdevNOnNewDevice *)arg;
    (void)ctx;
    plfapiinfra_usbdevN_OnNewDevice( data->devid, data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 80, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationHandled, 80, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevN_OnPhysicalDeviceConnected( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 81, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationReceived, 81, arg );
    }
    usbdevNOnPhysicalDeviceConnected * data = (usbdevNOnPhysicalDeviceConnected *)arg;
    (void)ctx;
    plfapiinfra_usbdevN_OnPhysicalDeviceConnected( data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 81, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationHandled, 81, arg );
    }
    return;
}

static void stub_plfapiinfra_usbdevN_OnPhysicalDeviceDisconnected( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 82, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationReceived, 82, arg );
    }
    usbdevNOnPhysicalDeviceDisconnected * data = (usbdevNOnPhysicalDeviceDisconnected *)arg;
    (void)ctx;
    plfapiinfra_usbdevN_OnPhysicalDeviceDisconnected( data->physdevid );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 82, arg );
    }
    if ( plfapiinfra_hook_usbdevN )
    {
        (*plfapiinfra_hook_usbdevN)( ipchtNotificationHandled, 82, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnInitialisationDone( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 83, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 83, arg );
    }
    (void)ctx;
    plfapiinfra_vidstorN_OnInitialisationDone();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 83, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 83, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnSDCardFormatProgress( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 84, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 84, arg );
    }
    vidstorNOnSDCardFormatProgress * data = (vidstorNOnSDCardFormatProgress *)arg;
    (void)ctx;
    plfapiinfra_vidstorN_OnSDCardFormatProgress( data->progress );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 84, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 84, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnSDCardFormatted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 85, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 85, arg );
    }
    vidstorNOnSDCardFormatted * data = (vidstorNOnSDCardFormatted *)arg;
    (void)ctx;
    plfapiinfra_vidstorN_OnSDCardFormatted( data->success );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 85, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 85, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnSDCardInserted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 86, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 86, arg );
    }
    (void)ctx;
    plfapiinfra_vidstorN_OnSDCardInserted();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 86, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 86, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnSDCardMounted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 87, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 87, arg );
    }
    vidstorNOnSDCardMounted * data = (vidstorNOnSDCardMounted *)arg;
    (void)ctx;
    plfapiinfra_vidstorN_OnSDCardMounted( data->mountpoint );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 87, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 87, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnSDCardMountFailed( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 88, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 88, arg );
    }
    vidstorNOnSDCardMountFailed * data = (vidstorNOnSDCardMountFailed *)arg;
    (void)ctx;
    plfapiinfra_vidstorN_OnSDCardMountFailed( data->mountpoint );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 88, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 88, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnSDCardRemoved( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 89, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 89, arg );
    }
    (void)ctx;
    plfapiinfra_vidstorN_OnSDCardRemoved();
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 89, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 89, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnSDCardUnmounted( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 90, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 90, arg );
    }
    vidstorNOnSDCardUnmounted * data = (vidstorNOnSDCardUnmounted *)arg;
    (void)ctx;
    plfapiinfra_vidstorN_OnSDCardUnmounted( data->mountpoint );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 90, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 90, arg );
    }
    return;
}

static void stub_plfapiinfra_vidstorN_OnSDCardUnmountFailed( void *ctx, void *arg )
{
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationReceived, 91, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationReceived, 91, arg );
    }
    vidstorNOnSDCardUnmountFailed * data = (vidstorNOnSDCardUnmountFailed *)arg;
    (void)ctx;
    plfapiinfra_vidstorN_OnSDCardUnmountFailed( data->mountpoint );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtNotificationHandled, 91, arg );
    }
    if ( plfapiinfra_hook_vidstorN )
    {
        (*plfapiinfra_hook_vidstorN)( ipchtNotificationHandled, 91, arg );
    }
    return;
}


static ComaListenerFunc plfapiinfra_listener_stubs[] = {
     stub_plfapiinfra_cecrxntf_OnReceived
    ,stub_plfapiinfra_cectxntf_OnTransmitCompleted
    ,stub_plfapiinfra_clkntf_OnAlarm
    ,stub_plfapiinfra_clkntf_OnClockChanged
    ,stub_plfapiinfra_clkntfx_OnAlarm
    ,stub_plfapiinfra_clkntfx_OnAlarmCancelled
    ,stub_plfapiinfra_clkntfx_OnClockChanged
    ,stub_plfapiinfra_fopsN_OnPartitionMounted
    ,stub_plfapiinfra_fopsN_OnPartitionMountFailed
    ,stub_plfapiinfra_fopsN_OnPartitionUnmounted
    ,stub_plfapiinfra_infraitfN_OnAvailabilityChanged
    ,stub_plfapiinfra_net2exexN_OnDnsStatusChecked
    ,stub_plfapiinfra_net2exexN_OnInitializationDone
    ,stub_plfapiinfra_net2exexN_OnNetworkInterfaceConfigStatusChanged
    ,stub_plfapiinfra_net2exexN_OnNetworkInterfacePhysicalStatusChanged
    ,stub_plfapiinfra_net2exexN_OnWifiManualSsidFound
    ,stub_plfapiinfra_net2exexN_OnWifiScanWifiDevicesCompleted
    ,stub_plfapiinfra_net2exexN_OnWifiSignalFound
    ,stub_plfapiinfra_net2exexN_OnWifiSignalLost
    ,stub_plfapiinfra_net2exexN_OnWpsConnectionFinished
    ,stub_plfapiinfra_net2exN_OnDnsStatusChecked
    ,stub_plfapiinfra_net2exN_OnInitializationDone
    ,stub_plfapiinfra_net2exN_OnNetworkInterfaceConfigStatusChanged
    ,stub_plfapiinfra_net2exN_OnNetworkInterfacePhysicalStatusChanged
    ,stub_plfapiinfra_net2exN_OnWifiManualSsidFound
    ,stub_plfapiinfra_net2exN_OnWifiScanWifiDevicesCompleted
    ,stub_plfapiinfra_net2exN_OnWifiSignalFound
    ,stub_plfapiinfra_net2exN_OnWifiSignalLost
    ,stub_plfapiinfra_net2N_OnDnsStatusChecked
    ,stub_plfapiinfra_net2N_OnInitializationDone
    ,stub_plfapiinfra_net2N_OnNetworkInterfaceConfigStatusChanged
    ,stub_plfapiinfra_net2N_OnNetworkInterfacePhysicalStatusChanged
    ,stub_plfapiinfra_net2N_OnWifiManualSsidFound
    ,stub_plfapiinfra_net2N_OnWifiSignalFound
    ,stub_plfapiinfra_net2N_OnWifiSignalLost
    ,stub_plfapiinfra_netexexN_OnDnsStatusChecked
    ,stub_plfapiinfra_netexexN_OnIpConfigurationConflict
    ,stub_plfapiinfra_netexexN_OnNetworkInterfaceConfigStatusChanged
    ,stub_plfapiinfra_netexexN_OnNetworkInterfacePhysicalStatusChanged
    ,stub_plfapiinfra_netexexN_OnSelectedWifiDeviceDisappeared
    ,stub_plfapiinfra_netexexN_OnWifiSelectionCompleted
    ,stub_plfapiinfra_netexN_OnDnsStatusChecked
    ,stub_plfapiinfra_netexN_OnIpConfigurationConflict
    ,stub_plfapiinfra_netexN_OnNetworkInterfaceConfigStatusChanged
    ,stub_plfapiinfra_netexN_OnNetworkInterfacePhysicalStatusChanged
    ,stub_plfapiinfra_netN_OnIpConfigurationConflict
    ,stub_plfapiinfra_netN_OnNetworkInterfaceConfigStatusChanged
    ,stub_plfapiinfra_netN_OnNetworkInterfacePhysicalStatusChanged
    ,stub_plfapiinfra_p2pac_WriteASync
    ,stub_plfapiinfra_p2pac_WriteASyncNoRetry
    ,stub_plfapiinfra_p2pac_WriteNoSync
    ,stub_plfapiinfra_p2pac_WriteNoSyncNoRetry
    ,stub_plfapiinfra_p2pacx_WriteASync
    ,stub_plfapiinfra_p2pacx_WriteASyncNoRetry
    ,stub_plfapiinfra_p2pacx_WriteCharASync
    ,stub_plfapiinfra_p2pacx_WriteCharASyncNoRetry
    ,stub_plfapiinfra_p2pacx_WriteCharNoSync
    ,stub_plfapiinfra_p2pacx_WriteCharNoSyncNoRetry
    ,stub_plfapiinfra_p2pacx_WriteNoSync
    ,stub_plfapiinfra_p2pacx_WriteNoSyncNoRetry
    ,stub_plfapiinfra_p2pahN_OnExecutionCompleted
    ,stub_plfapiinfra_p2pahN_OnTransmissionCompleted
    ,stub_plfapiinfra_upgtoolN_OnProgrammingMessage
    ,stub_plfapiinfra_upgtoolN_OnUpgradeLoaded
    ,stub_plfapiinfra_upgtoolN_OnUpgradeProgrammed
    ,stub_plfapiinfra_upgtoolN_OnUpgradeValidated
    ,stub_plfapiinfra_usbdevexN_OnDeviceError
    ,stub_plfapiinfra_usbdevexN_OnDeviceInfoChanged
    ,stub_plfapiinfra_usbdevexN_OnDeviceRemoved
    ,stub_plfapiinfra_usbdevexN_OnDriveMounted
    ,stub_plfapiinfra_usbdevexN_OnDriveUnmounted
    ,stub_plfapiinfra_usbdevexN_OnInitializationDone
    ,stub_plfapiinfra_usbdevexN_OnNewDevice
    ,stub_plfapiinfra_usbdevexN_OnPhysicalDeviceConnected
    ,stub_plfapiinfra_usbdevexN_OnPhysicalDeviceDisconnected
    ,stub_plfapiinfra_usbdevN_OnDeviceError
    ,stub_plfapiinfra_usbdevN_OnDeviceInfoChanged
    ,stub_plfapiinfra_usbdevN_OnDeviceRemoved
    ,stub_plfapiinfra_usbdevN_OnDriveMounted
    ,stub_plfapiinfra_usbdevN_OnDriveUnmounted
    ,stub_plfapiinfra_usbdevN_OnNewDevice
    ,stub_plfapiinfra_usbdevN_OnPhysicalDeviceConnected
    ,stub_plfapiinfra_usbdevN_OnPhysicalDeviceDisconnected
    ,stub_plfapiinfra_vidstorN_OnInitialisationDone
    ,stub_plfapiinfra_vidstorN_OnSDCardFormatProgress
    ,stub_plfapiinfra_vidstorN_OnSDCardFormatted
    ,stub_plfapiinfra_vidstorN_OnSDCardInserted
    ,stub_plfapiinfra_vidstorN_OnSDCardMounted
    ,stub_plfapiinfra_vidstorN_OnSDCardMountFailed
    ,stub_plfapiinfra_vidstorN_OnSDCardRemoved
    ,stub_plfapiinfra_vidstorN_OnSDCardUnmounted
    ,stub_plfapiinfra_vidstorN_OnSDCardUnmountFailed
};

extern FResult plfapiinfra_audonly_Activate( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonlyActivate *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonlyActivate );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 0, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCall, 0, data );
    }
    component->Call( component, idaudonlyActivate, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 0, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCallDone, 0, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly_Disable( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonlyDisable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonlyDisable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 1, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCall, 1, data );
    }
    component->Call( component, idaudonlyDisable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 1, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCallDone, 1, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly_Enable( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonlyEnable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonlyEnable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 2, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCall, 2, data );
    }
    component->Call( component, idaudonlyEnable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 2, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCallDone, 2, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly_IsActive( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonlyIsActive *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonlyIsActive );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 3, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCall, 3, data );
    }
    component->Call( component, idaudonlyIsActive, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 3, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCallDone, 3, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly_IsEnabled( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonlyIsEnabled *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonlyIsEnabled );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 4, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCall, 4, data );
    }
    component->Call( component, idaudonlyIsEnabled, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 4, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCallDone, 4, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly_SetDestLogicalAddress( int winid, int address )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonlySetDestLogicalAddress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonlySetDestLogicalAddress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 5, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCall, 5, data );
    }
    component->Call( component, idaudonlySetDestLogicalAddress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 5, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCallDone, 5, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly_SetForwardRcCecKeys( int winid, int nbrkeys, int * source, int * system, int * command, int * usercontrolcode )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonlySetForwardRcCecKeys *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonlySetForwardRcCecKeys );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->nbrkeys = nbrkeys;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 6, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCall, 6, data );
    }
    component->Call( component, idaudonlySetForwardRcCecKeys, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 6, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCallDone, 6, data );
    }

    /*  5. copy "out" parameters */
    if ( source != NULL )
    {
        *source = data->source;
    }
    if ( system != NULL )
    {
        *system = data->system;
    }
    if ( command != NULL )
    {
        *command = data->command;
    }
    if ( usercontrolcode != NULL )
    {
        *usercontrolcode = data->usercontrolcode;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly_SetListenAudioKey( int winid, int source, int system, int command )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonlySetListenAudioKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonlySetListenAudioKey );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->system = system;
    data->command = command;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 7, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCall, 7, data );
    }
    component->Call( component, idaudonlySetListenAudioKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 7, data );
    }
    if ( plfapiinfra_hook_audonly )
    {
        (*plfapiinfra_hook_audonly)( ipchtCallDone, 7, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_Activate( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2Activate *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2Activate );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 8, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 8, data );
    }
    component->Call( component, idaudonly2Activate, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 8, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 8, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_AddForwardCecKey( int winid, int source, int system, int command, int cecaddress, Nat8 cecusercontrolcode, int cecoperandsize, Nat8 cecoperand )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2AddForwardCecKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2AddForwardCecKey );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->system = system;
    data->command = command;
    data->cecaddress = cecaddress;
    data->cecusercontrolcode = cecusercontrolcode;
    data->cecoperandsize = cecoperandsize;
    data->cecoperand = cecoperand;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 9, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 9, data );
    }
    component->Call( component, idaudonly2AddForwardCecKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 9, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 9, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_ClearForwardCecKeys( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2ClearForwardCecKeys *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2ClearForwardCecKeys );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 10, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 10, data );
    }
    component->Call( component, idaudonly2ClearForwardCecKeys, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 10, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 10, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_Disable( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2Disable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2Disable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 11, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 11, data );
    }
    component->Call( component, idaudonly2Disable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 11, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 11, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_Enable( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2Enable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2Enable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 12, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 12, data );
    }
    component->Call( component, idaudonly2Enable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 12, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 12, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_IsActive( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2IsActive *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2IsActive );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 13, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 13, data );
    }
    component->Call( component, idaudonly2IsActive, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 13, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 13, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_IsDisabled( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2IsDisabled *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2IsDisabled );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 14, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 14, data );
    }
    component->Call( component, idaudonly2IsDisabled, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 14, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 14, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_SetDestLogicalAddress( int winid, int address, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2SetDestLogicalAddress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2SetDestLogicalAddress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 15, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 15, data );
    }
    component->Call( component, idaudonly2SetDestLogicalAddress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 15, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 15, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_SetListenAudioKey( int winid, int source, int system, int command )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2SetListenAudioKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2SetListenAudioKey );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->system = system;
    data->command = command;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 16, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 16, data );
    }
    component->Call( component, idaudonly2SetListenAudioKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 16, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 16, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_audonly2_SetStandbyKey( int winid, int source, int system, int command )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    audonly2SetStandbyKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( audonly2SetStandbyKey );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->system = system;
    data->command = command;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 17, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCall, 17, data );
    }
    component->Call( component, idaudonly2SetStandbyKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 17, data );
    }
    if ( plfapiinfra_hook_audonly2 )
    {
        (*plfapiinfra_hook_audonly2)( ipchtCallDone, 17, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_auth_Check( void * addr, int size, void * key, int keysize, void * sig, int sigsize, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    authCheck *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( authCheck ) + ( sizeof( void ) * size ) + ( sizeof( void ) * keysize ) + ( sizeof( void ) * sigsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->addr = ( addr == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authCheck) );
    data->key = ( key == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authCheck) + ( sizeof( void ) * size ) );
    data->sig = ( sig == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authCheck) + ( sizeof( void ) * size ) + ( sizeof( void ) * keysize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->addr != NULL )
    {
        memcpy( data->addr, addr, ( sizeof( void ) * size ) );
    }
    data->size = size;
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( void ) * keysize ) );
    }
    data->keysize = keysize;
    if ( data->sig != NULL )
    {
        memcpy( data->sig, sig, ( sizeof( void ) * sigsize ) );
    }
    data->sigsize = sigsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 18, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCall, 18, data );
    }
    component->Call( component, idauthCheck, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 18, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCallDone, 18, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_auth_CheckFile( void * fname, void * key, int keysize, void * sig, int sigsize, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    authCheckFile *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( authCheckFile ) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) + ( sizeof( void ) * keysize ) + ( sizeof( void ) * sigsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->fname = ( fname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(authCheckFile) );
    data->key = ( key == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authCheckFile) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) );
    data->sig = ( sig == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authCheckFile) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) + ( sizeof( void ) * keysize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->fname != NULL )
    {
        strcpy( data->fname, fname );
    }
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( void ) * keysize ) );
    }
    data->keysize = keysize;
    if ( data->sig != NULL )
    {
        memcpy( data->sig, sig, ( sizeof( void ) * sigsize ) );
    }
    data->sigsize = sigsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 19, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCall, 19, data );
    }
    component->Call( component, idauthCheckFile, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 19, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCallDone, 19, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_auth_CheckFileFromFile( void * fname, void * key, int keysize, void * sigfname, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    authCheckFileFromFile *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( authCheckFileFromFile ) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) + ( sizeof( void ) * keysize ) + ( ( sigfname == NULL ? 0 : strlen( sigfname ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->fname = ( fname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(authCheckFileFromFile) );
    data->key = ( key == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authCheckFileFromFile) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) );
    data->sigfname = ( sigfname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(authCheckFileFromFile) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) + ( sizeof( void ) * keysize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->fname != NULL )
    {
        strcpy( data->fname, fname );
    }
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( void ) * keysize ) );
    }
    data->keysize = keysize;
    if ( data->sigfname != NULL )
    {
        strcpy( data->sigfname, sigfname );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 20, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCall, 20, data );
    }
    component->Call( component, idauthCheckFileFromFile, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 20, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCallDone, 20, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_auth_GetTDFPublicKey( void * key, int keysize )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    authGetTDFPublicKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( authGetTDFPublicKey ) + ( sizeof( void ) * keysize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->key = ( key == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authGetTDFPublicKey) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->keysize = keysize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 21, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCall, 21, data );
    }
    component->Call( component, idauthGetTDFPublicKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 21, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCallDone, 21, data );
    }

    /*  5. copy "out" parameters */
    if ( key != NULL )
    {
        memcpy( key, data->key,( sizeof( void ) * keysize ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_auth_IsProductAuthenticationRequired( Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    authIsProductAuthenticationRequired *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( authIsProductAuthenticationRequired );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 22, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCall, 22, data );
    }
    component->Call( component, idauthIsProductAuthenticationRequired, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 22, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCallDone, 22, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_auth_Sign( void * addr, int size, void * key, int keysize, void * sig, int sigsize, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    authSign *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( authSign ) + ( sizeof( void ) * size ) + ( sizeof( void ) * keysize ) + ( sizeof( void ) * sigsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->addr = ( addr == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authSign) );
    data->key = ( key == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authSign) + ( sizeof( void ) * size ) );
    data->sig = ( sig == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authSign) + ( sizeof( void ) * size ) + ( sizeof( void ) * keysize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->addr != NULL )
    {
        memcpy( data->addr, addr, ( sizeof( void ) * size ) );
    }
    data->size = size;
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( void ) * keysize ) );
    }
    data->keysize = keysize;
    data->sigsize = sigsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 23, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCall, 23, data );
    }
    component->Call( component, idauthSign, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 23, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCallDone, 23, data );
    }

    /*  5. copy "out" parameters */
    if ( sig != NULL )
    {
        memcpy( sig, data->sig,( sizeof( void ) * sigsize ) );
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_auth_SignFile( char * fname, void * key, int keysize, void * sig, int sigsize, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    authSignFile *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( authSignFile ) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) + ( sizeof( void ) * keysize ) + ( sizeof( void ) * sigsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->fname = ( fname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(authSignFile) );
    data->key = ( key == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authSignFile) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) );
    data->sig = ( sig == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authSignFile) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) + ( sizeof( void ) * keysize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->fname != NULL )
    {
        strcpy( data->fname, fname );
    }
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( void ) * keysize ) );
    }
    data->keysize = keysize;
    data->sigsize = sigsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 24, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCall, 24, data );
    }
    component->Call( component, idauthSignFile, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 24, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCallDone, 24, data );
    }

    /*  5. copy "out" parameters */
    if ( sig != NULL )
    {
        memcpy( sig, data->sig,( sizeof( void ) * sigsize ) );
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_auth_SignFileToFile( char * fname, void * key, int keysize, char * sigfname, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    authSignFileToFile *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( authSignFileToFile ) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) + ( sizeof( void ) * keysize ) + ( ( sigfname == NULL ? 0 : strlen( sigfname ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->fname = ( fname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(authSignFileToFile) );
    data->key = ( key == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(authSignFileToFile) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) );
    data->sigfname = ( sigfname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(authSignFileToFile) + ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ) + ( sizeof( void ) * keysize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->fname != NULL )
    {
        strcpy( data->fname, fname );
    }
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( void ) * keysize ) );
    }
    data->keysize = keysize;
    if ( data->sigfname != NULL )
    {
        strcpy( data->sigfname, sigfname );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 25, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCall, 25, data );
    }
    component->Call( component, idauthSignFileToFile, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 25, data );
    }
    if ( plfapiinfra_hook_auth )
    {
        (*plfapiinfra_hook_auth)( ipchtCallDone, 25, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bffs_Close( int winid, int fd, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bffsClose *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bffsClose );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->fd = fd;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 26, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCall, 26, data );
    }
    component->Call( component, idbffsClose, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 26, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCallDone, 26, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bffs_Delete( int winid, char * filepath, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bffsDelete *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bffsDelete ) + ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filepath = ( filepath == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bffsDelete) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->filepath != NULL )
    {
        strcpy( data->filepath, filepath );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 27, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCall, 27, data );
    }
    component->Call( component, idbffsDelete, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 27, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCallDone, 27, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bffs_GetFileSize( int winid, char * filepath, int * size, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bffsGetFileSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bffsGetFileSize ) + ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filepath = ( filepath == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bffsGetFileSize) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->filepath != NULL )
    {
        strcpy( data->filepath, filepath );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 28, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCall, 28, data );
    }
    component->Call( component, idbffsGetFileSize, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 28, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCallDone, 28, data );
    }

    /*  5. copy "out" parameters */
    if ( size != NULL )
    {
        *size = data->size;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bffs_GetVolumeName( int winid, int volume, char * buf, int size, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bffsGetVolumeName *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bffsGetVolumeName ) + ( sizeof( char ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bffsGetVolumeName) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->volume = volume;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 29, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCall, 29, data );
    }
    component->Call( component, idbffsGetVolumeName, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 29, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCallDone, 29, data );
    }

    /*  5. copy "out" parameters */
    if ( buf != NULL )
    {
        memcpy( buf, data->buf,( sizeof( char ) * size ) );
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bffs_Open( int winid, char * filepath, int fmode, int * fd, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bffsOpen *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bffsOpen ) + ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filepath = ( filepath == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bffsOpen) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->filepath != NULL )
    {
        strcpy( data->filepath, filepath );
    }
    data->fmode = fmode;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 30, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCall, 30, data );
    }
    component->Call( component, idbffsOpen, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 30, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCallDone, 30, data );
    }

    /*  5. copy "out" parameters */
    if ( fd != NULL )
    {
        *fd = data->fd;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bffs_Read( int winid, int fd, char * fbuff, int * nbytes, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bffsRead *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bffsRead ) + ( sizeof( char ) * ( *nbytes ) );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->fbuff = ( fbuff == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bffsRead) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->fd = fd;
    data->nbytes = *nbytes;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 31, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCall, 31, data );
    }
    component->Call( component, idbffsRead, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 31, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCallDone, 31, data );
    }

    /*  5. copy "out" parameters */
    if ( fbuff != NULL )
    {
        memcpy( fbuff, data->fbuff,( sizeof( char ) * ( *nbytes ) ) );
    }
    if ( nbytes != NULL )
    {
        *nbytes = data->nbytes;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bffs_Seek( int winid, int fd, int offset, int smode, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bffsSeek *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bffsSeek );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->fd = fd;
    data->offset = offset;
    data->smode = smode;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 32, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCall, 32, data );
    }
    component->Call( component, idbffsSeek, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 32, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCallDone, 32, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bffs_Write( int winid, int fd, char * fbuff, int * nbytes, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bffsWrite *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bffsWrite ) + ( sizeof( char ) * ( *nbytes ) );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->fbuff = ( fbuff == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bffsWrite) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->fd = fd;
    if ( data->fbuff != NULL )
    {
        memcpy( data->fbuff, fbuff, ( sizeof( char ) * ( *nbytes ) ) );
    }
    data->nbytes = *nbytes;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 33, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCall, 33, data );
    }
    component->Call( component, idbffsWrite, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 33, data );
    }
    if ( plfapiinfra_hook_bffs )
    {
        (*plfapiinfra_hook_bffs)( ipchtCallDone, 33, data );
    }

    /*  5. copy "out" parameters */
    if ( nbytes != NULL )
    {
        *nbytes = data->nbytes;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bootloader_GetEnvironmentVariable( int winid, char * name, char * value, int size, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bootloaderGetEnvironmentVariable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bootloaderGetEnvironmentVariable ) + ( ( name == NULL ? 0 : strlen( name ) ) + 1 ) + ( sizeof( char ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->name = ( name == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bootloaderGetEnvironmentVariable) );
    data->value = ( value == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bootloaderGetEnvironmentVariable) + ( ( name == NULL ? 0 : strlen( name ) ) + 1 ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->name != NULL )
    {
        strcpy( data->name, name );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 34, data );
    }
    if ( plfapiinfra_hook_bootloader )
    {
        (*plfapiinfra_hook_bootloader)( ipchtCall, 34, data );
    }
    component->Call( component, idbootloaderGetEnvironmentVariable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 34, data );
    }
    if ( plfapiinfra_hook_bootloader )
    {
        (*plfapiinfra_hook_bootloader)( ipchtCallDone, 34, data );
    }

    /*  5. copy "out" parameters */
    if ( value != NULL )
    {
        memcpy( value, data->value,( sizeof( char ) * size ) );
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bootloader_ResetBootCounter( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bootloaderResetBootCounter *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bootloaderResetBootCounter );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 35, data );
    }
    if ( plfapiinfra_hook_bootloader )
    {
        (*plfapiinfra_hook_bootloader)( ipchtCall, 35, data );
    }
    component->Call( component, idbootloaderResetBootCounter, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 35, data );
    }
    if ( plfapiinfra_hook_bootloader )
    {
        (*plfapiinfra_hook_bootloader)( ipchtCallDone, 35, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_bootloader_SetEnvironmentVariable( int winid, char * name, char * value, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    bootloaderSetEnvironmentVariable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( bootloaderSetEnvironmentVariable ) + ( ( name == NULL ? 0 : strlen( name ) ) + 1 ) + ( ( value == NULL ? 0 : strlen( value ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->name = ( name == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bootloaderSetEnvironmentVariable) );
    data->value = ( value == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(bootloaderSetEnvironmentVariable) + ( ( name == NULL ? 0 : strlen( name ) ) + 1 ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->name != NULL )
    {
        strcpy( data->name, name );
    }
    if ( data->value != NULL )
    {
        strcpy( data->value, value );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 36, data );
    }
    if ( plfapiinfra_hook_bootloader )
    {
        (*plfapiinfra_hook_bootloader)( ipchtCall, 36, data );
    }
    component->Call( component, idbootloaderSetEnvironmentVariable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 36, data );
    }
    if ( plfapiinfra_hook_bootloader )
    {
        (*plfapiinfra_hook_bootloader)( ipchtCallDone, 36, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecack_MessageProcessed( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecackMessageProcessed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecackMessageProcessed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 37, data );
    }
    if ( plfapiinfra_hook_cecack )
    {
        (*plfapiinfra_hook_cecack)( ipchtCall, 37, data );
    }
    component->Call( component, idcecackMessageProcessed, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 37, data );
    }
    if ( plfapiinfra_hook_cecack )
    {
        (*plfapiinfra_hook_cecack)( ipchtCallDone, 37, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_Cancel( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlCancel *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlCancel );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 38, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 38, data );
    }
    component->Call( component, idcecctrlCancel, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 38, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 38, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_CausedWakeup( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlCausedWakeup *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlCausedWakeup );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 39, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 39, data );
    }
    component->Call( component, idcecctrlCausedWakeup, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 39, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 39, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_Disable( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlDisable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlDisable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 40, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 40, data );
    }
    component->Call( component, idcecctrlDisable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 40, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 40, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_DisableReceive( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlDisableReceive *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlDisableReceive );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 41, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 41, data );
    }
    component->Call( component, idcecctrlDisableReceive, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 41, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 41, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_DisableTransmitStatus( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlDisableTransmitStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlDisableTransmitStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 42, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 42, data );
    }
    component->Call( component, idcecctrlDisableTransmitStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 42, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 42, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_Enable( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlEnable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlEnable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 43, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 43, data );
    }
    component->Call( component, idcecctrlEnable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 43, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 43, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_EnableReceive( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlEnableReceive *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlEnableReceive );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 44, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 44, data );
    }
    component->Call( component, idcecctrlEnableReceive, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 44, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 44, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_EnableTransmitStatus( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlEnableTransmitStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlEnableTransmitStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 45, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 45, data );
    }
    component->Call( component, idcecctrlEnableTransmitStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 45, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 45, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_GetBufferedMsg( int winid, Nat8 * cec_message, Nat8 * msg_length )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlGetBufferedMsg *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlGetBufferedMsg ) + ( sizeof( Nat8 ) * ( *msg_length ) );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->cec_message = ( cec_message == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(cecctrlGetBufferedMsg) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->msg_length = *msg_length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 46, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 46, data );
    }
    component->Call( component, idcecctrlGetBufferedMsg, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 46, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 46, data );
    }

    /*  5. copy "out" parameters */
    if ( cec_message != NULL )
    {
        memcpy( cec_message, data->cec_message,( sizeof( Nat8 ) * ( *msg_length ) ) );
    }
    if ( msg_length != NULL )
    {
        *msg_length = data->msg_length;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_GetDeviceVendorID( int winid, Nat8 * vendor_id, int * length )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlGetDeviceVendorID *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlGetDeviceVendorID ) + ( sizeof( Nat8 ) * ( *length ) );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->vendor_id = ( vendor_id == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(cecctrlGetDeviceVendorID) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->length = *length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 47, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 47, data );
    }
    component->Call( component, idcecctrlGetDeviceVendorID, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 47, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 47, data );
    }

    /*  5. copy "out" parameters */
    if ( vendor_id != NULL )
    {
        memcpy( vendor_id, data->vendor_id,( sizeof( Nat8 ) * ( *length ) ) );
    }
    if ( length != NULL )
    {
        *length = data->length;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_GetLogicalAddress( int winid, CecLogicalAddress * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlGetLogicalAddress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlGetLogicalAddress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 48, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 48, data );
    }
    component->Call( component, idcecctrlGetLogicalAddress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 48, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 48, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_GetOSDName( int winid, char * osd_name, int * length )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlGetOSDName *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlGetOSDName ) + ( sizeof( char ) * ( *length ) );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->osd_name = ( osd_name == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(cecctrlGetOSDName) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->length = *length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 49, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 49, data );
    }
    component->Call( component, idcecctrlGetOSDName, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 49, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 49, data );
    }

    /*  5. copy "out" parameters */
    if ( osd_name != NULL )
    {
        memcpy( osd_name, data->osd_name,( sizeof( char ) * ( *length ) ) );
    }
    if ( length != NULL )
    {
        *length = data->length;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_GetVersion( int winid, CecVersion * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlGetVersion *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlGetVersion );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 50, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 50, data );
    }
    component->Call( component, idcecctrlGetVersion, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 50, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 50, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_Preview( int winid, Nat8 * pMessage, int size )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlPreview *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlPreview ) + ( sizeof( Nat8 ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->pMessage = ( pMessage == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(cecctrlPreview) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 51, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 51, data );
    }
    component->Call( component, idcecctrlPreview, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 51, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 51, data );
    }

    /*  5. copy "out" parameters */
    if ( pMessage != NULL )
    {
        memcpy( pMessage, data->pMessage,( sizeof( Nat8 ) * size ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_SetDeviceVendorID( int winid, Nat8 * vendor_id, int length )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlSetDeviceVendorID *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlSetDeviceVendorID ) + ( sizeof( Nat8 ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->vendor_id = ( vendor_id == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(cecctrlSetDeviceVendorID) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->vendor_id != NULL )
    {
        memcpy( data->vendor_id, vendor_id, ( sizeof( Nat8 ) * length ) );
    }
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 52, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 52, data );
    }
    component->Call( component, idcecctrlSetDeviceVendorID, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 52, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 52, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_SetLogicalAddress( int winid, CecLogicalAddress address )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlSetLogicalAddress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlSetLogicalAddress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 53, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 53, data );
    }
    component->Call( component, idcecctrlSetLogicalAddress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 53, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 53, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_SetOSDName( int winid, char * osd_name, int length )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlSetOSDName *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlSetOSDName ) + ( sizeof( char ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->osd_name = ( osd_name == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(cecctrlSetOSDName) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->osd_name != NULL )
    {
        memcpy( data->osd_name, osd_name, ( sizeof( char ) * length ) );
    }
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 54, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 54, data );
    }
    component->Call( component, idcecctrlSetOSDName, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 54, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 54, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_SetVersion( int winid, CecVersion version )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlSetVersion *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlSetVersion );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->version = version;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 55, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 55, data );
    }
    component->Call( component, idcecctrlSetVersion, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 55, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 55, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cecctrl_SetWakeupMode( int winid, CecOpcode * wkp_code, int size )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cecctrlSetWakeupMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cecctrlSetWakeupMode ) + ( sizeof( CecOpcode ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->wkp_code = ( wkp_code == NULL ) ? NULL : (CecOpcode *)( ((char*)data) + sizeof(cecctrlSetWakeupMode) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->wkp_code != NULL )
    {
        memcpy( data->wkp_code, wkp_code, ( sizeof( CecOpcode ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 56, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCall, 56, data );
    }
    component->Call( component, idcecctrlSetWakeupMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 56, data );
    }
    if ( plfapiinfra_hook_cecctrl )
    {
        (*plfapiinfra_hook_cecctrl)( ipchtCallDone, 56, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_cectx_Transmit( int winid, int size, Nat8 * msg, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cectxTransmit *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cectxTransmit ) + ( sizeof( Nat8 ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->msg = ( msg == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(cectxTransmit) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->size = size;
    if ( data->msg != NULL )
    {
        memcpy( data->msg, msg, ( sizeof( Nat8 ) * size ) );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 57, data );
    }
    if ( plfapiinfra_hook_cectx )
    {
        (*plfapiinfra_hook_cectx)( ipchtCall, 57, data );
    }
    component->Call( component, idcectxTransmit, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 57, data );
    }
    if ( plfapiinfra_hook_cectx )
    {
        (*plfapiinfra_hook_cectx)( ipchtCallDone, 57, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_AlarmIsSet( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkAlarmIsSet *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkAlarmIsSet );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 58, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 58, data );
    }
    component->Call( component, idclkAlarmIsSet, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 58, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 58, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_CancelAlarm( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkCancelAlarm *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkCancelAlarm );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 59, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 59, data );
    }
    component->Call( component, idclkCancelAlarm, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 59, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 59, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_CausedWakeup( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkCausedWakeup *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkCausedWakeup );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 60, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 60, data );
    }
    component->Call( component, idclkCausedWakeup, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 60, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 60, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_ClockIsSet( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkClockIsSet *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkClockIsSet );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 61, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 61, data );
    }
    component->Call( component, idclkClockIsSet, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 61, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 61, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_GetAlarm( int winid, DateTime * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkGetAlarm *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkGetAlarm );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 62, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 62, data );
    }
    component->Call( component, idclkGetAlarm, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 62, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 62, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_GetLocalTime( int winid, DateTime * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkGetLocalTime *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkGetLocalTime );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 63, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 63, data );
    }
    component->Call( component, idclkGetLocalTime, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 63, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 63, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_GetLocalTimeOffset( int winid, DateTime * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkGetLocalTimeOffset *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkGetLocalTimeOffset );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 64, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 64, data );
    }
    component->Call( component, idclkGetLocalTimeOffset, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 64, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 64, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_GetUniversalTime( int winid, DateTime * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkGetUniversalTime *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkGetUniversalTime );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 65, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 65, data );
    }
    component->Call( component, idclkGetUniversalTime, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 65, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 65, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_RunDuringStandby( int winid, Bool enable )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkRunDuringStandby *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkRunDuringStandby );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->enable = enable;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 66, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 66, data );
    }
    component->Call( component, idclkRunDuringStandby, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 66, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 66, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_SecondsSinceWakeup( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkSecondsSinceWakeup *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkSecondsSinceWakeup );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 67, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 67, data );
    }
    component->Call( component, idclkSecondsSinceWakeup, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 67, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 67, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_SetAlarm( int winid, DateTime alarm )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkSetAlarm *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkSetAlarm );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->alarm = alarm;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 68, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 68, data );
    }
    component->Call( component, idclkSetAlarm, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 68, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 68, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_SetClock( int winid, DateTime utc, DateTime lto )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkSetClock *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkSetClock );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->utc = utc;
    data->lto = lto;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 69, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 69, data );
    }
    component->Call( component, idclkSetClock, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 69, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 69, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_clk_SetWakeupMode( int winid, Bool enable )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    clkSetWakeupMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( clkSetWakeupMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->enable = enable;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 70, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCall, 70, data );
    }
    component->Call( component, idclkSetWakeupMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 70, data );
    }
    if ( plfapiinfra_hook_clk )
    {
        (*plfapiinfra_hook_clk)( ipchtCallDone, 70, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_crypt_Crypt( int winid, Nat8 * Key, Nat8 * Buffer, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cryptCrypt *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cryptCrypt );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->Key != NULL )
    {
        memcpy( data->Key, Key, ( sizeof( Nat8 ) * 256 ) );
    }
    if ( data->Buffer != NULL )
    {
        memcpy( data->Buffer, Buffer, ( sizeof( Nat8 ) * 256 ) );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 71, data );
    }
    if ( plfapiinfra_hook_crypt )
    {
        (*plfapiinfra_hook_crypt)( ipchtCall, 71, data );
    }
    component->Call( component, idcryptCrypt, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 71, data );
    }
    if ( plfapiinfra_hook_crypt )
    {
        (*plfapiinfra_hook_crypt)( ipchtCallDone, 71, data );
    }

    /*  5. copy "out" parameters */
    if ( Buffer != NULL )
    {
        memcpy( Buffer, data->Buffer,( sizeof( Nat8 ) * 256 ) );
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbbrwse_GetPacket( char * pub, char * label, Nat8 * bag, int baglength, Nat8 * packet, int packetlength )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbbrwseGetPacket *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbbrwseGetPacket ) + ( ( label == NULL ? 0 : strlen( label ) ) + 1 ) + ( sizeof( Nat8 ) * baglength ) + ( sizeof( Nat8 ) * packetlength );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->label = ( label == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(dbbrwseGetPacket) );
    data->bag = ( bag == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(dbbrwseGetPacket) + ( ( label == NULL ? 0 : strlen( label ) ) + 1 ) );
    data->packet = ( packet == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(dbbrwseGetPacket) + ( ( label == NULL ? 0 : strlen( label ) ) + 1 ) + ( sizeof( Nat8 ) * baglength ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->pub != NULL )
    {
        memcpy( data->pub, pub, ( sizeof( char ) * 32 ) );
    }
    if ( data->label != NULL )
    {
        strcpy( data->label, label );
    }
    if ( data->bag != NULL )
    {
        memcpy( data->bag, bag, ( sizeof( Nat8 ) * baglength ) );
    }
    data->baglength = baglength;
    data->packetlength = packetlength;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 72, data );
    }
    if ( plfapiinfra_hook_dbbrwse )
    {
        (*plfapiinfra_hook_dbbrwse)( ipchtCall, 72, data );
    }
    component->Call( component, iddbbrwseGetPacket, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 72, data );
    }
    if ( plfapiinfra_hook_dbbrwse )
    {
        (*plfapiinfra_hook_dbbrwse)( ipchtCallDone, 72, data );
    }

    /*  5. copy "out" parameters */
    if ( packet != NULL )
    {
        memcpy( packet, data->packet,( sizeof( Nat8 ) * packetlength ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbbrwse_GetPacketLength( char * pub, char * label, Nat8 * bag, int baglength, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbbrwseGetPacketLength *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbbrwseGetPacketLength ) + ( ( label == NULL ? 0 : strlen( label ) ) + 1 ) + ( sizeof( Nat8 ) * baglength );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->label = ( label == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(dbbrwseGetPacketLength) );
    data->bag = ( bag == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(dbbrwseGetPacketLength) + ( ( label == NULL ? 0 : strlen( label ) ) + 1 ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->pub != NULL )
    {
        memcpy( data->pub, pub, ( sizeof( char ) * 32 ) );
    }
    if ( data->label != NULL )
    {
        strcpy( data->label, label );
    }
    if ( data->bag != NULL )
    {
        memcpy( data->bag, bag, ( sizeof( Nat8 ) * baglength ) );
    }
    data->baglength = baglength;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 73, data );
    }
    if ( plfapiinfra_hook_dbbrwse )
    {
        (*plfapiinfra_hook_dbbrwse)( ipchtCall, 73, data );
    }
    component->Call( component, iddbbrwseGetPacketLength, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 73, data );
    }
    if ( plfapiinfra_hook_dbbrwse )
    {
        (*plfapiinfra_hook_dbbrwse)( ipchtCallDone, 73, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbtf_HasLastFileAccessSucceeded( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbtfHasLastFileAccessSucceeded *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbtfHasLastFileAccessSucceeded );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 74, data );
    }
    if ( plfapiinfra_hook_dbtf )
    {
        (*plfapiinfra_hook_dbtf)( ipchtCall, 74, data );
    }
    component->Call( component, iddbtfHasLastFileAccessSucceeded, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 74, data );
    }
    if ( plfapiinfra_hook_dbtf )
    {
        (*plfapiinfra_hook_dbtf)( ipchtCallDone, 74, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbtf_IsFilePresent( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbtfIsFilePresent *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbtfIsFilePresent );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 75, data );
    }
    if ( plfapiinfra_hook_dbtf )
    {
        (*plfapiinfra_hook_dbtf)( ipchtCall, 75, data );
    }
    component->Call( component, iddbtfIsFilePresent, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 75, data );
    }
    if ( plfapiinfra_hook_dbtf )
    {
        (*plfapiinfra_hook_dbtf)( ipchtCallDone, 75, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbtf_SendData( int winid, void * bag, int length, Nat16 * Crc, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbtfSendData *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbtfSendData ) + ( sizeof( void ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->bag = ( bag == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(dbtfSendData) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->bag != NULL )
    {
        memcpy( data->bag, bag, ( sizeof( void ) * length ) );
    }
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 76, data );
    }
    if ( plfapiinfra_hook_dbtf )
    {
        (*plfapiinfra_hook_dbtf)( ipchtCall, 76, data );
    }
    component->Call( component, iddbtfSendData, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 76, data );
    }
    if ( plfapiinfra_hook_dbtf )
    {
        (*plfapiinfra_hook_dbtf)( ipchtCallDone, 76, data );
    }

    /*  5. copy "out" parameters */
    if ( Crc != NULL )
    {
        *Crc = data->Crc;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbtfci_GetId( int winid, Nat8 * id, Nat32 * idlen, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbtfciGetId *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbtfciGetId ) + ( sizeof( Nat8 ) * ( *idlen ) );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->id = ( id == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(dbtfciGetId) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->idlen = *idlen;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 77, data );
    }
    if ( plfapiinfra_hook_dbtfci )
    {
        (*plfapiinfra_hook_dbtfci)( ipchtCall, 77, data );
    }
    component->Call( component, iddbtfciGetId, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 77, data );
    }
    if ( plfapiinfra_hook_dbtfci )
    {
        (*plfapiinfra_hook_dbtfci)( ipchtCallDone, 77, data );
    }

    /*  5. copy "out" parameters */
    if ( id != NULL )
    {
        memcpy( id, data->id,( sizeof( Nat8 ) * ( *idlen ) ) );
    }
    if ( idlen != NULL )
    {
        *idlen = data->idlen;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbtfci_HasLastFileAccessSucceeded( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbtfciHasLastFileAccessSucceeded *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbtfciHasLastFileAccessSucceeded );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 78, data );
    }
    if ( plfapiinfra_hook_dbtfci )
    {
        (*plfapiinfra_hook_dbtfci)( ipchtCall, 78, data );
    }
    component->Call( component, iddbtfciHasLastFileAccessSucceeded, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 78, data );
    }
    if ( plfapiinfra_hook_dbtfci )
    {
        (*plfapiinfra_hook_dbtfci)( ipchtCallDone, 78, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbtfci_IsFilePresent( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbtfciIsFilePresent *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbtfciIsFilePresent );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 79, data );
    }
    if ( plfapiinfra_hook_dbtfci )
    {
        (*plfapiinfra_hook_dbtfci)( ipchtCall, 79, data );
    }
    component->Call( component, iddbtfciIsFilePresent, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 79, data );
    }
    if ( plfapiinfra_hook_dbtfci )
    {
        (*plfapiinfra_hook_dbtfci)( ipchtCallDone, 79, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dbtfci_SendData( int winid, void * bag, int length, Nat16 * Crc, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dbtfciSendData *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dbtfciSendData ) + ( sizeof( void ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->bag = ( bag == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(dbtfciSendData) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->bag != NULL )
    {
        memcpy( data->bag, bag, ( sizeof( void ) * length ) );
    }
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 80, data );
    }
    if ( plfapiinfra_hook_dbtfci )
    {
        (*plfapiinfra_hook_dbtfci)( ipchtCall, 80, data );
    }
    component->Call( component, iddbtfciSendData, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 80, data );
    }
    if ( plfapiinfra_hook_dbtfci )
    {
        (*plfapiinfra_hook_dbtfci)( ipchtCallDone, 80, data );
    }

    /*  5. copy "out" parameters */
    if ( Crc != NULL )
    {
        *Crc = data->Crc;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dmpctr_DisableMagicKeys( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dmpctrDisableMagicKeys *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dmpctrDisableMagicKeys );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 81, data );
    }
    if ( plfapiinfra_hook_dmpctr )
    {
        (*plfapiinfra_hook_dmpctr)( ipchtCall, 81, data );
    }
    component->Call( component, iddmpctrDisableMagicKeys, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 81, data );
    }
    if ( plfapiinfra_hook_dmpctr )
    {
        (*plfapiinfra_hook_dmpctr)( ipchtCallDone, 81, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dmpctr_EnableMagicKeys( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dmpctrEnableMagicKeys *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dmpctrEnableMagicKeys );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 82, data );
    }
    if ( plfapiinfra_hook_dmpctr )
    {
        (*plfapiinfra_hook_dmpctr)( ipchtCall, 82, data );
    }
    component->Call( component, iddmpctrEnableMagicKeys, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 82, data );
    }
    if ( plfapiinfra_hook_dmpctr )
    {
        (*plfapiinfra_hook_dmpctr)( ipchtCallDone, 82, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_dmpctr_MakeDebugDump( int winid, Bool fatal, char * debugdata, int len, Nat32 options )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dmpctrMakeDebugDump *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dmpctrMakeDebugDump ) + ( sizeof( char ) * len );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->debugdata = ( debugdata == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(dmpctrMakeDebugDump) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->fatal = fatal;
    if ( data->debugdata != NULL )
    {
        memcpy( data->debugdata, debugdata, ( sizeof( char ) * len ) );
    }
    data->len = len;
    data->options = options;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 83, data );
    }
    if ( plfapiinfra_hook_dmpctr )
    {
        (*plfapiinfra_hook_dmpctr)( ipchtCall, 83, data );
    }
    component->Call( component, iddmpctrMakeDebugDump, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 83, data );
    }
    if ( plfapiinfra_hook_dmpctr )
    {
        (*plfapiinfra_hook_dmpctr)( ipchtCallDone, 83, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_ClearLog( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrClearLog *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrClearLog );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 84, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 84, data );
    }
    component->Call( component, idevlogctrClearLog, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 84, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 84, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_GetHwLogRecord( int winid, int BackwardRef, PlfApiEventLogEntry * log, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrGetHwLogRecord *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrGetHwLogRecord );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->BackwardRef = BackwardRef;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 85, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 85, data );
    }
    component->Call( component, idevlogctrGetHwLogRecord, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 85, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 85, data );
    }

    /*  5. copy "out" parameters */
    if ( log != NULL )
    {
        *log = data->log;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_GetLastAlign( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrGetLastAlign *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrGetLastAlign );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 86, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 86, data );
    }
    component->Call( component, idevlogctrGetLastAlign, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 86, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 86, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_GetLastLogCleared( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrGetLastLogCleared *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrGetLastLogCleared );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 87, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 87, data );
    }
    component->Call( component, idevlogctrGetLastLogCleared, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 87, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 87, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_GetLoggedEvents( int winid, Nat16 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrGetLoggedEvents *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrGetLoggedEvents );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 88, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 88, data );
    }
    component->Call( component, idevlogctrGetLoggedEvents, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 88, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 88, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_GetLogRecord( int winid, int BackwardRef, PlfApiEventLogEntry * log, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrGetLogRecord *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrGetLogRecord );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->BackwardRef = BackwardRef;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 89, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 89, data );
    }
    component->Call( component, idevlogctrGetLogRecord, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 89, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 89, data );
    }

    /*  5. copy "out" parameters */
    if ( log != NULL )
    {
        *log = data->log;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_GetNumReboots( int winid, Nat16 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrGetNumReboots *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrGetNumReboots );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 90, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 90, data );
    }
    component->Call( component, idevlogctrGetNumReboots, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 90, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 90, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_GetNvmIntegCheck( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrGetNvmIntegCheck *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrGetNvmIntegCheck );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 91, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 91, data );
    }
    component->Call( component, idevlogctrGetNvmIntegCheck, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 91, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 91, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_GetSwVersion( int winid, char * swver )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrGetSwVersion *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrGetSwVersion );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 92, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 92, data );
    }
    component->Call( component, idevlogctrGetSwVersion, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 92, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 92, data );
    }

    /*  5. copy "out" parameters */
    if ( swver != NULL )
    {
        memcpy( swver, data->swver,( sizeof( char ) * 33 ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_HwClearLog( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrHwClearLog *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrHwClearLog );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 93, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 93, data );
    }
    component->Call( component, idevlogctrHwClearLog, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 93, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 93, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_HwGetLastLogCleared( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrHwGetLastLogCleared *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrHwGetLastLogCleared );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 94, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 94, data );
    }
    component->Call( component, idevlogctrHwGetLastLogCleared, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 94, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 94, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_HwGetLoggedEvents( int winid, Nat16 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrHwGetLoggedEvents *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrHwGetLoggedEvents );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 95, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 95, data );
    }
    component->Call( component, idevlogctrHwGetLoggedEvents, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 95, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 95, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_SetLastKey( int winid, KeySource source, Bool Toggle, KeySystem system, KeyCommand command, int TimeStamp )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrSetLastKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrSetLastKey );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->Toggle = Toggle;
    data->system = system;
    data->command = command;
    data->TimeStamp = TimeStamp;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 96, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 96, data );
    }
    component->Call( component, idevlogctrSetLastKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 96, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 96, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_SetLastKeyUp( int winid, KeySystem sys, KeyCommand command )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrSetLastKeyUp *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrSetLastKeyUp );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->sys = sys;
    data->command = command;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 97, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 97, data );
    }
    component->Call( component, idevlogctrSetLastKeyUp, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 97, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 97, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_SetLastSrc( int winid, Nat8 src )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrSetLastSrc *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrSetLastSrc );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->src = src;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 98, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 98, data );
    }
    component->Call( component, idevlogctrSetLastSrc, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 98, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 98, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_SetNvmIntegCheck( int winid, Nat32 value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrSetNvmIntegCheck *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrSetNvmIntegCheck );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->value = value;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 99, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 99, data );
    }
    component->Call( component, idevlogctrSetNvmIntegCheck, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 99, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 99, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_evlogctr_SetSwVersion( int winid, char * swver )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    evlogctrSetSwVersion *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( evlogctrSetSwVersion ) + ( ( swver == NULL ? 0 : strlen( swver ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->swver = ( swver == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(evlogctrSetSwVersion) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->swver != NULL )
    {
        strcpy( data->swver, swver );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 100, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCall, 100, data );
    }
    component->Call( component, idevlogctrSetSwVersion, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 100, data );
    }
    if ( plfapiinfra_hook_evlogctr )
    {
        (*plfapiinfra_hook_evlogctr)( ipchtCallDone, 100, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_fops_IsPartitionMounted( int winid, char * mountpoint, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    fopsIsPartitionMounted *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( fopsIsPartitionMounted ) + ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->mountpoint = ( mountpoint == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(fopsIsPartitionMounted) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->mountpoint != NULL )
    {
        strcpy( data->mountpoint, mountpoint );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 101, data );
    }
    if ( plfapiinfra_hook_fops )
    {
        (*plfapiinfra_hook_fops)( ipchtCall, 101, data );
    }
    component->Call( component, idfopsIsPartitionMounted, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 101, data );
    }
    if ( plfapiinfra_hook_fops )
    {
        (*plfapiinfra_hook_fops)( ipchtCallDone, 101, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_fops_PartitionMount( int winid, char * partitionname, char * mountpoint, char * fstype, Nat32 mountflags, char * options, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    fopsPartitionMount *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( fopsPartitionMount ) + ( ( partitionname == NULL ? 0 : strlen( partitionname ) ) + 1 ) + ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ) + ( ( fstype == NULL ? 0 : strlen( fstype ) ) + 1 ) + ( ( options == NULL ? 0 : strlen( options ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->partitionname = ( partitionname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(fopsPartitionMount) );
    data->mountpoint = ( mountpoint == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(fopsPartitionMount) + ( ( partitionname == NULL ? 0 : strlen( partitionname ) ) + 1 ) );
    data->fstype = ( fstype == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(fopsPartitionMount) + ( ( partitionname == NULL ? 0 : strlen( partitionname ) ) + 1 ) + ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ) );
    data->options = ( options == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(fopsPartitionMount) + ( ( partitionname == NULL ? 0 : strlen( partitionname ) ) + 1 ) + ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ) + ( ( fstype == NULL ? 0 : strlen( fstype ) ) + 1 ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->partitionname != NULL )
    {
        strcpy( data->partitionname, partitionname );
    }
    if ( data->mountpoint != NULL )
    {
        strcpy( data->mountpoint, mountpoint );
    }
    if ( data->fstype != NULL )
    {
        strcpy( data->fstype, fstype );
    }
    data->mountflags = mountflags;
    if ( data->options != NULL )
    {
        strcpy( data->options, options );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 102, data );
    }
    if ( plfapiinfra_hook_fops )
    {
        (*plfapiinfra_hook_fops)( ipchtCall, 102, data );
    }
    component->Call( component, idfopsPartitionMount, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 102, data );
    }
    if ( plfapiinfra_hook_fops )
    {
        (*plfapiinfra_hook_fops)( ipchtCallDone, 102, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_fops_PartitionUnmount( int winid, char * mountpoint, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    fopsPartitionUnmount *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( fopsPartitionUnmount ) + ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->mountpoint = ( mountpoint == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(fopsPartitionUnmount) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->mountpoint != NULL )
    {
        strcpy( data->mountpoint, mountpoint );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 103, data );
    }
    if ( plfapiinfra_hook_fops )
    {
        (*plfapiinfra_hook_fops)( ipchtCall, 103, data );
    }
    component->Call( component, idfopsPartitionUnmount, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 103, data );
    }
    if ( plfapiinfra_hook_fops )
    {
        (*plfapiinfra_hook_fops)( ipchtCallDone, 103, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PinGetAlt( int winid, int pinid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPinGetAlt *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPinGetAlt );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->pinid = pinid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 104, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 104, data );
    }
    component->Call( component, idgioPinGetAlt, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 104, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 104, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PinGetLatch( int winid, int pinid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPinGetLatch *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPinGetLatch );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->pinid = pinid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 105, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 105, data );
    }
    component->Call( component, idgioPinGetLatch, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 105, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 105, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PinGetLine( int winid, int pinid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPinGetLine *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPinGetLine );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->pinid = pinid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 106, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 106, data );
    }
    component->Call( component, idgioPinGetLine, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 106, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 106, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PinGetMode( int winid, int pinid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPinGetMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPinGetMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->pinid = pinid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 107, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 107, data );
    }
    component->Call( component, idgioPinGetMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 107, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 107, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PinSetAlt( int winid, int pinid, int alt )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPinSetAlt *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPinSetAlt );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->pinid = pinid;
    data->alt = alt;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 108, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 108, data );
    }
    component->Call( component, idgioPinSetAlt, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 108, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 108, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PinSetLatch( int winid, int pinid, int value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPinSetLatch *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPinSetLatch );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->pinid = pinid;
    data->value = value;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 109, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 109, data );
    }
    component->Call( component, idgioPinSetLatch, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 109, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 109, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PinSetMode( int winid, int pinid, int mode )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPinSetMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPinSetMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->pinid = pinid;
    data->mode = mode;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 110, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 110, data );
    }
    component->Call( component, idgioPinSetMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 110, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 110, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PortGetLatch( int winid, int port, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPortGetLatch *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPortGetLatch );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->port = port;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 111, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 111, data );
    }
    component->Call( component, idgioPortGetLatch, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 111, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 111, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PortGetLine( int winid, int port, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPortGetLine *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPortGetLine );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->port = port;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 112, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 112, data );
    }
    component->Call( component, idgioPortGetLine, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 112, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 112, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PortSetAlt( int winid, int port, int mask, int alt )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPortSetAlt *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPortSetAlt );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->port = port;
    data->mask = mask;
    data->alt = alt;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 113, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 113, data );
    }
    component->Call( component, idgioPortSetAlt, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 113, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 113, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PortSetLatch( int winid, int port, int mask, int value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPortSetLatch *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPortSetLatch );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->port = port;
    data->mask = mask;
    data->value = value;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 114, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 114, data );
    }
    component->Call( component, idgioPortSetLatch, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 114, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 114, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_gio_PortSetMode( int winid, int port, int mask, int mode )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    gioPortSetMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( gioPortSetMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->port = port;
    data->mask = mask;
    data->mode = mode;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 115, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCall, 115, data );
    }
    component->Call( component, idgioPortSetMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 115, data );
    }
    if ( plfapiinfra_hook_gio )
    {
        (*plfapiinfra_hook_gio)( ipchtCallDone, 115, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_BlockBus( int winid, int bus, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccBlockBus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccBlockBus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 116, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 116, data );
    }
    component->Call( component, idi2ccBlockBus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 116, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 116, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_EnterIdleMode( int winid, int bus, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccEnterIdleMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccEnterIdleMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 117, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 117, data );
    }
    component->Call( component, idi2ccEnterIdleMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 117, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 117, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_GetBlocked( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccGetBlocked *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccGetBlocked );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 118, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 118, data );
    }
    component->Call( component, idi2ccGetBlocked, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 118, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 118, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_GetControlWord( int winid, int bus, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccGetControlWord *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccGetControlWord );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 119, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 119, data );
    }
    component->Call( component, idi2ccGetControlWord, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 119, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 119, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_GetIdle( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccGetIdle *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccGetIdle );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 120, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 120, data );
    }
    component->Call( component, idi2ccGetIdle, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 120, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 120, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_GetMasterEnabled( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccGetMasterEnabled *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccGetMasterEnabled );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 121, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 121, data );
    }
    component->Call( component, idi2ccGetMasterEnabled, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 121, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 121, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_GetSlaveEnabled( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccGetSlaveEnabled *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccGetSlaveEnabled );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 122, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 122, data );
    }
    component->Call( component, idi2ccGetSlaveEnabled, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 122, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 122, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_LeaveIdleMode( int winid, int bus, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccLeaveIdleMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccLeaveIdleMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 123, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 123, data );
    }
    component->Call( component, idi2ccLeaveIdleMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 123, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 123, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_MasterDisable( int winid, int bus, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccMasterDisable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccMasterDisable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 124, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 124, data );
    }
    component->Call( component, idi2ccMasterDisable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 124, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 124, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_MasterEnable( int winid, int bus, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccMasterEnable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccMasterEnable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 125, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 125, data );
    }
    component->Call( component, idi2ccMasterEnable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 125, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 125, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_SetBitRate( int winid, int bus, int bitrate, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccSetBitRate *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccSetBitRate );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;
    data->bitrate = bitrate;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 126, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 126, data );
    }
    component->Call( component, idi2ccSetBitRate, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 126, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 126, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_SetMasterTimeout( int winid, int bus, int timeout, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccSetMasterTimeout *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccSetMasterTimeout );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;
    data->timeout = timeout;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 127, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 127, data );
    }
    component->Call( component, idi2ccSetMasterTimeout, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 127, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 127, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_SlaveDisable( int winid, int bus, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccSlaveDisable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccSlaveDisable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 128, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 128, data );
    }
    component->Call( component, idi2ccSlaveDisable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 128, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 128, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_SlaveEnable( int winid, int address, Nat8 * buf, int size, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccSlaveEnable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccSlaveEnable ) + ( sizeof( Nat8 ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(i2ccSlaveEnable) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( Nat8 ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 129, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 129, data );
    }
    component->Call( component, idi2ccSlaveEnable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 129, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 129, data );
    }

    /*  5. copy "out" parameters */
    if ( buf != NULL )
    {
        memcpy( buf, data->buf,( sizeof( Nat8 ) * size ) );
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cc_UnblockBus( int winid, int bus, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2ccUnblockBus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2ccUnblockBus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->bus = bus;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 130, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCall, 130, data );
    }
    component->Call( component, idi2ccUnblockBus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 130, data );
    }
    if ( plfapiinfra_hook_i2cc )
    {
        (*plfapiinfra_hook_i2cc)( ipchtCallDone, 130, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cm_Read( int winid, int address, Nat8 * msg, int len, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2cmRead *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2cmRead ) + ( sizeof( Nat8 ) * len );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->msg = ( msg == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(i2cmRead) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;
    data->len = len;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 131, data );
    }
    if ( plfapiinfra_hook_i2cm )
    {
        (*plfapiinfra_hook_i2cm)( ipchtCall, 131, data );
    }
    component->Call( component, idi2cmRead, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 131, data );
    }
    if ( plfapiinfra_hook_i2cm )
    {
        (*plfapiinfra_hook_i2cm)( ipchtCallDone, 131, data );
    }

    /*  5. copy "out" parameters */
    if ( msg != NULL )
    {
        memcpy( msg, data->msg,( sizeof( Nat8 ) * len ) );
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cm_Write( int winid, int address, Nat8 * msg, int len, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2cmWrite *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2cmWrite ) + ( sizeof( Nat8 ) * len );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->msg = ( msg == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(i2cmWrite) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;
    if ( data->msg != NULL )
    {
        memcpy( data->msg, msg, ( sizeof( Nat8 ) * len ) );
    }
    data->len = len;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 132, data );
    }
    if ( plfapiinfra_hook_i2cm )
    {
        (*plfapiinfra_hook_i2cm)( ipchtCall, 132, data );
    }
    component->Call( component, idi2cmWrite, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 132, data );
    }
    if ( plfapiinfra_hook_i2cm )
    {
        (*plfapiinfra_hook_i2cm)( ipchtCallDone, 132, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_i2cm_WriteRead( int winid, int address, Nat8 * msgw, int lenw, Nat8 * msgr, int lenr, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    i2cmWriteRead *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( i2cmWriteRead ) + ( sizeof( Nat8 ) * lenw ) + ( sizeof( Nat8 ) * lenr );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->msgw = ( msgw == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(i2cmWriteRead) );
    data->msgr = ( msgr == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(i2cmWriteRead) + ( sizeof( Nat8 ) * lenw ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;
    if ( data->msgw != NULL )
    {
        memcpy( data->msgw, msgw, ( sizeof( Nat8 ) * lenw ) );
    }
    data->lenw = lenw;
    data->lenr = lenr;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 133, data );
    }
    if ( plfapiinfra_hook_i2cm )
    {
        (*plfapiinfra_hook_i2cm)( ipchtCall, 133, data );
    }
    component->Call( component, idi2cmWriteRead, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 133, data );
    }
    if ( plfapiinfra_hook_i2cm )
    {
        (*plfapiinfra_hook_i2cm)( ipchtCallDone, 133, data );
    }

    /*  5. copy "out" parameters */
    if ( msgr != NULL )
    {
        memcpy( msgr, data->msgr,( sizeof( Nat8 ) * lenr ) );
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_infraitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    infraitfGetAvailableInterfaces *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( infraitfGetAvailableInterfaces );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 134, data );
    }
    if ( plfapiinfra_hook_infraitf )
    {
        (*plfapiinfra_hook_infraitf)( ipchtCall, 134, data );
    }
    component->Call( component, idinfraitfGetAvailableInterfaces, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 134, data );
    }
    if ( plfapiinfra_hook_infraitf )
    {
        (*plfapiinfra_hook_infraitf)( ipchtCallDone, 134, data );
    }

    /*  5. copy "out" parameters */
    if ( nbrgroups != NULL )
    {
        *nbrgroups = data->nbrgroups;
    }
    if ( ids != NULL )
    {
        memcpy( ids, data->ids,( sizeof( Nat32 ) * 5 ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_isha_Finish( Nat32 context, Nat8 * digest )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ishaFinish *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ishaFinish );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->context = context;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 135, data );
    }
    if ( plfapiinfra_hook_isha )
    {
        (*plfapiinfra_hook_isha)( ipchtCall, 135, data );
    }
    component->Call( component, idishaFinish, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 135, data );
    }
    if ( plfapiinfra_hook_isha )
    {
        (*plfapiinfra_hook_isha)( ipchtCallDone, 135, data );
    }

    /*  5. copy "out" parameters */
    if ( digest != NULL )
    {
        memcpy( digest, data->digest,( sizeof( Nat8 ) * 20 ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_isha_Init( Nat32 * context )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ishaInit *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ishaInit );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 136, data );
    }
    if ( plfapiinfra_hook_isha )
    {
        (*plfapiinfra_hook_isha)( ipchtCall, 136, data );
    }
    component->Call( component, idishaInit, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 136, data );
    }
    if ( plfapiinfra_hook_isha )
    {
        (*plfapiinfra_hook_isha)( ipchtCallDone, 136, data );
    }

    /*  5. copy "out" parameters */
    if ( context != NULL )
    {
        *context = data->context;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_isha_Update( Nat32 context, Nat8 * buffer, Nat32 len )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ishaUpdate *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ishaUpdate ) + ( sizeof( Nat8 ) * len );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buffer = ( buffer == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(ishaUpdate) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->context = context;
    if ( data->buffer != NULL )
    {
        memcpy( data->buffer, buffer, ( sizeof( Nat8 ) * len ) );
    }
    data->len = len;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 137, data );
    }
    if ( plfapiinfra_hook_isha )
    {
        (*plfapiinfra_hook_isha)( ipchtCall, 137, data );
    }
    component->Call( component, idishaUpdate, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 137, data );
    }
    if ( plfapiinfra_hook_isha )
    {
        (*plfapiinfra_hook_isha)( ipchtCallDone, 137, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_keyi_Down( int winid, KeySource source, KeySystem system, KeyCommand command, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    keyiDown *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( keyiDown );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->system = system;
    data->command = command;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 138, data );
    }
    if ( plfapiinfra_hook_keyi )
    {
        (*plfapiinfra_hook_keyi)( ipchtCall, 138, data );
    }
    component->Call( component, idkeyiDown, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 138, data );
    }
    if ( plfapiinfra_hook_keyi )
    {
        (*plfapiinfra_hook_keyi)( ipchtCallDone, 138, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_keyi_Up( int winid, KeySource source, KeySystem system, KeyCommand command, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    keyiUp *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( keyiUp );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->system = system;
    data->command = command;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 139, data );
    }
    if ( plfapiinfra_hook_keyi )
    {
        (*plfapiinfra_hook_keyi)( ipchtCall, 139, data );
    }
    component->Call( component, idkeyiUp, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 139, data );
    }
    if ( plfapiinfra_hook_keyi )
    {
        (*plfapiinfra_hook_keyi)( ipchtCallDone, 139, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_DisablePlfLedControl( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledDisablePlfLedControl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledDisablePlfLedControl );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 140, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 140, data );
    }
    component->Call( component, idledDisablePlfLedControl, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 140, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 140, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_EnablePlfLedControl( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledEnablePlfLedControl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledEnablePlfLedControl );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 141, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 141, data );
    }
    component->Call( component, idledEnablePlfLedControl, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 141, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 141, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_GetIntensity( int winid, int led, Nat8 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledGetIntensity *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledGetIntensity );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->led = led;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 142, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 142, data );
    }
    component->Call( component, idledGetIntensity, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 142, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 142, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_IntensitySupported( int winid, int led, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledIntensitySupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledIntensitySupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->led = led;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 143, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 143, data );
    }
    component->Call( component, idledIntensitySupported, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 143, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 143, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_IsPlfLedControlEnabled( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledIsPlfLedControlEnabled *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledIsPlfLedControlEnabled );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 144, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 144, data );
    }
    component->Call( component, idledIsPlfLedControlEnabled, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 144, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 144, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_SetBlinking( int winid, int led, int msecson, int msecsoff )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledSetBlinking *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledSetBlinking );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->led = led;
    data->msecson = msecson;
    data->msecsoff = msecsoff;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 145, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 145, data );
    }
    component->Call( component, idledSetBlinking, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 145, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 145, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_SetFlash( int winid, int led, int msecs )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledSetFlash *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledSetFlash );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->led = led;
    data->msecs = msecs;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 146, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 146, data );
    }
    component->Call( component, idledSetFlash, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 146, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 146, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_SetIntensity( int windid, int led, Nat8 intensity )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledSetIntensity *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledSetIntensity );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->windid = windid;
    data->led = led;
    data->intensity = intensity;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 147, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 147, data );
    }
    component->Call( component, idledSetIntensity, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 147, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 147, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_SetLightGuide( int winid, int led, Bool turnon )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledSetLightGuide *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledSetLightGuide );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->led = led;
    data->turnon = turnon;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 148, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 148, data );
    }
    component->Call( component, idledSetLightGuide, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 148, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 148, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_led_SetPermanent( int winid, int led, Bool offon )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ledSetPermanent *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ledSetPermanent );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->led = led;
    data->offon = offon;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 149, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCall, 149, data );
    }
    component->Call( component, idledSetPermanent, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 149, data );
    }
    if ( plfapiinfra_hook_led )
    {
        (*plfapiinfra_hook_led)( ipchtCallDone, 149, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_ncd_Mem( int winid, Nat32 key, Nat32 size, Address * address, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    ncdMem *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( ncdMem );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->key = key;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 150, data );
    }
    if ( plfapiinfra_hook_ncd )
    {
        (*plfapiinfra_hook_ncd)( ipchtCall, 150, data );
    }
    component->Call( component, idncdMem, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 150, data );
    }
    if ( plfapiinfra_hook_ncd )
    {
        (*plfapiinfra_hook_ncd)( ipchtCallDone, 150, data );
    }

    /*  5. copy "out" parameters */
    if ( address != NULL )
    {
        *address = data->address;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_CheckDnsStatus( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netCheckDnsStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netCheckDnsStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 151, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 151, data );
    }
    component->Call( component, idnetCheckDnsStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 151, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 151, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_ConfigInterfaceAutomatic( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netConfigInterfaceAutomatic *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netConfigInterfaceAutomatic );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 152, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 152, data );
    }
    component->Call( component, idnetConfigInterfaceAutomatic, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 152, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 152, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_ConfigInterfaceStatic( int winid, Nat32 ipaddress, Nat32 ipmask, Nat32 gateway, Nat32 dns1, Nat32 dns2, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netConfigInterfaceStatic *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netConfigInterfaceStatic );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->ipaddress = ipaddress;
    data->ipmask = ipmask;
    data->gateway = gateway;
    data->dns1 = dns1;
    data->dns2 = dns2;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 153, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 153, data );
    }
    component->Call( component, idnetConfigInterfaceStatic, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 153, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 153, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_EnableNetworkInterface( int winid, int intfhandle, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netEnableNetworkInterface *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netEnableNetworkInterface );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 154, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 154, data );
    }
    component->Call( component, idnetEnableNetworkInterface, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 154, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 154, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetEnabledNetworkInterface( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetEnabledNetworkInterface *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetEnabledNetworkInterface );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 155, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 155, data );
    }
    component->Call( component, idnetGetEnabledNetworkInterface, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 155, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 155, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetEnabledNetworkInterfaceStatus( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetEnabledNetworkInterfaceStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetEnabledNetworkInterfaceStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 156, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 156, data );
    }
    component->Call( component, idnetGetEnabledNetworkInterfaceStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 156, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 156, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetInterfaceConfig( int winid, Nat32 * ipaddress, Nat32 * ipmask, Nat32 * gateway, Nat32 * dns1, Nat32 * dns2 )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetInterfaceConfig *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetInterfaceConfig );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 157, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 157, data );
    }
    component->Call( component, idnetGetInterfaceConfig, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 157, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 157, data );
    }

    /*  5. copy "out" parameters */
    if ( ipaddress != NULL )
    {
        *ipaddress = data->ipaddress;
    }
    if ( ipmask != NULL )
    {
        *ipmask = data->ipmask;
    }
    if ( gateway != NULL )
    {
        *gateway = data->gateway;
    }
    if ( dns1 != NULL )
    {
        *dns1 = data->dns1;
    }
    if ( dns2 != NULL )
    {
        *dns2 = data->dns2;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_getMaxNoOfAutomaticWirelessDevicesSupported( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netgetMaxNoOfAutomaticWirelessDevicesSupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netgetMaxNoOfAutomaticWirelessDevicesSupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 158, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 158, data );
    }
    component->Call( component, idnetgetMaxNoOfAutomaticWirelessDevicesSupported, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 158, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 158, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_getMaxNoOfManualWirelessDevicesSupported( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netgetMaxNoOfManualWirelessDevicesSupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netgetMaxNoOfManualWirelessDevicesSupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 159, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 159, data );
    }
    component->Call( component, idnetgetMaxNoOfManualWirelessDevicesSupported, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 159, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 159, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_getMaxNoOfNetworkinterfacesSupported( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netgetMaxNoOfNetworkinterfacesSupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netgetMaxNoOfNetworkinterfacesSupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 160, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 160, data );
    }
    component->Call( component, idnetgetMaxNoOfNetworkinterfacesSupported, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 160, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 160, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNetworkConfigMode( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNetworkConfigMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNetworkConfigMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 161, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 161, data );
    }
    component->Call( component, idnetGetNetworkConfigMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 161, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 161, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNetworkInterfaceConfigStatus( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNetworkInterfaceConfigStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNetworkInterfaceConfigStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 162, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 162, data );
    }
    component->Call( component, idnetGetNetworkInterfaceConfigStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 162, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 162, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNetworkInterfaceMacAddress( int winid, int intfhandle, int length, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNetworkInterfaceMacAddress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNetworkInterfaceMacAddress ) + ( sizeof( char ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->retval = ( retval == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(netGetNetworkInterfaceMacAddress) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 163, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 163, data );
    }
    component->Call( component, idnetGetNetworkInterfaceMacAddress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 163, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 163, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        memcpy( retval, data->retval,( sizeof( char ) * length ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNetworkInterfaceName( int winid, int intfhandle, int length, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNetworkInterfaceName *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNetworkInterfaceName ) + ( sizeof( char ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->retval = ( retval == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(netGetNetworkInterfaceName) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 164, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 164, data );
    }
    component->Call( component, idnetGetNetworkInterfaceName, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 164, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 164, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        memcpy( retval, data->retval,( sizeof( char ) * length ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNetworkInterfacePhysicalStatus( int winid, int intfhandle, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNetworkInterfacePhysicalStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNetworkInterfacePhysicalStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 165, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 165, data );
    }
    component->Call( component, idnetGetNetworkInterfacePhysicalStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 165, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 165, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNetworkInterfaceThroughput( int winid, int intfhandle, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNetworkInterfaceThroughput *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNetworkInterfaceThroughput );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 166, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 166, data );
    }
    component->Call( component, idnetGetNetworkInterfaceThroughput, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 166, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 166, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNetworkInterfaceType( int winid, int intfhandle, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNetworkInterfaceType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNetworkInterfaceType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 167, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 167, data );
    }
    component->Call( component, idnetGetNetworkInterfaceType, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 167, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 167, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNetworkInterfaceVersion( int winid, int intfhandle, int length, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNetworkInterfaceVersion *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNetworkInterfaceVersion ) + ( sizeof( char ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->retval = ( retval == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(netGetNetworkInterfaceVersion) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 168, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 168, data );
    }
    component->Call( component, idnetGetNetworkInterfaceVersion, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 168, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 168, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        memcpy( retval, data->retval,( sizeof( char ) * length ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNumberOfNetworkInterfaces( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNumberOfNetworkInterfaces *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNumberOfNetworkInterfaces );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 169, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 169, data );
    }
    component->Call( component, idnetGetNumberOfNetworkInterfaces, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 169, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 169, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetNumberOfWifiDevices( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetNumberOfWifiDevices *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetNumberOfWifiDevices );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 170, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 170, data );
    }
    component->Call( component, idnetGetNumberOfWifiDevices, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 170, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 170, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetSelectedWiFiDevice( int winid, int * selconfigmode, int * wifidev, char * ssid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetSelectedWiFiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetSelectedWiFiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 171, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 171, data );
    }
    component->Call( component, idnetGetSelectedWiFiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 171, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 171, data );
    }

    /*  5. copy "out" parameters */
    if ( selconfigmode != NULL )
    {
        *selconfigmode = data->selconfigmode;
    }
    if ( wifidev != NULL )
    {
        *wifidev = data->wifidev;
    }
    if ( ssid != NULL )
    {
        strcpy( ssid, data->ssid );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_GetStoredStaticInterfaceConfig( int winid, Nat32 * ipaddress, Nat32 * ipmask, Nat32 * gateway, Nat32 * dns1, Nat32 * dns2 )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netGetStoredStaticInterfaceConfig *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netGetStoredStaticInterfaceConfig );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 172, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 172, data );
    }
    component->Call( component, idnetGetStoredStaticInterfaceConfig, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 172, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 172, data );
    }

    /*  5. copy "out" parameters */
    if ( ipaddress != NULL )
    {
        *ipaddress = data->ipaddress;
    }
    if ( ipmask != NULL )
    {
        *ipmask = data->ipmask;
    }
    if ( gateway != NULL )
    {
        *gateway = data->gateway;
    }
    if ( dns1 != NULL )
    {
        *dns1 = data->dns1;
    }
    if ( dns2 != NULL )
    {
        *dns2 = data->dns2;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_IsInitializationDone( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netIsInitializationDone *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netIsInitializationDone );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 173, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 173, data );
    }
    component->Call( component, idnetIsInitializationDone, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 173, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 173, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_IsNetworkModeVirgin( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netIsNetworkModeVirgin *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netIsNetworkModeVirgin );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 174, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 174, data );
    }
    component->Call( component, idnetIsNetworkModeVirgin, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 174, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 174, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_SelectWiFiDevice( int winid, int selconfigmode, int wifidev, char * ssid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netSelectWiFiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netSelectWiFiDevice ) + ( ( ssid == NULL ? 0 : strlen( ssid ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->ssid = ( ssid == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(netSelectWiFiDevice) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->selconfigmode = selconfigmode;
    data->wifidev = wifidev;
    if ( data->ssid != NULL )
    {
        strcpy( data->ssid, ssid );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 175, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 175, data );
    }
    component->Call( component, idnetSelectWiFiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 175, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 175, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_SetNetworkToModeVirgin( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netSetNetworkToModeVirgin *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netSetNetworkToModeVirgin );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 176, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 176, data );
    }
    component->Call( component, idnetSetNetworkToModeVirgin, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 176, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 176, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetChannel( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetChannel *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetChannel );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 177, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 177, data );
    }
    component->Call( component, idnetWifiGetChannel, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 177, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 177, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetChannelWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetChannelWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetChannelWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 178, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 178, data );
    }
    component->Call( component, idnetWifiGetChannelWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 178, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 178, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetEffectiveSignalStrength( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetEffectiveSignalStrength *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetEffectiveSignalStrength );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 179, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 179, data );
    }
    component->Call( component, idnetWifiGetEffectiveSignalStrength, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 179, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 179, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetEffectiveThroughput( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetEffectiveThroughput *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetEffectiveThroughput );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 180, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 180, data );
    }
    component->Call( component, idnetWifiGetEffectiveThroughput, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 180, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 180, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetEncryptionMode( int winid, int * mode, int * auth )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetEncryptionMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetEncryptionMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 181, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 181, data );
    }
    component->Call( component, idnetWifiGetEncryptionMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 181, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 181, data );
    }

    /*  5. copy "out" parameters */
    if ( mode != NULL )
    {
        *mode = data->mode;
    }
    if ( auth != NULL )
    {
        *auth = data->auth;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetEncryptionModeWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetEncryptionModeWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetEncryptionModeWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 182, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 182, data );
    }
    component->Call( component, idnetWifiGetEncryptionModeWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 182, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 182, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetKey( int winid, Nat8 * key, int * len )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetKey ) + ( sizeof( Nat8 ) * ( *len ) );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->key = ( key == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(netWifiGetKey) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->len = *len;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 183, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 183, data );
    }
    component->Call( component, idnetWifiGetKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 183, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 183, data );
    }

    /*  5. copy "out" parameters */
    if ( key != NULL )
    {
        memcpy( key, data->key,( sizeof( Nat8 ) * ( *len ) ) );
    }
    if ( len != NULL )
    {
        *len = data->len;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetPortType( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetPortType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetPortType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 184, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 184, data );
    }
    component->Call( component, idnetWifiGetPortType, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 184, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 184, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetPortTypeWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetPortTypeWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetPortTypeWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 185, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 185, data );
    }
    component->Call( component, idnetWifiGetPortTypeWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 185, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 185, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetSignalStrengthWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetSignalStrengthWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetSignalStrengthWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 186, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 186, data );
    }
    component->Call( component, idnetWifiGetSignalStrengthWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 186, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 186, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetSsidWifiDevice( int winid, int wifidev, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetSsidWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetSsidWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 187, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 187, data );
    }
    component->Call( component, idnetWifiGetSsidWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 187, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 187, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        strcpy( retval, data->retval );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiGetThroughputWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiGetThroughputWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiGetThroughputWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 188, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 188, data );
    }
    component->Call( component, idnetWifiGetThroughputWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 188, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 188, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiSetChannel( int winid, int channel, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiSetChannel *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiSetChannel );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->channel = channel;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 189, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 189, data );
    }
    component->Call( component, idnetWifiSetChannel, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 189, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 189, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiSetEncryptionMode( int winid, int mode, int auth, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiSetEncryptionMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiSetEncryptionMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->mode = mode;
    data->auth = auth;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 190, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 190, data );
    }
    component->Call( component, idnetWifiSetEncryptionMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 190, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 190, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiSetKey( int winid, Nat8 * key, int len, FResult retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiSetKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiSetKey ) + ( sizeof( Nat8 ) * len );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->key = ( key == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(netWifiSetKey) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( Nat8 ) * len ) );
    }
    data->len = len;
    data->retval = retval;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 191, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 191, data );
    }
    component->Call( component, idnetWifiSetKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 191, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 191, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net_WifiSetPortType( int winid, int porttype, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netWifiSetPortType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netWifiSetPortType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->porttype = porttype;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 192, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCall, 192, data );
    }
    component->Call( component, idnetWifiSetPortType, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 192, data );
    }
    if ( plfapiinfra_hook_net )
    {
        (*plfapiinfra_hook_net)( ipchtCallDone, 192, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_CheckDnsStatus( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2CheckDnsStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2CheckDnsStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 193, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 193, data );
    }
    component->Call( component, idnet2CheckDnsStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 193, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 193, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_ConfigInterfaceAutomatic( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2ConfigInterfaceAutomatic *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2ConfigInterfaceAutomatic );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 194, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 194, data );
    }
    component->Call( component, idnet2ConfigInterfaceAutomatic, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 194, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 194, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_ConfigInterfaceStatic( int winid, Nat32 ipaddress, Nat32 ipmask, Nat32 gateway, Nat32 dns1, Nat32 dns2, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2ConfigInterfaceStatic *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2ConfigInterfaceStatic );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->ipaddress = ipaddress;
    data->ipmask = ipmask;
    data->gateway = gateway;
    data->dns1 = dns1;
    data->dns2 = dns2;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 195, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 195, data );
    }
    component->Call( component, idnet2ConfigInterfaceStatic, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 195, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 195, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_EnableNetworkInterface( int winid, int intfhandle, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2EnableNetworkInterface *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2EnableNetworkInterface );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 196, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 196, data );
    }
    component->Call( component, idnet2EnableNetworkInterface, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 196, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 196, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetEnabledNetworkInterface( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetEnabledNetworkInterface *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetEnabledNetworkInterface );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 197, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 197, data );
    }
    component->Call( component, idnet2GetEnabledNetworkInterface, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 197, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 197, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetInterfaceConfig( int winid, Nat32 * ipaddress, Nat32 * ipmask, Nat32 * gateway, Nat32 * dns1, Nat32 * dns2 )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetInterfaceConfig *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetInterfaceConfig );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 198, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 198, data );
    }
    component->Call( component, idnet2GetInterfaceConfig, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 198, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 198, data );
    }

    /*  5. copy "out" parameters */
    if ( ipaddress != NULL )
    {
        *ipaddress = data->ipaddress;
    }
    if ( ipmask != NULL )
    {
        *ipmask = data->ipmask;
    }
    if ( gateway != NULL )
    {
        *gateway = data->gateway;
    }
    if ( dns1 != NULL )
    {
        *dns1 = data->dns1;
    }
    if ( dns2 != NULL )
    {
        *dns2 = data->dns2;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_getMaxNoOfAutomaticWirelessDevicesSupported( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2getMaxNoOfAutomaticWirelessDevicesSupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2getMaxNoOfAutomaticWirelessDevicesSupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 199, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 199, data );
    }
    component->Call( component, idnet2getMaxNoOfAutomaticWirelessDevicesSupported, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 199, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 199, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_getMaxNoOfManualWirelessDevicesSupported( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2getMaxNoOfManualWirelessDevicesSupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2getMaxNoOfManualWirelessDevicesSupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 200, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 200, data );
    }
    component->Call( component, idnet2getMaxNoOfManualWirelessDevicesSupported, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 200, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 200, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_getMaxNoOfNetworkinterfacesSupported( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2getMaxNoOfNetworkinterfacesSupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2getMaxNoOfNetworkinterfacesSupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 201, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 201, data );
    }
    component->Call( component, idnet2getMaxNoOfNetworkinterfacesSupported, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 201, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 201, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNetworkConfigMode( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNetworkConfigMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNetworkConfigMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 202, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 202, data );
    }
    component->Call( component, idnet2GetNetworkConfigMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 202, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 202, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNetworkInterfaceConfigStatus( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNetworkInterfaceConfigStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNetworkInterfaceConfigStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 203, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 203, data );
    }
    component->Call( component, idnet2GetNetworkInterfaceConfigStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 203, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 203, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNetworkInterfaceMacAddress( int winid, int intfhandle, int length, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNetworkInterfaceMacAddress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNetworkInterfaceMacAddress ) + ( sizeof( char ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->retval = ( retval == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(net2GetNetworkInterfaceMacAddress) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 204, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 204, data );
    }
    component->Call( component, idnet2GetNetworkInterfaceMacAddress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 204, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 204, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        memcpy( retval, data->retval,( sizeof( char ) * length ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNetworkInterfaceName( int winid, int intfhandle, int length, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNetworkInterfaceName *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNetworkInterfaceName ) + ( sizeof( char ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->retval = ( retval == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(net2GetNetworkInterfaceName) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 205, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 205, data );
    }
    component->Call( component, idnet2GetNetworkInterfaceName, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 205, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 205, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        memcpy( retval, data->retval,( sizeof( char ) * length ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNetworkInterfacePhysicalStatus( int winid, int intfhandle, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNetworkInterfacePhysicalStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNetworkInterfacePhysicalStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 206, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 206, data );
    }
    component->Call( component, idnet2GetNetworkInterfacePhysicalStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 206, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 206, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNetworkInterfaceThroughput( int winid, int intfhandle, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNetworkInterfaceThroughput *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNetworkInterfaceThroughput );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 207, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 207, data );
    }
    component->Call( component, idnet2GetNetworkInterfaceThroughput, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 207, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 207, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNetworkInterfaceType( int winid, int intfhandle, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNetworkInterfaceType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNetworkInterfaceType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 208, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 208, data );
    }
    component->Call( component, idnet2GetNetworkInterfaceType, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 208, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 208, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNetworkInterfaceVersion( int winid, int intfhandle, int length, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNetworkInterfaceVersion *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNetworkInterfaceVersion ) + ( sizeof( char ) * length );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->retval = ( retval == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(net2GetNetworkInterfaceVersion) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->intfhandle = intfhandle;
    data->length = length;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 209, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 209, data );
    }
    component->Call( component, idnet2GetNetworkInterfaceVersion, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 209, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 209, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        memcpy( retval, data->retval,( sizeof( char ) * length ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNumberOfNetworkInterfaces( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNumberOfNetworkInterfaces *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNumberOfNetworkInterfaces );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 210, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 210, data );
    }
    component->Call( component, idnet2GetNumberOfNetworkInterfaces, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 210, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 210, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetNumberOfWifiDevices( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetNumberOfWifiDevices *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetNumberOfWifiDevices );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 211, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 211, data );
    }
    component->Call( component, idnet2GetNumberOfWifiDevices, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 211, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 211, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_GetStoredStaticInterfaceConfig( int winid, Nat32 * ipaddress, Nat32 * ipmask, Nat32 * gateway, Nat32 * dns1, Nat32 * dns2 )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2GetStoredStaticInterfaceConfig *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2GetStoredStaticInterfaceConfig );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 212, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 212, data );
    }
    component->Call( component, idnet2GetStoredStaticInterfaceConfig, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 212, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 212, data );
    }

    /*  5. copy "out" parameters */
    if ( ipaddress != NULL )
    {
        *ipaddress = data->ipaddress;
    }
    if ( ipmask != NULL )
    {
        *ipmask = data->ipmask;
    }
    if ( gateway != NULL )
    {
        *gateway = data->gateway;
    }
    if ( dns1 != NULL )
    {
        *dns1 = data->dns1;
    }
    if ( dns2 != NULL )
    {
        *dns2 = data->dns2;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_IsInitializationDone( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2IsInitializationDone *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2IsInitializationDone );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 213, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 213, data );
    }
    component->Call( component, idnet2IsInitializationDone, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 213, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 213, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_IsNetworkModeVirgin( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2IsNetworkModeVirgin *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2IsNetworkModeVirgin );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 214, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 214, data );
    }
    component->Call( component, idnet2IsNetworkModeVirgin, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 214, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 214, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_SelectWifiAntennas( int winid, int selection, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2SelectWifiAntennas *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2SelectWifiAntennas );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->selection = selection;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 215, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 215, data );
    }
    component->Call( component, idnet2SelectWifiAntennas, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 215, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 215, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_SetNetworkToModeVirgin( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2SetNetworkToModeVirgin *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2SetNetworkToModeVirgin );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 216, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 216, data );
    }
    component->Call( component, idnet2SetNetworkToModeVirgin, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 216, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 216, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiFindManualSsid( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiFindManualSsid *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiFindManualSsid );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 217, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 217, data );
    }
    component->Call( component, idnet2WifiFindManualSsid, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 217, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 217, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGenerateWpsPin( int winid, char * pin, int pinsize )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGenerateWpsPin *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGenerateWpsPin ) + ( sizeof( char ) * pinsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->pin = ( pin == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(net2WifiGenerateWpsPin) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->pinsize = pinsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 218, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 218, data );
    }
    component->Call( component, idnet2WifiGenerateWpsPin, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 218, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 218, data );
    }

    /*  5. copy "out" parameters */
    if ( pin != NULL )
    {
        memcpy( pin, data->pin,( sizeof( char ) * pinsize ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetChannel( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetChannel *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetChannel );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 219, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 219, data );
    }
    component->Call( component, idnet2WifiGetChannel, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 219, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 219, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetChannelWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetChannelWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetChannelWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 220, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 220, data );
    }
    component->Call( component, idnet2WifiGetChannelWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 220, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 220, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetEffectiveSignalStrength( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetEffectiveSignalStrength *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetEffectiveSignalStrength );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->retval = *retval;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 221, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 221, data );
    }
    component->Call( component, idnet2WifiGetEffectiveSignalStrength, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 221, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 221, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetEffectiveThroughput( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetEffectiveThroughput *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetEffectiveThroughput );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 222, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 222, data );
    }
    component->Call( component, idnet2WifiGetEffectiveThroughput, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 222, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 222, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetEncryptionMode( int winid, int * mode, int * auth )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetEncryptionMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetEncryptionMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 223, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 223, data );
    }
    component->Call( component, idnet2WifiGetEncryptionMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 223, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 223, data );
    }

    /*  5. copy "out" parameters */
    if ( mode != NULL )
    {
        *mode = data->mode;
    }
    if ( auth != NULL )
    {
        *auth = data->auth;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetEncryptionModeWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetEncryptionModeWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetEncryptionModeWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 224, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 224, data );
    }
    component->Call( component, idnet2WifiGetEncryptionModeWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 224, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 224, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetKey( int winid, char * key, int * len )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetKey ) + ( sizeof( char ) * ( *len ) );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->key = ( key == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(net2WifiGetKey) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->len = *len;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 225, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 225, data );
    }
    component->Call( component, idnet2WifiGetKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 225, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 225, data );
    }

    /*  5. copy "out" parameters */
    if ( key != NULL )
    {
        memcpy( key, data->key,( sizeof( char ) * ( *len ) ) );
    }
    if ( len != NULL )
    {
        *len = data->len;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetMacAddress( int winid, char * macaddr )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetMacAddress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetMacAddress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 226, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 226, data );
    }
    component->Call( component, idnet2WifiGetMacAddress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 226, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 226, data );
    }

    /*  5. copy "out" parameters */
    if ( macaddr != NULL )
    {
        strcpy( macaddr, data->macaddr );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetMacAddressWifiDevice( int winid, int wifidev, char * macaddr )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetMacAddressWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetMacAddressWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 227, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 227, data );
    }
    component->Call( component, idnet2WifiGetMacAddressWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 227, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 227, data );
    }

    /*  5. copy "out" parameters */
    if ( macaddr != NULL )
    {
        strcpy( macaddr, data->macaddr );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetPortType( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetPortType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetPortType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 228, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 228, data );
    }
    component->Call( component, idnet2WifiGetPortType, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 228, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 228, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetPortTypeWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetPortTypeWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetPortTypeWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 229, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 229, data );
    }
    component->Call( component, idnet2WifiGetPortTypeWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 229, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 229, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetSignalStrengthWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetSignalStrengthWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetSignalStrengthWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 230, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 230, data );
    }
    component->Call( component, idnet2WifiGetSignalStrengthWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 230, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 230, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetSsid( int winid, char * ssid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetSsid *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetSsid );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 231, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 231, data );
    }
    component->Call( component, idnet2WifiGetSsid, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 231, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 231, data );
    }

    /*  5. copy "out" parameters */
    if ( ssid != NULL )
    {
        strcpy( ssid, data->ssid );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetSsidWifiDevice( int winid, int wifidev, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetSsidWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetSsidWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 232, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 232, data );
    }
    component->Call( component, idnet2WifiGetSsidWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 232, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 232, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        strcpy( retval, data->retval );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetThroughputWifiDevice( int winid, int wifidev, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetThroughputWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetThroughputWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 233, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 233, data );
    }
    component->Call( component, idnet2WifiGetThroughputWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 233, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 233, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiGetWpsModeWifiDevice( int winid, int wifidev, int * mode )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiGetWpsModeWifiDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiGetWpsModeWifiDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->wifidev = wifidev;
    data->mode = *mode;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 234, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 234, data );
    }
    component->Call( component, idnet2WifiGetWpsModeWifiDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 234, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 234, data );
    }

    /*  5. copy "out" parameters */
    if ( mode != NULL )
    {
        *mode = data->mode;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiScanWifiDevices( int winid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiScanWifiDevices *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiScanWifiDevices );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 235, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 235, data );
    }
    component->Call( component, idnet2WifiScanWifiDevices, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 235, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 235, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiSetChannel( int winid, int channel, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiSetChannel *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiSetChannel );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->channel = channel;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 236, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 236, data );
    }
    component->Call( component, idnet2WifiSetChannel, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 236, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 236, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiSetEncryptionMode( int winid, int mode, int auth, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiSetEncryptionMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiSetEncryptionMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->mode = mode;
    data->auth = auth;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 237, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 237, data );
    }
    component->Call( component, idnet2WifiSetEncryptionMode, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 237, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 237, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiSetKey( int winid, char * key, int len, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiSetKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiSetKey ) + ( sizeof( char ) * len );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->key = ( key == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(net2WifiSetKey) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( char ) * len ) );
    }
    data->len = len;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 238, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 238, data );
    }
    component->Call( component, idnet2WifiSetKey, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 238, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 238, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiSetPortType( int winid, int porttype, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiSetPortType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiSetPortType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->porttype = porttype;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 239, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 239, data );
    }
    component->Call( component, idnet2WifiSetPortType, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 239, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 239, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiSetSsid( int winid, char * ssid, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiSetSsid *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiSetSsid ) + ( ( ssid == NULL ? 0 : strlen( ssid ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->ssid = ( ssid == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(net2WifiSetSsid) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->ssid != NULL )
    {
        strcpy( data->ssid, ssid );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 240, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 240, data );
    }
    component->Call( component, idnet2WifiSetSsid, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 240, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 240, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_net2_WifiStartWpsConnection( int winid, int mode, char * pin )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    net2WifiStartWpsConnection *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( net2WifiStartWpsConnection ) + ( ( pin == NULL ? 0 : strlen( pin ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->pin = ( pin == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(net2WifiStartWpsConnection) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->mode = mode;
    if ( data->pin != NULL )
    {
        strcpy( data->pin, pin );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 241, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCall, 241, data );
    }
    component->Call( component, idnet2WifiStartWpsConnection, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 241, data );
    }
    if ( plfapiinfra_hook_net2 )
    {
        (*plfapiinfra_hook_net2)( ipchtCallDone, 241, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pacN_OnExecutionCompleted( int winid, int appid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pacNOnExecutionCompleted *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pacNOnExecutionCompleted );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 242, data );
    }
    if ( plfapiinfra_hook_p2pacN )
    {
        (*plfapiinfra_hook_p2pacN)( ipchtCall, 242, data );
    }
    component->Call( component, idp2pacNOnExecutionCompleted, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 242, data );
    }
    if ( plfapiinfra_hook_p2pacN )
    {
        (*plfapiinfra_hook_p2pacN)( ipchtCallDone, 242, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pacN_OnTransmissionCompleted( int winid, int appid, Bool success )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pacNOnTransmissionCompleted *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pacNOnTransmissionCompleted );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->success = success;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 243, data );
    }
    if ( plfapiinfra_hook_p2pacN )
    {
        (*plfapiinfra_hook_p2pacN)( ipchtCall, 243, data );
    }
    component->Call( component, idp2pacNOnTransmissionCompleted, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 243, data );
    }
    if ( plfapiinfra_hook_p2pacN )
    {
        (*plfapiinfra_hook_p2pacN)( ipchtCallDone, 243, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pah_WriteASync( int winid, int appid, int bus, void * buf, int size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pahWriteASync *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pahWriteASync ) + ( sizeof( void ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(p2pahWriteASync) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->bus = bus;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( void ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 244, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCall, 244, data );
    }
    component->Call( component, idp2pahWriteASync, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 244, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCallDone, 244, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pah_WriteASyncNoRetry( int winid, int appid, int bus, void * buf, int size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pahWriteASyncNoRetry *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pahWriteASyncNoRetry ) + ( sizeof( void ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(p2pahWriteASyncNoRetry) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->bus = bus;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( void ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 245, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCall, 245, data );
    }
    component->Call( component, idp2pahWriteASyncNoRetry, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 245, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCallDone, 245, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pah_WriteCharASync( int winid, int appid, int bus, char * buf, int size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pahWriteCharASync *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pahWriteCharASync ) + ( sizeof( char ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(p2pahWriteCharASync) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->bus = bus;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( char ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 246, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCall, 246, data );
    }
    component->Call( component, idp2pahWriteCharASync, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 246, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCallDone, 246, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pah_WriteCharASyncNoRetry( int winid, int appid, int bus, char * buf, int size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pahWriteCharASyncNoRetry *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pahWriteCharASyncNoRetry ) + ( sizeof( char ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(p2pahWriteCharASyncNoRetry) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->bus = bus;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( char ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 247, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCall, 247, data );
    }
    component->Call( component, idp2pahWriteCharASyncNoRetry, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 247, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCallDone, 247, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pah_WriteCharNoSync( int winid, int appid, int bus, char * buf, int size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pahWriteCharNoSync *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pahWriteCharNoSync ) + ( sizeof( char ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(p2pahWriteCharNoSync) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->bus = bus;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( char ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 248, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCall, 248, data );
    }
    component->Call( component, idp2pahWriteCharNoSync, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 248, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCallDone, 248, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pah_WriteCharNoSyncNoRetry( int winid, int appid, int bus, char * buf, int size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pahWriteCharNoSyncNoRetry *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pahWriteCharNoSyncNoRetry ) + ( sizeof( char ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(p2pahWriteCharNoSyncNoRetry) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->bus = bus;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( char ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 249, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCall, 249, data );
    }
    component->Call( component, idp2pahWriteCharNoSyncNoRetry, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 249, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCallDone, 249, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pah_WriteNoSync( int winid, int appid, int bus, void * buf, int size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pahWriteNoSync *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pahWriteNoSync ) + ( sizeof( void ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(p2pahWriteNoSync) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->bus = bus;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( void ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 250, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCall, 250, data );
    }
    component->Call( component, idp2pahWriteNoSync, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 250, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCallDone, 250, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_p2pah_WriteNoSyncNoRetry( int winid, int appid, int bus, void * buf, int size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    p2pahWriteNoSyncNoRetry *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( p2pahWriteNoSyncNoRetry ) + ( sizeof( void ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buf = ( buf == NULL ) ? NULL : (void *)( ((char*)data) + sizeof(p2pahWriteNoSyncNoRetry) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->appid = appid;
    data->bus = bus;
    if ( data->buf != NULL )
    {
        memcpy( data->buf, buf, ( sizeof( void ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 251, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCall, 251, data );
    }
    component->Call( component, idp2pahWriteNoSyncNoRetry, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 251, data );
    }
    if ( plfapiinfra_hook_p2pah )
    {
        (*plfapiinfra_hook_p2pah)( ipchtCallDone, 251, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_resmgr_Acquire( int resid, Address * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    resmgrAcquire *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( resmgrAcquire );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->resid = resid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 252, data );
    }
    if ( plfapiinfra_hook_resmgr )
    {
        (*plfapiinfra_hook_resmgr)( ipchtCall, 252, data );
    }
    component->Call( component, idresmgrAcquire, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 252, data );
    }
    if ( plfapiinfra_hook_resmgr )
    {
        (*plfapiinfra_hook_resmgr)( ipchtCallDone, 252, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_resmgr_Release( int resid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    resmgrRelease *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( resmgrRelease );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->resid = resid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 253, data );
    }
    if ( plfapiinfra_hook_resmgr )
    {
        (*plfapiinfra_hook_resmgr)( ipchtCall, 253, data );
    }
    component->Call( component, idresmgrRelease, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 253, data );
    }
    if ( plfapiinfra_hook_resmgr )
    {
        (*plfapiinfra_hook_resmgr)( ipchtCallDone, 253, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_secsto_Check( char * filename, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    secstoCheck *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( secstoCheck ) + ( ( filename == NULL ? 0 : strlen( filename ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filename = ( filename == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(secstoCheck) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->filename != NULL )
    {
        strcpy( data->filename, filename );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 254, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCall, 254, data );
    }
    component->Call( component, idsecstoCheck, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 254, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCallDone, 254, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_secsto_GetPacket( int handle, char * label, int packetlength, Nat8 * packet )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    secstoGetPacket *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( secstoGetPacket ) + ( ( label == NULL ? 0 : strlen( label ) ) + 1 ) + ( sizeof( Nat8 ) * packetlength );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->label = ( label == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(secstoGetPacket) );
    data->packet = ( packet == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(secstoGetPacket) + ( ( label == NULL ? 0 : strlen( label ) ) + 1 ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->handle = handle;
    if ( data->label != NULL )
    {
        strcpy( data->label, label );
    }
    data->packetlength = packetlength;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 255, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCall, 255, data );
    }
    component->Call( component, idsecstoGetPacket, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 255, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCallDone, 255, data );
    }

    /*  5. copy "out" parameters */
    if ( packet != NULL )
    {
        memcpy( packet, data->packet,( sizeof( Nat8 ) * packetlength ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_secsto_GetPacketLength( int handle, char * label, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    secstoGetPacketLength *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( secstoGetPacketLength ) + ( ( label == NULL ? 0 : strlen( label ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->label = ( label == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(secstoGetPacketLength) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->handle = handle;
    if ( data->label != NULL )
    {
        strcpy( data->label, label );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 256, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCall, 256, data );
    }
    component->Call( component, idsecstoGetPacketLength, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 256, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCallDone, 256, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_secsto_Load( char * filename, char * pub, int * handle, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    secstoLoad *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( secstoLoad ) + ( ( filename == NULL ? 0 : strlen( filename ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filename = ( filename == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(secstoLoad) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->filename != NULL )
    {
        strcpy( data->filename, filename );
    }
    if ( data->pub != NULL )
    {
        memcpy( data->pub, pub, ( sizeof( char ) * 32 ) );
    }

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 257, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCall, 257, data );
    }
    component->Call( component, idsecstoLoad, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 257, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCallDone, 257, data );
    }

    /*  5. copy "out" parameters */
    if ( handle != NULL )
    {
        *handle = data->handle;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_secsto_Store( char * filename, int baglen, Nat8 * bag, int encrypt, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    secstoStore *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( secstoStore ) + ( ( filename == NULL ? 0 : strlen( filename ) ) + 1 ) + ( sizeof( Nat8 ) * baglen );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filename = ( filename == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(secstoStore) );
    data->bag = ( bag == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(secstoStore) + ( ( filename == NULL ? 0 : strlen( filename ) ) + 1 ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    if ( data->filename != NULL )
    {
        strcpy( data->filename, filename );
    }
    data->baglen = baglen;
    if ( data->bag != NULL )
    {
        memcpy( data->bag, bag, ( sizeof( Nat8 ) * baglen ) );
    }
    data->encrypt = encrypt;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 258, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCall, 258, data );
    }
    component->Call( component, idsecstoStore, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 258, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCallDone, 258, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_secsto_Unload( int handle )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    secstoUnload *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( secstoUnload );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->handle = handle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 259, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCall, 259, data );
    }
    component->Call( component, idsecstoUnload, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 259, data );
    }
    if ( plfapiinfra_hook_secsto )
    {
        (*plfapiinfra_hook_secsto)( ipchtCallDone, 259, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_shmem_CacheFlush( int winid, Address address, Nat32 size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    shmemCacheFlush *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( shmemCacheFlush );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 260, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCall, 260, data );
    }
    component->Call( component, idshmemCacheFlush, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 260, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCallDone, 260, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_shmem_CacheInvalidate( int winid, Address address, Nat32 size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    shmemCacheInvalidate *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( shmemCacheInvalidate );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 261, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCall, 261, data );
    }
    component->Call( component, idshmemCacheInvalidate, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 261, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCallDone, 261, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_shmem_Free( int winid, Address address, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    shmemFree *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( shmemFree );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->address = address;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 262, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCall, 262, data );
    }
    component->Call( component, idshmemFree, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 262, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCallDone, 262, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_shmem_Malloc( int winid, Nat32 handle, Nat32 size, Address * address, Nat32 flags, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    shmemMalloc *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( shmemMalloc );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->handle = handle;
    data->size = size;
    data->flags = flags;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 263, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCall, 263, data );
    }
    component->Call( component, idshmemMalloc, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 263, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCallDone, 263, data );
    }

    /*  5. copy "out" parameters */
    if ( address != NULL )
    {
        *address = data->address;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_shmem_MallocAlign( int winid, Nat32 handle, Nat32 size, Address * address, Nat32 flags, Nat32 alignment, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    shmemMallocAlign *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( shmemMallocAlign );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->handle = handle;
    data->size = size;
    data->flags = flags;
    data->alignment = alignment;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 264, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCall, 264, data );
    }
    component->Call( component, idshmemMallocAlign, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 264, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCallDone, 264, data );
    }

    /*  5. copy "out" parameters */
    if ( address != NULL )
    {
        *address = data->address;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_shmem_MmspCreate( int winid, Nat32 * handle, Nat32 size, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    shmemMmspCreate *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( shmemMmspCreate );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 265, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCall, 265, data );
    }
    component->Call( component, idshmemMmspCreate, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 265, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCallDone, 265, data );
    }

    /*  5. copy "out" parameters */
    if ( handle != NULL )
    {
        *handle = data->handle;
    }
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_shmem_MmspDelete( int winid, Nat32 handle, FResult * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    shmemMmspDelete *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( shmemMmspDelete );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->handle = handle;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 266, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCall, 266, data );
    }
    component->Call( component, idshmemMmspDelete, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 266, data );
    }
    if ( plfapiinfra_hook_shmem )
    {
        (*plfapiinfra_hook_shmem)( ipchtCallDone, 266, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_uartctl_SetBaudRate( int winid, int uart, int baudrate )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    uartctlSetBaudRate *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( uartctlSetBaudRate );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->uart = uart;
    data->baudrate = baudrate;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 267, data );
    }
    if ( plfapiinfra_hook_uartctl )
    {
        (*plfapiinfra_hook_uartctl)( ipchtCall, 267, data );
    }
    component->Call( component, iduartctlSetBaudRate, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 267, data );
    }
    if ( plfapiinfra_hook_uartctl )
    {
        (*plfapiinfra_hook_uartctl)( ipchtCallDone, 267, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_uartprint_Disable( void )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    uartprintDisable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( uartprintDisable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 268, data );
    }
    if ( plfapiinfra_hook_uartprint )
    {
        (*plfapiinfra_hook_uartprint)( ipchtCall, 268, data );
    }
    component->Call( component, iduartprintDisable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 268, data );
    }
    if ( plfapiinfra_hook_uartprint )
    {
        (*plfapiinfra_hook_uartprint)( ipchtCallDone, 268, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_uartprint_Enable( void )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    uartprintEnable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( uartprintEnable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 269, data );
    }
    if ( plfapiinfra_hook_uartprint )
    {
        (*plfapiinfra_hook_uartprint)( ipchtCall, 269, data );
    }
    component->Call( component, iduartprintEnable, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 269, data );
    }
    if ( plfapiinfra_hook_uartprint )
    {
        (*plfapiinfra_hook_uartprint)( ipchtCallDone, 269, data );
    }

    /*  5. copy "out" parameters */

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_uartprint_IsEnabled( Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    uartprintIsEnabled *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( uartprintIsEnabled );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 270, data );
    }
    if ( plfapiinfra_hook_uartprint )
    {
        (*plfapiinfra_hook_uartprint)( ipchtCall, 270, data );
    }
    component->Call( component, iduartprintIsEnabled, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 270, data );
    }
    if ( plfapiinfra_hook_uartprint )
    {
        (*plfapiinfra_hook_uartprint)( ipchtCallDone, 270, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_uid_GetSoCUniqueID( Nat64 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    uidGetSoCUniqueID *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( uidGetSoCUniqueID );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 271, data );
    }
    if ( plfapiinfra_hook_uid )
    {
        (*plfapiinfra_hook_uid)( ipchtCall, 271, data );
    }
    component->Call( component, iduidGetSoCUniqueID, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 271, data );
    }
    if ( plfapiinfra_hook_uid )
    {
        (*plfapiinfra_hook_uid)( ipchtCallDone, 271, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upginf_GetCurrentTvSwDescription( int winid, int descsize, char * desc )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upginfGetCurrentTvSwDescription *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upginfGetCurrentTvSwDescription ) + ( sizeof( char ) * descsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->desc = ( desc == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginfGetCurrentTvSwDescription) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->descsize = descsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 272, data );
    }
    if ( plfapiinfra_hook_upginf )
    {
        (*plfapiinfra_hook_upginf)( ipchtCall, 272, data );
    }
    component->Call( component, idupginfGetCurrentTvSwDescription, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 272, data );
    }
    if ( plfapiinfra_hook_upginf )
    {
        (*plfapiinfra_hook_upginf)( ipchtCallDone, 272, data );
    }

    /*  5. copy "out" parameters */
    if ( desc != NULL )
    {
        memcpy( desc, data->desc,( sizeof( char ) * descsize ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upginf_GetUpgHeaderSize( int winid, int * headersize )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upginfGetUpgHeaderSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upginfGetUpgHeaderSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 273, data );
    }
    if ( plfapiinfra_hook_upginf )
    {
        (*plfapiinfra_hook_upginf)( ipchtCall, 273, data );
    }
    component->Call( component, idupginfGetUpgHeaderSize, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 273, data );
    }
    if ( plfapiinfra_hook_upginf )
    {
        (*plfapiinfra_hook_upginf)( ipchtCallDone, 273, data );
    }

    /*  5. copy "out" parameters */
    if ( headersize != NULL )
    {
        *headersize = data->headersize;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upginf_GetUpgInfo( int winid, int buffersize, Nat8 * buffer, Bool * headervalid, Bool * flashable, Bool * executable, int * executionaddress, int swidsize, char * swid, int descriptionsize, char * description, int exceptionitemindex, int exceptionitemsize, char * exceptionitem )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upginfGetUpgInfo *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upginfGetUpgInfo ) + ( sizeof( Nat8 ) * buffersize ) + ( sizeof( char ) * swidsize ) + ( sizeof( char ) * descriptionsize ) + ( sizeof( char ) * exceptionitemsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->buffer = ( buffer == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(upginfGetUpgInfo) );
    data->swid = ( swid == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginfGetUpgInfo) + ( sizeof( Nat8 ) * buffersize ) );
    data->description = ( description == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginfGetUpgInfo) + ( sizeof( Nat8 ) * buffersize ) + ( sizeof( char ) * swidsize ) );
    data->exceptionitem = ( exceptionitem == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginfGetUpgInfo) + ( sizeof( Nat8 ) * buffersize ) + ( sizeof( char ) * swidsize ) + ( sizeof( char ) * descriptionsize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->buffersize = buffersize;
    if ( data->buffer != NULL )
    {
        memcpy( data->buffer, buffer, ( sizeof( Nat8 ) * buffersize ) );
    }
    data->swidsize = swidsize;
    data->descriptionsize = descriptionsize;
    data->exceptionitemindex = exceptionitemindex;
    data->exceptionitemsize = exceptionitemsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 274, data );
    }
    if ( plfapiinfra_hook_upginf )
    {
        (*plfapiinfra_hook_upginf)( ipchtCall, 274, data );
    }
    component->Call( component, idupginfGetUpgInfo, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 274, data );
    }
    if ( plfapiinfra_hook_upginf )
    {
        (*plfapiinfra_hook_upginf)( ipchtCallDone, 274, data );
    }

    /*  5. copy "out" parameters */
    if ( headervalid != NULL )
    {
        *headervalid = data->headervalid;
    }
    if ( flashable != NULL )
    {
        *flashable = data->flashable;
    }
    if ( executable != NULL )
    {
        *executable = data->executable;
    }
    if ( executionaddress != NULL )
    {
        *executionaddress = data->executionaddress;
    }
    if ( swid != NULL )
    {
        memcpy( swid, data->swid,( sizeof( char ) * swidsize ) );
    }
    if ( description != NULL )
    {
        memcpy( description, data->description,( sizeof( char ) * descriptionsize ) );
    }
    if ( exceptionitem != NULL )
    {
        memcpy( exceptionitem, data->exceptionitem,( sizeof( char ) * exceptionitemsize ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upginf2_GetCurrentTvSwDescription( int winid, int descsize, char * desc )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upginf2GetCurrentTvSwDescription *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upginf2GetCurrentTvSwDescription ) + ( sizeof( char ) * descsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->desc = ( desc == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf2GetCurrentTvSwDescription) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->descsize = descsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 275, data );
    }
    if ( plfapiinfra_hook_upginf2 )
    {
        (*plfapiinfra_hook_upginf2)( ipchtCall, 275, data );
    }
    component->Call( component, idupginf2GetCurrentTvSwDescription, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 275, data );
    }
    if ( plfapiinfra_hook_upginf2 )
    {
        (*plfapiinfra_hook_upginf2)( ipchtCallDone, 275, data );
    }

    /*  5. copy "out" parameters */
    if ( desc != NULL )
    {
        memcpy( desc, data->desc,( sizeof( char ) * descsize ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upginf2_GetUpgInfo( int winid, char * filePath, Bool * headervalid, Bool * flashable, Bool * executable, int * executionaddress, int swidsize, char * swid, int descriptionsize, char * description, int exceptionitemindex, int exceptionitemsize, char * exceptionitem )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upginf2GetUpgInfo *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upginf2GetUpgInfo ) + ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 ) + ( sizeof( char ) * swidsize ) + ( sizeof( char ) * descriptionsize ) + ( sizeof( char ) * exceptionitemsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filePath = ( filePath == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf2GetUpgInfo) );
    data->swid = ( swid == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf2GetUpgInfo) + ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 ) );
    data->description = ( description == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf2GetUpgInfo) + ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 ) + ( sizeof( char ) * swidsize ) );
    data->exceptionitem = ( exceptionitem == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf2GetUpgInfo) + ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 ) + ( sizeof( char ) * swidsize ) + ( sizeof( char ) * descriptionsize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->filePath != NULL )
    {
        strcpy( data->filePath, filePath );
    }
    data->swidsize = swidsize;
    data->descriptionsize = descriptionsize;
    data->exceptionitemindex = exceptionitemindex;
    data->exceptionitemsize = exceptionitemsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 276, data );
    }
    if ( plfapiinfra_hook_upginf2 )
    {
        (*plfapiinfra_hook_upginf2)( ipchtCall, 276, data );
    }
    component->Call( component, idupginf2GetUpgInfo, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 276, data );
    }
    if ( plfapiinfra_hook_upginf2 )
    {
        (*plfapiinfra_hook_upginf2)( ipchtCallDone, 276, data );
    }

    /*  5. copy "out" parameters */
    if ( headervalid != NULL )
    {
        *headervalid = data->headervalid;
    }
    if ( flashable != NULL )
    {
        *flashable = data->flashable;
    }
    if ( executable != NULL )
    {
        *executable = data->executable;
    }
    if ( executionaddress != NULL )
    {
        *executionaddress = data->executionaddress;
    }
    if ( swid != NULL )
    {
        memcpy( swid, data->swid,( sizeof( char ) * swidsize ) );
    }
    if ( description != NULL )
    {
        memcpy( description, data->description,( sizeof( char ) * descriptionsize ) );
    }
    if ( exceptionitem != NULL )
    {
        memcpy( exceptionitem, data->exceptionitem,( sizeof( char ) * exceptionitemsize ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upginf3_GetCurrentTvSwDescription( int winid, int descsize, char * desc )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upginf3GetCurrentTvSwDescription *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upginf3GetCurrentTvSwDescription ) + ( sizeof( char ) * descsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->desc = ( desc == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf3GetCurrentTvSwDescription) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->descsize = descsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 277, data );
    }
    if ( plfapiinfra_hook_upginf3 )
    {
        (*plfapiinfra_hook_upginf3)( ipchtCall, 277, data );
    }
    component->Call( component, idupginf3GetCurrentTvSwDescription, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 277, data );
    }
    if ( plfapiinfra_hook_upginf3 )
    {
        (*plfapiinfra_hook_upginf3)( ipchtCallDone, 277, data );
    }

    /*  5. copy "out" parameters */
    if ( desc != NULL )
    {
        memcpy( desc, data->desc,( sizeof( char ) * descsize ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upginf3_GetUpgInfo( int winid, char * filepath, int fileoffset, Bool * headervalid, Bool * flashable, Bool * executable, int * executionaddress, int swidsize, char * swid, int descriptionsize, char * description, int exceptionitemindex, int exceptionitemsize, char * exceptionitem )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upginf3GetUpgInfo *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upginf3GetUpgInfo ) + ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 ) + ( sizeof( char ) * swidsize ) + ( sizeof( char ) * descriptionsize ) + ( sizeof( char ) * exceptionitemsize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filepath = ( filepath == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf3GetUpgInfo) );
    data->swid = ( swid == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf3GetUpgInfo) + ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 ) );
    data->description = ( description == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf3GetUpgInfo) + ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 ) + ( sizeof( char ) * swidsize ) );
    data->exceptionitem = ( exceptionitem == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upginf3GetUpgInfo) + ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 ) + ( sizeof( char ) * swidsize ) + ( sizeof( char ) * descriptionsize ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->filepath != NULL )
    {
        strcpy( data->filepath, filepath );
    }
    data->fileoffset = fileoffset;
    data->swidsize = swidsize;
    data->descriptionsize = descriptionsize;
    data->exceptionitemindex = exceptionitemindex;
    data->exceptionitemsize = exceptionitemsize;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 278, data );
    }
    if ( plfapiinfra_hook_upginf3 )
    {
        (*plfapiinfra_hook_upginf3)( ipchtCall, 278, data );
    }
    component->Call( component, idupginf3GetUpgInfo, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 278, data );
    }
    if ( plfapiinfra_hook_upginf3 )
    {
        (*plfapiinfra_hook_upginf3)( ipchtCallDone, 278, data );
    }

    /*  5. copy "out" parameters */
    if ( headervalid != NULL )
    {
        *headervalid = data->headervalid;
    }
    if ( flashable != NULL )
    {
        *flashable = data->flashable;
    }
    if ( executable != NULL )
    {
        *executable = data->executable;
    }
    if ( executionaddress != NULL )
    {
        *executionaddress = data->executionaddress;
    }
    if ( swid != NULL )
    {
        memcpy( swid, data->swid,( sizeof( char ) * swidsize ) );
    }
    if ( description != NULL )
    {
        memcpy( description, data->description,( sizeof( char ) * descriptionsize ) );
    }
    if ( exceptionitem != NULL )
    {
        memcpy( exceptionitem, data->exceptionitem,( sizeof( char ) * exceptionitemsize ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_GetUpgLoadingProgress( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolGetUpgLoadingProgress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolGetUpgLoadingProgress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 279, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 279, data );
    }
    component->Call( component, idupgtoolGetUpgLoadingProgress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 279, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 279, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_GetUpgLoadingStatus( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolGetUpgLoadingStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolGetUpgLoadingStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 280, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 280, data );
    }
    component->Call( component, idupgtoolGetUpgLoadingStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 280, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 280, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_GetUpgProgrammingProgress( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolGetUpgProgrammingProgress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolGetUpgProgrammingProgress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 281, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 281, data );
    }
    component->Call( component, idupgtoolGetUpgProgrammingProgress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 281, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 281, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_GetUpgProgrammingStatus( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolGetUpgProgrammingStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolGetUpgProgrammingStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 282, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 282, data );
    }
    component->Call( component, idupgtoolGetUpgProgrammingStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 282, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 282, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_GetUpgValidationProgress( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolGetUpgValidationProgress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolGetUpgValidationProgress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 283, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 283, data );
    }
    component->Call( component, idupgtoolGetUpgValidationProgress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 283, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 283, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_GetUpgValidationStatus( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolGetUpgValidationStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolGetUpgValidationStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 284, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 284, data );
    }
    component->Call( component, idupgtoolGetUpgValidationStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 284, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 284, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_StartUpgLoading( int winid, char * filePath, Bool inPlaceDecrypt, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolStartUpgLoading *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolStartUpgLoading ) + ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filePath = ( filePath == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upgtoolStartUpgLoading) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->filePath != NULL )
    {
        strcpy( data->filePath, filePath );
    }
    data->inPlaceDecrypt = inPlaceDecrypt;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 285, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 285, data );
    }
    component->Call( component, idupgtoolStartUpgLoading, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 285, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 285, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_StartUpgProgramming( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolStartUpgProgramming *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolStartUpgProgramming );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 286, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 286, data );
    }
    component->Call( component, idupgtoolStartUpgProgramming, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 286, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 286, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_StartUpgValidation( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolStartUpgValidation *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolStartUpgValidation );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 287, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 287, data );
    }
    component->Call( component, idupgtoolStartUpgValidation, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 287, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 287, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_StopUpgLoading( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolStopUpgLoading *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolStopUpgLoading );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 288, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 288, data );
    }
    component->Call( component, idupgtoolStopUpgLoading, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 288, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 288, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_StopUpgProgramming( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolStopUpgProgramming *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolStopUpgProgramming );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 289, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 289, data );
    }
    component->Call( component, idupgtoolStopUpgProgramming, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 289, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 289, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool_StopUpgValidation( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtoolStopUpgValidation *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtoolStopUpgValidation );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 290, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCall, 290, data );
    }
    component->Call( component, idupgtoolStopUpgValidation, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 290, data );
    }
    if ( plfapiinfra_hook_upgtool )
    {
        (*plfapiinfra_hook_upgtool)( ipchtCallDone, 290, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_GetUpgLoadingProgress( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2GetUpgLoadingProgress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2GetUpgLoadingProgress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 291, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 291, data );
    }
    component->Call( component, idupgtool2GetUpgLoadingProgress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 291, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 291, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_GetUpgLoadingStatus( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2GetUpgLoadingStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2GetUpgLoadingStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 292, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 292, data );
    }
    component->Call( component, idupgtool2GetUpgLoadingStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 292, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 292, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_GetUpgProgrammingProgress( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2GetUpgProgrammingProgress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2GetUpgProgrammingProgress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 293, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 293, data );
    }
    component->Call( component, idupgtool2GetUpgProgrammingProgress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 293, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 293, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_GetUpgProgrammingStatus( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2GetUpgProgrammingStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2GetUpgProgrammingStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 294, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 294, data );
    }
    component->Call( component, idupgtool2GetUpgProgrammingStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 294, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 294, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_GetUpgValidationProgress( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2GetUpgValidationProgress *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2GetUpgValidationProgress );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 295, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 295, data );
    }
    component->Call( component, idupgtool2GetUpgValidationProgress, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 295, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 295, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_GetUpgValidationStatus( int winid, int * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2GetUpgValidationStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2GetUpgValidationStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 296, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 296, data );
    }
    component->Call( component, idupgtool2GetUpgValidationStatus, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 296, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 296, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_StartUpgLoading( int winid, char * filePath, int fileOffset, Bool inPlaceDecrypt, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2StartUpgLoading *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2StartUpgLoading ) + ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->filePath = ( filePath == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(upgtool2StartUpgLoading) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->filePath != NULL )
    {
        strcpy( data->filePath, filePath );
    }
    data->fileOffset = fileOffset;
    data->inPlaceDecrypt = inPlaceDecrypt;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 297, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 297, data );
    }
    component->Call( component, idupgtool2StartUpgLoading, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 297, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 297, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_StartUpgProgramming( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2StartUpgProgramming *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2StartUpgProgramming );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 298, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 298, data );
    }
    component->Call( component, idupgtool2StartUpgProgramming, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 298, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 298, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_StartUpgValidation( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2StartUpgValidation *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2StartUpgValidation );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 299, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 299, data );
    }
    component->Call( component, idupgtool2StartUpgValidation, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 299, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 299, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_StopUpgLoading( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2StopUpgLoading *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2StopUpgLoading );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 300, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 300, data );
    }
    component->Call( component, idupgtool2StopUpgLoading, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 300, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 300, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_StopUpgProgramming( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2StopUpgProgramming *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2StopUpgProgramming );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 301, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 301, data );
    }
    component->Call( component, idupgtool2StopUpgProgramming, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 301, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 301, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_upgtool2_StopUpgValidation( int winid, Bool * retVal )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    upgtool2StopUpgValidation *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( upgtool2StopUpgValidation );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 302, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCall, 302, data );
    }
    component->Call( component, idupgtool2StopUpgValidation, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 302, data );
    }
    if ( plfapiinfra_hook_upgtool2 )
    {
        (*plfapiinfra_hook_upgtool2)( ipchtCallDone, 302, data );
    }

    /*  5. copy "out" parameters */
    if ( retVal != NULL )
    {
        *retVal = data->retVal;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev_GetActiveDevicesList( int winid, int nrofdevs, int * devices, int * activedevices )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdevGetActiveDevicesList *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdevGetActiveDevicesList ) + ( sizeof( int ) * nrofdevs );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->devices = ( devices == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(usbdevGetActiveDevicesList) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->nrofdevs = nrofdevs;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 303, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCall, 303, data );
    }
    component->Call( component, idusbdevGetActiveDevicesList, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 303, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCallDone, 303, data );
    }

    /*  5. copy "out" parameters */
    if ( devices != NULL )
    {
        memcpy( devices, data->devices,( sizeof( int ) * nrofdevs ) );
    }
    if ( activedevices != NULL )
    {
        *activedevices = data->activedevices;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev_GetDeviceInfo( int winid, int devid, int manufstrlen, char * manufacturer, int prodstrlen, char * product, int revstrlen, char * revision, int * devicetype, Bool * deviswriteprotected, Bool * ismounted, int pathnamelength, char * pathname, int * physdevid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdevGetDeviceInfo *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdevGetDeviceInfo ) + ( sizeof( char ) * manufstrlen ) + ( sizeof( char ) * prodstrlen ) + ( sizeof( char ) * revstrlen ) + ( sizeof( char ) * pathnamelength );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->manufacturer = ( manufacturer == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(usbdevGetDeviceInfo) );
    data->product = ( product == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(usbdevGetDeviceInfo) + ( sizeof( char ) * manufstrlen ) );
    data->revision = ( revision == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(usbdevGetDeviceInfo) + ( sizeof( char ) * manufstrlen ) + ( sizeof( char ) * prodstrlen ) );
    data->pathname = ( pathname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(usbdevGetDeviceInfo) + ( sizeof( char ) * manufstrlen ) + ( sizeof( char ) * prodstrlen ) + ( sizeof( char ) * revstrlen ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->devid = devid;
    data->manufstrlen = manufstrlen;
    data->prodstrlen = prodstrlen;
    data->revstrlen = revstrlen;
    data->pathnamelength = pathnamelength;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 304, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCall, 304, data );
    }
    component->Call( component, idusbdevGetDeviceInfo, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 304, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCallDone, 304, data );
    }

    /*  5. copy "out" parameters */
    if ( manufacturer != NULL )
    {
        memcpy( manufacturer, data->manufacturer,( sizeof( char ) * manufstrlen ) );
    }
    if ( product != NULL )
    {
        memcpy( product, data->product,( sizeof( char ) * prodstrlen ) );
    }
    if ( revision != NULL )
    {
        memcpy( revision, data->revision,( sizeof( char ) * revstrlen ) );
    }
    if ( devicetype != NULL )
    {
        *devicetype = data->devicetype;
    }
    if ( deviswriteprotected != NULL )
    {
        *deviswriteprotected = data->deviswriteprotected;
    }
    if ( ismounted != NULL )
    {
        *ismounted = data->ismounted;
    }
    if ( pathname != NULL )
    {
        memcpy( pathname, data->pathname,( sizeof( char ) * pathnamelength ) );
    }
    if ( physdevid != NULL )
    {
        *physdevid = data->physdevid;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev_GetPhysDeviceMemberList( int winid, int physdevid, int nrofdevs, int * devices, int * actualnrofdevs )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdevGetPhysDeviceMemberList *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdevGetPhysDeviceMemberList ) + ( sizeof( int ) * nrofdevs );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->devices = ( devices == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(usbdevGetPhysDeviceMemberList) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->physdevid = physdevid;
    data->nrofdevs = nrofdevs;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 305, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCall, 305, data );
    }
    component->Call( component, idusbdevGetPhysDeviceMemberList, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 305, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCallDone, 305, data );
    }

    /*  5. copy "out" parameters */
    if ( devices != NULL )
    {
        memcpy( devices, data->devices,( sizeof( int ) * nrofdevs ) );
    }
    if ( actualnrofdevs != NULL )
    {
        *actualnrofdevs = data->actualnrofdevs;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev_GetPhysDevicesList( int winid, int nrofphysdevs, int * physdevices, int * activephysdevices )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdevGetPhysDevicesList *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdevGetPhysDevicesList ) + ( sizeof( int ) * nrofphysdevs );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->physdevices = ( physdevices == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(usbdevGetPhysDevicesList) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->nrofphysdevs = nrofphysdevs;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 306, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCall, 306, data );
    }
    component->Call( component, idusbdevGetPhysDevicesList, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 306, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCallDone, 306, data );
    }

    /*  5. copy "out" parameters */
    if ( physdevices != NULL )
    {
        memcpy( physdevices, data->physdevices,( sizeof( int ) * nrofphysdevs ) );
    }
    if ( activephysdevices != NULL )
    {
        *activephysdevices = data->activephysdevices;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev_GetUsbMaxDevices( int winid, int * maxdevs )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdevGetUsbMaxDevices *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdevGetUsbMaxDevices );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 307, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCall, 307, data );
    }
    component->Call( component, idusbdevGetUsbMaxDevices, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 307, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCallDone, 307, data );
    }

    /*  5. copy "out" parameters */
    if ( maxdevs != NULL )
    {
        *maxdevs = data->maxdevs;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev_GetUsbMaxPartitionsPerDevice( int winid, int * maxparts )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdevGetUsbMaxPartitionsPerDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdevGetUsbMaxPartitionsPerDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 308, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCall, 308, data );
    }
    component->Call( component, idusbdevGetUsbMaxPartitionsPerDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 308, data );
    }
    if ( plfapiinfra_hook_usbdev )
    {
        (*plfapiinfra_hook_usbdev)( ipchtCallDone, 308, data );
    }

    /*  5. copy "out" parameters */
    if ( maxparts != NULL )
    {
        *maxparts = data->maxparts;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev2_GetActiveDevicesList( int winid, int nrofdevs, int * devices, int * activedevices, FResult * fresult )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdev2GetActiveDevicesList *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdev2GetActiveDevicesList ) + ( sizeof( int ) * nrofdevs );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->devices = ( devices == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(usbdev2GetActiveDevicesList) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->nrofdevs = nrofdevs;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 309, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCall, 309, data );
    }
    component->Call( component, idusbdev2GetActiveDevicesList, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 309, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCallDone, 309, data );
    }

    /*  5. copy "out" parameters */
    if ( devices != NULL )
    {
        memcpy( devices, data->devices,( sizeof( int ) * nrofdevs ) );
    }
    if ( activedevices != NULL )
    {
        *activedevices = data->activedevices;
    }
    if ( fresult != NULL )
    {
        *fresult = data->fresult;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev2_GetDeviceInfo( int winid, int devid, int manufstrlen, char * manufacturer, int prodstrlen, char * product, int revstrlen, char * revision, int * devicetype, Bool * deviswriteprotected, Bool * ismounted, int pathnamelength, char * pathname, int * physdevid, FResult * fresult )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdev2GetDeviceInfo *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdev2GetDeviceInfo ) + ( sizeof( char ) * manufstrlen ) + ( sizeof( char ) * prodstrlen ) + ( sizeof( char ) * revstrlen ) + ( sizeof( char ) * pathnamelength );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->manufacturer = ( manufacturer == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(usbdev2GetDeviceInfo) );
    data->product = ( product == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(usbdev2GetDeviceInfo) + ( sizeof( char ) * manufstrlen ) );
    data->revision = ( revision == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(usbdev2GetDeviceInfo) + ( sizeof( char ) * manufstrlen ) + ( sizeof( char ) * prodstrlen ) );
    data->pathname = ( pathname == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(usbdev2GetDeviceInfo) + ( sizeof( char ) * manufstrlen ) + ( sizeof( char ) * prodstrlen ) + ( sizeof( char ) * revstrlen ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->devid = devid;
    data->manufstrlen = manufstrlen;
    data->prodstrlen = prodstrlen;
    data->revstrlen = revstrlen;
    data->pathnamelength = pathnamelength;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 310, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCall, 310, data );
    }
    component->Call( component, idusbdev2GetDeviceInfo, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 310, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCallDone, 310, data );
    }

    /*  5. copy "out" parameters */
    if ( manufacturer != NULL )
    {
        memcpy( manufacturer, data->manufacturer,( sizeof( char ) * manufstrlen ) );
    }
    if ( product != NULL )
    {
        memcpy( product, data->product,( sizeof( char ) * prodstrlen ) );
    }
    if ( revision != NULL )
    {
        memcpy( revision, data->revision,( sizeof( char ) * revstrlen ) );
    }
    if ( devicetype != NULL )
    {
        *devicetype = data->devicetype;
    }
    if ( deviswriteprotected != NULL )
    {
        *deviswriteprotected = data->deviswriteprotected;
    }
    if ( ismounted != NULL )
    {
        *ismounted = data->ismounted;
    }
    if ( pathname != NULL )
    {
        memcpy( pathname, data->pathname,( sizeof( char ) * pathnamelength ) );
    }
    if ( physdevid != NULL )
    {
        *physdevid = data->physdevid;
    }
    if ( fresult != NULL )
    {
        *fresult = data->fresult;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev2_GetPhysDeviceMemberList( int winid, int physdevid, int nrofdevs, int * devices, int * actualnrofdevs, FResult * fresult )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdev2GetPhysDeviceMemberList *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdev2GetPhysDeviceMemberList ) + ( sizeof( int ) * nrofdevs );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->devices = ( devices == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(usbdev2GetPhysDeviceMemberList) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->physdevid = physdevid;
    data->nrofdevs = nrofdevs;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 311, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCall, 311, data );
    }
    component->Call( component, idusbdev2GetPhysDeviceMemberList, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 311, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCallDone, 311, data );
    }

    /*  5. copy "out" parameters */
    if ( devices != NULL )
    {
        memcpy( devices, data->devices,( sizeof( int ) * nrofdevs ) );
    }
    if ( actualnrofdevs != NULL )
    {
        *actualnrofdevs = data->actualnrofdevs;
    }
    if ( fresult != NULL )
    {
        *fresult = data->fresult;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev2_GetPhysDevicesList( int winid, int nrofphysdevs, int * physdevices, int * activephysdevices, FResult * fresult )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdev2GetPhysDevicesList *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdev2GetPhysDevicesList ) + ( sizeof( int ) * nrofphysdevs );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->physdevices = ( physdevices == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(usbdev2GetPhysDevicesList) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->nrofphysdevs = nrofphysdevs;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 312, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCall, 312, data );
    }
    component->Call( component, idusbdev2GetPhysDevicesList, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 312, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCallDone, 312, data );
    }

    /*  5. copy "out" parameters */
    if ( physdevices != NULL )
    {
        memcpy( physdevices, data->physdevices,( sizeof( int ) * nrofphysdevs ) );
    }
    if ( activephysdevices != NULL )
    {
        *activephysdevices = data->activephysdevices;
    }
    if ( fresult != NULL )
    {
        *fresult = data->fresult;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev2_GetUsbMaxDevices( int winid, int * maxdevs )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdev2GetUsbMaxDevices *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdev2GetUsbMaxDevices );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 313, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCall, 313, data );
    }
    component->Call( component, idusbdev2GetUsbMaxDevices, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 313, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCallDone, 313, data );
    }

    /*  5. copy "out" parameters */
    if ( maxdevs != NULL )
    {
        *maxdevs = data->maxdevs;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev2_GetUsbMaxPartitionsPerDevice( int winid, int * maxparts )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdev2GetUsbMaxPartitionsPerDevice *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdev2GetUsbMaxPartitionsPerDevice );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 314, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCall, 314, data );
    }
    component->Call( component, idusbdev2GetUsbMaxPartitionsPerDevice, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 314, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCallDone, 314, data );
    }

    /*  5. copy "out" parameters */
    if ( maxparts != NULL )
    {
        *maxparts = data->maxparts;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_usbdev2_IsInitializationDone( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    usbdev2IsInitializationDone *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( usbdev2IsInitializationDone );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 315, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCall, 315, data );
    }
    component->Call( component, idusbdev2IsInitializationDone, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 315, data );
    }
    if ( plfapiinfra_hook_usbdev2 )
    {
        (*plfapiinfra_hook_usbdev2)( ipchtCallDone, 315, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor_Format( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstorFormat *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstorFormat );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 316, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCall, 316, data );
    }
    component->Call( component, idvidstorFormat, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 316, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCallDone, 316, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor_GetFreeSize( int winid, Nat64 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstorGetFreeSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstorGetFreeSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 317, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCall, 317, data );
    }
    component->Call( component, idvidstorGetFreeSize, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 317, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCallDone, 317, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor_GetSize( int winid, Nat64 * retval, int * error )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstorGetSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstorGetSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 318, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCall, 318, data );
    }
    component->Call( component, idvidstorGetSize, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 318, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCallDone, 318, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }
    if ( error != NULL )
    {
        *error = data->error;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor_GetSpeedClass( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstorGetSpeedClass *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstorGetSpeedClass );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 319, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCall, 319, data );
    }
    component->Call( component, idvidstorGetSpeedClass, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 319, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCallDone, 319, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor_GetState( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstorGetState *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstorGetState );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 320, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCall, 320, data );
    }
    component->Call( component, idvidstorGetState, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 320, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCallDone, 320, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor_GetWriteProtected( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstorGetWriteProtected *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstorGetWriteProtected );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 321, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCall, 321, data );
    }
    component->Call( component, idvidstorGetWriteProtected, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 321, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCallDone, 321, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor_IsInitialisationDone( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstorIsInitialisationDone *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstorIsInitialisationDone );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 322, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCall, 322, data );
    }
    component->Call( component, idvidstorIsInitialisationDone, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 322, data );
    }
    if ( plfapiinfra_hook_vidstor )
    {
        (*plfapiinfra_hook_vidstor)( ipchtCallDone, 322, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor2_Format( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstor2Format *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstor2Format );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 323, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCall, 323, data );
    }
    component->Call( component, idvidstor2Format, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 323, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCallDone, 323, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor2_GetFreeSize( int winid, Nat64 * retval, int * error )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstor2GetFreeSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstor2GetFreeSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 324, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCall, 324, data );
    }
    component->Call( component, idvidstor2GetFreeSize, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 324, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCallDone, 324, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }
    if ( error != NULL )
    {
        *error = data->error;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor2_GetMountPoint( int winid, char * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstor2GetMountPoint *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstor2GetMountPoint );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 325, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCall, 325, data );
    }
    component->Call( component, idvidstor2GetMountPoint, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 325, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCallDone, 325, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        strcpy( retval, data->retval );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor2_GetSize( int winid, Nat64 * retval, int * error )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstor2GetSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstor2GetSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 326, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCall, 326, data );
    }
    component->Call( component, idvidstor2GetSize, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 326, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCallDone, 326, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }
    if ( error != NULL )
    {
        *error = data->error;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor2_GetSpeedClass( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstor2GetSpeedClass *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstor2GetSpeedClass );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 327, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCall, 327, data );
    }
    component->Call( component, idvidstor2GetSpeedClass, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 327, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCallDone, 327, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor2_GetState( int winid, int * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstor2GetState *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstor2GetState );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 328, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCall, 328, data );
    }
    component->Call( component, idvidstor2GetState, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 328, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCallDone, 328, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor2_GetWriteProtected( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstor2GetWriteProtected *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstor2GetWriteProtected );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 329, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCall, 329, data );
    }
    component->Call( component, idvidstor2GetWriteProtected, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 329, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCallDone, 329, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiinfra_vidstor2_IsInitialisationDone( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vidstor2IsInitialisationDone *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vidstor2IsInitialisationDone );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCall, 330, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCall, 330, data );
    }
    component->Call( component, idvidstor2IsInitialisationDone, (void *)data, &result );
    if ( plfapiinfra_hookGlobal )
    {
        (*plfapiinfra_hookGlobal)( ipchtCallDone, 330, data );
    }
    if ( plfapiinfra_hook_vidstor2 )
    {
        (*plfapiinfra_hook_vidstor2)( ipchtCallDone, 330, data );
    }

    /*  5. copy "out" parameters */
    if ( retval != NULL )
    {
        *retval = data->retval;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}


void plfapiinfra_EnableNotification_cecrxntf(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idcecrxntfOnReceived, stub_plfapiinfra_cecrxntf_OnReceived, NULL );
}
void plfapiinfra_EnableNotification_cectxntf(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idcectxntfOnTransmitCompleted, stub_plfapiinfra_cectxntf_OnTransmitCompleted, NULL );
}
void plfapiinfra_EnableNotification_clkntf(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idclkntfOnAlarm, stub_plfapiinfra_clkntf_OnAlarm, NULL );
    component->Listen( component, idclkntfOnClockChanged, stub_plfapiinfra_clkntf_OnClockChanged, NULL );
}
void plfapiinfra_EnableNotification_clkntfx(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idclkntfxOnAlarm, stub_plfapiinfra_clkntfx_OnAlarm, NULL );
    component->Listen( component, idclkntfxOnAlarmCancelled, stub_plfapiinfra_clkntfx_OnAlarmCancelled, NULL );
    component->Listen( component, idclkntfxOnClockChanged, stub_plfapiinfra_clkntfx_OnClockChanged, NULL );
}
void plfapiinfra_EnableNotification_fopsN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idfopsNOnPartitionMounted, stub_plfapiinfra_fopsN_OnPartitionMounted, NULL );
    component->Listen( component, idfopsNOnPartitionMountFailed, stub_plfapiinfra_fopsN_OnPartitionMountFailed, NULL );
    component->Listen( component, idfopsNOnPartitionUnmounted, stub_plfapiinfra_fopsN_OnPartitionUnmounted, NULL );
}
void plfapiinfra_EnableNotification_infraitfN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idinfraitfNOnAvailabilityChanged, stub_plfapiinfra_infraitfN_OnAvailabilityChanged, NULL );
}
void plfapiinfra_EnableNotification_net2exexN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idnet2exexNOnDnsStatusChecked, stub_plfapiinfra_net2exexN_OnDnsStatusChecked, NULL );
    component->Listen( component, idnet2exexNOnInitializationDone, stub_plfapiinfra_net2exexN_OnInitializationDone, NULL );
    component->Listen( component, idnet2exexNOnNetworkInterfaceConfigStatusChanged, stub_plfapiinfra_net2exexN_OnNetworkInterfaceConfigStatusChanged, NULL );
    component->Listen( component, idnet2exexNOnNetworkInterfacePhysicalStatusChanged, stub_plfapiinfra_net2exexN_OnNetworkInterfacePhysicalStatusChanged, NULL );
    component->Listen( component, idnet2exexNOnWifiManualSsidFound, stub_plfapiinfra_net2exexN_OnWifiManualSsidFound, NULL );
    component->Listen( component, idnet2exexNOnWifiScanWifiDevicesCompleted, stub_plfapiinfra_net2exexN_OnWifiScanWifiDevicesCompleted, NULL );
    component->Listen( component, idnet2exexNOnWifiSignalFound, stub_plfapiinfra_net2exexN_OnWifiSignalFound, NULL );
    component->Listen( component, idnet2exexNOnWifiSignalLost, stub_plfapiinfra_net2exexN_OnWifiSignalLost, NULL );
    component->Listen( component, idnet2exexNOnWpsConnectionFinished, stub_plfapiinfra_net2exexN_OnWpsConnectionFinished, NULL );
}
void plfapiinfra_EnableNotification_net2exN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idnet2exNOnDnsStatusChecked, stub_plfapiinfra_net2exN_OnDnsStatusChecked, NULL );
    component->Listen( component, idnet2exNOnInitializationDone, stub_plfapiinfra_net2exN_OnInitializationDone, NULL );
    component->Listen( component, idnet2exNOnNetworkInterfaceConfigStatusChanged, stub_plfapiinfra_net2exN_OnNetworkInterfaceConfigStatusChanged, NULL );
    component->Listen( component, idnet2exNOnNetworkInterfacePhysicalStatusChanged, stub_plfapiinfra_net2exN_OnNetworkInterfacePhysicalStatusChanged, NULL );
    component->Listen( component, idnet2exNOnWifiManualSsidFound, stub_plfapiinfra_net2exN_OnWifiManualSsidFound, NULL );
    component->Listen( component, idnet2exNOnWifiScanWifiDevicesCompleted, stub_plfapiinfra_net2exN_OnWifiScanWifiDevicesCompleted, NULL );
    component->Listen( component, idnet2exNOnWifiSignalFound, stub_plfapiinfra_net2exN_OnWifiSignalFound, NULL );
    component->Listen( component, idnet2exNOnWifiSignalLost, stub_plfapiinfra_net2exN_OnWifiSignalLost, NULL );
}
void plfapiinfra_EnableNotification_net2N(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idnet2NOnDnsStatusChecked, stub_plfapiinfra_net2N_OnDnsStatusChecked, NULL );
    component->Listen( component, idnet2NOnInitializationDone, stub_plfapiinfra_net2N_OnInitializationDone, NULL );
    component->Listen( component, idnet2NOnNetworkInterfaceConfigStatusChanged, stub_plfapiinfra_net2N_OnNetworkInterfaceConfigStatusChanged, NULL );
    component->Listen( component, idnet2NOnNetworkInterfacePhysicalStatusChanged, stub_plfapiinfra_net2N_OnNetworkInterfacePhysicalStatusChanged, NULL );
    component->Listen( component, idnet2NOnWifiManualSsidFound, stub_plfapiinfra_net2N_OnWifiManualSsidFound, NULL );
    component->Listen( component, idnet2NOnWifiSignalFound, stub_plfapiinfra_net2N_OnWifiSignalFound, NULL );
    component->Listen( component, idnet2NOnWifiSignalLost, stub_plfapiinfra_net2N_OnWifiSignalLost, NULL );
}
void plfapiinfra_EnableNotification_netexexN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idnetexexNOnDnsStatusChecked, stub_plfapiinfra_netexexN_OnDnsStatusChecked, NULL );
    component->Listen( component, idnetexexNOnIpConfigurationConflict, stub_plfapiinfra_netexexN_OnIpConfigurationConflict, NULL );
    component->Listen( component, idnetexexNOnNetworkInterfaceConfigStatusChanged, stub_plfapiinfra_netexexN_OnNetworkInterfaceConfigStatusChanged, NULL );
    component->Listen( component, idnetexexNOnNetworkInterfacePhysicalStatusChanged, stub_plfapiinfra_netexexN_OnNetworkInterfacePhysicalStatusChanged, NULL );
    component->Listen( component, idnetexexNOnSelectedWifiDeviceDisappeared, stub_plfapiinfra_netexexN_OnSelectedWifiDeviceDisappeared, NULL );
    component->Listen( component, idnetexexNOnWifiSelectionCompleted, stub_plfapiinfra_netexexN_OnWifiSelectionCompleted, NULL );
}
void plfapiinfra_EnableNotification_netexN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idnetexNOnDnsStatusChecked, stub_plfapiinfra_netexN_OnDnsStatusChecked, NULL );
    component->Listen( component, idnetexNOnIpConfigurationConflict, stub_plfapiinfra_netexN_OnIpConfigurationConflict, NULL );
    component->Listen( component, idnetexNOnNetworkInterfaceConfigStatusChanged, stub_plfapiinfra_netexN_OnNetworkInterfaceConfigStatusChanged, NULL );
    component->Listen( component, idnetexNOnNetworkInterfacePhysicalStatusChanged, stub_plfapiinfra_netexN_OnNetworkInterfacePhysicalStatusChanged, NULL );
}
void plfapiinfra_EnableNotification_netN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idnetNOnIpConfigurationConflict, stub_plfapiinfra_netN_OnIpConfigurationConflict, NULL );
    component->Listen( component, idnetNOnNetworkInterfaceConfigStatusChanged, stub_plfapiinfra_netN_OnNetworkInterfaceConfigStatusChanged, NULL );
    component->Listen( component, idnetNOnNetworkInterfacePhysicalStatusChanged, stub_plfapiinfra_netN_OnNetworkInterfacePhysicalStatusChanged, NULL );
}
void plfapiinfra_EnableNotification_p2pac(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idp2pacWriteASync, stub_plfapiinfra_p2pac_WriteASync, NULL );
    component->Listen( component, idp2pacWriteASyncNoRetry, stub_plfapiinfra_p2pac_WriteASyncNoRetry, NULL );
    component->Listen( component, idp2pacWriteNoSync, stub_plfapiinfra_p2pac_WriteNoSync, NULL );
    component->Listen( component, idp2pacWriteNoSyncNoRetry, stub_plfapiinfra_p2pac_WriteNoSyncNoRetry, NULL );
}
void plfapiinfra_EnableNotification_p2pacx(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idp2pacxWriteASync, stub_plfapiinfra_p2pacx_WriteASync, NULL );
    component->Listen( component, idp2pacxWriteASyncNoRetry, stub_plfapiinfra_p2pacx_WriteASyncNoRetry, NULL );
    component->Listen( component, idp2pacxWriteCharASync, stub_plfapiinfra_p2pacx_WriteCharASync, NULL );
    component->Listen( component, idp2pacxWriteCharASyncNoRetry, stub_plfapiinfra_p2pacx_WriteCharASyncNoRetry, NULL );
    component->Listen( component, idp2pacxWriteCharNoSync, stub_plfapiinfra_p2pacx_WriteCharNoSync, NULL );
    component->Listen( component, idp2pacxWriteCharNoSyncNoRetry, stub_plfapiinfra_p2pacx_WriteCharNoSyncNoRetry, NULL );
    component->Listen( component, idp2pacxWriteNoSync, stub_plfapiinfra_p2pacx_WriteNoSync, NULL );
    component->Listen( component, idp2pacxWriteNoSyncNoRetry, stub_plfapiinfra_p2pacx_WriteNoSyncNoRetry, NULL );
}
void plfapiinfra_EnableNotification_p2pahN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idp2pahNOnExecutionCompleted, stub_plfapiinfra_p2pahN_OnExecutionCompleted, NULL );
    component->Listen( component, idp2pahNOnTransmissionCompleted, stub_plfapiinfra_p2pahN_OnTransmissionCompleted, NULL );
}
void plfapiinfra_EnableNotification_upgtoolN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idupgtoolNOnProgrammingMessage, stub_plfapiinfra_upgtoolN_OnProgrammingMessage, NULL );
    component->Listen( component, idupgtoolNOnUpgradeLoaded, stub_plfapiinfra_upgtoolN_OnUpgradeLoaded, NULL );
    component->Listen( component, idupgtoolNOnUpgradeProgrammed, stub_plfapiinfra_upgtoolN_OnUpgradeProgrammed, NULL );
    component->Listen( component, idupgtoolNOnUpgradeValidated, stub_plfapiinfra_upgtoolN_OnUpgradeValidated, NULL );
}
void plfapiinfra_EnableNotification_usbdevexN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idusbdevexNOnDeviceError, stub_plfapiinfra_usbdevexN_OnDeviceError, NULL );
    component->Listen( component, idusbdevexNOnDeviceInfoChanged, stub_plfapiinfra_usbdevexN_OnDeviceInfoChanged, NULL );
    component->Listen( component, idusbdevexNOnDeviceRemoved, stub_plfapiinfra_usbdevexN_OnDeviceRemoved, NULL );
    component->Listen( component, idusbdevexNOnDriveMounted, stub_plfapiinfra_usbdevexN_OnDriveMounted, NULL );
    component->Listen( component, idusbdevexNOnDriveUnmounted, stub_plfapiinfra_usbdevexN_OnDriveUnmounted, NULL );
    component->Listen( component, idusbdevexNOnInitializationDone, stub_plfapiinfra_usbdevexN_OnInitializationDone, NULL );
    component->Listen( component, idusbdevexNOnNewDevice, stub_plfapiinfra_usbdevexN_OnNewDevice, NULL );
    component->Listen( component, idusbdevexNOnPhysicalDeviceConnected, stub_plfapiinfra_usbdevexN_OnPhysicalDeviceConnected, NULL );
    component->Listen( component, idusbdevexNOnPhysicalDeviceDisconnected, stub_plfapiinfra_usbdevexN_OnPhysicalDeviceDisconnected, NULL );
}
void plfapiinfra_EnableNotification_usbdevN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idusbdevNOnDeviceError, stub_plfapiinfra_usbdevN_OnDeviceError, NULL );
    component->Listen( component, idusbdevNOnDeviceInfoChanged, stub_plfapiinfra_usbdevN_OnDeviceInfoChanged, NULL );
    component->Listen( component, idusbdevNOnDeviceRemoved, stub_plfapiinfra_usbdevN_OnDeviceRemoved, NULL );
    component->Listen( component, idusbdevNOnDriveMounted, stub_plfapiinfra_usbdevN_OnDriveMounted, NULL );
    component->Listen( component, idusbdevNOnDriveUnmounted, stub_plfapiinfra_usbdevN_OnDriveUnmounted, NULL );
    component->Listen( component, idusbdevNOnNewDevice, stub_plfapiinfra_usbdevN_OnNewDevice, NULL );
    component->Listen( component, idusbdevNOnPhysicalDeviceConnected, stub_plfapiinfra_usbdevN_OnPhysicalDeviceConnected, NULL );
    component->Listen( component, idusbdevNOnPhysicalDeviceDisconnected, stub_plfapiinfra_usbdevN_OnPhysicalDeviceDisconnected, NULL );
}
void plfapiinfra_EnableNotification_vidstorN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idvidstorNOnInitialisationDone, stub_plfapiinfra_vidstorN_OnInitialisationDone, NULL );
    component->Listen( component, idvidstorNOnSDCardFormatProgress, stub_plfapiinfra_vidstorN_OnSDCardFormatProgress, NULL );
    component->Listen( component, idvidstorNOnSDCardFormatted, stub_plfapiinfra_vidstorN_OnSDCardFormatted, NULL );
    component->Listen( component, idvidstorNOnSDCardInserted, stub_plfapiinfra_vidstorN_OnSDCardInserted, NULL );
    component->Listen( component, idvidstorNOnSDCardMounted, stub_plfapiinfra_vidstorN_OnSDCardMounted, NULL );
    component->Listen( component, idvidstorNOnSDCardMountFailed, stub_plfapiinfra_vidstorN_OnSDCardMountFailed, NULL );
    component->Listen( component, idvidstorNOnSDCardRemoved, stub_plfapiinfra_vidstorN_OnSDCardRemoved, NULL );
    component->Listen( component, idvidstorNOnSDCardUnmounted, stub_plfapiinfra_vidstorN_OnSDCardUnmounted, NULL );
    component->Listen( component, idvidstorNOnSDCardUnmountFailed, stub_plfapiinfra_vidstorN_OnSDCardUnmountFailed, NULL );
}

void plfapiinfra_DisableNotification_cecrxntf(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idcecrxntfOnReceived );
}
void plfapiinfra_DisableNotification_cectxntf(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idcectxntfOnTransmitCompleted );
}
void plfapiinfra_DisableNotification_clkntf(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idclkntfOnAlarm );
    component->Unlisten( component, idclkntfOnClockChanged );
}
void plfapiinfra_DisableNotification_clkntfx(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idclkntfxOnAlarm );
    component->Unlisten( component, idclkntfxOnAlarmCancelled );
    component->Unlisten( component, idclkntfxOnClockChanged );
}
void plfapiinfra_DisableNotification_fopsN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idfopsNOnPartitionMounted );
    component->Unlisten( component, idfopsNOnPartitionMountFailed );
    component->Unlisten( component, idfopsNOnPartitionUnmounted );
}
void plfapiinfra_DisableNotification_infraitfN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idinfraitfNOnAvailabilityChanged );
}
void plfapiinfra_DisableNotification_net2exexN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idnet2exexNOnDnsStatusChecked );
    component->Unlisten( component, idnet2exexNOnInitializationDone );
    component->Unlisten( component, idnet2exexNOnNetworkInterfaceConfigStatusChanged );
    component->Unlisten( component, idnet2exexNOnNetworkInterfacePhysicalStatusChanged );
    component->Unlisten( component, idnet2exexNOnWifiManualSsidFound );
    component->Unlisten( component, idnet2exexNOnWifiScanWifiDevicesCompleted );
    component->Unlisten( component, idnet2exexNOnWifiSignalFound );
    component->Unlisten( component, idnet2exexNOnWifiSignalLost );
    component->Unlisten( component, idnet2exexNOnWpsConnectionFinished );
}
void plfapiinfra_DisableNotification_net2exN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idnet2exNOnDnsStatusChecked );
    component->Unlisten( component, idnet2exNOnInitializationDone );
    component->Unlisten( component, idnet2exNOnNetworkInterfaceConfigStatusChanged );
    component->Unlisten( component, idnet2exNOnNetworkInterfacePhysicalStatusChanged );
    component->Unlisten( component, idnet2exNOnWifiManualSsidFound );
    component->Unlisten( component, idnet2exNOnWifiScanWifiDevicesCompleted );
    component->Unlisten( component, idnet2exNOnWifiSignalFound );
    component->Unlisten( component, idnet2exNOnWifiSignalLost );
}
void plfapiinfra_DisableNotification_net2N(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idnet2NOnDnsStatusChecked );
    component->Unlisten( component, idnet2NOnInitializationDone );
    component->Unlisten( component, idnet2NOnNetworkInterfaceConfigStatusChanged );
    component->Unlisten( component, idnet2NOnNetworkInterfacePhysicalStatusChanged );
    component->Unlisten( component, idnet2NOnWifiManualSsidFound );
    component->Unlisten( component, idnet2NOnWifiSignalFound );
    component->Unlisten( component, idnet2NOnWifiSignalLost );
}
void plfapiinfra_DisableNotification_netexexN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idnetexexNOnDnsStatusChecked );
    component->Unlisten( component, idnetexexNOnIpConfigurationConflict );
    component->Unlisten( component, idnetexexNOnNetworkInterfaceConfigStatusChanged );
    component->Unlisten( component, idnetexexNOnNetworkInterfacePhysicalStatusChanged );
    component->Unlisten( component, idnetexexNOnSelectedWifiDeviceDisappeared );
    component->Unlisten( component, idnetexexNOnWifiSelectionCompleted );
}
void plfapiinfra_DisableNotification_netexN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idnetexNOnDnsStatusChecked );
    component->Unlisten( component, idnetexNOnIpConfigurationConflict );
    component->Unlisten( component, idnetexNOnNetworkInterfaceConfigStatusChanged );
    component->Unlisten( component, idnetexNOnNetworkInterfacePhysicalStatusChanged );
}
void plfapiinfra_DisableNotification_netN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idnetNOnIpConfigurationConflict );
    component->Unlisten( component, idnetNOnNetworkInterfaceConfigStatusChanged );
    component->Unlisten( component, idnetNOnNetworkInterfacePhysicalStatusChanged );
}
void plfapiinfra_DisableNotification_p2pac(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idp2pacWriteASync );
    component->Unlisten( component, idp2pacWriteASyncNoRetry );
    component->Unlisten( component, idp2pacWriteNoSync );
    component->Unlisten( component, idp2pacWriteNoSyncNoRetry );
}
void plfapiinfra_DisableNotification_p2pacx(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idp2pacxWriteASync );
    component->Unlisten( component, idp2pacxWriteASyncNoRetry );
    component->Unlisten( component, idp2pacxWriteCharASync );
    component->Unlisten( component, idp2pacxWriteCharASyncNoRetry );
    component->Unlisten( component, idp2pacxWriteCharNoSync );
    component->Unlisten( component, idp2pacxWriteCharNoSyncNoRetry );
    component->Unlisten( component, idp2pacxWriteNoSync );
    component->Unlisten( component, idp2pacxWriteNoSyncNoRetry );
}
void plfapiinfra_DisableNotification_p2pahN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idp2pahNOnExecutionCompleted );
    component->Unlisten( component, idp2pahNOnTransmissionCompleted );
}
void plfapiinfra_DisableNotification_upgtoolN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idupgtoolNOnProgrammingMessage );
    component->Unlisten( component, idupgtoolNOnUpgradeLoaded );
    component->Unlisten( component, idupgtoolNOnUpgradeProgrammed );
    component->Unlisten( component, idupgtoolNOnUpgradeValidated );
}
void plfapiinfra_DisableNotification_usbdevexN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idusbdevexNOnDeviceError );
    component->Unlisten( component, idusbdevexNOnDeviceInfoChanged );
    component->Unlisten( component, idusbdevexNOnDeviceRemoved );
    component->Unlisten( component, idusbdevexNOnDriveMounted );
    component->Unlisten( component, idusbdevexNOnDriveUnmounted );
    component->Unlisten( component, idusbdevexNOnInitializationDone );
    component->Unlisten( component, idusbdevexNOnNewDevice );
    component->Unlisten( component, idusbdevexNOnPhysicalDeviceConnected );
    component->Unlisten( component, idusbdevexNOnPhysicalDeviceDisconnected );
}
void plfapiinfra_DisableNotification_usbdevN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idusbdevNOnDeviceError );
    component->Unlisten( component, idusbdevNOnDeviceInfoChanged );
    component->Unlisten( component, idusbdevNOnDeviceRemoved );
    component->Unlisten( component, idusbdevNOnDriveMounted );
    component->Unlisten( component, idusbdevNOnDriveUnmounted );
    component->Unlisten( component, idusbdevNOnNewDevice );
    component->Unlisten( component, idusbdevNOnPhysicalDeviceConnected );
    component->Unlisten( component, idusbdevNOnPhysicalDeviceDisconnected );
}
void plfapiinfra_DisableNotification_vidstorN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idvidstorNOnInitialisationDone );
    component->Unlisten( component, idvidstorNOnSDCardFormatProgress );
    component->Unlisten( component, idvidstorNOnSDCardFormatted );
    component->Unlisten( component, idvidstorNOnSDCardInserted );
    component->Unlisten( component, idvidstorNOnSDCardMounted );
    component->Unlisten( component, idvidstorNOnSDCardMountFailed );
    component->Unlisten( component, idvidstorNOnSDCardRemoved );
    component->Unlisten( component, idvidstorNOnSDCardUnmounted );
    component->Unlisten( component, idvidstorNOnSDCardUnmountFailed );
}

extern void plfapiinfra_EnableNotification( int notificationID )
{
    if ( NULL==component )
        return;
    if ( (notificationID < 0) || ( notificationID >= plfapiinfraNotificationID_Last ) )
        return;
#ifndef NO_PLFAPIINFRA_LISTENER_STUBS
    component->Listen( component, notificationID, plfapiinfra_listener_stubs[notificationID], NULL );
#endif    
}

extern void plfapiinfra_DisableNotification( int notificationID )
{
    if ( NULL==component )
        return;
    if ( (notificationID < 0) || ( notificationID >= plfapiinfraNotificationID_Last ) )
        return;
    component->Unlisten( component, notificationID );
}

extern int plfapiinfra_Init( int argc, char *argv[] )
{
    DirectResult  ret;
    
    // dfb_config_init( &argc, &argv[] );	// Is this one needed?
    ret = FusionDaleInit( &argc, &argv );
    if (ret)
    {
        D_DERROR( ret, "[plfapiinfra-client] FusionDaleInit() failed!\n" );
        return -1;
    }
    ret = FusionDaleCreate( &dale );
    if (ret) {
        D_DERROR( ret, "[plfapiinfra-client] FusionDaleCreate() failed!\n" );
        return -2;
    }
    ret = dale->EnterComa( dale, "IPC_plfapiinfra", &coma );
    if (ret) {
        D_DERROR( ret, "[plfapiinfra-client] IFusionDale::EnterComa('IPC_plfapiinfra') failed!\n" );
        return -3;
    }
    ret = coma->GetComponent( coma, "CPlatformApiInfrastructure", 0, &component );
    if (ret) {
        D_DERROR( ret, "[plfapiinfra-client] IComa::GetComponent('CPlatformApiInfrastructure') failed!\n" );
        return -4;
    }
	return 0;
}

extern void plfapiinfra_Exit( void )
{
    component->Release( component );
    component = NULL;
    coma->Release( coma );
    coma = NULL;
    dale->Release( dale );
    dale = NULL;
}
