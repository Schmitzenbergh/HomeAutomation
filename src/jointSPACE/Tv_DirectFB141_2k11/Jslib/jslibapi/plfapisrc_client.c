
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


#include "plfapisrc.h"
#include "plfapisrc_internal.h"

#include "string.h"
#include "stdio.h"
#include "direct/messages.h"
#include "fusiondale.h"

static IFusionDale     *dale      = NULL;
static IComa           *coma      = NULL;
static IComaComponent  *component = NULL;

/* Hooks: variables */
static IpcHookFunction plfapisrc_hookGlobal = NULL;
static IpcHookFunction plfapisrc_hook_amut2 = NULL;
static IpcHookFunction plfapisrc_hook_brk = NULL;
static IpcHookFunction plfapisrc_hook_conf = NULL;
static IpcHookFunction plfapisrc_hook_dsgid = NULL;
static IpcHookFunction plfapisrc_hook_errid = NULL;
static IpcHookFunction plfapisrc_hook_src = NULL;
static IpcHookFunction plfapisrc_hook_srcid = NULL;
static IpcHookFunction plfapisrc_hook_srcitf = NULL;
static IpcHookFunction plfapisrc_hook_srcitfid = NULL;
static IpcHookFunction plfapisrc_hook_vmut2 = NULL;
static IpcHookFunction plfapisrc_hook_brkN = NULL;
static IpcHookFunction plfapisrc_hook_src2N = NULL;
static IpcHookFunction plfapisrc_hook_srcitfN = NULL;
static IpcHookFunction plfapisrc_hook_srcN = NULL;

/* Hooks: Implementations */
void plfapisrc_RegisterHookGlobal( IpcHookFunction callback )
{
    plfapisrc_hookGlobal = callback;
}

/*  The following function is for the Koala wrapper only */
extern void plfapisrc_Hook_CallPosted( unsigned int id, void *data )
{
    if (plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDecoupled, id, data );
    }
}

/* HookType: ipchtCallReceived, ipchtCallHandled */
void plfapisrc_RegisterHook_amut2( IpcHookFunction callback )
{
    plfapisrc_hook_amut2 = callback;
}

void plfapisrc_RegisterHook_brk( IpcHookFunction callback )
{
    plfapisrc_hook_brk = callback;
}

void plfapisrc_RegisterHook_conf( IpcHookFunction callback )
{
    plfapisrc_hook_conf = callback;
}

void plfapisrc_RegisterHook_dsgid( IpcHookFunction callback )
{
    plfapisrc_hook_dsgid = callback;
}

void plfapisrc_RegisterHook_errid( IpcHookFunction callback )
{
    plfapisrc_hook_errid = callback;
}

void plfapisrc_RegisterHook_src( IpcHookFunction callback )
{
    plfapisrc_hook_src = callback;
}

void plfapisrc_RegisterHook_srcid( IpcHookFunction callback )
{
    plfapisrc_hook_srcid = callback;
}

void plfapisrc_RegisterHook_srcitf( IpcHookFunction callback )
{
    plfapisrc_hook_srcitf = callback;
}

void plfapisrc_RegisterHook_srcitfid( IpcHookFunction callback )
{
    plfapisrc_hook_srcitfid = callback;
}

void plfapisrc_RegisterHook_vmut2( IpcHookFunction callback )
{
    plfapisrc_hook_vmut2 = callback;
}

/* HookType: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
void plfapisrc_RegisterHook_brkN( IpcHookFunction callback )
{
    plfapisrc_hook_brkN = callback;
}

void plfapisrc_RegisterHook_src2N( IpcHookFunction callback )
{
    plfapisrc_hook_src2N = callback;
}

void plfapisrc_RegisterHook_srcitfN( IpcHookFunction callback )
{
    plfapisrc_hook_srcitfN = callback;
}

void plfapisrc_RegisterHook_srcN( IpcHookFunction callback )
{
    plfapisrc_hook_srcN = callback;
}

#if defined(USE_WEAK_NOTIFICATIONS)
void plfapisrc_brkN_OnDestinationStatusChanged( tmPlfInstPreset_Destination_t destination, Bool status ) WEAK;
void plfapisrc_brkN_OnExtensionStatusChanged( tmPlfInstPreset_Source_t source, Bool status ) WEAK;
void plfapisrc_src2N_OnAudioSourceSelected( int audionodeid, int source ) WEAK;
void plfapisrc_src2N_OnSourceSettingsApplied( int winid ) WEAK;
void plfapisrc_src2N_OnVideoSourceSelected( int winid, int source ) WEAK;
void plfapisrc_srcitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids ) WEAK;
void plfapisrc_srcN_OnAudioSourceSelected( int audionodeid, int source ) WEAK;
void plfapisrc_srcN_OnSourceSettingsApplied( void ) WEAK;
void plfapisrc_srcN_OnVideoSourceSelected( int winid, int source ) WEAK;

void plfapisrc_brkN_OnDestinationStatusChanged( tmPlfInstPreset_Destination_t destination, Bool status )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 0, NULL );
    }
    if ( plfapisrc_hook_brkN )
    {
        (*plfapisrc_hook_brkN)( ipchtNotificationDiscarded, 0, NULL );
    }
    /* do nothing */
    (void)destination;
    (void)status;
}

