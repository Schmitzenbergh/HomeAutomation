
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


#include "jsApi.h"
#include "jsApi_internal.h"

#include "string.h"
#include "stdio.h"
#include "direct/messages.h"
#include "fusiondale.h"

static IFusionDale     *dale      = NULL;
static IComa           *coma      = NULL;
static IComaComponent  *component = NULL;

/* Hooks: variables */
static IpcHookFunction jsApi_hookGlobal = NULL;
static IpcHookFunction jsApi_hook_js = NULL;

/* Hooks: Implementations */
void jsApi_RegisterHookGlobal( IpcHookFunction callback )
{
    jsApi_hookGlobal = callback;
}

/*  The following function is for the Koala wrapper only */
extern void jsApi_Hook_CallPosted( unsigned int id, void *data )
{
    if (jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDecoupled, id, data );
    }
}

/* HookType: ipchtCallReceived, ipchtCallHandled */
void jsApi_RegisterHook_js( IpcHookFunction callback )
{
    jsApi_hook_js = callback;
}

/* HookType: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */

#define NO_JSAPI_LISTENER_STUBS

extern FResult jsApi_js_AmbiGetConfiguration( int * topology, int * nbrofsegmentsx, int * nbrofsegmentsy, int * nbrofsegmentsz, int * version )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiGetConfiguration *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiGetConfiguration );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 0, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 0, data );
    }
    component->Call( component, idjsAmbiGetConfiguration, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 0, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 0, data );
    }

    /*  5. copy "out" parameters */
    if ( topology != NULL )
    {
        *topology = data->topology;
    }
    if ( nbrofsegmentsx != NULL )
    {
        *nbrofsegmentsx = data->nbrofsegmentsx;
    }
    if ( nbrofsegmentsy != NULL )
    {
        *nbrofsegmentsy = data->nbrofsegmentsy;
    }
    if ( nbrofsegmentsz != NULL )
    {
        *nbrofsegmentsz = data->nbrofsegmentsz;
    }
    if ( version != NULL )
    {
        *version = data->version;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult jsApi_js_AmbiGetMode( int * mode )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiGetMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiGetMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 1, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 1, data );
    }
    component->Call( component, idjsAmbiGetMode, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 1, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 1, data );
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

