
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


#if !defined(_PLFAPIAF_INTERNAL_H_)
#define _PLFAPIAF_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} afitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
} arcDisable;

typedef struct {
    unsigned int callcookie;
} arcEnable;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} arcIsEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooAmplifierMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooBalanceSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooBassSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooDeltaVolumeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} hsooEnableAmplifierMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} hsooEnableMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooEqualizerSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooGetAmplifierMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} hsooGetBalance;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} hsooGetBass;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} hsooGetDeltaVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int retval; //out,  
} hsooGetEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooGetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} hsooGetTreble;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} hsooGetVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int retval; //out,  
} hsooMaxEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int retval; //out,  
} hsooMedEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int retval; //out,  
} hsooMinEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mute; //in,  
} hsooSetAmplifierMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int balance; //in,  
} hsooSetBalance;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bass; //in,  
} hsooSetBass;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int delta; //in,  
} hsooSetDeltaVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int value; //in,  
} hsooSetEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mute; //in,  
} hsooSetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int treble; //in,  
} hsooSetTreble;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int volume; //in,  
} hsooSetVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooTrebleSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} hsooVolumeSupported;

typedef struct {
    unsigned int callcookie;
} keybpDisable;

typedef struct {
    unsigned int callcookie;
} keybpEnable;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} keybpIsEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sipGetImprovementMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} sipGetLoudness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int improvement; //in,  
    Bool retval; //out,  
} sipIsImprovementModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int improvement; //in,  
    Bool retval; //out,  
} sipIsImprovementModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} sipIsLoudnessAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} sipIsLoudnessSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int improvement; //in,  
} sipSetImprovementMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool loudness; //in,  
} sipSetLoudness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} slaGetAutoVolumeLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} slaGetDynamicRangeCompression;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} slaGetNightMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} slaIsAutoVolumeLevelAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} slaIsAutoVolumeLevelSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int drc; //in,  
    Bool retval; //out,  
} slaIsDynamicRangeCompressionAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int drc; //in,  
    Bool retval; //out,  
} slaIsDynamicRangeCompressionSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} slaIsNightModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} slaIsNightModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool avl; //in,  
} slaSetAutoVolumeLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int drc; //in,  
} slaSetDynamicRangeCompression;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool nmc; //in,  
} slaSetNightMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} smtGetActualMuteStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int outputs; //in,  
} smtMuteOutputs;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int outputs; //in,  
    int retval; //out,  
} snddelayGetDelay;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int outputs; //in,  
    int delay; //in,  
} snddelaySetDelay;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int autosurroundmode; //in,  
    int retval; //out,  
} somAutoSurroundModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} somGetAutoSurround;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundmode; //in,  
    int retval; //out,  
} somGetSurroundLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundlevel; //in,  
    int retval; //out,  
} somGetSurroundLevelEffectStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundlevel; //in,  
    int retval; //out,  
} somGetSurroundMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundmode; //in,  
    int retval; //out,  
} somGetSurroundModeEffectStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int autosurroundmode; //in,  
} somSetAutoSurround;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundlevel; //in,  
} somSetSurroundLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int strength; //in,  
    int surroundlevel; //in,  
} somSetSurroundLevelEffectStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundmode; //in,  
} somSetSurroundMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int strength; //in,  
    int surroundmode; //in,  
} somSetSurroundModeEffectStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundlevel; //in,  
    Bool retval; //out,  
} somSurroundLevelAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundlevel; //in,  
    Bool retval; //out,  
} somSurroundLevelEffectStrengthSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundlevel; //in,  
    Bool retval; //out,  
} somSurroundLevelSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundmode; //in,  
    Bool retval; //out,  
} somSurroundModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundmode; //in,  
    Bool retval; //out,  
} somSurroundModeEffectStrengthSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int surroundmode; //in,  
    Bool retval; //out,  
} somSurroundModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sprGetSoundProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int soundprofile; //in,  
    Bool retval; //out,  
} sprIsSoundProfileSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int soundprofile; //in,  
} sprSetSoundProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    PlfApiSmartActivity act; //in,  
    int retval; //out,  
} spr2GetDefaultProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} spr2GetSoundProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int soundprofile; //in,  
    int item; //in,  
    int retval; //out,  
} spr2GetSoundProfileItem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int soundprofile; //in,  
    Bool retval; //out,  
} spr2IsSoundProfileSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int soundprofile; //in,  
} spr2SetSoundProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int retval; //out,  
} ssocFrontChannels;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ssocGetChannel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} ssocIsDigital;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} ssocIsDolbyProLogic;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} ssocIsMono;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} ssocIsRelated;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} ssocIsSecondLanguage;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} ssocIsStereo;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int retval; //out,  
} ssocLfeChannels;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int retval; //out,  
} ssocRearChannels;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
} ssocSetChannel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooAmplifierMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooBalanceSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooBassSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooDeltaVolumeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} ssooEnableAmplifierMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} ssooEnableMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooEqualizerSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooGetAmplifierMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ssooGetBalance;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ssooGetBass;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ssooGetDeltaVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int retval; //out,  
} ssooGetEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooGetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ssooGetTreble;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ssooGetVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int retval; //out,  
} ssooMaxEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int retval; //out,  
} ssooMedEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int retval; //out,  
} ssooMinEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mute; //in,  
} ssooSetAmplifierMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int balance; //in,  
} ssooSetBalance;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bass; //in,  
} ssooSetBass;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int delta; //in,  
} ssooSetDeltaVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int band; //in,  
    int value; //in,  
} ssooSetEqualizerBandValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mute; //in,  
} ssooSetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int treble; //in,  
} ssooSetTreble;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int volume; //in,  
} ssooSetVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooTrebleSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ssooVolumeSupported;

/* argument structures for notifications (requires) */
typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} afitfNOnAvailabilityChanged;

typedef struct {
    int band; //in,  
} hsooNOnEqualizerBandValueChanged;

typedef struct {
    int channel; //in,  
} ssocNOnSoundPropertiesChanged;

typedef struct {
    int band; //in,  
} ssooNOnEqualizerBandValueChanged;

#endif /* _PLFAPIAF_INTERNAL_H_ */

