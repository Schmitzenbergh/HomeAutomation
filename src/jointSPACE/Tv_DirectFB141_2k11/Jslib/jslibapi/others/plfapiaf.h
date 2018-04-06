
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


#if !defined(_PLFAPIAF_H_)
#define _PLFAPIAF_H_

#if !defined(_PLFAPIAF_DD_)
#include "plfapiaf_types.h"
#endif

extern int  plfapiaf_Init( int arg, char * argv[] );
extern void plfapiaf_Exit( void );

/*  Symbols for plfapiafMethodID */
extern int idafitfGetAvailableInterfaces;  /* 0 */
extern int idarcDisable;  /* 1 */
extern int idarcEnable;  /* 2 */
extern int idarcIsEnabled;  /* 3 */
extern int idhsooAmplifierMuteSupported;  /* 4 */
extern int idhsooBalanceSupported;  /* 5 */
extern int idhsooBassSupported;  /* 6 */
extern int idhsooDeltaVolumeSupported;  /* 7 */
extern int idhsooEnableAmplifierMute;  /* 8 */
extern int idhsooEnableMute;  /* 9 */
extern int idhsooEqualizerSupported;  /* 10 */
extern int idhsooGetAmplifierMute;  /* 11 */
extern int idhsooGetBalance;  /* 12 */
extern int idhsooGetBass;  /* 13 */
extern int idhsooGetDeltaVolume;  /* 14 */
extern int idhsooGetEqualizerBandValue;  /* 15 */
extern int idhsooGetMute;  /* 16 */
extern int idhsooGetTreble;  /* 17 */
extern int idhsooGetVolume;  /* 18 */
extern int idhsooMaxEqualizerBandValue;  /* 19 */
extern int idhsooMedEqualizerBandValue;  /* 20 */
extern int idhsooMinEqualizerBandValue;  /* 21 */
extern int idhsooMuteSupported;  /* 22 */
extern int idhsooSetAmplifierMute;  /* 23 */
extern int idhsooSetBalance;  /* 24 */
extern int idhsooSetBass;  /* 25 */
extern int idhsooSetDeltaVolume;  /* 26 */
extern int idhsooSetEqualizerBandValue;  /* 27 */
extern int idhsooSetMute;  /* 28 */
extern int idhsooSetTreble;  /* 29 */
extern int idhsooSetVolume;  /* 30 */
extern int idhsooTrebleSupported;  /* 31 */
extern int idhsooVolumeSupported;  /* 32 */
extern int idkeybpDisable;  /* 33 */
extern int idkeybpEnable;  /* 34 */
extern int idkeybpIsEnabled;  /* 35 */
extern int idsipGetImprovementMode;  /* 36 */
extern int idsipGetLoudness;  /* 37 */
extern int idsipIsImprovementModeAllowed;  /* 38 */
extern int idsipIsImprovementModeSupported;  /* 39 */
extern int idsipIsLoudnessAllowed;  /* 40 */
extern int idsipIsLoudnessSupported;  /* 41 */
extern int idsipSetImprovementMode;  /* 42 */
extern int idsipSetLoudness;  /* 43 */
extern int idslaGetAutoVolumeLevel;  /* 44 */
extern int idslaGetDynamicRangeCompression;  /* 45 */
extern int idslaGetNightMode;  /* 46 */
extern int idslaIsAutoVolumeLevelAllowed;  /* 47 */
extern int idslaIsAutoVolumeLevelSupported;  /* 48 */
extern int idslaIsDynamicRangeCompressionAllowed;  /* 49 */
extern int idslaIsDynamicRangeCompressionSupported;  /* 50 */
extern int idslaIsNightModeAllowed;  /* 51 */
extern int idslaIsNightModeSupported;  /* 52 */
extern int idslaSetAutoVolumeLevel;  /* 53 */
extern int idslaSetDynamicRangeCompression;  /* 54 */
extern int idslaSetNightMode;  /* 55 */
extern int idsmtGetActualMuteStatus;  /* 56 */
extern int idsmtMuteOutputs;  /* 57 */
extern int idsnddelayGetDelay;  /* 58 */
extern int idsnddelaySetDelay;  /* 59 */
extern int idsomAutoSurroundModeSupported;  /* 60 */
extern int idsomGetAutoSurround;  /* 61 */
extern int idsomGetSurroundLevel;  /* 62 */
extern int idsomGetSurroundLevelEffectStrength;  /* 63 */
extern int idsomGetSurroundMode;  /* 64 */
extern int idsomGetSurroundModeEffectStrength;  /* 65 */
extern int idsomSetAutoSurround;  /* 66 */
extern int idsomSetSurroundLevel;  /* 67 */
extern int idsomSetSurroundLevelEffectStrength;  /* 68 */
extern int idsomSetSurroundMode;  /* 69 */
extern int idsomSetSurroundModeEffectStrength;  /* 70 */
extern int idsomSurroundLevelAllowed;  /* 71 */
extern int idsomSurroundLevelEffectStrengthSupported;  /* 72 */
extern int idsomSurroundLevelSupported;  /* 73 */
extern int idsomSurroundModeAllowed;  /* 74 */
extern int idsomSurroundModeEffectStrengthSupported;  /* 75 */
extern int idsomSurroundModeSupported;  /* 76 */
extern int idsprGetSoundProfile;  /* 77 */
extern int idsprIsSoundProfileSupported;  /* 78 */
extern int idsprSetSoundProfile;  /* 79 */
extern int idspr2GetDefaultProfile;  /* 80 */
extern int idspr2GetSoundProfile;  /* 81 */
extern int idspr2GetSoundProfileItem;  /* 82 */
extern int idspr2IsSoundProfileSupported;  /* 83 */
extern int idspr2SetSoundProfile;  /* 84 */
extern int idssocFrontChannels;  /* 85 */
extern int idssocGetChannel;  /* 86 */
extern int idssocIsDigital;  /* 87 */
extern int idssocIsDolbyProLogic;  /* 88 */
extern int idssocIsMono;  /* 89 */
extern int idssocIsRelated;  /* 90 */
extern int idssocIsSecondLanguage;  /* 91 */
extern int idssocIsStereo;  /* 92 */
extern int idssocLfeChannels;  /* 93 */
extern int idssocRearChannels;  /* 94 */
extern int idssocSetChannel;  /* 95 */
extern int idssooAmplifierMuteSupported;  /* 96 */
extern int idssooBalanceSupported;  /* 97 */
extern int idssooBassSupported;  /* 98 */
extern int idssooDeltaVolumeSupported;  /* 99 */
extern int idssooEnableAmplifierMute;  /* 100 */
extern int idssooEnableMute;  /* 101 */
extern int idssooEqualizerSupported;  /* 102 */
extern int idssooGetAmplifierMute;  /* 103 */
extern int idssooGetBalance;  /* 104 */
extern int idssooGetBass;  /* 105 */
extern int idssooGetDeltaVolume;  /* 106 */
extern int idssooGetEqualizerBandValue;  /* 107 */
extern int idssooGetMute;  /* 108 */
extern int idssooGetTreble;  /* 109 */
extern int idssooGetVolume;  /* 110 */
extern int idssooMaxEqualizerBandValue;  /* 111 */
extern int idssooMedEqualizerBandValue;  /* 112 */
extern int idssooMinEqualizerBandValue;  /* 113 */
extern int idssooMuteSupported;  /* 114 */
extern int idssooSetAmplifierMute;  /* 115 */
extern int idssooSetBalance;  /* 116 */
extern int idssooSetBass;  /* 117 */
extern int idssooSetDeltaVolume;  /* 118 */
extern int idssooSetEqualizerBandValue;  /* 119 */
extern int idssooSetMute;  /* 120 */
extern int idssooSetTreble;  /* 121 */
extern int idssooSetVolume;  /* 122 */
extern int idssooTrebleSupported;  /* 123 */
extern int idssooVolumeSupported;  /* 124 */
extern int plfapiafMethodID_Last;  /* 125 */

