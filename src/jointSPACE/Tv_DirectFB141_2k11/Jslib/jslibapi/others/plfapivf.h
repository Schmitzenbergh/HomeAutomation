
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


#if !defined(_PLFAPIVF_H_)
#define _PLFAPIVF_H_

#if !defined(_PLFAPIVF_DD_)
#include "plfapivf_types.h"
#endif

extern int  plfapivf_Init( int arg, char * argv[] );
extern void plfapivf_Exit( void );

/*  Symbols for plfapivfMethodID */
extern int idcprcGetCopyRight;  /* 0 */
extern int idcprcIsCopyRightSupported;  /* 1 */
extern int idcprcSetCopyRight;  /* 2 */
extern int iddemoDemoModeAllowed;  /* 3 */
extern int iddemoDemoModeSupported;  /* 4 */
extern int iddemoGetDemoMode;  /* 5 */
extern int iddemoSetDemoMode;  /* 6 */
extern int idpprGetDefaultProfile;  /* 7 */
extern int idpprGetPictureProfile;  /* 8 */
extern int idpprGetProfileItem;  /* 9 */
extern int idpprIsPictureProfileSupported;  /* 10 */
extern int idpprSetPictureProfile;  /* 11 */
extern int idpstAutoTvSupported;  /* 12 */
extern int idpstGetActualAmbientLevel;  /* 13 */
extern int idpstGetActualBrightnessLevel;  /* 14 */
extern int idpstGetActualColorLevel;  /* 15 */
extern int idpstGetActualContrastLevel;  /* 16 */
extern int idpstGetActualHistogramLevel;  /* 17 */
extern int idpstGetActualMotionLevel;  /* 18 */
extern int idpstGetActualNoiseLevel;  /* 19 */
extern int idpstGetActualSharpnessLevel;  /* 20 */
extern int idpstGetActualTintLevel;  /* 21 */
extern int idpstGetAutoTv;  /* 22 */
extern int idpstGetPictureStyle;  /* 23 */
extern int idpstIsControlledParameter;  /* 24 */
extern int idpstPictureStyleSupported;  /* 25 */
extern int idpstSetAutoTv;  /* 26 */
extern int idpstSetPictureStyle;  /* 27 */
extern int idsltDisable;  /* 28 */
extern int idsltEnable;  /* 29 */
extern int idsltGetMaxSharpness;  /* 30 */
extern int idsltGetMinSharpness;  /* 31 */
extern int idsltIsProcessImageAllowed;  /* 32 */
extern int idsltIsProcessImageSupported;  /* 33 */
extern int idsltProcessImage;  /* 34 */
extern int idthreeDfGet3DFormat;  /* 35 */
extern int idthreeDfIsAllowed3DFormat;  /* 36 */
extern int idthreeDfIsSupported3DFormat;  /* 37 */
extern int idthreeDfSet3DFormat;  /* 38 */
extern int idthreeDvGet3DViewing;  /* 39 */
extern int idthreeDvIsAllowed3DViewing;  /* 40 */
extern int idthreeDvIsSupported3DViewing;  /* 41 */
extern int idthreeDvSet3DViewing;  /* 42 */
extern int idvdelayGetDelay;  /* 43 */
extern int idvfitfGetAvailableInterfaces;  /* 44 */
extern int idvim2ColorEnhancementSupported;  /* 45 */
extern int idvim2DnrSupported;  /* 46 */
extern int idvim2DynamicContrastSupported;  /* 47 */
extern int idvim2EnableClearLcdFallback;  /* 48 */
extern int idvim2GammaSupported;  /* 49 */
extern int idvim2GetClearLcd;  /* 50 */
extern int idvim2GetColorEnhancement;  /* 51 */
extern int idvim2GetDigitalNaturalMotion;  /* 52 */
extern int idvim2GetDnr;  /* 53 */
extern int idvim2GetDynamicBacklight;  /* 54 */
extern int idvim2GetDynamicContrast;  /* 55 */
extern int idvim2GetGamma;  /* 56 */
extern int idvim2GetLightSensor;  /* 57 */
extern int idvim2GetLti;  /* 58 */
extern int idvim2GetMaxDigitalNaturalMotion;  /* 59 */
extern int idvim2GetMaxDnr;  /* 60 */
extern int idvim2GetMaxDynamicContrast;  /* 61 */
extern int idvim2GetMaxGamma;  /* 62 */
extern int idvim2GetMaxMpegNoiseReduction;  /* 63 */
extern int idvim2GetMaxSharpness;  /* 64 */
extern int idvim2GetMedDigitalNaturalMotion;  /* 65 */
extern int idvim2GetMedDnr;  /* 66 */
extern int idvim2GetMedDynamicContrast;  /* 67 */
extern int idvim2GetMedGamma;  /* 68 */
extern int idvim2GetMedMpegNoiseReduction;  /* 69 */
extern int idvim2GetMedSharpness;  /* 70 */
extern int idvim2GetMinDigitalNaturalMotion;  /* 71 */
extern int idvim2GetMinDnr;  /* 72 */
extern int idvim2GetMinDynamicContrast;  /* 73 */
extern int idvim2GetMinGamma;  /* 74 */
extern int idvim2GetMinMpegNoiseReduction;  /* 75 */
extern int idvim2GetMinSharpness;  /* 76 */
extern int idvim2GetMpegNoiseReduction;  /* 77 */
extern int idvim2GetOffDigitalNaturalMotion;  /* 78 */
extern int idvim2GetOffDnr;  /* 79 */
extern int idvim2GetOffDynamicContrast;  /* 80 */
extern int idvim2GetOffMpegNoiseReduction;  /* 81 */
extern int idvim2GetPCProcessing;  /* 82 */
extern int idvim2GetSharpness;  /* 83 */
extern int idvim2IsClearLcdAllowed;  /* 84 */
extern int idvim2IsClearLcdFallbackEnabled;  /* 85 */
extern int idvim2IsClearLcdSupported;  /* 86 */
extern int idvim2IsDigitalNaturalMotionAllowed;  /* 87 */
extern int idvim2IsDigitalNaturalMotionSupported;  /* 88 */
extern int idvim2IsDynamicBacklightAllowed;  /* 89 */
extern int idvim2IsDynamicBacklightSupported;  /* 90 */
extern int idvim2IsPCProcessingAllowed;  /* 91 */
extern int idvim2IsPCProcessingSupported;  /* 92 */
extern int idvim2LightSensorAllowed;  /* 93 */
extern int idvim2LightSensorSupported;  /* 94 */
extern int idvim2LtiSupported;  /* 95 */
extern int idvim2MpegNoiseReductionSupported;  /* 96 */
extern int idvim2SetClearLcd;  /* 97 */
extern int idvim2SetColorEnhancement;  /* 98 */
extern int idvim2SetDigitalNaturalMotion;  /* 99 */
extern int idvim2SetDnr;  /* 100 */
extern int idvim2SetDynamicBacklight;  /* 101 */
extern int idvim2SetDynamicContrast;  /* 102 */
extern int idvim2SetGamma;  /* 103 */
extern int idvim2SetLightSensor;  /* 104 */
extern int idvim2SetLti;  /* 105 */
extern int idvim2SetMpegNoiseReduction;  /* 106 */
extern int idvim2SetPCProcessing;  /* 107 */
extern int idvim2SetSharpness;  /* 108 */
extern int idvim2SharpnessSupported;  /* 109 */
extern int idvio2GetBrightness;  /* 110 */
extern int idvio2GetColor;  /* 111 */
extern int idvio2GetContrast;  /* 112 */
extern int idvio2GetFieldFrequency;  /* 113 */
extern int idvio2GetHue;  /* 114 */
extern int idvio2GetTilt;  /* 115 */
extern int idvio2GetTint;  /* 116 */
extern int idvio2HueAllowed;  /* 117 */
extern int idvio2HueSupported;  /* 118 */
extern int idvio2InterlaceControllable;  /* 119 */
extern int idvio2IsInterlaced;  /* 120 */
extern int idvio2NumberOfLines;  /* 121 */
extern int idvio2SetBrightness;  /* 122 */
extern int idvio2SetColor;  /* 123 */
extern int idvio2SetContrast;  /* 124 */
extern int idvio2SetHue;  /* 125 */
extern int idvio2SetInterlaced;  /* 126 */
extern int idvio2SetTilt;  /* 127 */
extern int idvio2SetTint;  /* 128 */
extern int idvio2TiltSupported;  /* 129 */
extern int idvio2TintSupported;  /* 130 */
extern int idvpGetCurrentViewPort;  /* 131 */
extern int idvpIsViewPortAllowed;  /* 132 */
extern int idvpIsViewPortSupported;  /* 133 */
extern int idvwm2EnableSubtitleShift;  /* 134 */
extern int idvwm2GetAbsoluteShift;  /* 135 */
extern int idvwm2GetAntiAgeing;  /* 136 */
extern int idvwm2GetAutoDetect;  /* 137 */
extern int idvwm2GetAutoFormatMode;  /* 138 */
extern int idvwm2GetDefaultSetting;  /* 139 */
extern int idvwm2GetDefaultShift;  /* 140 */
extern int idvwm2GetImageFormat;  /* 141 */
extern int idvwm2GetMaxZoomX;  /* 142 */
extern int idvwm2GetMaxZoomY;  /* 143 */
extern int idvwm2GetMinZoomX;  /* 144 */
extern int idvwm2GetMinZoomY;  /* 145 */
extern int idvwm2GetOverscan;  /* 146 */
extern int idvwm2GetShift;  /* 147 */
extern int idvwm2GetViewMode;  /* 148 */
extern int idvwm2GetWindowFormat;  /* 149 */
extern int idvwm2GetZoom;  /* 150 */
extern int idvwm2IsAbsoluteShiftAllowed;  /* 151 */
extern int idvwm2IsAbsoluteShiftSupported;  /* 152 */
extern int idvwm2IsAllowedViewMode;  /* 153 */
extern int idvwm2IsAllowedViewModeEx;  /* 154 */
extern int idvwm2IsAntiAgeingSupported;  /* 155 */
extern int idvwm2IsAutoFormatModeAllowed;  /* 156 */
extern int idvwm2IsAutoFormatModeSupported;  /* 157 */
extern int idvwm2IsOverscanAllowed;  /* 158 */
extern int idvwm2IsOverscanSupported;  /* 159 */
extern int idvwm2IsShiftAllowed;  /* 160 */
extern int idvwm2IsShiftSupported;  /* 161 */
extern int idvwm2IsSubtitleShiftEnabled;  /* 162 */
extern int idvwm2IsSupportedViewMode;  /* 163 */
extern int idvwm2IsSupportedViewModeEx;  /* 164 */
extern int idvwm2IsZoomSupported;  /* 165 */
extern int idvwm2SetAbsoluteShift;  /* 166 */
extern int idvwm2SetAntiAgeing;  /* 167 */
extern int idvwm2SetAutoFormatMode;  /* 168 */
extern int idvwm2SetDefaultShift;  /* 169 */
extern int idvwm2SetOverscan;  /* 170 */
extern int idvwm2SetShift;  /* 171 */
extern int idvwm2SetSmoothChange;  /* 172 */
extern int idvwm2SetViewMode;  /* 173 */
extern int idvwm2SetViewModeEx;  /* 174 */
extern int idvwm2SetZoom;  /* 175 */
extern int idvwm2UseAutoDetect;  /* 176 */
extern int idvwm2UseAutoDetectAllowed;  /* 177 */
extern int idvwm2UseAutoDetectEx;  /* 178 */
extern int idvwm2UseAutoDetectExAllowed;  /* 179 */
extern int idvwm2UseAutoDetectExSupported;  /* 180 */
extern int idvwm2UseAutoDetectSupported;  /* 181 */
extern int plfapivfMethodID_Last;  /* 182 */