extern FResult jsApi_js_AmbiGetNbrOfPixelsPerSide( int side, int * nbrofpixels )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiGetNbrOfPixelsPerSide *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiGetNbrOfPixelsPerSide );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->side = side;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 2, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 2, data );
    }
    component->Call( component, idjsAmbiGetNbrOfPixelsPerSide, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 2, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 2, data );
    }

    /*  5. copy "out" parameters */
    if ( nbrofpixels != NULL )
    {
        *nbrofpixels = data->nbrofpixels;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult jsApi_js_AmbiGetPixel( int side, int index, int * red, int * green, int * blue )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiGetPixel *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiGetPixel );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->side = side;
    data->index = index;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 3, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 3, data );
    }
    component->Call( component, idjsAmbiGetPixel, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 3, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 3, data );
    }

    /*  5. copy "out" parameters */
    if ( red != NULL )
    {
        *red = data->red;
    }
    if ( green != NULL )
    {
        *green = data->green;
    }
    if ( blue != NULL )
    {
        *blue = data->blue;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult jsApi_js_AmbiGetPixelArray( int side, int startindex, int size, int * red, int * green, int * blue )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiGetPixelArray *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiGetPixelArray ) + ( sizeof( int ) * size ) + ( sizeof( int ) * size ) + ( sizeof( int ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->red = ( red == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiGetPixelArray) );
    data->green = ( green == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiGetPixelArray) + ( sizeof( int ) * size ) );
    data->blue = ( blue == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiGetPixelArray) + ( sizeof( int ) * size ) + ( sizeof( int ) * size ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->side = side;
    data->startindex = startindex;
    data->size = size;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 4, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 4, data );
    }
    component->Call( component, idjsAmbiGetPixelArray, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 4, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 4, data );
    }

    /*  5. copy "out" parameters */
    if ( red != NULL )
    {
        memcpy( red, data->red,( sizeof( int ) * size ) );
    }
    if ( green != NULL )
    {
        memcpy( green, data->green,( sizeof( int ) * size ) );
    }
    if ( blue != NULL )
    {
        memcpy( blue, data->blue,( sizeof( int ) * size ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult jsApi_js_AmbiGetRawPixel( int side, int index, int * red, int * green, int * blue )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiGetRawPixel *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiGetRawPixel );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->side = side;
    data->index = index;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 5, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 5, data );
    }
    component->Call( component, idjsAmbiGetRawPixel, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 5, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 5, data );
    }

    /*  5. copy "out" parameters */
    if ( red != NULL )
    {
        *red = data->red;
    }
    if ( green != NULL )
    {
        *green = data->green;
    }
    if ( blue != NULL )
    {
        *blue = data->blue;
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult jsApi_js_AmbiGetRawPixelArray( int side, int startindex, int size, int * red, int * green, int * blue )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiGetRawPixelArray *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiGetRawPixelArray ) + ( sizeof( int ) * size ) + ( sizeof( int ) * size ) + ( sizeof( int ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->red = ( red == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiGetRawPixelArray) );
    data->green = ( green == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiGetRawPixelArray) + ( sizeof( int ) * size ) );
    data->blue = ( blue == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiGetRawPixelArray) + ( sizeof( int ) * size ) + ( sizeof( int ) * size ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->side = side;
    data->startindex = startindex;
    data->size = size;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 6, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 6, data );
    }
    component->Call( component, idjsAmbiGetRawPixelArray, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 6, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 6, data );
    }

    /*  5. copy "out" parameters */
    if ( red != NULL )
    {
        memcpy( red, data->red,( sizeof( int ) * size ) );
    }
    if ( green != NULL )
    {
        memcpy( green, data->green,( sizeof( int ) * size ) );
    }
    if ( blue != NULL )
    {
        memcpy( blue, data->blue,( sizeof( int ) * size ) );
    }

    /*  6. free datastructure */
    if ( ComaSize > 4096 )
    {
        coma->FreeLocal( coma );
    }

    /*  7.  return */
    return ( (FResult)result );
}

extern FResult jsApi_js_AmbiIsModeSupported( int mode, Bool * retval )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiIsModeSupported *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiIsModeSupported );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->mode = mode;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 7, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 7, data );
    }
    component->Call( component, idjsAmbiIsModeSupported, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 7, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 7, data );
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

extern FResult jsApi_js_AmbiSetMode( int mode )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiSetMode *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiSetMode );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->mode = mode;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 8, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 8, data );
    }
    component->Call( component, idjsAmbiSetMode, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 8, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 8, data );
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

extern FResult jsApi_js_AmbiSetPixel( int side, int index, int red, int green, int blue )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiSetPixel *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiSetPixel );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->side = side;
    data->index = index;
    data->red = red;
    data->green = green;
    data->blue = blue;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 9, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 9, data );
    }
    component->Call( component, idjsAmbiSetPixel, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 9, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 9, data );
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

extern FResult jsApi_js_AmbiSetPixelArray( int side, int startindex, int size, int * red, int * green, int * blue )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAmbiSetPixelArray *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAmbiSetPixelArray ) + ( sizeof( int ) * size ) + ( sizeof( int ) * size ) + ( sizeof( int ) * size );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }
    data->red = ( red == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiSetPixelArray) );
    data->green = ( green == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiSetPixelArray) + ( sizeof( int ) * size ) );
    data->blue = ( blue == NULL ) ? NULL : (int *)( ((char*)data) + sizeof(jsAmbiSetPixelArray) + ( sizeof( int ) * size ) + ( sizeof( int ) * size ) );

    /*  3. Fill shared data structure (for "in" parameters) */
    data->side = side;
    data->startindex = startindex;
    data->size = size;
    if ( data->red != NULL )
    {
        memcpy( data->red, red, ( sizeof( int ) * size ) );
    }
    if ( data->green != NULL )
    {
        memcpy( data->green, green, ( sizeof( int ) * size ) );
    }
    if ( data->blue != NULL )
    {
        memcpy( data->blue, blue, ( sizeof( int ) * size ) );
    }

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 10, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 10, data );
    }
    component->Call( component, idjsAmbiSetPixelArray, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 10, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 10, data );
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