void plfapisrc_brkN_OnExtensionStatusChanged( tmPlfInstPreset_Source_t source, Bool status )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 1, NULL );
    }
    if ( plfapisrc_hook_brkN )
    {
        (*plfapisrc_hook_brkN)( ipchtNotificationDiscarded, 1, NULL );
    }
    /* do nothing */
    (void)source;
    (void)status;
}

void plfapisrc_src2N_OnAudioSourceSelected( int audionodeid, int source )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 2, NULL );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationDiscarded, 2, NULL );
    }
    /* do nothing */
    (void)audionodeid;
    (void)source;
}

void plfapisrc_src2N_OnSourceSettingsApplied( int winid )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 3, NULL );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationDiscarded, 3, NULL );
    }
    /* do nothing */
    (void)winid;
}

void plfapisrc_src2N_OnVideoSourceSelected( int winid, int source )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 4, NULL );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationDiscarded, 4, NULL );
    }
    /* do nothing */
    (void)winid;
    (void)source;
}

void plfapisrc_srcitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 5, NULL );
    }
    if ( plfapisrc_hook_srcitfN )
    {
        (*plfapisrc_hook_srcitfN)( ipchtNotificationDiscarded, 5, NULL );
    }
    /* do nothing */
    (void)nbrgroups;
    (void)ids;
}

void plfapisrc_srcN_OnAudioSourceSelected( int audionodeid, int source )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 6, NULL );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationDiscarded, 6, NULL );
    }
    /* do nothing */
    (void)audionodeid;
    (void)source;
}

void plfapisrc_srcN_OnSourceSettingsApplied( void )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 7, NULL );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationDiscarded, 7, NULL );
    }
    /* do nothing */
}

void plfapisrc_srcN_OnVideoSourceSelected( int winid, int source )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationDiscarded, 8, NULL );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationDiscarded, 8, NULL );
    }
    /* do nothing */
    (void)winid;
    (void)source;
}

#endif /* USE_WEAK_NOTIFICATIONS */

static void stub_plfapisrc_brkN_OnDestinationStatusChanged( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 0, arg );
    }
    if ( plfapisrc_hook_brkN )
    {
        (*plfapisrc_hook_brkN)( ipchtNotificationReceived, 0, arg );
    }
    brkNOnDestinationStatusChanged * data = (brkNOnDestinationStatusChanged *)arg;
    (void)ctx;
    plfapisrc_brkN_OnDestinationStatusChanged( data->destination, data->status );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 0, arg );
    }
    if ( plfapisrc_hook_brkN )
    {
        (*plfapisrc_hook_brkN)( ipchtNotificationHandled, 0, arg );
    }
    return;
}

static void stub_plfapisrc_brkN_OnExtensionStatusChanged( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 1, arg );
    }
    if ( plfapisrc_hook_brkN )
    {
        (*plfapisrc_hook_brkN)( ipchtNotificationReceived, 1, arg );
    }
    brkNOnExtensionStatusChanged * data = (brkNOnExtensionStatusChanged *)arg;
    (void)ctx;
    plfapisrc_brkN_OnExtensionStatusChanged( data->source, data->status );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 1, arg );
    }
    if ( plfapisrc_hook_brkN )
    {
        (*plfapisrc_hook_brkN)( ipchtNotificationHandled, 1, arg );
    }
    return;
}

