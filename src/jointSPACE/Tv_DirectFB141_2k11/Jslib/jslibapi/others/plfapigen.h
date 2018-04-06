
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


#if !defined(_PLFAPIGEN_H_)
#define _PLFAPIGEN_H_

#if !defined(_PLFAPIGEN_DD_)
#include "plfapigen_types.h"
#endif

extern int  plfapigen_Init( int arg, char * argv[] );
extern void plfapigen_Exit( void );

/*  Symbols for plfapigenMethodID */
extern int idalnDefault;  /* 0 */
extern int idalnGet;  /* 1 */
extern int idalnGetIx;  /* 2 */
extern int idalnGetMaxIx;  /* 3 */
extern int idalnIsIxSupported;  /* 4 */
extern int idalnIsSupported;  /* 5 */
extern int idalnMax;  /* 6 */
extern int idalnMin;  /* 7 */
extern int idalnRecall;  /* 8 */
extern int idalnRecallAlignment;  /* 9 */
extern int idalnSet;  /* 10 */
extern int idalnSetIx;  /* 11 */
extern int idalnStore;  /* 12 */
extern int idalnStoreAlignment;  /* 13 */
extern int idambDisablePowerLimitation;  /* 14 */
extern int idambEnableFallback;  /* 15 */
extern int idambGetActiveLightMode;  /* 16 */
extern int idambGetBalance;  /* 17 */
extern int idambGetColorBoost;  /* 18 */
extern int idambGetHue;  /* 19 */
extern int idambGetImmersion;  /* 20 */
extern int idambGetLavaLightMode;  /* 21 */
extern int idambGetLightModeHue;  /* 22 */
extern int idambGetLightModeSaturation;  /* 23 */
extern int idambGetLightModeType;  /* 24 */
extern int idambGetLightState;  /* 25 */
extern int idambGetMute;  /* 26 */
extern int idambGetPredefinedMode;  /* 27 */
extern int idambGetSaturation;  /* 28 */
extern int idambGetSeparation;  /* 29 */
extern int idambGetStaticLightMode;  /* 30 */
extern int idambGetSunset;  /* 31 */
extern int idambGetValue;  /* 32 */
extern int idambIsActiveLightModeAllowed;  /* 33 */
extern int idambIsActiveLightModeSupported;  /* 34 */
extern int idambIsBalanceAllowed;  /* 35 */
extern int idambIsBalanceSupported;  /* 36 */
extern int idambIsColorBoostAllowed;  /* 37 */
extern int idambIsColorBoostSupported;  /* 38 */
extern int idambIsCyclingOnValueAllowed;  /* 39 */
extern int idambIsCyclingOnValueOngoing;  /* 40 */
extern int idambIsCyclingOnValueSupported;  /* 41 */
extern int idambIsFallbackEnabled;  /* 42 */
extern int idambIsHueAllowed;  /* 43 */
extern int idambIsHueSupported;  /* 44 */
extern int idambIsImmersionAllowed;  /* 45 */
extern int idambIsImmersionSupported;  /* 46 */
extern int idambIsLavaLightModeAllowed;  /* 47 */
extern int idambIsLavaLightModeSupported;  /* 48 */
extern int idambIsLightModeHueSupported;  /* 49 */
extern int idambIsLightModeSaturationSupported;  /* 50 */
extern int idambIsLightModeTypeAllowed;  /* 51 */
extern int idambIsLightModeTypeSupported;  /* 52 */
extern int idambIsLightStateAllowed;  /* 53 */
extern int idambIsLightStateSupported;  /* 54 */
extern int idambIsMuteAllowed;  /* 55 */
extern int idambIsMuteSupported;  /* 56 */
extern int idambIsPowerLimitationDisabled;  /* 57 */
extern int idambIsPredefinedModeAllowed;  /* 58 */
extern int idambIsPredefinedModeSupported;  /* 59 */
extern int idambIsSaturationAllowed;  /* 60 */
extern int idambIsSaturationSupported;  /* 61 */
extern int idambIsSeparationAllowed;  /* 62 */
extern int idambIsSeparationSupported;  /* 63 */
extern int idambIsStaticLightModeAllowed;  /* 64 */
extern int idambIsStaticLightModeSupported;  /* 65 */
extern int idambIsSunsetSupported;  /* 66 */
extern int idambIsValueAllowed;  /* 67 */
extern int idambIsValueSupported;  /* 68 */
extern int idambSetActiveLightMode;  /* 69 */
extern int idambSetBalance;  /* 70 */
extern int idambSetColorBoost;  /* 71 */
extern int idambSetHue;  /* 72 */
extern int idambSetImmersion;  /* 73 */
extern int idambSetLavaLightMode;  /* 74 */
extern int idambSetLightModeType;  /* 75 */
extern int idambSetLightState;  /* 76 */
extern int idambSetMute;  /* 77 */
extern int idambSetPredefinedMode;  /* 78 */
extern int idambSetSaturation;  /* 79 */
extern int idambSetSeparation;  /* 80 */
extern int idambSetStaticLightMode;  /* 81 */
extern int idambSetSunset;  /* 82 */
extern int idambSetValue;  /* 83 */
extern int idambStartCyclingOnValue;  /* 84 */
extern int idambStopCyclingOnValue;  /* 85 */
extern int idamblApplySettings;  /* 86 */
extern int idamblCheckSettingsApplied;  /* 87 */
extern int idamblEnableFactoryMode;  /* 88 */
extern int idamblGetColorBoost;  /* 89 */
extern int idamblGetContrast;  /* 90 */
extern int idamblGetImmersion;  /* 91 */
extern int idamblGetLampTestZone;  /* 92 */
extern int idamblGetLavaRGB;  /* 93 */
extern int idamblGetMatrixBoard;  /* 94 */
extern int idamblGetMode;  /* 95 */
extern int idamblGetRGB;  /* 96 */
extern int idamblGetSeparation;  /* 97 */
extern int idamblGetState;  /* 98 */
extern int idamblGetStaticRGB;  /* 99 */
extern int idamblGetWallColors;  /* 100 */
extern int idamblIsColorBoostSupported;  /* 101 */
extern int idamblIsContrastSupported;  /* 102 */
extern int idamblIsImmersionSupported;  /* 103 */
extern int idamblIsLampTestZoneSupported;  /* 104 */
extern int idamblIsLavaRGBSupported;  /* 105 */
extern int idamblIsModeSupported;  /* 106 */
extern int idamblIsSeparationSupported;  /* 107 */
extern int idamblIsStateSupported;  /* 108 */
extern int idamblIsStaticRGBSupported;  /* 109 */
extern int idamblSelectWallColor;  /* 110 */
extern int idamblSetColorBoost;  /* 111 */
extern int idamblSetContrast;  /* 112 */
extern int idamblSetCurrent;  /* 113 */
extern int idamblSetImmersion;  /* 114 */
extern int idamblSetLampTestZone;  /* 115 */
extern int idamblSetLavaRGB;  /* 116 */
extern int idamblSetMatrix;  /* 117 */
extern int idamblSetMatrixBoard;  /* 118 */
extern int idamblSetMode;  /* 119 */
extern int idamblSetPixel;  /* 120 */
extern int idamblSetRGB;  /* 121 */
extern int idamblSetSeparation;  /* 122 */
extern int idamblSetState;  /* 123 */
extern int idamblSetStaticRGB;  /* 124 */
extern int idamblxApplySettings;  /* 125 */
extern int idamblxCheckSettingsApplied;  /* 126 */
extern int idamblxEnableFactoryMode;  /* 127 */
extern int idamblxGetBrightnessBoard;  /* 128 */
extern int idamblxGetColorBoost;  /* 129 */
extern int idamblxGetContrast;  /* 130 */
extern int idamblxGetCorrectionBoard;  /* 131 */
extern int idamblxGetImmersion;  /* 132 */
extern int idamblxGetLampTestZone;  /* 133 */
extern int idamblxGetLavaRGB;  /* 134 */
extern int idamblxGetMatrixBoard;  /* 135 */
extern int idamblxGetMode;  /* 136 */
extern int idamblxGetRGB;  /* 137 */
extern int idamblxGetSeparation;  /* 138 */
extern int idamblxGetState;  /* 139 */
extern int idamblxGetStaticRGB;  /* 140 */
extern int idamblxGetWallColors;  /* 141 */
extern int idamblxIsColorBoostSupported;  /* 142 */
extern int idamblxIsContrastSupported;  /* 143 */
extern int idamblxIsImmersionSupported;  /* 144 */
extern int idamblxIsLampTestZoneSupported;  /* 145 */
extern int idamblxIsLavaRGBSupported;  /* 146 */
extern int idamblxIsModeSupported;  /* 147 */
extern int idamblxIsSeparationSupported;  /* 148 */
extern int idamblxIsStateSupported;  /* 149 */
extern int idamblxIsStaticRGBSupported;  /* 150 */
extern int idamblxSelectWallColor;  /* 151 */
extern int idamblxSetBrightnessBoard;  /* 152 */
extern int idamblxSetColorBoost;  /* 153 */
extern int idamblxSetContrast;  /* 154 */
extern int idamblxSetCorrectionBoard;  /* 155 */
extern int idamblxSetCurrent;  /* 156 */
extern int idamblxSetImmersion;  /* 157 */
extern int idamblxSetLampTestZone;  /* 158 */
extern int idamblxSetLavaRGB;  /* 159 */
extern int idamblxSetMatrix;  /* 160 */
extern int idamblxSetMatrixBoard;  /* 161 */
extern int idamblxSetMode;  /* 162 */
extern int idamblxSetPixel;  /* 163 */
extern int idamblxSetRGB;  /* 164 */
extern int idamblxSetSeparation;  /* 165 */
extern int idamblxSetState;  /* 166 */
extern int idamblxSetStaticRGB;  /* 167 */
extern int idbcontDisableFactoryMode;  /* 168 */
extern int idbcontEnableFactoryMode;  /* 169 */
extern int idbcontxDisableFactoryMode;  /* 170 */
extern int idbcontxEnableFactoryMode;  /* 171 */
extern int idbcontxGetTCONAlignment;  /* 172 */
extern int idbcontxResetTCONAlignment;  /* 173 */
extern int idbcontxSetTCONAlignment;  /* 174 */
extern int idcabattrDisplayString;  /* 175 */
extern int idcabattrGetCabinetIdFallback;  /* 176 */
extern int idcabattrGetCabinetProfile;  /* 177 */
extern int idcabattrGetNrOfCabinets;  /* 178 */
extern int idcabattrIsCabinetSupported;  /* 179 */
extern int idcabattrSetCabinetProfile;  /* 180 */
extern int idcrContrastReductionAllowed;  /* 181 */
extern int idcrContrastReductionSupported;  /* 182 */
extern int idcrGetActualContrastReduction;  /* 183 */
extern int idcrGetContrastReduction;  /* 184 */
extern int idcrResetContrastReductionTimer;  /* 185 */
extern int idcrSetContrastReduction;  /* 186 */
extern int idfilesplitGetCalculateCrcState;  /* 187 */
extern int idfilesplitGetCopySplitState;  /* 188 */
extern int idfilesplitGetDeleteState;  /* 189 */
extern int idfilesplitStartCalculateCrc;  /* 190 */
extern int idfilesplitStartCopySplit;  /* 191 */
extern int idfilesplitStartDelete;  /* 192 */
extern int idfilesplitStopCalculateCrc;  /* 193 */
extern int idfilesplitStopCopySplit;  /* 194 */
extern int idfilesplitStopDelete;  /* 195 */
extern int idgenitfGetAvailableInterfaces;  /* 196 */
extern int idhplgToggle;  /* 197 */
extern int idhwerrGetFirstError;  /* 198 */
extern int idhwerrGetLayer1Error;  /* 199 */
extern int idhwerrGetLayer2Error;  /* 200 */
extern int idpomGetPowerMeterValue;  /* 201 */
extern int idpomPowerMeterAllowed;  /* 202 */
extern int idpomPowerMeterSupported;  /* 203 */
extern int idsbpGetBalance;  /* 204 */
extern int idsbpGetFrequency;  /* 205 */
extern int idsbpGetMaxFrequency;  /* 206 */
extern int idsbpGetMaxVolume;  /* 207 */
extern int idsbpGetMinFrequency;  /* 208 */
extern int idsbpGetMinVolume;  /* 209 */
extern int idsbpGetMute;  /* 210 */
extern int idsbpGetVolume;  /* 211 */
extern int idsbpSetBalance;  /* 212 */
extern int idsbpSetFrequency;  /* 213 */
extern int idsbpSetMute;  /* 214 */
extern int idsbpSetVolume;  /* 215 */
extern int idscrattrDisplayString;  /* 216 */
extern int idscrattrDoubleFrameSupported;  /* 217 */
extern int idscrattrGetAspectRatio;  /* 218 */
extern int idscrattrGetClearLcd;  /* 219 */
extern int idscrattrGetFrameRate;  /* 220 */
extern int idscrattrGetFullHdSupported;  /* 221 */
extern int idscrattrGetPnxHorResolution;  /* 222 */
extern int idscrattrGetPnxVertResolution;  /* 223 */
extern int idscrattrGetScreenBitWidth;  /* 224 */
extern int idscrattrGetScreenBrand;  /* 225 */
extern int idscrattrGetScreenHorResolution;  /* 226 */
extern int idscrattrGetScreenIdFallback;  /* 227 */
extern int idscrattrGetScreenLvdsMode;  /* 228 */
extern int idscrattrGetScreenScanType;  /* 229 */
extern int idscrattrGetScreenSize;  /* 230 */
extern int idscrattrGetScreenType;  /* 231 */
extern int idscrattrGetScreenVertResolution;  /* 232 */
extern int idscrattrIsScreenSupported;  /* 233 */
extern int idservAreProtectionsEnabled;  /* 234 */
extern int idservClearProtectionState;  /* 235 */
extern int idservEnableProtections;  /* 236 */
extern int idservFunctionalTest;  /* 237 */
extern int idservGetFunctionalTestResult;  /* 238 */
extern int idservGetI2cRefreshState;  /* 239 */
extern int idservGetIdleMode;  /* 240 */
extern int idservGetNumberOfSteps;  /* 241 */
extern int idservGetPowerStep;  /* 242 */
extern int idservIsI2cTrafficLocked;  /* 243 */
extern int idservIsStepAllowed;  /* 244 */
extern int idservIsTransitionActive;  /* 245 */
extern int idservLockI2cTraffic;  /* 246 */
extern int idservSetI2cRefreshState;  /* 247 */
extern int idservSetIdleMode;  /* 248 */
extern int idservSetPowerStep;  /* 249 */
extern int idservUnlockI2cTraffic;  /* 250 */
extern int idsplaGetSplashScreen;  /* 251 */
extern int idsplaIsSplashScreenSupported;  /* 252 */
extern int idsplaSetSplashScreen;  /* 253 */
extern int idtmpctrlAbortFanBoardSelfTest;  /* 254 */
extern int idtmpctrlExecuteFanBoardSelfTest;  /* 255 */
extern int idtmpctrlGetFanBoardSelfTestResult;  /* 256 */
extern int idtmpctrlGetFanSpeed;  /* 257 */
extern int idtmpctrlGetMaxTemperature;  /* 258 */
extern int idtmpctrlGetSensorTemperature;  /* 259 */
extern int idtmpctrlGetTemperatureThreshold;  /* 260 */
extern int idtmpctrlIsFanBoardSelfTestSupported;  /* 261 */
extern int idtmpctrlIsFanSpeedSupported;  /* 262 */
extern int idtmpctrlIsMaxTemperatureSupported;  /* 263 */
extern int idtmpctrlIsSensorTemperatureSupported;  /* 264 */
extern int idtmpctrlIsTemperatureThresholdSupported;  /* 265 */
extern int idtmpctrlSetFanSpeedMode;  /* 266 */
extern int idtmpctrlSetManualFanSpeed;  /* 267 */
extern int idtmpctrlSetManualTemperatureThreshold;  /* 268 */
extern int idtmpctrlSetMaxTemperature;  /* 269 */
extern int idtmpctrlSetTemperatureThresholdMode;  /* 270 */
extern int idverGetDeviceVersion;  /* 271 */
extern int idverGetDeviceVersionEx;  /* 272 */
extern int idverGetSubsystemVersion;  /* 273 */
extern int idvgtpGetTestPattern;  /* 274 */
extern int idvgtpIsTestPatternAllowed;  /* 275 */
extern int idvgtpSetTestPattern;  /* 276 */
extern int plfapigenMethodID_Last;  /* 277 */

