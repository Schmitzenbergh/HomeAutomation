
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


#include "plfapiconn.h"
#include "plfapiconn_internal.h"

#include "string.h"
#include "stdio.h"
#include "direct/messages.h"
#include "fusiondale.h"

static IFusionDale     *dale      = NULL;
static IComa           *coma      = NULL;
static IComaComponent  *component = NULL;

/* Hooks: variables */
static IpcHookFunction plfapiconn_hookGlobal = NULL;
static IpcHookFunction plfapiconn_hook_cmdmx = NULL;
static IpcHookFunction plfapiconn_hook_connitf = NULL;
static IpcHookFunction plfapiconn_hook_connitfid = NULL;
static IpcHookFunction plfapiconn_hook_dcf = NULL;
static IpcHookFunction plfapiconn_hook_errid = NULL;
static IpcHookFunction plfapiconn_hook_imgdec = NULL;
static IpcHookFunction plfapiconn_hook_md = NULL;
static IpcHookFunction plfapiconn_hook_netschemecfg = NULL;
static IpcHookFunction plfapiconn_hook_urlsrcjpg = NULL;
static IpcHookFunction plfapiconn_hook_urlsrcmp3 = NULL;
static IpcHookFunction plfapiconn_hook_urlsrcvid = NULL;
static IpcHookFunction plfapiconn_hook_cmdmxN = NULL;
static IpcHookFunction plfapiconn_hook_connitfN = NULL;
static IpcHookFunction plfapiconn_hook_digadecN = NULL;
static IpcHookFunction plfapiconn_hook_digvdecN = NULL;
static IpcHookFunction plfapiconn_hook_imgdecN = NULL;
static IpcHookFunction plfapiconn_hook_mdN = NULL;
static IpcHookFunction plfapiconn_hook_urlsrcjpgN = NULL;
static IpcHookFunction plfapiconn_hook_urlsrcmp3N = NULL;
static IpcHookFunction plfapiconn_hook_urlsrcvidN = NULL;

/* Hooks: Implementations */
void plfapiconn_RegisterHookGlobal( IpcHookFunction callback )
{
    plfapiconn_hookGlobal = callback;
}

/*  The following function is for the Koala wrapper only */
extern void plfapiconn_Hook_CallPosted( unsigned int id, void *data )
{
    if (plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDecoupled, id, data );
    }
}

/* HookType: ipchtCallReceived, ipchtCallHandled */
void plfapiconn_RegisterHook_cmdmx( IpcHookFunction callback )
{
    plfapiconn_hook_cmdmx = callback;
}

void plfapiconn_RegisterHook_connitf( IpcHookFunction callback )
{
    plfapiconn_hook_connitf = callback;
}

void plfapiconn_RegisterHook_connitfid( IpcHookFunction callback )
{
    plfapiconn_hook_connitfid = callback;
}

void plfapiconn_RegisterHook_dcf( IpcHookFunction callback )
{
    plfapiconn_hook_dcf = callback;
}

void plfapiconn_RegisterHook_errid( IpcHookFunction callback )
{
    plfapiconn_hook_errid = callback;
}

void plfapiconn_RegisterHook_imgdec( IpcHookFunction callback )
{
    plfapiconn_hook_imgdec = callback;
}

void plfapiconn_RegisterHook_md( IpcHookFunction callback )
{
    plfapiconn_hook_md = callback;
}

void plfapiconn_RegisterHook_netschemecfg( IpcHookFunction callback )
{
    plfapiconn_hook_netschemecfg = callback;
}

void plfapiconn_RegisterHook_urlsrcjpg( IpcHookFunction callback )
{
    plfapiconn_hook_urlsrcjpg = callback;
}

void plfapiconn_RegisterHook_urlsrcmp3( IpcHookFunction callback )
{
    plfapiconn_hook_urlsrcmp3 = callback;
}

void plfapiconn_RegisterHook_urlsrcvid( IpcHookFunction callback )
{
    plfapiconn_hook_urlsrcvid = callback;
}

/* HookType: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
void plfapiconn_RegisterHook_cmdmxN( IpcHookFunction callback )
{
    plfapiconn_hook_cmdmxN = callback;
}

void plfapiconn_RegisterHook_connitfN( IpcHookFunction callback )
{
    plfapiconn_hook_connitfN = callback;
}

void plfapiconn_RegisterHook_digadecN( IpcHookFunction callback )
{
    plfapiconn_hook_digadecN = callback;
}

void plfapiconn_RegisterHook_digvdecN( IpcHookFunction callback )
{
    plfapiconn_hook_digvdecN = callback;
}

void plfapiconn_RegisterHook_imgdecN( IpcHookFunction callback )
{
    plfapiconn_hook_imgdecN = callback;
}

void plfapiconn_RegisterHook_mdN( IpcHookFunction callback )
{
    plfapiconn_hook_mdN = callback;
}

void plfapiconn_RegisterHook_urlsrcjpgN( IpcHookFunction callback )
{
    plfapiconn_hook_urlsrcjpgN = callback;
}

void plfapiconn_RegisterHook_urlsrcmp3N( IpcHookFunction callback )
{
    plfapiconn_hook_urlsrcmp3N = callback;
}

void plfapiconn_RegisterHook_urlsrcvidN( IpcHookFunction callback )
{
    plfapiconn_hook_urlsrcvidN = callback;
}

#if defined(USE_WEAK_NOTIFICATIONS)
void plfapiconn_cmdmxN_OnBufferFull( void ) WEAK;
void plfapiconn_cmdmxN_OnDataArrived( Nat32 dataCookie, Nat32 primaryDataSize, tmCmDmx_Buffer_t PrimaryDataStartAddress, Nat32 secondaryDataSize, tmCmDmx_Buffer_t SecondaryDataStartAddress ) WEAK;
void plfapiconn_cmdmxN_OnSystemBitRateChanged( Nat32 bitRate ) WEAK;
void plfapiconn_connitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids ) WEAK;
void plfapiconn_digadecN_OnError( tmDigAdec_Error_t err ) WEAK;
void plfapiconn_digvdecN_OnError( tmDigVdec_Error_t err ) WEAK;
void plfapiconn_digvdecN_OnStandardDataChanged( tmDigVdec_CompressionStandard_t standard, tmDigVdec_Profile_t profile, tmDigVdec_Level_t level ) WEAK;
void plfapiconn_imgdecN_OnEndMetaData( void ) WEAK;
void plfapiconn_imgdecN_OnFullImageDecoded( tmImageDec2_Status_t status ) WEAK;
void plfapiconn_imgdecN_OnMetaDataFound( Nat32 size, tmImageDec_Buffer_t RawData ) WEAK;
void plfapiconn_imgdecN_OnResolutionObtained( tmImageDec2_Status_t status, Nat32 horRes, Nat32 vertRes ) WEAK;
void plfapiconn_imgdecN_OnThumbnailDecoded( tmImageDec2_Status_t status ) WEAK;
void plfapiconn_imgdecN_OnThumbnailPresence( tmImageDec2_Status_t status, Bool presence ) WEAK;
void plfapiconn_mdN_OnAvTypeNotify( int winid, Nat32 cookie, MediaDetect_Format_t * fmt ) WEAK;
void plfapiconn_urlsrcjpgN_OnAccessible( void ) WEAK;
void plfapiconn_urlsrcjpgN_OnActionAborted( void ) WEAK;
void plfapiconn_urlsrcjpgN_OnBufferingStatusChanged( tmUrlSrc_BufferingState_t bufferState ) WEAK;
void plfapiconn_urlsrcjpgN_OnConnectionRetry( void ) WEAK;
void plfapiconn_urlsrcjpgN_OnDataConsumed( Nat64 bytesConsumed ) WEAK;
void plfapiconn_urlsrcjpgN_OnEndOfInput( void ) WEAK;
void plfapiconn_urlsrcjpgN_OnEndOfRendering( void ) WEAK;
void plfapiconn_urlsrcjpgN_OnNotAccessible( tmUrlSrc_NotAccessibleCause_t cause ) WEAK;
void plfapiconn_urlsrcjpgN_OnPlayTimeChanged( Nat32 timePlayed ) WEAK;
void plfapiconn_urlsrcjpgN_OnSetPositionAborted( void ) WEAK;
void plfapiconn_urlsrcjpgN_OnSetPositionCompleted( Nat32 actualTime, Bool endOfStreamReached ) WEAK;
void plfapiconn_urlsrcjpgN_OnTrickControlLost( void ) WEAK;
void plfapiconn_urlsrcmp3N_OnAccessible( void ) WEAK;
void plfapiconn_urlsrcmp3N_OnActionAborted( void ) WEAK;
void plfapiconn_urlsrcmp3N_OnBufferingStatusChanged( tmUrlSrc_BufferingState_t bufferState ) WEAK;
void plfapiconn_urlsrcmp3N_OnConnectionRetry( void ) WEAK;
void plfapiconn_urlsrcmp3N_OnDataConsumed( Nat64 bytesConsumed ) WEAK;
void plfapiconn_urlsrcmp3N_OnEndOfInput( void ) WEAK;
void plfapiconn_urlsrcmp3N_OnEndOfRendering( void ) WEAK;
void plfapiconn_urlsrcmp3N_OnNotAccessible( tmUrlSrc_NotAccessibleCause_t cause ) WEAK;
void plfapiconn_urlsrcmp3N_OnPlayTimeChanged( Nat32 timePlayed ) WEAK;
void plfapiconn_urlsrcmp3N_OnSetPositionAborted( void ) WEAK;
void plfapiconn_urlsrcmp3N_OnSetPositionCompleted( Nat32 actualTime, Bool endOfStreamReached ) WEAK;
void plfapiconn_urlsrcmp3N_OnTrickControlLost( void ) WEAK;
void plfapiconn_urlsrcvidN_OnAccessible( void ) WEAK;
void plfapiconn_urlsrcvidN_OnActionAborted( void ) WEAK;
void plfapiconn_urlsrcvidN_OnBufferingStatusChanged( tmUrlSrc_BufferingState_t bufferState ) WEAK;
void plfapiconn_urlsrcvidN_OnConnectionRetry( void ) WEAK;
void plfapiconn_urlsrcvidN_OnDataConsumed( Nat64 bytesConsumed ) WEAK;
void plfapiconn_urlsrcvidN_OnEndOfInput( void ) WEAK;
void plfapiconn_urlsrcvidN_OnEndOfRendering( void ) WEAK;
void plfapiconn_urlsrcvidN_OnNotAccessible( tmUrlSrc_NotAccessibleCause_t cause ) WEAK;
void plfapiconn_urlsrcvidN_OnPlayTimeChanged( Nat32 timePlayed ) WEAK;
void plfapiconn_urlsrcvidN_OnSetPositionAborted( void ) WEAK;
void plfapiconn_urlsrcvidN_OnSetPositionCompleted( Nat32 actualTime, Bool endOfStreamReached ) WEAK;
void plfapiconn_urlsrcvidN_OnTrickControlLost( void ) WEAK;

void plfapiconn_cmdmxN_OnBufferFull( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 0, NULL );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationDiscarded, 0, NULL );
    }
    /* do nothing */
}

void plfapiconn_cmdmxN_OnDataArrived( Nat32 dataCookie, Nat32 primaryDataSize, tmCmDmx_Buffer_t PrimaryDataStartAddress, Nat32 secondaryDataSize, tmCmDmx_Buffer_t SecondaryDataStartAddress )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 1, NULL );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationDiscarded, 1, NULL );
    }
    /* do nothing */
    (void)dataCookie;
    (void)primaryDataSize;
    (void)PrimaryDataStartAddress;
    (void)secondaryDataSize;
    (void)SecondaryDataStartAddress;
}

void plfapiconn_cmdmxN_OnSystemBitRateChanged( Nat32 bitRate )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 2, NULL );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationDiscarded, 2, NULL );
    }
    /* do nothing */
    (void)bitRate;
}

void plfapiconn_connitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 3, NULL );
    }
    if ( plfapiconn_hook_connitfN )
    {
        (*plfapiconn_hook_connitfN)( ipchtNotificationDiscarded, 3, NULL );
    }
    /* do nothing */
    (void)nbrgroups;
    (void)ids;
}

void plfapiconn_digadecN_OnError( tmDigAdec_Error_t err )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 4, NULL );
    }
    if ( plfapiconn_hook_digadecN )
    {
        (*plfapiconn_hook_digadecN)( ipchtNotificationDiscarded, 4, NULL );
    }
    /* do nothing */
    (void)err;
}