/*  Symbols for plfapivfNotificationID */
extern int iddemoNOnDemoModeAllowedChanged;  /* 0 */
extern int iddemoNOnDemoModeChanged;  /* 1 */
extern int iddemoNOnDemoModeCompleted;  /* 2 */
extern int idpstNOnAutoTvChanged;  /* 3 */
extern int idpstNOnPictureStyleChanged;  /* 4 */
extern int idsltNOnProcessImageAllowedChanged;  /* 5 */
extern int idsltNOnProcessImageCompleted;  /* 6 */
extern int idthreeDfNOn3DFormatChanged;  /* 7 */
extern int idthreeDfNOnIsAllowed3DFormatChanged;  /* 8 */
extern int idthreeDvNOn3DViewingChanged;  /* 9 */
extern int idthreeDvNOnIsAllowed3DViewingChanged;  /* 10 */
extern int idthreeDvNOnIsSupported3DViewingChanged;  /* 11 */
extern int idvdelayNOnDelayChanged;  /* 12 */
extern int idvfitfNOnAvailabilityChanged;  /* 13 */
extern int idvim3NOnClearLcdAllowednessChanged;  /* 14 */
extern int idvim3NOnClearLcdChanged;  /* 15 */
extern int idvim3NOnColorEnhancementChanged;  /* 16 */
extern int idvim3NOnDigitalNaturalMotionAllowednessChanged;  /* 17 */
extern int idvim3NOnDigitalNaturalMotionChanged;  /* 18 */
extern int idvim3NOnDnrChanged;  /* 19 */
extern int idvim3NOnDynamicBacklightAllowednessChanged;  /* 20 */
extern int idvim3NOnDynamicBacklightChanged;  /* 21 */
extern int idvim3NOnDynamicContrastChanged;  /* 22 */
extern int idvim3NOnGammaChanged;  /* 23 */
extern int idvim3NOnLightSensorAllowednessChanged;  /* 24 */
extern int idvim3NOnLightSensorChanged;  /* 25 */
extern int idvim3NOnLtiChanged;  /* 26 */
extern int idvim3NOnMpegNoiseReductionChanged;  /* 27 */
extern int idvim3NOnPcProcessingAllowednessChanged;  /* 28 */
extern int idvim3NOnPcProcessingChanged;  /* 29 */
extern int idvim3NOnSharpnessChanged;  /* 30 */
extern int idvio2NOnBrightnessChanged;  /* 31 */
extern int idvio2NOnColorChanged;  /* 32 */
extern int idvio2NOnContrastChanged;  /* 33 */
extern int idvio2NOnFieldFrequencyChanged;  /* 34 */
extern int idvio2NOnHueAllowedChanged;  /* 35 */
extern int idvio2NOnHueChanged;  /* 36 */
extern int idvio2NOnInterlacedChanged;  /* 37 */
extern int idvio2NOnNumberOfLinesChanged;  /* 38 */
extern int idvio2NOnTiltChanged;  /* 39 */
extern int idvio2NOnTintChanged;  /* 40 */
extern int idvpNOnViewPortAllowednessChanged;  /* 41 */
extern int idvpNOnViewPortChanged;  /* 42 */
extern int idvwm2NOnAutoDetectAllowedChanged;  /* 43 */
extern int idvwm2NOnImageFormatChanged;  /* 44 */
extern int idvwm2NOnIsAllowedViewModeChanged;  /* 45 */
extern int idvwm2NOnIsOverscanAllowedChanged;  /* 46 */
extern int idvwm2NOnOverscanChanged;  /* 47 */
extern int idvwm2NOnShiftChanged;  /* 48 */
extern int idvwm2NOnViewModeChanged;  /* 49 */
extern int idvwm2NOnWindowFormatChanged;  /* 50 */
extern int idvwm2NOnZoomChanged;  /* 51 */
extern int plfapivfNotificationID_Last;  /* 52 */