/*  Symbols for plfapigenNotificationID */
extern int idambNOnActiveLightModeAllowedChanged;  /* 0 */
extern int idambNOnActiveLightModeChanged;  /* 1 */
extern int idambNOnBalanceAllowedChanged;  /* 2 */
extern int idambNOnBalanceChanged;  /* 3 */
extern int idambNOnColorBoostAllowedChanged;  /* 4 */
extern int idambNOnColorBoostChanged;  /* 5 */
extern int idambNOnCyclingOnValueAllowedChanged;  /* 6 */
extern int idambNOnCyclingStopped;  /* 7 */
extern int idambNOnHueAllowedChanged;  /* 8 */
extern int idambNOnHueChanged;  /* 9 */
extern int idambNOnImmersionAllowedChanged;  /* 10 */
extern int idambNOnImmersionChanged;  /* 11 */
extern int idambNOnLavaLightModeAllowedChanged;  /* 12 */
extern int idambNOnLavaLightModeChanged;  /* 13 */
extern int idambNOnLightModeTypesAllowedChanged;  /* 14 */
extern int idambNOnLightModeTypesChanged;  /* 15 */
extern int idambNOnLightStateAllowedChanged;  /* 16 */
extern int idambNOnLightStateChanged;  /* 17 */
extern int idambNOnMuteAllowedChanged;  /* 18 */
extern int idambNOnMuteChanged;  /* 19 */
extern int idambNOnPredefinedModeAllowedChanged;  /* 20 */
extern int idambNOnPredefinedModeChanged;  /* 21 */
extern int idambNOnSaturationAllowedChanged;  /* 22 */
extern int idambNOnSaturationChanged;  /* 23 */
extern int idambNOnSeparationAllowedChanged;  /* 24 */
extern int idambNOnSeparationChanged;  /* 25 */
extern int idambNOnStaticLightModeAllowedChanged;  /* 26 */
extern int idambNOnStaticLightModeChanged;  /* 27 */
extern int idambNOnValueAllowedChanged;  /* 28 */
extern int idambNOnValueChanged;  /* 29 */
extern int idcrNOnContrastReductionAllowedChanged;  /* 30 */
extern int idcrNOnContrastReductionTimerExpired;  /* 31 */
extern int idfilesplitNOnCalculateCrcFinished;  /* 32 */
extern int idfilesplitNOnCopySplitFinished;  /* 33 */
extern int idfilesplitNOnDeleteFinished;  /* 34 */
extern int idgenitfNOnAvailabilityChanged;  /* 35 */
extern int idhwerrNOnError;  /* 36 */
extern int idservNOnFunctionalTestCompleted;  /* 37 */
extern int idservNOnI2cTrafficLocked;  /* 38 */
extern int idservNOnI2cTrafficUnlocked;  /* 39 */
extern int idservNOnIdleModeReached;  /* 40 */
extern int idservNOnPowerStepReached;  /* 41 */
extern int idtmpctrlNOnFanBoardSelfTestCompleted;  /* 42 */
extern int plfapigenNotificationID_Last;  /* 43 */