static void stub_plfapisrc_src2N_OnAudioSourceSelected( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 2, arg );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationReceived, 2, arg );
    }
    src2NOnAudioSourceSelected * data = (src2NOnAudioSourceSelected *)arg;
    (void)ctx;
    plfapisrc_src2N_OnAudioSourceSelected( data->audionodeid, data->source );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 2, arg );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationHandled, 2, arg );
    }
    return;
}

static void stub_plfapisrc_src2N_OnSourceSettingsApplied( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 3, arg );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationReceived, 3, arg );
    }
    src2NOnSourceSettingsApplied * data = (src2NOnSourceSettingsApplied *)arg;
    (void)ctx;
    plfapisrc_src2N_OnSourceSettingsApplied( data->winid );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 3, arg );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationHandled, 3, arg );
    }
    return;
}

static void stub_plfapisrc_src2N_OnVideoSourceSelected( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 4, arg );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationReceived, 4, arg );
    }
    src2NOnVideoSourceSelected * data = (src2NOnVideoSourceSelected *)arg;
    (void)ctx;
    plfapisrc_src2N_OnVideoSourceSelected( data->winid, data->source );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 4, arg );
    }
    if ( plfapisrc_hook_src2N )
    {
        (*plfapisrc_hook_src2N)( ipchtNotificationHandled, 4, arg );
    }
    return;
}

static void stub_plfapisrc_srcitfN_OnAvailabilityChanged( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 5, arg );
    }
    if ( plfapisrc_hook_srcitfN )
    {
        (*plfapisrc_hook_srcitfN)( ipchtNotificationReceived, 5, arg );
    }
    srcitfNOnAvailabilityChanged * data = (srcitfNOnAvailabilityChanged *)arg;
    (void)ctx;
    plfapisrc_srcitfN_OnAvailabilityChanged( data->nbrgroups, (Nat32 *)data->ids );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 5, arg );
    }
    if ( plfapisrc_hook_srcitfN )
    {
        (*plfapisrc_hook_srcitfN)( ipchtNotificationHandled, 5, arg );
    }
    return;
}

static void stub_plfapisrc_srcN_OnAudioSourceSelected( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 6, arg );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationReceived, 6, arg );
    }
    srcNOnAudioSourceSelected * data = (srcNOnAudioSourceSelected *)arg;
    (void)ctx;
    plfapisrc_srcN_OnAudioSourceSelected( data->audionodeid, data->source );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 6, arg );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationHandled, 6, arg );
    }
    return;
}

static void stub_plfapisrc_srcN_OnSourceSettingsApplied( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 7, arg );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationReceived, 7, arg );
    }
    (void)ctx;
    plfapisrc_srcN_OnSourceSettingsApplied();
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 7, arg );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationHandled, 7, arg );
    }
    return;
}

static void stub_plfapisrc_srcN_OnVideoSourceSelected( void *ctx, void *arg )
{
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationReceived, 8, arg );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationReceived, 8, arg );
    }
    srcNOnVideoSourceSelected * data = (srcNOnVideoSourceSelected *)arg;
    (void)ctx;
    plfapisrc_srcN_OnVideoSourceSelected( data->winid, data->source );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtNotificationHandled, 8, arg );
    }
    if ( plfapisrc_hook_srcN )
    {
        (*plfapisrc_hook_srcN)( ipchtNotificationHandled, 8, arg );
    }
    return;
}


static ComaListenerFunc plfapisrc_listener_stubs[] = {
     stub_plfapisrc_brkN_OnDestinationStatusChanged
    ,stub_plfapisrc_brkN_OnExtensionStatusChanged
    ,stub_plfapisrc_src2N_OnAudioSourceSelected
    ,stub_plfapisrc_src2N_OnSourceSettingsApplied
    ,stub_plfapisrc_src2N_OnVideoSourceSelected
    ,stub_plfapisrc_srcitfN_OnAvailabilityChanged
    ,stub_plfapisrc_srcN_OnAudioSourceSelected
    ,stub_plfapisrc_srcN_OnSourceSettingsApplied
    ,stub_plfapisrc_srcN_OnVideoSourceSelected
};