void plfapiconn_digvdecN_OnError( tmDigVdec_Error_t err )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 5, NULL );
    }
    if ( plfapiconn_hook_digvdecN )
    {
        (*plfapiconn_hook_digvdecN)( ipchtNotificationDiscarded, 5, NULL );
    }
    /* do nothing */
    (void)err;
}

void plfapiconn_digvdecN_OnStandardDataChanged( tmDigVdec_CompressionStandard_t standard, tmDigVdec_Profile_t profile, tmDigVdec_Level_t level )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 6, NULL );
    }
    if ( plfapiconn_hook_digvdecN )
    {
        (*plfapiconn_hook_digvdecN)( ipchtNotificationDiscarded, 6, NULL );
    }
    /* do nothing */
    (void)standard;
    (void)profile;
    (void)level;
}

void plfapiconn_imgdecN_OnEndMetaData( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 7, NULL );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationDiscarded, 7, NULL );
    }
    /* do nothing */
}

void plfapiconn_imgdecN_OnFullImageDecoded( tmImageDec2_Status_t status )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 8, NULL );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationDiscarded, 8, NULL );
    }
    /* do nothing */
    (void)status;
}

void plfapiconn_imgdecN_OnMetaDataFound( Nat32 size, tmImageDec_Buffer_t RawData )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 9, NULL );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationDiscarded, 9, NULL );
    }
    /* do nothing */
    (void)size;
    (void)RawData;
}

void plfapiconn_imgdecN_OnResolutionObtained( tmImageDec2_Status_t status, Nat32 horRes, Nat32 vertRes )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 10, NULL );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationDiscarded, 10, NULL );
    }
    /* do nothing */
    (void)status;
    (void)horRes;
    (void)vertRes;
}

void plfapiconn_imgdecN_OnThumbnailDecoded( tmImageDec2_Status_t status )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 11, NULL );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationDiscarded, 11, NULL );
    }
    /* do nothing */
    (void)status;
}

void plfapiconn_imgdecN_OnThumbnailPresence( tmImageDec2_Status_t status, Bool presence )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 12, NULL );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationDiscarded, 12, NULL );
    }
    /* do nothing */
    (void)status;
    (void)presence;
}

void plfapiconn_mdN_OnAvTypeNotify( int winid, Nat32 cookie, MediaDetect_Format_t * fmt )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 13, NULL );
    }
    if ( plfapiconn_hook_mdN )
    {
        (*plfapiconn_hook_mdN)( ipchtNotificationDiscarded, 13, NULL );
    }
    /* do nothing */
    (void)winid;
    (void)cookie;
    (void)fmt;
}

void plfapiconn_urlsrcjpgN_OnAccessible( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 14, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 14, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcjpgN_OnActionAborted( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 15, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 15, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcjpgN_OnBufferingStatusChanged( tmUrlSrc_BufferingState_t bufferState )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 16, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 16, NULL );
    }
    /* do nothing */
    (void)bufferState;
}

void plfapiconn_urlsrcjpgN_OnConnectionRetry( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 17, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 17, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcjpgN_OnDataConsumed( Nat64 bytesConsumed )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 18, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 18, NULL );
    }
    /* do nothing */
    (void)bytesConsumed;
}

void plfapiconn_urlsrcjpgN_OnEndOfInput( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 19, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 19, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcjpgN_OnEndOfRendering( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 20, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 20, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcjpgN_OnNotAccessible( tmUrlSrc_NotAccessibleCause_t cause )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 21, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 21, NULL );
    }
    /* do nothing */
    (void)cause;
}

void plfapiconn_urlsrcjpgN_OnPlayTimeChanged( Nat32 timePlayed )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 22, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 22, NULL );
    }
    /* do nothing */
    (void)timePlayed;
}

void plfapiconn_urlsrcjpgN_OnSetPositionAborted( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 23, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 23, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcjpgN_OnSetPositionCompleted( Nat32 actualTime, Bool endOfStreamReached )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 24, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 24, NULL );
    }
    /* do nothing */
    (void)actualTime;
    (void)endOfStreamReached;
}

void plfapiconn_urlsrcjpgN_OnTrickControlLost( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 25, NULL );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationDiscarded, 25, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcmp3N_OnAccessible( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 26, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 26, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcmp3N_OnActionAborted( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 27, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 27, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcmp3N_OnBufferingStatusChanged( tmUrlSrc_BufferingState_t bufferState )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 28, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 28, NULL );
    }
    /* do nothing */
    (void)bufferState;
}

void plfapiconn_urlsrcmp3N_OnConnectionRetry( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 29, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 29, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcmp3N_OnDataConsumed( Nat64 bytesConsumed )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 30, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 30, NULL );
    }
    /* do nothing */
    (void)bytesConsumed;
}

void plfapiconn_urlsrcmp3N_OnEndOfInput( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 31, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 31, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcmp3N_OnEndOfRendering( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 32, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 32, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcmp3N_OnNotAccessible( tmUrlSrc_NotAccessibleCause_t cause )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 33, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 33, NULL );
    }
    /* do nothing */
    (void)cause;
}

void plfapiconn_urlsrcmp3N_OnPlayTimeChanged( Nat32 timePlayed )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 34, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 34, NULL );
    }
    /* do nothing */
    (void)timePlayed;
}

void plfapiconn_urlsrcmp3N_OnSetPositionAborted( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 35, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 35, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcmp3N_OnSetPositionCompleted( Nat32 actualTime, Bool endOfStreamReached )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 36, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 36, NULL );
    }
    /* do nothing */
    (void)actualTime;
    (void)endOfStreamReached;
}

void plfapiconn_urlsrcmp3N_OnTrickControlLost( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 37, NULL );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationDiscarded, 37, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcvidN_OnAccessible( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 38, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 38, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcvidN_OnActionAborted( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 39, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 39, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcvidN_OnBufferingStatusChanged( tmUrlSrc_BufferingState_t bufferState )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 40, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 40, NULL );
    }
    /* do nothing */
    (void)bufferState;
}

void plfapiconn_urlsrcvidN_OnConnectionRetry( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 41, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 41, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcvidN_OnDataConsumed( Nat64 bytesConsumed )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 42, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 42, NULL );
    }
    /* do nothing */
    (void)bytesConsumed;
}

void plfapiconn_urlsrcvidN_OnEndOfInput( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 43, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 43, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcvidN_OnEndOfRendering( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 44, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 44, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcvidN_OnNotAccessible( tmUrlSrc_NotAccessibleCause_t cause )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 45, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 45, NULL );
    }
    /* do nothing */
    (void)cause;
}

void plfapiconn_urlsrcvidN_OnPlayTimeChanged( Nat32 timePlayed )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 46, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 46, NULL );
    }
    /* do nothing */
    (void)timePlayed;
}

void plfapiconn_urlsrcvidN_OnSetPositionAborted( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 47, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 47, NULL );
    }
    /* do nothing */
}

void plfapiconn_urlsrcvidN_OnSetPositionCompleted( Nat32 actualTime, Bool endOfStreamReached )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 48, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 48, NULL );
    }
    /* do nothing */
    (void)actualTime;
    (void)endOfStreamReached;
}

void plfapiconn_urlsrcvidN_OnTrickControlLost( void )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationDiscarded, 49, NULL );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationDiscarded, 49, NULL );
    }
    /* do nothing */
}

#endif /* USE_WEAK_NOTIFICATIONS */

static void stub_plfapiconn_cmdmxN_OnBufferFull( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 0, arg );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationReceived, 0, arg );
    }
    (void)ctx;
    plfapiconn_cmdmxN_OnBufferFull();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 0, arg );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationHandled, 0, arg );
    }
    return;
}

static void stub_plfapiconn_cmdmxN_OnDataArrived( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 1, arg );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationReceived, 1, arg );
    }
    cmdmxNOnDataArrived * data = (cmdmxNOnDataArrived *)arg;
    (void)ctx;
    plfapiconn_cmdmxN_OnDataArrived( data->dataCookie, data->primaryDataSize, data->PrimaryDataStartAddress, data->secondaryDataSize, data->SecondaryDataStartAddress );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 1, arg );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationHandled, 1, arg );
    }
    return;
}

static void stub_plfapiconn_cmdmxN_OnSystemBitRateChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 2, arg );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationReceived, 2, arg );
    }
    cmdmxNOnSystemBitRateChanged * data = (cmdmxNOnSystemBitRateChanged *)arg;
    (void)ctx;
    plfapiconn_cmdmxN_OnSystemBitRateChanged( data->bitRate );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 2, arg );
    }
    if ( plfapiconn_hook_cmdmxN )
    {
        (*plfapiconn_hook_cmdmxN)( ipchtNotificationHandled, 2, arg );
    }
    return;
}

static void stub_plfapiconn_connitfN_OnAvailabilityChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 3, arg );
    }
    if ( plfapiconn_hook_connitfN )
    {
        (*plfapiconn_hook_connitfN)( ipchtNotificationReceived, 3, arg );
    }
    connitfNOnAvailabilityChanged * data = (connitfNOnAvailabilityChanged *)arg;
    (void)ctx;
    plfapiconn_connitfN_OnAvailabilityChanged( data->nbrgroups, (Nat32 *)data->ids );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 3, arg );
    }
    if ( plfapiconn_hook_connitfN )
    {
        (*plfapiconn_hook_connitfN)( ipchtNotificationHandled, 3, arg );
    }
    return;
}

static void stub_plfapiconn_digadecN_OnError( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 4, arg );
    }
    if ( plfapiconn_hook_digadecN )
    {
        (*plfapiconn_hook_digadecN)( ipchtNotificationReceived, 4, arg );
    }
    digadecNOnError * data = (digadecNOnError *)arg;
    (void)ctx;
    plfapiconn_digadecN_OnError( data->err );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 4, arg );
    }
    if ( plfapiconn_hook_digadecN )
    {
        (*plfapiconn_hook_digadecN)( ipchtNotificationHandled, 4, arg );
    }
    return;
}

static void stub_plfapiconn_digvdecN_OnError( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 5, arg );
    }
    if ( plfapiconn_hook_digvdecN )
    {
        (*plfapiconn_hook_digvdecN)( ipchtNotificationReceived, 5, arg );
    }
    digvdecNOnError * data = (digvdecNOnError *)arg;
    (void)ctx;
    plfapiconn_digvdecN_OnError( data->err );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 5, arg );
    }
    if ( plfapiconn_hook_digvdecN )
    {
        (*plfapiconn_hook_digvdecN)( ipchtNotificationHandled, 5, arg );
    }
    return;
}

static void stub_plfapiconn_digvdecN_OnStandardDataChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 6, arg );
    }
    if ( plfapiconn_hook_digvdecN )
    {
        (*plfapiconn_hook_digvdecN)( ipchtNotificationReceived, 6, arg );
    }
    digvdecNOnStandardDataChanged * data = (digvdecNOnStandardDataChanged *)arg;
    (void)ctx;
    plfapiconn_digvdecN_OnStandardDataChanged( data->standard, data->profile, data->level );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 6, arg );
    }
    if ( plfapiconn_hook_digvdecN )
    {
        (*plfapiconn_hook_digvdecN)( ipchtNotificationHandled, 6, arg );
    }
    return;
}

static void stub_plfapiconn_imgdecN_OnEndMetaData( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 7, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationReceived, 7, arg );
    }
    (void)ctx;
    plfapiconn_imgdecN_OnEndMetaData();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 7, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationHandled, 7, arg );
    }
    return;
}

static void stub_plfapiconn_imgdecN_OnFullImageDecoded( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 8, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationReceived, 8, arg );
    }
    imgdecNOnFullImageDecoded * data = (imgdecNOnFullImageDecoded *)arg;
    (void)ctx;
    plfapiconn_imgdecN_OnFullImageDecoded( data->status );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 8, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationHandled, 8, arg );
    }
    return;
}

static void stub_plfapiconn_imgdecN_OnMetaDataFound( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 9, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationReceived, 9, arg );
    }
    imgdecNOnMetaDataFound * data = (imgdecNOnMetaDataFound *)arg;
    (void)ctx;
    plfapiconn_imgdecN_OnMetaDataFound( data->size, data->RawData );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 9, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationHandled, 9, arg );
    }
    return;
}

