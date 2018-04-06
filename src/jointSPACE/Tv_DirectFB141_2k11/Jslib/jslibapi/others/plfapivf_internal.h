
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


#if !defined(_PLFAPIVF_INTERNAL_H_)
#define _PLFAPIVF_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} cprcGetCopyRight;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int copyright; //in,  
    Bool retval; //out,  
} cprcIsCopyRightSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int copyright; //in,  
} cprcSetCopyRight;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} demoDemoModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} demoDemoModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} demoGetDemoMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    int retval; //out,  
} demoSetDemoMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    PlfApiSmartActivity act; //in,  
    int retval; //out,  
} pprGetDefaultProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pprGetPictureProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    int item; //in,  
    int retval; //out,  
} pprGetProfileItem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pictureprofile; //in,  
    Bool retval; //out,  
} pprIsPictureProfileSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pictureprofile; //in,  
} pprSetPictureProfile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} pstAutoTvSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualAmbientLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualBrightnessLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualColorLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualContrastLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualHistogramLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualMotionLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualNoiseLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualSharpnessLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetActualTintLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetAutoTv;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} pstGetPictureStyle;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int param; //in,  
    Bool retval; //out,  
} pstIsControlledParameter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int picturestyle; //in,  
    Bool retval; //out,  
} pstPictureStyleSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} pstSetAutoTv;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int picturestyle; //in,  
} pstSetPictureStyle;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} sltDisable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} sltEnable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sltGetMaxSharpness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sltGetMinSharpness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Address pBuffer; //in,  
    Nat32 hsize; //in,  
    Nat32 vsize; //in,  
    Nat32 stride; //in,  
    Nat32 upleftx; //in,  
    Nat32 uplefty; //in,  
    Nat32 lowrightx; //in,  
    Nat32 lowrighty; //in,  
    Nat32 pixfmttype; //in,  
    Nat32 pixfmtclass; //in,  
    int bright; //in,  
    int contr; //in,  
    int sat; //in,  
    int sharp; //in,  
    Bool lightsensor; //in,  
    Bool retval; //out,  
} sltIsProcessImageAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Address pBuffer; //in,  
    Nat32 hsize; //in,  
    Nat32 vsize; //in,  
    Nat32 stride; //in,  
    Nat32 upleftx; //in,  
    Nat32 uplefty; //in,  
    Nat32 lowrightx; //in,  
    Nat32 lowrighty; //in,  
    Nat32 pixfmttype; //in,  
    Nat32 pixfmtclass; //in,  
    int bright; //in,  
    int contr; //in,  
    int sat; //in,  
    int sharp; //in,  
    Bool lightsensor; //in,  
    Bool retval; //out,  
} sltIsProcessImageSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Address pBuffer; //in,  
    Nat32 hsize; //in,  
    Nat32 vsize; //in,  
    Nat32 stride; //in,  
    Nat32 upleftx; //in,  
    Nat32 uplefty; //in,  
    Nat32 lowrightx; //in,  
    Nat32 lowrighty; //in,  
    Nat32 pixfmttype; //in,  
    Nat32 pixfmtclass; //in,  
    int bright; //in,  
    int contr; //in,  
    int sat; //in,  
    int sharp; //in,  
    Bool lightsensor; //in,  
    Bool retval; //out,  
} sltProcessImage;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} threeDfGet3DFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int format; //in,  
    Bool retval; //out,  
} threeDfIsAllowed3DFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int format; //in,  
    Bool retval; //out,  
} threeDfIsSupported3DFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int format; //in,  
} threeDfSet3DFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} threeDvGet3DViewing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewing; //in,  
    Bool retval; //out,  
} threeDvIsAllowed3DViewing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewing; //in,  
    Bool retval; //out,  
} threeDvIsSupported3DViewing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewing; //in,  
} threeDvSet3DViewing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vdelayGetDelay;

typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} vfitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2ColorEnhancementSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2DnrSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2DynamicContrastSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} vim2EnableClearLcdFallback;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2GammaSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2GetClearLcd;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetColorEnhancement;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetDigitalNaturalMotion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetDnr;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetDynamicBacklight;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetDynamicContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetGamma;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2GetLightSensor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2GetLti;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMaxDigitalNaturalMotion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMaxDnr;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMaxDynamicContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMaxGamma;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMaxMpegNoiseReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMaxSharpness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMedDigitalNaturalMotion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMedDnr;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMedDynamicContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMedGamma;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMedMpegNoiseReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMedSharpness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMinDigitalNaturalMotion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMinDnr;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMinDynamicContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMinGamma;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMinMpegNoiseReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMinSharpness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetMpegNoiseReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetOffDigitalNaturalMotion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetOffDnr;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetOffDynamicContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetOffMpegNoiseReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2GetPCProcessing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vim2GetSharpness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2IsClearLcdAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2IsClearLcdFallbackEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2IsClearLcdSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2IsDigitalNaturalMotionAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2IsDigitalNaturalMotionSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2IsDynamicBacklightAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2IsDynamicBacklightSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2IsPCProcessingAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2IsPCProcessingSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2LightSensorAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2LightSensorSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vim2LtiSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2MpegNoiseReductionSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} vim2SetClearLcd;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vim2SetColorEnhancement;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vim2SetDigitalNaturalMotion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vim2SetDnr;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vim2SetDynamicBacklight;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vim2SetDynamicContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vim2SetGamma;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} vim2SetLightSensor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} vim2SetLti;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vim2SetMpegNoiseReduction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} vim2SetPCProcessing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vim2SetSharpness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vim2SharpnessSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vio2GetBrightness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vio2GetColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vio2GetContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vio2GetFieldFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vio2GetHue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vio2GetTilt;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vio2GetTint;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vio2HueAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vio2HueSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vio2InterlaceControllable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vio2IsInterlaced;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vio2NumberOfLines;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int brightness; //in,  
} vio2SetBrightness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int color; //in,  
} vio2SetColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int contrast; //in,  
} vio2SetContrast;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int hue; //in,  
} vio2SetHue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool interlaced; //in,  
} vio2SetInterlaced;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int tilt; //in,  
} vio2SetTilt;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int tint; //in,  
} vio2SetTint;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vio2TiltSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int tint; //in,  
    Bool retval; //out,  
} vio2TintSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int ulx; //out,  
    int uly; //out,  
    int lrx; //out,  
    int lry; //out,  
    int width; //out,  
    int height; //out,  
} vpGetCurrentViewPort;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vpIsViewPortAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vpIsViewPortSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool onoff; //in,  
} vwm2EnableSubtitleShift;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int x; //out,  
    int y; //out,  
} vwm2GetAbsoluteShift;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 retval; //out,  
} vwm2GetAntiAgeing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetAutoDetect;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetAutoFormatMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int setting; //in,  
    int res; //in,  
    PlfApiSmartActivity act; //in,  
    int retval; //out,  
} vwm2GetDefaultSetting;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewmode; //in,  
    int dx; //out,  
    int dy; //out,  
} vwm2GetDefaultShift;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetImageFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetMaxZoomX;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetMaxZoomY;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetMinZoomX;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetMinZoomY;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetOverscan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int dx; //out,  
    int dy; //out,  
} vwm2GetShift;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetViewMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2GetWindowFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zoomx; //out,  
    int zoomy; //out,  
} vwm2GetZoom;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int x; //in,  
    int y; //in,  
    Bool retval; //out,  
} vwm2IsAbsoluteShiftAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int x; //in,  
    int y; //in,  
    Bool retval; //out,  
} vwm2IsAbsoluteShiftSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewmode; //in,  
    Bool retval; //out,  
} vwm2IsAllowedViewMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewmode; //in,  
    int dx; //in,  
    int dy; //in,  
    Bool retval; //out,  
} vwm2IsAllowedViewModeEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 mode; //in,  
    Bool retval; //out,  
} vwm2IsAntiAgeingSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vwm2IsAutoFormatModeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    Bool retval; //out,  
} vwm2IsAutoFormatModeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int overscan; //in,  
    Bool retval; //out,  
} vwm2IsOverscanAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int overscan; //in,  
    Bool retval; //out,  
} vwm2IsOverscanSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int dx; //in,  
    int dy; //in,  
    Bool retval; //out,  
} vwm2IsShiftAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int dx; //in,  
    int dy; //in,  
    Bool retval; //out,  
} vwm2IsShiftSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vwm2IsSubtitleShiftEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewmode; //in,  
    Bool retval; //out,  
} vwm2IsSupportedViewMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewmode; //in,  
    int dx; //in,  
    int dy; //in,  
    Bool retval; //out,  
} vwm2IsSupportedViewModeEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zoomx; //in,  
    int zoomy; //in,  
    Bool retval; //out,  
} vwm2IsZoomSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int x; //in,  
    int y; //in,  
} vwm2SetAbsoluteShift;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 mode; //in,  
} vwm2SetAntiAgeing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} vwm2SetAutoFormatMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewmode; //in,  
    int dx; //in,  
    int dy; //in,  
} vwm2SetDefaultShift;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int overscan; //in,  
} vwm2SetOverscan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int dx; //in,  
    int dy; //in,  
} vwm2SetShift;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int time; //in,  
} vwm2SetSmoothChange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewmode; //in,  
} vwm2SetViewMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int viewmode; //in,  
    int dx; //in,  
    int dy; //in,  
} vwm2SetViewModeEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int zoomx; //in,  
    int zoomy; //in,  
    int dx; //in,  
    int dy; //in,  
} vwm2SetZoom;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    int retval; //out,  
} vwm2UseAutoDetect;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2UseAutoDetectAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    int dx; //in,  
    int dy; //in,  
    int retval; //out,  
} vwm2UseAutoDetectEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int dx; //in,  
    int dy; //in,  
    int retval; //out,  
} vwm2UseAutoDetectExAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int dx; //in,  
    int dy; //in,  
    int retval; //out,  
} vwm2UseAutoDetectExSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vwm2UseAutoDetectSupported;