extern FResult jsApi_js_AudioGetBass( int value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAudioGetBass *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAudioGetBass );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->value = value;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 11, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 11, data );
    }
    component->Call( component, idjsAudioGetBass, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 11, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 11, data );
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

extern FResult jsApi_js_AudioGetTreble( int value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAudioGetTreble *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAudioGetTreble );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->value = value;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 12, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 12, data );
    }
    component->Call( component, idjsAudioGetTreble, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 12, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 12, data );
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

extern FResult jsApi_js_AudioGetVolume( int value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAudioGetVolume *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAudioGetVolume );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->value = value;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 13, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 13, data );
    }
    component->Call( component, idjsAudioGetVolume, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 13, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 13, data );
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

extern FResult jsApi_js_AudioSetBass( int value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAudioSetBass *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAudioSetBass );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->value = value;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 14, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 14, data );
    }
    component->Call( component, idjsAudioSetBass, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 14, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 14, data );
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

extern FResult jsApi_js_AudioSetTreble( int value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAudioSetTreble *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAudioSetTreble );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->value = value;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 15, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 15, data );
    }
    component->Call( component, idjsAudioSetTreble, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 15, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 15, data );
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

extern FResult jsApi_js_AudioSetVolume( int value )
{

    /*  0. protection in the supplier */

    /*  1. local variables */
    jsAudioSetVolume *data = NULL;
    DirectResult ret = 0;
    int ComaSize = 0;
    int result = 0;

    /*  2. Allocate shared data structure */
    ComaSize = sizeof( jsAudioSetVolume );
    ret = coma->GetLocal( coma, ComaSize, (void *)&data );
    if ( ret )
    {
        D_DERROR( ret, "IComa::GetLocal failed for %d bytes)\n", (int)( ComaSize ) );
    }

    /*  3. Fill shared data structure (for "in" parameters) */
    data->value = value;

    /*  4. Actual call */
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCall, 16, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCall, 16, data );
    }
    component->Call( component, idjsAudioSetVolume, (void *)data, &result );
    if ( jsApi_hookGlobal )
    {
        (*jsApi_hookGlobal)( ipchtCallDone, 16, data );
    }
    if ( jsApi_hook_js )
    {
        (*jsApi_hook_js)( ipchtCallDone, 16, data );
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




extern void jsApi_EnableNotification( int notificationID )
{
    if ( NULL==component )
        return;
    if ( (notificationID < 0) || ( notificationID >= jsApiNotificationID_Last ) )
        return;
#ifndef NO_JSAPI_LISTENER_STUBS
    component->Listen( component, notificationID, jsApi_listener_stubs[notificationID], NULL );
#endif    
}

extern void jsApi_DisableNotification( int notificationID )
{
    if ( NULL==component )
        return;
    if ( (notificationID < 0) || ( notificationID >= jsApiNotificationID_Last ) )
        return;
    component->Unlisten( component, notificationID );
}

extern int jsApi_Init( int argc, char *argv[] )
{
    DirectResult  ret;
    
    // dfb_config_init( &argc, &argv[] );	// Is this one needed?
    ret = FusionDaleInit( &argc, &argv );
    if (ret)
    {
        D_DERROR( ret, "[jsApi-client] FusionDaleInit() failed!\n" );
        return -1;
    }
    ret = FusionDaleCreate( &dale );
    if (ret) {
        D_DERROR( ret, "[jsApi-client] FusionDaleCreate() failed!\n" );
        return -2;
    }
    ret = dale->EnterComa( dale, "IPC_jsApi", &coma );
    if (ret) {
        D_DERROR( ret, "[jsApi-client] IFusionDale::EnterComa('IPC_jsApi') failed!\n" );
        return -3;
    }
    ret = coma->GetComponent( coma, "CPlatformApiJointSpace", 0, &component );
    if (ret) {
        D_DERROR( ret, "[jsApi-client] IComa::GetComponent('CPlatformApiJointSpace') failed!\n" );
        return -4;
    }
	return 0;
}

extern void jsApi_Exit( void )
{
    component->Release( component );
    component = NULL;
    coma->Release( coma );
    coma = NULL;
    dale->Release( dale );
    dale = NULL;
}