/*  Symbols for plfapiafNotificationID */
extern int idafitfNOnAvailabilityChanged;  /* 0 */
extern int idhsooNOnBassChanged;  /* 1 */
extern int idhsooNOnEqualizerBandValueChanged;  /* 2 */
extern int idhsooNOnMuted;  /* 3 */
extern int idhsooNOnTrebleChanged;  /* 4 */
extern int idhsooNOnVolumeChanged;  /* 5 */
extern int idsipNOnImprovementModeAllowedChanged;  /* 6 */
extern int idsipNOnImprovementModeChanged;  /* 7 */
extern int idsipNOnLoudnessModeAllowedChanged;  /* 8 */
extern int idsipNOnLoudnessModeChanged;  /* 9 */
extern int idslaNOnAutoVolumeLevelAllowedChanged;  /* 10 */
extern int idslaNOnAutoVolumeLevelChanged;  /* 11 */
extern int idslaNOnDynamicRangeCompressionAllowedChanged;  /* 12 */
extern int idslaNOnDynamicRangeCompressionChanged;  /* 13 */
extern int idslaNOnNightModeAllowedChanged;  /* 14 */
extern int idslaNOnNightModeChanged;  /* 15 */
extern int idsomNAutoSurroundModeActiveNotify;  /* 16 */
extern int idsomNOnSurroundLevelAllowedChanged;  /* 17 */
extern int idsomNOnSurroundLevelChanged;  /* 18 */
extern int idsomNOnSurroundModeAllowedChanged;  /* 19 */
extern int idsomNOnSurroundModeChanged;  /* 20 */
extern int idssocNOnChannelChanged;  /* 21 */
extern int idssocNOnSoundPropertiesChanged;  /* 22 */
extern int idssooNOnBassChanged;  /* 23 */
extern int idssooNOnEqualizerBandValueChanged;  /* 24 */
extern int idssooNOnMuted;  /* 25 */
extern int idssooNOnTrebleChanged;  /* 26 */
extern int idssooNOnVolumeChanged;  /* 27 */
extern int plfapiafNotificationID_Last;  /* 28 */

