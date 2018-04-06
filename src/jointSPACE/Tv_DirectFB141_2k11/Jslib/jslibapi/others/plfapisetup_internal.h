
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


#if !defined(_PLFAPISETUP_INTERNAL_H_)
#define _PLFAPISETUP_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
} blkEnableBlanking;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} blkIsBlanked;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} blkIsBlankingEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool blanked; //in,  
} blkSetBlanked;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int color; //in,  
} blkSetBlankingColor;

typedef struct {
    unsigned int callcookie;
    int destid; //in,  
    int windowid; //in,  
    Bool IsBorder; //in,  
} dstAttachClient;

typedef struct {
    unsigned int callcookie;
    int destid; //in,  
    int windowid; //in,  
} dstDetachClient;

typedef struct {
    unsigned int callcookie;
    int destid; //in,  
    int windowid; //in,  
    Bool IsBorder; //in,  
} dstSetDestination;

typedef struct {
    unsigned int callcookie;
    int streamid; //in,  
    int ul_x; //in,  
    int ul_y; //in,  
    int lr_x; //in,  
    int lr_y; //in,  
    Bool retval; //out,  
} dstSetVideoCoordinates;

typedef struct {
    unsigned int callcookie;
    int mode; //in,  
    Bool retval; //out,  
} dstSetVideoOutputMode;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} dst2ApplyDestinationSettings;

typedef struct {
    unsigned int callcookie;
    int destid; //in,  
    int windowid; //in,  
    Bool IsBorder; //in,  
} dst2AttachClient;

typedef struct {
    unsigned int callcookie;
    int destid; //in,  
    int windowid; //in,  
} dst2DetachClient;

typedef struct {
    unsigned int callcookie;
    int destid; //in,  
    int destprop; //in,  
    int windowid; //in,  
    Bool IsBorder; //in,  
} dst2SetDestination;

typedef struct {
    unsigned int callcookie;
    int destid; //in,  
    int ul_x; //in,  
    int ul_y; //in,  
    int lr_x; //in,  
    int lr_y; //in,  
} dst2SetVideoCoordinates;

typedef struct {
    unsigned int callcookie;
    Bool force; //in,  
} gfxscctrlForceNativeMode;

typedef struct {
    unsigned int callcookie;
    int layers; //in,  
    Bool force; //in,  
} gfxscctrlForcePrecompensationMode;

typedef struct {
    unsigned int callcookie;
} keyDisable;

typedef struct {
    unsigned int callcookie;
} keyEnable;

typedef struct {
    unsigned int callcookie;
    RemoteControlKey * key; //in, data ( sizeof( RemoteControlKey ) * size ), dynamic ( sizeof( RemoteControlKey ) * size ), 
    int size; //in,  
} keySetWakeupMode;

typedef struct {
    unsigned int callcookie;
} lgcDisable;

typedef struct {
    unsigned int callcookie;
} lgcEnable;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} lgcIsEnabled;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} powGetAutomaticRestarts;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} powGetMuteScreen;

typedef struct {
    unsigned int callcookie;
    int retval; //out,  
} powGetTvPower;

typedef struct {
    unsigned int callcookie;
    int src; //out,  
    int sys; //out,  
    int cmd; //out,  
} powGetWakeupInfo;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} powIsInProtection;

typedef struct {
    unsigned int callcookie;
    int mode; //in,  
    Bool retval; //out,  
} powIsTvPowerSupported;

typedef struct {
    unsigned int callcookie;
    int appl; //in,  
} powRestart;

typedef struct {
    unsigned int callcookie;
    Bool enable; //in,  
} powSetAutomaticRestarts;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} powSetMuteScreen;

typedef struct {
    unsigned int callcookie;
    int mode; //in,  
} powSetTvPower;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} powStartHotboot;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} powStopHotboot;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} powTransitionActive;

typedef struct {
    unsigned int callcookie;
    int resid; //in,  
    int nbrclients; //in,  
    int * winid; //in, data ( sizeof( int ) * nbrclients ), dynamic ( sizeof( int ) * nbrclients ), 
} resSetClientResourceAllocation;

typedef struct {
    unsigned int callcookie;
    int resid; //in,  
    int nbrclients; //in,  
    int * winid; //in, data ( sizeof( int ) * nbrclients ), dynamic ( sizeof( int ) * nbrclients ), 
} resSetResourceAllocation;

/* argument structures for notifications (requires) */
typedef struct {
    int streamid; //in,  
} dstNOnVideoCoordinatesSet;

typedef struct {
    int mode; //in,  
} dstNOnVideoOutputModeSet;

#endif /* _PLFAPISETUP_INTERNAL_H_ */