/* argument structures for notifications (requires) */
typedef struct {
    int mode; //in,  
} pstNOnAutoTvChanged;

typedef struct {
    int picturestyle; //in,  
} pstNOnPictureStyleChanged;

typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} vfitfNOnAvailabilityChanged;

typedef struct {
    Bool onoff; //in,  
} vim3NOnClearLcdChanged;

typedef struct {
    int mode; //in,  
} vim3NOnColorEnhancementChanged;

typedef struct {
    int mode; //in,  
} vim3NOnDigitalNaturalMotionChanged;

typedef struct {
    int mode; //in,  
} vim3NOnDnrChanged;

typedef struct {
    int mode; //in,  
} vim3NOnDynamicBacklightChanged;

typedef struct {
    int mode; //in,  
} vim3NOnDynamicContrastChanged;

typedef struct {
    int mode; //in,  
} vim3NOnGammaChanged;

typedef struct {
    Bool onoff; //in,  
} vim3NOnLightSensorChanged;

typedef struct {
    Bool onoff; //in,  
} vim3NOnLtiChanged;

typedef struct {
    int mode; //in,  
} vim3NOnMpegNoiseReductionChanged;

typedef struct {
    Bool onoff; //in,  
} vim3NOnPcProcessingChanged;

typedef struct {
    int mode; //in,  
} vim3NOnSharpnessChanged;

typedef struct {
    int ulx; //in,  
    int uly; //in,  
    int lrx; //in,  
    int lry; //in,  
    int width; //in,  
    int height; //in,  
} vpNOnViewPortChanged;

#endif /* _PLFAPIVF_INTERNAL_H_ */