/*  Functions clients can call, implemented by the supplier. */
extern FResult plfapivf_cprc_GetCopyRight( int winid, int * retval );
extern FResult plfapivf_cprc_IsCopyRightSupported( int winid, int copyright, Bool * retval );
extern FResult plfapivf_cprc_SetCopyRight( int winid, int copyright );
#define plfapivf_cprc_CopyRightCopyOnce  ((int)1)
#define plfapivf_cprc_CopyRightCopyOnce_CONSTANT  1
#define plfapivf_cprc_CopyRightNone  ((int)0)
#define plfapivf_cprc_CopyRightNone_CONSTANT  0
#define plfapivf_cprc_CopyRightProtected  ((int)2)
#define plfapivf_cprc_CopyRightProtected_CONSTANT  2
#define plfapivf_cprc_CopyRightUnknown  ((int)-1)
#define plfapivf_cprc_CopyRightUnknown_CONSTANT  -1
extern FResult plfapivf_demo_DemoModeAllowed( int winid, int mode, Bool * retval );
extern FResult plfapivf_demo_DemoModeSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_demo_GetDemoMode( int winid, int * retval );
extern FResult plfapivf_demo_SetDemoMode( int winid, int mode, int * retval );
#define plfapivf_demo_DemoActive  ((int)1)
#define plfapivf_demo_DemoActive_CONSTANT  1
#define plfapivf_demo_DemoNotAllowed  ((int)4)
#define plfapivf_demo_DemoNotAllowed_CONSTANT  4
#define plfapivf_demo_DemoOk  ((int)0)
#define plfapivf_demo_DemoOk_CONSTANT  0
#define plfapivf_demo_DemoPending  ((int)2)
#define plfapivf_demo_DemoPending_CONSTANT  2
#define plfapivf_demo_DemoRefused  ((int)3)
#define plfapivf_demo_DemoRefused_CONSTANT  3
#define plfapivf_demo_ModeDnr  ((int)1)
#define plfapivf_demo_ModeDnr_CONSTANT  1
#define plfapivf_demo_ModeHdr  ((int)9)
#define plfapivf_demo_ModeHdr_CONSTANT  9
#define plfapivf_demo_ModeHistogram  ((int)2)
#define plfapivf_demo_ModeHistogram_CONSTANT  2
#define plfapivf_demo_ModeLedBacklight  ((int)7)
#define plfapivf_demo_ModeLedBacklight_CONSTANT  7
#define plfapivf_demo_ModeLocalContrast  ((int)8)
#define plfapivf_demo_ModeLocalContrast_CONSTANT  8
#define plfapivf_demo_ModeMaximumPixelImprovement  ((int)4)
#define plfapivf_demo_ModeMaximumPixelImprovement_CONSTANT  4
#define plfapivf_demo_ModeMotionCompensation  ((int)3)
#define plfapivf_demo_ModeMotionCompensation_CONSTANT  3
#define plfapivf_demo_ModeMotionVectorOverlay  ((int)5)
#define plfapivf_demo_ModeMotionVectorOverlay_CONSTANT  5
#define plfapivf_demo_ModeOff  ((int)0)
#define plfapivf_demo_ModeOff_CONSTANT  0
#define plfapivf_demo_ModeScanningBacklight  ((int)6)
#define plfapivf_demo_ModeScanningBacklight_CONSTANT  6
#define plfapivf_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapivf_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapivf_errid_Ok  ((FResult)0)
#define plfapivf_errid_Ok_CONSTANT  0
#define plfapivf_errid_Other  ((FResult)-1)
#define plfapivf_errid_Other_CONSTANT  -1
#define plfapivf_errid_ResourceNotOwned  ((FResult)1)
#define plfapivf_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapivf_ppr_GetDefaultProfile( int winid, PlfApiSmartActivity act, int * retval );
extern FResult plfapivf_ppr_GetPictureProfile( int winid, int * retval );
extern FResult plfapivf_ppr_GetProfileItem( int winid, int mode, int item, int * retval );
extern FResult plfapivf_ppr_IsPictureProfileSupported( int winid, int pictureprofile, Bool * retval );
extern FResult plfapivf_ppr_SetPictureProfile( int winid, int pictureprofile );
#define plfapivf_ppr_ItemAdvSharpness  ((int)5)
#define plfapivf_ppr_ItemAdvSharpness_CONSTANT  5
#define plfapivf_ppr_ItemBrightness  ((int)0)
#define plfapivf_ppr_ItemBrightness_CONSTANT  0
#define plfapivf_ppr_ItemColor  ((int)2)
#define plfapivf_ppr_ItemColor_CONSTANT  2
#define plfapivf_ppr_ItemColorEnhancement  ((int)13)
#define plfapivf_ppr_ItemColorEnhancement_CONSTANT  13
#define plfapivf_ppr_ItemContrast  ((int)1)
#define plfapivf_ppr_ItemContrast_CONSTANT  1
#define plfapivf_ppr_ItemDigitalClearLcd  ((int)7)
#define plfapivf_ppr_ItemDigitalClearLcd_CONSTANT  7
#define plfapivf_ppr_ItemDigitalNaturalMotion  ((int)6)
#define plfapivf_ppr_ItemDigitalNaturalMotion_CONSTANT  6
#define plfapivf_ppr_ItemDynamicBacklight  ((int)10)
#define plfapivf_ppr_ItemDynamicBacklight_CONSTANT  10
#define plfapivf_ppr_ItemDynamicContrast  ((int)11)
#define plfapivf_ppr_ItemDynamicContrast_CONSTANT  11
#define plfapivf_ppr_ItemGamma  ((int)14)
#define plfapivf_ppr_ItemGamma_CONSTANT  14
#define plfapivf_ppr_ItemHue  ((int)4)
#define plfapivf_ppr_ItemHue_CONSTANT  4
#define plfapivf_ppr_ItemLightSensor  ((int)8)
#define plfapivf_ppr_ItemLightSensor_CONSTANT  8
#define plfapivf_ppr_ItemMpegArtRed  ((int)9)
#define plfapivf_ppr_ItemMpegArtRed_CONSTANT  9
#define plfapivf_ppr_ItemNoiseReductiom  ((int)12)
#define plfapivf_ppr_ItemNoiseReductiom_CONSTANT  12
#define plfapivf_ppr_ItemSharpnessLevel  ((int)3)
#define plfapivf_ppr_ItemSharpnessLevel_CONSTANT  3
#define plfapivf_ppr_ItemTint  ((int)15)
#define plfapivf_ppr_ItemTint_CONSTANT  15
#define plfapivf_ppr_PictureProfileCinema  ((int)7)
#define plfapivf_ppr_PictureProfileCinema_CONSTANT  7
#define plfapivf_ppr_PictureProfileCustom  ((int)10)
#define plfapivf_ppr_PictureProfileCustom_CONSTANT  10
#define plfapivf_ppr_PictureProfileEco  ((int)4)
#define plfapivf_ppr_PictureProfileEco_CONSTANT  4
#define plfapivf_ppr_PictureProfileGame  ((int)6)
#define plfapivf_ppr_PictureProfileGame_CONSTANT  6
#define plfapivf_ppr_PictureProfileNatural  ((int)2)
#define plfapivf_ppr_PictureProfileNatural_CONSTANT  2
#define plfapivf_ppr_PictureProfileNeutral  ((int)2)
#define plfapivf_ppr_PictureProfileNeutral_CONSTANT  2
#define plfapivf_ppr_PictureProfilePersonal  ((int)9)
#define plfapivf_ppr_PictureProfilePersonal_CONSTANT  9
#define plfapivf_ppr_PictureProfilePhoto  ((int)8)
#define plfapivf_ppr_PictureProfilePhoto_CONSTANT  8
#define plfapivf_ppr_PictureProfileShop  ((int)5)
#define plfapivf_ppr_PictureProfileShop_CONSTANT  5
#define plfapivf_ppr_PictureProfileStandard  ((int)3)
#define plfapivf_ppr_PictureProfileStandard_CONSTANT  3
#define plfapivf_ppr_PictureProfileVivid  ((int)1)
#define plfapivf_ppr_PictureProfileVivid_CONSTANT  1
extern FResult plfapivf_pst_AutoTvSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_pst_GetActualAmbientLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetActualBrightnessLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetActualColorLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetActualContrastLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetActualHistogramLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetActualMotionLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetActualNoiseLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetActualSharpnessLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetActualTintLevel( int winid, int * retval );
extern FResult plfapivf_pst_GetAutoTv( int winid, int * retval );
extern FResult plfapivf_pst_GetPictureStyle( int winid, int * retval );
extern FResult plfapivf_pst_IsControlledParameter( int winid, int param, Bool * retval );
extern FResult plfapivf_pst_PictureStyleSupported( int winid, int picturestyle, Bool * retval );
extern FResult plfapivf_pst_SetAutoTv( int winid, int mode );
extern FResult plfapivf_pst_SetPictureStyle( int winid, int picturestyle );
#define plfapivf_pst_Brightness  ((int)2)
#define plfapivf_pst_Brightness_CONSTANT  2
#define plfapivf_pst_Color  ((int)0)
#define plfapivf_pst_Color_CONSTANT  0
#define plfapivf_pst_Contrast  ((int)1)
#define plfapivf_pst_Contrast_CONSTANT  1
#define plfapivf_pst_Cti  ((int)4)
#define plfapivf_pst_Cti_CONSTANT  4
#define plfapivf_pst_Dnr  ((int)3)
#define plfapivf_pst_Dnr_CONSTANT  3
#define plfapivf_pst_DynamicContrast  ((int)6)
#define plfapivf_pst_DynamicContrast_CONSTANT  6
#define plfapivf_pst_Eco  ((int)1)
#define plfapivf_pst_Eco_CONSTANT  1
#define plfapivf_pst_FineText  ((int)9)
#define plfapivf_pst_FineText_CONSTANT  9
#define plfapivf_pst_FirstPictureStyle  ((int)0)
#define plfapivf_pst_FirstPictureStyle_CONSTANT  0
#define plfapivf_pst_Graphics  ((int)7)
#define plfapivf_pst_Graphics_CONSTANT  7
#define plfapivf_pst_HighAutoTv  ((int)3)
#define plfapivf_pst_HighAutoTv_CONSTANT  3
#define plfapivf_pst_LastPictureStyle  ((int)12)
#define plfapivf_pst_LastPictureStyle_CONSTANT  12
#define plfapivf_pst_LowAutoTv  ((int)1)
#define plfapivf_pst_LowAutoTv_CONSTANT  1
#define plfapivf_pst_MaxAutoTv  ((int)3)
#define plfapivf_pst_MaxAutoTv_CONSTANT  3
#define plfapivf_pst_MaxLevel  ((int)255)
#define plfapivf_pst_MaxLevel_CONSTANT  255
#define plfapivf_pst_MedAutoTv  ((int)2)
#define plfapivf_pst_MedAutoTv_CONSTANT  2
#define plfapivf_pst_MinLevel  ((int)0)
#define plfapivf_pst_MinLevel_CONSTANT  0
#define plfapivf_pst_Motion  ((int)7)
#define plfapivf_pst_Motion_CONSTANT  7
#define plfapivf_pst_Movies  ((int)10)
#define plfapivf_pst_Movies_CONSTANT  10
#define plfapivf_pst_MultiMedia  ((int)6)
#define plfapivf_pst_MultiMedia_CONSTANT  6
#define plfapivf_pst_Natural  ((int)3)
#define plfapivf_pst_Natural_CONSTANT  3
#define plfapivf_pst_NoAutoTv  ((int)0)
#define plfapivf_pst_NoAutoTv_CONSTANT  0
#define plfapivf_pst_Personal  ((int)0)
#define plfapivf_pst_Personal_CONSTANT  0
#define plfapivf_pst_Rich  ((int)4)
#define plfapivf_pst_Rich_CONSTANT  4
#define plfapivf_pst_Sharpness  ((int)5)
#define plfapivf_pst_Sharpness_CONSTANT  5
#define plfapivf_pst_Soft  ((int)2)
#define plfapivf_pst_Soft_CONSTANT  2
#define plfapivf_pst_Sport  ((int)5)
#define plfapivf_pst_Sport_CONSTANT  5
#define plfapivf_pst_Text  ((int)8)
#define plfapivf_pst_Text_CONSTANT  8
#define plfapivf_pst_Tint  ((int)8)
#define plfapivf_pst_Tint_CONSTANT  8
#define plfapivf_pst_WeakSignals  ((int)11)
#define plfapivf_pst_WeakSignals_CONSTANT  11
extern FResult plfapivf_slt_Disable( int winid );
extern FResult plfapivf_slt_Enable( int winid );
extern FResult plfapivf_slt_GetMaxSharpness( int winid, int * retval );
extern FResult plfapivf_slt_GetMinSharpness( int winid, int * retval );
extern FResult plfapivf_slt_IsProcessImageAllowed( int winid, Address pBuffer, Nat32 hsize, Nat32 vsize, Nat32 stride, Nat32 upleftx, Nat32 uplefty, Nat32 lowrightx, Nat32 lowrighty, Nat32 pixfmttype, Nat32 pixfmtclass, int bright, int contr, int sat, int sharp, Bool lightsensor, Bool * retval );
extern FResult plfapivf_slt_IsProcessImageSupported( int winid, Address pBuffer, Nat32 hsize, Nat32 vsize, Nat32 stride, Nat32 upleftx, Nat32 uplefty, Nat32 lowrightx, Nat32 lowrighty, Nat32 pixfmttype, Nat32 pixfmtclass, int bright, int contr, int sat, int sharp, Bool lightsensor, Bool * retval );
extern FResult plfapivf_slt_ProcessImage( int winid, Address pBuffer, Nat32 hsize, Nat32 vsize, Nat32 stride, Nat32 upleftx, Nat32 uplefty, Nat32 lowrightx, Nat32 lowrighty, Nat32 pixfmttype, Nat32 pixfmtclass, int bright, int contr, int sat, int sharp, Bool lightsensor, Bool * retval );
#define plfapivf_slt_MaxBrightness  ((int)100)
#define plfapivf_slt_MaxBrightness_CONSTANT  100
#define plfapivf_slt_MaxContrast  ((int)100)
#define plfapivf_slt_MaxContrast_CONSTANT  100
#define plfapivf_slt_MaxSaturation  ((int)100)
#define plfapivf_slt_MaxSaturation_CONSTANT  100
#define plfapivf_slt_MinBrightness  ((int)0)
#define plfapivf_slt_MinBrightness_CONSTANT  0
#define plfapivf_slt_MinContrast  ((int)0)
#define plfapivf_slt_MinContrast_CONSTANT  0
#define plfapivf_slt_MinSaturation  ((int)0)
#define plfapivf_slt_MinSaturation_CONSTANT  0
#define plfapivf_slt_PixFmtArgb1555  ((Nat32)2)
#define plfapivf_slt_PixFmtArgb1555_CONSTANT  2
#define plfapivf_slt_PixFmtArgb4444  ((Nat32)4)
#define plfapivf_slt_PixFmtArgb4444_CONSTANT  4
#define plfapivf_slt_PixFmtArgb8888  ((Nat32)7)
#define plfapivf_slt_PixFmtArgb8888_CONSTANT  7
#define plfapivf_slt_PixFmtArgbClut1bpp  ((Nat32)5)
#define plfapivf_slt_PixFmtArgbClut1bpp_CONSTANT  5
#define plfapivf_slt_PixFmtArgbClut2bpp  ((Nat32)6)
#define plfapivf_slt_PixFmtArgbClut2bpp_CONSTANT  6
#define plfapivf_slt_PixFmtArgbClut4bpp  ((Nat32)7)
#define plfapivf_slt_PixFmtArgbClut4bpp_CONSTANT  7
#define plfapivf_slt_PixFmtArgbClut8bpp  ((Nat32)8)
#define plfapivf_slt_PixFmtArgbClut8bpp_CONSTANT  8
#define plfapivf_slt_PixFmtAyuvClut1bpp  ((Nat32)13)
#define plfapivf_slt_PixFmtAyuvClut1bpp_CONSTANT  13
#define plfapivf_slt_PixFmtAyuvClut2bpp  ((Nat32)14)
#define plfapivf_slt_PixFmtAyuvClut2bpp_CONSTANT  14
#define plfapivf_slt_PixFmtAyuvClut4bpp  ((Nat32)15)
#define plfapivf_slt_PixFmtAyuvClut4bpp_CONSTANT  15
#define plfapivf_slt_PixFmtAyuvClut8bpp  ((Nat32)16)
#define plfapivf_slt_PixFmtAyuvClut8bpp_CONSTANT  16
#define plfapivf_slt_PixFmtClassClut  ((Nat32)3)
#define plfapivf_slt_PixFmtClassClut_CONSTANT  3
#define plfapivf_slt_PixFmtClassRgb  ((Nat32)2)
#define plfapivf_slt_PixFmtClassRgb_CONSTANT  2
#define plfapivf_slt_PixFmtClassYuv  ((Nat32)1)
#define plfapivf_slt_PixFmtClassYuv_CONSTANT  1
#define plfapivf_slt_PixFmtRgb565  ((Nat32)5)
#define plfapivf_slt_PixFmtRgb565_CONSTANT  5
#define plfapivf_slt_PixFmtRgbClut1bpp  ((Nat32)1)
#define plfapivf_slt_PixFmtRgbClut1bpp_CONSTANT  1
#define plfapivf_slt_PixFmtRgbClut2bpp  ((Nat32)2)
#define plfapivf_slt_PixFmtRgbClut2bpp_CONSTANT  2
#define plfapivf_slt_PixFmtRgbClut4bpp  ((Nat32)3)
#define plfapivf_slt_PixFmtRgbClut4bpp_CONSTANT  3
#define plfapivf_slt_PixFmtRgbClut8bpp  ((Nat32)4)
#define plfapivf_slt_PixFmtRgbClut8bpp_CONSTANT  4
#define plfapivf_slt_PixFmtUyvy  ((Nat32)1)
#define plfapivf_slt_PixFmtUyvy_CONSTANT  1
#define plfapivf_slt_PixFmtVyuy  ((Nat32)3)
#define plfapivf_slt_PixFmtVyuy_CONSTANT  3
#define plfapivf_slt_PixFmtXrgb1555  ((Nat32)1)
#define plfapivf_slt_PixFmtXrgb1555_CONSTANT  1
#define plfapivf_slt_PixFmtXrgb4444  ((Nat32)3)
#define plfapivf_slt_PixFmtXrgb4444_CONSTANT  3
#define plfapivf_slt_PixFmtXrgb8888  ((Nat32)6)
#define plfapivf_slt_PixFmtXrgb8888_CONSTANT  6
#define plfapivf_slt_PixFmtYuv420  ((Nat32)4)
#define plfapivf_slt_PixFmtYuv420_CONSTANT  4
#define plfapivf_slt_PixFmtYuvClut1bpp  ((Nat32)9)
#define plfapivf_slt_PixFmtYuvClut1bpp_CONSTANT  9
#define plfapivf_slt_PixFmtYuvClut2bpp  ((Nat32)10)
#define plfapivf_slt_PixFmtYuvClut2bpp_CONSTANT  10
#define plfapivf_slt_PixFmtYuvClut4bpp  ((Nat32)11)
#define plfapivf_slt_PixFmtYuvClut4bpp_CONSTANT  11
#define plfapivf_slt_PixFmtYuvClut8bpp  ((Nat32)12)
#define plfapivf_slt_PixFmtYuvClut8bpp_CONSTANT  12
#define plfapivf_slt_PixFmtYuy2  ((Nat32)2)
#define plfapivf_slt_PixFmtYuy2_CONSTANT  2
extern FResult plfapivf_threeDf_Get3DFormat( int winid, int * retval );
extern FResult plfapivf_threeDf_IsAllowed3DFormat( int winid, int format, Bool * retval );
extern FResult plfapivf_threeDf_IsSupported3DFormat( int winid, int format, Bool * retval );
extern FResult plfapivf_threeDf_Set3DFormat( int winid, int format );
#define plfapivf_threeDf_Format3DAuto  ((int)0)
#define plfapivf_threeDf_Format3DAuto_CONSTANT  0
#define plfapivf_threeDf_Format3DFramePacked  ((int)3)
#define plfapivf_threeDf_Format3DFramePacked_CONSTANT  3
#define plfapivf_threeDf_Format3DSideBySide  ((int)1)
#define plfapivf_threeDf_Format3DSideBySide_CONSTANT  1
#define plfapivf_threeDf_Format3DTopBottom  ((int)2)
#define plfapivf_threeDf_Format3DTopBottom_CONSTANT  2
extern FResult plfapivf_threeDv_Get3DViewing( int winid, int * retval );
extern FResult plfapivf_threeDv_IsAllowed3DViewing( int winid, int viewing, Bool * retval );
extern FResult plfapivf_threeDv_IsSupported3DViewing( int winid, int viewing, Bool * retval );
extern FResult plfapivf_threeDv_Set3DViewing( int winid, int viewing );
#define plfapivf_threeDv_Viewing2D  ((int)1)
#define plfapivf_threeDv_Viewing2D_CONSTANT  1
#define plfapivf_threeDv_Viewing3D  ((int)0)
#define plfapivf_threeDv_Viewing3D_CONSTANT  0
extern FResult plfapivf_vdelay_GetDelay( int winid, int * retval );
extern FResult plfapivf_vfitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids );
#define plfapivf_vfitfid_cprc  ((Nat32)1)
#define plfapivf_vfitfid_cprc_CONSTANT  1
#define plfapivf_vfitfid_demo  ((Nat32)1)
#define plfapivf_vfitfid_demo_CONSTANT  1
#define plfapivf_vfitfid_gfxctrl  ((Nat32)1)
#define plfapivf_vfitfid_gfxctrl_CONSTANT  1
#define plfapivf_vfitfid_ppr  ((Nat32)1)
#define plfapivf_vfitfid_ppr_CONSTANT  1
#define plfapivf_vfitfid_pst  ((Nat32)1)
#define plfapivf_vfitfid_pst_CONSTANT  1
#define plfapivf_vfitfid_slt  ((Nat32)1)
#define plfapivf_vfitfid_slt_CONSTANT  1
#define plfapivf_vfitfid_threeDf  ((Nat32)1)
#define plfapivf_vfitfid_threeDf_CONSTANT  1
#define plfapivf_vfitfid_threeDfN  ((Nat32)1)
#define plfapivf_vfitfid_threeDfN_CONSTANT  1
#define plfapivf_vfitfid_threeDv  ((Nat32)1)
#define plfapivf_vfitfid_threeDv_CONSTANT  1
#define plfapivf_vfitfid_threeDvN  ((Nat32)1)
#define plfapivf_vfitfid_threeDvN_CONSTANT  1
#define plfapivf_vfitfid_vclip  ((Nat32)1)
#define plfapivf_vfitfid_vclip_CONSTANT  1
#define plfapivf_vfitfid_vdelay  ((Nat32)1)
#define plfapivf_vfitfid_vdelay_CONSTANT  1
#define plfapivf_vfitfid_vfr  ((Nat32)1)
#define plfapivf_vfitfid_vfr_CONSTANT  1
#define plfapivf_vfitfid_vim  ((Nat32)1)
#define plfapivf_vfitfid_vim_CONSTANT  1
#define plfapivf_vfitfid_vim2  ((Nat32)1)
#define plfapivf_vfitfid_vim2_CONSTANT  1
#define plfapivf_vfitfid_vio  ((Nat32)1)
#define plfapivf_vfitfid_vio_CONSTANT  1
#define plfapivf_vfitfid_vio2  ((Nat32)1)
#define plfapivf_vfitfid_vio2_CONSTANT  1
#define plfapivf_vfitfid_vmt  ((Nat32)1)
#define plfapivf_vfitfid_vmt_CONSTANT  1
#define plfapivf_vfitfid_vp  ((Nat32)1)
#define plfapivf_vfitfid_vp_CONSTANT  1
#define plfapivf_vfitfid_vsc  ((Nat32)1)
#define plfapivf_vfitfid_vsc_CONSTANT  1
#define plfapivf_vfitfid_vvmt  ((Nat32)1)
#define plfapivf_vfitfid_vvmt_CONSTANT  1
#define plfapivf_vfitfid_vwm  ((Nat32)1)
#define plfapivf_vfitfid_vwm_CONSTANT  1
#define plfapivf_vfitfid_vwm2  ((Nat32)1)
#define plfapivf_vfitfid_vwm2_CONSTANT  1
extern FResult plfapivf_vim2_ColorEnhancementSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_DnrSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_DynamicContrastSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_EnableClearLcdFallback( int winid, Bool onoff );
extern FResult plfapivf_vim2_GammaSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_GetClearLcd( int winid, Bool * retval );
extern FResult plfapivf_vim2_GetColorEnhancement( int winid, int * retval );
extern FResult plfapivf_vim2_GetDigitalNaturalMotion( int winid, int * retval );
extern FResult plfapivf_vim2_GetDnr( int winid, int * retval );
extern FResult plfapivf_vim2_GetDynamicBacklight( int winid, int * retval );
extern FResult plfapivf_vim2_GetDynamicContrast( int winid, int * retval );
extern FResult plfapivf_vim2_GetGamma( int winid, int * retval );
extern FResult plfapivf_vim2_GetLightSensor( int winid, Bool * retval );
extern FResult plfapivf_vim2_GetLti( int winid, Bool * retval );
extern FResult plfapivf_vim2_GetMaxDigitalNaturalMotion( int winid, int * retval );
extern FResult plfapivf_vim2_GetMaxDnr( int winid, int * retval );
extern FResult plfapivf_vim2_GetMaxDynamicContrast( int winid, int * retval );
extern FResult plfapivf_vim2_GetMaxGamma( int winid, int * retval );
extern FResult plfapivf_vim2_GetMaxMpegNoiseReduction( int winid, int * retval );
extern FResult plfapivf_vim2_GetMaxSharpness( int winid, int * retval );
extern FResult plfapivf_vim2_GetMedDigitalNaturalMotion( int winid, int * retval );
extern FResult plfapivf_vim2_GetMedDnr( int winid, int * retval );
extern FResult plfapivf_vim2_GetMedDynamicContrast( int winid, int * retval );
extern FResult plfapivf_vim2_GetMedGamma( int winid, int * retval );
extern FResult plfapivf_vim2_GetMedMpegNoiseReduction( int winid, int * retval );
extern FResult plfapivf_vim2_GetMedSharpness( int winid, int * retval );
extern FResult plfapivf_vim2_GetMinDigitalNaturalMotion( int winid, int * retval );
extern FResult plfapivf_vim2_GetMinDnr( int winid, int * retval );
extern FResult plfapivf_vim2_GetMinDynamicContrast( int winid, int * retval );
extern FResult plfapivf_vim2_GetMinGamma( int winid, int * retval );
extern FResult plfapivf_vim2_GetMinMpegNoiseReduction( int winid, int * retval );
extern FResult plfapivf_vim2_GetMinSharpness( int winid, int * retval );
extern FResult plfapivf_vim2_GetMpegNoiseReduction( int winid, int * retval );
extern FResult plfapivf_vim2_GetOffDigitalNaturalMotion( int winid, int * retval );
extern FResult plfapivf_vim2_GetOffDnr( int winid, int * retval );
extern FResult plfapivf_vim2_GetOffDynamicContrast( int winid, int * retval );
extern FResult plfapivf_vim2_GetOffMpegNoiseReduction( int winid, int * retval );
extern FResult plfapivf_vim2_GetPCProcessing( int winid, Bool * retval );
extern FResult plfapivf_vim2_GetSharpness( int winid, int * retval );
extern FResult plfapivf_vim2_IsClearLcdAllowed( int winid, Bool * retval );
extern FResult plfapivf_vim2_IsClearLcdFallbackEnabled( int winid, Bool * retval );
extern FResult plfapivf_vim2_IsClearLcdSupported( int winid, Bool * retval );
extern FResult plfapivf_vim2_IsDigitalNaturalMotionAllowed( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_IsDigitalNaturalMotionSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_IsDynamicBacklightAllowed( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_IsDynamicBacklightSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_IsPCProcessingAllowed( int winid, Bool * retval );
extern FResult plfapivf_vim2_IsPCProcessingSupported( int winid, Bool * retval );
extern FResult plfapivf_vim2_LightSensorAllowed( int winid, Bool * retval );
extern FResult plfapivf_vim2_LightSensorSupported( int winid, Bool * retval );
extern FResult plfapivf_vim2_LtiSupported( int winid, Bool * retval );
extern FResult plfapivf_vim2_MpegNoiseReductionSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_vim2_SetClearLcd( int winid, Bool onoff );
extern FResult plfapivf_vim2_SetColorEnhancement( int winid, int mode );
extern FResult plfapivf_vim2_SetDigitalNaturalMotion( int winid, int mode );
extern FResult plfapivf_vim2_SetDnr( int winid, int mode );
extern FResult plfapivf_vim2_SetDynamicBacklight( int winid, int mode );
extern FResult plfapivf_vim2_SetDynamicContrast( int winid, int mode );
extern FResult plfapivf_vim2_SetGamma( int winid, int mode );
extern FResult plfapivf_vim2_SetLightSensor( int winid, Bool onoff );
extern FResult plfapivf_vim2_SetLti( int winid, Bool onoff );
extern FResult plfapivf_vim2_SetMpegNoiseReduction( int winid, int mode );
extern FResult plfapivf_vim2_SetPCProcessing( int winid, Bool onoff );
extern FResult plfapivf_vim2_SetSharpness( int winid, int mode );
extern FResult plfapivf_vim2_SharpnessSupported( int winid, int mode, Bool * retval );
#define plfapivf_vim2_ModeBasicDynamicBacklight  ((int)3)
#define plfapivf_vim2_ModeBasicDynamicBacklight_CONSTANT  3
#define plfapivf_vim2_ModeBestPictureDynamicBacklight  ((int)2)
#define plfapivf_vim2_ModeBestPictureDynamicBacklight_CONSTANT  2
#define plfapivf_vim2_ModeBestPowerDynamicBacklight  ((int)1)
#define plfapivf_vim2_ModeBestPowerDynamicBacklight_CONSTANT  1
#define plfapivf_vim2_ModeMaxColorEnhancement  ((int)3)
#define plfapivf_vim2_ModeMaxColorEnhancement_CONSTANT  3
#define plfapivf_vim2_ModeMedColorEnhancement  ((int)2)
#define plfapivf_vim2_ModeMedColorEnhancement_CONSTANT  2
#define plfapivf_vim2_ModeMinColorEnhancement  ((int)1)
#define plfapivf_vim2_ModeMinColorEnhancement_CONSTANT  1
#define plfapivf_vim2_ModeOffColorEnhancement  ((int)0)
#define plfapivf_vim2_ModeOffColorEnhancement_CONSTANT  0
#define plfapivf_vim2_ModeOffDynamicBacklight  ((int)0)
#define plfapivf_vim2_ModeOffDynamicBacklight_CONSTANT  0
extern FResult plfapivf_vio2_GetBrightness( int winid, int * retval );
extern FResult plfapivf_vio2_GetColor( int winid, int * retval );
extern FResult plfapivf_vio2_GetContrast( int winid, int * retval );
extern FResult plfapivf_vio2_GetFieldFrequency( int winid, int * retval );
extern FResult plfapivf_vio2_GetHue( int winid, int * retval );
extern FResult plfapivf_vio2_GetTilt( int winid, int * retval );
extern FResult plfapivf_vio2_GetTint( int winid, int * retval );
extern FResult plfapivf_vio2_HueAllowed( int winid, Bool * retval );
extern FResult plfapivf_vio2_HueSupported( int winid, Bool * retval );
extern FResult plfapivf_vio2_InterlaceControllable( int winid, Bool * retval );
extern FResult plfapivf_vio2_IsInterlaced( int winid, Bool * retval );
extern FResult plfapivf_vio2_NumberOfLines( int winid, int * retval );
extern FResult plfapivf_vio2_SetBrightness( int winid, int brightness );
extern FResult plfapivf_vio2_SetColor( int winid, int color );
extern FResult plfapivf_vio2_SetContrast( int winid, int contrast );
extern FResult plfapivf_vio2_SetHue( int winid, int hue );
extern FResult plfapivf_vio2_SetInterlaced( int winid, Bool interlaced );
extern FResult plfapivf_vio2_SetTilt( int winid, int tilt );
extern FResult plfapivf_vio2_SetTint( int winid, int tint );
extern FResult plfapivf_vio2_TiltSupported( int winid, Bool * retval );
extern FResult plfapivf_vio2_TintSupported( int winid, int tint, Bool * retval );
#define plfapivf_vio2_CoolTint  ((int)0)
#define plfapivf_vio2_CoolTint_CONSTANT  0
#define plfapivf_vio2_CustomTint  ((int)3)
#define plfapivf_vio2_CustomTint_CONSTANT  3
#define plfapivf_vio2_MaxBrightness  ((int)100)
#define plfapivf_vio2_MaxBrightness_CONSTANT  100
#define plfapivf_vio2_MaxColor  ((int)100)
#define plfapivf_vio2_MaxColor_CONSTANT  100
#define plfapivf_vio2_MaxContrast  ((int)100)
#define plfapivf_vio2_MaxContrast_CONSTANT  100
#define plfapivf_vio2_MaxHue  ((int)100)
#define plfapivf_vio2_MaxHue_CONSTANT  100
#define plfapivf_vio2_MaxTilt  ((int)255)
#define plfapivf_vio2_MaxTilt_CONSTANT  255
#define plfapivf_vio2_MaxTint  ((int)3)
#define plfapivf_vio2_MaxTint_CONSTANT  3
#define plfapivf_vio2_MinBrightness  ((int)0)
#define plfapivf_vio2_MinBrightness_CONSTANT  0
#define plfapivf_vio2_MinColor  ((int)0)
#define plfapivf_vio2_MinColor_CONSTANT  0
#define plfapivf_vio2_MinContrast  ((int)0)
#define plfapivf_vio2_MinContrast_CONSTANT  0
#define plfapivf_vio2_MinHue  ((int)0)
#define plfapivf_vio2_MinHue_CONSTANT  0
#define plfapivf_vio2_MinTilt  ((int)-255)
#define plfapivf_vio2_MinTilt_CONSTANT  -255
#define plfapivf_vio2_MinTint  ((int)0)
#define plfapivf_vio2_MinTint_CONSTANT  0
#define plfapivf_vio2_NormalTint  ((int)1)
#define plfapivf_vio2_NormalTint_CONSTANT  1
#define plfapivf_vio2_NoTilt  ((int)0)
#define plfapivf_vio2_NoTilt_CONSTANT  0
#define plfapivf_vio2_WarmTint  ((int)2)
#define plfapivf_vio2_WarmTint_CONSTANT  2
extern FResult plfapivf_vp_GetCurrentViewPort( int winid, int * ulx, int * uly, int * lrx, int * lry, int * width, int * height );
extern FResult plfapivf_vp_IsViewPortAllowed( int winid, Bool * retval );
extern FResult plfapivf_vp_IsViewPortSupported( int winid, Bool * retval );
extern FResult plfapivf_vwm2_EnableSubtitleShift( int winid, Bool onoff );
extern FResult plfapivf_vwm2_GetAbsoluteShift( int winid, int * x, int * y );
extern FResult plfapivf_vwm2_GetAntiAgeing( int winid, Nat8 * retval );
extern FResult plfapivf_vwm2_GetAutoDetect( int winid, int * retval );
extern FResult plfapivf_vwm2_GetAutoFormatMode( int winid, int * retval );
extern FResult plfapivf_vwm2_GetDefaultSetting( int winid, int setting, int res, PlfApiSmartActivity act, int * retval );
extern FResult plfapivf_vwm2_GetDefaultShift( int winid, int viewmode, int * dx, int * dy );
extern FResult plfapivf_vwm2_GetImageFormat( int winid, int * retval );
extern FResult plfapivf_vwm2_GetMaxZoomX( int winid, int * retval );
extern FResult plfapivf_vwm2_GetMaxZoomY( int winid, int * retval );
extern FResult plfapivf_vwm2_GetMinZoomX( int winid, int * retval );
extern FResult plfapivf_vwm2_GetMinZoomY( int winid, int * retval );
extern FResult plfapivf_vwm2_GetOverscan( int winid, int * retval );
extern FResult plfapivf_vwm2_GetShift( int winid, int * dx, int * dy );
extern FResult plfapivf_vwm2_GetViewMode( int winid, int * retval );
extern FResult plfapivf_vwm2_GetWindowFormat( int winid, int * retval );
extern FResult plfapivf_vwm2_GetZoom( int winid, int * zoomx, int * zoomy );
extern FResult plfapivf_vwm2_IsAbsoluteShiftAllowed( int winid, int x, int y, Bool * retval );
extern FResult plfapivf_vwm2_IsAbsoluteShiftSupported( int winid, int x, int y, Bool * retval );
extern FResult plfapivf_vwm2_IsAllowedViewMode( int winid, int viewmode, Bool * retval );
extern FResult plfapivf_vwm2_IsAllowedViewModeEx( int winid, int viewmode, int dx, int dy, Bool * retval );
extern FResult plfapivf_vwm2_IsAntiAgeingSupported( int winid, Nat8 mode, Bool * retval );
extern FResult plfapivf_vwm2_IsAutoFormatModeAllowed( int winid, int mode, Bool * retval );
extern FResult plfapivf_vwm2_IsAutoFormatModeSupported( int winid, int mode, Bool * retval );
extern FResult plfapivf_vwm2_IsOverscanAllowed( int winid, int overscan, Bool * retval );
extern FResult plfapivf_vwm2_IsOverscanSupported( int winid, int overscan, Bool * retval );
extern FResult plfapivf_vwm2_IsShiftAllowed( int winid, int dx, int dy, Bool * retval );
extern FResult plfapivf_vwm2_IsShiftSupported( int winid, int dx, int dy, Bool * retval );
extern FResult plfapivf_vwm2_IsSubtitleShiftEnabled( int winid, Bool * retval );
extern FResult plfapivf_vwm2_IsSupportedViewMode( int winid, int viewmode, Bool * retval );
extern FResult plfapivf_vwm2_IsSupportedViewModeEx( int winid, int viewmode, int dx, int dy, Bool * retval );
extern FResult plfapivf_vwm2_IsZoomSupported( int winid, int zoomx, int zoomy, Bool * retval );
extern FResult plfapivf_vwm2_SetAbsoluteShift( int winid, int x, int y );
extern FResult plfapivf_vwm2_SetAntiAgeing( int winid, Nat8 mode );
extern FResult plfapivf_vwm2_SetAutoFormatMode( int winid, int mode );
extern FResult plfapivf_vwm2_SetDefaultShift( int winid, int viewmode, int dx, int dy );
extern FResult plfapivf_vwm2_SetOverscan( int winid, int overscan );
extern FResult plfapivf_vwm2_SetShift( int winid, int dx, int dy );
extern FResult plfapivf_vwm2_SetSmoothChange( int winid, int time );
extern FResult plfapivf_vwm2_SetViewMode( int winid, int viewmode );
extern FResult plfapivf_vwm2_SetViewModeEx( int winid, int viewmode, int dx, int dy );
extern FResult plfapivf_vwm2_SetZoom( int winid, int zoomx, int zoomy, int dx, int dy );
extern FResult plfapivf_vwm2_UseAutoDetect( int winid, int mode, int * retval );
extern FResult plfapivf_vwm2_UseAutoDetectAllowed( int winid, int * retval );
extern FResult plfapivf_vwm2_UseAutoDetectEx( int winid, int mode, int dx, int dy, int * retval );
extern FResult plfapivf_vwm2_UseAutoDetectExAllowed( int winid, int dx, int dy, int * retval );
extern FResult plfapivf_vwm2_UseAutoDetectExSupported( int winid, int dx, int dy, int * retval );
extern FResult plfapivf_vwm2_UseAutoDetectSupported( int winid, int * retval );
#define plfapivf_vwm2_AntiAgeingAll  ((Nat8)3)
#define plfapivf_vwm2_AntiAgeingAll_CONSTANT  3
#define plfapivf_vwm2_AntiAgeingHorizontal  ((Nat8)1)
#define plfapivf_vwm2_AntiAgeingHorizontal_CONSTANT  1
#define plfapivf_vwm2_AntiAgeingNone  ((Nat8)0)
#define plfapivf_vwm2_AntiAgeingNone_CONSTANT  0
#define plfapivf_vwm2_AntiAgeingVertical  ((Nat8)2)
#define plfapivf_vwm2_AntiAgeingVertical_CONSTANT  2
#define plfapivf_vwm2_AutoDetect  ((int)2)
#define plfapivf_vwm2_AutoDetect_CONSTANT  2
#define plfapivf_vwm2_AutoFormatMode  ((int)1)
#define plfapivf_vwm2_AutoFormatMode_CONSTANT  1
#define plfapivf_vwm2_HalfWindowLeft  ((int)5)
#define plfapivf_vwm2_HalfWindowLeft_CONSTANT  5
#define plfapivf_vwm2_HalfWindowLeftSqueezed  ((int)6)
#define plfapivf_vwm2_HalfWindowLeftSqueezed_CONSTANT  6
#define plfapivf_vwm2_HD  ((int)1)
#define plfapivf_vwm2_HD_CONSTANT  1
#define plfapivf_vwm2_HighRes  ((int)8)
#define plfapivf_vwm2_HighRes_CONSTANT  8
#define plfapivf_vwm2_HorizontalSqueeze  ((int)0)
#define plfapivf_vwm2_HorizontalSqueeze_CONSTANT  0
#define plfapivf_vwm2_ImageFormat14by9Center  ((int)3)
#define plfapivf_vwm2_ImageFormat14by9Center_CONSTANT  3
#define plfapivf_vwm2_ImageFormat14by9Top  ((int)2)
#define plfapivf_vwm2_ImageFormat14by9Top_CONSTANT  2
#define plfapivf_vwm2_ImageFormat16by9Center  ((int)5)
#define plfapivf_vwm2_ImageFormat16by9Center_CONSTANT  5
#define plfapivf_vwm2_ImageFormat16by9FullFormat  ((int)9)
#define plfapivf_vwm2_ImageFormat16by9FullFormat_CONSTANT  9
#define plfapivf_vwm2_ImageFormat16by9Top  ((int)4)
#define plfapivf_vwm2_ImageFormat16by9Top_CONSTANT  4
#define plfapivf_vwm2_ImageFormat16by9Use14by9  ((int)7)
#define plfapivf_vwm2_ImageFormat16by9Use14by9_CONSTANT  7
#define plfapivf_vwm2_ImageFormat16by9Use4by3  ((int)8)
#define plfapivf_vwm2_ImageFormat16by9Use4by3_CONSTANT  8
#define plfapivf_vwm2_ImageFormat4by3FullFormat  ((int)1)
#define plfapivf_vwm2_ImageFormat4by3FullFormat_CONSTANT  1
#define plfapivf_vwm2_ImageFormat4by3Use14by9  ((int)6)
#define plfapivf_vwm2_ImageFormat4by3Use14by9_CONSTANT  6
#define plfapivf_vwm2_ImageFormatInvalid  ((int)-1)
#define plfapivf_vwm2_ImageFormatInvalid_CONSTANT  -1
#define plfapivf_vwm2_ImageFormatMoreThan16by9Center  ((int)10)
#define plfapivf_vwm2_ImageFormatMoreThan16by9Center_CONSTANT  10
#define plfapivf_vwm2_ImageFormatUnknown  ((int)0)
#define plfapivf_vwm2_ImageFormatUnknown_CONSTANT  0
#define plfapivf_vwm2_MaxHorizontalAbsoluteShift  ((int)100)
#define plfapivf_vwm2_MaxHorizontalAbsoluteShift_CONSTANT  100
#define plfapivf_vwm2_MaxHorizontalShift  ((int)100)
#define plfapivf_vwm2_MaxHorizontalShift_CONSTANT  100
#define plfapivf_vwm2_MaxOverscan  ((int)10)
#define plfapivf_vwm2_MaxOverscan_CONSTANT  10
#define plfapivf_vwm2_MaxVerticalAbsoluteShift  ((int)100)
#define plfapivf_vwm2_MaxVerticalAbsoluteShift_CONSTANT  100
#define plfapivf_vwm2_MaxVerticalShift  ((int)100)
#define plfapivf_vwm2_MaxVerticalShift_CONSTANT  100
#define plfapivf_vwm2_MinHorizontalAbsoluteShift  ((int)-100)
#define plfapivf_vwm2_MinHorizontalAbsoluteShift_CONSTANT  -100
#define plfapivf_vwm2_MinHorizontalShift  ((int)-100)
#define plfapivf_vwm2_MinHorizontalShift_CONSTANT  -100
#define plfapivf_vwm2_MinOverscan  ((int)0)
#define plfapivf_vwm2_MinOverscan_CONSTANT  0
#define plfapivf_vwm2_MinVerticalAbsoluteShift  ((int)-100)
#define plfapivf_vwm2_MinVerticalAbsoluteShift_CONSTANT  -100
#define plfapivf_vwm2_MinVerticalShift  ((int)-100)
#define plfapivf_vwm2_MinVerticalShift_CONSTANT  -100
#define plfapivf_vwm2_MovieExpand14by9  ((int)2)
#define plfapivf_vwm2_MovieExpand14by9_CONSTANT  2
#define plfapivf_vwm2_MovieExpand16by9  ((int)3)
#define plfapivf_vwm2_MovieExpand16by9_CONSTANT  3
#define plfapivf_vwm2_NativeMode  ((int)9)
#define plfapivf_vwm2_NativeMode_CONSTANT  9
#define plfapivf_vwm2_OtherViewMode  ((int)15)
#define plfapivf_vwm2_OtherViewMode_CONSTANT  15
#define plfapivf_vwm2_Overscan  ((int)3)
#define plfapivf_vwm2_Overscan_CONSTANT  3
#define plfapivf_vwm2_PerfectAspectRatio  ((int)1)
#define plfapivf_vwm2_PerfectAspectRatio_CONSTANT  1
#define plfapivf_vwm2_ScreenFit  ((int)0)
#define plfapivf_vwm2_ScreenFit_CONSTANT  0
#define plfapivf_vwm2_SD  ((int)0)
#define plfapivf_vwm2_SD_CONSTANT  0
#define plfapivf_vwm2_SuperZoom  ((int)7)
#define plfapivf_vwm2_SuperZoom_CONSTANT  7
#define plfapivf_vwm2_UltraWide  ((int)10)
#define plfapivf_vwm2_UltraWide_CONSTANT  10
#define plfapivf_vwm2_UltraWide16by9  ((int)12)
#define plfapivf_vwm2_UltraWide16by9_CONSTANT  12
#define plfapivf_vwm2_UltraWideSubtitle  ((int)11)
#define plfapivf_vwm2_UltraWideSubtitle_CONSTANT  11
#define plfapivf_vwm2_UltraWideSuperZoomME16by9  ((int)14)
#define plfapivf_vwm2_UltraWideSuperZoomME16by9_CONSTANT  14
#define plfapivf_vwm2_UseAll  ((int)511)
#define plfapivf_vwm2_UseAll_CONSTANT  511
#define plfapivf_vwm2_UseBlackBars  ((int)32)
#define plfapivf_vwm2_UseBlackBars_CONSTANT  32
#define plfapivf_vwm2_UseBlackBarsWithSubtitleOffset  ((int)64)
#define plfapivf_vwm2_UseBlackBarsWithSubtitleOffset_CONSTANT  64
#define plfapivf_vwm2_UseDigitalMetaData  ((int)128)
#define plfapivf_vwm2_UseDigitalMetaData_CONSTANT  128
#define plfapivf_vwm2_UseInputResolution  ((int)256)
#define plfapivf_vwm2_UseInputResolution_CONSTANT  256
#define plfapivf_vwm2_UseNone  ((int)0)
#define plfapivf_vwm2_UseNone_CONSTANT  0
#define plfapivf_vwm2_UseP50Format  ((int)8)
#define plfapivf_vwm2_UseP50Format_CONSTANT  8
#define plfapivf_vwm2_UseP50Top  ((int)16)
#define plfapivf_vwm2_UseP50Top_CONSTANT  16
#define plfapivf_vwm2_UsePin8  ((int)4)
#define plfapivf_vwm2_UsePin8_CONSTANT  4
#define plfapivf_vwm2_UseWssFormat  ((int)1)
#define plfapivf_vwm2_UseWssFormat_CONSTANT  1
#define plfapivf_vwm2_UseWssTop  ((int)2)
#define plfapivf_vwm2_UseWssTop_CONSTANT  2
#define plfapivf_vwm2_VideoWindow  ((int)13)
#define plfapivf_vwm2_VideoWindow_CONSTANT  13
#define plfapivf_vwm2_ViewMode  ((int)0)
#define plfapivf_vwm2_ViewMode_CONSTANT  0
#define plfapivf_vwm2_ViewModeFirst  ((int)0)
#define plfapivf_vwm2_ViewModeFirst_CONSTANT  0
#define plfapivf_vwm2_ViewModeLast  ((int)15)
#define plfapivf_vwm2_ViewModeLast_CONSTANT  15
#define plfapivf_vwm2_WideScreen  ((int)1)
#define plfapivf_vwm2_WideScreen_CONSTANT  1
#define plfapivf_vwm2_WindowFormat15by9  ((int)1)
#define plfapivf_vwm2_WindowFormat15by9_CONSTANT  1
#define plfapivf_vwm2_WindowFormat16by9  ((int)2)
#define plfapivf_vwm2_WindowFormat16by9_CONSTANT  2
#define plfapivf_vwm2_WindowFormat4by3  ((int)0)
#define plfapivf_vwm2_WindowFormat4by3_CONSTANT  0
#define plfapivf_vwm2_ZoomMode  ((int)4)
#define plfapivf_vwm2_ZoomMode_CONSTANT  4

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapivf_demoN_OnDemoModeAllowedChanged( void );
extern void plfapivf_demoN_OnDemoModeChanged( void );
extern void plfapivf_demoN_OnDemoModeCompleted( void );
extern void plfapivf_pstN_OnAutoTvChanged( int mode );
extern void plfapivf_pstN_OnPictureStyleChanged( int picturestyle );
extern void plfapivf_sltN_OnProcessImageAllowedChanged( void );
extern void plfapivf_sltN_OnProcessImageCompleted( void );
extern void plfapivf_threeDfN_On3DFormatChanged( void );
extern void plfapivf_threeDfN_OnIsAllowed3DFormatChanged( void );
extern void plfapivf_threeDvN_On3DViewingChanged( void );
extern void plfapivf_threeDvN_OnIsAllowed3DViewingChanged( void );
extern void plfapivf_threeDvN_OnIsSupported3DViewingChanged( void );
extern void plfapivf_vdelayN_OnDelayChanged( void );
extern void plfapivf_vfitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids );
extern void plfapivf_vim3N_OnClearLcdAllowednessChanged( void );
extern void plfapivf_vim3N_OnClearLcdChanged( Bool onoff );
extern void plfapivf_vim3N_OnColorEnhancementChanged( int mode );
extern void plfapivf_vim3N_OnDigitalNaturalMotionAllowednessChanged( void );
extern void plfapivf_vim3N_OnDigitalNaturalMotionChanged( int mode );
extern void plfapivf_vim3N_OnDnrChanged( int mode );
extern void plfapivf_vim3N_OnDynamicBacklightAllowednessChanged( void );
extern void plfapivf_vim3N_OnDynamicBacklightChanged( int mode );
extern void plfapivf_vim3N_OnDynamicContrastChanged( int mode );
extern void plfapivf_vim3N_OnGammaChanged( int mode );
extern void plfapivf_vim3N_OnLightSensorAllowednessChanged( void );
extern void plfapivf_vim3N_OnLightSensorChanged( Bool onoff );
extern void plfapivf_vim3N_OnLtiChanged( Bool onoff );
extern void plfapivf_vim3N_OnMpegNoiseReductionChanged( int mode );
extern void plfapivf_vim3N_OnPcProcessingAllowednessChanged( void );
extern void plfapivf_vim3N_OnPcProcessingChanged( Bool onoff );
extern void plfapivf_vim3N_OnSharpnessChanged( int mode );
extern void plfapivf_vio2N_OnBrightnessChanged( void );
extern void plfapivf_vio2N_OnColorChanged( void );
extern void plfapivf_vio2N_OnContrastChanged( void );
extern void plfapivf_vio2N_OnFieldFrequencyChanged( void );
extern void plfapivf_vio2N_OnHueAllowedChanged( void );
extern void plfapivf_vio2N_OnHueChanged( void );
extern void plfapivf_vio2N_OnInterlacedChanged( void );
extern void plfapivf_vio2N_OnNumberOfLinesChanged( void );
extern void plfapivf_vio2N_OnTiltChanged( void );
extern void plfapivf_vio2N_OnTintChanged( void );
extern void plfapivf_vpN_OnViewPortAllowednessChanged( void );
extern void plfapivf_vpN_OnViewPortChanged( int ulx, int uly, int lrx, int lry, int width, int height );
extern void plfapivf_vwm2N_OnAutoDetectAllowedChanged( void );
extern void plfapivf_vwm2N_OnImageFormatChanged( void );
extern void plfapivf_vwm2N_OnIsAllowedViewModeChanged( void );
extern void plfapivf_vwm2N_OnIsOverscanAllowedChanged( void );
extern void plfapivf_vwm2N_OnOverscanChanged( void );
extern void plfapivf_vwm2N_OnShiftChanged( void );
extern void plfapivf_vwm2N_OnViewModeChanged( void );
extern void plfapivf_vwm2N_OnWindowFormatChanged( void );
extern void plfapivf_vwm2N_OnZoomChanged( void );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapivf_EnableNotification_demoN( void );
extern void plfapivf_DisableNotification_demoN( void );
extern void plfapivf_EnableNotification_pstN( void );
extern void plfapivf_DisableNotification_pstN( void );
extern void plfapivf_EnableNotification_sltN( void );
extern void plfapivf_DisableNotification_sltN( void );
extern void plfapivf_EnableNotification_threeDfN( void );
extern void plfapivf_DisableNotification_threeDfN( void );
extern void plfapivf_EnableNotification_threeDvN( void );
extern void plfapivf_DisableNotification_threeDvN( void );
extern void plfapivf_EnableNotification_vdelayN( void );
extern void plfapivf_DisableNotification_vdelayN( void );
extern void plfapivf_EnableNotification_vfitfN( void );
extern void plfapivf_DisableNotification_vfitfN( void );
extern void plfapivf_EnableNotification_vim3N( void );
extern void plfapivf_DisableNotification_vim3N( void );
extern void plfapivf_EnableNotification_vio2N( void );
extern void plfapivf_DisableNotification_vio2N( void );
extern void plfapivf_EnableNotification_vpN( void );
extern void plfapivf_DisableNotification_vpN( void );
extern void plfapivf_EnableNotification_vwm2N( void );
extern void plfapivf_DisableNotification_vwm2N( void );
extern void plfapivf_EnableNotification( int notificationId );
extern void plfapivf_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapivf_call_stubs */
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

extern void plfapivf_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapivf_RegisterHook_cprc( IpcHookFunction callback );
extern void plfapivf_RegisterHook_demo( IpcHookFunction callback );
extern void plfapivf_RegisterHook_errid( IpcHookFunction callback );
extern void plfapivf_RegisterHook_ppr( IpcHookFunction callback );
extern void plfapivf_RegisterHook_pst( IpcHookFunction callback );
extern void plfapivf_RegisterHook_slt( IpcHookFunction callback );
extern void plfapivf_RegisterHook_threeDf( IpcHookFunction callback );
extern void plfapivf_RegisterHook_threeDv( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vdelay( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vfitf( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vfitfid( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vim2( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vio2( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vp( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vwm2( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapivf_RegisterHook_demoN( IpcHookFunction callback );
extern void plfapivf_RegisterHook_pstN( IpcHookFunction callback );
extern void plfapivf_RegisterHook_sltN( IpcHookFunction callback );
extern void plfapivf_RegisterHook_threeDfN( IpcHookFunction callback );
extern void plfapivf_RegisterHook_threeDvN( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vdelayN( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vfitfN( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vim3N( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vio2N( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vpN( IpcHookFunction callback );
extern void plfapivf_RegisterHook_vwm2N( IpcHookFunction callback );

#endif /* _PLFAPIVF_H_ */