static void stub_plfapiconn_imgdecN_OnResolutionObtained( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 10, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationReceived, 10, arg );
    }
    imgdecNOnResolutionObtained * data = (imgdecNOnResolutionObtained *)arg;
    (void)ctx;
    plfapiconn_imgdecN_OnResolutionObtained( data->status, data->horRes, data->vertRes );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 10, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationHandled, 10, arg );
    }
    return;
}

static void stub_plfapiconn_imgdecN_OnThumbnailDecoded( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 11, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationReceived, 11, arg );
    }
    imgdecNOnThumbnailDecoded * data = (imgdecNOnThumbnailDecoded *)arg;
    (void)ctx;
    plfapiconn_imgdecN_OnThumbnailDecoded( data->status );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 11, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationHandled, 11, arg );
    }
    return;
}

static void stub_plfapiconn_imgdecN_OnThumbnailPresence( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 12, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationReceived, 12, arg );
    }
    imgdecNOnThumbnailPresence * data = (imgdecNOnThumbnailPresence *)arg;
    (void)ctx;
    plfapiconn_imgdecN_OnThumbnailPresence( data->status, data->presence );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 12, arg );
    }
    if ( plfapiconn_hook_imgdecN )
    {
        (*plfapiconn_hook_imgdecN)( ipchtNotificationHandled, 12, arg );
    }
    return;
}

static void stub_plfapiconn_mdN_OnAvTypeNotify( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 13, arg );
    }
    if ( plfapiconn_hook_mdN )
    {
        (*plfapiconn_hook_mdN)( ipchtNotificationReceived, 13, arg );
    }
    mdNOnAvTypeNotify * data = (mdNOnAvTypeNotify *)arg;
    (void)ctx;
    plfapiconn_mdN_OnAvTypeNotify( data->winid, data->cookie, &data->fmt );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 13, arg );
    }
    if ( plfapiconn_hook_mdN )
    {
        (*plfapiconn_hook_mdN)( ipchtNotificationHandled, 13, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnAccessible( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 14, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 14, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnAccessible();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 14, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 14, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnActionAborted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 15, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 15, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnActionAborted();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 15, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 15, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnBufferingStatusChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 16, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 16, arg );
    }
    urlsrcjpgNOnBufferingStatusChanged * data = (urlsrcjpgNOnBufferingStatusChanged *)arg;
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnBufferingStatusChanged( data->bufferState );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 16, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 16, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnConnectionRetry( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 17, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 17, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnConnectionRetry();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 17, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 17, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnDataConsumed( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 18, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 18, arg );
    }
    urlsrcjpgNOnDataConsumed * data = (urlsrcjpgNOnDataConsumed *)arg;
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnDataConsumed( data->bytesConsumed );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 18, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 18, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnEndOfInput( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 19, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 19, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnEndOfInput();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 19, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 19, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnEndOfRendering( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 20, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 20, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnEndOfRendering();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 20, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 20, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnNotAccessible( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 21, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 21, arg );
    }
    urlsrcjpgNOnNotAccessible * data = (urlsrcjpgNOnNotAccessible *)arg;
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnNotAccessible( data->cause );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 21, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 21, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnPlayTimeChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 22, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 22, arg );
    }
    urlsrcjpgNOnPlayTimeChanged * data = (urlsrcjpgNOnPlayTimeChanged *)arg;
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnPlayTimeChanged( data->timePlayed );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 22, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 22, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnSetPositionAborted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 23, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 23, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnSetPositionAborted();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 23, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 23, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnSetPositionCompleted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 24, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 24, arg );
    }
    urlsrcjpgNOnSetPositionCompleted * data = (urlsrcjpgNOnSetPositionCompleted *)arg;
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnSetPositionCompleted( data->actualTime, data->endOfStreamReached );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 24, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 24, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcjpgN_OnTrickControlLost( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 25, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationReceived, 25, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcjpgN_OnTrickControlLost();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 25, arg );
    }
    if ( plfapiconn_hook_urlsrcjpgN )
    {
        (*plfapiconn_hook_urlsrcjpgN)( ipchtNotificationHandled, 25, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnAccessible( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 26, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 26, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnAccessible();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 26, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 26, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnActionAborted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 27, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 27, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnActionAborted();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 27, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 27, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnBufferingStatusChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 28, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 28, arg );
    }
    urlsrcmp3NOnBufferingStatusChanged * data = (urlsrcmp3NOnBufferingStatusChanged *)arg;
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnBufferingStatusChanged( data->bufferState );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 28, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 28, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnConnectionRetry( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 29, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 29, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnConnectionRetry();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 29, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 29, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnDataConsumed( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 30, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 30, arg );
    }
    urlsrcmp3NOnDataConsumed * data = (urlsrcmp3NOnDataConsumed *)arg;
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnDataConsumed( data->bytesConsumed );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 30, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 30, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnEndOfInput( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 31, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 31, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnEndOfInput();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 31, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 31, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnEndOfRendering( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 32, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 32, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnEndOfRendering();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 32, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 32, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnNotAccessible( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 33, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 33, arg );
    }
    urlsrcmp3NOnNotAccessible * data = (urlsrcmp3NOnNotAccessible *)arg;
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnNotAccessible( data->cause );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 33, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 33, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnPlayTimeChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 34, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 34, arg );
    }
    urlsrcmp3NOnPlayTimeChanged * data = (urlsrcmp3NOnPlayTimeChanged *)arg;
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnPlayTimeChanged( data->timePlayed );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 34, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 34, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnSetPositionAborted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 35, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 35, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnSetPositionAborted();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 35, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 35, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnSetPositionCompleted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 36, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 36, arg );
    }
    urlsrcmp3NOnSetPositionCompleted * data = (urlsrcmp3NOnSetPositionCompleted *)arg;
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnSetPositionCompleted( data->actualTime, data->endOfStreamReached );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 36, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 36, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcmp3N_OnTrickControlLost( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 37, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationReceived, 37, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcmp3N_OnTrickControlLost();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 37, arg );
    }
    if ( plfapiconn_hook_urlsrcmp3N )
    {
        (*plfapiconn_hook_urlsrcmp3N)( ipchtNotificationHandled, 37, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnAccessible( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 38, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 38, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcvidN_OnAccessible();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 38, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 38, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnActionAborted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 39, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 39, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcvidN_OnActionAborted();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 39, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 39, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnBufferingStatusChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 40, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 40, arg );
    }
    urlsrcvidNOnBufferingStatusChanged * data = (urlsrcvidNOnBufferingStatusChanged *)arg;
    (void)ctx;
    plfapiconn_urlsrcvidN_OnBufferingStatusChanged( data->bufferState );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 40, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 40, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnConnectionRetry( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 41, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 41, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcvidN_OnConnectionRetry();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 41, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 41, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnDataConsumed( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 42, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 42, arg );
    }
    urlsrcvidNOnDataConsumed * data = (urlsrcvidNOnDataConsumed *)arg;
    (void)ctx;
    plfapiconn_urlsrcvidN_OnDataConsumed( data->bytesConsumed );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 42, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 42, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnEndOfInput( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 43, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 43, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcvidN_OnEndOfInput();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 43, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 43, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnEndOfRendering( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 44, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 44, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcvidN_OnEndOfRendering();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 44, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 44, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnNotAccessible( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 45, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 45, arg );
    }
    urlsrcvidNOnNotAccessible * data = (urlsrcvidNOnNotAccessible *)arg;
    (void)ctx;
    plfapiconn_urlsrcvidN_OnNotAccessible( data->cause );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 45, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 45, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnPlayTimeChanged( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 46, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 46, arg );
    }
    urlsrcvidNOnPlayTimeChanged * data = (urlsrcvidNOnPlayTimeChanged *)arg;
    (void)ctx;
    plfapiconn_urlsrcvidN_OnPlayTimeChanged( data->timePlayed );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 46, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 46, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnSetPositionAborted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 47, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 47, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcvidN_OnSetPositionAborted();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 47, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 47, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnSetPositionCompleted( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 48, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 48, arg );
    }
    urlsrcvidNOnSetPositionCompleted * data = (urlsrcvidNOnSetPositionCompleted *)arg;
    (void)ctx;
    plfapiconn_urlsrcvidN_OnSetPositionCompleted( data->actualTime, data->endOfStreamReached );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 48, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 48, arg );
    }
    return;
}

static void stub_plfapiconn_urlsrcvidN_OnTrickControlLost( void *ctx, void *arg )
{
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationReceived, 49, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationReceived, 49, arg );
    }
    (void)ctx;
    plfapiconn_urlsrcvidN_OnTrickControlLost();
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtNotificationHandled, 49, arg );
    }
    if ( plfapiconn_hook_urlsrcvidN )
    {
        (*plfapiconn_hook_urlsrcvidN)( ipchtNotificationHandled, 49, arg );
    }
    return;
}


static ComaListenerFunc plfapiconn_listener_stubs[] = {
     stub_plfapiconn_cmdmxN_OnBufferFull
    ,stub_plfapiconn_cmdmxN_OnDataArrived
    ,stub_plfapiconn_cmdmxN_OnSystemBitRateChanged
    ,stub_plfapiconn_connitfN_OnAvailabilityChanged
    ,stub_plfapiconn_digadecN_OnError
    ,stub_plfapiconn_digvdecN_OnError
    ,stub_plfapiconn_digvdecN_OnStandardDataChanged
    ,stub_plfapiconn_imgdecN_OnEndMetaData
    ,stub_plfapiconn_imgdecN_OnFullImageDecoded
    ,stub_plfapiconn_imgdecN_OnMetaDataFound
    ,stub_plfapiconn_imgdecN_OnResolutionObtained
    ,stub_plfapiconn_imgdecN_OnThumbnailDecoded
    ,stub_plfapiconn_imgdecN_OnThumbnailPresence
    ,stub_plfapiconn_mdN_OnAvTypeNotify
    ,stub_plfapiconn_urlsrcjpgN_OnAccessible
    ,stub_plfapiconn_urlsrcjpgN_OnActionAborted
    ,stub_plfapiconn_urlsrcjpgN_OnBufferingStatusChanged
    ,stub_plfapiconn_urlsrcjpgN_OnConnectionRetry
    ,stub_plfapiconn_urlsrcjpgN_OnDataConsumed
    ,stub_plfapiconn_urlsrcjpgN_OnEndOfInput
    ,stub_plfapiconn_urlsrcjpgN_OnEndOfRendering
    ,stub_plfapiconn_urlsrcjpgN_OnNotAccessible
    ,stub_plfapiconn_urlsrcjpgN_OnPlayTimeChanged
    ,stub_plfapiconn_urlsrcjpgN_OnSetPositionAborted
    ,stub_plfapiconn_urlsrcjpgN_OnSetPositionCompleted
    ,stub_plfapiconn_urlsrcjpgN_OnTrickControlLost
    ,stub_plfapiconn_urlsrcmp3N_OnAccessible
    ,stub_plfapiconn_urlsrcmp3N_OnActionAborted
    ,stub_plfapiconn_urlsrcmp3N_OnBufferingStatusChanged
    ,stub_plfapiconn_urlsrcmp3N_OnConnectionRetry
    ,stub_plfapiconn_urlsrcmp3N_OnDataConsumed
    ,stub_plfapiconn_urlsrcmp3N_OnEndOfInput
    ,stub_plfapiconn_urlsrcmp3N_OnEndOfRendering
    ,stub_plfapiconn_urlsrcmp3N_OnNotAccessible
    ,stub_plfapiconn_urlsrcmp3N_OnPlayTimeChanged
    ,stub_plfapiconn_urlsrcmp3N_OnSetPositionAborted
    ,stub_plfapiconn_urlsrcmp3N_OnSetPositionCompleted
    ,stub_plfapiconn_urlsrcmp3N_OnTrickControlLost
    ,stub_plfapiconn_urlsrcvidN_OnAccessible
    ,stub_plfapiconn_urlsrcvidN_OnActionAborted
    ,stub_plfapiconn_urlsrcvidN_OnBufferingStatusChanged
    ,stub_plfapiconn_urlsrcvidN_OnConnectionRetry
    ,stub_plfapiconn_urlsrcvidN_OnDataConsumed
    ,stub_plfapiconn_urlsrcvidN_OnEndOfInput
    ,stub_plfapiconn_urlsrcvidN_OnEndOfRendering
    ,stub_plfapiconn_urlsrcvidN_OnNotAccessible
    ,stub_plfapiconn_urlsrcvidN_OnPlayTimeChanged
    ,stub_plfapiconn_urlsrcvidN_OnSetPositionAborted
    ,stub_plfapiconn_urlsrcvidN_OnSetPositionCompleted
    ,stub_plfapiconn_urlsrcvidN_OnTrickControlLost
};