/*  Functions clients can call, implemented by the supplier. */
extern FResult plfapiaf_afitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids );
#define plfapiaf_afitfid_arc  ((Nat32)1)
#define plfapiaf_afitfid_arc_CONSTANT  1
#define plfapiaf_afitfid_hsoo  ((Nat32)1)
#define plfapiaf_afitfid_hsoo_CONSTANT  1
#define plfapiaf_afitfid_keybp  ((Nat32)1)
#define plfapiaf_afitfid_keybp_CONSTANT  1
#define plfapiaf_afitfid_sip  ((Nat32)1)
#define plfapiaf_afitfid_sip_CONSTANT  1
#define plfapiaf_afitfid_sla  ((Nat32)1)
#define plfapiaf_afitfid_sla_CONSTANT  1
#define plfapiaf_afitfid_smt  ((Nat32)1)
#define plfapiaf_afitfid_smt_CONSTANT  1
#define plfapiaf_afitfid_snddelay  ((Nat32)1)
#define plfapiaf_afitfid_snddelay_CONSTANT  1
#define plfapiaf_afitfid_som  ((Nat32)1)
#define plfapiaf_afitfid_som_CONSTANT  1
#define plfapiaf_afitfid_spr  ((Nat32)1)
#define plfapiaf_afitfid_spr_CONSTANT  1
#define plfapiaf_afitfid_spr2  ((Nat32)1)
#define plfapiaf_afitfid_spr2_CONSTANT  1
#define plfapiaf_afitfid_ssoc  ((Nat32)1)
#define plfapiaf_afitfid_ssoc_CONSTANT  1
#define plfapiaf_afitfid_ssoo  ((Nat32)1)
#define plfapiaf_afitfid_ssoo_CONSTANT  1
extern FResult plfapiaf_arc_Disable( void );
extern FResult plfapiaf_arc_Enable( void );
extern FResult plfapiaf_arc_IsEnabled( Bool * retval );
#define plfapiaf_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapiaf_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapiaf_errid_Ok  ((FResult)0)
#define plfapiaf_errid_Ok_CONSTANT  0
#define plfapiaf_errid_Other  ((FResult)-1)
#define plfapiaf_errid_Other_CONSTANT  -1
#define plfapiaf_errid_ResourceNotOwned  ((FResult)1)
#define plfapiaf_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapiaf_hsoo_AmplifierMuteSupported( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_BalanceSupported( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_BassSupported( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_DeltaVolumeSupported( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_EnableAmplifierMute( int winid, Bool enable );
extern FResult plfapiaf_hsoo_EnableMute( int winid, Bool enable );
extern FResult plfapiaf_hsoo_EqualizerSupported( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_GetAmplifierMute( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_GetBalance( int winid, int * retval );
extern FResult plfapiaf_hsoo_GetBass( int winid, int * retval );
extern FResult plfapiaf_hsoo_GetDeltaVolume( int winid, int * retval );
extern FResult plfapiaf_hsoo_GetEqualizerBandValue( int winid, int band, int * retval );
extern FResult plfapiaf_hsoo_GetMute( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_GetTreble( int winid, int * retval );
extern FResult plfapiaf_hsoo_GetVolume( int winid, int * retval );
extern FResult plfapiaf_hsoo_MaxEqualizerBandValue( int winid, int band, int * retval );
extern FResult plfapiaf_hsoo_MedEqualizerBandValue( int winid, int band, int * retval );
extern FResult plfapiaf_hsoo_MinEqualizerBandValue( int winid, int band, int * retval );
extern FResult plfapiaf_hsoo_MuteSupported( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_SetAmplifierMute( int winid, Bool mute );
extern FResult plfapiaf_hsoo_SetBalance( int winid, int balance );
extern FResult plfapiaf_hsoo_SetBass( int winid, int bass );
extern FResult plfapiaf_hsoo_SetDeltaVolume( int winid, int delta );
extern FResult plfapiaf_hsoo_SetEqualizerBandValue( int winid, int band, int value );
extern FResult plfapiaf_hsoo_SetMute( int winid, Bool mute );
extern FResult plfapiaf_hsoo_SetTreble( int winid, int treble );
extern FResult plfapiaf_hsoo_SetVolume( int winid, int volume );
extern FResult plfapiaf_hsoo_TrebleSupported( int winid, Bool * retval );
extern FResult plfapiaf_hsoo_VolumeSupported( int winid, Bool * retval );
#define plfapiaf_hsoo_MaxBalance  ((int)255)
#define plfapiaf_hsoo_MaxBalance_CONSTANT  255
#define plfapiaf_hsoo_MaxBass  ((int)255)
#define plfapiaf_hsoo_MaxBass_CONSTANT  255
#define plfapiaf_hsoo_MaxDeltaVolume  ((int)255)
#define plfapiaf_hsoo_MaxDeltaVolume_CONSTANT  255
#define plfapiaf_hsoo_MaxEqualizerBand  ((int)4)
#define plfapiaf_hsoo_MaxEqualizerBand_CONSTANT  4
#define plfapiaf_hsoo_MaxTreble  ((int)255)
#define plfapiaf_hsoo_MaxTreble_CONSTANT  255
#define plfapiaf_hsoo_MaxVolume  ((int)255)
#define plfapiaf_hsoo_MaxVolume_CONSTANT  255
#define plfapiaf_hsoo_MedBalance  ((int)0)
#define plfapiaf_hsoo_MedBalance_CONSTANT  0
#define plfapiaf_hsoo_MedBass  ((int)128)
#define plfapiaf_hsoo_MedBass_CONSTANT  128
#define plfapiaf_hsoo_MedDeltaVolume  ((int)0)
#define plfapiaf_hsoo_MedDeltaVolume_CONSTANT  0
#define plfapiaf_hsoo_MedTreble  ((int)128)
#define plfapiaf_hsoo_MedTreble_CONSTANT  128
#define plfapiaf_hsoo_MinBalance  ((int)-255)
#define plfapiaf_hsoo_MinBalance_CONSTANT  -255
#define plfapiaf_hsoo_MinBass  ((int)0)
#define plfapiaf_hsoo_MinBass_CONSTANT  0
#define plfapiaf_hsoo_MinDeltaVolume  ((int)-255)
#define plfapiaf_hsoo_MinDeltaVolume_CONSTANT  -255
#define plfapiaf_hsoo_MinEqualizerBand  ((int)0)
#define plfapiaf_hsoo_MinEqualizerBand_CONSTANT  0
#define plfapiaf_hsoo_MinTreble  ((int)0)
#define plfapiaf_hsoo_MinTreble_CONSTANT  0
#define plfapiaf_hsoo_MinVolume  ((int)0)
#define plfapiaf_hsoo_MinVolume_CONSTANT  0
extern FResult plfapiaf_keybp_Disable( void );
extern FResult plfapiaf_keybp_Enable( void );
extern FResult plfapiaf_keybp_IsEnabled( Bool * retval );
extern FResult plfapiaf_sip_GetImprovementMode( int winid, int * retval );
extern FResult plfapiaf_sip_GetLoudness( int winid, Bool * retval );
extern FResult plfapiaf_sip_IsImprovementModeAllowed( int winid, int improvement, Bool * retval );
extern FResult plfapiaf_sip_IsImprovementModeSupported( int winid, int improvement, Bool * retval );
extern FResult plfapiaf_sip_IsLoudnessAllowed( int winid, Bool * retval );
extern FResult plfapiaf_sip_IsLoudnessSupported( int winid, Bool * retval );
extern FResult plfapiaf_sip_SetImprovementMode( int winid, int improvement );
extern FResult plfapiaf_sip_SetLoudness( int winid, Bool loudness );
#define plfapiaf_sip_ImprovementBbe  ((int)4)
#define plfapiaf_sip_ImprovementBbe_CONSTANT  4
#define plfapiaf_sip_ImprovementDbe  ((int)1)
#define plfapiaf_sip_ImprovementDbe_CONSTANT  1
#define plfapiaf_sip_ImprovementMpb  ((int)8)
#define plfapiaf_sip_ImprovementMpb_CONSTANT  8
#define plfapiaf_sip_ImprovementNone  ((int)0)
#define plfapiaf_sip_ImprovementNone_CONSTANT  0
#define plfapiaf_sip_ImprovementUltraBass  ((int)2)
#define plfapiaf_sip_ImprovementUltraBass_CONSTANT  2
extern FResult plfapiaf_sla_GetAutoVolumeLevel( int winid, Bool * retval );
extern FResult plfapiaf_sla_GetDynamicRangeCompression( int winid, int * retval );
extern FResult plfapiaf_sla_GetNightMode( int winid, Bool * retval );
extern FResult plfapiaf_sla_IsAutoVolumeLevelAllowed( int winid, Bool * retval );
extern FResult plfapiaf_sla_IsAutoVolumeLevelSupported( int winid, Bool * retval );
extern FResult plfapiaf_sla_IsDynamicRangeCompressionAllowed( int winid, int drc, Bool * retval );
extern FResult plfapiaf_sla_IsDynamicRangeCompressionSupported( int winid, int drc, Bool * retval );
extern FResult plfapiaf_sla_IsNightModeAllowed( int winid, Bool * retval );
extern FResult plfapiaf_sla_IsNightModeSupported( int winid, Bool * retval );
extern FResult plfapiaf_sla_SetAutoVolumeLevel( int winid, Bool avl );
extern FResult plfapiaf_sla_SetDynamicRangeCompression( int winid, int drc );
extern FResult plfapiaf_sla_SetNightMode( int winid, Bool nmc );
#define plfapiaf_sla_DrcModeCompressed  ((int)3)
#define plfapiaf_sla_DrcModeCompressed_CONSTANT  3
#define plfapiaf_sla_DrcModeDynamic  ((int)1)
#define plfapiaf_sla_DrcModeDynamic_CONSTANT  1
#define plfapiaf_sla_DrcModeStandard  ((int)2)
#define plfapiaf_sla_DrcModeStandard_CONSTANT  2
#define plfapiaf_sla_DrcModeUnknown  ((int)0)
#define plfapiaf_sla_DrcModeUnknown_CONSTANT  0
extern FResult plfapiaf_smt_GetActualMuteStatus( int winid, int * retval );
extern FResult plfapiaf_smt_MuteOutputs( int winid, int outputs );
#define plfapiaf_smt_All  ((int)253)
#define plfapiaf_smt_All_CONSTANT  253
#define plfapiaf_smt_Headphone  ((int)1)
#define plfapiaf_smt_Headphone_CONSTANT  1
#define plfapiaf_smt_Line1  ((int)16)
#define plfapiaf_smt_Line1_CONSTANT  16
#define plfapiaf_smt_Line2  ((int)32)
#define plfapiaf_smt_Line2_CONSTANT  32
#define plfapiaf_smt_Monitor  ((int)4)
#define plfapiaf_smt_Monitor_CONSTANT  4
#define plfapiaf_smt_None  ((int)0)
#define plfapiaf_smt_None_CONSTANT  0
#define plfapiaf_smt_Spdif  ((int)8)
#define plfapiaf_smt_Spdif_CONSTANT  8
#define plfapiaf_smt_Speaker  ((int)192)
#define plfapiaf_smt_Speaker_CONSTANT  192
#define plfapiaf_smt_SpeakerLeft  ((int)64)
#define plfapiaf_smt_SpeakerLeft_CONSTANT  64
#define plfapiaf_smt_SpeakerRight  ((int)128)
#define plfapiaf_smt_SpeakerRight_CONSTANT  128
extern FResult plfapiaf_snddelay_GetDelay( int winid, int outputs, int * retval );
extern FResult plfapiaf_snddelay_SetDelay( int winid, int outputs, int delay );
#define plfapiaf_snddelay_All  ((int)63)
#define plfapiaf_snddelay_All_CONSTANT  63
#define plfapiaf_snddelay_Headphone  ((int)1)
#define plfapiaf_snddelay_Headphone_CONSTANT  1
#define plfapiaf_snddelay_Line1  ((int)16)
#define plfapiaf_snddelay_Line1_CONSTANT  16
#define plfapiaf_snddelay_Line2  ((int)32)
#define plfapiaf_snddelay_Line2_CONSTANT  32
#define plfapiaf_snddelay_MinimumDelay  ((int)-1)
#define plfapiaf_snddelay_MinimumDelay_CONSTANT  -1
#define plfapiaf_snddelay_Monitor  ((int)4)
#define plfapiaf_snddelay_Monitor_CONSTANT  4
#define plfapiaf_snddelay_None  ((int)0)
#define plfapiaf_snddelay_None_CONSTANT  0
#define plfapiaf_snddelay_Spdif  ((int)8)
#define plfapiaf_snddelay_Spdif_CONSTANT  8
#define plfapiaf_snddelay_Speaker  ((int)2)
#define plfapiaf_snddelay_Speaker_CONSTANT  2
#define plfapiaf_snddelay_Synced  ((int)0)
#define plfapiaf_snddelay_Synced_CONSTANT  0
extern FResult plfapiaf_som_AutoSurroundModeSupported( int winid, int autosurroundmode, int * retval );
extern FResult plfapiaf_som_GetAutoSurround( int winid, int * retval );
extern FResult plfapiaf_som_GetSurroundLevel( int winid, int surroundmode, int * retval );
extern FResult plfapiaf_som_GetSurroundLevelEffectStrength( int winid, int surroundlevel, int * retval );
extern FResult plfapiaf_som_GetSurroundMode( int winid, int surroundlevel, int * retval );
extern FResult plfapiaf_som_GetSurroundModeEffectStrength( int winid, int surroundmode, int * retval );
extern FResult plfapiaf_som_SetAutoSurround( int winid, int autosurroundmode );
extern FResult plfapiaf_som_SetSurroundLevel( int winid, int surroundlevel );
extern FResult plfapiaf_som_SetSurroundLevelEffectStrength( int winid, int strength, int surroundlevel );
extern FResult plfapiaf_som_SetSurroundMode( int winid, int surroundmode );
extern FResult plfapiaf_som_SetSurroundModeEffectStrength( int winid, int strength, int surroundmode );
extern FResult plfapiaf_som_SurroundLevelAllowed( int winid, int surroundlevel, Bool * retval );
extern FResult plfapiaf_som_SurroundLevelEffectStrengthSupported( int winid, int surroundlevel, Bool * retval );
extern FResult plfapiaf_som_SurroundLevelSupported( int winid, int surroundlevel, Bool * retval );
extern FResult plfapiaf_som_SurroundModeAllowed( int winid, int surroundmode, Bool * retval );
extern FResult plfapiaf_som_SurroundModeEffectStrengthSupported( int winid, int surroundmode, Bool * retval );
extern FResult plfapiaf_som_SurroundModeSupported( int winid, int surroundmode, Bool * retval );
#define plfapiaf_som_CurrentLevel  ((int)0)
#define plfapiaf_som_CurrentLevel_CONSTANT  0
#define plfapiaf_som_CurrentMode  ((int)0)
#define plfapiaf_som_CurrentMode_CONSTANT  0
#define plfapiaf_som_Digital3D  ((int)26)
#define plfapiaf_som_Digital3D_CONSTANT  26
#define plfapiaf_som_DolbyDigital  ((int)22)
#define plfapiaf_som_DolbyDigital_CONSTANT  22
#define plfapiaf_som_DolbyProLogic  ((int)10)
#define plfapiaf_som_DolbyProLogic_CONSTANT  10
#define plfapiaf_som_DolbyProLogicII  ((int)24)
#define plfapiaf_som_DolbyProLogicII_CONSTANT  24
#define plfapiaf_som_DolbyProLogicPhantom  ((int)27)
#define plfapiaf_som_DolbyProLogicPhantom_CONSTANT  27
#define plfapiaf_som_Front3Stereo  ((int)8)
#define plfapiaf_som_Front3Stereo_CONSTANT  8
#define plfapiaf_som_Hall  ((int)3)
#define plfapiaf_som_Hall_CONSTANT  3
#define plfapiaf_som_Incredible3DSurround  ((int)7)
#define plfapiaf_som_Incredible3DSurround_CONSTANT  7
#define plfapiaf_som_IncredibleMono  ((int)11)
#define plfapiaf_som_IncredibleMono_CONSTANT  11
#define plfapiaf_som_IncredibleStereo  ((int)12)
#define plfapiaf_som_IncredibleStereo_CONSTANT  12
#define plfapiaf_som_IncredibleSurround  ((int)4)
#define plfapiaf_som_IncredibleSurround_CONSTANT  4
#define plfapiaf_som_LevelEnhanced  ((int)2)
#define plfapiaf_som_LevelEnhanced_CONSTANT  2
#define plfapiaf_som_LevelFront3  ((int)3)
#define plfapiaf_som_LevelFront3_CONSTANT  3
#define plfapiaf_som_LevelHall  ((int)5)
#define plfapiaf_som_LevelHall_CONSTANT  5
#define plfapiaf_som_LevelMaximum  ((int)6)
#define plfapiaf_som_LevelMaximum_CONSTANT  6
#define plfapiaf_som_LevelOff  ((int)1)
#define plfapiaf_som_LevelOff_CONSTANT  1
#define plfapiaf_som_LevelVirtual  ((int)4)
#define plfapiaf_som_LevelVirtual_CONSTANT  4
#define plfapiaf_som_Matrix  ((int)21)
#define plfapiaf_som_Matrix_CONSTANT  21
#define plfapiaf_som_MaxEffectStrength  ((int)3)
#define plfapiaf_som_MaxEffectStrength_CONSTANT  3
#define plfapiaf_som_MedEffectStrength  ((int)2)
#define plfapiaf_som_MedEffectStrength_CONSTANT  2
#define plfapiaf_som_MinEffectStrength  ((int)1)
#define plfapiaf_som_MinEffectStrength_CONSTANT  1
#define plfapiaf_som_MPEGMultiChannel  ((int)23)
#define plfapiaf_som_MPEGMultiChannel_CONSTANT  23
#define plfapiaf_som_NoEffect  ((int)0)
#define plfapiaf_som_NoEffect_CONSTANT  0
#define plfapiaf_som_Off  ((int)1)
#define plfapiaf_som_Off_CONSTANT  1
#define plfapiaf_som_Spatial  ((int)2)
#define plfapiaf_som_Spatial_CONSTANT  2
#define plfapiaf_som_Srs3DSound  ((int)6)
#define plfapiaf_som_Srs3DSound_CONSTANT  6
#define plfapiaf_som_SrsTruSurround  ((int)17)
#define plfapiaf_som_SrsTruSurround_CONSTANT  17
#define plfapiaf_som_SrsTruSurroundWithDPLII  ((int)18)
#define plfapiaf_som_SrsTruSurroundWithDPLII_CONSTANT  18
#define plfapiaf_som_SrsTruSurroundXT  ((int)19)
#define plfapiaf_som_SrsTruSurroundXT_CONSTANT  19
#define plfapiaf_som_SrsTruSurroundXTWithDPLII  ((int)20)
#define plfapiaf_som_SrsTruSurroundXTWithDPLII_CONSTANT  20
#define plfapiaf_som_SrsWow  ((int)5)
#define plfapiaf_som_SrsWow_CONSTANT  5
#define plfapiaf_som_Stereo4  ((int)9)
#define plfapiaf_som_Stereo4_CONSTANT  9
#define plfapiaf_som_useMonoStereo  ((int)16)
#define plfapiaf_som_useMonoStereo_CONSTANT  16
#define plfapiaf_som_useNone  ((int)0)
#define plfapiaf_som_useNone_CONSTANT  0
#define plfapiaf_som_useP50Dpl  ((int)2)
#define plfapiaf_som_useP50Dpl_CONSTANT  2
#define plfapiaf_som_useSPDIFDpl  ((int)4)
#define plfapiaf_som_useSPDIFDpl_CONSTANT  4
#define plfapiaf_som_useSpeakerConfiguration  ((int)8)
#define plfapiaf_som_useSpeakerConfiguration_CONSTANT  8
#define plfapiaf_som_useWssDpl  ((int)1)
#define plfapiaf_som_useWssDpl_CONSTANT  1
#define plfapiaf_som_VirtualDolby422  ((int)13)
#define plfapiaf_som_VirtualDolby422_CONSTANT  13
#define plfapiaf_som_VirtualDolby423  ((int)14)
#define plfapiaf_som_VirtualDolby423_CONSTANT  14
#define plfapiaf_som_VirtualDolby521  ((int)15)
#define plfapiaf_som_VirtualDolby521_CONSTANT  15
#define plfapiaf_som_VirtualDolby522  ((int)16)
#define plfapiaf_som_VirtualDolby522_CONSTANT  16
#define plfapiaf_som_VirtualDolbyDigital  ((int)25)
#define plfapiaf_som_VirtualDolbyDigital_CONSTANT  25
extern FResult plfapiaf_spr_GetSoundProfile( int winid, int * retval );
extern FResult plfapiaf_spr_IsSoundProfileSupported( int winid, int soundprofile, Bool * retval );
extern FResult plfapiaf_spr_SetSoundProfile( int winid, int soundprofile );
#define plfapiaf_spr_SoundProfileEco  ((int)4)
#define plfapiaf_spr_SoundProfileEco_CONSTANT  4
#define plfapiaf_spr_SoundProfileGame  ((int)6)
#define plfapiaf_spr_SoundProfileGame_CONSTANT  6
#define plfapiaf_spr_SoundProfileNeutral  ((int)2)
#define plfapiaf_spr_SoundProfileNeutral_CONSTANT  2
#define plfapiaf_spr_SoundProfileShop  ((int)5)
#define plfapiaf_spr_SoundProfileShop_CONSTANT  5
#define plfapiaf_spr_SoundProfileStandard  ((int)3)
#define plfapiaf_spr_SoundProfileStandard_CONSTANT  3
#define plfapiaf_spr_SoundProfileVivid  ((int)1)
#define plfapiaf_spr_SoundProfileVivid_CONSTANT  1
extern FResult plfapiaf_spr2_GetDefaultProfile( int winid, PlfApiSmartActivity act, int * retval );
extern FResult plfapiaf_spr2_GetSoundProfile( int winid, int * retval );
extern FResult plfapiaf_spr2_GetSoundProfileItem( int winid, int soundprofile, int item, int * retval );
extern FResult plfapiaf_spr2_IsSoundProfileSupported( int winid, int soundprofile, Bool * retval );
extern FResult plfapiaf_spr2_SetSoundProfile( int winid, int soundprofile );
#define plfapiaf_spr2_ItemBass  ((int)2)
#define plfapiaf_spr2_ItemBass_CONSTANT  2
#define plfapiaf_spr2_ItemSurround  ((int)3)
#define plfapiaf_spr2_ItemSurround_CONSTANT  3
#define plfapiaf_spr2_ItemTreble  ((int)1)
#define plfapiaf_spr2_ItemTreble_CONSTANT  1
#define plfapiaf_spr2_SoundProfileDrama  ((int)6)
#define plfapiaf_spr2_SoundProfileDrama_CONSTANT  6
#define plfapiaf_spr2_SoundProfileGame  ((int)5)
#define plfapiaf_spr2_SoundProfileGame_CONSTANT  5
#define plfapiaf_spr2_SoundProfileMovie  ((int)4)
#define plfapiaf_spr2_SoundProfileMovie_CONSTANT  4
#define plfapiaf_spr2_SoundProfileNews  ((int)3)
#define plfapiaf_spr2_SoundProfileNews_CONSTANT  3
#define plfapiaf_spr2_SoundProfilePersonal  ((int)1)
#define plfapiaf_spr2_SoundProfilePersonal_CONSTANT  1
#define plfapiaf_spr2_SoundProfileSettingAssistant1  ((int)8)
#define plfapiaf_spr2_SoundProfileSettingAssistant1_CONSTANT  8
#define plfapiaf_spr2_SoundProfileSettingAssistant2  ((int)9)
#define plfapiaf_spr2_SoundProfileSettingAssistant2_CONSTANT  9
#define plfapiaf_spr2_SoundProfileSettingAssistant3  ((int)10)
#define plfapiaf_spr2_SoundProfileSettingAssistant3_CONSTANT  10
#define plfapiaf_spr2_SoundProfileSports  ((int)7)
#define plfapiaf_spr2_SoundProfileSports_CONSTANT  7
#define plfapiaf_spr2_SoundProfileStandard  ((int)2)
#define plfapiaf_spr2_SoundProfileStandard_CONSTANT  2
extern FResult plfapiaf_ssoc_FrontChannels( int winid, int channel, int * retval );
extern FResult plfapiaf_ssoc_GetChannel( int winid, int * retval );
extern FResult plfapiaf_ssoc_IsDigital( int winid, int channel, Bool * retval );
extern FResult plfapiaf_ssoc_IsDolbyProLogic( int winid, int channel, Bool * retval );
extern FResult plfapiaf_ssoc_IsMono( int winid, int channel, Bool * retval );
extern FResult plfapiaf_ssoc_IsRelated( int winid, int channel, Bool * retval );
extern FResult plfapiaf_ssoc_IsSecondLanguage( int winid, int channel, Bool * retval );
extern FResult plfapiaf_ssoc_IsStereo( int winid, int channel, Bool * retval );
extern FResult plfapiaf_ssoc_LfeChannels( int winid, int channel, int * retval );
extern FResult plfapiaf_ssoc_RearChannels( int winid, int channel, int * retval );
extern FResult plfapiaf_ssoc_SetChannel( int winid, int channel );
#define plfapiaf_ssoc_Channel1  ((int)1)
#define plfapiaf_ssoc_Channel1_CONSTANT  1
#define plfapiaf_ssoc_Channel2  ((int)2)
#define plfapiaf_ssoc_Channel2_CONSTANT  2
#define plfapiaf_ssoc_Channel3  ((int)3)
#define plfapiaf_ssoc_Channel3_CONSTANT  3
extern FResult plfapiaf_ssoo_AmplifierMuteSupported( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_BalanceSupported( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_BassSupported( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_DeltaVolumeSupported( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_EnableAmplifierMute( int winid, Bool enable );
extern FResult plfapiaf_ssoo_EnableMute( int winid, Bool enable );
extern FResult plfapiaf_ssoo_EqualizerSupported( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_GetAmplifierMute( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_GetBalance( int winid, int * retval );
extern FResult plfapiaf_ssoo_GetBass( int winid, int * retval );
extern FResult plfapiaf_ssoo_GetDeltaVolume( int winid, int * retval );
extern FResult plfapiaf_ssoo_GetEqualizerBandValue( int winid, int band, int * retval );
extern FResult plfapiaf_ssoo_GetMute( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_GetTreble( int winid, int * retval );
extern FResult plfapiaf_ssoo_GetVolume( int winid, int * retval );
extern FResult plfapiaf_ssoo_MaxEqualizerBandValue( int winid, int band, int * retval );
extern FResult plfapiaf_ssoo_MedEqualizerBandValue( int winid, int band, int * retval );
extern FResult plfapiaf_ssoo_MinEqualizerBandValue( int winid, int band, int * retval );
extern FResult plfapiaf_ssoo_MuteSupported( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_SetAmplifierMute( int winid, Bool mute );
extern FResult plfapiaf_ssoo_SetBalance( int winid, int balance );
extern FResult plfapiaf_ssoo_SetBass( int winid, int bass );
extern FResult plfapiaf_ssoo_SetDeltaVolume( int winid, int delta );
extern FResult plfapiaf_ssoo_SetEqualizerBandValue( int winid, int band, int value );
extern FResult plfapiaf_ssoo_SetMute( int winid, Bool mute );
extern FResult plfapiaf_ssoo_SetTreble( int winid, int treble );
extern FResult plfapiaf_ssoo_SetVolume( int winid, int volume );
extern FResult plfapiaf_ssoo_TrebleSupported( int winid, Bool * retval );
extern FResult plfapiaf_ssoo_VolumeSupported( int winid, Bool * retval );
#define plfapiaf_ssoo_MaxBalance  ((int)255)
#define plfapiaf_ssoo_MaxBalance_CONSTANT  255
#define plfapiaf_ssoo_MaxBass  ((int)255)
#define plfapiaf_ssoo_MaxBass_CONSTANT  255
#define plfapiaf_ssoo_MaxDeltaVolume  ((int)255)
#define plfapiaf_ssoo_MaxDeltaVolume_CONSTANT  255
#define plfapiaf_ssoo_MaxEqualizerBand  ((int)4)
#define plfapiaf_ssoo_MaxEqualizerBand_CONSTANT  4
#define plfapiaf_ssoo_MaxTreble  ((int)255)
#define plfapiaf_ssoo_MaxTreble_CONSTANT  255
#define plfapiaf_ssoo_MaxVolume  ((int)255)
#define plfapiaf_ssoo_MaxVolume_CONSTANT  255
#define plfapiaf_ssoo_MedBalance  ((int)0)
#define plfapiaf_ssoo_MedBalance_CONSTANT  0
#define plfapiaf_ssoo_MedBass  ((int)128)
#define plfapiaf_ssoo_MedBass_CONSTANT  128
#define plfapiaf_ssoo_MedDeltaVolume  ((int)0)
#define plfapiaf_ssoo_MedDeltaVolume_CONSTANT  0
#define plfapiaf_ssoo_MedTreble  ((int)128)
#define plfapiaf_ssoo_MedTreble_CONSTANT  128
#define plfapiaf_ssoo_MinBalance  ((int)-255)
#define plfapiaf_ssoo_MinBalance_CONSTANT  -255
#define plfapiaf_ssoo_MinBass  ((int)0)
#define plfapiaf_ssoo_MinBass_CONSTANT  0
#define plfapiaf_ssoo_MinDeltaVolume  ((int)-255)
#define plfapiaf_ssoo_MinDeltaVolume_CONSTANT  -255
#define plfapiaf_ssoo_MinEqualizerBand  ((int)0)
#define plfapiaf_ssoo_MinEqualizerBand_CONSTANT  0
#define plfapiaf_ssoo_MinTreble  ((int)0)
#define plfapiaf_ssoo_MinTreble_CONSTANT  0
#define plfapiaf_ssoo_MinVolume  ((int)0)
#define plfapiaf_ssoo_MinVolume_CONSTANT  0

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapiaf_afitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids );
extern void plfapiaf_hsooN_OnBassChanged( void );
extern void plfapiaf_hsooN_OnEqualizerBandValueChanged( int band );
extern void plfapiaf_hsooN_OnMuted( void );
extern void plfapiaf_hsooN_OnTrebleChanged( void );
extern void plfapiaf_hsooN_OnVolumeChanged( void );
extern void plfapiaf_sipN_OnImprovementModeAllowedChanged( void );
extern void plfapiaf_sipN_OnImprovementModeChanged( void );
extern void plfapiaf_sipN_OnLoudnessModeAllowedChanged( void );
extern void plfapiaf_sipN_OnLoudnessModeChanged( void );
extern void plfapiaf_slaN_OnAutoVolumeLevelAllowedChanged( void );
extern void plfapiaf_slaN_OnAutoVolumeLevelChanged( void );
extern void plfapiaf_slaN_OnDynamicRangeCompressionAllowedChanged( void );
extern void plfapiaf_slaN_OnDynamicRangeCompressionChanged( void );
extern void plfapiaf_slaN_OnNightModeAllowedChanged( void );
extern void plfapiaf_slaN_OnNightModeChanged( void );
extern void plfapiaf_somN_AutoSurroundModeActiveNotify( void );
extern void plfapiaf_somN_OnSurroundLevelAllowedChanged( void );
extern void plfapiaf_somN_OnSurroundLevelChanged( void );
extern void plfapiaf_somN_OnSurroundModeAllowedChanged( void );
extern void plfapiaf_somN_OnSurroundModeChanged( void );
extern void plfapiaf_ssocN_OnChannelChanged( void );
extern void plfapiaf_ssocN_OnSoundPropertiesChanged( int channel );
extern void plfapiaf_ssooN_OnBassChanged( void );
extern void plfapiaf_ssooN_OnEqualizerBandValueChanged( int band );
extern void plfapiaf_ssooN_OnMuted( void );
extern void plfapiaf_ssooN_OnTrebleChanged( void );
extern void plfapiaf_ssooN_OnVolumeChanged( void );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapiaf_EnableNotification_afitfN( void );
extern void plfapiaf_DisableNotification_afitfN( void );
extern void plfapiaf_EnableNotification_hsooN( void );
extern void plfapiaf_DisableNotification_hsooN( void );
extern void plfapiaf_EnableNotification_sipN( void );
extern void plfapiaf_DisableNotification_sipN( void );
extern void plfapiaf_EnableNotification_slaN( void );
extern void plfapiaf_DisableNotification_slaN( void );
extern void plfapiaf_EnableNotification_somN( void );
extern void plfapiaf_DisableNotification_somN( void );
extern void plfapiaf_EnableNotification_ssocN( void );
extern void plfapiaf_DisableNotification_ssocN( void );
extern void plfapiaf_EnableNotification_ssooN( void );
extern void plfapiaf_DisableNotification_ssooN( void );
extern void plfapiaf_EnableNotification( int notificationId );
extern void plfapiaf_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapiaf_call_stubs */
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

extern void plfapiaf_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapiaf_RegisterHook_afitf( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_afitfid( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_arc( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_errid( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_hsoo( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_keybp( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_sip( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_sla( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_smt( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_snddelay( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_som( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_spr( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_spr2( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_ssoc( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_ssoo( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapiaf_RegisterHook_afitfN( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_hsooN( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_sipN( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_slaN( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_somN( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_ssocN( IpcHookFunction callback );
extern void plfapiaf_RegisterHook_ssooN( IpcHookFunction callback );

#endif /* _PLFAPIAF_H_ */