extern FResult plfapisrc_amut2_Disable( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    amut2Disable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( amut2Disable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 0, data );
    }
    if ( plfapisrc_hook_amut2 )
    {
        (*plfapisrc_hook_amut2)( ipchtCall, 0, data );
    }
    component->Call( component, idamut2Disable, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 0, data );
    }
    if ( plfapisrc_hook_amut2 )
    {
        (*plfapisrc_hook_amut2)( ipchtCallDone, 0, data );
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

extern FResult plfapisrc_amut2_Enable( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    amut2Enable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( amut2Enable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 1, data );
    }
    if ( plfapisrc_hook_amut2 )
    {
        (*plfapisrc_hook_amut2)( ipchtCall, 1, data );
    }
    component->Call( component, idamut2Enable, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 1, data );
    }
    if ( plfapisrc_hook_amut2 )
    {
        (*plfapisrc_hook_amut2)( ipchtCallDone, 1, data );
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

extern FResult plfapisrc_amut2_IsEnabled( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    amut2IsEnabled *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( amut2IsEnabled );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 2, data );
    }
    if ( plfapisrc_hook_amut2 )
    {
        (*plfapisrc_hook_amut2)( ipchtCall, 2, data );
    }
    component->Call( component, idamut2IsEnabled, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 2, data );
    }
    if ( plfapisrc_hook_amut2 )
    {
        (*plfapisrc_hook_amut2)( ipchtCallDone, 2, data );
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

extern FResult plfapisrc_brk_DestinationExists( int winid, tmPlfInstPreset_Destination_t destination, Bool * Exists )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkDestinationExists *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkDestinationExists );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->destination = destination;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 3, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 3, data );
    }
    component->Call( component, idbrkDestinationExists, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 3, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 3, data );
    }

    /*  5. copy "out" parameters */
    if ( Exists != NULL )
    {
        *Exists = data->Exists;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_brk_DestinationStatus( int winid, tmPlfInstPreset_Destination_t destination, Bool * pStatus )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkDestinationStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkDestinationStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->destination = destination;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 4, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 4, data );
    }
    component->Call( component, idbrkDestinationStatus, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 4, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 4, data );
    }

    /*  5. copy "out" parameters */
    if ( pStatus != NULL )
    {
        *pStatus = data->pStatus;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_brk_ExtensionStatus( int winid, tmPlfInstPreset_Source_t source, Bool * Status )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkExtensionStatus *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkExtensionStatus );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 5, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 5, data );
    }
    component->Call( component, idbrkExtensionStatus, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 5, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 5, data );
    }

    /*  5. copy "out" parameters */
    if ( Status != NULL )
    {
        *Status = data->Status;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_brk_GetDestinationType( int winid, tmPlfInstPreset_Destination_t destination, tmPlfInstPreset_DestinationType_t * DestinationType )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkGetDestinationType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkGetDestinationType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->destination = destination;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 6, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 6, data );
    }
    component->Call( component, idbrkGetDestinationType, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 6, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 6, data );
    }

    /*  5. copy "out" parameters */
    if ( DestinationType != NULL )
    {
        *DestinationType = data->DestinationType;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_brk_GetSourceType( int winid, tmPlfInstPreset_Source_t source, tmPlfInstPreset_SourceType_t * SourceType )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkGetSourceType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkGetSourceType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 7, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 7, data );
    }
    component->Call( component, idbrkGetSourceType, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 7, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 7, data );
    }

    /*  5. copy "out" parameters */
    if ( SourceType != NULL )
    {
        *SourceType = data->SourceType;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_brk_SetDestinationType( int winid, tmPlfInstPreset_Destination_t destination, tmPlfInstPreset_DestinationType_t destinationType )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkSetDestinationType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkSetDestinationType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->destination = destination;
    data->destinationType = destinationType;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 8, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 8, data );
    }
    component->Call( component, idbrkSetDestinationType, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 8, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 8, data );
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

extern FResult plfapisrc_brk_SetSourceType( int winid, tmPlfInstPreset_Source_t source, tmPlfInstPreset_SourceType_t sourceType )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkSetSourceType *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkSetSourceType );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->sourceType = sourceType;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 9, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 9, data );
    }
    component->Call( component, idbrkSetSourceType, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 9, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 9, data );
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