extern FResult plfapiconn_cmdmx_AllocateClientStream( int winid, int * streamid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxAllocateClientStream *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxAllocateClientStream );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 0, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 0, data );
    }
    component->Call( component, idcmdmxAllocateClientStream, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 0, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 0, data );
    }

    /*  5. copy "out" parameters */
    if ( streamid != NULL )
    {
        *streamid = data->streamid;
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

extern FResult plfapiconn_cmdmx_Free( int winid, int streamid, Nat32 datacookie, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxFree *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxFree );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->streamid = streamid;
    data->datacookie = datacookie;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 1, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 1, data );
    }
    component->Call( component, idcmdmxFree, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 1, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 1, data );
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

extern FResult plfapiconn_cmdmx_GetAvailableClientStreams( int winid, Nat32 * AvailClientStr, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxGetAvailableClientStreams *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxGetAvailableClientStreams );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 2, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 2, data );
    }
    component->Call( component, idcmdmxGetAvailableClientStreams, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 2, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 2, data );
    }

    /*  5. copy "out" parameters */
    if ( AvailClientStr != NULL )
    {
        *AvailClientStr = data->AvailClientStr;
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

extern FResult plfapiconn_cmdmx_GetPlatformStream( int winid, tmCmDmx_PlatformStreamType_t platformStreamType, int * streamid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxGetPlatformStream *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxGetPlatformStream );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->platformStreamType = platformStreamType;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 3, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 3, data );
    }
    component->Call( component, idcmdmxGetPlatformStream, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 3, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 3, data );
    }

    /*  5. copy "out" parameters */
    if ( streamid != NULL )
    {
        *streamid = data->streamid;
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

extern FResult plfapiconn_cmdmx_GetStreamInfo( int winid, Nat32 streamIndex, Nat16 langSize, tmCmDmx_StreamType_t * StreamType, char * streamLanguage, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxGetStreamInfo *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxGetStreamInfo ) + ( sizeof( char ) * langSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->streamLanguage = ( streamLanguage == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(cmdmxGetStreamInfo) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->streamIndex = streamIndex;
    data->langSize = langSize;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 4, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 4, data );
    }
    component->Call( component, idcmdmxGetStreamInfo, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 4, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 4, data );
    }

    /*  5. copy "out" parameters */
    if ( StreamType != NULL )
    {
        *StreamType = data->StreamType;
    }
    if ( streamLanguage != NULL )
    {
        memcpy( streamLanguage, data->streamLanguage,( sizeof( char ) * langSize ) );
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

extern FResult plfapiconn_cmdmx_GetStreamMapSize( int winid, Nat32 * NumberOfStreams, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxGetStreamMapSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxGetStreamMapSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 5, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 5, data );
    }
    component->Call( component, idcmdmxGetStreamMapSize, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 5, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 5, data );
    }

    /*  5. copy "out" parameters */
    if ( NumberOfStreams != NULL )
    {
        *NumberOfStreams = data->NumberOfStreams;
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

extern FResult plfapiconn_cmdmx_GetSupportedPlatformStreams( int winid, tmCmDmx_SuppPlatformStreamTypes_t * SuppPlatformStreams, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxGetSupportedPlatformStreams *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxGetSupportedPlatformStreams );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 6, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 6, data );
    }
    component->Call( component, idcmdmxGetSupportedPlatformStreams, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 6, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 6, data );
    }

    /*  5. copy "out" parameters */
    if ( SuppPlatformStreams != NULL )
    {
        *SuppPlatformStreams = data->SuppPlatformStreams;
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

extern FResult plfapiconn_cmdmx_SetBuffer( int winid, int streamid, tmCmDmx_BufferType_t bufferType, Nat32 bufferSize, Nat32 granularity, tmCmDmx_Buffer_t buffer, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxSetBuffer *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxSetBuffer );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->streamid = streamid;
    data->bufferType = bufferType;
    data->bufferSize = bufferSize;
    data->granularity = granularity;
    data->buffer = buffer;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 7, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 7, data );
    }
    component->Call( component, idcmdmxSetBuffer, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 7, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 7, data );
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

extern FResult plfapiconn_cmdmx_SetStreamIndex( int winid, int streamid, Nat32 streamIndex, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxSetStreamIndex *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxSetStreamIndex );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->streamid = streamid;
    data->streamIndex = streamIndex;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 8, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 8, data );
    }
    component->Call( component, idcmdmxSetStreamIndex, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 8, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 8, data );
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

extern FResult plfapiconn_cmdmx_Start( int winid, int streamid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxStart *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxStart );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->streamid = streamid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 9, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 9, data );
    }
    component->Call( component, idcmdmxStart, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 9, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 9, data );
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

extern FResult plfapiconn_cmdmx_Stop( int winid, int streamid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    cmdmxStop *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( cmdmxStop );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->streamid = streamid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 10, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCall, 10, data );
    }
    component->Call( component, idcmdmxStop, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 10, data );
    }
    if ( plfapiconn_hook_cmdmx )
    {
        (*plfapiconn_hook_cmdmx)( ipchtCallDone, 10, data );
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

extern FResult plfapiconn_connitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    connitfGetAvailableInterfaces *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( connitfGetAvailableInterfaces );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 11, data );
    }
    if ( plfapiconn_hook_connitf )
    {
        (*plfapiconn_hook_connitf)( ipchtCall, 11, data );
    }
    component->Call( component, idconnitfGetAvailableInterfaces, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 11, data );
    }
    if ( plfapiconn_hook_connitf )
    {
        (*plfapiconn_hook_connitf)( ipchtCallDone, 11, data );
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

extern FResult plfapiconn_dcf_SetAesContentKey( int winid, Nat8 * key, int size, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    dcfSetAesContentKey *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( dcfSetAesContentKey ) + ( sizeof( Nat8 ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->key = ( key == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(dcfSetAesContentKey) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->key != NULL )
    {
        memcpy( data->key, key, ( sizeof( Nat8 ) * size ) );
    }
    data->size = size;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 12, data );
    }
    if ( plfapiconn_hook_dcf )
    {
        (*plfapiconn_hook_dcf)( ipchtCall, 12, data );
    }
    component->Call( component, iddcfSetAesContentKey, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 12, data );
    }
    if ( plfapiconn_hook_dcf )
    {
        (*plfapiconn_hook_dcf)( ipchtCallDone, 12, data );
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

extern FResult plfapiconn_imgdec_DecodeImage( int winid, Nat32 requestedHorRes, Nat32 requestedVertRes, Nat32 stride, tmPixFmtCls_t formatClass, tmPixFmtType_t formatType, Bool useImageArea, tmImageDec2_ImageArea_t requestedImageArea, Nat32 bufferSize, tmImageDec_Buffer_t Buffer, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecDecodeImage *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecDecodeImage );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->requestedHorRes = requestedHorRes;
    data->requestedVertRes = requestedVertRes;
    data->stride = stride;
    data->formatClass = formatClass;
    data->formatType = formatType;
    data->useImageArea = useImageArea;
    data->requestedImageArea = requestedImageArea;
    data->bufferSize = bufferSize;
    data->Buffer = Buffer;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 13, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 13, data );
    }
    component->Call( component, idimgdecDecodeImage, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 13, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 13, data );
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

extern FResult plfapiconn_imgdec_DecodeThumbnail( int winid, Nat32 requestedHorRes, Nat32 requestedVertRes, Nat32 stride, tmPixFmtCls_t formatClass, tmPixFmtType_t formatType, Nat32 bufferSize, tmImageDec_Buffer_t Buffer, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecDecodeThumbnail *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecDecodeThumbnail );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->requestedHorRes = requestedHorRes;
    data->requestedVertRes = requestedVertRes;
    data->stride = stride;
    data->formatClass = formatClass;
    data->formatType = formatType;
    data->bufferSize = bufferSize;
    data->Buffer = Buffer;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 14, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 14, data );
    }
    component->Call( component, idimgdecDecodeThumbnail, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 14, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 14, data );
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

extern FResult plfapiconn_imgdec_GetBufAlignment( int winid, Nat32 * BufAlignment, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetBufAlignment *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetBufAlignment );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 15, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 15, data );
    }
    component->Call( component, idimgdecGetBufAlignment, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 15, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 15, data );
    }

    /*  5. copy "out" parameters */
    if ( BufAlignment != NULL )
    {
        *BufAlignment = data->BufAlignment;
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

extern FResult plfapiconn_imgdec_GetMaxResolution( int winid, Nat32 * MaxHorRes, Nat32 * MaxVertRes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetMaxResolution *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetMaxResolution );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 16, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 16, data );
    }
    component->Call( component, idimgdecGetMaxResolution, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 16, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 16, data );
    }

    /*  5. copy "out" parameters */
    if ( MaxHorRes != NULL )
    {
        *MaxHorRes = data->MaxHorRes;
    }
    if ( MaxVertRes != NULL )
    {
        *MaxVertRes = data->MaxVertRes;
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

extern FResult plfapiconn_imgdec_GetMetaDataPresent( int winid, Bool * MetaDataPresent, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetMetaDataPresent *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetMetaDataPresent );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 17, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 17, data );
    }
    component->Call( component, idimgdecGetMetaDataPresent, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 17, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 17, data );
    }

    /*  5. copy "out" parameters */
    if ( MetaDataPresent != NULL )
    {
        *MetaDataPresent = data->MetaDataPresent;
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

extern FResult plfapiconn_imgdec_GetOrgFullResolution( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetOrgFullResolution *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetOrgFullResolution );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 18, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 18, data );
    }
    component->Call( component, idimgdecGetOrgFullResolution, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 18, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 18, data );
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

