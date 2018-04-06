
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


#if !defined(_PLFAPIGEN_INTERNAL_H_)
#define _PLFAPIGEN_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    int retval; //out,  
} alnDefault;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    int retval; //out,  
} alnGet;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    int index; //in,  
    int retval; //out,  
} alnGetIx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    int retval; //out,  
} alnGetMaxIx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    Bool retval; //out,  
} alnIsIxSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    Bool retval; //out,  
} alnIsSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    int retval; //out,  
} alnMax;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    int retval; //out,  
} alnMin;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} alnRecall;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
} alnRecallAlignment;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    int value; //in,  
} alnSet;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
    int index; //in,  
    int value; //in,  
} alnSetIx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} alnStore;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alignment; //in,  
} alnStoreAlignment;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} ambDisablePowerLimitation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} ambEnableFallback;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetActiveLightMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetBalance;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetColorBoost;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetHue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetImmersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetLavaLightMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    int retval; //out,  
} ambGetLightModeHue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    int retval; //out,  
} ambGetLightModeSaturation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetLightModeType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambGetLightState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambGetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetPredefinedMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetSaturation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetSeparation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetStaticLightMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambGetSunset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} ambGetValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsActiveLightModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsActiveLightModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bal; //in,  
    Bool retval; //out,  
} ambIsBalanceAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bal; //in,  
    Bool retval; //out,  
} ambIsBalanceSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int boost; //in,  
    Bool retval; //out,  
} ambIsColorBoostAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int boost; //in,  
    Bool retval; //out,  
} ambIsColorBoostSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambIsCyclingOnValueAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambIsCyclingOnValueOngoing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambIsCyclingOnValueSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambIsFallbackEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int hue; //in,  
    Bool retval; //out,  
} ambIsHueAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int hue; //in,  
    Bool retval; //out,  
} ambIsHueSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int im; //in,  
    Bool retval; //out,  
} ambIsImmersionAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int im; //in,  
    Bool retval; //out,  
} ambIsImmersionSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsLavaLightModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsLavaLightModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsLightModeHueSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsLightModeSaturationSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int modeType; //in,  
    Bool retval; //out,  
} ambIsLightModeTypeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int modeType; //in,  
    Bool retval; //out,  
} ambIsLightModeTypeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
    Bool retval; //out,  
} ambIsLightStateAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
    Bool retval; //out,  
} ambIsLightStateSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
    Bool retval; //out,  
} ambIsMuteAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
    Bool retval; //out,  
} ambIsMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambIsPowerLimitationDisabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsPredefinedModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsPredefinedModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int sat; //in,  
    Bool retval; //out,  
} ambIsSaturationAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int sat; //in,  
    Bool retval; //out,  
} ambIsSaturationSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int sep; //in,  
    Bool retval; //out,  
} ambIsSeparationAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int sep; //in,  
    Bool retval; //out,  
} ambIsSeparationSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsStaticLightModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} ambIsStaticLightModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ambIsSunsetSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int val; //in,  
    Bool retval; //out,  
} ambIsValueAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int val; //in,  
    Bool retval; //out,  
} ambIsValueSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} ambSetActiveLightMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bal; //in,  
} ambSetBalance;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int boost; //in,  
} ambSetColorBoost;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int hue; //in,  
} ambSetHue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int im; //in,  
} ambSetImmersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} ambSetLavaLightMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int modeType; //in,  
} ambSetLightModeType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
    Bool retval; //out,  
} ambSetLightState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
    Bool retval; //out,  
} ambSetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} ambSetPredefinedMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int sat; //in,  
} ambSetSaturation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int sep; //in,  
} ambSetSeparation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} ambSetStaticLightMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} ambSetSunset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int val; //in,  
} ambSetValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} ambStartCyclingOnValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} ambStopCyclingOnValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} amblApplySettings;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblCheckSettingsApplied;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} amblEnableFactoryMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblGetColorBoost;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int left; //out,  
    int right; //out,  
    int top; //out,  
    int bottom; //out,  
} amblGetContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblGetImmersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zone; //out,  
} amblGetLampTestZone;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int r1; //out,  
    int g1; //out,  
    int b1; //out,  
    int r2; //out,  
    int g2; //out,  
    int b2; //out,  
    int lavaAlgo; //out,  
} amblGetLavaRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int board; //out,  
    int Rr; //out,  
    int Rg; //out,  
    int Rb; //out,  
    int Gr; //out,  
    int Gg; //out,  
    int Gb; //out,  
    int Br; //out,  
    int Bg; //out,  
    int Bb; //out,  
    int Rfactor; //out,  
    int Gfactor; //out,  
    int Bfactor; //out,  
} amblGetMatrixBoard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblGetMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} amblGetRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblGetSeparation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} amblGetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} amblGetStaticRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 size; //out,  
    Nat8 Red[24]; //out, data ( sizeof( Nat8 ) * 24 ), 
    Nat8 Green[24]; //out, data ( sizeof( Nat8 ) * 24 ), 
    Nat8 Blue[24]; //out, data ( sizeof( Nat8 ) * 24 ), 
} amblGetWallColors;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int boost; //in,  
    Bool retval; //out,  
} amblIsColorBoostSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int left; //in,  
    int right; //in,  
    int top; //in,  
    int bottom; //in,  
    Bool retval; //out,  
} amblIsContrastSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int immersion; //in,  
    Bool retval; //out,  
} amblIsImmersionSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zone; //in,  
    Bool retval; //out,  
} amblIsLampTestZoneSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int r1; //in,  
    int g1; //in,  
    int b1; //in,  
    int r2; //in,  
    int g2; //in,  
    int b2; //in,  
    int lavaAlgo; //in,  
    Bool retval; //out,  
} amblIsLavaRGBSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} amblIsModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int level; //in,  
    Bool retval; //out,  
} amblIsSeparationSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
    Bool retval; //out,  
} amblIsStateSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
    Bool retval; //out,  
} amblIsStaticRGBSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 index; //in,  
} amblSelectWallColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int level; //in,  
} amblSetColorBoost;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int left; //in,  
    int right; //in,  
    int top; //in,  
    int bottom; //in,  
} amblSetContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int r; //in,  
    int g; //in,  
    int b; //in,  
} amblSetCurrent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int immersion; //in,  
} amblSetImmersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zone; //in,  
} amblSetLampTestZone;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int r1; //in,  
    int g1; //in,  
    int b1; //in,  
    int r2; //in,  
    int g2; //in,  
    int b2; //in,  
    int lavaAlgo; //in,  
} amblSetLavaRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pixel; //in,  
    int Rr; //in,  
    int Rg; //in,  
    int Rb; //in,  
    int Gr; //in,  
    int Gg; //in,  
    int Gb; //in,  
    int Br; //in,  
    int Bg; //in,  
    int Bb; //in,  
    int Rfactor; //in,  
    int Gfactor; //in,  
    int Bfactor; //in,  
} amblSetMatrix;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int board; //in,  
    int Rr; //in,  
    int Rg; //in,  
    int Rb; //in,  
    int Gr; //in,  
    int Gg; //in,  
    int Gb; //in,  
    int Br; //in,  
    int Bg; //in,  
    int Bb; //in,  
    int Rfactor; //in,  
    int Gfactor; //in,  
    int Bfactor; //in,  
} amblSetMatrixBoard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} amblSetMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pixel; //in,  
    int r; //in,  
    int g; //in,  
    int b; //in,  
} amblSetPixel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
} amblSetRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int level; //in,  
} amblSetSeparation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} amblSetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
} amblSetStaticRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} amblxApplySettings;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblxCheckSettingsApplied;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} amblxEnableFactoryMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int board; //in,  
    int Rfactor; //out,  
    int Gfactor; //out,  
    int Bfactor; //out,  
} amblxGetBrightnessBoard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblxGetColorBoost;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int left; //out,  
    int right; //out,  
    int top; //out,  
    int bottom; //out,  
} amblxGetContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int board; //in,  
    int correction; //out,  
} amblxGetCorrectionBoard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblxGetImmersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zone; //out,  
} amblxGetLampTestZone;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int r1; //out,  
    int g1; //out,  
    int b1; //out,  
    int r2; //out,  
    int g2; //out,  
    int b2; //out,  
    int lavaAlgo; //out,  
} amblxGetLavaRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int board; //in,  
    int Rr; //out,  
    int Rg; //out,  
    int Rb; //out,  
    int Gr; //out,  
    int Gg; //out,  
    int Gb; //out,  
    int Br; //out,  
    int Bg; //out,  
    int Bb; //out,  
} amblxGetMatrixBoard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblxGetMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} amblxGetRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} amblxGetSeparation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} amblxGetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} amblxGetStaticRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 size; //out,  
    Nat8 Red[24]; //out, data ( sizeof( Nat8 ) * 24 ), 
    Nat8 Green[24]; //out, data ( sizeof( Nat8 ) * 24 ), 
    Nat8 Blue[24]; //out, data ( sizeof( Nat8 ) * 24 ), 
} amblxGetWallColors;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int boost; //in,  
    Bool retval; //out,  
} amblxIsColorBoostSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int left; //in,  
    int right; //in,  
    int top; //in,  
    int bottom; //in,  
    Bool retval; //out,  
} amblxIsContrastSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int immersion; //in,  
    Bool retval; //out,  
} amblxIsImmersionSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zone; //in,  
    Bool retval; //out,  
} amblxIsLampTestZoneSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int r1; //in,  
    int g1; //in,  
    int b1; //in,  
    int r2; //in,  
    int g2; //in,  
    int b2; //in,  
    int lavaAlgo; //in,  
    Bool retval; //out,  
} amblxIsLavaRGBSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} amblxIsModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int level; //in,  
    Bool retval; //out,  
} amblxIsSeparationSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
    Bool retval; //out,  
} amblxIsStateSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
    Bool retval; //out,  
} amblxIsStaticRGBSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 index; //in,  
} amblxSelectWallColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int board; //in,  
    int Rfactor; //in,  
    int Gfactor; //in,  
    int Bfactor; //in,  
} amblxSetBrightnessBoard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int level; //in,  
} amblxSetColorBoost;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int left; //in,  
    int right; //in,  
    int top; //in,  
    int bottom; //in,  
} amblxSetContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int board; //in,  
    int correction; //in,  
} amblxSetCorrectionBoard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int r; //in,  
    int g; //in,  
    int b; //in,  
} amblxSetCurrent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int immersion; //in,  
} amblxSetImmersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zone; //in,  
} amblxSetLampTestZone;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int r1; //in,  
    int g1; //in,  
    int b1; //in,  
    int r2; //in,  
    int g2; //in,  
    int b2; //in,  
    int lavaAlgo; //in,  
} amblxSetLavaRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pixel; //in,  
    int Rr; //in,  
    int Rg; //in,  
    int Rb; //in,  
    int Gr; //in,  
    int Gg; //in,  
    int Gb; //in,  
    int Br; //in,  
    int Bg; //in,  
    int Bb; //in,  
    int Rfactor; //in,  
    int Gfactor; //in,  
    int Bfactor; //in,  
} amblxSetMatrix;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int board; //in,  
    int Rr; //in,  
    int Rg; //in,  
    int Rb; //in,  
    int Gr; //in,  
    int Gg; //in,  
    int Gb; //in,  
    int Br; //in,  
    int Bg; //in,  
    int Bb; //in,  
} amblxSetMatrixBoard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} amblxSetMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pixel; //in,  
    int r; //in,  
    int g; //in,  
    int b; //in,  
} amblxSetPixel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
} amblxSetRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int level; //in,  
} amblxSetSeparation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} amblxSetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
} amblxSetStaticRGB;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} bcontDisableFactoryMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} bcontEnableFactoryMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} bcontxDisableFactoryMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} bcontxEnableFactoryMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} bcontxGetTCONAlignment;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} bcontxResetTCONAlignment;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int value; //in,  
} bcontxSetTCONAlignment;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int cabinetid; //in,  
    int length; //in,  
    char * retval; //out, data ( sizeof( char ) * length ), dynamic ( sizeof( char ) * length ), 
} cabattrDisplayString;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} cabattrGetCabinetIdFallback;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} cabattrGetCabinetProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} cabattrGetNrOfCabinets;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int cabinetid; //in,  
    Bool retval; //out,  
} cabattrIsCabinetSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int profileId; //in,  
} cabattrSetCabinetProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    Bool retval; //out,  
} crContrastReductionAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    Bool retval; //out,  
} crContrastReductionSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    Bool retval; //out,  
} crGetActualContrastReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    Bool retval; //out,  
} crGetContrastReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
} crResetContrastReductionTimer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    Bool enable; //in,  
} crSetContrastReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 calcCrc; //out,  
    int retVal; //out,  
} filesplitGetCalculateCrcState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} filesplitGetCopySplitState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} filesplitGetDeleteState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * path; //in, string,  dynamic ( ( path == NULL ? 0 : strlen( path ) ) + 1 ), 
    int retVal; //out,  
} filesplitStartCalculateCrc;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int chunkSize; //in,  
    char * srcPath; //in, string,  dynamic ( ( srcPath == NULL ? 0 : strlen( srcPath ) ) + 1 ), 
    char * destPath; //in, string,  dynamic ( ( destPath == NULL ? 0 : strlen( destPath ) ) + 1 ), 
    Bool simplyCopy; //in,  
    int retVal; //out,  
} filesplitStartCopySplit;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * path; //in, string,  dynamic ( ( path == NULL ? 0 : strlen( path ) ) + 1 ), 
    int retVal; //out,  
} filesplitStartDelete;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} filesplitStopCalculateCrc;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} filesplitStopCopySplit;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} filesplitStopDelete;

typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} genitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} hplgToggle;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int errid; //out,  
} hwerrGetFirstError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int errid; //in,  
    int layer1err; //out,  
} hwerrGetLayer1Error;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int errid; //in,  
    int layer2err; //out,  
} hwerrGetLayer2Error;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pomGetPowerMeterValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} pomPowerMeterAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} pomPowerMeterSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sbpGetBalance;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sbpGetFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sbpGetMaxFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sbpGetMaxVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sbpGetMinFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sbpGetMinVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} sbpGetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sbpGetVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int balance; //in,  
} sbpSetBalance;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int frequency; //in,  
} sbpSetFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mute; //in,  
} sbpSetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int volume; //in,  
} sbpSetVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int screenid; //in,  
    int len; //in,  
    char * retval; //out, data ( sizeof( char ) * len ), dynamic ( sizeof( char ) * len ), 
} scrattrDisplayString;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} scrattrDoubleFrameSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetAspectRatio;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetClearLcd;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetFrameRate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} scrattrGetFullHdSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetPnxHorResolution;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetPnxVertResolution;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenBitWidth;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenBrand;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenHorResolution;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenIdFallback;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenLvdsMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenScanType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} scrattrGetScreenVertResolution;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int screenid; //in,  
    Bool retval; //out,  
} scrattrIsScreenSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} servAreProtectionsEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} servClearProtectionState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
} servEnableProtections;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} servFunctionalTest;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} servGetFunctionalTestResult;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} servGetI2cRefreshState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} servGetIdleMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} servGetNumberOfSteps;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} servGetPowerStep;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} servIsI2cTrafficLocked;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int step; //in,  
    Bool retval; //out,  
} servIsStepAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} servIsTransitionActive;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} servLockI2cTraffic;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
} servSetI2cRefreshState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
    Bool retval; //out,  
} servSetIdleMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int step; //in,  
    Bool retval; //out,  
} servSetPowerStep;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} servUnlockI2cTraffic;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} splaGetSplashScreen;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} splaIsSplashScreenSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} splaSetSplashScreen;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} tmpctrlAbortFanBoardSelfTest;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} tmpctrlExecuteFanBoardSelfTest;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} tmpctrlGetFanBoardSelfTestResult;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int fanid; //in,  
    int speed; //out,  
} tmpctrlGetFanSpeed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} tmpctrlGetMaxTemperature;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} tmpctrlGetSensorTemperature;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int threshold; //in,  
    int value; //out,  
} tmpctrlGetTemperatureThreshold;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} tmpctrlIsFanBoardSelfTestSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} tmpctrlIsFanSpeedSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} tmpctrlIsMaxTemperatureSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} tmpctrlIsSensorTemperatureSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} tmpctrlIsTemperatureThresholdSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} tmpctrlSetFanSpeedMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int fanid; //in,  
    int speed; //in,  
} tmpctrlSetManualFanSpeed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int threshold; //in,  
    int value; //in,  
} tmpctrlSetManualTemperatureThreshold;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int maxtemp; //in,  
} tmpctrlSetMaxTemperature;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} tmpctrlSetTemperatureThresholdMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int device; //in,  
    int len; //in,  
    char * retval; //out, data ( sizeof( char ) * len ), dynamic ( sizeof( char ) * len ), 
} verGetDeviceVersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int device; //in,  
    Nat8 * buf; //out, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    int size; //in,  
    int retval; //out,  
} verGetDeviceVersionEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int len; //in,  
    char * version; //out, data ( sizeof( char ) * len ), dynamic ( sizeof( char ) * len ), 
} verGetSubsystemVersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int generatorid; //in,  
    int retval; //out,  
} vgtpGetTestPattern;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int generatorid; //in,  
    int patternid; //in,  
    Bool retval; //out,  
} vgtpIsTestPatternAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int generatorid; //in,  
    int patternid; //in,  
} vgtpSetTestPattern;

/* argument structures for notifications (requires) */
typedef struct {
    int layer; //in,  
} crNOnContrastReductionAllowedChanged;

typedef struct {
    int layer; //in,  
} crNOnContrastReductionTimerExpired;

typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} genitfNOnAvailabilityChanged;

typedef struct {
    int errid; //in,  
} hwerrNOnError;

typedef struct {
    Bool result; //in,  
} servNOnFunctionalTestCompleted;

typedef struct {
    Bool mode; //in,  
} servNOnIdleModeReached;

typedef struct {
    int step; //in,  
} servNOnPowerStepReached;

typedef struct {
    int result; //in,  
} tmpctrlNOnFanBoardSelfTestCompleted;

#endif /* _PLFAPIGEN_INTERNAL_H_ */