extern FResult plfapisrc_brk_SourceExists( int winid, tmPlfInstPreset_Source_t source, Bool * Exists )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkSourceExists *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkSourceExists );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 10, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 10, data );
    }
    component->Call( component, idbrkSourceExists, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 10, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 10, data );
    }

    /*  5. copy "out" parameters */
    if ( Exists != NULL )
    {
        *Exists = data->Exists;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_brk_SourceTypeSupported( int winid, tmPlfInstPreset_Source_t source, tmPlfInstPreset_SourceType_t sourceType, Bool * Supported )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    brkSourceTypeSupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( brkSourceTypeSupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->sourceType = sourceType;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 11, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCall, 11, data );
    }
    component->Call( component, idbrkSourceTypeSupported, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 11, data );
    }
    if ( plfapisrc_hook_brk )
    {
        (*plfapisrc_hook_brk)( ipchtCallDone, 11, data );
    }

    /*  5. copy "out" parameters */
    if ( Supported != NULL )
    {
        *Supported = data->Supported;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_conf_AssociateSoundInput( int source, int assoc )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    confAssociateSoundInput *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( confAssociateSoundInput );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->source = source;
    data->assoc = assoc;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 12, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCall, 12, data );
    }
    component->Call( component, idconfAssociateSoundInput, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 12, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCallDone, 12, data );
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

extern FResult plfapisrc_conf_EnablePcMode( int source, Bool ena )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    confEnablePcMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( confEnablePcMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->source = source;
    data->ena = ena;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 13, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCall, 13, data );
    }
    component->Call( component, idconfEnablePcMode, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 13, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCallDone, 13, data );
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

extern FResult plfapisrc_conf_GetAssociatedSoundInput( int source, int * assoc )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    confGetAssociatedSoundInput *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( confGetAssociatedSoundInput );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->source = source;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 14, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCall, 14, data );
    }
    component->Call( component, idconfGetAssociatedSoundInput, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 14, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCallDone, 14, data );
    }

    /*  5. copy "out" parameters */
    if ( assoc != NULL )
    {
        *assoc = data->assoc;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_conf_GetMonitorOutMode( int * mode )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    confGetMonitorOutMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( confGetMonitorOutMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 15, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCall, 15, data );
    }
    component->Call( component, idconfGetMonitorOutMode, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 15, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCallDone, 15, data );
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

extern FResult plfapisrc_conf_GetTunerMedium( int * medium )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    confGetTunerMedium *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( confGetTunerMedium );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 16, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCall, 16, data );
    }
    component->Call( component, idconfGetTunerMedium, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 16, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCallDone, 16, data );
    }

    /*  5. copy "out" parameters */
    if ( medium != NULL )
    {
        *medium = data->medium;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_conf_IsAssociateSoundInputAllowed( int source, int assoc, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    confIsAssociateSoundInputAllowed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( confIsAssociateSoundInputAllowed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->source = source;
    data->assoc = assoc;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 17, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCall, 17, data );
    }
    component->Call( component, idconfIsAssociateSoundInputAllowed, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 17, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCallDone, 17, data );
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

extern FResult plfapisrc_conf_SetMonitorOutMode( int mode )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    confSetMonitorOutMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( confSetMonitorOutMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->mode = mode;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 18, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCall, 18, data );
    }
    component->Call( component, idconfSetMonitorOutMode, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 18, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCallDone, 18, data );
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

extern FResult plfapisrc_conf_SetTunerMedium( int medium )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    confSetTunerMedium *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( confSetTunerMedium );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->medium = medium;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 19, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCall, 19, data );
    }
    component->Call( component, idconfSetTunerMedium, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 19, data );
    }
    if ( plfapisrc_hook_conf )
    {
        (*plfapisrc_hook_conf)( ipchtCallDone, 19, data );
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

extern FResult plfapisrc_src_ApplySourceSettings( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcApplySourceSettings *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcApplySourceSettings );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 20, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCall, 20, data );
    }
    component->Call( component, idsrcApplySourceSettings, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 20, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCallDone, 20, data );
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