extern FResult plfapiconn_imgdec_GetOrgImageAspectRatio( int winid, Nat16 * Numerator, Nat16 * Denominator, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetOrgImageAspectRatio *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetOrgImageAspectRatio );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 19, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 19, data );
    }
    component->Call( component, idimgdecGetOrgImageAspectRatio, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 19, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 19, data );
    }

    /*  5. copy "out" parameters */
    if ( Numerator != NULL )
    {
        *Numerator = data->Numerator;
    }
    if ( Denominator != NULL )
    {
        *Denominator = data->Denominator;
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

extern FResult plfapiconn_imgdec_GetOrgImageOrientation( int winid, tmImageDec2_Orientation_t * Orientation, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetOrgImageOrientation *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetOrgImageOrientation );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 20, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 20, data );
    }
    component->Call( component, idimgdecGetOrgImageOrientation, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 20, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 20, data );
    }

    /*  5. copy "out" parameters */
    if ( Orientation != NULL )
    {
        *Orientation = data->Orientation;
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

extern FResult plfapiconn_imgdec_GetOrgThumbnailResolution( int winid, Nat32 * HorRes, Nat32 * VertRes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetOrgThumbnailResolution *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetOrgThumbnailResolution );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 21, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 21, data );
    }
    component->Call( component, idimgdecGetOrgThumbnailResolution, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 21, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 21, data );
    }

    /*  5. copy "out" parameters */
    if ( HorRes != NULL )
    {
        *HorRes = data->HorRes;
    }
    if ( VertRes != NULL )
    {
        *VertRes = data->VertRes;
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

extern FResult plfapiconn_imgdec_GetRawMetaData( int winid, tmImageDec2_ImageFormat_t * ImageFormat, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetRawMetaData *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetRawMetaData );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 22, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 22, data );
    }
    component->Call( component, idimgdecGetRawMetaData, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 22, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 22, data );
    }

    /*  5. copy "out" parameters */
    if ( ImageFormat != NULL )
    {
        *ImageFormat = data->ImageFormat;
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

extern FResult plfapiconn_imgdec_GetRotationMode( int winid, tmImageDec2_RotationMode_t * Mode, tmImageDec2_Orientation_t * Orientation, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetRotationMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetRotationMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 23, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 23, data );
    }
    component->Call( component, idimgdecGetRotationMode, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 23, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 23, data );
    }

    /*  5. copy "out" parameters */
    if ( Mode != NULL )
    {
        *Mode = data->Mode;
    }
    if ( Orientation != NULL )
    {
        *Orientation = data->Orientation;
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

extern FResult plfapiconn_imgdec_GetScaleRange( int winid, Nat32 * MinHorPercentage, Nat32 * MinVertPercentage, Nat32 * MaxHorPercentage, Nat32 * MaxVertPercentage, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetScaleRange *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetScaleRange );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 24, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 24, data );
    }
    component->Call( component, idimgdecGetScaleRange, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 24, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 24, data );
    }

    /*  5. copy "out" parameters */
    if ( MinHorPercentage != NULL )
    {
        *MinHorPercentage = data->MinHorPercentage;
    }
    if ( MinVertPercentage != NULL )
    {
        *MinVertPercentage = data->MinVertPercentage;
    }
    if ( MaxHorPercentage != NULL )
    {
        *MaxHorPercentage = data->MaxHorPercentage;
    }
    if ( MaxVertPercentage != NULL )
    {
        *MaxVertPercentage = data->MaxVertPercentage;
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

extern FResult plfapiconn_imgdec_GetSuppFormatClasses( int winid, tmPixFmtClsSet_t * FormatClasses, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetSuppFormatClasses *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetSuppFormatClasses );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 25, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 25, data );
    }
    component->Call( component, idimgdecGetSuppFormatClasses, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 25, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 25, data );
    }

    /*  5. copy "out" parameters */
    if ( FormatClasses != NULL )
    {
        *FormatClasses = data->FormatClasses;
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

extern FResult plfapiconn_imgdec_GetSuppFormatTypes( int winid, tmPixFmtCls_t formatClass, tmPixFmtTypeSet_t * FormatTypes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetSuppFormatTypes *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetSuppFormatTypes );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->formatClass = formatClass;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 26, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 26, data );
    }
    component->Call( component, idimgdecGetSuppFormatTypes, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 26, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 26, data );
    }

    /*  5. copy "out" parameters */
    if ( FormatTypes != NULL )
    {
        *FormatTypes = data->FormatTypes;
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

extern FResult plfapiconn_imgdec_GetSuppImageFormats( int winid, tmImageDec2_ImageFormats_t * Formats, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetSuppImageFormats *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetSuppImageFormats );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 27, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 27, data );
    }
    component->Call( component, idimgdecGetSuppImageFormats, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 27, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 27, data );
    }

    /*  5. copy "out" parameters */
    if ( Formats != NULL )
    {
        *Formats = data->Formats;
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

extern FResult plfapiconn_imgdec_GetSupportedRotationModes( int winid, tmImageDec2_RotationModes_t * Modes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetSupportedRotationModes *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetSupportedRotationModes );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 28, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 28, data );
    }
    component->Call( component, idimgdecGetSupportedRotationModes, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 28, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 28, data );
    }

    /*  5. copy "out" parameters */
    if ( Modes != NULL )
    {
        *Modes = data->Modes;
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

extern FResult plfapiconn_imgdec_GetThumbnailPresent( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecGetThumbnailPresent *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecGetThumbnailPresent );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 29, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 29, data );
    }
    component->Call( component, idimgdecGetThumbnailPresent, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 29, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 29, data );
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

extern FResult plfapiconn_imgdec_SetRotationMode( int winid, tmImageDec2_RotationMode_t mode, tmImageDec2_Orientation_t orientation, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    imgdecSetRotationMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( imgdecSetRotationMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->mode = mode;
    data->orientation = orientation;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 30, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCall, 30, data );
    }
    component->Call( component, idimgdecSetRotationMode, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 30, data );
    }
    if ( plfapiconn_hook_imgdec )
    {
        (*plfapiconn_hook_imgdec)( ipchtCallDone, 30, data );
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

extern FResult plfapiconn_md_GetAvType( int winid, char * url, Nat32 * cookie )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    mdGetAvType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( mdGetAvType ) + ( ( url == NULL ? 0 : strlen( url ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->url = ( url == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(mdGetAvType) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->url != NULL )
    {
        strcpy( data->url, url );
    }

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 31, data );
    }
    if ( plfapiconn_hook_md )
    {
        (*plfapiconn_hook_md)( ipchtCall, 31, data );
    }
    component->Call( component, idmdGetAvType, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 31, data );
    }
    if ( plfapiconn_hook_md )
    {
        (*plfapiconn_hook_md)( ipchtCallDone, 31, data );
    }

    /*  5. copy "out" parameters */
    if ( cookie != NULL )
    {
        *cookie = data->cookie;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapiconn_netschemecfg_GetNetworkJitter( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netschemecfgGetNetworkJitter *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netschemecfgGetNetworkJitter );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 32, data );
    }
    if ( plfapiconn_hook_netschemecfg )
    {
        (*plfapiconn_hook_netschemecfg)( ipchtCall, 32, data );
    }
    component->Call( component, idnetschemecfgGetNetworkJitter, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 32, data );
    }
    if ( plfapiconn_hook_netschemecfg )
    {
        (*plfapiconn_hook_netschemecfg)( ipchtCallDone, 32, data );
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

extern FResult plfapiconn_netschemecfg_SetNetworkJitter( int winid, Nat32 milliseconds )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    netschemecfgSetNetworkJitter *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( netschemecfgSetNetworkJitter );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->milliseconds = milliseconds;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 33, data );
    }
    if ( plfapiconn_hook_netschemecfg )
    {
        (*plfapiconn_hook_netschemecfg)( ipchtCall, 33, data );
    }
    component->Call( component, idnetschemecfgSetNetworkJitter, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 33, data );
    }
    if ( plfapiconn_hook_netschemecfg )
    {
        (*plfapiconn_hook_netschemecfg)( ipchtCallDone, 33, data );
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

extern FResult plfapiconn_urlsrcjpg_AbortAction( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgAbortAction *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgAbortAction );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 34, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 34, data );
    }
    component->Call( component, idurlsrcjpgAbortAction, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 34, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 34, data );
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

extern FResult plfapiconn_urlsrcjpg_CloseUrl( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgCloseUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgCloseUrl );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 35, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 35, data );
    }
    component->Call( component, idurlsrcjpgCloseUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 35, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 35, data );
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

extern FResult plfapiconn_urlsrcjpg_GetAvailStepModes( int winid, tmUrlSrc_StepModes_t * AvailStepModes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetAvailStepModes *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetAvailStepModes );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 36, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 36, data );
    }
    component->Call( component, idurlsrcjpgGetAvailStepModes, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 36, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 36, data );
    }

    /*  5. copy "out" parameters */
    if ( AvailStepModes != NULL )
    {
        *AvailStepModes = data->AvailStepModes;
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

extern FResult plfapiconn_urlsrcjpg_GetBufferFullness( int winid, Nat32 * BufferFullness, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetBufferFullness *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetBufferFullness );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 37, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 37, data );
    }
    component->Call( component, idurlsrcjpgGetBufferFullness, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 37, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 37, data );
    }

    /*  5. copy "out" parameters */
    if ( BufferFullness != NULL )
    {
        *BufferFullness = data->BufferFullness;
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

extern FResult plfapiconn_urlsrcjpg_GetPosition( int winid, Nat32 * Time, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetPosition *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetPosition );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 38, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 38, data );
    }
    component->Call( component, idurlsrcjpgGetPosition, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 38, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 38, data );
    }

    /*  5. copy "out" parameters */
    if ( Time != NULL )
    {
        *Time = data->Time;
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

extern FResult plfapiconn_urlsrcjpg_GetSeekMode( int winid, tmUrlSrc_SeekMode_t * seekMode, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetSeekMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetSeekMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 39, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 39, data );
    }
    component->Call( component, idurlsrcjpgGetSeekMode, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 39, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 39, data );
    }

    /*  5. copy "out" parameters */
    if ( seekMode != NULL )
    {
        *seekMode = data->seekMode;
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

extern FResult plfapiconn_urlsrcjpg_GetSizeForDuration( int winid, Nat32 timeDuration, Nat32 * numberOfBytes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetSizeForDuration *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetSizeForDuration );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->timeDuration = timeDuration;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 40, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 40, data );
    }
    component->Call( component, idurlsrcjpgGetSizeForDuration, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 40, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 40, data );
    }

    /*  5. copy "out" parameters */
    if ( numberOfBytes != NULL )
    {
        *numberOfBytes = data->numberOfBytes;
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

extern FResult plfapiconn_urlsrcjpg_GetSpeed( int winid, Int8 * requestedSpeedNum, Nat8 * requestedSpeedDenom, Int8 * ActualSpeedNum, Nat8 * ActualSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetSpeed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetSpeed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 41, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 41, data );
    }
    component->Call( component, idurlsrcjpgGetSpeed, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 41, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 41, data );
    }

    /*  5. copy "out" parameters */
    if ( requestedSpeedNum != NULL )
    {
        *requestedSpeedNum = data->requestedSpeedNum;
    }
    if ( requestedSpeedDenom != NULL )
    {
        *requestedSpeedDenom = data->requestedSpeedDenom;
    }
    if ( ActualSpeedNum != NULL )
    {
        *ActualSpeedNum = data->ActualSpeedNum;
    }
    if ( ActualSpeedDenom != NULL )
    {
        *ActualSpeedDenom = data->ActualSpeedDenom;
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

extern FResult plfapiconn_urlsrcjpg_GetSpeedRange( int winid, Bool * ReverseSupp, Nat8 * MinSpeedNum, Nat8 * MinSpeedDenom, Nat8 * MaxSpeedNum, Nat8 * pMaxSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetSpeedRange *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetSpeedRange );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 42, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 42, data );
    }
    component->Call( component, idurlsrcjpgGetSpeedRange, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 42, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 42, data );
    }

    /*  5. copy "out" parameters */
    if ( ReverseSupp != NULL )
    {
        *ReverseSupp = data->ReverseSupp;
    }
    if ( MinSpeedNum != NULL )
    {
        *MinSpeedNum = data->MinSpeedNum;
    }
    if ( MinSpeedDenom != NULL )
    {
        *MinSpeedDenom = data->MinSpeedDenom;
    }
    if ( MaxSpeedNum != NULL )
    {
        *MaxSpeedNum = data->MaxSpeedNum;
    }
    if ( pMaxSpeedDenom != NULL )
    {
        *pMaxSpeedDenom = data->pMaxSpeedDenom;
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

extern FResult plfapiconn_urlsrcjpg_GetSuppSchemes( int winid, tmUrlSrc_Schemes_t * SupportedSchemes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetSuppSchemes *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetSuppSchemes );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 43, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 43, data );
    }
    component->Call( component, idurlsrcjpgGetSuppSchemes, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 43, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 43, data );
    }

    /*  5. copy "out" parameters */
    if ( SupportedSchemes != NULL )
    {
        *SupportedSchemes = data->SupportedSchemes;
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

extern FResult plfapiconn_urlsrcjpg_GetTotalDuration( int winid, Nat32 * TotalDuration, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetTotalDuration *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetTotalDuration );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 44, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 44, data );
    }
    component->Call( component, idurlsrcjpgGetTotalDuration, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 44, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 44, data );
    }

    /*  5. copy "out" parameters */
    if ( TotalDuration != NULL )
    {
        *TotalDuration = data->TotalDuration;
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

extern FResult plfapiconn_urlsrcjpg_GetTotalSize( int winid, Nat64 * TotalSize, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetTotalSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetTotalSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 45, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 45, data );
    }
    component->Call( component, idurlsrcjpgGetTotalSize, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 45, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 45, data );
    }

    /*  5. copy "out" parameters */
    if ( TotalSize != NULL )
    {
        *TotalSize = data->TotalSize;
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

extern FResult plfapiconn_urlsrcjpg_GetUrl( int winid, Nat16 size, Nat32 * ActualSize, Nat8 * url, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgGetUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgGetUrl ) + ( sizeof( Nat8 ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->url = ( url == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(urlsrcjpgGetUrl) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 46, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 46, data );
    }
    component->Call( component, idurlsrcjpgGetUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 46, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 46, data );
    }

    /*  5. copy "out" parameters */
    if ( ActualSize != NULL )
    {
        *ActualSize = data->ActualSize;
    }
    if ( url != NULL )
    {
        memcpy( url, data->url,( sizeof( Nat8 ) * size ) );
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

extern FResult plfapiconn_urlsrcjpg_OpenUrl( int winid, char * url, Nat32 timeOut, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgOpenUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgOpenUrl ) + ( ( url == NULL ? 0 : strlen( url ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->url = ( url == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(urlsrcjpgOpenUrl) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->url != NULL )
    {
        strcpy( data->url, url );
    }
    data->timeOut = timeOut;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 47, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 47, data );
    }
    component->Call( component, idurlsrcjpgOpenUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 47, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 47, data );
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

extern FResult plfapiconn_urlsrcjpg_Pause( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgPause *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgPause );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 48, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 48, data );
    }
    component->Call( component, idurlsrcjpgPause, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 48, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 48, data );
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

extern FResult plfapiconn_urlsrcjpg_Resume( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgResume *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgResume );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 49, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 49, data );
    }
    component->Call( component, idurlsrcjpgResume, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 49, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 49, data );
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

