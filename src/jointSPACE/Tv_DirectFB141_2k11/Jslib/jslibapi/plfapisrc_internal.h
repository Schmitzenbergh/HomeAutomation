
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


#if !defined(_PLFAPISRC_INTERNAL_H_)
#define _PLFAPISRC_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} amut2Disable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} amut2Enable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} amut2IsEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Destination_t destination; //in,  
    Bool Exists; //out,  
} brkDestinationExists;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Destination_t destination; //in,  
    Bool pStatus; //out,  
} brkDestinationStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Source_t source; //in,  
    Bool Status; //out,  
} brkExtensionStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Destination_t destination; //in,  
    tmPlfInstPreset_DestinationType_t DestinationType; //out,  
} brkGetDestinationType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Source_t source; //in,  
    tmPlfInstPreset_SourceType_t SourceType; //out,  
} brkGetSourceType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Destination_t destination; //in,  
    tmPlfInstPreset_DestinationType_t destinationType; //in,  
} brkSetDestinationType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Source_t source; //in,  
    tmPlfInstPreset_SourceType_t sourceType; //in,  
} brkSetSourceType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Source_t source; //in,  
    Bool Exists; //out,  
} brkSourceExists;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Source_t source; //in,  
    tmPlfInstPreset_SourceType_t sourceType; //in,  
    Bool Supported; //out,  
} brkSourceTypeSupported;

typedef struct {
    unsigned int callcookie;
    int source; //in,  
    int assoc; //in,  
} confAssociateSoundInput;

typedef struct {
    unsigned int callcookie;
    int source; //in,  
    Bool ena; //in,  
} confEnablePcMode;

typedef struct {
    unsigned int callcookie;
    int source; //in,  
    int assoc; //out,  
} confGetAssociatedSoundInput;

typedef struct {
    unsigned int callcookie;
    int mode; //out,  
} confGetMonitorOutMode;

typedef struct {
    unsigned int callcookie;
    int medium; //out,  
} confGetTunerMedium;

typedef struct {
    unsigned int callcookie;
    int source; //in,  
    int assoc; //in,  
    Bool retval; //out,  
} confIsAssociateSoundInputAllowed;

typedef struct {
    unsigned int callcookie;
    int mode; //in,  
} confSetMonitorOutMode;

typedef struct {
    unsigned int callcookie;
    int medium; //in,  
} confSetTunerMedium;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} srcApplySourceSettings;

typedef struct {
    unsigned int callcookie;
    int audionodeid; //in,  
    int source; //out,  
    Nat32 designator; //out,  
} srcGetCurrentAudioSelection;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int source; //out,  
    Nat32 designator; //out,  
} srcGetCurrentVideoSelection;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int source; //in,  
    int sourceSignalType; //out,  
    int sourceType; //out,  
} srcGetSourceCapabilities;

typedef struct {
    unsigned int callcookie;
    int audionodeid; //in,  
    int source; //in,  
    Nat32 designator; //in,  
    Bool retval; //out,  
} srcIsAudioSelectionAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int source; //in,  
    Nat32 designator; //in,  
    Bool retval; //out,  
} srcIsVideoSelectionAllowed;

typedef struct {
    unsigned int callcookie;
    int audionodeid; //in,  
    int source; //in,  
    Nat32 designator; //in,  
    Bool retval; //out,  
} srcSelectAudioSource;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int source; //in,  
    Nat32 designator; //in,  
    Bool retval; //out,  
} srcSelectVideoSource;

typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} srcitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} vmut2Disable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} vmut2Enable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vmut2IsEnabled;

/* argument structures for notifications (requires) */
typedef struct {
    tmPlfInstPreset_Destination_t destination; //in,  
    Bool status; //in,  
} brkNOnDestinationStatusChanged;

typedef struct {
    tmPlfInstPreset_Source_t source; //in,  
    Bool status; //in,  
} brkNOnExtensionStatusChanged;

typedef struct {
    int audionodeid; //in,  
    int source; //in,  
} src2NOnAudioSourceSelected;

typedef struct {
    int winid; //in,  
} src2NOnSourceSettingsApplied;

typedef struct {
    int winid; //in,  
    int source; //in,  
} src2NOnVideoSourceSelected;

typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} srcitfNOnAvailabilityChanged;

typedef struct {
    int audionodeid; //in,  
    int source; //in,  
} srcNOnAudioSourceSelected;

typedef struct {
    int winid; //in,  
    int source; //in,  
} srcNOnVideoSourceSelected;

#endif /* _PLFAPISRC_INTERNAL_H_ */