extern FResult plfapisrc_src_GetCurrentAudioSelection( int audionodeid, int * source, Nat32 * designator )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcGetCurrentAudioSelection *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcGetCurrentAudioSelection );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->audionodeid = audionodeid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 21, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCall, 21, data );
    }
    component->Call( component, idsrcGetCurrentAudioSelection, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 21, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCallDone, 21, data );
    }

    /*  5. copy "out" parameters */
    if ( source != NULL )
    {
        *source = data->source;
    }
    if ( designator != NULL )
    {
        *designator = data->designator;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_src_GetCurrentVideoSelection( int winid, int * source, Nat32 * designator )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcGetCurrentVideoSelection *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcGetCurrentVideoSelection );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 22, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCall, 22, data );
    }
    component->Call( component, idsrcGetCurrentVideoSelection, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 22, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCallDone, 22, data );
    }

    /*  5. copy "out" parameters */
    if ( source != NULL )
    {
        *source = data->source;
    }
    if ( designator != NULL )
    {
        *designator = data->designator;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_src_GetSourceCapabilities( int winid, int source, int * sourceSignalType, int * sourceType )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcGetSourceCapabilities *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcGetSourceCapabilities );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 23, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCall, 23, data );
    }
    component->Call( component, idsrcGetSourceCapabilities, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 23, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCallDone, 23, data );
    }

    /*  5. copy "out" parameters */
    if ( sourceSignalType != NULL )
    {
        *sourceSignalType = data->sourceSignalType;
    }
    if ( sourceType != NULL )
    {
        *sourceType = data->sourceType;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult plfapisrc_src_IsAudioSelectionAllowed( int audionodeid, int source, Nat32 designator, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcIsAudioSelectionAllowed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcIsAudioSelectionAllowed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->audionodeid = audionodeid;
    data->source = source;
    data->designator = designator;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 24, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCall, 24, data );
    }
    component->Call( component, idsrcIsAudioSelectionAllowed, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 24, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCallDone, 24, data );
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

extern FResult plfapisrc_src_IsVideoSelectionAllowed( int winid, int source, Nat32 designator, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcIsVideoSelectionAllowed *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcIsVideoSelectionAllowed );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->designator = designator;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 25, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCall, 25, data );
    }
    component->Call( component, idsrcIsVideoSelectionAllowed, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 25, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCallDone, 25, data );
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

extern FResult plfapisrc_src_SelectAudioSource( int audionodeid, int source, Nat32 designator, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcSelectAudioSource *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcSelectAudioSource );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->audionodeid = audionodeid;
    data->source = source;
    data->designator = designator;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 26, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCall, 26, data );
    }
    component->Call( component, idsrcSelectAudioSource, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 26, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCallDone, 26, data );
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

extern FResult plfapisrc_src_SelectVideoSource( int winid, int source, Nat32 designator, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcSelectVideoSource *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcSelectVideoSource );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;
    data->source = source;
    data->designator = designator;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 27, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCall, 27, data );
    }
    component->Call( component, idsrcSelectVideoSource, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 27, data );
    }
    if ( plfapisrc_hook_src )
    {
        (*plfapisrc_hook_src)( ipchtCallDone, 27, data );
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

extern FResult plfapisrc_srcitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    srcitfGetAvailableInterfaces *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( srcitfGetAvailableInterfaces );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 28, data );
    }
    if ( plfapisrc_hook_srcitf )
    {
        (*plfapisrc_hook_srcitf)( ipchtCall, 28, data );
    }
    component->Call( component, idsrcitfGetAvailableInterfaces, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 28, data );
    }
    if ( plfapisrc_hook_srcitf )
    {
        (*plfapisrc_hook_srcitf)( ipchtCallDone, 28, data );
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

extern FResult plfapisrc_vmut2_Disable( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vmut2Disable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vmut2Disable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 29, data );
    }
    if ( plfapisrc_hook_vmut2 )
    {
        (*plfapisrc_hook_vmut2)( ipchtCall, 29, data );
    }
    component->Call( component, idvmut2Disable, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 29, data );
    }
    if ( plfapisrc_hook_vmut2 )
    {
        (*plfapisrc_hook_vmut2)( ipchtCallDone, 29, data );
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

extern FResult plfapisrc_vmut2_Enable( int winid )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vmut2Enable *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vmut2Enable );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 30, data );
    }
    if ( plfapisrc_hook_vmut2 )
    {
        (*plfapisrc_hook_vmut2)( ipchtCall, 30, data );
    }
    component->Call( component, idvmut2Enable, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 30, data );
    }
    if ( plfapisrc_hook_vmut2 )
    {
        (*plfapisrc_hook_vmut2)( ipchtCallDone, 30, data );
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

extern FResult plfapisrc_vmut2_IsEnabled( int winid, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    vmut2IsEnabled *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( vmut2IsEnabled );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->winid = winid;

    /*  4. Actual call */
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCall, 31, data );
    }
    if ( plfapisrc_hook_vmut2 )
    {
        (*plfapisrc_hook_vmut2)( ipchtCall, 31, data );
    }
    component->Call( component, idvmut2IsEnabled, (void *)data, &result );
    if ( plfapisrc_hookGlobal )
    {
        (*plfapisrc_hookGlobal)( ipchtCallDone, 31, data );
    }
    if ( plfapisrc_hook_vmut2 )
    {
        (*plfapisrc_hook_vmut2)( ipchtCallDone, 31, data );
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


void plfapisrc_EnableNotification_brkN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idbrkNOnDestinationStatusChanged, stub_plfapisrc_brkN_OnDestinationStatusChanged, NULL );
    component->Listen( component, idbrkNOnExtensionStatusChanged, stub_plfapisrc_brkN_OnExtensionStatusChanged, NULL );
}
void plfapisrc_EnableNotification_src2N(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idsrc2NOnAudioSourceSelected, stub_plfapisrc_src2N_OnAudioSourceSelected, NULL );
    component->Listen( component, idsrc2NOnSourceSettingsApplied, stub_plfapisrc_src2N_OnSourceSettingsApplied, NULL );
    component->Listen( component, idsrc2NOnVideoSourceSelected, stub_plfapisrc_src2N_OnVideoSourceSelected, NULL );
}
void plfapisrc_EnableNotification_srcitfN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idsrcitfNOnAvailabilityChanged, stub_plfapisrc_srcitfN_OnAvailabilityChanged, NULL );
}
void plfapisrc_EnableNotification_srcN(void)
{
    if ( NULL==component )
        return;
    component->Listen( component, idsrcNOnAudioSourceSelected, stub_plfapisrc_srcN_OnAudioSourceSelected, NULL );
    component->Listen( component, idsrcNOnSourceSettingsApplied, stub_plfapisrc_srcN_OnSourceSettingsApplied, NULL );
    component->Listen( component, idsrcNOnVideoSourceSelected, stub_plfapisrc_srcN_OnVideoSourceSelected, NULL );
}