extern FResult plfapiconn_urlsrcjpg_SetPosition( int winid, Nat32 requestedTime, tmUrlSrc_Rounding_t rounding, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgSetPosition *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgSetPosition );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->requestedTime = requestedTime;
    data->rounding = rounding;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 50, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 50, data );
    }
    component->Call( component, idurlsrcjpgSetPosition, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 50, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 50, data );
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

extern FResult plfapiconn_urlsrcjpg_SetSeekMode( int winid, tmUrlSrc_SeekMode_t seekMode, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgSetSeekMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgSetSeekMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->seekMode = seekMode;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 51, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 51, data );
    }
    component->Call( component, idurlsrcjpgSetSeekMode, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 51, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 51, data );
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

extern FResult plfapiconn_urlsrcjpg_SetSpeed( int winid, Int8 requestedSpeedNum, Nat8 requestedSpeedDenom, Int8 * ActualSpeedNum, Nat8 * ActualSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgSetSpeed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgSetSpeed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->requestedSpeedNum = requestedSpeedNum;
    data->requestedSpeedDenom = requestedSpeedDenom;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 52, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 52, data );
    }
    component->Call( component, idurlsrcjpgSetSpeed, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 52, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 52, data );
    }

    /*  5. copy "out" parameters */
    if ( ActualSpeedNum != NULL )
    {
        *ActualSpeedNum = data->ActualSpeedNum;
    }
    if ( ActualSpeedDenom != NULL )
    {
        *ActualSpeedDenom = data->ActualSpeedDenom;
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

extern FResult plfapiconn_urlsrcjpg_Start( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgStart *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgStart );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 53, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 53, data );
    }
    component->Call( component, idurlsrcjpgStart, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 53, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 53, data );
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

extern FResult plfapiconn_urlsrcjpg_StepBackward( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgStepBackward *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgStepBackward );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 54, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 54, data );
    }
    component->Call( component, idurlsrcjpgStepBackward, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 54, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 54, data );
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

extern FResult plfapiconn_urlsrcjpg_StepForward( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgStepForward *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgStepForward );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 55, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 55, data );
    }
    component->Call( component, idurlsrcjpgStepForward, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 55, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 55, data );
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

extern FResult plfapiconn_urlsrcjpg_Stop( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcjpgStop *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcjpgStop );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 56, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCall, 56, data );
    }
    component->Call( component, idurlsrcjpgStop, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 56, data );
    }
    if ( plfapiconn_hook_urlsrcjpg )
    {
        (*plfapiconn_hook_urlsrcjpg)( ipchtCallDone, 56, data );
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

extern FResult plfapiconn_urlsrcmp3_AbortAction( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3AbortAction *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3AbortAction );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 57, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 57, data );
    }
    component->Call( component, idurlsrcmp3AbortAction, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 57, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 57, data );
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

extern FResult plfapiconn_urlsrcmp3_CloseUrl( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3CloseUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3CloseUrl );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 58, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 58, data );
    }
    component->Call( component, idurlsrcmp3CloseUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 58, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 58, data );
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

extern FResult plfapiconn_urlsrcmp3_GetAvailStepModes( int winid, tmUrlSrc_StepModes_t * AvailStepModes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetAvailStepModes *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetAvailStepModes );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 59, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 59, data );
    }
    component->Call( component, idurlsrcmp3GetAvailStepModes, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 59, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 59, data );
    }

    /*  5. copy "out" parameters */
    if ( AvailStepModes != NULL )
    {
        *AvailStepModes = data->AvailStepModes;
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

extern FResult plfapiconn_urlsrcmp3_GetBufferFullness( int winid, Nat32 * BufferFullness, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetBufferFullness *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetBufferFullness );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 60, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 60, data );
    }
    component->Call( component, idurlsrcmp3GetBufferFullness, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 60, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 60, data );
    }

    /*  5. copy "out" parameters */
    if ( BufferFullness != NULL )
    {
        *BufferFullness = data->BufferFullness;
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

extern FResult plfapiconn_urlsrcmp3_GetPosition( int winid, Nat32 * Time, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetPosition *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetPosition );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 61, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 61, data );
    }
    component->Call( component, idurlsrcmp3GetPosition, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 61, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 61, data );
    }

    /*  5. copy "out" parameters */
    if ( Time != NULL )
    {
        *Time = data->Time;
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

extern FResult plfapiconn_urlsrcmp3_GetSeekMode( int winid, tmUrlSrc_SeekMode_t * seekMode, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetSeekMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetSeekMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 62, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 62, data );
    }
    component->Call( component, idurlsrcmp3GetSeekMode, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 62, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 62, data );
    }

    /*  5. copy "out" parameters */
    if ( seekMode != NULL )
    {
        *seekMode = data->seekMode;
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

extern FResult plfapiconn_urlsrcmp3_GetSizeForDuration( int winid, Nat32 timeDuration, Nat32 * numberOfBytes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetSizeForDuration *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetSizeForDuration );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->timeDuration = timeDuration;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 63, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 63, data );
    }
    component->Call( component, idurlsrcmp3GetSizeForDuration, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 63, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 63, data );
    }

    /*  5. copy "out" parameters */
    if ( numberOfBytes != NULL )
    {
        *numberOfBytes = data->numberOfBytes;
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

extern FResult plfapiconn_urlsrcmp3_GetSpeed( int winid, Int8 * requestedSpeedNum, Nat8 * requestedSpeedDenom, Int8 * ActualSpeedNum, Nat8 * ActualSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetSpeed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetSpeed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 64, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 64, data );
    }
    component->Call( component, idurlsrcmp3GetSpeed, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 64, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 64, data );
    }

    /*  5. copy "out" parameters */
    if ( requestedSpeedNum != NULL )
    {
        *requestedSpeedNum = data->requestedSpeedNum;
    }
    if ( requestedSpeedDenom != NULL )
    {
        *requestedSpeedDenom = data->requestedSpeedDenom;
    }
    if ( ActualSpeedNum != NULL )
    {
        *ActualSpeedNum = data->ActualSpeedNum;
    }
    if ( ActualSpeedDenom != NULL )
    {
        *ActualSpeedDenom = data->ActualSpeedDenom;
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

extern FResult plfapiconn_urlsrcmp3_GetSpeedRange( int winid, Bool * ReverseSupp, Nat8 * MinSpeedNum, Nat8 * MinSpeedDenom, Nat8 * MaxSpeedNum, Nat8 * pMaxSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetSpeedRange *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetSpeedRange );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 65, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 65, data );
    }
    component->Call( component, idurlsrcmp3GetSpeedRange, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 65, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 65, data );
    }

    /*  5. copy "out" parameters */
    if ( ReverseSupp != NULL )
    {
        *ReverseSupp = data->ReverseSupp;
    }
    if ( MinSpeedNum != NULL )
    {
        *MinSpeedNum = data->MinSpeedNum;
    }
    if ( MinSpeedDenom != NULL )
    {
        *MinSpeedDenom = data->MinSpeedDenom;
    }
    if ( MaxSpeedNum != NULL )
    {
        *MaxSpeedNum = data->MaxSpeedNum;
    }
    if ( pMaxSpeedDenom != NULL )
    {
        *pMaxSpeedDenom = data->pMaxSpeedDenom;
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

extern FResult plfapiconn_urlsrcmp3_GetSuppSchemes( int winid, tmUrlSrc_Schemes_t * SupportedSchemes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetSuppSchemes *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetSuppSchemes );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 66, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 66, data );
    }
    component->Call( component, idurlsrcmp3GetSuppSchemes, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 66, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 66, data );
    }

    /*  5. copy "out" parameters */
    if ( SupportedSchemes != NULL )
    {
        *SupportedSchemes = data->SupportedSchemes;
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

extern FResult plfapiconn_urlsrcmp3_GetTotalDuration( int winid, Nat32 * TotalDuration, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetTotalDuration *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetTotalDuration );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 67, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 67, data );
    }
    component->Call( component, idurlsrcmp3GetTotalDuration, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 67, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 67, data );
    }

    /*  5. copy "out" parameters */
    if ( TotalDuration != NULL )
    {
        *TotalDuration = data->TotalDuration;
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

extern FResult plfapiconn_urlsrcmp3_GetTotalSize( int winid, Nat64 * TotalSize, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetTotalSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetTotalSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 68, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 68, data );
    }
    component->Call( component, idurlsrcmp3GetTotalSize, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 68, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 68, data );
    }

    /*  5. copy "out" parameters */
    if ( TotalSize != NULL )
    {
        *TotalSize = data->TotalSize;
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

extern FResult plfapiconn_urlsrcmp3_GetUrl( int winid, Nat16 size, Nat32 * ActualSize, Nat8 * url, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3GetUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3GetUrl ) + ( sizeof( Nat8 ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->url = ( url == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(urlsrcmp3GetUrl) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 69, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 69, data );
    }
    component->Call( component, idurlsrcmp3GetUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 69, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 69, data );
    }

    /*  5. copy "out" parameters */
    if ( ActualSize != NULL )
    {
        *ActualSize = data->ActualSize;
    }
    if ( url != NULL )
    {
        memcpy( url, data->url,( sizeof( Nat8 ) * size ) );
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

extern FResult plfapiconn_urlsrcmp3_OpenUrl( int winid, char * url, Nat32 timeOut, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3OpenUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3OpenUrl ) + ( ( url == NULL ? 0 : strlen( url ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->url = ( url == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(urlsrcmp3OpenUrl) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->url != NULL )
    {
        strcpy( data->url, url );
    }
    data->timeOut = timeOut;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 70, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 70, data );
    }
    component->Call( component, idurlsrcmp3OpenUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 70, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 70, data );
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

extern FResult plfapiconn_urlsrcmp3_Pause( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3Pause *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3Pause );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 71, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 71, data );
    }
    component->Call( component, idurlsrcmp3Pause, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 71, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 71, data );
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

extern FResult plfapiconn_urlsrcmp3_Resume( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3Resume *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3Resume );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 72, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 72, data );
    }
    component->Call( component, idurlsrcmp3Resume, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 72, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 72, data );
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

extern FResult plfapiconn_urlsrcmp3_SetPosition( int winid, Nat32 requestedTime, tmUrlSrc_Rounding_t rounding, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3SetPosition *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3SetPosition );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->requestedTime = requestedTime;
    data->rounding = rounding;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 73, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 73, data );
    }
    component->Call( component, idurlsrcmp3SetPosition, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 73, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 73, data );
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

extern FResult plfapiconn_urlsrcmp3_SetSeekMode( int winid, tmUrlSrc_SeekMode_t seekMode, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3SetSeekMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3SetSeekMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->seekMode = seekMode;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 74, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 74, data );
    }
    component->Call( component, idurlsrcmp3SetSeekMode, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 74, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 74, data );
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

extern FResult plfapiconn_urlsrcmp3_SetSpeed( int winid, Int8 requestedSpeedNum, Nat8 requestedSpeedDenom, Int8 * ActualSpeedNum, Nat8 * ActualSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3SetSpeed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3SetSpeed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->requestedSpeedNum = requestedSpeedNum;
    data->requestedSpeedDenom = requestedSpeedDenom;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 75, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 75, data );
    }
    component->Call( component, idurlsrcmp3SetSpeed, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 75, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 75, data );
    }

    /*  5. copy "out" parameters */
    if ( ActualSpeedNum != NULL )
    {
        *ActualSpeedNum = data->ActualSpeedNum;
    }
    if ( ActualSpeedDenom != NULL )
    {
        *ActualSpeedDenom = data->ActualSpeedDenom;
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

extern FResult plfapiconn_urlsrcmp3_Start( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3Start *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3Start );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 76, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 76, data );
    }
    component->Call( component, idurlsrcmp3Start, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 76, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 76, data );
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

extern FResult plfapiconn_urlsrcmp3_StepBackward( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3StepBackward *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3StepBackward );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 77, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 77, data );
    }
    component->Call( component, idurlsrcmp3StepBackward, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 77, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 77, data );
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