/*  Functions clients can call, implemented by the supplier. */
extern FResult plfapigen_aln_Default( int winid, int alignment, int * retval );
extern FResult plfapigen_aln_Get( int winid, int alignment, int * retval );
extern FResult plfapigen_aln_GetIx( int winid, int alignment, int index, int * retval );
extern FResult plfapigen_aln_GetMaxIx( int winid, int alignment, int * retval );
extern FResult plfapigen_aln_IsIxSupported( int winid, int alignment, Bool * retval );
extern FResult plfapigen_aln_IsSupported( int winid, int alignment, Bool * retval );
extern FResult plfapigen_aln_Max( int winid, int alignment, int * retval );
extern FResult plfapigen_aln_Min( int winid, int alignment, int * retval );
extern FResult plfapigen_aln_Recall( int winid );
extern FResult plfapigen_aln_RecallAlignment( int winid, int alignment );
extern FResult plfapigen_aln_Set( int winid, int alignment, int value );
extern FResult plfapigen_aln_SetIx( int winid, int alignment, int index, int value );
extern FResult plfapigen_aln_Store( int winid );
extern FResult plfapigen_aln_StoreAlignment( int winid, int alignment );
#define plfapigen_alnid_AmbientLightLeftInverted  ((int)33)
#define plfapigen_alnid_AmbientLightLeftInverted_CONSTANT  33
#define plfapigen_alnid_AmbientLightRightInverted  ((int)34)
#define plfapigen_alnid_AmbientLightRightInverted_CONSTANT  34
#define plfapigen_alnid_AmbientLightTopInverted  ((int)35)
#define plfapigen_alnid_AmbientLightTopInverted_CONSTANT  35
#define plfapigen_alnid_AutoSharpness  ((int)10)
#define plfapigen_alnid_AutoSharpness_CONSTANT  10
#define plfapigen_alnid_BlackLevelOffsetBlue  ((int)22)
#define plfapigen_alnid_BlackLevelOffsetBlue_CONSTANT  22
#define plfapigen_alnid_BlackLevelOffsetGreen  ((int)21)
#define plfapigen_alnid_BlackLevelOffsetGreen_CONSTANT  21
#define plfapigen_alnid_BlackLevelOffsetGreenCustom  ((int)32)
#define plfapigen_alnid_BlackLevelOffsetGreenCustom_CONSTANT  32
#define plfapigen_alnid_BlackLevelOffsetRed  ((int)20)
#define plfapigen_alnid_BlackLevelOffsetRed_CONSTANT  20
#define plfapigen_alnid_BlackLevelOffsetRedCustom  ((int)31)
#define plfapigen_alnid_BlackLevelOffsetRedCustom_CONSTANT  31
#define plfapigen_alnid_BlueAmplitudeCool  ((int)11)
#define plfapigen_alnid_BlueAmplitudeCool_CONSTANT  11
#define plfapigen_alnid_BlueAmplitudeCustom  ((int)30)
#define plfapigen_alnid_BlueAmplitudeCustom_CONSTANT  30
#define plfapigen_alnid_BlueAmplitudeNormal  ((int)12)
#define plfapigen_alnid_BlueAmplitudeNormal_CONSTANT  12
#define plfapigen_alnid_BlueAmplitudeWarm  ((int)13)
#define plfapigen_alnid_BlueAmplitudeWarm_CONSTANT  13
#define plfapigen_alnid_CompensationBlueToRed  ((int)24)
#define plfapigen_alnid_CompensationBlueToRed_CONSTANT  24
#define plfapigen_alnid_CompensationGreenToRed  ((int)25)
#define plfapigen_alnid_CompensationGreenToRed_CONSTANT  25
#define plfapigen_alnid_CompensationHours  ((int)23)
#define plfapigen_alnid_CompensationHours_CONSTANT  23
#define plfapigen_alnid_DisplayOperationHours  ((int)27)
#define plfapigen_alnid_DisplayOperationHours_CONSTANT  27
#define plfapigen_alnid_FirstAlignment  ((int)1)
#define plfapigen_alnid_FirstAlignment_CONSTANT  1
#define plfapigen_alnid_GreenAmplitudeCool  ((int)14)
#define plfapigen_alnid_GreenAmplitudeCool_CONSTANT  14
#define plfapigen_alnid_GreenAmplitudeCustom  ((int)29)
#define plfapigen_alnid_GreenAmplitudeCustom_CONSTANT  29
#define plfapigen_alnid_GreenAmplitudeNormal  ((int)15)
#define plfapigen_alnid_GreenAmplitudeNormal_CONSTANT  15
#define plfapigen_alnid_GreenAmplitudeWarm  ((int)16)
#define plfapigen_alnid_GreenAmplitudeWarm_CONSTANT  16
#define plfapigen_alnid_IfAgcSecondTunerTakeOver  ((int)2)
#define plfapigen_alnid_IfAgcSecondTunerTakeOver_CONSTANT  2
#define plfapigen_alnid_IfAgcTopPos  ((int)36)
#define plfapigen_alnid_IfAgcTopPos_CONSTANT  36
#define plfapigen_alnid_IfAgcTunerTakeOver  ((int)1)
#define plfapigen_alnid_IfAgcTunerTakeOver_CONSTANT  1
#define plfapigen_alnid_IfPllFastFilter  ((int)3)
#define plfapigen_alnid_IfPllFastFilter_CONSTANT  3
#define plfapigen_alnid_IfPllFastFilterSecondTuner  ((int)4)
#define plfapigen_alnid_IfPllFastFilterSecondTuner_CONSTANT  4
#define plfapigen_alnid_IfPllOffsetNegative  ((int)6)
#define plfapigen_alnid_IfPllOffsetNegative_CONSTANT  6
#define plfapigen_alnid_IfPllOffsetNegativeSecondTuner  ((int)8)
#define plfapigen_alnid_IfPllOffsetNegativeSecondTuner_CONSTANT  8
#define plfapigen_alnid_IfPllOffsetPositive  ((int)5)
#define plfapigen_alnid_IfPllOffsetPositive_CONSTANT  5
#define plfapigen_alnid_IfPllOffsetPositiveSecondTuner  ((int)7)
#define plfapigen_alnid_IfPllOffsetPositiveSecondTuner_CONSTANT  7
#define plfapigen_alnid_LastAlignment  ((int)39)
#define plfapigen_alnid_LastAlignment_CONSTANT  39
#define plfapigen_alnid_LightSensor  ((int)9)
#define plfapigen_alnid_LightSensor_CONSTANT  9
#define plfapigen_alnid_RedAmplitudeCool  ((int)17)
#define plfapigen_alnid_RedAmplitudeCool_CONSTANT  17
#define plfapigen_alnid_RedAmplitudeCustom  ((int)28)
#define plfapigen_alnid_RedAmplitudeCustom_CONSTANT  28
#define plfapigen_alnid_RedAmplitudeNormal  ((int)18)
#define plfapigen_alnid_RedAmplitudeNormal_CONSTANT  18
#define plfapigen_alnid_RedAmplitudeWarm  ((int)19)
#define plfapigen_alnid_RedAmplitudeWarm_CONSTANT  19
#define plfapigen_alnid_TunerIfGainCalibrationHigh  ((int)39)
#define plfapigen_alnid_TunerIfGainCalibrationHigh_CONSTANT  39
#define plfapigen_alnid_TunerIfGainCalibrationLow  ((int)37)
#define plfapigen_alnid_TunerIfGainCalibrationLow_CONSTANT  37
#define plfapigen_alnid_TunerIfGainCalibrationMedium  ((int)38)
#define plfapigen_alnid_TunerIfGainCalibrationMedium_CONSTANT  38
#define plfapigen_alnid_valIfPllFastFilterIncreased  ((int)2)
#define plfapigen_alnid_valIfPllFastFilterIncreased_CONSTANT  2
#define plfapigen_alnid_valIfPllFastFilterNormal  ((int)1)
#define plfapigen_alnid_valIfPllFastFilterNormal_CONSTANT  1
#define plfapigen_alnid_WhitepointCompensationFactor  ((int)26)
#define plfapigen_alnid_WhitepointCompensationFactor_CONSTANT  26
extern FResult plfapigen_amb_DisablePowerLimitation( int winid, Bool onoff );
extern FResult plfapigen_amb_EnableFallback( int winid, Bool onoff );
extern FResult plfapigen_amb_GetActiveLightMode( int winid, int * retval );
extern FResult plfapigen_amb_GetBalance( int winid, int * retval );
extern FResult plfapigen_amb_GetColorBoost( int winid, int * retval );
extern FResult plfapigen_amb_GetHue( int winid, int * retval );
extern FResult plfapigen_amb_GetImmersion( int winid, int * retval );
extern FResult plfapigen_amb_GetLavaLightMode( int winid, int * retval );
extern FResult plfapigen_amb_GetLightModeHue( int winid, int mode, int * retval );
extern FResult plfapigen_amb_GetLightModeSaturation( int winid, int mode, int * retval );
extern FResult plfapigen_amb_GetLightModeType( int winid, int * retval );
extern FResult plfapigen_amb_GetLightState( int winid, Bool * retval );
extern FResult plfapigen_amb_GetMute( int winid, Bool * retval );
extern FResult plfapigen_amb_GetPredefinedMode( int winid, int * retval );
extern FResult plfapigen_amb_GetSaturation( int winid, int * retval );
extern FResult plfapigen_amb_GetSeparation( int winid, int * retval );
extern FResult plfapigen_amb_GetStaticLightMode( int winid, int * retval );
extern FResult plfapigen_amb_GetSunset( int winid, Bool * retval );
extern FResult plfapigen_amb_GetValue( int winid, int * retval );
extern FResult plfapigen_amb_IsActiveLightModeAllowed( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsActiveLightModeSupported( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsBalanceAllowed( int winid, int bal, Bool * retval );
extern FResult plfapigen_amb_IsBalanceSupported( int winid, int bal, Bool * retval );
extern FResult plfapigen_amb_IsColorBoostAllowed( int winid, int boost, Bool * retval );
extern FResult plfapigen_amb_IsColorBoostSupported( int winid, int boost, Bool * retval );
extern FResult plfapigen_amb_IsCyclingOnValueAllowed( int winid, Bool * retval );
extern FResult plfapigen_amb_IsCyclingOnValueOngoing( int winid, Bool * retval );
extern FResult plfapigen_amb_IsCyclingOnValueSupported( int winid, Bool * retval );
extern FResult plfapigen_amb_IsFallbackEnabled( int winid, Bool * retval );
extern FResult plfapigen_amb_IsHueAllowed( int winid, int hue, Bool * retval );
extern FResult plfapigen_amb_IsHueSupported( int winid, int hue, Bool * retval );
extern FResult plfapigen_amb_IsImmersionAllowed( int winid, int im, Bool * retval );
extern FResult plfapigen_amb_IsImmersionSupported( int winid, int im, Bool * retval );
extern FResult plfapigen_amb_IsLavaLightModeAllowed( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsLavaLightModeSupported( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsLightModeHueSupported( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsLightModeSaturationSupported( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsLightModeTypeAllowed( int winid, int modeType, Bool * retval );
extern FResult plfapigen_amb_IsLightModeTypeSupported( int winid, int modeType, Bool * retval );
extern FResult plfapigen_amb_IsLightStateAllowed( int winid, Bool onoff, Bool * retval );
extern FResult plfapigen_amb_IsLightStateSupported( int winid, Bool onoff, Bool * retval );
extern FResult plfapigen_amb_IsMuteAllowed( int winid, Bool onoff, Bool * retval );
extern FResult plfapigen_amb_IsMuteSupported( int winid, Bool onoff, Bool * retval );
extern FResult plfapigen_amb_IsPowerLimitationDisabled( int winid, Bool * retval );
extern FResult plfapigen_amb_IsPredefinedModeAllowed( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsPredefinedModeSupported( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsSaturationAllowed( int winid, int sat, Bool * retval );
extern FResult plfapigen_amb_IsSaturationSupported( int winid, int sat, Bool * retval );
extern FResult plfapigen_amb_IsSeparationAllowed( int winid, int sep, Bool * retval );
extern FResult plfapigen_amb_IsSeparationSupported( int winid, int sep, Bool * retval );
extern FResult plfapigen_amb_IsStaticLightModeAllowed( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsStaticLightModeSupported( int winid, int mode, Bool * retval );
extern FResult plfapigen_amb_IsSunsetSupported( int winid, Bool * retval );
extern FResult plfapigen_amb_IsValueAllowed( int winid, int val, Bool * retval );
extern FResult plfapigen_amb_IsValueSupported( int winid, int val, Bool * retval );
extern FResult plfapigen_amb_SetActiveLightMode( int winid, int mode );
extern FResult plfapigen_amb_SetBalance( int winid, int bal );
extern FResult plfapigen_amb_SetColorBoost( int winid, int boost );
extern FResult plfapigen_amb_SetHue( int winid, int hue );
extern FResult plfapigen_amb_SetImmersion( int winid, int im );
extern FResult plfapigen_amb_SetLavaLightMode( int winid, int mode );
extern FResult plfapigen_amb_SetLightModeType( int winid, int modeType );
extern FResult plfapigen_amb_SetLightState( int winid, Bool onoff, Bool * retval );
extern FResult plfapigen_amb_SetMute( int winid, Bool onoff, Bool * retval );
extern FResult plfapigen_amb_SetPredefinedMode( int winid, int mode );
extern FResult plfapigen_amb_SetSaturation( int winid, int sat );
extern FResult plfapigen_amb_SetSeparation( int winid, int sep );
extern FResult plfapigen_amb_SetStaticLightMode( int winid, int mode );
extern FResult plfapigen_amb_SetSunset( int winid, Bool onoff );
extern FResult plfapigen_amb_SetValue( int winid, int val );
extern FResult plfapigen_amb_StartCyclingOnValue( int winid );
extern FResult plfapigen_amb_StopCyclingOnValue( int winid );
#define plfapigen_amb_ColorBoostMax  ((int)3)
#define plfapigen_amb_ColorBoostMax_CONSTANT  3
#define plfapigen_amb_ColorBoostMed  ((int)2)
#define plfapigen_amb_ColorBoostMed_CONSTANT  2
#define plfapigen_amb_ColorBoostMin  ((int)1)
#define plfapigen_amb_ColorBoostMin_CONSTANT  1
#define plfapigen_amb_ColorBoostOff  ((int)0)
#define plfapigen_amb_ColorBoostOff_CONSTANT  0
#define plfapigen_amb_Eco  ((int)4)
#define plfapigen_amb_Eco_CONSTANT  4
#define plfapigen_amb_Game  ((int)6)
#define plfapigen_amb_Game_CONSTANT  6
#define plfapigen_amb_MaxBalance  ((int)50)
#define plfapigen_amb_MaxBalance_CONSTANT  50
#define plfapigen_amb_MaxHue  ((int)100)
#define plfapigen_amb_MaxHue_CONSTANT  100
#define plfapigen_amb_MaxImmersion  ((int)10)
#define plfapigen_amb_MaxImmersion_CONSTANT  10
#define plfapigen_amb_MaxSaturation  ((int)100)
#define plfapigen_amb_MaxSaturation_CONSTANT  100
#define plfapigen_amb_MaxValue  ((int)100)
#define plfapigen_amb_MaxValue_CONSTANT  100
#define plfapigen_amb_MedBalance  ((int)0)
#define plfapigen_amb_MedBalance_CONSTANT  0
#define plfapigen_amb_MinBalance  ((int)-50)
#define plfapigen_amb_MinBalance_CONSTANT  -50
#define plfapigen_amb_MinHue  ((int)0)
#define plfapigen_amb_MinHue_CONSTANT  0
#define plfapigen_amb_MinImmersion  ((int)0)
#define plfapigen_amb_MinImmersion_CONSTANT  0
#define plfapigen_amb_MinSaturation  ((int)0)
#define plfapigen_amb_MinSaturation_CONSTANT  0
#define plfapigen_amb_MinValue  ((int)0)
#define plfapigen_amb_MinValue_CONSTANT  0
#define plfapigen_amb_ModeAction  ((int)3)
#define plfapigen_amb_ModeAction_CONSTANT  3
#define plfapigen_amb_ModeActiveCustom  ((int)0)
#define plfapigen_amb_ModeActiveCustom_CONSTANT  0
#define plfapigen_amb_ModeAmbiance  ((int)2)
#define plfapigen_amb_ModeAmbiance_CONSTANT  2
#define plfapigen_amb_ModeBlue  ((int)5)
#define plfapigen_amb_ModeBlue_CONSTANT  5
#define plfapigen_amb_ModeCoolWhite  ((int)3)
#define plfapigen_amb_ModeCoolWhite_CONSTANT  3
#define plfapigen_amb_ModeGreen  ((int)6)
#define plfapigen_amb_ModeGreen_CONSTANT  6
#define plfapigen_amb_ModeLava1  ((int)1)
#define plfapigen_amb_ModeLava1_CONSTANT  1
#define plfapigen_amb_ModeLava2  ((int)2)
#define plfapigen_amb_ModeLava2_CONSTANT  2
#define plfapigen_amb_ModeLava3  ((int)3)
#define plfapigen_amb_ModeLava3_CONSTANT  3
#define plfapigen_amb_ModeLava4  ((int)4)
#define plfapigen_amb_ModeLava4_CONSTANT  4
#define plfapigen_amb_ModeLavaCustom  ((int)0)
#define plfapigen_amb_ModeLavaCustom_CONSTANT  0
#define plfapigen_amb_ModeModerate  ((int)5)
#define plfapigen_amb_ModeModerate_CONSTANT  5
#define plfapigen_amb_ModeMovie  ((int)4)
#define plfapigen_amb_ModeMovie_CONSTANT  4
#define plfapigen_amb_ModeRed  ((int)4)
#define plfapigen_amb_ModeRed_CONSTANT  4
#define plfapigen_amb_ModeRelaxing  ((int)1)
#define plfapigen_amb_ModeRelaxing_CONSTANT  1
#define plfapigen_amb_ModeStaticCustom  ((int)0)
#define plfapigen_amb_ModeStaticCustom_CONSTANT  0
#define plfapigen_amb_ModeTypeActive  ((int)0)
#define plfapigen_amb_ModeTypeActive_CONSTANT  0
#define plfapigen_amb_ModeTypeDynamicLounge  ((int)3)
#define plfapigen_amb_ModeTypeDynamicLounge_CONSTANT  3
#define plfapigen_amb_ModeTypeLava  ((int)2)
#define plfapigen_amb_ModeTypeLava_CONSTANT  2
#define plfapigen_amb_ModeTypeStatic  ((int)1)
#define plfapigen_amb_ModeTypeStatic_CONSTANT  1
#define plfapigen_amb_ModeWarmWhite  ((int)1)
#define plfapigen_amb_ModeWarmWhite_CONSTANT  1
#define plfapigen_amb_ModeWhite  ((int)2)
#define plfapigen_amb_ModeWhite_CONSTANT  2
#define plfapigen_amb_Neutral  ((int)2)
#define plfapigen_amb_Neutral_CONSTANT  2
#define plfapigen_amb_SeparationMax  ((int)3)
#define plfapigen_amb_SeparationMax_CONSTANT  3
#define plfapigen_amb_SeparationMed  ((int)2)
#define plfapigen_amb_SeparationMed_CONSTANT  2
#define plfapigen_amb_SeparationMin  ((int)1)
#define plfapigen_amb_SeparationMin_CONSTANT  1
#define plfapigen_amb_SeparationOff  ((int)0)
#define plfapigen_amb_SeparationOff_CONSTANT  0
#define plfapigen_amb_Shop  ((int)5)
#define plfapigen_amb_Shop_CONSTANT  5
#define plfapigen_amb_Standard  ((int)3)
#define plfapigen_amb_Standard_CONSTANT  3
#define plfapigen_amb_Vivid  ((int)1)
#define plfapigen_amb_Vivid_CONSTANT  1
extern FResult plfapigen_ambl_ApplySettings( int winid );
extern FResult plfapigen_ambl_CheckSettingsApplied( int winid, int * retval );
extern FResult plfapigen_ambl_EnableFactoryMode( int winid, Bool enable );
extern FResult plfapigen_ambl_GetColorBoost( int winid, int * retval );
extern FResult plfapigen_ambl_GetContrast( int winid, int * left, int * right, int * top, int * bottom );
extern FResult plfapigen_ambl_GetImmersion( int winid, int * retval );
extern FResult plfapigen_ambl_GetLampTestZone( int winid, int * zone );
extern FResult plfapigen_ambl_GetLavaRGB( int winid, int * r1, int * g1, int * b1, int * r2, int * g2, int * b2, int * lavaAlgo );
extern FResult plfapigen_ambl_GetMatrixBoard( int winid, int * board, int * Rr, int * Rg, int * Rb, int * Gr, int * Gg, int * Gb, int * Br, int * Bg, int * Bb, int * Rfactor, int * Gfactor, int * Bfactor );
extern FResult plfapigen_ambl_GetMode( int winid, int * retval );
extern FResult plfapigen_ambl_GetRGB( int winid, int * red, int * green, int * blue );
extern FResult plfapigen_ambl_GetSeparation( int winid, int * retval );
extern FResult plfapigen_ambl_GetState( int winid, Bool * retval );
extern FResult plfapigen_ambl_GetStaticRGB( int winid, int * red, int * green, int * blue );
extern FResult plfapigen_ambl_GetWallColors( int winid, Nat32 * size, Nat8 * Red, Nat8 * Green, Nat8 * Blue );
extern FResult plfapigen_ambl_IsColorBoostSupported( int winid, int boost, Bool * retval );
extern FResult plfapigen_ambl_IsContrastSupported( int winid, int left, int right, int top, int bottom, Bool * retval );
extern FResult plfapigen_ambl_IsImmersionSupported( int winid, int immersion, Bool * retval );
extern FResult plfapigen_ambl_IsLampTestZoneSupported( int winid, int zone, Bool * retval );
extern FResult plfapigen_ambl_IsLavaRGBSupported( int winid, int r1, int g1, int b1, int r2, int g2, int b2, int lavaAlgo, Bool * retval );
extern FResult plfapigen_ambl_IsModeSupported( int winid, int mode, Bool * retval );
extern FResult plfapigen_ambl_IsSeparationSupported( int winid, int level, Bool * retval );
extern FResult plfapigen_ambl_IsStateSupported( int winid, Bool onoff, Bool * retval );
extern FResult plfapigen_ambl_IsStaticRGBSupported( int winid, int red, int green, int blue, Bool * retval );
extern FResult plfapigen_ambl_SelectWallColor( int winid, Nat32 index );
extern FResult plfapigen_ambl_SetColorBoost( int winid, int level );
extern FResult plfapigen_ambl_SetContrast( int winid, int left, int right, int top, int bottom );
extern FResult plfapigen_ambl_SetCurrent( int winid, int r, int g, int b );
extern FResult plfapigen_ambl_SetImmersion( int winid, int immersion );
extern FResult plfapigen_ambl_SetLampTestZone( int winid, int zone );
extern FResult plfapigen_ambl_SetLavaRGB( int winid, int r1, int g1, int b1, int r2, int g2, int b2, int lavaAlgo );
extern FResult plfapigen_ambl_SetMatrix( int winid, int pixel, int Rr, int Rg, int Rb, int Gr, int Gg, int Gb, int Br, int Bg, int Bb, int Rfactor, int Gfactor, int Bfactor );
extern FResult plfapigen_ambl_SetMatrixBoard( int winid, int board, int Rr, int Rg, int Rb, int Gr, int Gg, int Gb, int Br, int Bg, int Bb, int Rfactor, int Gfactor, int Bfactor );
extern FResult plfapigen_ambl_SetMode( int winid, int mode );
extern FResult plfapigen_ambl_SetPixel( int winid, int pixel, int r, int g, int b );
extern FResult plfapigen_ambl_SetRGB( int winid, int red, int green, int blue );
extern FResult plfapigen_ambl_SetSeparation( int winid, int level );
extern FResult plfapigen_ambl_SetState( int winid, Bool onoff );
extern FResult plfapigen_ambl_SetStaticRGB( int winid, int red, int green, int blue );
#define plfapigen_ambl_BlueMax  ((int)255)
#define plfapigen_ambl_BlueMax_CONSTANT  255
#define plfapigen_ambl_BlueMin  ((int)0)
#define plfapigen_ambl_BlueMin_CONSTANT  0
#define plfapigen_ambl_CheckSettingsApplied_busy  ((int)1)
#define plfapigen_ambl_CheckSettingsApplied_busy_CONSTANT  1
#define plfapigen_ambl_CheckSettingsApplied_failed  ((int)2)
#define plfapigen_ambl_CheckSettingsApplied_failed_CONSTANT  2
#define plfapigen_ambl_CheckSettingsApplied_ok  ((int)0)
#define plfapigen_ambl_CheckSettingsApplied_ok_CONSTANT  0
#define plfapigen_ambl_ColorBoostMax  ((int)3)
#define plfapigen_ambl_ColorBoostMax_CONSTANT  3
#define plfapigen_ambl_ColorBoostMed  ((int)2)
#define plfapigen_ambl_ColorBoostMed_CONSTANT  2
#define plfapigen_ambl_ColorBoostMin  ((int)1)
#define plfapigen_ambl_ColorBoostMin_CONSTANT  1
#define plfapigen_ambl_ColorBoostOff  ((int)0)
#define plfapigen_ambl_ColorBoostOff_CONSTANT  0
#define plfapigen_ambl_GreenMax  ((int)255)
#define plfapigen_ambl_GreenMax_CONSTANT  255
#define plfapigen_ambl_GreenMin  ((int)0)
#define plfapigen_ambl_GreenMin_CONSTANT  0
#define plfapigen_ambl_LavaAlgoMax  ((int)4)
#define plfapigen_ambl_LavaAlgoMax_CONSTANT  4
#define plfapigen_ambl_LavaAlgoMin  ((int)1)
#define plfapigen_ambl_LavaAlgoMin_CONSTANT  1
#define plfapigen_ambl_LavaBlueMax  ((int)15)
#define plfapigen_ambl_LavaBlueMax_CONSTANT  15
#define plfapigen_ambl_LavaBlueMin  ((int)0)
#define plfapigen_ambl_LavaBlueMin_CONSTANT  0
#define plfapigen_ambl_LavaGreenMax  ((int)15)
#define plfapigen_ambl_LavaGreenMax_CONSTANT  15
#define plfapigen_ambl_LavaGreenMin  ((int)0)
#define plfapigen_ambl_LavaGreenMin_CONSTANT  0
#define plfapigen_ambl_LavaRedMax  ((int)15)
#define plfapigen_ambl_LavaRedMax_CONSTANT  15
#define plfapigen_ambl_LavaRedMin  ((int)0)
#define plfapigen_ambl_LavaRedMin_CONSTANT  0
#define plfapigen_ambl_MaxContrast  ((int)255)
#define plfapigen_ambl_MaxContrast_CONSTANT  255
#define plfapigen_ambl_MaxImmersion  ((int)10)
#define plfapigen_ambl_MaxImmersion_CONSTANT  10
#define plfapigen_ambl_MaxLampTestZone  ((int)13)
#define plfapigen_ambl_MaxLampTestZone_CONSTANT  13
#define plfapigen_ambl_MaxNbrOfWallColors  ((int)24)
#define plfapigen_ambl_MaxNbrOfWallColors_CONSTANT  24
#define plfapigen_ambl_MinContrast  ((int)0)
#define plfapigen_ambl_MinContrast_CONSTANT  0
#define plfapigen_ambl_MinImmersion  ((int)0)
#define plfapigen_ambl_MinImmersion_CONSTANT  0
#define plfapigen_ambl_MinLampTestZone  ((int)0)
#define plfapigen_ambl_MinLampTestZone_CONSTANT  0
#define plfapigen_ambl_ModeActive  ((int)0)
#define plfapigen_ambl_ModeActive_CONSTANT  0
#define plfapigen_ambl_ModeDynamic  ((int)2)
#define plfapigen_ambl_ModeDynamic_CONSTANT  2
#define plfapigen_ambl_ModeLampTest  ((int)3)
#define plfapigen_ambl_ModeLampTest_CONSTANT  3
#define plfapigen_ambl_ModeLava  ((int)2)
#define plfapigen_ambl_ModeLava_CONSTANT  2
#define plfapigen_ambl_ModeModerate  ((int)4)
#define plfapigen_ambl_ModeModerate_CONSTANT  4
#define plfapigen_ambl_ModeMovie  ((int)3)
#define plfapigen_ambl_ModeMovie_CONSTANT  3
#define plfapigen_ambl_ModeNormal  ((int)1)
#define plfapigen_ambl_ModeNormal_CONSTANT  1
#define plfapigen_ambl_ModeRelaxing  ((int)0)
#define plfapigen_ambl_ModeRelaxing_CONSTANT  0
#define plfapigen_ambl_ModeStatic  ((int)1)
#define plfapigen_ambl_ModeStatic_CONSTANT  1
#define plfapigen_ambl_RedMax  ((int)255)
#define plfapigen_ambl_RedMax_CONSTANT  255
#define plfapigen_ambl_RedMin  ((int)0)
#define plfapigen_ambl_RedMin_CONSTANT  0
#define plfapigen_ambl_SeparationMax  ((int)3)
#define plfapigen_ambl_SeparationMax_CONSTANT  3
#define plfapigen_ambl_SeparationMed  ((int)2)
#define plfapigen_ambl_SeparationMed_CONSTANT  2
#define plfapigen_ambl_SeparationMin  ((int)1)
#define plfapigen_ambl_SeparationMin_CONSTANT  1
#define plfapigen_ambl_SeparationOff  ((int)0)
#define plfapigen_ambl_SeparationOff_CONSTANT  0
#define plfapigen_ambl_StaticBlueMax  ((int)255)
#define plfapigen_ambl_StaticBlueMax_CONSTANT  255
#define plfapigen_ambl_StaticBlueMin  ((int)0)
#define plfapigen_ambl_StaticBlueMin_CONSTANT  0
#define plfapigen_ambl_StaticGreenMax  ((int)255)
#define plfapigen_ambl_StaticGreenMax_CONSTANT  255
#define plfapigen_ambl_StaticGreenMin  ((int)0)
#define plfapigen_ambl_StaticGreenMin_CONSTANT  0
#define plfapigen_ambl_StaticRedMax  ((int)255)
#define plfapigen_ambl_StaticRedMax_CONSTANT  255
#define plfapigen_ambl_StaticRedMin  ((int)0)
#define plfapigen_ambl_StaticRedMin_CONSTANT  0
extern FResult plfapigen_amblx_ApplySettings( int winid );
extern FResult plfapigen_amblx_CheckSettingsApplied( int winid, int * retval );
extern FResult plfapigen_amblx_EnableFactoryMode( int winid, Bool enable );
extern FResult plfapigen_amblx_GetBrightnessBoard( int winid, int board, int * Rfactor, int * Gfactor, int * Bfactor );
extern FResult plfapigen_amblx_GetColorBoost( int winid, int * retval );
extern FResult plfapigen_amblx_GetContrast( int winid, int * left, int * right, int * top, int * bottom );
extern FResult plfapigen_amblx_GetCorrectionBoard( int winid, int board, int * correction );
extern FResult plfapigen_amblx_GetImmersion( int winid, int * retval );
extern FResult plfapigen_amblx_GetLampTestZone( int winid, int * zone );
extern FResult plfapigen_amblx_GetLavaRGB( int winid, int * r1, int * g1, int * b1, int * r2, int * g2, int * b2, int * lavaAlgo );
extern FResult plfapigen_amblx_GetMatrixBoard( int winid, int board, int * Rr, int * Rg, int * Rb, int * Gr, int * Gg, int * Gb, int * Br, int * Bg, int * Bb );
extern FResult plfapigen_amblx_GetMode( int winid, int * retval );
extern FResult plfapigen_amblx_GetRGB( int winid, int * red, int * green, int * blue );
extern FResult plfapigen_amblx_GetSeparation( int winid, int * retval );
extern FResult plfapigen_amblx_GetState( int winid, Bool * retval );
extern FResult plfapigen_amblx_GetStaticRGB( int winid, int * red, int * green, int * blue );
extern FResult plfapigen_amblx_GetWallColors( int winid, Nat32 * size, Nat8 * Red, Nat8 * Green, Nat8 * Blue );
extern FResult plfapigen_amblx_IsColorBoostSupported( int winid, int boost, Bool * retval );
extern FResult plfapigen_amblx_IsContrastSupported( int winid, int left, int right, int top, int bottom, Bool * retval );
extern FResult plfapigen_amblx_IsImmersionSupported( int winid, int immersion, Bool * retval );
extern FResult plfapigen_amblx_IsLampTestZoneSupported( int winid, int zone, Bool * retval );
extern FResult plfapigen_amblx_IsLavaRGBSupported( int winid, int r1, int g1, int b1, int r2, int g2, int b2, int lavaAlgo, Bool * retval );
extern FResult plfapigen_amblx_IsModeSupported( int winid, int mode, Bool * retval );
extern FResult plfapigen_amblx_IsSeparationSupported( int winid, int level, Bool * retval );
extern FResult plfapigen_amblx_IsStateSupported( int winid, Bool onoff, Bool * retval );
extern FResult plfapigen_amblx_IsStaticRGBSupported( int winid, int red, int green, int blue, Bool * retval );
extern FResult plfapigen_amblx_SelectWallColor( int winid, Nat32 index );
extern FResult plfapigen_amblx_SetBrightnessBoard( int winid, int board, int Rfactor, int Gfactor, int Bfactor );
extern FResult plfapigen_amblx_SetColorBoost( int winid, int level );
extern FResult plfapigen_amblx_SetContrast( int winid, int left, int right, int top, int bottom );
extern FResult plfapigen_amblx_SetCorrectionBoard( int winid, int board, int correction );
extern FResult plfapigen_amblx_SetCurrent( int winid, int r, int g, int b );
extern FResult plfapigen_amblx_SetImmersion( int winid, int immersion );
extern FResult plfapigen_amblx_SetLampTestZone( int winid, int zone );
extern FResult plfapigen_amblx_SetLavaRGB( int winid, int r1, int g1, int b1, int r2, int g2, int b2, int lavaAlgo );
extern FResult plfapigen_amblx_SetMatrix( int winid, int pixel, int Rr, int Rg, int Rb, int Gr, int Gg, int Gb, int Br, int Bg, int Bb, int Rfactor, int Gfactor, int Bfactor );
extern FResult plfapigen_amblx_SetMatrixBoard( int winid, int board, int Rr, int Rg, int Rb, int Gr, int Gg, int Gb, int Br, int Bg, int Bb );
extern FResult plfapigen_amblx_SetMode( int winid, int mode );
extern FResult plfapigen_amblx_SetPixel( int winid, int pixel, int r, int g, int b );
extern FResult plfapigen_amblx_SetRGB( int winid, int red, int green, int blue );
extern FResult plfapigen_amblx_SetSeparation( int winid, int level );
extern FResult plfapigen_amblx_SetState( int winid, Bool onoff );
extern FResult plfapigen_amblx_SetStaticRGB( int winid, int red, int green, int blue );
#define plfapigen_amblx_BlueMax  ((int)255)
#define plfapigen_amblx_BlueMax_CONSTANT  255
#define plfapigen_amblx_BlueMin  ((int)0)
#define plfapigen_amblx_BlueMin_CONSTANT  0
#define plfapigen_amblx_CheckSettingsApplied_busy  ((int)1)
#define plfapigen_amblx_CheckSettingsApplied_busy_CONSTANT  1
#define plfapigen_amblx_CheckSettingsApplied_failed  ((int)2)
#define plfapigen_amblx_CheckSettingsApplied_failed_CONSTANT  2
#define plfapigen_amblx_CheckSettingsApplied_ok  ((int)0)
#define plfapigen_amblx_CheckSettingsApplied_ok_CONSTANT  0
#define plfapigen_amblx_ColorBoostMax  ((int)3)
#define plfapigen_amblx_ColorBoostMax_CONSTANT  3
#define plfapigen_amblx_ColorBoostMed  ((int)2)
#define plfapigen_amblx_ColorBoostMed_CONSTANT  2
#define plfapigen_amblx_ColorBoostMin  ((int)1)
#define plfapigen_amblx_ColorBoostMin_CONSTANT  1
#define plfapigen_amblx_ColorBoostOff  ((int)0)
#define plfapigen_amblx_ColorBoostOff_CONSTANT  0
#define plfapigen_amblx_GreenMax  ((int)255)
#define plfapigen_amblx_GreenMax_CONSTANT  255
#define plfapigen_amblx_GreenMin  ((int)0)
#define plfapigen_amblx_GreenMin_CONSTANT  0
#define plfapigen_amblx_LavaAlgoMax  ((int)4)
#define plfapigen_amblx_LavaAlgoMax_CONSTANT  4
#define plfapigen_amblx_LavaAlgoMin  ((int)1)
#define plfapigen_amblx_LavaAlgoMin_CONSTANT  1
#define plfapigen_amblx_LavaBlueMax  ((int)15)
#define plfapigen_amblx_LavaBlueMax_CONSTANT  15
#define plfapigen_amblx_LavaBlueMin  ((int)0)
#define plfapigen_amblx_LavaBlueMin_CONSTANT  0
#define plfapigen_amblx_LavaGreenMax  ((int)15)
#define plfapigen_amblx_LavaGreenMax_CONSTANT  15
#define plfapigen_amblx_LavaGreenMin  ((int)0)
#define plfapigen_amblx_LavaGreenMin_CONSTANT  0
#define plfapigen_amblx_LavaRedMax  ((int)15)
#define plfapigen_amblx_LavaRedMax_CONSTANT  15
#define plfapigen_amblx_LavaRedMin  ((int)0)
#define plfapigen_amblx_LavaRedMin_CONSTANT  0
#define plfapigen_amblx_MaxContrast  ((int)255)
#define plfapigen_amblx_MaxContrast_CONSTANT  255
#define plfapigen_amblx_MaxImmersion  ((int)10)
#define plfapigen_amblx_MaxImmersion_CONSTANT  10
#define plfapigen_amblx_MaxLampTestZone  ((int)13)
#define plfapigen_amblx_MaxLampTestZone_CONSTANT  13
#define plfapigen_amblx_MaxNbrOfWallColors  ((int)24)
#define plfapigen_amblx_MaxNbrOfWallColors_CONSTANT  24
#define plfapigen_amblx_MinContrast  ((int)0)
#define plfapigen_amblx_MinContrast_CONSTANT  0
#define plfapigen_amblx_MinImmersion  ((int)0)
#define plfapigen_amblx_MinImmersion_CONSTANT  0
#define plfapigen_amblx_MinLampTestZone  ((int)0)
#define plfapigen_amblx_MinLampTestZone_CONSTANT  0
#define plfapigen_amblx_ModeActive  ((int)0)
#define plfapigen_amblx_ModeActive_CONSTANT  0
#define plfapigen_amblx_ModeDynamic  ((int)2)
#define plfapigen_amblx_ModeDynamic_CONSTANT  2
#define plfapigen_amblx_ModeLampTest  ((int)3)
#define plfapigen_amblx_ModeLampTest_CONSTANT  3
#define plfapigen_amblx_ModeLava  ((int)2)
#define plfapigen_amblx_ModeLava_CONSTANT  2
#define plfapigen_amblx_ModeModerate  ((int)4)
#define plfapigen_amblx_ModeModerate_CONSTANT  4
#define plfapigen_amblx_ModeMovie  ((int)3)
#define plfapigen_amblx_ModeMovie_CONSTANT  3
#define plfapigen_amblx_ModeNormal  ((int)1)
#define plfapigen_amblx_ModeNormal_CONSTANT  1
#define plfapigen_amblx_ModeRelaxing  ((int)0)
#define plfapigen_amblx_ModeRelaxing_CONSTANT  0
#define plfapigen_amblx_ModeStatic  ((int)1)
#define plfapigen_amblx_ModeStatic_CONSTANT  1
#define plfapigen_amblx_RedMax  ((int)255)
#define plfapigen_amblx_RedMax_CONSTANT  255
#define plfapigen_amblx_RedMin  ((int)0)
#define plfapigen_amblx_RedMin_CONSTANT  0
#define plfapigen_amblx_SeparationMax  ((int)3)
#define plfapigen_amblx_SeparationMax_CONSTANT  3
#define plfapigen_amblx_SeparationMed  ((int)2)
#define plfapigen_amblx_SeparationMed_CONSTANT  2
#define plfapigen_amblx_SeparationMin  ((int)1)
#define plfapigen_amblx_SeparationMin_CONSTANT  1
#define plfapigen_amblx_SeparationOff  ((int)0)
#define plfapigen_amblx_SeparationOff_CONSTANT  0
#define plfapigen_amblx_StaticBlueMax  ((int)255)
#define plfapigen_amblx_StaticBlueMax_CONSTANT  255
#define plfapigen_amblx_StaticBlueMin  ((int)0)
#define plfapigen_amblx_StaticBlueMin_CONSTANT  0
#define plfapigen_amblx_StaticGreenMax  ((int)255)
#define plfapigen_amblx_StaticGreenMax_CONSTANT  255
#define plfapigen_amblx_StaticGreenMin  ((int)0)
#define plfapigen_amblx_StaticGreenMin_CONSTANT  0
#define plfapigen_amblx_StaticRedMax  ((int)255)
#define plfapigen_amblx_StaticRedMax_CONSTANT  255
#define plfapigen_amblx_StaticRedMin  ((int)0)
#define plfapigen_amblx_StaticRedMin_CONSTANT  0
extern FResult plfapigen_bcont_DisableFactoryMode( int winid );
extern FResult plfapigen_bcont_EnableFactoryMode( int winid );
extern FResult plfapigen_bcontx_DisableFactoryMode( int winid );
extern FResult plfapigen_bcontx_EnableFactoryMode( int winid );
extern FResult plfapigen_bcontx_GetTCONAlignment( int winid, int * retval );
extern FResult plfapigen_bcontx_ResetTCONAlignment( int winid );
extern FResult plfapigen_bcontx_SetTCONAlignment( int winid, int value );
extern FResult plfapigen_cabattr_DisplayString( int winid, int cabinetid, int length, char * retval );
extern FResult plfapigen_cabattr_GetCabinetIdFallback( int winid, int * retval );
extern FResult plfapigen_cabattr_GetCabinetProfile( int winid, int * retval );
extern FResult plfapigen_cabattr_GetNrOfCabinets( int winid, int * retval );
extern FResult plfapigen_cabattr_IsCabinetSupported( int winid, int cabinetid, Bool * retval );
extern FResult plfapigen_cabattr_SetCabinetProfile( int winid, int profileId );
#define plfapigen_cabattr_ProfileTableStand  ((int)0)
#define plfapigen_cabattr_ProfileTableStand_CONSTANT  0
#define plfapigen_cabattr_ProfileWallHugging  ((int)1)
#define plfapigen_cabattr_ProfileWallHugging_CONSTANT  1
extern FResult plfapigen_cr_ContrastReductionAllowed( int winid, int layer, Bool * retval );
extern FResult plfapigen_cr_ContrastReductionSupported( int winid, int layer, Bool * retval );
extern FResult plfapigen_cr_GetActualContrastReduction( int winid, int layer, Bool * retval );
extern FResult plfapigen_cr_GetContrastReduction( int winid, int layer, Bool * retval );
extern FResult plfapigen_cr_ResetContrastReductionTimer( int winid, int layer );
extern FResult plfapigen_cr_SetContrastReduction( int winid, int layer, Bool enable );
#define plfapigen_cr_GfxLayer0  ((int)2)
#define plfapigen_cr_GfxLayer0_CONSTANT  2
#define plfapigen_cr_GfxLayer1  ((int)4)
#define plfapigen_cr_GfxLayer1_CONSTANT  4
#define plfapigen_cr_VideoLayer  ((int)1)
#define plfapigen_cr_VideoLayer_CONSTANT  1
#define plfapigen_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapigen_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapigen_errid_Ok  ((FResult)0)
#define plfapigen_errid_Ok_CONSTANT  0
#define plfapigen_errid_Other  ((FResult)-1)
#define plfapigen_errid_Other_CONSTANT  -1
#define plfapigen_errid_ResourceNotOwned  ((FResult)1)
#define plfapigen_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapigen_filesplit_GetCalculateCrcState( int winid, Nat32 * calcCrc, int * retVal );
extern FResult plfapigen_filesplit_GetCopySplitState( int winid, int * retVal );
extern FResult plfapigen_filesplit_GetDeleteState( int winid, int * retVal );
extern FResult plfapigen_filesplit_StartCalculateCrc( int winid, char * path, int * retVal );
extern FResult plfapigen_filesplit_StartCopySplit( int winid, int chunkSize, char * srcPath, char * destPath, Bool simplyCopy, int * retVal );
extern FResult plfapigen_filesplit_StartDelete( int winid, char * path, int * retVal );
extern FResult plfapigen_filesplit_StopCalculateCrc( int winid, int * retVal );
extern FResult plfapigen_filesplit_StopCopySplit( int winid, int * retVal );
extern FResult plfapigen_filesplit_StopDelete( int winid, int * retVal );
#define plfapigen_filesplit_stateAlreadyStarted  ((int)-1)
#define plfapigen_filesplit_stateAlreadyStarted_CONSTANT  -1
#define plfapigen_filesplit_stateBusy  ((int)2)
#define plfapigen_filesplit_stateBusy_CONSTANT  2
#define plfapigen_filesplit_stateDestFailed  ((int)-3)
#define plfapigen_filesplit_stateDestFailed_CONSTANT  -3
#define plfapigen_filesplit_stateFailed  ((int)-4)
#define plfapigen_filesplit_stateFailed_CONSTANT  -4
#define plfapigen_filesplit_stateNotStarted  ((int)1)
#define plfapigen_filesplit_stateNotStarted_CONSTANT  1
#define plfapigen_filesplit_stateOk  ((int)0)
#define plfapigen_filesplit_stateOk_CONSTANT  0
#define plfapigen_filesplit_stateSrcFailed  ((int)-2)
#define plfapigen_filesplit_stateSrcFailed_CONSTANT  -2
extern FResult plfapigen_genitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids );
#define plfapigen_genitfid_aln  ((Nat32)1)
#define plfapigen_genitfid_aln_CONSTANT  1
#define plfapigen_genitfid_alnid  ((Nat32)1)
#define plfapigen_genitfid_alnid_CONSTANT  1
#define plfapigen_genitfid_amb  ((Nat32)1)
#define plfapigen_genitfid_amb_CONSTANT  1
#define plfapigen_genitfid_ambl  ((Nat32)1)
#define plfapigen_genitfid_ambl_CONSTANT  1
#define plfapigen_genitfid_amblx  ((Nat32)1)
#define plfapigen_genitfid_amblx_CONSTANT  1
#define plfapigen_genitfid_bcont  ((Nat32)1)
#define plfapigen_genitfid_bcont_CONSTANT  1
#define plfapigen_genitfid_bcontx  ((Nat32)1)
#define plfapigen_genitfid_bcontx_CONSTANT  1
#define plfapigen_genitfid_cabattr  ((Nat32)1)
#define plfapigen_genitfid_cabattr_CONSTANT  1
#define plfapigen_genitfid_cr  ((Nat32)1)
#define plfapigen_genitfid_cr_CONSTANT  1
#define plfapigen_genitfid_filesplit  ((Nat32)1)
#define plfapigen_genitfid_filesplit_CONSTANT  1
#define plfapigen_genitfid_hplg  ((Nat32)1)
#define plfapigen_genitfid_hplg_CONSTANT  1
#define plfapigen_genitfid_hwerr  ((Nat32)1)
#define plfapigen_genitfid_hwerr_CONSTANT  1
#define plfapigen_genitfid_hwerrids  ((Nat32)1)
#define plfapigen_genitfid_hwerrids_CONSTANT  1
#define plfapigen_genitfid_pom  ((Nat32)1)
#define plfapigen_genitfid_pom_CONSTANT  1
#define plfapigen_genitfid_sbp  ((Nat32)1)
#define plfapigen_genitfid_sbp_CONSTANT  1
#define plfapigen_genitfid_scrattr  ((Nat32)1)
#define plfapigen_genitfid_scrattr_CONSTANT  1
#define plfapigen_genitfid_serv  ((Nat32)1)
#define plfapigen_genitfid_serv_CONSTANT  1
#define plfapigen_genitfid_spla  ((Nat32)1)
#define plfapigen_genitfid_spla_CONSTANT  1
#define plfapigen_genitfid_tmpctrl  ((Nat32)1)
#define plfapigen_genitfid_tmpctrl_CONSTANT  1
#define plfapigen_genitfid_ver  ((Nat32)1)
#define plfapigen_genitfid_ver_CONSTANT  1
#define plfapigen_genitfid_vgtp  ((Nat32)1)
#define plfapigen_genitfid_vgtp_CONSTANT  1
#define plfapigen_genitfid_vgtpid  ((Nat32)1)
#define plfapigen_genitfid_vgtpid_CONSTANT  1
extern FResult plfapigen_hplg_Toggle( int winid );
extern FResult plfapigen_hwerr_GetFirstError( int winid, int * errid );
extern FResult plfapigen_hwerr_GetLayer1Error( int winid, int errid, int * layer1err );
extern FResult plfapigen_hwerr_GetLayer2Error( int winid, int errid, int * layer2err );
#define plfapigen_hwerrids_AmbiLighError  ((int)34)
#define plfapigen_hwerrids_AmbiLighError_CONSTANT  34
#define plfapigen_hwerrids_ArmError  ((int)33)
#define plfapigen_hwerrids_ArmError_CONSTANT  33
#define plfapigen_hwerrids_AvPipBoard  ((int)8)
#define plfapigen_hwerrids_AvPipBoard_CONSTANT  8
#define plfapigen_hwerrids_AvPipBoardError  ((int)38)
#define plfapigen_hwerrids_AvPipBoardError_CONSTANT  38
#define plfapigen_hwerrids_Board200Hz  ((int)9)
#define plfapigen_hwerrids_Board200Hz_CONSTANT  9
#define plfapigen_hwerrids_BootNVMError  ((int)12)
#define plfapigen_hwerrids_BootNVMError_CONSTANT  12
#define plfapigen_hwerrids_ChannelDecoder2Error  ((int)26)
#define plfapigen_hwerrids_ChannelDecoder2Error_CONSTANT  26
#define plfapigen_hwerrids_ChannelDecoderDvbc  ((int)39)
#define plfapigen_hwerrids_ChannelDecoderDvbc_CONSTANT  39
#define plfapigen_hwerrids_ChannelDecoderDvbs  ((int)41)
#define plfapigen_hwerrids_ChannelDecoderDvbs_CONSTANT  41
#define plfapigen_hwerrids_ChannelDecoderError  ((int)20)
#define plfapigen_hwerrids_ChannelDecoderError_CONSTANT  20
#define plfapigen_hwerrids_ChannelDecoderSTBV  ((int)40)
#define plfapigen_hwerrids_ChannelDecoderSTBV_CONSTANT  40
#define plfapigen_hwerrids_DcdcAlLedDimGroupErr  ((int)8)
#define plfapigen_hwerrids_DcdcAlLedDimGroupErr_CONSTANT  8
#define plfapigen_hwerrids_DCSpeakerError  ((int)2)
#define plfapigen_hwerrids_DCSpeakerError_CONSTANT  2
#define plfapigen_hwerrids_DimmingLEDBacklightError  ((int)32)
#define plfapigen_hwerrids_DimmingLEDBacklightError_CONSTANT  32
#define plfapigen_hwerrids_DisplayError  ((int)31)
#define plfapigen_hwerrids_DisplayError_CONSTANT  31
#define plfapigen_hwerrids_DisplayPortLvds2dp  ((int)29)
#define plfapigen_hwerrids_DisplayPortLvds2dp_CONSTANT  29
#define plfapigen_hwerrids_DisplayPortMonitorNotAlive  ((int)30)
#define plfapigen_hwerrids_DisplayPortMonitorNotAlive_CONSTANT  30
#define plfapigen_hwerrids_DisplaySupplyGroupErr  ((int)3)
#define plfapigen_hwerrids_DisplaySupplyGroupErr_CONSTANT  3
#define plfapigen_hwerrids_DisplayTypeGroupErr  ((int)5)
#define plfapigen_hwerrids_DisplayTypeGroupErr_CONSTANT  5
#define plfapigen_hwerrids_DPTransmitter  ((int)6)
#define plfapigen_hwerrids_DPTransmitter_CONSTANT  6
#define plfapigen_hwerrids_DpTxLvds2dp  ((int)27)
#define plfapigen_hwerrids_DpTxLvds2dp_CONSTANT  27
#define plfapigen_hwerrids_Error12V  ((int)37)
#define plfapigen_hwerrids_Error12V_CONSTANT  37
#define plfapigen_hwerrids_Fan1Error  ((int)24)
#define plfapigen_hwerrids_Fan1Error_CONSTANT  24
#define plfapigen_hwerrids_Fan2Error  ((int)25)
#define plfapigen_hwerrids_Fan2Error_CONSTANT  25
#define plfapigen_hwerrids_FanGroupErr  ((int)7)
#define plfapigen_hwerrids_FanGroupErr_CONSTANT  7
#define plfapigen_hwerrids_FanI2CExpanderError  ((int)22)
#define plfapigen_hwerrids_FanI2CExpanderError_CONSTANT  22
#define plfapigen_hwerrids_FpgaLocalContrastError  ((int)16)
#define plfapigen_hwerrids_FpgaLocalContrastError_CONSTANT  16
#define plfapigen_hwerrids_FpgaLvds2dp  ((int)28)
#define plfapigen_hwerrids_FpgaLvds2dp_CONSTANT  28
#define plfapigen_hwerrids_FrontEndError  ((int)35)
#define plfapigen_hwerrids_FrontEndError_CONSTANT  35
#define plfapigen_hwerrids_HDMIedidError  ((int)17)
#define plfapigen_hwerrids_HDMIedidError_CONSTANT  17
#define plfapigen_hwerrids_HdmiMuxError  ((int)10)
#define plfapigen_hwerrids_HdmiMuxError_CONSTANT  10
#define plfapigen_hwerrids_I2C1BlockedError  ((int)4)
#define plfapigen_hwerrids_I2C1BlockedError_CONSTANT  4
#define plfapigen_hwerrids_I2C2BlockedError  ((int)7)
#define plfapigen_hwerrids_I2C2BlockedError_CONSTANT  7
#define plfapigen_hwerrids_I2C3BlockedError  ((int)5)
#define plfapigen_hwerrids_I2C3BlockedError_CONSTANT  5
#define plfapigen_hwerrids_I2C4BlockedError  ((int)6)
#define plfapigen_hwerrids_I2C4BlockedError_CONSTANT  6
#define plfapigen_hwerrids_I2CSwitchError  ((int)11)
#define plfapigen_hwerrids_I2CSwitchError_CONSTANT  11
#define plfapigen_hwerrids_InverterDisplaySupplyError  ((int)8)
#define plfapigen_hwerrids_InverterDisplaySupplyError_CONSTANT  8
#define plfapigen_hwerrids_LedBlGlueDevice  ((int)36)
#define plfapigen_hwerrids_LedBlGlueDevice_CONSTANT  36
#define plfapigen_hwerrids_LNBController  ((int)42)
#define plfapigen_hwerrids_LNBController_CONSTANT  42
#define plfapigen_hwerrids_LNBCurrentOverload  ((int)43)
#define plfapigen_hwerrids_LNBCurrentOverload_CONSTANT  43
#define plfapigen_hwerrids_MainNVMError  ((int)19)
#define plfapigen_hwerrids_MainNVMError_CONSTANT  19
#define plfapigen_hwerrids_MasterIFError  ((int)13)
#define plfapigen_hwerrids_MasterIFError_CONSTANT  13
#define plfapigen_hwerrids_MicronasIFError  ((int)14)
#define plfapigen_hwerrids_MicronasIFError_CONSTANT  14
#define plfapigen_hwerrids_MOPOutputProcessorError  ((int)15)
#define plfapigen_hwerrids_MOPOutputProcessorError_CONSTANT  15
#define plfapigen_hwerrids_MpcProcessorError  ((int)47)
#define plfapigen_hwerrids_MpcProcessorError_CONSTANT  47
#define plfapigen_hwerrids_PlatformSupplyGroupErr  ((int)4)
#define plfapigen_hwerrids_PlatformSupplyGroupErr_CONSTANT  4
#define plfapigen_hwerrids_PNX5xxxError  ((int)9)
#define plfapigen_hwerrids_PNX5xxxError_CONSTANT  9
#define plfapigen_hwerrids_SsbGroupErr  ((int)2)
#define plfapigen_hwerrids_SsbGroupErr_CONSTANT  2
#define plfapigen_hwerrids_Sti710xError  ((int)21)
#define plfapigen_hwerrids_Sti710xError_CONSTANT  21
#define plfapigen_hwerrids_SystemBootFailError  ((int)1)
#define plfapigen_hwerrids_SystemBootFailError_CONSTANT  1
#define plfapigen_hwerrids_Tcon  ((int)45)
#define plfapigen_hwerrids_Tcon_CONSTANT  45
#define plfapigen_hwerrids_TconEEPROM  ((int)46)
#define plfapigen_hwerrids_TconEEPROM_CONSTANT  46
#define plfapigen_hwerrids_TemperatureError  ((int)3)
#define plfapigen_hwerrids_TemperatureError_CONSTANT  3
#define plfapigen_hwerrids_TempSensorError  ((int)23)
#define plfapigen_hwerrids_TempSensorError_CONSTANT  23
#define plfapigen_hwerrids_Tuner1Error  ((int)18)
#define plfapigen_hwerrids_Tuner1Error_CONSTANT  18
#define plfapigen_hwerrids_TunerDvbs  ((int)44)
#define plfapigen_hwerrids_TunerDvbs_CONSTANT  44
extern FResult plfapigen_pom_GetPowerMeterValue( int winid, int * retval );
extern FResult plfapigen_pom_PowerMeterAllowed( int winid, Bool * retval );
extern FResult plfapigen_pom_PowerMeterSupported( int winid, Bool * retval );
#define plfapigen_pom_MaxPowerMeter  ((int)100)
#define plfapigen_pom_MaxPowerMeter_CONSTANT  100
#define plfapigen_pom_MinPowerMeter  ((int)0)
#define plfapigen_pom_MinPowerMeter_CONSTANT  0
extern FResult plfapigen_sbp_GetBalance( int winid, int * retval );
extern FResult plfapigen_sbp_GetFrequency( int winid, int * retval );
extern FResult plfapigen_sbp_GetMaxFrequency( int winid, int * retval );
extern FResult plfapigen_sbp_GetMaxVolume( int winid, int * retval );
extern FResult plfapigen_sbp_GetMinFrequency( int winid, int * retval );
extern FResult plfapigen_sbp_GetMinVolume( int winid, int * retval );
extern FResult plfapigen_sbp_GetMute( int winid, Bool * retval );
extern FResult plfapigen_sbp_GetVolume( int winid, int * retval );
extern FResult plfapigen_sbp_SetBalance( int winid, int balance );
extern FResult plfapigen_sbp_SetFrequency( int winid, int frequency );
extern FResult plfapigen_sbp_SetMute( int winid, Bool mute );
extern FResult plfapigen_sbp_SetVolume( int winid, int volume );
#define plfapigen_sbp_BalanceLeft  ((int)1)
#define plfapigen_sbp_BalanceLeft_CONSTANT  1
#define plfapigen_sbp_BalanceReset  ((int)0)
#define plfapigen_sbp_BalanceReset_CONSTANT  0
#define plfapigen_sbp_BalanceRight  ((int)2)
#define plfapigen_sbp_BalanceRight_CONSTANT  2
extern FResult plfapigen_scrattr_DisplayString( int winid, int screenid, int len, char * retval );
extern FResult plfapigen_scrattr_DoubleFrameSupported( int winid, Bool * retval );
extern FResult plfapigen_scrattr_GetAspectRatio( int winid, int * retval );
extern FResult plfapigen_scrattr_GetClearLcd( int winid, int * retval );
extern FResult plfapigen_scrattr_GetFrameRate( int winid, int * retval );
extern FResult plfapigen_scrattr_GetFullHdSupported( int winid, Bool * retval );
extern FResult plfapigen_scrattr_GetPnxHorResolution( int winid, int * retval );
extern FResult plfapigen_scrattr_GetPnxVertResolution( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenBitWidth( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenBrand( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenHorResolution( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenIdFallback( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenLvdsMode( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenScanType( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenSize( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenType( int winid, int * retval );
extern FResult plfapigen_scrattr_GetScreenVertResolution( int winid, int * retval );
extern FResult plfapigen_scrattr_IsScreenSupported( int winid, int screenid, Bool * retval );
#define plfapigen_scrattr_ClearLcdBDI  ((int)4)
#define plfapigen_scrattr_ClearLcdBDI_CONSTANT  4
#define plfapigen_scrattr_ClearLcdGFI  ((int)3)
#define plfapigen_scrattr_ClearLcdGFI_CONSTANT  3
#define plfapigen_scrattr_ClearLcdNA  ((int)0)
#define plfapigen_scrattr_ClearLcdNA_CONSTANT  0
#define plfapigen_scrattr_ClearLcdSBL  ((int)1)
#define plfapigen_scrattr_ClearLcdSBL_CONSTANT  1
#define plfapigen_scrattr_ClearLcdSPD  ((int)2)
#define plfapigen_scrattr_ClearLcdSPD_CONSTANT  2
#define plfapigen_scrattr_ScrBitWidth10  ((int)2)
#define plfapigen_scrattr_ScrBitWidth10_CONSTANT  2
#define plfapigen_scrattr_ScrBitWidth8  ((int)1)
#define plfapigen_scrattr_ScrBitWidth8_CONSTANT  1
#define plfapigen_scrattr_ScrBrandAlis  ((int)6)
#define plfapigen_scrattr_ScrBrandAlis_CONSTANT  6
#define plfapigen_scrattr_ScrBrandAuo  ((int)7)
#define plfapigen_scrattr_ScrBrandAuo_CONSTANT  7
#define plfapigen_scrattr_ScrBrandCmo  ((int)14)
#define plfapigen_scrattr_ScrBrandCmo_CONSTANT  14
#define plfapigen_scrattr_ScrBrandFhp  ((int)16)
#define plfapigen_scrattr_ScrBrandFhp_CONSTANT  16
#define plfapigen_scrattr_ScrBrandFujitsu  ((int)12)
#define plfapigen_scrattr_ScrBrandFujitsu_CONSTANT  12
#define plfapigen_scrattr_ScrBrandLcos  ((int)8)
#define plfapigen_scrattr_ScrBrandLcos_CONSTANT  8
#define plfapigen_scrattr_ScrBrandLcosMpc  ((int)9)
#define plfapigen_scrattr_ScrBrandLcosMpc_CONSTANT  9
#define plfapigen_scrattr_ScrBrandLg  ((int)10)
#define plfapigen_scrattr_ScrBrandLg_CONSTANT  10
#define plfapigen_scrattr_ScrBrandLpl  ((int)1)
#define plfapigen_scrattr_ScrBrandLpl_CONSTANT  1
#define plfapigen_scrattr_ScrBrandNA  ((int)0)
#define plfapigen_scrattr_ScrBrandNA_CONSTANT  0
#define plfapigen_scrattr_ScrBrandNec  ((int)5)
#define plfapigen_scrattr_ScrBrandNec_CONSTANT  5
#define plfapigen_scrattr_ScrBrandPanasonic  ((int)11)
#define plfapigen_scrattr_ScrBrandPanasonic_CONSTANT  11
#define plfapigen_scrattr_ScrBrandPhilips  ((int)13)
#define plfapigen_scrattr_ScrBrandPhilips_CONSTANT  13
#define plfapigen_scrattr_ScrBrandPioneer  ((int)4)
#define plfapigen_scrattr_ScrBrandPioneer_CONSTANT  4
#define plfapigen_scrattr_ScrBrandQdi  ((int)15)
#define plfapigen_scrattr_ScrBrandQdi_CONSTANT  15
#define plfapigen_scrattr_ScrBrandSamsung  ((int)3)
#define plfapigen_scrattr_ScrBrandSamsung_CONSTANT  3
#define plfapigen_scrattr_ScrBrandSharp  ((int)2)
#define plfapigen_scrattr_ScrBrandSharp_CONSTANT  2
#define plfapigen_scrattr_ScrFR100Hz  ((int)100)
#define plfapigen_scrattr_ScrFR100Hz_CONSTANT  100
#define plfapigen_scrattr_ScrFR200Hz  ((int)200)
#define plfapigen_scrattr_ScrFR200Hz_CONSTANT  200
#define plfapigen_scrattr_ScrFR50Hz  ((int)50)
#define plfapigen_scrattr_ScrFR50Hz_CONSTANT  50
#define plfapigen_scrattr_ScrLvdsModeJapanese  ((int)1)
#define plfapigen_scrattr_ScrLvdsModeJapanese_CONSTANT  1
#define plfapigen_scrattr_ScrLvdsModeKorean  ((int)2)
#define plfapigen_scrattr_ScrLvdsModeKorean_CONSTANT  2
#define plfapigen_scrattr_ScrLvdsModeVesa  ((int)3)
#define plfapigen_scrattr_ScrLvdsModeVesa_CONSTANT  3
#define plfapigen_scrattr_ScrScnInterlaced  ((int)2)
#define plfapigen_scrattr_ScrScnInterlaced_CONSTANT  2
#define plfapigen_scrattr_ScrScnProgressive  ((int)1)
#define plfapigen_scrattr_ScrScnProgressive_CONSTANT  1
#define plfapigen_scrattr_ScrSize19  ((int)18)
#define plfapigen_scrattr_ScrSize19_CONSTANT  18
#define plfapigen_scrattr_ScrSize20  ((int)1)
#define plfapigen_scrattr_ScrSize20_CONSTANT  1
#define plfapigen_scrattr_ScrSize22  ((int)19)
#define plfapigen_scrattr_ScrSize22_CONSTANT  19
#define plfapigen_scrattr_ScrSize23  ((int)2)
#define plfapigen_scrattr_ScrSize23_CONSTANT  2
#define plfapigen_scrattr_ScrSize26  ((int)3)
#define plfapigen_scrattr_ScrSize26_CONSTANT  3
#define plfapigen_scrattr_ScrSize27  ((int)20)
#define plfapigen_scrattr_ScrSize27_CONSTANT  20
#define plfapigen_scrattr_ScrSize30  ((int)4)
#define plfapigen_scrattr_ScrSize30_CONSTANT  4
#define plfapigen_scrattr_ScrSize32  ((int)5)
#define plfapigen_scrattr_ScrSize32_CONSTANT  5
#define plfapigen_scrattr_ScrSize37  ((int)6)
#define plfapigen_scrattr_ScrSize37_CONSTANT  6
#define plfapigen_scrattr_ScrSize40  ((int)21)
#define plfapigen_scrattr_ScrSize40_CONSTANT  21
#define plfapigen_scrattr_ScrSize42  ((int)7)
#define plfapigen_scrattr_ScrSize42_CONSTANT  7
#define plfapigen_scrattr_ScrSize45  ((int)8)
#define plfapigen_scrattr_ScrSize45_CONSTANT  8
#define plfapigen_scrattr_ScrSize46  ((int)9)
#define plfapigen_scrattr_ScrSize46_CONSTANT  9
#define plfapigen_scrattr_ScrSize47  ((int)10)
#define plfapigen_scrattr_ScrSize47_CONSTANT  10
#define plfapigen_scrattr_ScrSize50  ((int)11)
#define plfapigen_scrattr_ScrSize50_CONSTANT  11
#define plfapigen_scrattr_ScrSize52  ((int)12)
#define plfapigen_scrattr_ScrSize52_CONSTANT  12
#define plfapigen_scrattr_ScrSize55  ((int)13)
#define plfapigen_scrattr_ScrSize55_CONSTANT  13
#define plfapigen_scrattr_ScrSize56  ((int)22)
#define plfapigen_scrattr_ScrSize56_CONSTANT  22
#define plfapigen_scrattr_ScrSize58  ((int)23)
#define plfapigen_scrattr_ScrSize58_CONSTANT  23
#define plfapigen_scrattr_ScrSize61  ((int)14)
#define plfapigen_scrattr_ScrSize61_CONSTANT  14
#define plfapigen_scrattr_ScrSize62  ((int)15)
#define plfapigen_scrattr_ScrSize62_CONSTANT  15
#define plfapigen_scrattr_ScrSize63  ((int)16)
#define plfapigen_scrattr_ScrSize63_CONSTANT  16
#define plfapigen_scrattr_ScrSize66  ((int)17)
#define plfapigen_scrattr_ScrSize66_CONSTANT  17
#define plfapigen_scrattr_ScrSizeNA  ((int)0)
#define plfapigen_scrattr_ScrSizeNA_CONSTANT  0
#define plfapigen_scrattr_ScrTypeGde  ((int)4)
#define plfapigen_scrattr_ScrTypeGde_CONSTANT  4
#define plfapigen_scrattr_ScrTypeLcd  ((int)2)
#define plfapigen_scrattr_ScrTypeLcd_CONSTANT  2
#define plfapigen_scrattr_ScrTypeLCoS  ((int)3)
#define plfapigen_scrattr_ScrTypeLCoS_CONSTANT  3
#define plfapigen_scrattr_ScrTypeNA  ((int)0)
#define plfapigen_scrattr_ScrTypeNA_CONSTANT  0
#define plfapigen_scrattr_ScrTypePlasma  ((int)1)
#define plfapigen_scrattr_ScrTypePlasma_CONSTANT  1
#define plfapigen_scrattr_SrcAR16by9  ((int)1)
#define plfapigen_scrattr_SrcAR16by9_CONSTANT  1
#define plfapigen_scrattr_SrcAR21by9  ((int)2)
#define plfapigen_scrattr_SrcAR21by9_CONSTANT  2
#define plfapigen_scrattr_SrcAR4by3  ((int)0)
#define plfapigen_scrattr_SrcAR4by3_CONSTANT  0
extern FResult plfapigen_serv_AreProtectionsEnabled( int winid, Bool * retval );
extern FResult plfapigen_serv_ClearProtectionState( int winid );
extern FResult plfapigen_serv_EnableProtections( int winid, Bool mode );
extern FResult plfapigen_serv_FunctionalTest( int winid );
extern FResult plfapigen_serv_GetFunctionalTestResult( int winid, Bool * retval );
extern FResult plfapigen_serv_GetI2cRefreshState( int winid, Bool * retval );
extern FResult plfapigen_serv_GetIdleMode( int winid, Bool * retval );
extern FResult plfapigen_serv_GetNumberOfSteps( int winid, int * retval );
extern FResult plfapigen_serv_GetPowerStep( int winid, int * retval );
extern FResult plfapigen_serv_IsI2cTrafficLocked( int winid, Bool * retval );
extern FResult plfapigen_serv_IsStepAllowed( int winid, int step, Bool * retval );
extern FResult plfapigen_serv_IsTransitionActive( int winid, int * retval );
extern FResult plfapigen_serv_LockI2cTraffic( int winid, Bool * retval );
extern FResult plfapigen_serv_SetI2cRefreshState( int winid, Bool mode );
extern FResult plfapigen_serv_SetIdleMode( int winid, Bool mode, Bool * retval );
extern FResult plfapigen_serv_SetPowerStep( int winid, int step, Bool * retval );
extern FResult plfapigen_serv_UnlockI2cTraffic( int winid, Bool * retval );
extern FResult plfapigen_spla_GetSplashScreen( int winid, Bool * retval );
extern FResult plfapigen_spla_IsSplashScreenSupported( int winid, Bool * retval );
extern FResult plfapigen_spla_SetSplashScreen( int winid, Bool enable );
extern FResult plfapigen_tmpctrl_AbortFanBoardSelfTest( int winid );
extern FResult plfapigen_tmpctrl_ExecuteFanBoardSelfTest( int winid );
extern FResult plfapigen_tmpctrl_GetFanBoardSelfTestResult( int winid, int * retval );
extern FResult plfapigen_tmpctrl_GetFanSpeed( int winid, int fanid, int * speed );
extern FResult plfapigen_tmpctrl_GetMaxTemperature( int winid, int * retval );
extern FResult plfapigen_tmpctrl_GetSensorTemperature( int winid, int * retval );
extern FResult plfapigen_tmpctrl_GetTemperatureThreshold( int winid, int threshold, int * value );
extern FResult plfapigen_tmpctrl_IsFanBoardSelfTestSupported( int winid, Bool * retval );
extern FResult plfapigen_tmpctrl_IsFanSpeedSupported( int winid, Bool * retval );
extern FResult plfapigen_tmpctrl_IsMaxTemperatureSupported( int winid, Bool * retval );
extern FResult plfapigen_tmpctrl_IsSensorTemperatureSupported( int winid, Bool * retval );
extern FResult plfapigen_tmpctrl_IsTemperatureThresholdSupported( int winid, Bool * retval );
extern FResult plfapigen_tmpctrl_SetFanSpeedMode( int winid, int mode );
extern FResult plfapigen_tmpctrl_SetManualFanSpeed( int winid, int fanid, int speed );
extern FResult plfapigen_tmpctrl_SetManualTemperatureThreshold( int winid, int threshold, int value );
extern FResult plfapigen_tmpctrl_SetMaxTemperature( int winid, int maxtemp );
extern FResult plfapigen_tmpctrl_SetTemperatureThresholdMode( int winid, int mode );
#define plfapigen_tmpctrl_FanId1  ((int)1)
#define plfapigen_tmpctrl_FanId1_CONSTANT  1
#define plfapigen_tmpctrl_FanId2  ((int)2)
#define plfapigen_tmpctrl_FanId2_CONSTANT  2
#define plfapigen_tmpctrl_FanSpeedModeAuto  ((int)2)
#define plfapigen_tmpctrl_FanSpeedModeAuto_CONSTANT  2
#define plfapigen_tmpctrl_FanSpeedModeManual  ((int)1)
#define plfapigen_tmpctrl_FanSpeedModeManual_CONSTANT  1
#define plfapigen_tmpctrl_HighTemperatureThreshold  ((int)2)
#define plfapigen_tmpctrl_HighTemperatureThreshold_CONSTANT  2
#define plfapigen_tmpctrl_LowTemperatureThreshold  ((int)1)
#define plfapigen_tmpctrl_LowTemperatureThreshold_CONSTANT  1
#define plfapigen_tmpctrl_MaxFanSpeed  ((int)255)
#define plfapigen_tmpctrl_MaxFanSpeed_CONSTANT  255
#define plfapigen_tmpctrl_MinFanSpeed  ((int)0)
#define plfapigen_tmpctrl_MinFanSpeed_CONSTANT  0
#define plfapigen_tmpctrl_SelfTestResultAborted  ((int)3)
#define plfapigen_tmpctrl_SelfTestResultAborted_CONSTANT  3
#define plfapigen_tmpctrl_SelfTestResultFailed  ((int)1)
#define plfapigen_tmpctrl_SelfTestResultFailed_CONSTANT  1
#define plfapigen_tmpctrl_SelfTestResultNone  ((int)4)
#define plfapigen_tmpctrl_SelfTestResultNone_CONSTANT  4
#define plfapigen_tmpctrl_SelfTestResultOngoing  ((int)2)
#define plfapigen_tmpctrl_SelfTestResultOngoing_CONSTANT  2
#define plfapigen_tmpctrl_SelfTestResultSucceeded  ((int)0)
#define plfapigen_tmpctrl_SelfTestResultSucceeded_CONSTANT  0
#define plfapigen_tmpctrl_TemperatureThresholdModeAuto  ((int)2)
#define plfapigen_tmpctrl_TemperatureThresholdModeAuto_CONSTANT  2
#define plfapigen_tmpctrl_TemperatureThresholdModeManual  ((int)1)
#define plfapigen_tmpctrl_TemperatureThresholdModeManual_CONSTANT  1
extern FResult plfapigen_ver_GetDeviceVersion( int winid, int device, int len, char * retval );
extern FResult plfapigen_ver_GetDeviceVersionEx( int winid, int device, Nat8 * buf, int size, int * retval );
extern FResult plfapigen_ver_GetSubsystemVersion( int winid, int len, char * version );
#define plfapigen_ver_AmbilightFile  ((int)10)
#define plfapigen_ver_AmbilightFile_CONSTANT  10
#define plfapigen_ver_Bcm7206  ((int)31)
#define plfapigen_ver_Bcm7206_CONSTANT  31
#define plfapigen_ver_CabinetFile  ((int)11)
#define plfapigen_ver_CabinetFile_CONSTANT  11
#define plfapigen_ver_DisplayFile  ((int)7)
#define plfapigen_ver_DisplayFile_CONSTANT  7
#define plfapigen_ver_Epld  ((int)1)
#define plfapigen_ver_Epld_CONSTANT  1
#define plfapigen_ver_EpldDfi  ((int)12)
#define plfapigen_ver_EpldDfi_CONSTANT  12
#define plfapigen_ver_EpldLedBacklight  ((int)19)
#define plfapigen_ver_EpldLedBacklight_CONSTANT  19
#define plfapigen_ver_EpldLocalContrast  ((int)26)
#define plfapigen_ver_EpldLocalContrast_CONSTANT  26
#define plfapigen_ver_PacificHW  ((int)4)
#define plfapigen_ver_PacificHW_CONSTANT  4
#define plfapigen_ver_PacificRAM  ((int)2)
#define plfapigen_ver_PacificRAM_CONSTANT  2
#define plfapigen_ver_PacificROM  ((int)3)
#define plfapigen_ver_PacificROM_CONSTANT  3
#define plfapigen_ver_Pnx5050HW  ((int)6)
#define plfapigen_ver_Pnx5050HW_CONSTANT  6
#define plfapigen_ver_Pnx5050SW  ((int)5)
#define plfapigen_ver_Pnx5050SW_CONSTANT  5
#define plfapigen_ver_PNX5100BootNvm  ((int)18)
#define plfapigen_ver_PNX5100BootNvm_CONSTANT  18
#define plfapigen_ver_Pnx5100HW  ((int)14)
#define plfapigen_ver_Pnx5100HW_CONSTANT  14
#define plfapigen_ver_Pnx5100SW  ((int)13)
#define plfapigen_ver_Pnx5100SW_CONSTANT  13
#define plfapigen_ver_PqfFile  ((int)27)
#define plfapigen_ver_PqfFile_CONSTANT  27
#define plfapigen_ver_PqPrivateFile  ((int)9)
#define plfapigen_ver_PqPrivateFile_CONSTANT  9
#define plfapigen_ver_PqPublicFile  ((int)8)
#define plfapigen_ver_PqPublicFile_CONSTANT  8
#define plfapigen_ver_PqsFile  ((int)28)
#define plfapigen_ver_PqsFile_CONSTANT  28
#define plfapigen_ver_PquFile  ((int)29)
#define plfapigen_ver_PquFile_CONSTANT  29
#define plfapigen_ver_StandbySoftware  ((int)17)
#define plfapigen_ver_StandbySoftware_CONSTANT  17
#define plfapigen_ver_STi7100HW  ((int)15)
#define plfapigen_ver_STi7100HW_CONSTANT  15
#define plfapigen_ver_STi7100SW  ((int)16)
#define plfapigen_ver_STi7100SW_CONSTANT  16
#define plfapigen_ver_TemperatureFile  ((int)30)
#define plfapigen_ver_TemperatureFile_CONSTANT  30
extern FResult plfapigen_vgtp_GetTestPattern( int winid, int generatorid, int * retval );
extern FResult plfapigen_vgtp_IsTestPatternAllowed( int winid, int generatorid, int patternid, Bool * retval );
extern FResult plfapigen_vgtp_SetTestPattern( int winid, int generatorid, int patternid );
#define plfapigen_vgtpid_valGenAvip  ((int)0)
#define plfapigen_vgtpid_valGenAvip_CONSTANT  0
#define plfapigen_vgtpid_valGenAvipFd  ((int)1)
#define plfapigen_vgtpid_valGenAvipFd_CONSTANT  1
#define plfapigen_vgtpid_valGenBcm7206  ((int)18)
#define plfapigen_vgtpid_valGenBcm7206_CONSTANT  18
#define plfapigen_vgtpid_valGenColumbus  ((int)4)
#define plfapigen_vgtpid_valGenColumbus_CONSTANT  4
#define plfapigen_vgtpid_valGenDpRxMonitor  ((int)15)
#define plfapigen_vgtpid_valGenDpRxMonitor_CONSTANT  15
#define plfapigen_vgtpid_valGenDpTxLvds2dp  ((int)13)
#define plfapigen_vgtpid_valGenDpTxLvds2dp_CONSTANT  13
#define plfapigen_vgtpid_valGenEpldDfi  ((int)9)
#define plfapigen_vgtpid_valGenEpldDfi_CONSTANT  9
#define plfapigen_vgtpid_valGenEpldLedBacklight  ((int)12)
#define plfapigen_vgtpid_valGenEpldLedBacklight_CONSTANT  12
#define plfapigen_vgtpid_valGenEpldLocalContrast  ((int)17)
#define plfapigen_vgtpid_valGenEpldLocalContrast_CONSTANT  17
#define plfapigen_vgtpid_valGenFpgaLvds2dp  ((int)14)
#define plfapigen_vgtpid_valGenFpgaLvds2dp_CONSTANT  14
#define plfapigen_vgtpid_valGenFpgaMonitor  ((int)16)
#define plfapigen_vgtpid_valGenFpgaMonitor_CONSTANT  16
#define plfapigen_vgtpid_valGenHdmi  ((int)7)
#define plfapigen_vgtpid_valGenHdmi_CONSTANT  7
#define plfapigen_vgtpid_valGenHirate  ((int)5)
#define plfapigen_vgtpid_valGenHirate_CONSTANT  5
#define plfapigen_vgtpid_valGenPacific  ((int)6)
#define plfapigen_vgtpid_valGenPacific_CONSTANT  6
#define plfapigen_vgtpid_valGenPnx5050  ((int)8)
#define plfapigen_vgtpid_valGenPnx5050_CONSTANT  8
#define plfapigen_vgtpid_valGenPnx5100  ((int)10)
#define plfapigen_vgtpid_valGenPnx5100_CONSTANT  10
#define plfapigen_vgtpid_valGenSti7100  ((int)11)
#define plfapigen_vgtpid_valGenSti7100_CONSTANT  11
#define plfapigen_vgtpid_valGenViper  ((int)2)
#define plfapigen_vgtpid_valGenViper_CONSTANT  2
#define plfapigen_vgtpid_valGenViperFd  ((int)3)
#define plfapigen_vgtpid_valGenViperFd_CONSTANT  3
#define plfapigen_vgtpid_valTPAvipColorBar  ((int)1)
#define plfapigen_vgtpid_valTPAvipColorBar_CONSTANT  1
#define plfapigen_vgtpid_valTPAvipMonoBar  ((int)2)
#define plfapigen_vgtpid_valTPAvipMonoBar_CONSTANT  2
#define plfapigen_vgtpid_valTPColorBar  ((int)1)
#define plfapigen_vgtpid_valTPColorBar_CONSTANT  1
#define plfapigen_vgtpid_valTPColumbusItu656OutTestPattern  ((int)8)
#define plfapigen_vgtpid_valTPColumbusItu656OutTestPattern_CONSTANT  8
#define plfapigen_vgtpid_valTPColumbusItu656TestPattern  ((int)7)
#define plfapigen_vgtpid_valTPColumbusItu656TestPattern_CONSTANT  7
#define plfapigen_vgtpid_valTPColumbusTestAtInput  ((int)5)
#define plfapigen_vgtpid_valTPColumbusTestAtInput_CONSTANT  5
#define plfapigen_vgtpid_valTPColumbusTestAtOutput  ((int)6)
#define plfapigen_vgtpid_valTPColumbusTestAtOutput_CONSTANT  6
#define plfapigen_vgtpid_valTPDpRxMonitor  ((int)46)
#define plfapigen_vgtpid_valTPDpRxMonitor_CONSTANT  46
#define plfapigen_vgtpid_valTPDpTxLvds2dp  ((int)43)
#define plfapigen_vgtpid_valTPDpTxLvds2dp_CONSTANT  43
#define plfapigen_vgtpid_valTPEpldDfi  ((int)35)
#define plfapigen_vgtpid_valTPEpldDfi_CONSTANT  35
#define plfapigen_vgtpid_valTPEpldLedBacklight  ((int)39)
#define plfapigen_vgtpid_valTPEpldLedBacklight_CONSTANT  39
#define plfapigen_vgtpid_valTPEpldLedBacklightCheckerboard  ((int)49)
#define plfapigen_vgtpid_valTPEpldLedBacklightCheckerboard_CONSTANT  49
#define plfapigen_vgtpid_valTPEpldLedBacklightDimming0  ((int)40)
#define plfapigen_vgtpid_valTPEpldLedBacklightDimming0_CONSTANT  40
#define plfapigen_vgtpid_valTPEpldLedBacklightDimming100  ((int)42)
#define plfapigen_vgtpid_valTPEpldLedBacklightDimming100_CONSTANT  42
#define plfapigen_vgtpid_valTPEpldLedBacklightDimming50  ((int)41)
#define plfapigen_vgtpid_valTPEpldLedBacklightDimming50_CONSTANT  41
#define plfapigen_vgtpid_valTPEpldLedBacklightInvertedCheckerboard  ((int)50)
#define plfapigen_vgtpid_valTPEpldLedBacklightInvertedCheckerboard_CONSTANT  50
#define plfapigen_vgtpid_valTPEpldLocalContrast  ((int)51)
#define plfapigen_vgtpid_valTPEpldLocalContrast_CONSTANT  51
#define plfapigen_vgtpid_valTPFpgaLvds2dpHorizontalBars  ((int)44)
#define plfapigen_vgtpid_valTPFpgaLvds2dpHorizontalBars_CONSTANT  44
#define plfapigen_vgtpid_valTPFpgaLvds2dpVerticalBars  ((int)45)
#define plfapigen_vgtpid_valTPFpgaLvds2dpVerticalBars_CONSTANT  45
#define plfapigen_vgtpid_valTPFpgaMonitorHorizontalBars  ((int)47)
#define plfapigen_vgtpid_valTPFpgaMonitorHorizontalBars_CONSTANT  47
#define plfapigen_vgtpid_valTPFpgaMonitorVerticalBars  ((int)48)
#define plfapigen_vgtpid_valTPFpgaMonitorVerticalBars_CONSTANT  48
#define plfapigen_vgtpid_valTPHdmi1024x1024i60  ((int)24)
#define plfapigen_vgtpid_valTPHdmi1024x1024i60_CONSTANT  24
#define plfapigen_vgtpid_valTPHdmi1024x768p60  ((int)18)
#define plfapigen_vgtpid_valTPHdmi1024x768p60_CONSTANT  18
#define plfapigen_vgtpid_valTPHdmi1280x1152i50  ((int)32)
#define plfapigen_vgtpid_valTPHdmi1280x1152i50_CONSTANT  32
#define plfapigen_vgtpid_valTPHdmi1280x720p60  ((int)30)
#define plfapigen_vgtpid_valTPHdmi1280x720p60_CONSTANT  30
#define plfapigen_vgtpid_valTPHdmi1280x768p60  ((int)26)
#define plfapigen_vgtpid_valTPHdmi1280x768p60_CONSTANT  26
#define plfapigen_vgtpid_valTPHdmi1366x768p60  ((int)25)
#define plfapigen_vgtpid_valTPHdmi1366x768p60_CONSTANT  25
#define plfapigen_vgtpid_valTPHdmi1440x1080i60  ((int)23)
#define plfapigen_vgtpid_valTPHdmi1440x1080i60_CONSTANT  23
#define plfapigen_vgtpid_valTPHdmi1920x1080i50  ((int)31)
#define plfapigen_vgtpid_valTPHdmi1920x1080i50_CONSTANT  31
#define plfapigen_vgtpid_valTPHdmi1920x1080i60  ((int)21)
#define plfapigen_vgtpid_valTPHdmi1920x1080i60_CONSTANT  21
#define plfapigen_vgtpid_valTPHdmi640x480p60  ((int)16)
#define plfapigen_vgtpid_valTPHdmi640x480p60_CONSTANT  16
#define plfapigen_vgtpid_valTPHdmi720x240p60  ((int)27)
#define plfapigen_vgtpid_valTPHdmi720x240p60_CONSTANT  27
#define plfapigen_vgtpid_valTPHdmi720x288p50  ((int)28)
#define plfapigen_vgtpid_valTPHdmi720x288p50_CONSTANT  28
#define plfapigen_vgtpid_valTPHdmi720x480p60  ((int)20)
#define plfapigen_vgtpid_valTPHdmi720x480p60_CONSTANT  20
#define plfapigen_vgtpid_valTPHdmi800x480p60  ((int)29)
#define plfapigen_vgtpid_valTPHdmi800x480p60_CONSTANT  29
#define plfapigen_vgtpid_valTPHdmi800x600p60  ((int)19)
#define plfapigen_vgtpid_valTPHdmi800x600p60_CONSTANT  19
#define plfapigen_vgtpid_valTPHdmi800x600p75  ((int)17)
#define plfapigen_vgtpid_valTPHdmi800x600p75_CONSTANT  17
#define plfapigen_vgtpid_valTPHdmi960x1080i60  ((int)22)
#define plfapigen_vgtpid_valTPHdmi960x1080i60_CONSTANT  22
#define plfapigen_vgtpid_valTPHdmiNtsc  ((int)14)
#define plfapigen_vgtpid_valTPHdmiNtsc_CONSTANT  14
#define plfapigen_vgtpid_valTPHdmiPal  ((int)13)
#define plfapigen_vgtpid_valTPHdmiPal_CONSTANT  13
#define plfapigen_vgtpid_valTPHdmiSecam  ((int)15)
#define plfapigen_vgtpid_valTPHdmiSecam_CONSTANT  15
#define plfapigen_vgtpid_valTPHiRate480iColorBar  ((int)10)
#define plfapigen_vgtpid_valTPHiRate480iColorBar_CONSTANT  10
#define plfapigen_vgtpid_valTPHiRate576iColorBar  ((int)11)
#define plfapigen_vgtpid_valTPHiRate576iColorBar_CONSTANT  11
#define plfapigen_vgtpid_valTPHiRateNoTestPattern  ((int)9)
#define plfapigen_vgtpid_valTPHiRateNoTestPattern_CONSTANT  9
#define plfapigen_vgtpid_valTPNoTestPattern  ((int)0)
#define plfapigen_vgtpid_valTPNoTestPattern_CONSTANT  0
#define plfapigen_vgtpid_valTPPacific  ((int)12)
#define plfapigen_vgtpid_valTPPacific_CONSTANT  12
#define plfapigen_vgtpid_valTPPnx5050ColorBar  ((int)33)
#define plfapigen_vgtpid_valTPPnx5050ColorBar_CONSTANT  33
#define plfapigen_vgtpid_valTPPnx5050White  ((int)34)
#define plfapigen_vgtpid_valTPPnx5050White_CONSTANT  34
#define plfapigen_vgtpid_valTPPnx5100ColorBar  ((int)36)
#define plfapigen_vgtpid_valTPPnx5100ColorBar_CONSTANT  36
#define plfapigen_vgtpid_valTPPnx5100White  ((int)37)
#define plfapigen_vgtpid_valTPPnx5100White_CONSTANT  37
#define plfapigen_vgtpid_valTPSti7100  ((int)38)
#define plfapigen_vgtpid_valTPSti7100_CONSTANT  38
#define plfapigen_vgtpid_valTPViperNtsc  ((int)4)
#define plfapigen_vgtpid_valTPViperNtsc_CONSTANT  4
#define plfapigen_vgtpid_valTPViperPal  ((int)3)
#define plfapigen_vgtpid_valTPViperPal_CONSTANT  3

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapigen_ambN_OnActiveLightModeAllowedChanged( void );
extern void plfapigen_ambN_OnActiveLightModeChanged( void );
extern void plfapigen_ambN_OnBalanceAllowedChanged( void );
extern void plfapigen_ambN_OnBalanceChanged( void );
extern void plfapigen_ambN_OnColorBoostAllowedChanged( void );
extern void plfapigen_ambN_OnColorBoostChanged( void );
extern void plfapigen_ambN_OnCyclingOnValueAllowedChanged( void );
extern void plfapigen_ambN_OnCyclingStopped( void );
extern void plfapigen_ambN_OnHueAllowedChanged( void );
extern void plfapigen_ambN_OnHueChanged( void );
extern void plfapigen_ambN_OnImmersionAllowedChanged( void );
extern void plfapigen_ambN_OnImmersionChanged( void );
extern void plfapigen_ambN_OnLavaLightModeAllowedChanged( void );
extern void plfapigen_ambN_OnLavaLightModeChanged( void );
extern void plfapigen_ambN_OnLightModeTypesAllowedChanged( void );
extern void plfapigen_ambN_OnLightModeTypesChanged( void );
extern void plfapigen_ambN_OnLightStateAllowedChanged( void );
extern void plfapigen_ambN_OnLightStateChanged( void );
extern void plfapigen_ambN_OnMuteAllowedChanged( void );
extern void plfapigen_ambN_OnMuteChanged( void );
extern void plfapigen_ambN_OnPredefinedModeAllowedChanged( void );
extern void plfapigen_ambN_OnPredefinedModeChanged( void );
extern void plfapigen_ambN_OnSaturationAllowedChanged( void );
extern void plfapigen_ambN_OnSaturationChanged( void );
extern void plfapigen_ambN_OnSeparationAllowedChanged( void );
extern void plfapigen_ambN_OnSeparationChanged( void );
extern void plfapigen_ambN_OnStaticLightModeAllowedChanged( void );
extern void plfapigen_ambN_OnStaticLightModeChanged( void );
extern void plfapigen_ambN_OnValueAllowedChanged( void );
extern void plfapigen_ambN_OnValueChanged( void );
extern void plfapigen_crN_OnContrastReductionAllowedChanged( int layer );
extern void plfapigen_crN_OnContrastReductionTimerExpired( int layer );
extern void plfapigen_filesplitN_OnCalculateCrcFinished( void );
extern void plfapigen_filesplitN_OnCopySplitFinished( void );
extern void plfapigen_filesplitN_OnDeleteFinished( void );
extern void plfapigen_genitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids );
extern void plfapigen_hwerrN_OnError( int errid );
extern void plfapigen_servN_OnFunctionalTestCompleted( Bool result );
extern void plfapigen_servN_OnI2cTrafficLocked( void );
extern void plfapigen_servN_OnI2cTrafficUnlocked( void );
extern void plfapigen_servN_OnIdleModeReached( Bool mode );
extern void plfapigen_servN_OnPowerStepReached( int step );
extern void plfapigen_tmpctrlN_OnFanBoardSelfTestCompleted( int result );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapigen_EnableNotification_ambN( void );
extern void plfapigen_DisableNotification_ambN( void );
extern void plfapigen_EnableNotification_crN( void );
extern void plfapigen_DisableNotification_crN( void );
extern void plfapigen_EnableNotification_filesplitN( void );
extern void plfapigen_DisableNotification_filesplitN( void );
extern void plfapigen_EnableNotification_genitfN( void );
extern void plfapigen_DisableNotification_genitfN( void );
extern void plfapigen_EnableNotification_hwerrN( void );
extern void plfapigen_DisableNotification_hwerrN( void );
extern void plfapigen_EnableNotification_servN( void );
extern void plfapigen_DisableNotification_servN( void );
extern void plfapigen_EnableNotification_tmpctrlN( void );
extern void plfapigen_DisableNotification_tmpctrlN( void );
extern void plfapigen_EnableNotification( int notificationId );
extern void plfapigen_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapigen_call_stubs */
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

extern void plfapigen_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapigen_RegisterHook_aln( IpcHookFunction callback );
extern void plfapigen_RegisterHook_alnid( IpcHookFunction callback );
extern void plfapigen_RegisterHook_amb( IpcHookFunction callback );
extern void plfapigen_RegisterHook_ambl( IpcHookFunction callback );
extern void plfapigen_RegisterHook_amblx( IpcHookFunction callback );
extern void plfapigen_RegisterHook_bcont( IpcHookFunction callback );
extern void plfapigen_RegisterHook_bcontx( IpcHookFunction callback );
extern void plfapigen_RegisterHook_cabattr( IpcHookFunction callback );
extern void plfapigen_RegisterHook_cr( IpcHookFunction callback );
extern void plfapigen_RegisterHook_errid( IpcHookFunction callback );
extern void plfapigen_RegisterHook_filesplit( IpcHookFunction callback );
extern void plfapigen_RegisterHook_genitf( IpcHookFunction callback );
extern void plfapigen_RegisterHook_genitfid( IpcHookFunction callback );
extern void plfapigen_RegisterHook_hplg( IpcHookFunction callback );
extern void plfapigen_RegisterHook_hwerr( IpcHookFunction callback );
extern void plfapigen_RegisterHook_hwerrids( IpcHookFunction callback );
extern void plfapigen_RegisterHook_pom( IpcHookFunction callback );
extern void plfapigen_RegisterHook_sbp( IpcHookFunction callback );
extern void plfapigen_RegisterHook_scrattr( IpcHookFunction callback );
extern void plfapigen_RegisterHook_serv( IpcHookFunction callback );
extern void plfapigen_RegisterHook_spla( IpcHookFunction callback );
extern void plfapigen_RegisterHook_tmpctrl( IpcHookFunction callback );
extern void plfapigen_RegisterHook_ver( IpcHookFunction callback );
extern void plfapigen_RegisterHook_vgtp( IpcHookFunction callback );
extern void plfapigen_RegisterHook_vgtpid( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapigen_RegisterHook_ambN( IpcHookFunction callback );
extern void plfapigen_RegisterHook_crN( IpcHookFunction callback );
extern void plfapigen_RegisterHook_filesplitN( IpcHookFunction callback );
extern void plfapigen_RegisterHook_genitfN( IpcHookFunction callback );
extern void plfapigen_RegisterHook_hwerrN( IpcHookFunction callback );
extern void plfapigen_RegisterHook_servN( IpcHookFunction callback );
extern void plfapigen_RegisterHook_tmpctrlN( IpcHookFunction callback );

#endif /* _PLFAPIGEN_H_ */