void plfapisrc_DisableNotification_brkN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idbrkNOnDestinationStatusChanged );
    component->Unlisten( component, idbrkNOnExtensionStatusChanged );
}
void plfapisrc_DisableNotification_src2N(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idsrc2NOnAudioSourceSelected );
    component->Unlisten( component, idsrc2NOnSourceSettingsApplied );
    component->Unlisten( component, idsrc2NOnVideoSourceSelected );
}
void plfapisrc_DisableNotification_srcitfN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idsrcitfNOnAvailabilityChanged );
}
void plfapisrc_DisableNotification_srcN(void)
{
    if ( NULL==component )
        return;
    component->Unlisten( component, idsrcNOnAudioSourceSelected );
    component->Unlisten( component, idsrcNOnSourceSettingsApplied );
    component->Unlisten( component, idsrcNOnVideoSourceSelected );
}

extern void plfapisrc_EnableNotification( int notificationID )
{
    if ( NULL==component )
        return;
    if ( (notificationID < 0) || ( notificationID >= plfapisrcNotificationID_Last ) )
        return;
#ifndef NO_PLFAPISRC_LISTENER_STUBS
    component->Listen( component, notificationID, plfapisrc_listener_stubs[notificationID], NULL );
#endif    
}

extern void plfapisrc_DisableNotification( int notificationID )
{
    if ( NULL==component )
        return;
    if ( (notificationID < 0) || ( notificationID >= plfapisrcNotificationID_Last ) )
        return;
    component->Unlisten( component, notificationID );
}

extern int plfapisrc_Init( int argc, char *argv[] )
{
    DirectResult  ret;
    
    // dfb_config_init( &argc, &argv[] );	// Is this one needed?
    ret = FusionDaleInit( &argc, &argv );
    if (ret)
    {
        D_DERROR( ret, "[plfapisrc-client] FusionDaleInit() failed!\n" );
        return -1;
    }
    ret = FusionDaleCreate( &dale );
    if (ret) {
        D_DERROR( ret, "[plfapisrc-client] FusionDaleCreate() failed!\n" );
        return -2;
    }
    ret = dale->EnterComa( dale, "IPC_plfapisrc", &coma );
    if (ret) {
        D_DERROR( ret, "[plfapisrc-client] IFusionDale::EnterComa('IPC_plfapisrc') failed!\n" );
        return -3;
    }
    ret = coma->GetComponent( coma, "CPlatformApiSource", 0, &component );
    if (ret) {
        D_DERROR( ret, "[plfapisrc-client] IComa::GetComponent('CPlatformApiSource') failed!\n" );
        return -4;
    }
	return 0;
}

extern void plfapisrc_Exit( void )
{
    component->Release( component );
    component = NULL;
    coma->Release( coma );
    coma = NULL;
    dale->Release( dale );
    dale = NULL;
}