extern FResult plfapiconn_urlsrcmp3_StepForward( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3StepForward *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3StepForward );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 78, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 78, data );
    }
    component->Call( component, idurlsrcmp3StepForward, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 78, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 78, data );
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

extern FResult plfapiconn_urlsrcmp3_Stop( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcmp3Stop *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcmp3Stop );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 79, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCall, 79, data );
    }
    component->Call( component, idurlsrcmp3Stop, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 79, data );
    }
    if ( plfapiconn_hook_urlsrcmp3 )
    {
        (*plfapiconn_hook_urlsrcmp3)( ipchtCallDone, 79, data );
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

extern FResult plfapiconn_urlsrcvid_AbortAction( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidAbortAction *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidAbortAction );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 80, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 80, data );
    }
    component->Call( component, idurlsrcvidAbortAction, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 80, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 80, data );
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

extern FResult plfapiconn_urlsrcvid_CloseUrl( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidCloseUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidCloseUrl );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 81, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 81, data );
    }
    component->Call( component, idurlsrcvidCloseUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 81, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 81, data );
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

extern FResult plfapiconn_urlsrcvid_GetAvailStepModes( int winid, tmUrlSrc_StepModes_t * AvailStepModes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetAvailStepModes *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetAvailStepModes );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 82, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 82, data );
    }
    component->Call( component, idurlsrcvidGetAvailStepModes, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 82, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 82, data );
    }

    /*  5. copy "out" parameters */
    if ( AvailStepModes != NULL )
    {
        *AvailStepModes = data->AvailStepModes;
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

extern FResult plfapiconn_urlsrcvid_GetBufferFullness( int winid, Nat32 * BufferFullness, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetBufferFullness *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetBufferFullness );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 83, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 83, data );
    }
    component->Call( component, idurlsrcvidGetBufferFullness, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 83, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 83, data );
    }

    /*  5. copy "out" parameters */
    if ( BufferFullness != NULL )
    {
        *BufferFullness = data->BufferFullness;
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

extern FResult plfapiconn_urlsrcvid_GetPosition( int winid, Nat32 * Time, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetPosition *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetPosition );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 84, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 84, data );
    }
    component->Call( component, idurlsrcvidGetPosition, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 84, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 84, data );
    }

    /*  5. copy "out" parameters */
    if ( Time != NULL )
    {
        *Time = data->Time;
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

extern FResult plfapiconn_urlsrcvid_GetSeekMode( int winid, tmUrlSrc_SeekMode_t * seekMode, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetSeekMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetSeekMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 85, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 85, data );
    }
    component->Call( component, idurlsrcvidGetSeekMode, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 85, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 85, data );
    }

    /*  5. copy "out" parameters */
    if ( seekMode != NULL )
    {
        *seekMode = data->seekMode;
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

extern FResult plfapiconn_urlsrcvid_GetSizeForDuration( int winid, Nat32 timeDuration, Nat32 * numberOfBytes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetSizeForDuration *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetSizeForDuration );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->timeDuration = timeDuration;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 86, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 86, data );
    }
    component->Call( component, idurlsrcvidGetSizeForDuration, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 86, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 86, data );
    }

    /*  5. copy "out" parameters */
    if ( numberOfBytes != NULL )
    {
        *numberOfBytes = data->numberOfBytes;
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

extern FResult plfapiconn_urlsrcvid_GetSpeed( int winid, Int8 * requestedSpeedNum, Nat8 * requestedSpeedDenom, Int8 * ActualSpeedNum, Nat8 * ActualSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetSpeed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetSpeed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 87, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 87, data );
    }
    component->Call( component, idurlsrcvidGetSpeed, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 87, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 87, data );
    }

    /*  5. copy "out" parameters */
    if ( requestedSpeedNum != NULL )
    {
        *requestedSpeedNum = data->requestedSpeedNum;
    }
    if ( requestedSpeedDenom != NULL )
    {
        *requestedSpeedDenom = data->requestedSpeedDenom;
    }
    if ( ActualSpeedNum != NULL )
    {
        *ActualSpeedNum = data->ActualSpeedNum;
    }
    if ( ActualSpeedDenom != NULL )
    {
        *ActualSpeedDenom = data->ActualSpeedDenom;
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

extern FResult plfapiconn_urlsrcvid_GetSpeedRange( int winid, Bool * ReverseSupp, Nat8 * MinSpeedNum, Nat8 * MinSpeedDenom, Nat8 * MaxSpeedNum, Nat8 * pMaxSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetSpeedRange *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetSpeedRange );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 88, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 88, data );
    }
    component->Call( component, idurlsrcvidGetSpeedRange, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 88, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 88, data );
    }

    /*  5. copy "out" parameters */
    if ( ReverseSupp != NULL )
    {
        *ReverseSupp = data->ReverseSupp;
    }
    if ( MinSpeedNum != NULL )
    {
        *MinSpeedNum = data->MinSpeedNum;
    }
    if ( MinSpeedDenom != NULL )
    {
        *MinSpeedDenom = data->MinSpeedDenom;
    }
    if ( MaxSpeedNum != NULL )
    {
        *MaxSpeedNum = data->MaxSpeedNum;
    }
    if ( pMaxSpeedDenom != NULL )
    {
        *pMaxSpeedDenom = data->pMaxSpeedDenom;
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

extern FResult plfapiconn_urlsrcvid_GetSuppSchemes( int winid, tmUrlSrc_Schemes_t * SupportedSchemes, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetSuppSchemes *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetSuppSchemes );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 89, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 89, data );
    }
    component->Call( component, idurlsrcvidGetSuppSchemes, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 89, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 89, data );
    }

    /*  5. copy "out" parameters */
    if ( SupportedSchemes != NULL )
    {
        *SupportedSchemes = data->SupportedSchemes;
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

extern FResult plfapiconn_urlsrcvid_GetTotalDuration( int winid, Nat32 * TotalDuration, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetTotalDuration *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetTotalDuration );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 90, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 90, data );
    }
    component->Call( component, idurlsrcvidGetTotalDuration, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 90, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 90, data );
    }

    /*  5. copy "out" parameters */
    if ( TotalDuration != NULL )
    {
        *TotalDuration = data->TotalDuration;
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

extern FResult plfapiconn_urlsrcvid_GetTotalSize( int winid, Nat64 * TotalSize, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetTotalSize *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetTotalSize );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 91, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 91, data );
    }
    component->Call( component, idurlsrcvidGetTotalSize, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 91, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 91, data );
    }

    /*  5. copy "out" parameters */
    if ( TotalSize != NULL )
    {
        *TotalSize = data->TotalSize;
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

extern FResult plfapiconn_urlsrcvid_GetUrl( int winid, Nat16 size, Nat32 * ActualSize, Nat8 * url, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidGetUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidGetUrl ) + ( sizeof( Nat8 ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->url = ( url == NULL ) ? NULL : (Nat8 *)( ((char*)data) + sizeof(urlsrcvidGetUrl) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->size = size;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 92, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 92, data );
    }
    component->Call( component, idurlsrcvidGetUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 92, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 92, data );
    }

    /*  5. copy "out" parameters */
    if ( ActualSize != NULL )
    {
        *ActualSize = data->ActualSize;
    }
    if ( url != NULL )
    {
        memcpy( url, data->url,( sizeof( Nat8 ) * size ) );
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

extern FResult plfapiconn_urlsrcvid_OpenUrl( int winid, char * url, Nat32 timeOut, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidOpenUrl *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidOpenUrl ) + ( ( url == NULL ? 0 : strlen( url ) ) + 1 );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->url = ( url == NULL ) ? NULL : (char *)( ((char*)data) + sizeof(urlsrcvidOpenUrl) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    if ( data->url != NULL )
    {
        strcpy( data->url, url );
    }
    data->timeOut = timeOut;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 93, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 93, data );
    }
    component->Call( component, idurlsrcvidOpenUrl, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 93, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 93, data );
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

extern FResult plfapiconn_urlsrcvid_Pause( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidPause *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidPause );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 94, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 94, data );
    }
    component->Call( component, idurlsrcvidPause, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 94, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 94, data );
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

extern FResult plfapiconn_urlsrcvid_Resume( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidResume *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidResume );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 95, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 95, data );
    }
    component->Call( component, idurlsrcvidResume, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 95, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 95, data );
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

extern FResult plfapiconn_urlsrcvid_SetPosition( int winid, Nat32 requestedTime, tmUrlSrc_Rounding_t rounding, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidSetPosition *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidSetPosition );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->requestedTime = requestedTime;
    data->rounding = rounding;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 96, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 96, data );
    }
    component->Call( component, idurlsrcvidSetPosition, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 96, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 96, data );
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

extern FResult plfapiconn_urlsrcvid_SetSeekMode( int winid, tmUrlSrc_SeekMode_t seekMode, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidSetSeekMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidSetSeekMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->seekMode = seekMode;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 97, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 97, data );
    }
    component->Call( component, idurlsrcvidSetSeekMode, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 97, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 97, data );
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

extern FResult plfapiconn_urlsrcvid_SetSpeed( int winid, Int8 requestedSpeedNum, Nat8 requestedSpeedDenom, Int8 * ActualSpeedNum, Nat8 * ActualSpeedDenom, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidSetSpeed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidSetSpeed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->requestedSpeedNum = requestedSpeedNum;
    data->requestedSpeedDenom = requestedSpeedDenom;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 98, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 98, data );
    }
    component->Call( component, idurlsrcvidSetSpeed, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 98, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 98, data );
    }

    /*  5. copy "out" parameters */
    if ( ActualSpeedNum != NULL )
    {
        *ActualSpeedNum = data->ActualSpeedNum;
    }
    if ( ActualSpeedDenom != NULL )
    {
        *ActualSpeedDenom = data->ActualSpeedDenom;
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

extern FResult plfapiconn_urlsrcvid_Start( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidStart *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidStart );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 99, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 99, data );
    }
    component->Call( component, idurlsrcvidStart, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 99, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 99, data );
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

extern FResult plfapiconn_urlsrcvid_StepBackward( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidStepBackward *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidStepBackward );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 100, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 100, data );
    }
    component->Call( component, idurlsrcvidStepBackward, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 100, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 100, data );
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

extern FResult plfapiconn_urlsrcvid_StepForward( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidStepForward *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidStepForward );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 101, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 101, data );
    }
    component->Call( component, idurlsrcvidStepForward, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 101, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 101, data );
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

extern FResult plfapiconn_urlsrcvid_Stop( int winid, Nat32 * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    urlsrcvidStop *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( urlsrcvidStop );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCall, 102, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCall, 102, data );
    }
    component->Call( component, idurlsrcvidStop, (void *)data, &result );
    if ( plfapiconn_hookGlobal )
    {
        (*plfapiconn_hookGlobal)( ipchtCallDone, 102, data );
    }
    if ( plfapiconn_hook_urlsrcvid )
    {
        (*plfapiconn_hook_urlsrcvid)( ipchtCallDone, 102, data );
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


void plfapiconn_EnableNotification_cmdmxN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idcmdmxNOnBufferFull, stub_plfapiconn_cmdmxN_OnBufferFull, NULL );
    component->Listen( component, idcmdmxNOnDataArrived, stub_plfapiconn_cmdmxN_OnDataArrived, NULL );
    component->Listen( component, idcmdmxNOnSystemBitRateChanged, stub_plfapiconn_cmdmxN_OnSystemBitRateChanged, NULL );
}
void plfapiconn_EnableNotification_connitfN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idconnitfNOnAvailabilityChanged, stub_plfapiconn_connitfN_OnAvailabilityChanged, NULL );
}
void plfapiconn_EnableNotification_digadecN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, iddigadecNOnError, stub_plfapiconn_digadecN_OnError, NULL );
}
void plfapiconn_EnableNotification_digvdecN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, iddigvdecNOnError, stub_plfapiconn_digvdecN_OnError, NULL );
    component->Listen( component, iddigvdecNOnStandardDataChanged, stub_plfapiconn_digvdecN_OnStandardDataChanged, NULL );
}
void plfapiconn_EnableNotification_imgdecN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idimgdecNOnEndMetaData, stub_plfapiconn_imgdecN_OnEndMetaData, NULL );
    component->Listen( component, idimgdecNOnFullImageDecoded, stub_plfapiconn_imgdecN_OnFullImageDecoded, NULL );
    component->Listen( component, idimgdecNOnMetaDataFound, stub_plfapiconn_imgdecN_OnMetaDataFound, NULL );
    component->Listen( component, idimgdecNOnResolutionObtained, stub_plfapiconn_imgdecN_OnResolutionObtained, NULL );
    component->Listen( component, idimgdecNOnThumbnailDecoded, stub_plfapiconn_imgdecN_OnThumbnailDecoded, NULL );
    component->Listen( component, idimgdecNOnThumbnailPresence, stub_plfapiconn_imgdecN_OnThumbnailPresence, NULL );
}
void plfapiconn_EnableNotification_mdN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idmdNOnAvTypeNotify, stub_plfapiconn_mdN_OnAvTypeNotify, NULL );
}
void plfapiconn_EnableNotification_urlsrcjpgN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idurlsrcjpgNOnAccessible, stub_plfapiconn_urlsrcjpgN_OnAccessible, NULL );
    component->Listen( component, idurlsrcjpgNOnActionAborted, stub_plfapiconn_urlsrcjpgN_OnActionAborted, NULL );
    component->Listen( component, idurlsrcjpgNOnBufferingStatusChanged, stub_plfapiconn_urlsrcjpgN_OnBufferingStatusChanged, NULL );
    component->Listen( component, idurlsrcjpgNOnConnectionRetry, stub_plfapiconn_urlsrcjpgN_OnConnectionRetry, NULL );
    component->Listen( component, idurlsrcjpgNOnDataConsumed, stub_plfapiconn_urlsrcjpgN_OnDataConsumed, NULL );
    component->Listen( component, idurlsrcjpgNOnEndOfInput, stub_plfapiconn_urlsrcjpgN_OnEndOfInput, NULL );
    component->Listen( component, idurlsrcjpgNOnEndOfRendering, stub_plfapiconn_urlsrcjpgN_OnEndOfRendering, NULL );
    component->Listen( component, idurlsrcjpgNOnNotAccessible, stub_plfapiconn_urlsrcjpgN_OnNotAccessible, NULL );
    component->Listen( component, idurlsrcjpgNOnPlayTimeChanged, stub_plfapiconn_urlsrcjpgN_OnPlayTimeChanged, NULL );
    component->Listen( component, idurlsrcjpgNOnSetPositionAborted, stub_plfapiconn_urlsrcjpgN_OnSetPositionAborted, NULL );
    component->Listen( component, idurlsrcjpgNOnSetPositionCompleted, stub_plfapiconn_urlsrcjpgN_OnSetPositionCompleted, NULL );
    component->Listen( component, idurlsrcjpgNOnTrickControlLost, stub_plfapiconn_urlsrcjpgN_OnTrickControlLost, NULL );
}
void plfapiconn_EnableNotification_urlsrcmp3N(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idurlsrcmp3NOnAccessible, stub_plfapiconn_urlsrcmp3N_OnAccessible, NULL );
    component->Listen( component, idurlsrcmp3NOnActionAborted, stub_plfapiconn_urlsrcmp3N_OnActionAborted, NULL );
    component->Listen( component, idurlsrcmp3NOnBufferingStatusChanged, stub_plfapiconn_urlsrcmp3N_OnBufferingStatusChanged, NULL );
    component->Listen( component, idurlsrcmp3NOnConnectionRetry, stub_plfapiconn_urlsrcmp3N_OnConnectionRetry, NULL );
    component->Listen( component, idurlsrcmp3NOnDataConsumed, stub_plfapiconn_urlsrcmp3N_OnDataConsumed, NULL );
    component->Listen( component, idurlsrcmp3NOnEndOfInput, stub_plfapiconn_urlsrcmp3N_OnEndOfInput, NULL );
    component->Listen( component, idurlsrcmp3NOnEndOfRendering, stub_plfapiconn_urlsrcmp3N_OnEndOfRendering, NULL );
    component->Listen( component, idurlsrcmp3NOnNotAccessible, stub_plfapiconn_urlsrcmp3N_OnNotAccessible, NULL );
    component->Listen( component, idurlsrcmp3NOnPlayTimeChanged, stub_plfapiconn_urlsrcmp3N_OnPlayTimeChanged, NULL );
    component->Listen( component, idurlsrcmp3NOnSetPositionAborted, stub_plfapiconn_urlsrcmp3N_OnSetPositionAborted, NULL );
    component->Listen( component, idurlsrcmp3NOnSetPositionCompleted, stub_plfapiconn_urlsrcmp3N_OnSetPositionCompleted, NULL );
    component->Listen( component, idurlsrcmp3NOnTrickControlLost, stub_plfapiconn_urlsrcmp3N_OnTrickControlLost, NULL );
}
void plfapiconn_EnableNotification_urlsrcvidN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idurlsrcvidNOnAccessible, stub_plfapiconn_urlsrcvidN_OnAccessible, NULL );
    component->Listen( component, idurlsrcvidNOnActionAborted, stub_plfapiconn_urlsrcvidN_OnActionAborted, NULL );
    component->Listen( component, idurlsrcvidNOnBufferingStatusChanged, stub_plfapiconn_urlsrcvidN_OnBufferingStatusChanged, NULL );
    component->Listen( component, idurlsrcvidNOnConnectionRetry, stub_plfapiconn_urlsrcvidN_OnConnectionRetry, NULL );
    component->Listen( component, idurlsrcvidNOnDataConsumed, stub_plfapiconn_urlsrcvidN_OnDataConsumed, NULL );
    component->Listen( component, idurlsrcvidNOnEndOfInput, stub_plfapiconn_urlsrcvidN_OnEndOfInput, NULL );
    component->Listen( component, idurlsrcvidNOnEndOfRendering, stub_plfapiconn_urlsrcvidN_OnEndOfRendering, NULL );
    component->Listen( component, idurlsrcvidNOnNotAccessible, stub_plfapiconn_urlsrcvidN_OnNotAccessible, NULL );
    component->Listen( component, idurlsrcvidNOnPlayTimeChanged, stub_plfapiconn_urlsrcvidN_OnPlayTimeChanged, NULL );
    component->Listen( component, idurlsrcvidNOnSetPositionAborted, stub_plfapiconn_urlsrcvidN_OnSetPositionAborted, NULL );
    component->Listen( component, idurlsrcvidNOnSetPositionCompleted, stub_plfapiconn_urlsrcvidN_OnSetPositionCompleted, NULL );
    component->Listen( component, idurlsrcvidNOnTrickControlLost, stub_plfapiconn_urlsrcvidN_OnTrickControlLost, NULL );
}

void plfapiconn_DisableNotification_cmdmxN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idcmdmxNOnBufferFull );
    component->Unlisten( component, idcmdmxNOnDataArrived );
    component->Unlisten( component, idcmdmxNOnSystemBitRateChanged );
}
void plfapiconn_DisableNotification_connitfN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idconnitfNOnAvailabilityChanged );
}
void plfapiconn_DisableNotification_digadecN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, iddigadecNOnError );
}
void plfapiconn_DisableNotification_digvdecN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, iddigvdecNOnError );
    component->Unlisten( component, iddigvdecNOnStandardDataChanged );
}
void plfapiconn_DisableNotification_imgdecN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idimgdecNOnEndMetaData );
    component->Unlisten( component, idimgdecNOnFullImageDecoded );
    component->Unlisten( component, idimgdecNOnMetaDataFound );
    component->Unlisten( component, idimgdecNOnResolutionObtained );
    component->Unlisten( component, idimgdecNOnThumbnailDecoded );
    component->Unlisten( component, idimgdecNOnThumbnailPresence );
}
void plfapiconn_DisableNotification_mdN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idmdNOnAvTypeNotify );
}
void plfapiconn_DisableNotification_urlsrcjpgN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idurlsrcjpgNOnAccessible );
    component->Unlisten( component, idurlsrcjpgNOnActionAborted );
    component->Unlisten( component, idurlsrcjpgNOnBufferingStatusChanged );
    component->Unlisten( component, idurlsrcjpgNOnConnectionRetry );
    component->Unlisten( component, idurlsrcjpgNOnDataConsumed );
    component->Unlisten( component, idurlsrcjpgNOnEndOfInput );
    component->Unlisten( component, idurlsrcjpgNOnEndOfRendering );
    component->Unlisten( component, idurlsrcjpgNOnNotAccessible );
    component->Unlisten( component, idurlsrcjpgNOnPlayTimeChanged );
    component->Unlisten( component, idurlsrcjpgNOnSetPositionAborted );
    component->Unlisten( component, idurlsrcjpgNOnSetPositionCompleted );
    component->Unlisten( component, idurlsrcjpgNOnTrickControlLost );
}
void plfapiconn_DisableNotification_urlsrcmp3N(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idurlsrcmp3NOnAccessible );
    component->Unlisten( component, idurlsrcmp3NOnActionAborted );
    component->Unlisten( component, idurlsrcmp3NOnBufferingStatusChanged );
    component->Unlisten( component, idurlsrcmp3NOnConnectionRetry );
    component->Unlisten( component, idurlsrcmp3NOnDataConsumed );
    component->Unlisten( component, idurlsrcmp3NOnEndOfInput );
    component->Unlisten( component, idurlsrcmp3NOnEndOfRendering );
    component->Unlisten( component, idurlsrcmp3NOnNotAccessible );
    component->Unlisten( component, idurlsrcmp3NOnPlayTimeChanged );
    component->Unlisten( component, idurlsrcmp3NOnSetPositionAborted );
    component->Unlisten( component, idurlsrcmp3NOnSetPositionCompleted );
    component->Unlisten( component, idurlsrcmp3NOnTrickControlLost );
}
void plfapiconn_DisableNotification_urlsrcvidN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idurlsrcvidNOnAccessible );
    component->Unlisten( component, idurlsrcvidNOnActionAborted );
    component->Unlisten( component, idurlsrcvidNOnBufferingStatusChanged );
    component->Unlisten( component, idurlsrcvidNOnConnectionRetry );
    component->Unlisten( component, idurlsrcvidNOnDataConsumed );
    component->Unlisten( component, idurlsrcvidNOnEndOfInput );
    component->Unlisten( component, idurlsrcvidNOnEndOfRendering );
    component->Unlisten( component, idurlsrcvidNOnNotAccessible );
    component->Unlisten( component, idurlsrcvidNOnPlayTimeChanged );
    component->Unlisten( component, idurlsrcvidNOnSetPositionAborted );
    component->Unlisten( component, idurlsrcvidNOnSetPositionCompleted );
    component->Unlisten( component, idurlsrcvidNOnTrickControlLost );
}

extern void plfapiconn_EnableNotification( int notificationID )
{
    if ( NULL==component )
        return;
    if ( (notificationID < 0) || ( notificationID >= plfapiconnNotificationID_Last ) )
        return;
#ifndef NO_PLFAPICONN_LISTENER_STUBS
    component->Listen( component, notificationID, plfapiconn_listener_stubs[notificationID], NULL );
#endif    
}

extern void plfapiconn_DisableNotification( int notificationID )
{
    if ( NULL==component )
        return;
    if ( (notificationID < 0) || ( notificationID >= plfapiconnNotificationID_Last ) )
        return;
    component->Unlisten( component, notificationID );
}

extern int plfapiconn_Init( int argc, char *argv[] )
{
    DirectResult  ret;
    
    // dfb_config_init( &argc, &argv[] );	// Is this one needed?
    ret = FusionDaleInit( &argc, &argv );
    if (ret)
    {
        D_DERROR( ret, "[plfapiconn-client] FusionDaleInit() failed!\n" );
        return -1;
    }
    ret = FusionDaleCreate( &dale );
    if (ret) {
        D_DERROR( ret, "[plfapiconn-client] FusionDaleCreate() failed!\n" );
        return -2;
    }
    ret = dale->EnterComa( dale, "IPC_plfapiconn", &coma );
    if (ret) {
        D_DERROR( ret, "[plfapiconn-client] IFusionDale::EnterComa('IPC_plfapiconn') failed!\n" );
        return -3;
    }
    ret = coma->GetComponent( coma, "CPlatformApiConnectivity", 0, &component );
    if (ret) {
        D_DERROR( ret, "[plfapiconn-client] IComa::GetComponent('CPlatformApiConnectivity') failed!\n" );
        return -4;
    }
	return 0;
}

extern void plfapiconn_Exit( void )
{
    component->Release( component );
    component = NULL;
    coma->Release( coma );
    coma = NULL;
    dale->Release( dale );
    dale = NULL;
}
