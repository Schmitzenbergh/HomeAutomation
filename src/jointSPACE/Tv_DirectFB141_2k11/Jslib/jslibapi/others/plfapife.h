
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


#if !defined(_PLFAPIFE_H_)
#define _PLFAPIFE_H_

#if !defined(_PLFAPIFE_DD_)
#include "plfapife_types.h"
#endif

extern int  plfapife_Init( int arg, char * argv[] );
extern void plfapife_Exit( void );

/*  Symbols for plfapifeMethodID */
extern int idaclipAddData;  /* 0 */
extern int idaclipContinue;  /* 1 */
extern int idaclipEnableClipPlay;  /* 2 */
extern int idaclipGetAvailableNrBuffers;  /* 3 */
extern int idaclipGetClipPlayEnabled;  /* 4 */
extern int idaclipGetMaxNrBuffers;  /* 5 */
extern int idaclipGetPauseSupp;  /* 6 */
extern int idaclipGetState;  /* 7 */
extern int idaclipPause;  /* 8 */
extern int idaclipStart;  /* 9 */
extern int idaclipStop;  /* 10 */
extern int idaclipexAddData;  /* 11 */
extern int idaclipexContinue;  /* 12 */
extern int idaclipexEnableClipPlay;  /* 13 */
extern int idaclipexEnableSeek;  /* 14 */
extern int idaclipexGetAvailableNrBuffers;  /* 15 */
extern int idaclipexGetClipPlayEnabled;  /* 16 */
extern int idaclipexGetMaxNrBuffers;  /* 17 */
extern int idaclipexGetPauseSupp;  /* 18 */
extern int idaclipexGetSeekEnabled;  /* 19 */
extern int idaclipexGetState;  /* 20 */
extern int idaclipexGetTotalSeekTime;  /* 21 */
extern int idaclipexPause;  /* 22 */
extern int idaclipexSeek;  /* 23 */
extern int idaclipexStart;  /* 24 */
extern int idaclipexStop;  /* 25 */
extern int idapitestStartTest;  /* 26 */
extern int idapitestStopTest;  /* 27 */
extern int idassmGetMeasValid;  /* 28 */
extern int idassmGetSigStrength;  /* 29 */
extern int idassmGetSigStrengthRange;  /* 30 */
extern int idassmStart;  /* 31 */
extern int idassmStop;  /* 32 */
extern int idchantabFreq2Chan;  /* 33 */
extern int idchantabGetCarrierFreq;  /* 34 */
extern int idchantabGetFirstChan;  /* 35 */
extern int idchantabGetFirstTable;  /* 36 */
extern int idchantabGetIsChan;  /* 37 */
extern int idchantabGetLastChan;  /* 38 */
extern int idchantabGetLowerFreq;  /* 39 */
extern int idchantabGetNextChan;  /* 40 */
extern int idchantabGetNextTable;  /* 41 */
extern int idchantabGetNextValidChan;  /* 42 */
extern int idchantabGetPrevChan;  /* 43 */
extern int idchantabGetPrevValidChan;  /* 44 */
extern int idchantabGetSegmentBoundaries;  /* 45 */
extern int idchantabGetTable;  /* 46 */
extern int idchantabGetTableSupp;  /* 47 */
extern int idchantabGetUpperFreq;  /* 48 */
extern int idchantabSetTable;  /* 49 */
extern int idchdecGetActualConstellation;  /* 50 */
extern int idchdecGetActualIqMode;  /* 51 */
extern int idchdecGetBer;  /* 52 */
extern int idchdecGetBerThreshold;  /* 53 */
extern int idchdecGetBerThresholdRange;  /* 54 */
extern int idchdecGetCarrierPresent;  /* 55 */
extern int idchdecGetConstellation;  /* 56 */
extern int idchdecGetFrequencyError;  /* 57 */
extern int idchdecGetFrequencyErrorSupp;  /* 58 */
extern int idchdecGetIqMode;  /* 59 */
extern int idchdecGetSuppConstellations;  /* 60 */
extern int idchdecGetSuppIqModes;  /* 61 */
extern int idchdecGetSymbolError;  /* 62 */
extern int idchdecGetSymbolErrorSupp;  /* 63 */
extern int idchdecGetTimeError;  /* 64 */
extern int idchdecGetTimeErrorSupp;  /* 65 */
extern int idchdecSetBerThreshold;  /* 66 */
extern int idchdecSetConstellation;  /* 67 */
extern int idchdecSetFrequencyError;  /* 68 */
extern int idchdecSetIqMode;  /* 69 */
extern int idchdecSetSymbolError;  /* 70 */
extern int idchdecSetTimeError;  /* 71 */
extern int idchdec2GetActualConstellation;  /* 72 */
extern int idchdec2GetActualIqMode;  /* 73 */
extern int idchdec2GetBer;  /* 74 */
extern int idchdec2GetBerThreshold;  /* 75 */
extern int idchdec2GetBerThresholdRange;  /* 76 */
extern int idchdec2GetCarrierPresent;  /* 77 */
extern int idchdec2GetConstellation;  /* 78 */
extern int idchdec2GetFrequencyError;  /* 79 */
extern int idchdec2GetFrequencyErrorSupp;  /* 80 */
extern int idchdec2GetIqMode;  /* 81 */
extern int idchdec2GetSuppConstellations;  /* 82 */
extern int idchdec2GetSuppIqModes;  /* 83 */
extern int idchdec2GetSymbolError;  /* 84 */
extern int idchdec2GetSymbolErrorSupp;  /* 85 */
extern int idchdec2GetTimeError;  /* 86 */
extern int idchdec2GetTimeErrorSupp;  /* 87 */
extern int idchdec2SetBerThreshold;  /* 88 */
extern int idchdec2SetConstellation;  /* 89 */
extern int idchdec2SetFrequencyError;  /* 90 */
extern int idchdec2SetIqMode;  /* 91 */
extern int idchdec2SetSymbolError;  /* 92 */
extern int idchdec2SetTimeError;  /* 93 */
extern int idchdecdvbcGetActualCodeRate;  /* 94 */
extern int idchdecdvbcGetFreqStep;  /* 95 */
extern int idchdecdvbcGetSymbolRate;  /* 96 */
extern int idchdecdvbcGetSymbolRateRange;  /* 97 */
extern int idchdecdvbcResetFreqStep;  /* 98 */
extern int idchdecdvbcSetFreqStep;  /* 99 */
extern int idchdecdvbcSetSearchRates;  /* 100 */
extern int idchdecdvbcSetSymbolRate;  /* 101 */
extern int idchdecdvbtGetActualChanBandwidth;  /* 102 */
extern int idchdecdvbtGetActualCodeRates;  /* 103 */
extern int idchdecdvbtGetActualFrequencyOffset;  /* 104 */
extern int idchdecdvbtGetActualGuardInterval;  /* 105 */
extern int idchdecdvbtGetActualHierarchyMode;  /* 106 */
extern int idchdecdvbtGetActualTxMode;  /* 107 */
extern int idchdecdvbtGetChanBandwidth;  /* 108 */
extern int idchdecdvbtGetChannelInformation;  /* 109 */
extern int idchdecdvbtGetCodeRates;  /* 110 */
extern int idchdecdvbtGetFrequencyOffset;  /* 111 */
extern int idchdecdvbtGetGuardInterval;  /* 112 */
extern int idchdecdvbtGetHierarchyMode;  /* 113 */
extern int idchdecdvbtGetStreamPriority;  /* 114 */
extern int idchdecdvbtGetSuppChanBandwidths;  /* 115 */
extern int idchdecdvbtGetSuppCodeRates;  /* 116 */
extern int idchdecdvbtGetSuppFrequencyOffsets;  /* 117 */
extern int idchdecdvbtGetSuppGuardIntervals;  /* 118 */
extern int idchdecdvbtGetSuppHierarchyModes;  /* 119 */
extern int idchdecdvbtGetSuppTxModes;  /* 120 */
extern int idchdecdvbtGetTpsCellid;  /* 121 */
extern int idchdecdvbtGetTxMode;  /* 122 */
extern int idchdecdvbtSetChanBandwidth;  /* 123 */
extern int idchdecdvbtSetChannelInformation;  /* 124 */
extern int idchdecdvbtSetCodeRates;  /* 125 */
extern int idchdecdvbtSetFrequencyOffset;  /* 126 */
extern int idchdecdvbtSetGuardInterval;  /* 127 */
extern int idchdecdvbtSetHierarchyMode;  /* 128 */
extern int idchdecdvbtSetStreamPriority;  /* 129 */
extern int idchdecdvbtSetTxMode;  /* 130 */
extern int idchdecisdbtGetActualCodeRates;  /* 131 */
extern int idchdecisdbtGetActualConstellation;  /* 132 */
extern int idchdecisdbtGetActualGuardInterval;  /* 133 */
extern int idchdecisdbtGetChannelInformation;  /* 134 */
extern int idchdecisdbtGetCodeRates;  /* 135 */
extern int idchdecisdbtGetConstellation;  /* 136 */
extern int idchdecisdbtGetGuardInterval;  /* 137 */
extern int idchdecisdbtGetLayer;  /* 138 */
extern int idchdecisdbtGetSuppCodeRates;  /* 139 */
extern int idchdecisdbtGetSuppConstellations;  /* 140 */
extern int idchdecisdbtGetSuppGuardIntervals;  /* 141 */
extern int idchdecisdbtGetSupportedLayers;  /* 142 */
extern int idchdecisdbtSetChannelInformation;  /* 143 */
extern int idchdecisdbtSetCodeRates;  /* 144 */
extern int idchdecisdbtSetConstellation;  /* 145 */
extern int idchdecisdbtSetGuardInterval;  /* 146 */
extern int idchdecisdbtSetLayer;  /* 147 */
extern int idchdecisdbt2GetActualBroadcastType;  /* 148 */
extern int idchdecisdbt2GetActualCodeRates;  /* 149 */
extern int idchdecisdbt2GetActualConstellation;  /* 150 */
extern int idchdecisdbt2GetActualGuardInterval;  /* 151 */
extern int idchdecisdbt2GetActualNumberofSegments;  /* 152 */
extern int idchdecisdbt2GetActualTimeInterleave;  /* 153 */
extern int idchdecisdbt2GetActualTxMode;  /* 154 */
extern int idchdecisdbt2GetBroadcastType;  /* 155 */
extern int idchdecisdbt2GetChannelInformation;  /* 156 */
extern int idchdecisdbt2GetCodeRates;  /* 157 */
extern int idchdecisdbt2GetConstellation;  /* 158 */
extern int idchdecisdbt2GetGuardInterval;  /* 159 */
extern int idchdecisdbt2GetLayer;  /* 160 */
extern int idchdecisdbt2GetNumberofSegments;  /* 161 */
extern int idchdecisdbt2GetSuppBroadcastType;  /* 162 */
extern int idchdecisdbt2GetSuppCodeRates;  /* 163 */
extern int idchdecisdbt2GetSuppConstellations;  /* 164 */
extern int idchdecisdbt2GetSuppGuardIntervals;  /* 165 */
extern int idchdecisdbt2GetSuppNumberofSegments;  /* 166 */
extern int idchdecisdbt2GetSupportedLayers;  /* 167 */
extern int idchdecisdbt2GetSuppTimeInterleave;  /* 168 */
extern int idchdecisdbt2GetSuppTxMode;  /* 169 */
extern int idchdecisdbt2GetTimeInterleave;  /* 170 */
extern int idchdecisdbt2GetTxMode;  /* 171 */
extern int idchdecisdbt2SetBroadcastType;  /* 172 */
extern int idchdecisdbt2SetChannelInformation;  /* 173 */
extern int idchdecisdbt2SetCodeRates;  /* 174 */
extern int idchdecisdbt2SetConstellation;  /* 175 */
extern int idchdecisdbt2SetGuardInterval;  /* 176 */
extern int idchdecisdbt2SetLayer;  /* 177 */
extern int idchdecisdbt2SetNumberofSegments;  /* 178 */
extern int idchdecisdbt2SetTimeInterleave;  /* 179 */
extern int idchdecisdbt2SetTxMode;  /* 180 */
extern int idchdecselGetChanDec;  /* 181 */
extern int idchdecselIsChanDecSupported;  /* 182 */
extern int idchdecselSetChanDec;  /* 183 */
extern int idciplusaiAI_SelectApplication;  /* 184 */
extern int idciplusammiAMMI_Abort;  /* 185 */
extern int idciplusammiAMMI_AbortAck;  /* 186 */
extern int idciplusammiAMMI_Close;  /* 187 */
extern int idciplusammiAMMI_Request;  /* 188 */
extern int idciplusammiAMMI_StartAck;  /* 189 */
extern int idcipluscaCa_NotifyPMT;  /* 190 */
extern int idciplusccCC_GetBrandID;  /* 191 */
extern int idciplushcHC_Release;  /* 192 */
extern int idciplushlcHLC_SetCountry;  /* 193 */
extern int idciplushlcHLC_SetLanguage;  /* 194 */
extern int idciplusinitOnRequestActivate;  /* 195 */
extern int idciplusinitOnRequestEnd;  /* 196 */
extern int idciplusinitOnRequestInit;  /* 197 */
extern int idciplusinitResetHard;  /* 198 */
extern int idciplusinitResetSoft;  /* 199 */
extern int idciplusinitSwitchTS;  /* 200 */
extern int idciplusmmiMMI_Close;  /* 201 */
extern int idciplusmmiMMI_ResponseEnq;  /* 202 */
extern int idciplusmmiMMI_ResponseList;  /* 203 */
extern int idciplusmmiMMI_ResponseMenu;  /* 204 */
extern int idciplusstatusGetStatus;  /* 205 */
extern int idciplusupgrUPGR_UpgradeReply;  /* 206 */
extern int idcolColorSystemSupported;  /* 207 */
extern int idcolColorSystemSupportedEx;  /* 208 */
extern int idcolCombFilterActive;  /* 209 */
extern int idcolCombFilterEnabled;  /* 210 */
extern int idcolCombFilterSupported;  /* 211 */
extern int idcolEnableCombFilter;  /* 212 */
extern int idcolForceColorSystem;  /* 213 */
extern int idcolForceColorSystemEx;  /* 214 */
extern int idcolGetCarrierFrequency;  /* 215 */
extern int idcolGetColorSystem;  /* 216 */
extern int idcolGetForcedCarrierFrequency;  /* 217 */
extern int idcolGetForcedColorSystem;  /* 218 */
extern int idcolGetSuggestedCarrierFrequency;  /* 219 */
extern int idcolGetSuggestedColorSystem;  /* 220 */
extern int idcolSuggestColorSystem;  /* 221 */
extern int idcolSuggestColorSystemEx;  /* 222 */
extern int iddiseqSend;  /* 223 */
extern int iddiseqSendMsg;  /* 224 */
extern int iddvbsAttemptLock;  /* 225 */
extern int iddvbsGetParams;  /* 226 */
extern int idfeitfGetAvailableInterfaces;  /* 227 */
extern int idgdripAddData;  /* 228 */
extern int idgdripGetAvailableNrBuffers;  /* 229 */
extern int idgdripGetBufAlignment;  /* 230 */
extern int idgdripGetMaxNrBuffers;  /* 231 */
extern int idgdripGetOutputFrame;  /* 232 */
extern int idgdripGetScalingRestrictions;  /* 233 */
extern int idgdripGetState;  /* 234 */
extern int idgdripGetSuppFormatClasses;  /* 235 */
extern int idgdripGetSuppFormatTypes;  /* 236 */
extern int idgdripStart;  /* 237 */
extern int idgdripStop;  /* 238 */
extern int idhsysGetSoundSystem;  /* 239 */
extern int idprsFillPreset;  /* 240 */
extern int idprsGetAttribute;  /* 241 */
extern int idprsGetMaxPreset;  /* 242 */
extern int idprsGetMinPreset;  /* 243 */
extern int idprsGetPreset;  /* 244 */
extern int idprsInitPreset;  /* 245 */
extern int idprsLoadAttribute;  /* 246 */
extern int idprsLoadPreset;  /* 247 */
extern int idprsSetAttribute;  /* 248 */
extern int idprsSetPreset;  /* 249 */
extern int idprsStoreAttribute;  /* 250 */
extern int idprsStoreAttributeSupported;  /* 251 */
extern int idprsStorePreset;  /* 252 */
extern int idprsStorePresetSupported;  /* 253 */
extern int idprsSwapPreset;  /* 254 */
extern int idqssmGetMeasValid;  /* 255 */
extern int idqssmGetSigStrength;  /* 256 */
extern int idqssmGetSigStrengthRange;  /* 257 */
extern int idqssmStart;  /* 258 */
extern int idqssmStop;  /* 259 */
extern int idrfampGet;  /* 260 */
extern int idrfampGetRange;  /* 261 */
extern int idrfampSet;  /* 262 */
extern int idsadGetADRouting;  /* 263 */
extern int idsadGetVolume;  /* 264 */
extern int idsadGetVolumeMax;  /* 265 */
extern int idsadGetVolumeMin;  /* 266 */
extern int idsadIsADRoutingAllowed;  /* 267 */
extern int idsadIsADRoutingSupported;  /* 268 */
extern int idsadIsVolumeControlAllowed;  /* 269 */
extern int idsadIsVolumeControlSupported;  /* 270 */
extern int idsadSetADRouting;  /* 271 */
extern int idsadSetVolume;  /* 272 */
extern int idsiqGetActualNoiseLevel;  /* 273 */
extern int idsndAllowSoundSystem;  /* 274 */
extern int idsndGetAllowedSoundSystem;  /* 275 */
extern int idsocFrontChannels;  /* 276 */
extern int idsocGetChannel;  /* 277 */
extern int idsocIsDigital;  /* 278 */
extern int idsocIsDolbyProLogic;  /* 279 */
extern int idsocIsMono;  /* 280 */
extern int idsocIsRelated;  /* 281 */
extern int idsocIsSecondLanguage;  /* 282 */
extern int idsocIsStereo;  /* 283 */
extern int idsocLfeChannels;  /* 284 */
extern int idsocRearChannels;  /* 285 */
extern int idsocSetChannel;  /* 286 */
extern int idssmGetMeasValid;  /* 287 */
extern int idssmGetSigStrength;  /* 288 */
extern int idssmGetSigStrengthRange;  /* 289 */
extern int idssmStart;  /* 290 */
extern int idssmStop;  /* 291 */
extern int idssysGetSoundSystem;  /* 292 */
extern int idstcdecActivateAlarm;  /* 293 */
extern int idstcdecAllocateAlarm;  /* 294 */
extern int idstcdecCancelAlarm;  /* 295 */
extern int idstcdecGetAvailableNrAlarms;  /* 296 */
extern int idstcdecGetMaxNrAlarms;  /* 297 */
extern int idstcdecGetTime;  /* 298 */
extern int idtmcGetTxtMode;  /* 299 */
extern int idtmcSetTxtMode;  /* 300 */
extern int idtsdmxCancelFilter;  /* 301 */
extern int idtsdmxCancelListFilter;  /* 302 */
extern int idtsdmxCancelPes;  /* 303 */
extern int idtsdmxFreeListBuffer;  /* 304 */
extern int idtsdmxFreePesBuffer;  /* 305 */
extern int idtsdmxFreeSectionBuffer;  /* 306 */
extern int idtsdmxGetAudioDescriptivePid;  /* 307 */
extern int idtsdmxGetAudioPid;  /* 308 */
extern int idtsdmxGetAudioStreamType;  /* 309 */
extern int idtsdmxGetPcrPid;  /* 310 */
extern int idtsdmxGetPcrStreamType;  /* 311 */
extern int idtsdmxGetScramblingStatus;  /* 312 */
extern int idtsdmxGetVideoPid;  /* 313 */
extern int idtsdmxGetVideoStreamType;  /* 314 */
extern int idtsdmxIsAudioStreamTypeSupported;  /* 315 */
extern int idtsdmxIsPcrStreamTypeSupported;  /* 316 */
extern int idtsdmxIsRequestAllowed;  /* 317 */
extern int idtsdmxIsVideoStreamTypeSupported;  /* 318 */
extern int idtsdmxRequestFilter;  /* 319 */
extern int idtsdmxRequestListFilter;  /* 320 */
extern int idtsdmxRequestPes;  /* 321 */
extern int idtsdmxSetAudioDescriptivePid;  /* 322 */
extern int idtsdmxSetAudioPid;  /* 323 */
extern int idtsdmxSetAudioStreamType;  /* 324 */
extern int idtsdmxSetPcrPid;  /* 325 */
extern int idtsdmxSetPcrStreamType;  /* 326 */
extern int idtsdmxSetVideoPid;  /* 327 */
extern int idtsdmxSetVideoStreamType;  /* 328 */
extern int idtsdmxStopAudioDescriptivePid;  /* 329 */
extern int idtsdmxStopAudioPid;  /* 330 */
extern int idtsdmxStopPcrPid;  /* 331 */
extern int idtsdmxStopVideoPid;  /* 332 */
extern int idtsdmxUpdateFilter;  /* 333 */
extern int idtsdmxUpdateListFilter;  /* 334 */
extern int idtsdmxexCancelFilter;  /* 335 */
extern int idtsdmxexCancelListFilter;  /* 336 */
extern int idtsdmxexCancelPes;  /* 337 */
extern int idtsdmxexCancelPesList;  /* 338 */
extern int idtsdmxexFreeListBuffer;  /* 339 */
extern int idtsdmxexFreePesBuffer;  /* 340 */
extern int idtsdmxexFreePesListBuffer;  /* 341 */
extern int idtsdmxexFreeSectionBuffer;  /* 342 */
extern int idtsdmxexGetAudioDescriptivePid;  /* 343 */
extern int idtsdmxexGetAudioPid;  /* 344 */
extern int idtsdmxexGetAudioStreamType;  /* 345 */
extern int idtsdmxexGetPcrPid;  /* 346 */
extern int idtsdmxexGetPcrStreamType;  /* 347 */
extern int idtsdmxexGetScramblingStatus;  /* 348 */
extern int idtsdmxexGetVideoPid;  /* 349 */
extern int idtsdmxexGetVideoStreamType;  /* 350 */
extern int idtsdmxexIsAudioStreamTypeSupported;  /* 351 */
extern int idtsdmxexIsPcrStreamTypeSupported;  /* 352 */
extern int idtsdmxexIsRequestAllowed;  /* 353 */
extern int idtsdmxexIsVideoStreamTypeSupported;  /* 354 */
extern int idtsdmxexRequestFilter;  /* 355 */
extern int idtsdmxexRequestListFilter;  /* 356 */
extern int idtsdmxexRequestPes;  /* 357 */
extern int idtsdmxexRequestPesList;  /* 358 */
extern int idtsdmxexSetAudioDescriptivePid;  /* 359 */
extern int idtsdmxexSetAudioPid;  /* 360 */
extern int idtsdmxexSetAudioStreamType;  /* 361 */
extern int idtsdmxexSetPcrPid;  /* 362 */
extern int idtsdmxexSetPcrStreamType;  /* 363 */
extern int idtsdmxexSetVideoPid;  /* 364 */
extern int idtsdmxexSetVideoStreamType;  /* 365 */
extern int idtsdmxexStopAudioDescriptivePid;  /* 366 */
extern int idtsdmxexStopAudioPid;  /* 367 */
extern int idtsdmxexStopPcrPid;  /* 368 */
extern int idtsdmxexStopVideoPid;  /* 369 */
extern int idtsdmxexUpdateFilter;  /* 370 */
extern int idtsdmxexUpdateListFilter;  /* 371 */
extern int idtunEnableAfc;  /* 372 */
extern int idtunGetAfcEnabled;  /* 373 */
extern int idtunGetAfcSupp;  /* 374 */
extern int idtunGetAfcValue;  /* 375 */
extern int idtunGetChan;  /* 376 */
extern int idtunGetChanOffset;  /* 377 */
extern int idtunGetChanOffsetRange;  /* 378 */
extern int idtunGetFreq;  /* 379 */
extern int idtunGetFreqRange;  /* 380 */
extern int idtunGetSearchMode;  /* 381 */
extern int idtunGetSearchModeSupp;  /* 382 */
extern int idtunGetSearchState;  /* 383 */
extern int idtunGetStationPresent;  /* 384 */
extern int idtunGetTvSystem;  /* 385 */
extern int idtunGetTvSystemSupp;  /* 386 */
extern int idtunSetChan;  /* 387 */
extern int idtunSetFreq;  /* 388 */
extern int idtunSetTunerGain;  /* 389 */
extern int idtunSetTvSystem;  /* 390 */
extern int idtunStartSearch;  /* 391 */
extern int idtunStopSearch;  /* 392 */
extern int idvbiinsInsertWss;  /* 393 */
extern int idvbislEnableAutoSlicing;  /* 394 */
extern int idvbislGetAutoSlicingEnabled;  /* 395 */
extern int idvbislGetVbiLines;  /* 396 */
extern int idvbislSetSlicermode;  /* 397 */
extern int idvbislSetVbiLines;  /* 398 */
extern int idvclipAddData;  /* 399 */
extern int idvclipEnableClipPlay;  /* 400 */
extern int idvclipGetAvailableNrBuffers;  /* 401 */
extern int idvclipGetClipPlayEnabled;  /* 402 */
extern int idvclipGetMaxNrBuffers;  /* 403 */
extern int idvclipGetState;  /* 404 */
extern int idvclipStart;  /* 405 */
extern int idvclipStop;  /* 406 */
extern int idvclipexAddData;  /* 407 */
extern int idvclipexEnableClipPlay;  /* 408 */
extern int idvclipexEnableSeek;  /* 409 */
extern int idvclipexGetAvailableNrBuffers;  /* 410 */
extern int idvclipexGetClipPlayEnabled;  /* 411 */
extern int idvclipexGetMaxNrBuffers;  /* 412 */
extern int idvclipexGetSeekEnabled;  /* 413 */
extern int idvclipexGetState;  /* 414 */
extern int idvclipexGetTotalSeekTime;  /* 415 */
extern int idvclipexPause;  /* 416 */
extern int idvclipexResume;  /* 417 */
extern int idvclipexSeek;  /* 418 */
extern int idvclipexStart;  /* 419 */
extern int idvclipexStop;  /* 420 */
extern int idvfrFreezeAllowed;  /* 421 */
extern int idvfrFreezeSupported;  /* 422 */
extern int idvfrGetStrobe;  /* 423 */
extern int idvfrIsFrozen;  /* 424 */
extern int idvfrSetFreeze;  /* 425 */
extern int idvfrSetStrobe;  /* 426 */
extern int idvfrStrobeAllowed;  /* 427 */
extern int idvfrStrobeSupported;  /* 428 */
extern int idvipGetFieldFrequency;  /* 429 */
extern int idvipGetImageFormat;  /* 430 */
extern int idvipGetInterlace;  /* 431 */
extern int idvipGetMacroVisionType;  /* 432 */
extern int idvipGetNumberOfFrameLines;  /* 433 */
extern int idvipGetNumberOfVisibleLines;  /* 434 */
extern int idvipGetNumberOfVisiblePixels;  /* 435 */
extern int idvipGetSignalPresent;  /* 436 */
extern int idvipGetVideoCoding;  /* 437 */
extern int idvipGetVideoDetectionSensitivity;  /* 438 */
extern int idvipGetVideoPresent;  /* 439 */
extern int idvipGetVideoProtection;  /* 440 */
extern int idvipIsFilmMode;  /* 441 */
extern int idvipIsFromVcr;  /* 442 */
extern int idvipIsPCFormat;  /* 443 */
extern int idvipIsVideoDetectionSensitivitySupported;  /* 444 */
extern int idvipSetVideoDetectionSensitivity;  /* 445 */
extern int plfapifeMethodID_Last;  /* 446 */

/*  Symbols for plfapifeNotificationID */
extern int idaclipexNOnBufferAvailable;  /* 0 */
extern int idaclipexNOnEndOfData;  /* 1 */
extern int idaclipexNOnPaused;  /* 2 */
extern int idaclipexNOnSeekCompleted;  /* 3 */
extern int idaclipexNOnStarted;  /* 4 */
extern int idaclipexNOnStopped;  /* 5 */
extern int idaclipexNOnTotalSeekTimeChanged;  /* 6 */
extern int idaclipNOnBufferAvailable;  /* 7 */
extern int idaclipNOnEndOfData;  /* 8 */
extern int idaclipNOnPaused;  /* 9 */
extern int idaclipNOnStarted;  /* 10 */
extern int idaclipNOnStopped;  /* 11 */
extern int idapitestntfTestResult;  /* 12 */
extern int idassmNOnMeasAborted;  /* 13 */
extern int idassmNOnMeasReady;  /* 14 */
extern int idchdec2NOnBerThresholdCrossed;  /* 15 */
extern int idchdec2NOnCarrierPresentChanged;  /* 16 */
extern int idchdec2NOnChanBandwidthDetected;  /* 17 */
extern int idchdec2NOnCodeRateDetected;  /* 18 */
extern int idchdec2NOnConstellationDetected;  /* 19 */
extern int idchdec2NOnGuardIntervalDetected;  /* 20 */
extern int idchdec2NOnHierarchyModeDetected;  /* 21 */
extern int idchdec2NOnIqModeDetected;  /* 22 */
extern int idchdec2NOnTxModeDetected;  /* 23 */
extern int idchdecNOnBerThresholdCrossed;  /* 24 */
extern int idchdecNOnCarrierPresentChanged;  /* 25 */
extern int idchdecNOnChanBandwidthDetected;  /* 26 */
extern int idchdecNOnCodeRateDetected;  /* 27 */
extern int idchdecNOnConstellationDetected;  /* 28 */
extern int idchdecNOnGuardIntervalDetected;  /* 29 */
extern int idchdecNOnHierarchyModeDetected;  /* 30 */
extern int idchdecNOnIqModeDetected;  /* 31 */
extern int idchdecNOnTxModeDetected;  /* 32 */
extern int idciplusaintfAI_ApplicationList;  /* 33 */
extern int idciplusammintfAMMI_AbortRequest;  /* 34 */
extern int idciplusammintfAMMI_AckAbort;  /* 35 */
extern int idciplusammintfAMMI_AckRequest;  /* 36 */
extern int idciplusammintfAMMI_Close;  /* 37 */
extern int idciplusammintfAMMI_Open;  /* 38 */
extern int idciplusammintfAMMI_StartRequest;  /* 39 */
extern int idcipluscantfCa_ListCaSystemId;  /* 40 */
extern int idcipluscantfCa_Update;  /* 41 */
extern int idciplusccntfCC_OnBrandID;  /* 42 */
extern int idciplushcntfHC_ClearRequest;  /* 43 */
extern int idciplushcntfHC_ReplaceRequest;  /* 44 */
extern int idciplushcntfHC_TuneRequest;  /* 45 */
extern int idciplusinitntfReturnActivate;  /* 46 */
extern int idciplusinitntfReturnEnd;  /* 47 */
extern int idciplusinitntfReturnInit;  /* 48 */
extern int idciplusmmintfMMI_Close;  /* 49 */
extern int idciplusmmintfMMI_CmdEnquery;  /* 50 */
extern int idciplusmmintfMMI_CmdList;  /* 51 */
extern int idciplusmmintfMMI_CmdMenu;  /* 52 */
extern int idciplusmmintfMMI_Open;  /* 53 */
extern int idciplusstatusntfOnStatus;  /* 54 */
extern int idciplusupgrntfUPGR_Close;  /* 55 */
extern int idciplusupgrntfUPGR_Open;  /* 56 */
extern int idciplusupgrntfUPGR_UpgradeComplete;  /* 57 */
extern int idciplusupgrntfUPGR_UpgradeProgress;  /* 58 */
extern int idciplusupgrntfUPGR_UpgradeRequest;  /* 59 */
extern int idcolNOnColorSystemChanged;  /* 60 */
extern int idcolNOnCombFilterActiveChanged;  /* 61 */
extern int iddiseqNOnMsgSent;  /* 62 */
extern int iddvbsNOnLockChanged;  /* 63 */
extern int idfeitfNOnAvailabilityChanged;  /* 64 */
extern int idgdripNOnBufferAvailable;  /* 65 */
extern int idgdripNOnEndOfData;  /* 66 */
extern int idgdripNOnFrameDecoded;  /* 67 */
extern int idgdripNOnStarted;  /* 68 */
extern int idgdripNOnStopped;  /* 69 */
extern int idhsysNOnSoundSystemChanged;  /* 70 */
extern int idqssmNOnMeasAborted;  /* 71 */
extern int idqssmNOnMeasReady;  /* 72 */
extern int idsocNOnChannelChanged;  /* 73 */
extern int idsocNOnSoundPropertiesChanged;  /* 74 */
extern int idssmNOnMeasAborted;  /* 75 */
extern int idssmNOnMeasReady;  /* 76 */
extern int idssysNOnSoundSystemChanged;  /* 77 */
extern int idstcdecNOnCancelled;  /* 78 */
extern int idstcdecNOnDiscontinuity;  /* 79 */
extern int idstcdecNOnExpired;  /* 80 */
extern int idstcdecNOnLocked;  /* 81 */
extern int idstcdecNOnUnlocked;  /* 82 */
extern int idtsdmxexNOnAudioDescriptivePidStopped;  /* 83 */
extern int idtsdmxexNOnAudioPidStopped;  /* 84 */
extern int idtsdmxexNOnBufferOverflow;  /* 85 */
extern int idtsdmxexNOnPcrPidStopped;  /* 86 */
extern int idtsdmxexNOnPesArrived;  /* 87 */
extern int idtsdmxexNOnPesCancelled;  /* 88 */
extern int idtsdmxexNOnPesListArrived;  /* 89 */
extern int idtsdmxexNOnPesListCancelled;  /* 90 */
extern int idtsdmxexNOnRequestAllowed;  /* 91 */
extern int idtsdmxexNOnRequestCancelled;  /* 92 */
extern int idtsdmxexNOnRequestListCancelled;  /* 93 */
extern int idtsdmxexNOnRequestNotAllowed;  /* 94 */
extern int idtsdmxexNOnScramblingStatusChanged;  /* 95 */
extern int idtsdmxexNOnSectionArrived;  /* 96 */
extern int idtsdmxexNOnSectionListArrived;  /* 97 */
extern int idtsdmxexNOnSyncLock;  /* 98 */
extern int idtsdmxexNOnSyncLost;  /* 99 */
extern int idtsdmxexNOnVideoPidStopped;  /* 100 */
extern int idtsdmxNOnAudioDescriptivePidStopped;  /* 101 */
extern int idtsdmxNOnAudioPidStopped;  /* 102 */
extern int idtsdmxNOnBufferOverflow;  /* 103 */
extern int idtsdmxNOnPcrPidStopped;  /* 104 */
extern int idtsdmxNOnPesArrived;  /* 105 */
extern int idtsdmxNOnPesCancelled;  /* 106 */
extern int idtsdmxNOnRequestAllowed;  /* 107 */
extern int idtsdmxNOnRequestCancelled;  /* 108 */
extern int idtsdmxNOnRequestListCancelled;  /* 109 */
extern int idtsdmxNOnRequestNotAllowed;  /* 110 */
extern int idtsdmxNOnScramblingStatusChanged;  /* 111 */
extern int idtsdmxNOnSectionArrived;  /* 112 */
extern int idtsdmxNOnSectionListArrived;  /* 113 */
extern int idtsdmxNOnSyncLock;  /* 114 */
extern int idtsdmxNOnSyncLost;  /* 115 */
extern int idtsdmxNOnVideoPidStopped;  /* 116 */
extern int idtunNOnAfcFreqChanged;  /* 117 */
extern int idtunNOnAfcLimitReached;  /* 118 */
extern int idtunNOnAfcModeChanged;  /* 119 */
extern int idtunNOnSearchInProgress;  /* 120 */
extern int idtunNOnSearchStateChanged;  /* 121 */
extern int idtunNOnStationFound;  /* 122 */
extern int idtunNOnStationNotFound;  /* 123 */
extern int idtunNOnTvSystemDetected;  /* 124 */
extern int idvbislNOnCcData;  /* 125 */
extern int idvbislNOnCcNoData;  /* 126 */
extern int idvbislNOnCgmsData;  /* 127 */
extern int idvbislNOnCgmsNoData;  /* 128 */
extern int idvbislNOnGemstarData;  /* 129 */
extern int idvbislNOnGemstarNoData;  /* 130 */
extern int idvbislNOnVpsData;  /* 131 */
extern int idvbislNOnVpsNoData;  /* 132 */
extern int idvbislNOnWssData;  /* 133 */
extern int idvbislNOnWssNoData;  /* 134 */
extern int idvbislNOnWstData;  /* 135 */
extern int idvbislNOnWstNoData;  /* 136 */
extern int idvclipexNOnBufferAvailable;  /* 137 */
extern int idvclipexNOnEndOfData;  /* 138 */
extern int idvclipexNOnPaused;  /* 139 */
extern int idvclipexNOnSeekCompleted;  /* 140 */
extern int idvclipexNOnStarted;  /* 141 */
extern int idvclipexNOnStopped;  /* 142 */
extern int idvclipexNOnTotalSeekTimeChanged;  /* 143 */
extern int idvclipNOnBufferAvailable;  /* 144 */
extern int idvclipNOnEndOfData;  /* 145 */
extern int idvclipNOnStarted;  /* 146 */
extern int idvclipNOnStopped;  /* 147 */
extern int idvfrNOnFreezeAllowedChanged;  /* 148 */
extern int idvfrNOnFreezeCompleted;  /* 149 */
extern int idvfrNOnStrobeAllowedChanged;  /* 150 */
extern int idvfrNOnStrobeChanged;  /* 151 */
extern int idvipNOnFieldFrequencyChanged;  /* 152 */
extern int idvipNOnFilmModeChanged;  /* 153 */
extern int idvipNOnFromVcrChanged;  /* 154 */
extern int idvipNOnImageFormatChanged;  /* 155 */
extern int idvipNOnInterlacedChanged;  /* 156 */
extern int idvipNOnNumberOfFrameLinesChanged;  /* 157 */
extern int idvipNOnNumberOfVisibleLinesChanged;  /* 158 */
extern int idvipNOnNumberOfVisiblePixelsChanged;  /* 159 */
extern int idvipNOnSignalPresentChanged;  /* 160 */
extern int idvipNOnVideoCodingChanged;  /* 161 */
extern int idvipNOnVideoPresentChanged;  /* 162 */
extern int idvipNOnVideoProtectionChanged;  /* 163 */
extern int plfapifeNotificationID_Last;  /* 164 */

/*  Functions clients can call, implemented by the supplier. */
extern FResult plfapife_aclip_AddData( int winid, Nat32 id, Nat32 size, Address Data, Bool endOfData, Nat32 * retval );
extern FResult plfapife_aclip_Continue( int winid, Nat32 * retval );
extern FResult plfapife_aclip_EnableClipPlay( int winid, Bool enable, Nat32 * retval );
extern FResult plfapife_aclip_GetAvailableNrBuffers( int winid, Nat32 * AvailableNrBuffers, Nat32 * retval );
extern FResult plfapife_aclip_GetClipPlayEnabled( int winid, Bool * Enable, Nat32 * retval );
extern FResult plfapife_aclip_GetMaxNrBuffers( int winid, Nat32 * MaxNrBuffers, Nat32 * retval );
extern FResult plfapife_aclip_GetPauseSupp( int winid, Bool * Supported, Nat32 * retval );
extern FResult plfapife_aclip_GetState( int winid, tmDigAdec_ClipDecodingState_t * State, Nat32 * retval );
extern FResult plfapife_aclip_Pause( int winid, Nat32 * retval );
extern FResult plfapife_aclip_Start( int winid, Nat32 * retval );
extern FResult plfapife_aclip_Stop( int winid, Nat32 * retval );
extern FResult plfapife_aclipex_AddData( int winid, Nat32 id, Nat32 size, Address Data, Bool endOfData, Nat32 * retval );
extern FResult plfapife_aclipex_Continue( int winid, Nat32 * retval );
extern FResult plfapife_aclipex_EnableClipPlay( int winid, Bool enable, Nat32 * retval );
extern FResult plfapife_aclipex_EnableSeek( int winid, Bool enable, Nat32 * retval );
extern FResult plfapife_aclipex_GetAvailableNrBuffers( int winid, Nat32 * AvailableNrBuffers, Nat32 * retval );
extern FResult plfapife_aclipex_GetClipPlayEnabled( int winid, Bool * Enable, Nat32 * retval );
extern FResult plfapife_aclipex_GetMaxNrBuffers( int winid, Nat32 * MaxNrBuffers, Nat32 * retval );
extern FResult plfapife_aclipex_GetPauseSupp( int winid, Bool * Supported, Nat32 * retval );
extern FResult plfapife_aclipex_GetSeekEnabled( int winid, Bool * penable, Nat32 * retval );
extern FResult plfapife_aclipex_GetState( int winid, tmDigAdec_ClipDecodingState_t * State, Nat32 * retval );
extern FResult plfapife_aclipex_GetTotalSeekTime( int winid, Nat32 * ptotalseektime, Nat32 * retval );
extern FResult plfapife_aclipex_Pause( int winid, Nat32 * retval );
extern FResult plfapife_aclipex_Seek( int winid, Nat32 msec, Nat32 * retval );
extern FResult plfapife_aclipex_Start( int winid, Nat32 * retval );
extern FResult plfapife_aclipex_Stop( int winid, Nat32 * retval );
extern FResult plfapife_apitest_StartTest( int winid, Nat32 id, Nat32 param1, Nat32 param2 );
extern FResult plfapife_apitest_StopTest( int winid, Nat32 id );
extern FResult plfapife_assm_GetMeasValid( int winid, Bool * Valid, Nat32 * retval );
extern FResult plfapife_assm_GetSigStrength( int winid, Nat32 * Strength, Nat32 * retval );
extern FResult plfapife_assm_GetSigStrengthRange( int winid, Nat32 * MinStrength, Nat32 * MaxStrength, Nat32 * retval );
extern FResult plfapife_assm_Start( int winid, Bool * Avail, Nat32 * retval );
extern FResult plfapife_assm_Stop( int winid, Bool * Stopped, Nat32 * retval );
extern FResult plfapife_chantab_Freq2Chan( int winid, Nat32 freq, tmFe_ChanTable_t table, Nat32 * Chan, Nat32 * retval );
extern FResult plfapife_chantab_GetCarrierFreq( int winid, Nat32 chan, tmFe_ChanTable_t table, Nat32 * Freq, Nat32 * retval );
extern FResult plfapife_chantab_GetFirstChan( int winid, tmFe_ChanTable_t table, Nat32 * Chan, Nat32 * retval );
extern FResult plfapife_chantab_GetFirstTable( int winid, tmFe_ChanTable_t * Table, Nat32 * retval );
extern FResult plfapife_chantab_GetIsChan( int winid, Nat32 chan, tmFe_ChanTable_t table, Bool * IsChan, Nat32 * retval );
extern FResult plfapife_chantab_GetLastChan( int winid, tmFe_ChanTable_t table, Nat32 * Chan, Nat32 * retval );
extern FResult plfapife_chantab_GetLowerFreq( int winid, Nat32 chan, tmFe_ChanTable_t table, Nat32 * Freq, Nat32 * retval );
extern FResult plfapife_chantab_GetNextChan( int winid, Nat32 chan, tmFe_ChanTable_t table, Nat32 * Chan, Nat32 * retval );
extern FResult plfapife_chantab_GetNextTable( int winid, tmFe_ChanTable_t curtable, tmFe_ChanTable_t * Table, Nat32 * retval );
extern FResult plfapife_chantab_GetNextValidChan( int winid, Nat32 freq, tmFe_ChanTable_t table, Nat32 * Chan, Nat32 * retval );
extern FResult plfapife_chantab_GetPrevChan( int winid, Nat32 chan, tmFe_ChanTable_t table, Nat32 * Chan, Nat32 * retval );
extern FResult plfapife_chantab_GetPrevValidChan( int winid, Nat32 freq, tmFe_ChanTable_t table, Nat32 * Chan, Nat32 * retval );
extern FResult plfapife_chantab_GetSegmentBoundaries( int winid, Nat32 chan, tmFe_ChanTable_t table, Nat32 * LowerBound, Nat32 * UpperBound, Nat32 * retval );
extern FResult plfapife_chantab_GetTable( int winid, tmFe_ChanTable_t * Table, Nat32 * retval );
extern FResult plfapife_chantab_GetTableSupp( int winid, tmFe_ChanTable_t table, Bool * Supp, Nat32 * retval );
extern FResult plfapife_chantab_GetUpperFreq( int winid, Nat32 chan, tmFe_ChanTable_t table, Nat32 * Freq, Nat32 * retval );
extern FResult plfapife_chantab_SetTable( int winid, tmFe_ChanTable_t table, Nat32 * retval );
extern FResult plfapife_chdec_GetActualConstellation( int winid, tmFe_Constellation_t * pConstellation, Nat32 * retval );
extern FResult plfapife_chdec_GetActualIqMode( int winid, tmFe_IqMode_t * pIqMode, Nat32 * retval );
extern FResult plfapife_chdec_GetBer( int winid, Nat32 * Ber, Nat32 * retval );
extern FResult plfapife_chdec_GetBerThreshold( int winid, Nat32 * Threshold, Nat32 * retval );
extern FResult plfapife_chdec_GetBerThresholdRange( int winid, Nat32 * MinThreshold, Nat32 * MaxThreshold, Nat32 * retval );
extern FResult plfapife_chdec_GetCarrierPresent( int winid, Bool * Present, Nat32 * retval );
extern FResult plfapife_chdec_GetConstellation( int winid, tmFe_Constellation_t * pConstellation, Nat32 * retval );
extern FResult plfapife_chdec_GetFrequencyError( int winid, Int32 * Error, Nat32 * retval );
extern FResult plfapife_chdec_GetFrequencyErrorSupp( int winid, Bool * FreqErrorSupp, Nat32 * retval );
extern FResult plfapife_chdec_GetIqMode( int winid, tmFe_IqMode_t * pIqMode, Nat32 * retval );
extern FResult plfapife_chdec_GetSuppConstellations( int winid, tmFe_ConstellationSet_t * pConstellations, Nat32 * retval );
extern FResult plfapife_chdec_GetSuppIqModes( int winid, tmFe_IqModeSet_t * pIqModes, Nat32 * retval );
extern FResult plfapife_chdec_GetSymbolError( int winid, Int32 * Error, Nat32 * retval );
extern FResult plfapife_chdec_GetSymbolErrorSupp( int winid, Bool * SymbolErrorSupp, Nat32 * retval );
extern FResult plfapife_chdec_GetTimeError( int winid, Int32 * Error, Nat32 * retval );
extern FResult plfapife_chdec_GetTimeErrorSupp( int winid, Bool * TimeErrorSupp, Nat32 * retval );
extern FResult plfapife_chdec_SetBerThreshold( int winid, Nat32 threshold, Nat32 * retval );
extern FResult plfapife_chdec_SetConstellation( int winid, tmFe_Constellation_t constellation, Nat32 * retval );
extern FResult plfapife_chdec_SetFrequencyError( int winid, Int32 error, Nat32 * retval );
extern FResult plfapife_chdec_SetIqMode( int winid, tmFe_IqMode_t iqMode, Nat32 * retval );
extern FResult plfapife_chdec_SetSymbolError( int winid, Int32 error, Nat32 * retval );
extern FResult plfapife_chdec_SetTimeError( int winid, Int32 error, Nat32 * retval );
extern FResult plfapife_chdec2_GetActualConstellation( int winid, tmFe_Constellation_t * pConstellation, Nat32 * retval );
extern FResult plfapife_chdec2_GetActualIqMode( int winid, tmFe_IqMode_t * pIqMode, Nat32 * retval );
extern FResult plfapife_chdec2_GetBer( int winid, Nat32 * Ber, Nat32 * retval );
extern FResult plfapife_chdec2_GetBerThreshold( int winid, Nat32 * Threshold, Nat32 * retval );
extern FResult plfapife_chdec2_GetBerThresholdRange( int winid, Nat32 * MinThreshold, Nat32 * MaxThreshold, Nat32 * retval );
extern FResult plfapife_chdec2_GetCarrierPresent( int winid, Bool * Present, Nat32 * retval );
extern FResult plfapife_chdec2_GetConstellation( int winid, tmFe_Constellation_t * pConstellation, Nat32 * retval );
extern FResult plfapife_chdec2_GetFrequencyError( int winid, Int32 * Error, Nat32 * retval );
extern FResult plfapife_chdec2_GetFrequencyErrorSupp( int winid, Bool * FreqErrorSupp, Nat32 * retval );
extern FResult plfapife_chdec2_GetIqMode( int winid, tmFe_IqMode_t * pIqMode, Nat32 * retval );
extern FResult plfapife_chdec2_GetSuppConstellations( int winid, tmFe_ConstellationSet_t * pConstellations, Nat32 * retval );
extern FResult plfapife_chdec2_GetSuppIqModes( int winid, tmFe_IqModeSet_t * pIqModes, Nat32 * retval );
extern FResult plfapife_chdec2_GetSymbolError( int winid, Int32 * Error, Nat32 * retval );
extern FResult plfapife_chdec2_GetSymbolErrorSupp( int winid, Bool * SymbolErrorSupp, Nat32 * retval );
extern FResult plfapife_chdec2_GetTimeError( int winid, Int32 * Error, Nat32 * retval );
extern FResult plfapife_chdec2_GetTimeErrorSupp( int winid, Bool * TimeErrorSupp, Nat32 * retval );
extern FResult plfapife_chdec2_SetBerThreshold( int winid, Nat32 threshold, Nat32 * retval );
extern FResult plfapife_chdec2_SetConstellation( int winid, tmFe_Constellation_t constellation, Nat32 * retval );
extern FResult plfapife_chdec2_SetFrequencyError( int winid, Int32 error, Nat32 * retval );
extern FResult plfapife_chdec2_SetIqMode( int winid, tmFe_IqMode_t iqMode, Nat32 * retval );
extern FResult plfapife_chdec2_SetSymbolError( int winid, Int32 error, Nat32 * retval );
extern FResult plfapife_chdec2_SetTimeError( int winid, Int32 error, Nat32 * retval );
extern FResult plfapife_chdecdvbc_GetActualCodeRate( int winid, Nat32 * rate, Nat32 * retval );
extern FResult plfapife_chdecdvbc_GetFreqStep( int winid, Nat32 * step, Nat32 * retval );
extern FResult plfapife_chdecdvbc_GetSymbolRate( int winid, Nat32 * rate, Nat32 * retval );
extern FResult plfapife_chdecdvbc_GetSymbolRateRange( int winid, Nat32 * MinSymbolRate, Nat32 * MaxSymbolRate, Nat32 * retval );
extern FResult plfapife_chdecdvbc_ResetFreqStep( int winid, Nat32 * retval );
extern FResult plfapife_chdecdvbc_SetFreqStep( int winid, Nat32 step, Nat32 * retval );
extern FResult plfapife_chdecdvbc_SetSearchRates( int winid, tmFe_SearchSymbolRate_t * SearchRate, Nat32 size, Nat32 * retval );
extern FResult plfapife_chdecdvbc_SetSymbolRate( int winid, Nat32 rate, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetActualChanBandwidth( int winid, tmFe_ChanBandwidth_t * Bandwidth, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetActualCodeRates( int winid, tmFe_CodeRate_t * HighPrioRate, tmFe_CodeRate_t * LowPrioRate, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetActualFrequencyOffset( int winid, tmFe_FrequencyOffset_t * Offset, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetActualGuardInterval( int winid, tmFe_GuardInterval_t * Interval, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetActualHierarchyMode( int winid, tmFe_HierarchyMode_t * Mode, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetActualTxMode( int winid, tmFe_TxMode_t * Mode, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetChanBandwidth( int winid, tmFe_ChanBandwidth_t * Bandwidth, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetChannelInformation( int winid, Nat16 * info, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetCodeRates( int winid, tmFe_CodeRate_t * HighPrioRate, tmFe_CodeRate_t * LowPrioRate, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetFrequencyOffset( int winid, tmFe_FrequencyOffset_t * Offset, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetGuardInterval( int winid, tmFe_GuardInterval_t * Interval, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetHierarchyMode( int winid, tmFe_HierarchyMode_t * Mode, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetStreamPriority( int winid, tmFe_StreamPriority_t * streamPriority, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetSuppChanBandwidths( int winid, tmFe_ChanBandwidthSet_t * Bandwidths, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetSuppCodeRates( int winid, tmFe_CodeRateSet_t * Rates, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetSuppFrequencyOffsets( int winid, tmFe_FrequencyOffsetSet_t * Offsets, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetSuppGuardIntervals( int winid, tmFe_GuardIntervalSet_t * Intervals, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetSuppHierarchyModes( int winid, tmFe_HierarchyModeSet_t * Modes, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetSuppTxModes( int winid, tmFe_TxModeSet_t * Modes, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetTpsCellid( int winid, Nat16 * cellId, Nat32 * retval );
extern FResult plfapife_chdecdvbt_GetTxMode( int winid, tmFe_TxMode_t * Mode, Nat32 * retval );
extern FResult plfapife_chdecdvbt_SetChanBandwidth( int winid, tmFe_ChanBandwidth_t bandwidth, Nat32 * retval );
extern FResult plfapife_chdecdvbt_SetChannelInformation( int winid, Nat16 info, Nat32 * retval );
extern FResult plfapife_chdecdvbt_SetCodeRates( int winid, tmFe_CodeRate_t highPrioRate, tmFe_CodeRate_t lowPrioRate, Nat32 * retval );
extern FResult plfapife_chdecdvbt_SetFrequencyOffset( int winid, tmFe_FrequencyOffset_t offset, Nat32 * retval );
extern FResult plfapife_chdecdvbt_SetGuardInterval( int winid, tmFe_GuardInterval_t interval, Nat32 * retval );
extern FResult plfapife_chdecdvbt_SetHierarchyMode( int winid, tmFe_HierarchyMode_t mode, Nat32 * retval );
extern FResult plfapife_chdecdvbt_SetStreamPriority( int winid, tmFe_StreamPriority_t streamPriority, Nat32 * retval );
extern FResult plfapife_chdecdvbt_SetTxMode( int winid, tmFe_TxMode_t mode, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetActualCodeRates( int winid, int layer, tmFe_CodeRate_t * coderate, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetActualConstellation( int winid, int layer, tmFe_Constellation_t * pConstellation, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetActualGuardInterval( int winid, tmFe_GuardInterval_t * Interval, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetChannelInformation( int winid, Nat16 * info, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetCodeRates( int winid, int layer, tmFe_CodeRate_t * coderate, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetConstellation( int winid, int layer, tmFe_Constellation_t * pConstellation, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetGuardInterval( int winid, tmFe_GuardInterval_t * Interval, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetLayer( int winid, int * layer );
extern FResult plfapife_chdecisdbt_GetSuppCodeRates( int winid, tmFe_CodeRateSet_t * Rates, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetSuppConstellations( int winid, tmFe_ConstellationSet_t * pConstellations, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetSuppGuardIntervals( int winid, tmFe_GuardIntervalSet_t * Intervals, Nat32 * retval );
extern FResult plfapife_chdecisdbt_GetSupportedLayers( int winid, int * layers );
extern FResult plfapife_chdecisdbt_SetChannelInformation( int winid, Nat16 info, Nat32 * retval );
extern FResult plfapife_chdecisdbt_SetCodeRates( int winid, int layer, tmFe_CodeRate_t coderate, Nat32 * retval );
extern FResult plfapife_chdecisdbt_SetConstellation( int winid, int layer, tmFe_Constellation_t constellation, Nat32 * retval );
extern FResult plfapife_chdecisdbt_SetGuardInterval( int winid, tmFe_GuardInterval_t interval, Nat32 * retval );
extern FResult plfapife_chdecisdbt_SetLayer( int winid, int layer );
#define plfapife_chdecisdbt_LayerA  ((int)1)
#define plfapife_chdecisdbt_LayerA_CONSTANT  1
#define plfapife_chdecisdbt_LayerB  ((int)2)
#define plfapife_chdecisdbt_LayerB_CONSTANT  2
#define plfapife_chdecisdbt_LayerC  ((int)4)
#define plfapife_chdecisdbt_LayerC_CONSTANT  4
extern FResult plfapife_chdecisdbt2_GetActualBroadcastType( int winid, tmFe_BroadcastType_t * BroadcastType, tmFe_Partial_t * Partial, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetActualCodeRates( int winid, int layer, tmFe_CodeRate_t * coderate, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetActualConstellation( int winid, int layer, tmFe_Constellation_t * pConstellation, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetActualGuardInterval( int winid, tmFe_GuardInterval_t * Interval, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetActualNumberofSegments( int winid, int layer, tmFe_NumberofSegments_t * segments, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetActualTimeInterleave( int winid, int layer, tmFe_TimeInterleave_t * timeinterleave, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetActualTxMode( int winid, tmFe_TxMode_t * TxMode, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetBroadcastType( int winid, tmFe_BroadcastType_t * BroadcastType, tmFe_Partial_t * Partial, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetChannelInformation( int winid, Nat16 * info, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetCodeRates( int winid, int layer, tmFe_CodeRate_t * coderate, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetConstellation( int winid, int layer, tmFe_Constellation_t * pConstellation, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetGuardInterval( int winid, tmFe_GuardInterval_t * Interval, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetLayer( int winid, int * layer );
extern FResult plfapife_chdecisdbt2_GetNumberofSegments( int winid, int layer, tmFe_NumberofSegments_t * segments, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetSuppBroadcastType( int winid, tmFe_BroadcastTypeSet_t * BroadcastType, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetSuppCodeRates( int winid, tmFe_CodeRateSet_t * Rates, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetSuppConstellations( int winid, tmFe_ConstellationSet_t * pConstellations, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetSuppGuardIntervals( int winid, tmFe_GuardIntervalSet_t * Intervals, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetSuppNumberofSegments( int winid, int layer, tmFe_NumberofSegments_t * segments, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetSupportedLayers( int winid, int * layers );
extern FResult plfapife_chdecisdbt2_GetSuppTimeInterleave( int winid, tmFe_TimeInterleaveSet_t * TimeInterleave, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetSuppTxMode( int winid, tmFe_TxModeSet_t * TxMode, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetTimeInterleave( int winid, int layer, tmFe_TimeInterleave_t * timeinterleave, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_GetTxMode( int winid, tmFe_TxMode_t * TxMode, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_SetBroadcastType( int winid, tmFe_BroadcastType_t BroadcastType, tmFe_Partial_t Partial, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_SetChannelInformation( int winid, Nat16 info, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_SetCodeRates( int winid, int layer, tmFe_CodeRate_t coderate, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_SetConstellation( int winid, int layer, tmFe_Constellation_t constellation, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_SetGuardInterval( int winid, tmFe_GuardInterval_t interval, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_SetLayer( int winid, int layer );
extern FResult plfapife_chdecisdbt2_SetNumberofSegments( int winid, int layer, tmFe_NumberofSegments_t segments, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_SetTimeInterleave( int winid, int layer, tmFe_TimeInterleave_t timeinterleave, Nat32 * retval );
extern FResult plfapife_chdecisdbt2_SetTxMode( int winid, tmFe_TxMode_t txmode, Nat32 * retval );
#define plfapife_chdecisdbt2_LayerA  ((int)1)
#define plfapife_chdecisdbt2_LayerA_CONSTANT  1
#define plfapife_chdecisdbt2_LayerB  ((int)2)
#define plfapife_chdecisdbt2_LayerB_CONSTANT  2
#define plfapife_chdecisdbt2_LayerC  ((int)4)
#define plfapife_chdecisdbt2_LayerC_CONSTANT  4
extern FResult plfapife_chdecsel_GetChanDec( int winid, Nat32 * decoder );
extern FResult plfapife_chdecsel_IsChanDecSupported( int winid, Nat32 decoder, Nat32 * retval );
extern FResult plfapife_chdecsel_SetChanDec( int winid, Nat32 decoder );
#define plfapife_chdecsel_ChanDecDvbC  ((Nat32)2)
#define plfapife_chdecsel_ChanDecDvbC_CONSTANT  2
#define plfapife_chdecsel_ChanDecDvbS  ((Nat32)4)
#define plfapife_chdecsel_ChanDecDvbS_CONSTANT  4
#define plfapife_chdecsel_ChanDecDvbT  ((Nat32)1)
#define plfapife_chdecsel_ChanDecDvbT_CONSTANT  1
#define plfapife_chdecsel_ChanDecISDBT  ((Nat32)8)
#define plfapife_chdecsel_ChanDecISDBT_CONSTANT  8
extern FResult plfapife_ciplusai_AI_SelectApplication( int winid, CIPlusHandle handle, Nat32 appli_index, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusammi_AMMI_Abort( int winid, CIPlusHandle handle, Nat16 ammiId, Nat16 byteLen, Nat8 * ptbyte, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusammi_AMMI_AbortAck( int winid, CIPlusHandle handle, Nat16 ammiId, Nat16 byteLen, Nat8 * ptbyte, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusammi_AMMI_Close( int winid, CIPlusHandle handle, Nat16 ammiId, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusammi_AMMI_Request( int winid, CIPlusHandle handle, Nat16 ammiId, CIPlusRequestType_e request_type, Nat32 byteLen, Address shrdmemptByte, Nat16 fileNameLen, Address ptFileName, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusammi_AMMI_StartAck( int winid, CIPlusHandle handle, Nat16 ammiId, Nat8 ackCode, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusca_Ca_NotifyPMT( int winid, CIPlusHandle handle, Nat16 sessionid, Nat16 NbOfCADescriptors, CIPlusCaListMng_e listmng, CIPlusCaCommand_e command, Nat16 PMTLength, Nat8 * PMTdata, CIPlusResult_e * Result );
extern FResult plfapife_cipluscc_CC_GetBrandID( int winid, CIPlusHandle handle, Nat16 * brandId );
extern FResult plfapife_ciplushc_HC_Release( int winid, CIPlusHandle handle, CIPlusResult_e * Result );
extern FResult plfapife_ciplushlc_HLC_SetCountry( int winid, Nat32 countryCode, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplushlc_HLC_SetLanguage( int winid, Nat32 langCode, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusinit_OnRequestActivate( int winid, CIPlusHandle handle, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusinit_OnRequestEnd( int winid, CIPlusHandle handle, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusinit_OnRequestInit( int winid, CIPlusVersion_e CiVersion, Bool LSCActive, Bool SASActive, Bool PVRActive, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusinit_ResetHard( int winid, CIPlusHandle handle, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusinit_ResetSoft( int winid, CIPlusHandle handle, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusinit_SwitchTS( int winid, CIPlusHandle handle, CIPlusTSMode_e tsmode, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusmmi_MMI_Close( int winid, CIPlusHandle handle, Nat16 mmiId, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusmmi_MMI_ResponseEnq( int winid, CIPlusHandle handle, Nat16 mmiId, Nat8 answ, Nat16 textLen, Nat8 * textPtr, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusmmi_MMI_ResponseList( int winid, CIPlusHandle handle, Nat16 mmiId, Nat16 choice, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusmmi_MMI_ResponseMenu( int winid, CIPlusHandle handle, Nat16 mmiId, Nat16 choice, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusstatus_GetStatus( int winid, CIPlusHandle handle, CIPlusStatus_e * status, CIPlusResult_e * ciResult );
extern FResult plfapife_ciplusupgr_UPGR_UpgradeReply( int winid, CIPlusHandle handle, CIPlusUPGRReply_e reply, CIPlusResult_e * ciResult );
extern FResult plfapife_col_ColorSystemSupported( int winid, int colorsystem, Bool * retval );
extern FResult plfapife_col_ColorSystemSupportedEx( int winid, int colorsystem, int carrierfrequency, Bool * retval );
extern FResult plfapife_col_CombFilterActive( int winid, Bool * retval );
extern FResult plfapife_col_CombFilterEnabled( int winid, Bool * retval );
extern FResult plfapife_col_CombFilterSupported( int winid, Bool * retval );
extern FResult plfapife_col_EnableCombFilter( int winid, Bool mode );
extern FResult plfapife_col_ForceColorSystem( int winid, int colorsystem );
extern FResult plfapife_col_ForceColorSystemEx( int winid, int colorsystem, int carrierfrequency );
extern FResult plfapife_col_GetCarrierFrequency( int winid, int * retval );
extern FResult plfapife_col_GetColorSystem( int winid, int * retval );
extern FResult plfapife_col_GetForcedCarrierFrequency( int winid, int * retval );
extern FResult plfapife_col_GetForcedColorSystem( int winid, int * retval );
extern FResult plfapife_col_GetSuggestedCarrierFrequency( int winid, int * retval );
extern FResult plfapife_col_GetSuggestedColorSystem( int winid, int * retval );
extern FResult plfapife_col_SuggestColorSystem( int winid, int colorsystem );
extern FResult plfapife_col_SuggestColorSystemEx( int winid, int colorsystem, int carrierfrequency );
#define plfapife_col_Freq3pt575611  ((int)2)
#define plfapife_col_Freq3pt575611_CONSTANT  2
#define plfapife_col_Freq3pt579545  ((int)3)
#define plfapife_col_Freq3pt579545_CONSTANT  3
#define plfapife_col_Freq3pt582056  ((int)1)
#define plfapife_col_Freq3pt582056_CONSTANT  1
#define plfapife_col_Freq4pt433619  ((int)0)
#define plfapife_col_Freq4pt433619_CONSTANT  0
#define plfapife_col_FreqInvalid  ((int)-2)
#define plfapife_col_FreqInvalid_CONSTANT  -2
#define plfapife_col_FreqUnknown  ((int)-1)
#define plfapife_col_FreqUnknown_CONSTANT  -1
#define plfapife_col_InvalidColorSystem  ((int)-2)
#define plfapife_col_InvalidColorSystem_CONSTANT  -2
#define plfapife_col_Ntsc  ((int)2)
#define plfapife_col_Ntsc_CONSTANT  2
#define plfapife_col_Pal  ((int)0)
#define plfapife_col_Pal_CONSTANT  0
#define plfapife_col_Secam  ((int)1)
#define plfapife_col_Secam_CONSTANT  1
#define plfapife_col_UnknownColorSystem  ((int)-1)
#define plfapife_col_UnknownColorSystem_CONSTANT  -1
extern FResult plfapife_diseq_Send( int winid, int polarisation, int band, int ctrlword1, int bytelen1, int ctrlword2, int bytelen2, int toneburst, int cookie, int * CmdResult );
extern FResult plfapife_diseq_SendMsg( int winid, int polarisation, int band, int datalen, Nat8 * buffer, int toneburst, int cookie, int * CmdResult );
#define plfapife_diseq_BandHigh  ((int)1)
#define plfapife_diseq_BandHigh_CONSTANT  1
#define plfapife_diseq_BandLow  ((int)2)
#define plfapife_diseq_BandLow_CONSTANT  2
#define plfapife_diseq_CmdResultInvalidParam  ((int)2)
#define plfapife_diseq_CmdResultInvalidParam_CONSTANT  2
#define plfapife_diseq_CmdResultInvalidState  ((int)3)
#define plfapife_diseq_CmdResultInvalidState_CONSTANT  3
#define plfapife_diseq_CmdResultOK  ((int)0)
#define plfapife_diseq_CmdResultOK_CONSTANT  0
#define plfapife_diseq_CmdResultSending  ((int)1)
#define plfapife_diseq_CmdResultSending_CONSTANT  1
#define plfapife_diseq_PolarisationHorizontal  ((int)1)
#define plfapife_diseq_PolarisationHorizontal_CONSTANT  1
#define plfapife_diseq_PolarisationVertical  ((int)2)
#define plfapife_diseq_PolarisationVertical_CONSTANT  2
#define plfapife_diseq_ToneBurstNone  ((int)0)
#define plfapife_diseq_ToneBurstNone_CONSTANT  0
#define plfapife_diseq_ToneBurstSatA  ((int)1)
#define plfapife_diseq_ToneBurstSatA_CONSTANT  1
#define plfapife_diseq_ToneBurstSatB  ((int)2)
#define plfapife_diseq_ToneBurstSatB_CONSTANT  2
extern FResult plfapife_dvbs_AttemptLock( int winid, int Frequency, int SearchRange, int SymbolRate, int ModulationStandard, int ModulationType, int CodeRate, int PunctureRate, int IQMode, int * Timeout, int Cookie, int * CmdResult );
extern FResult plfapife_dvbs_GetParams( int winid, int * Frequency, int * SymbolRate, int * ModulationStandard, int * ModulationType, int * CodeRate, int * PunctureRate, int * IQMode, int * LockState, int * CmdResult );
#define plfapife_dvbs_CmdResultInvalidParam  ((int)3)
#define plfapife_dvbs_CmdResultInvalidParam_CONSTANT  3
#define plfapife_dvbs_CmdResultInvalidState  ((int)4)
#define plfapife_dvbs_CmdResultInvalidState_CONSTANT  4
#define plfapife_dvbs_CmdResultLocked  ((int)2)
#define plfapife_dvbs_CmdResultLocked_CONSTANT  2
#define plfapife_dvbs_CmdResultLocking  ((int)1)
#define plfapife_dvbs_CmdResultLocking_CONSTANT  1
#define plfapife_dvbs_CmdResultOK  ((int)0)
#define plfapife_dvbs_CmdResultOK_CONSTANT  0
#define plfapife_dvbs_CodeRate_1_2  ((int)8)
#define plfapife_dvbs_CodeRate_1_2_CONSTANT  8
#define plfapife_dvbs_CodeRate_1_3  ((int)2)
#define plfapife_dvbs_CodeRate_1_3_CONSTANT  2
#define plfapife_dvbs_CodeRate_1_4  ((int)1)
#define plfapife_dvbs_CodeRate_1_4_CONSTANT  1
#define plfapife_dvbs_CodeRate_2_3  ((int)32)
#define plfapife_dvbs_CodeRate_2_3_CONSTANT  32
#define plfapife_dvbs_CodeRate_2_5  ((int)4)
#define plfapife_dvbs_CodeRate_2_5_CONSTANT  4
#define plfapife_dvbs_CodeRate_3_4  ((int)64)
#define plfapife_dvbs_CodeRate_3_4_CONSTANT  64
#define plfapife_dvbs_CodeRate_3_5  ((int)16)
#define plfapife_dvbs_CodeRate_3_5_CONSTANT  16
#define plfapife_dvbs_CodeRate_4_5  ((int)128)
#define plfapife_dvbs_CodeRate_4_5_CONSTANT  128
#define plfapife_dvbs_CodeRate_5_6  ((int)256)
#define plfapife_dvbs_CodeRate_5_6_CONSTANT  256
#define plfapife_dvbs_CodeRate_8_9  ((int)512)
#define plfapife_dvbs_CodeRate_8_9_CONSTANT  512
#define plfapife_dvbs_CodeRate_9_10  ((int)1024)
#define plfapife_dvbs_CodeRate_9_10_CONSTANT  1024
#define plfapife_dvbs_CodeRateUnknown  ((int)-1)
#define plfapife_dvbs_CodeRateUnknown_CONSTANT  -1
#define plfapife_dvbs_FreqMax  ((int)2150000)
#define plfapife_dvbs_FreqMax_CONSTANT  2150000
#define plfapife_dvbs_FreqMin  ((int)950000)
#define plfapife_dvbs_FreqMin_CONSTANT  950000
#define plfapife_dvbs_IQModeInverse  ((int)2)
#define plfapife_dvbs_IQModeInverse_CONSTANT  2
#define plfapife_dvbs_IQModeNormal  ((int)1)
#define plfapife_dvbs_IQModeNormal_CONSTANT  1
#define plfapife_dvbs_IQModeUnknown  ((int)-1)
#define plfapife_dvbs_IQModeUnknown_CONSTANT  -1
#define plfapife_dvbs_LockStateDemodLock  ((int)1)
#define plfapife_dvbs_LockStateDemodLock_CONSTANT  1
#define plfapife_dvbs_LockStateFECLock  ((int)2)
#define plfapife_dvbs_LockStateFECLock_CONSTANT  2
#define plfapife_dvbs_LockStateNOLock  ((int)0)
#define plfapife_dvbs_LockStateNOLock_CONSTANT  0
#define plfapife_dvbs_ModulationStandardDvbDSS  ((int)4)
#define plfapife_dvbs_ModulationStandardDvbDSS_CONSTANT  4
#define plfapife_dvbs_ModulationStandardDvbS1  ((int)1)
#define plfapife_dvbs_ModulationStandardDvbS1_CONSTANT  1
#define plfapife_dvbs_ModulationStandardDvbS2  ((int)2)
#define plfapife_dvbs_ModulationStandardDvbS2_CONSTANT  2
#define plfapife_dvbs_ModulationStandardUnknown  ((int)-1)
#define plfapife_dvbs_ModulationStandardUnknown_CONSTANT  -1
#define plfapife_dvbs_ModulationType16APSK  ((int)4)
#define plfapife_dvbs_ModulationType16APSK_CONSTANT  4
#define plfapife_dvbs_ModulationType32APSK  ((int)8)
#define plfapife_dvbs_ModulationType32APSK_CONSTANT  8
#define plfapife_dvbs_ModulationType8PSK  ((int)2)
#define plfapife_dvbs_ModulationType8PSK_CONSTANT  2
#define plfapife_dvbs_ModulationTypeQPSK  ((int)1)
#define plfapife_dvbs_ModulationTypeQPSK_CONSTANT  1
#define plfapife_dvbs_ModulationTypeUnknown  ((int)-1)
#define plfapife_dvbs_ModulationTypeUnknown_CONSTANT  -1
#define plfapife_dvbs_PunctureRate_1_2  ((int)1)
#define plfapife_dvbs_PunctureRate_1_2_CONSTANT  1
#define plfapife_dvbs_PunctureRate_2_3  ((int)2)
#define plfapife_dvbs_PunctureRate_2_3_CONSTANT  2
#define plfapife_dvbs_PunctureRate_3_4  ((int)4)
#define plfapife_dvbs_PunctureRate_3_4_CONSTANT  4
#define plfapife_dvbs_PunctureRate_4_5  ((int)8)
#define plfapife_dvbs_PunctureRate_4_5_CONSTANT  8
#define plfapife_dvbs_PunctureRate_5_6  ((int)16)
#define plfapife_dvbs_PunctureRate_5_6_CONSTANT  16
#define plfapife_dvbs_PunctureRate_6_7  ((int)32)
#define plfapife_dvbs_PunctureRate_6_7_CONSTANT  32
#define plfapife_dvbs_PunctureRate_7_8  ((int)64)
#define plfapife_dvbs_PunctureRate_7_8_CONSTANT  64
#define plfapife_dvbs_PunctureRate_8_9  ((int)128)
#define plfapife_dvbs_PunctureRate_8_9_CONSTANT  128
#define plfapife_dvbs_PunctureRateUnknown  ((int)-1)
#define plfapife_dvbs_PunctureRateUnknown_CONSTANT  -1
#define plfapife_dvbs_SearchRangeMax  ((int)50000)
#define plfapife_dvbs_SearchRangeMax_CONSTANT  50000
#define plfapife_dvbs_SearchRangeMin  ((int)1000)
#define plfapife_dvbs_SearchRangeMin_CONSTANT  1000
#define plfapife_dvbs_SearchRangeTune  ((int)0)
#define plfapife_dvbs_SearchRangeTune_CONSTANT  0
#define plfapife_dvbs_SymbRateMax  ((int)70000000)
#define plfapife_dvbs_SymbRateMax_CONSTANT  70000000
#define plfapife_dvbs_SymbRateMin  ((int)1000000)
#define plfapife_dvbs_SymbRateMin_CONSTANT  1000000
#define plfapife_dvbs_SymbRateUnknown  ((int)-1)
#define plfapife_dvbs_SymbRateUnknown_CONSTANT  -1
#define plfapife_errid_InterfaceNotAvailable  ((FResult)2)
#define plfapife_errid_InterfaceNotAvailable_CONSTANT  2
#define plfapife_errid_Ok  ((FResult)0)
#define plfapife_errid_Ok_CONSTANT  0
#define plfapife_errid_Other  ((FResult)-1)
#define plfapife_errid_Other_CONSTANT  -1
#define plfapife_errid_ResourceNotOwned  ((FResult)1)
#define plfapife_errid_ResourceNotOwned_CONSTANT  1
extern FResult plfapife_feitf_GetAvailableInterfaces( int * nbrgroups, Nat32 * ids );
#define plfapife_feitfid_aclip  ((Nat32)131072)
#define plfapife_feitfid_aclip_CONSTANT  131072
#define plfapife_feitfid_aclipex  ((Nat32)8388608)
#define plfapife_feitfid_aclipex_CONSTANT  8388608
#define plfapife_feitfid_apitest  ((Nat32)1)
#define plfapife_feitfid_apitest_CONSTANT  1
#define plfapife_feitfid_assm  ((Nat32)64)
#define plfapife_feitfid_assm_CONSTANT  64
#define plfapife_feitfid_chantab  ((Nat32)2048)
#define plfapife_feitfid_chantab_CONSTANT  2048
#define plfapife_feitfid_chdec  ((Nat32)512)
#define plfapife_feitfid_chdec_CONSTANT  512
#define plfapife_feitfid_chdec2  ((Nat32)524288)
#define plfapife_feitfid_chdec2_CONSTANT  524288
#define plfapife_feitfid_chdecdvbc  ((Nat32)1048576)
#define plfapife_feitfid_chdecdvbc_CONSTANT  1048576
#define plfapife_feitfid_chdecdvbt  ((Nat32)1024)
#define plfapife_feitfid_chdecdvbt_CONSTANT  1024
#define plfapife_feitfid_chdecisdbt  ((Nat32)2097152)
#define plfapife_feitfid_chdecisdbt_CONSTANT  2097152
#define plfapife_feitfid_chdecisdbt2  ((Nat32)4194304)
#define plfapife_feitfid_chdecisdbt2_CONSTANT  4194304
#define plfapife_feitfid_chdecsel  ((Nat32)1)
#define plfapife_feitfid_chdecsel_CONSTANT  1
#define plfapife_feitfid_ciplusai  ((Nat32)1)
#define plfapife_feitfid_ciplusai_CONSTANT  1
#define plfapife_feitfid_ciplusammi  ((Nat32)1)
#define plfapife_feitfid_ciplusammi_CONSTANT  1
#define plfapife_feitfid_ciplusca  ((Nat32)1)
#define plfapife_feitfid_ciplusca_CONSTANT  1
#define plfapife_feitfid_cipluscc  ((Nat32)1)
#define plfapife_feitfid_cipluscc_CONSTANT  1
#define plfapife_feitfid_ciplushc  ((Nat32)1)
#define plfapife_feitfid_ciplushc_CONSTANT  1
#define plfapife_feitfid_ciplushlc  ((Nat32)1)
#define plfapife_feitfid_ciplushlc_CONSTANT  1
#define plfapife_feitfid_ciplusinit  ((Nat32)1)
#define plfapife_feitfid_ciplusinit_CONSTANT  1
#define plfapife_feitfid_ciplusmmi  ((Nat32)1)
#define plfapife_feitfid_ciplusmmi_CONSTANT  1
#define plfapife_feitfid_ciplusstatus  ((Nat32)1)
#define plfapife_feitfid_ciplusstatus_CONSTANT  1
#define plfapife_feitfid_ciplusupgr  ((Nat32)1)
#define plfapife_feitfid_ciplusupgr_CONSTANT  1
#define plfapife_feitfid_col  ((Nat32)1)
#define plfapife_feitfid_col_CONSTANT  1
#define plfapife_feitfid_diseq  ((Nat32)1)
#define plfapife_feitfid_diseq_CONSTANT  1
#define plfapife_feitfid_dvbs  ((Nat32)1)
#define plfapife_feitfid_dvbs_CONSTANT  1
#define plfapife_feitfid_gdrip  ((Nat32)33554432)
#define plfapife_feitfid_gdrip_CONSTANT  33554432
#define plfapife_feitfid_hsys  ((Nat32)1)
#define plfapife_feitfid_hsys_CONSTANT  1
#define plfapife_feitfid_prs  ((Nat32)1)
#define plfapife_feitfid_prs_CONSTANT  1
#define plfapife_feitfid_qssm  ((Nat32)128)
#define plfapife_feitfid_qssm_CONSTANT  128
#define plfapife_feitfid_rfamp  ((Nat32)4096)
#define plfapife_feitfid_rfamp_CONSTANT  4096
#define plfapife_feitfid_sad  ((Nat32)1)
#define plfapife_feitfid_sad_CONSTANT  1
#define plfapife_feitfid_siq  ((Nat32)1)
#define plfapife_feitfid_siq_CONSTANT  1
#define plfapife_feitfid_snd  ((Nat32)1)
#define plfapife_feitfid_snd_CONSTANT  1
#define plfapife_feitfid_soc  ((Nat32)1)
#define plfapife_feitfid_soc_CONSTANT  1
#define plfapife_feitfid_ssm  ((Nat32)256)
#define plfapife_feitfid_ssm_CONSTANT  256
#define plfapife_feitfid_ssys  ((Nat32)1)
#define plfapife_feitfid_ssys_CONSTANT  1
#define plfapife_feitfid_stcdec  ((Nat32)32768)
#define plfapife_feitfid_stcdec_CONSTANT  32768
#define plfapife_feitfid_tmc  ((Nat32)1)
#define plfapife_feitfid_tmc_CONSTANT  1
#define plfapife_feitfid_tsdmx  ((Nat32)16384)
#define plfapife_feitfid_tsdmx_CONSTANT  16384
#define plfapife_feitfid_tsdmxex  ((Nat32)16384)
#define plfapife_feitfid_tsdmxex_CONSTANT  16384
#define plfapife_feitfid_tun  ((Nat32)8192)
#define plfapife_feitfid_tun_CONSTANT  8192
#define plfapife_feitfid_vbiins  ((Nat32)1)
#define plfapife_feitfid_vbiins_CONSTANT  1
#define plfapife_feitfid_vbisl  ((Nat32)65536)
#define plfapife_feitfid_vbisl_CONSTANT  65536
#define plfapife_feitfid_vclip  ((Nat32)262144)
#define plfapife_feitfid_vclip_CONSTANT  262144
#define plfapife_feitfid_vclipex  ((Nat32)16777216)
#define plfapife_feitfid_vclipex_CONSTANT  16777216
#define plfapife_feitfid_vfr  ((Nat32)1)
#define plfapife_feitfid_vfr_CONSTANT  1
#define plfapife_feitfid_vip  ((Nat32)1)
#define plfapife_feitfid_vip_CONSTANT  1
extern FResult plfapife_gdrip_AddData( int winid, Nat32 id, Nat32 size, Address Data, Bool endOfData, Nat32 * retval );
extern FResult plfapife_gdrip_GetAvailableNrBuffers( int winid, Nat32 * AvailableNrBuffers, Nat32 * retval );
extern FResult plfapife_gdrip_GetBufAlignment( int winid, Nat32 * pAlignment, Nat32 * retval );
extern FResult plfapife_gdrip_GetMaxNrBuffers( int winid, Nat32 * MaxNrBuffers, Nat32 * retval );
extern FResult plfapife_gdrip_GetOutputFrame( int winid, Nat32 reqHorRes, Nat32 reqVertRes, Nat32 horPos, Nat32 vertPos, Nat32 stride, tmPixFmtCls_t formatClass, tmPixFmtType_t formatType, Nat32 bufferSize, Address buffer, Nat32 * retval );
extern FResult plfapife_gdrip_GetScalingRestrictions( int winid, Nat32 * pMaxRequestedHorRes, Nat32 * pMaxRequestedVertRes, Nat32 * pMinRequestedHorRes, Nat32 * pMinRequestedVertRes, Nat32 * retval );
extern FResult plfapife_gdrip_GetState( int winid, tmDigVdec_ClipDecodingState_t * ClipDecodingState, Nat32 * retval );
extern FResult plfapife_gdrip_GetSuppFormatClasses( int winid, tmPixFmtClsSet_t * pFormatClassSet, Nat32 * retval );
extern FResult plfapife_gdrip_GetSuppFormatTypes( int winid, tmPixFmtTypeSet_t * pFormatTypesSet, Nat32 * retval );
extern FResult plfapife_gdrip_Start( int winid, Nat32 * retval );
extern FResult plfapife_gdrip_Stop( int winid, Nat32 * retval );
extern FResult plfapife_hsys_GetSoundSystem( int winid, Nat32 * retval );
#define plfapife_hsys_ContainsData  ((Nat32)16384)
#define plfapife_hsys_ContainsData_CONSTANT  16384
#define plfapife_hsys_ContainsDolbyProLogic  ((Nat32)131072)
#define plfapife_hsys_ContainsDolbyProLogic_CONSTANT  131072
#define plfapife_hsys_ContainsDual  ((Nat32)32768)
#define plfapife_hsys_ContainsDual_CONSTANT  32768
#define plfapife_hsys_ContainsDynamicRangeCompression  ((Nat32)262144)
#define plfapife_hsys_ContainsDynamicRangeCompression_CONSTANT  262144
#define plfapife_hsys_ContainsKaraoke  ((Nat32)524288)
#define plfapife_hsys_ContainsKaraoke_CONSTANT  524288
#define plfapife_hsys_ContainsUnrelated  ((Nat32)65536)
#define plfapife_hsys_ContainsUnrelated_CONSTANT  65536
#define plfapife_hsys_Is2CS  ((Nat32)128)
#define plfapife_hsys_Is2CS_CONSTANT  128
#define plfapife_hsys_IsAC3  ((Nat32)2048)
#define plfapife_hsys_IsAC3_CONSTANT  2048
#define plfapife_hsys_IsAC3Plus  ((Nat32)1048576)
#define plfapife_hsys_IsAC3Plus_CONSTANT  1048576
#define plfapife_hsys_IsAM  ((Nat32)16)
#define plfapife_hsys_IsAM_CONSTANT  16
#define plfapife_hsys_IsAnalog  ((Nat32)2)
#define plfapife_hsys_IsAnalog_CONSTANT  2
#define plfapife_hsys_IsBaseband  ((Nat32)8)
#define plfapife_hsys_IsBaseband_CONSTANT  8
#define plfapife_hsys_IsBTSC  ((Nat32)256)
#define plfapife_hsys_IsBTSC_CONSTANT  256
#define plfapife_hsys_IsDigital  ((Nat32)4)
#define plfapife_hsys_IsDigital_CONSTANT  4
#define plfapife_hsys_IsDTS  ((Nat32)8192)
#define plfapife_hsys_IsDTS_CONSTANT  8192
#define plfapife_hsys_IsEIAJ  ((Nat32)512)
#define plfapife_hsys_IsEIAJ_CONSTANT  512
#define plfapife_hsys_IsFM  ((Nat32)32)
#define plfapife_hsys_IsFM_CONSTANT  32
#define plfapife_hsys_IsHEAAC  ((Nat32)2097152)
#define plfapife_hsys_IsHEAAC_CONSTANT  2097152
#define plfapife_hsys_IsMPEG  ((Nat32)4096)
#define plfapife_hsys_IsMPEG_CONSTANT  4096
#define plfapife_hsys_IsNicam  ((Nat32)64)
#define plfapife_hsys_IsNicam_CONSTANT  64
#define plfapife_hsys_IsPCM  ((Nat32)1024)
#define plfapife_hsys_IsPCM_CONSTANT  1024
#define plfapife_hsys_IsWMA  ((Nat32)4194304)
#define plfapife_hsys_IsWMA_CONSTANT  4194304
#define plfapife_hsys_SoundPresent  ((Nat32)1)
#define plfapife_hsys_SoundPresent_CONSTANT  1
extern FResult plfapife_prs_FillPreset( int winid, tmPlfInstPreset_Source_t source, int preset, Nat32 * retval );
extern FResult plfapife_prs_GetAttribute( int winid, int preset, tmPlfInstPreset_PresetAttribute_t attribute, int * Value, Nat32 * retval );
extern FResult plfapife_prs_GetMaxPreset( int winid, int * PresetIndex, Nat32 * retval );
extern FResult plfapife_prs_GetMinPreset( int winid, int * PresetIndex, Nat32 * retval );
extern FResult plfapife_prs_GetPreset( int winid, tmPlfInstPreset_Source_t source, int * Preset, Nat32 * retval );
extern FResult plfapife_prs_InitPreset( int winid, int preset, Nat32 * retval );
extern FResult plfapife_prs_LoadAttribute( int winid, int preset, tmPlfInstPreset_PresetAttribute_t attribute, Nat32 * retval );
extern FResult plfapife_prs_LoadPreset( int winid, int preset, Nat32 * retval );
extern FResult plfapife_prs_SetAttribute( int winid, int preset, tmPlfInstPreset_PresetAttribute_t attribute, int value, Nat32 * retval );
extern FResult plfapife_prs_SetPreset( int winid, tmPlfInstPreset_Source_t source, int preset, Nat32 * retval );
extern FResult plfapife_prs_StoreAttribute( int winid, int preset, tmPlfInstPreset_PresetAttribute_t attribute, Nat32 * retval );
extern FResult plfapife_prs_StoreAttributeSupported( int winid, tmPlfInstPreset_PresetAttribute_t attribute, Bool * Supported, Nat32 * retval );
extern FResult plfapife_prs_StorePreset( int winid, int preset, Nat32 * retval );
extern FResult plfapife_prs_StorePresetSupported( int winid, Bool * Supported, Nat32 * retval );
extern FResult plfapife_prs_SwapPreset( int winid, int preset1, int preset2, Nat32 * retval );
extern FResult plfapife_qssm_GetMeasValid( int winid, Bool * Valid, Nat32 * retval );
extern FResult plfapife_qssm_GetSigStrength( int winid, Nat32 * Strength, Nat32 * retval );
extern FResult plfapife_qssm_GetSigStrengthRange( int winid, Nat32 * MinStrength, Nat32 * MaxStrength, Nat32 * retval );
extern FResult plfapife_qssm_Start( int winid, Bool * Avail, Nat32 * retval );
extern FResult plfapife_qssm_Stop( int winid, Bool * Stopped, Nat32 * retval );
extern FResult plfapife_rfamp_Get( int winid, Int32 * Amp, Nat32 * retval );
extern FResult plfapife_rfamp_GetRange( int winid, Int32 * MinAmp, Int32 * MaxAmp, Nat32 * retval );
extern FResult plfapife_rfamp_Set( int winid, Int32 amp, Nat32 * retval );
extern FResult plfapife_sad_GetADRouting( int winid, int * retval );
extern FResult plfapife_sad_GetVolume( int winid, int * retval );
extern FResult plfapife_sad_GetVolumeMax( int winid, int * retval );
extern FResult plfapife_sad_GetVolumeMin( int winid, int * retval );
extern FResult plfapife_sad_IsADRoutingAllowed( int winid, Bool * retval );
extern FResult plfapife_sad_IsADRoutingSupported( int winid, Bool * retval );
extern FResult plfapife_sad_IsVolumeControlAllowed( int winid, Bool * retval );
extern FResult plfapife_sad_IsVolumeControlSupported( int winid, Bool * retval );
extern FResult plfapife_sad_SetADRouting( int winid, int outputs );
extern FResult plfapife_sad_SetVolume( int winid, int volume );
#define plfapife_sad_HeadPhones  ((int)2)
#define plfapife_sad_HeadPhones_CONSTANT  2
#define plfapife_sad_MainSpeakers  ((int)1)
#define plfapife_sad_MainSpeakers_CONSTANT  1
#define plfapife_sad_MonitorOut  ((int)4)
#define plfapife_sad_MonitorOut_CONSTANT  4
#define plfapife_sad_NoADRouting  ((int)0)
#define plfapife_sad_NoADRouting_CONSTANT  0
#define plfapife_sad_SpdifOut  ((int)8)
#define plfapife_sad_SpdifOut_CONSTANT  8
extern FResult plfapife_siq_GetActualNoiseLevel( int winid, int * retval );
#define plfapife_siq_MaxLevel  ((int)255)
#define plfapife_siq_MaxLevel_CONSTANT  255
#define plfapife_siq_MinLevel  ((int)0)
#define plfapife_siq_MinLevel_CONSTANT  0
extern FResult plfapife_snd_AllowSoundSystem( int winid, int system );
extern FResult plfapife_snd_GetAllowedSoundSystem( int winid, int * retval );
#define plfapife_snd_Allow2CS  ((int)8)
#define plfapife_snd_Allow2CS_CONSTANT  8
#define plfapife_snd_AllowAC3  ((int)128)
#define plfapife_snd_AllowAC3_CONSTANT  128
#define plfapife_snd_AllowAnalog  ((int)1)
#define plfapife_snd_AllowAnalog_CONSTANT  1
#define plfapife_snd_AllowBTSC  ((int)16)
#define plfapife_snd_AllowBTSC_CONSTANT  16
#define plfapife_snd_AllowDigital  ((int)2)
#define plfapife_snd_AllowDigital_CONSTANT  2
#define plfapife_snd_AllowDTS  ((int)512)
#define plfapife_snd_AllowDTS_CONSTANT  512
#define plfapife_snd_AllowEIAJ  ((int)32)
#define plfapife_snd_AllowEIAJ_CONSTANT  32
#define plfapife_snd_AllowMPEG  ((int)256)
#define plfapife_snd_AllowMPEG_CONSTANT  256
#define plfapife_snd_AllowNicam  ((int)4)
#define plfapife_snd_AllowNicam_CONSTANT  4
#define plfapife_snd_AllowPCM  ((int)64)
#define plfapife_snd_AllowPCM_CONSTANT  64
extern FResult plfapife_soc_FrontChannels( int winid, int channel, int * retval );
extern FResult plfapife_soc_GetChannel( int winid, int * retval );
extern FResult plfapife_soc_IsDigital( int winid, int channel, Bool * retval );
extern FResult plfapife_soc_IsDolbyProLogic( int winid, int channel, Bool * retval );
extern FResult plfapife_soc_IsMono( int winid, int channel, Bool * retval );
extern FResult plfapife_soc_IsRelated( int winid, int channel, Bool * retval );
extern FResult plfapife_soc_IsSecondLanguage( int winid, int channel, Bool * retval );
extern FResult plfapife_soc_IsStereo( int winid, int channel, Bool * retval );
extern FResult plfapife_soc_LfeChannels( int winid, int channel, int * retval );
extern FResult plfapife_soc_RearChannels( int winid, int channel, int * retval );
extern FResult plfapife_soc_SetChannel( int winid, int channel );
#define plfapife_soc_Channel1  ((int)1)
#define plfapife_soc_Channel1_CONSTANT  1
#define plfapife_soc_Channel2  ((int)2)
#define plfapife_soc_Channel2_CONSTANT  2
#define plfapife_soc_Channel3  ((int)3)
#define plfapife_soc_Channel3_CONSTANT  3
extern FResult plfapife_ssm_GetMeasValid( int winid, Bool * Valid, Nat32 * retval );
extern FResult plfapife_ssm_GetSigStrength( int winid, Nat32 * Strength, Nat32 * retval );
extern FResult plfapife_ssm_GetSigStrengthRange( int winid, Nat32 * MinStrength, Nat32 * MaxStrength, Nat32 * retval );
extern FResult plfapife_ssm_Start( int winid, Bool * Avail, Nat32 * retval );
extern FResult plfapife_ssm_Stop( int winid, Bool * Stopped, Nat32 * retval );
extern FResult plfapife_ssys_GetSoundSystem( int winid, Nat32 * retval );
#define plfapife_ssys_ContainsData  ((Nat32)16384)
#define plfapife_ssys_ContainsData_CONSTANT  16384
#define plfapife_ssys_ContainsDolbyProLogic  ((Nat32)131072)
#define plfapife_ssys_ContainsDolbyProLogic_CONSTANT  131072
#define plfapife_ssys_ContainsDual  ((Nat32)32768)
#define plfapife_ssys_ContainsDual_CONSTANT  32768
#define plfapife_ssys_ContainsDynamicRangeCompression  ((Nat32)262144)
#define plfapife_ssys_ContainsDynamicRangeCompression_CONSTANT  262144
#define plfapife_ssys_ContainsKaraoke  ((Nat32)524288)
#define plfapife_ssys_ContainsKaraoke_CONSTANT  524288
#define plfapife_ssys_ContainsUnrelated  ((Nat32)65536)
#define plfapife_ssys_ContainsUnrelated_CONSTANT  65536
#define plfapife_ssys_Is2CS  ((Nat32)128)
#define plfapife_ssys_Is2CS_CONSTANT  128
#define plfapife_ssys_IsAC3  ((Nat32)2048)
#define plfapife_ssys_IsAC3_CONSTANT  2048
#define plfapife_ssys_IsAC3Plus  ((Nat32)1048576)
#define plfapife_ssys_IsAC3Plus_CONSTANT  1048576
#define plfapife_ssys_IsAM  ((Nat32)16)
#define plfapife_ssys_IsAM_CONSTANT  16
#define plfapife_ssys_IsAnalog  ((Nat32)2)
#define plfapife_ssys_IsAnalog_CONSTANT  2
#define plfapife_ssys_IsBaseband  ((Nat32)8)
#define plfapife_ssys_IsBaseband_CONSTANT  8
#define plfapife_ssys_IsBTSC  ((Nat32)256)
#define plfapife_ssys_IsBTSC_CONSTANT  256
#define plfapife_ssys_IsDigital  ((Nat32)4)
#define plfapife_ssys_IsDigital_CONSTANT  4
#define plfapife_ssys_IsDTS  ((Nat32)8192)
#define plfapife_ssys_IsDTS_CONSTANT  8192
#define plfapife_ssys_IsEIAJ  ((Nat32)512)
#define plfapife_ssys_IsEIAJ_CONSTANT  512
#define plfapife_ssys_IsFM  ((Nat32)32)
#define plfapife_ssys_IsFM_CONSTANT  32
#define plfapife_ssys_IsHEAAC  ((Nat32)2097152)
#define plfapife_ssys_IsHEAAC_CONSTANT  2097152
#define plfapife_ssys_IsMPEG  ((Nat32)4096)
#define plfapife_ssys_IsMPEG_CONSTANT  4096
#define plfapife_ssys_IsNicam  ((Nat32)64)
#define plfapife_ssys_IsNicam_CONSTANT  64
#define plfapife_ssys_IsPCM  ((Nat32)1024)
#define plfapife_ssys_IsPCM_CONSTANT  1024
#define plfapife_ssys_IsWMA  ((Nat32)4194304)
#define plfapife_ssys_IsWMA_CONSTANT  4194304
#define plfapife_ssys_SoundPresent  ((Nat32)1)
#define plfapife_ssys_SoundPresent_CONSTANT  1
extern FResult plfapife_stcdec_ActivateAlarm( int winid, int alarmid, tmTimeStamp_t minValue, tmTimeStamp_t maxValue, Bool absolute, Nat32 * retval );
extern FResult plfapife_stcdec_AllocateAlarm( int winid, int * alarmid, Nat32 * retval );
extern FResult plfapife_stcdec_CancelAlarm( int winid, int alarmid, Nat32 * retval );
extern FResult plfapife_stcdec_GetAvailableNrAlarms( int winid, Nat32 * AvailableNrAlarms, Nat32 * retval );
extern FResult plfapife_stcdec_GetMaxNrAlarms( int winid, Nat32 * MaxNrAlarms, Nat32 * retval );
extern FResult plfapife_stcdec_GetTime( int winid, tmTimeStamp_t * Value, Nat32 * retval );
extern FResult plfapife_tmc_GetTxtMode( int winid, int * retval );
extern FResult plfapife_tmc_SetTxtMode( int winid, int mode );
#define plfapife_tmc_TxtModeOff  ((int)0)
#define plfapife_tmc_TxtModeOff_CONSTANT  0
#define plfapife_tmc_TxtModeOn  ((int)1)
#define plfapife_tmc_TxtModeOn_CONSTANT  1
#define plfapife_tmc_TxtModeTransparent  ((int)2)
#define plfapife_tmc_TxtModeTransparent_CONSTANT  2
extern FResult plfapife_tsdmx_CancelFilter( int winid, Nat32 subscrId, Nat32 * error );
extern FResult plfapife_tsdmx_CancelListFilter( int winid, Nat32 subscrId, Nat32 * error );
extern FResult plfapife_tsdmx_CancelPes( int winid, Nat32 subscrId, Nat32 * error );
extern FResult plfapife_tsdmx_FreeListBuffer( int windowid, Nat32 subscrId, Nat32 listcookie, Nat32 * error );
extern FResult plfapife_tsdmx_FreePesBuffer( int windowid, Nat32 subscrId, Nat32 datacookie, Nat32 * error );
extern FResult plfapife_tsdmx_FreeSectionBuffer( int windowid, Nat32 subscrId, Nat32 datacookie, Nat32 * error );
extern FResult plfapife_tsdmx_GetAudioDescriptivePid( int windowid, Nat16 * pid, Nat32 * error );
extern FResult plfapife_tsdmx_GetAudioPid( int windowid, Nat16 * pid, Nat32 * error );
extern FResult plfapife_tsdmx_GetAudioStreamType( int windowid, int * streamtype, Nat32 * error );
extern FResult plfapife_tsdmx_GetPcrPid( int windowid, Nat16 * pid, Nat32 * error );
extern FResult plfapife_tsdmx_GetPcrStreamType( int windowid, int * streamtype, Nat32 * error );
extern FResult plfapife_tsdmx_GetScramblingStatus( int windowid, int MediaType, Nat32 * error, int * retval );
extern FResult plfapife_tsdmx_GetVideoPid( int windowid, Nat16 * pid, Nat32 * error );
extern FResult plfapife_tsdmx_GetVideoStreamType( int windowid, int * streamtype, Nat32 * error );
extern FResult plfapife_tsdmx_IsAudioStreamTypeSupported( int windowid, int streamtype, Bool * supported, Nat32 * error );
extern FResult plfapife_tsdmx_IsPcrStreamTypeSupported( int windowid, int streamtype, Bool * supported, Nat32 * error );
extern FResult plfapife_tsdmx_IsRequestAllowed( int winid, Bool * retval );
extern FResult plfapife_tsdmx_IsVideoStreamTypeSupported( int windowid, int streamtype, Bool * supported, Nat32 * error );
extern FResult plfapife_tsdmx_RequestFilter( int winid, int pid, int BufferSize, int CrcMode, Bool ContinuousMode, Nat32 cookie, int FilterDepth, Nat8 * ModeArray, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Nat32 * retval );
extern FResult plfapife_tsdmx_RequestListFilter( int winid, int pid, int BufferSize, int CrcMode, Bool ContinuousMode, Nat32 timeout, Nat32 listLength, Nat32 cookie, int FilterDepth, Nat8 * ModeArray, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Nat32 * retval );
extern FResult plfapife_tsdmx_RequestPes( int winid, int pid, int BufferSize, Nat32 cookie, int FilterDepth, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Nat32 * retval );
extern FResult plfapife_tsdmx_SetAudioDescriptivePid( int windowid, Nat16 pid, Nat32 * error );
extern FResult plfapife_tsdmx_SetAudioPid( int windowid, Nat16 pid, Nat32 * error );
extern FResult plfapife_tsdmx_SetAudioStreamType( int windowid, int streamtype, Nat32 * error );
extern FResult plfapife_tsdmx_SetPcrPid( int windowid, Nat16 pid, Nat32 * error );
extern FResult plfapife_tsdmx_SetPcrStreamType( int windowid, int streamtype, Nat32 * error );
extern FResult plfapife_tsdmx_SetVideoPid( int windowid, Nat16 pid, Nat32 * error );
extern FResult plfapife_tsdmx_SetVideoStreamType( int windowid, int streamtype, Nat32 * error );
extern FResult plfapife_tsdmx_StopAudioDescriptivePid( int windowid, Nat32 * error );
extern FResult plfapife_tsdmx_StopAudioPid( int windowid, Nat32 * error );
extern FResult plfapife_tsdmx_StopPcrPid( int windowid, Nat32 * error );
extern FResult plfapife_tsdmx_StopVideoPid( int windowid, Nat32 * error );
extern FResult plfapife_tsdmx_UpdateFilter( int winid, Nat32 subscrId, int FilterDepth, Nat8 * ModeArray, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Bool * retval );
extern FResult plfapife_tsdmx_UpdateListFilter( int winid, Nat32 subscrId, int FilterDepth, Nat8 * ModeArray, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Bool * retval );
#define plfapife_tsdmx_CrcModeAcceptAllSections  ((int)2)
#define plfapife_tsdmx_CrcModeAcceptAllSections_CONSTANT  2
#define plfapife_tsdmx_CrcModeDontCheckCrc  ((int)3)
#define plfapife_tsdmx_CrcModeDontCheckCrc_CONSTANT  3
#define plfapife_tsdmx_CrcModeSkipBadSections  ((int)1)
#define plfapife_tsdmx_CrcModeSkipBadSections_CONSTANT  1
#define plfapife_tsdmx_FilterDepth  ((int)12)
#define plfapife_tsdmx_FilterDepth_CONSTANT  12
#define plfapife_tsdmx_InvalidSubscrId  ((Nat32)-1)
#define plfapife_tsdmx_InvalidSubscrId_CONSTANT  -1
#define plfapife_tsdmx_MediaTypeAudio  ((int)1)
#define plfapife_tsdmx_MediaTypeAudio_CONSTANT  1
#define plfapife_tsdmx_MediaTypeAudioDesc  ((int)3)
#define plfapife_tsdmx_MediaTypeAudioDesc_CONSTANT  3
#define plfapife_tsdmx_MediaTypeVideo  ((int)2)
#define plfapife_tsdmx_MediaTypeVideo_CONSTANT  2
#define plfapife_tsdmx_NotScrambled  ((int)2)
#define plfapife_tsdmx_NotScrambled_CONSTANT  2
#define plfapife_tsdmx_Scrambled  ((int)3)
#define plfapife_tsdmx_Scrambled_CONSTANT  3
#define plfapife_tsdmx_ScramblingUnknown  ((int)1)
#define plfapife_tsdmx_ScramblingUnknown_CONSTANT  1
#define plfapife_tsdmx_StreamTypeaac  ((int)14)
#define plfapife_tsdmx_StreamTypeaac_CONSTANT  14
#define plfapife_tsdmx_StreamTypeac3  ((int)10)
#define plfapife_tsdmx_StreamTypeac3_CONSTANT  10
#define plfapife_tsdmx_StreamTypeddplus  ((int)17)
#define plfapife_tsdmx_StreamTypeddplus_CONSTANT  17
#define plfapife_tsdmx_StreamTypedivx  ((int)12)
#define plfapife_tsdmx_StreamTypedivx_CONSTANT  12
#define plfapife_tsdmx_StreamTypedts  ((int)18)
#define plfapife_tsdmx_StreamTypedts_CONSTANT  18
#define plfapife_tsdmx_StreamTypeh264  ((int)11)
#define plfapife_tsdmx_StreamTypeh264_CONSTANT  11
#define plfapife_tsdmx_StreamTypeheaac  ((int)15)
#define plfapife_tsdmx_StreamTypeheaac_CONSTANT  15
#define plfapife_tsdmx_StreamTypeInvalid  ((int)0)
#define plfapife_tsdmx_StreamTypeInvalid_CONSTANT  0
#define plfapife_tsdmx_StreamTypemma  ((int)20)
#define plfapife_tsdmx_StreamTypemma_CONSTANT  20
#define plfapife_tsdmx_StreamTypemmw  ((int)19)
#define plfapife_tsdmx_StreamTypemmw_CONSTANT  19
#define plfapife_tsdmx_StreamTypemp1a  ((int)4)
#define plfapife_tsdmx_StreamTypemp1a_CONSTANT  4
#define plfapife_tsdmx_StreamTypemp1v  ((int)1)
#define plfapife_tsdmx_StreamTypemp1v_CONSTANT  1
#define plfapife_tsdmx_StreamTypemp2a  ((int)5)
#define plfapife_tsdmx_StreamTypemp2a_CONSTANT  5
#define plfapife_tsdmx_StreamTypemp2v  ((int)2)
#define plfapife_tsdmx_StreamTypemp2v_CONSTANT  2
#define plfapife_tsdmx_StreamTypemp4a  ((int)6)
#define plfapife_tsdmx_StreamTypemp4a_CONSTANT  6
#define plfapife_tsdmx_StreamTypemp4v  ((int)3)
#define plfapife_tsdmx_StreamTypemp4v_CONSTANT  3
#define plfapife_tsdmx_StreamTypeOther  ((int)21)
#define plfapife_tsdmx_StreamTypeOther_CONSTANT  21
#define plfapife_tsdmx_StreamTypepcr  ((int)9)
#define plfapife_tsdmx_StreamTypepcr_CONSTANT  9
#define plfapife_tsdmx_StreamTypesubt  ((int)8)
#define plfapife_tsdmx_StreamTypesubt_CONSTANT  8
#define plfapife_tsdmx_StreamTypettxt  ((int)7)
#define plfapife_tsdmx_StreamTypettxt_CONSTANT  7
#define plfapife_tsdmx_StreamTypevc1  ((int)13)
#define plfapife_tsdmx_StreamTypevc1_CONSTANT  13
#define plfapife_tsdmx_StreamTypewma  ((int)16)
#define plfapife_tsdmx_StreamTypewma_CONSTANT  16
extern FResult plfapife_tsdmxex_CancelFilter( int winid, Nat32 subscrId, Nat32 * error );
extern FResult plfapife_tsdmxex_CancelListFilter( int winid, Nat32 subscrId, Nat32 * error );
extern FResult plfapife_tsdmxex_CancelPes( int winid, Nat32 subscrId, Nat32 * error );
extern FResult plfapife_tsdmxex_CancelPesList( int winid, Nat32 subscrId, Nat32 * error );
extern FResult plfapife_tsdmxex_FreeListBuffer( int windowid, Nat32 subscrId, Nat32 listcookie, Nat32 * error );
extern FResult plfapife_tsdmxex_FreePesBuffer( int windowid, Nat32 subscrId, Nat32 datacookie, Nat32 * error );
extern FResult plfapife_tsdmxex_FreePesListBuffer( int windowid, Nat32 subscrId, Nat32 listcookie, Nat32 * error );
extern FResult plfapife_tsdmxex_FreeSectionBuffer( int windowid, Nat32 subscrId, Nat32 datacookie, Nat32 * error );
extern FResult plfapife_tsdmxex_GetAudioDescriptivePid( int windowid, Nat16 * pid, Nat32 * error );
extern FResult plfapife_tsdmxex_GetAudioPid( int windowid, Nat16 * pid, Nat32 * error );
extern FResult plfapife_tsdmxex_GetAudioStreamType( int windowid, int * streamtype, Nat32 * error );
extern FResult plfapife_tsdmxex_GetPcrPid( int windowid, Nat16 * pid, Nat32 * error );
extern FResult plfapife_tsdmxex_GetPcrStreamType( int windowid, int * streamtype, Nat32 * error );
extern FResult plfapife_tsdmxex_GetScramblingStatus( int windowid, int MediaType, Nat32 * error, int * retval );
extern FResult plfapife_tsdmxex_GetVideoPid( int windowid, Nat16 * pid, Nat32 * error );
extern FResult plfapife_tsdmxex_GetVideoStreamType( int windowid, int * streamtype, Nat32 * error );
extern FResult plfapife_tsdmxex_IsAudioStreamTypeSupported( int windowid, int streamtype, Bool * supported, Nat32 * error );
extern FResult plfapife_tsdmxex_IsPcrStreamTypeSupported( int windowid, int streamtype, Bool * supported, Nat32 * error );
extern FResult plfapife_tsdmxex_IsRequestAllowed( int winid, Bool * retval );
extern FResult plfapife_tsdmxex_IsVideoStreamTypeSupported( int windowid, int streamtype, Bool * supported, Nat32 * error );
extern FResult plfapife_tsdmxex_RequestFilter( int winid, int pid, int BufferSize, int CrcMode, Bool ContinuousMode, Nat32 cookie, int FilterDepth, Nat8 * ModeArray, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Nat32 * retval );
extern FResult plfapife_tsdmxex_RequestListFilter( int winid, int pid, int BufferSize, int CrcMode, Bool ContinuousMode, Nat32 timeout, Nat32 listLength, Nat32 cookie, int FilterDepth, Nat8 * ModeArray, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Nat32 * retval );
extern FResult plfapife_tsdmxex_RequestPes( int winid, int pid, int BufferSize, Nat32 cookie, int FilterDepth, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Nat32 * retval );
extern FResult plfapife_tsdmxex_RequestPesList( int winid, int pid, int BufferSize, Nat32 timeout, Nat32 listLength, Nat32 cookie, int FilterDepth, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Nat32 * retval );
extern FResult plfapife_tsdmxex_SetAudioDescriptivePid( int windowid, Nat16 pid, Nat32 * error );
extern FResult plfapife_tsdmxex_SetAudioPid( int windowid, Nat16 pid, Nat32 * error );
extern FResult plfapife_tsdmxex_SetAudioStreamType( int windowid, int streamtype, Nat32 * error );
extern FResult plfapife_tsdmxex_SetPcrPid( int windowid, Nat16 pid, Nat32 * error );
extern FResult plfapife_tsdmxex_SetPcrStreamType( int windowid, int streamtype, Nat32 * error );
extern FResult plfapife_tsdmxex_SetVideoPid( int windowid, Nat16 pid, Nat32 * error );
extern FResult plfapife_tsdmxex_SetVideoStreamType( int windowid, int streamtype, Nat32 * error );
extern FResult plfapife_tsdmxex_StopAudioDescriptivePid( int windowid, Nat32 * error );
extern FResult plfapife_tsdmxex_StopAudioPid( int windowid, Nat32 * error );
extern FResult plfapife_tsdmxex_StopPcrPid( int windowid, Nat32 * error );
extern FResult plfapife_tsdmxex_StopVideoPid( int windowid, Nat32 * error );
extern FResult plfapife_tsdmxex_UpdateFilter( int winid, Nat32 subscrId, int FilterDepth, Nat8 * ModeArray, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Bool * retval );
extern FResult plfapife_tsdmxex_UpdateListFilter( int winid, Nat32 subscrId, int FilterDepth, Nat8 * ModeArray, Nat8 * MatchArray, Nat8 * MaskArray, Nat32 * error, Bool * retval );
#define plfapife_tsdmxex_CrcModeAcceptAllSections  ((int)2)
#define plfapife_tsdmxex_CrcModeAcceptAllSections_CONSTANT  2
#define plfapife_tsdmxex_CrcModeDontCheckCrc  ((int)3)
#define plfapife_tsdmxex_CrcModeDontCheckCrc_CONSTANT  3
#define plfapife_tsdmxex_CrcModeSkipBadSections  ((int)1)
#define plfapife_tsdmxex_CrcModeSkipBadSections_CONSTANT  1
#define plfapife_tsdmxex_FilterDepth  ((int)12)
#define plfapife_tsdmxex_FilterDepth_CONSTANT  12
#define plfapife_tsdmxex_InvalidSubscrId  ((Nat32)-1)
#define plfapife_tsdmxex_InvalidSubscrId_CONSTANT  -1
#define plfapife_tsdmxex_MediaTypeAudio  ((int)1)
#define plfapife_tsdmxex_MediaTypeAudio_CONSTANT  1
#define plfapife_tsdmxex_MediaTypeAudioDesc  ((int)3)
#define plfapife_tsdmxex_MediaTypeAudioDesc_CONSTANT  3
#define plfapife_tsdmxex_MediaTypeVideo  ((int)2)
#define plfapife_tsdmxex_MediaTypeVideo_CONSTANT  2
#define plfapife_tsdmxex_NotScrambled  ((int)2)
#define plfapife_tsdmxex_NotScrambled_CONSTANT  2
#define plfapife_tsdmxex_Scrambled  ((int)3)
#define plfapife_tsdmxex_Scrambled_CONSTANT  3
#define plfapife_tsdmxex_ScramblingUnknown  ((int)1)
#define plfapife_tsdmxex_ScramblingUnknown_CONSTANT  1
#define plfapife_tsdmxex_StreamTypeaac  ((int)14)
#define plfapife_tsdmxex_StreamTypeaac_CONSTANT  14
#define plfapife_tsdmxex_StreamTypeac3  ((int)10)
#define plfapife_tsdmxex_StreamTypeac3_CONSTANT  10
#define plfapife_tsdmxex_StreamTypeddplus  ((int)17)
#define plfapife_tsdmxex_StreamTypeddplus_CONSTANT  17
#define plfapife_tsdmxex_StreamTypedivx  ((int)12)
#define plfapife_tsdmxex_StreamTypedivx_CONSTANT  12
#define plfapife_tsdmxex_StreamTypedts  ((int)18)
#define plfapife_tsdmxex_StreamTypedts_CONSTANT  18
#define plfapife_tsdmxex_StreamTypeh264  ((int)11)
#define plfapife_tsdmxex_StreamTypeh264_CONSTANT  11
#define plfapife_tsdmxex_StreamTypeheaac  ((int)15)
#define plfapife_tsdmxex_StreamTypeheaac_CONSTANT  15
#define plfapife_tsdmxex_StreamTypeInvalid  ((int)0)
#define plfapife_tsdmxex_StreamTypeInvalid_CONSTANT  0
#define plfapife_tsdmxex_StreamTypemma  ((int)20)
#define plfapife_tsdmxex_StreamTypemma_CONSTANT  20
#define plfapife_tsdmxex_StreamTypemmw  ((int)19)
#define plfapife_tsdmxex_StreamTypemmw_CONSTANT  19
#define plfapife_tsdmxex_StreamTypemp1a  ((int)4)
#define plfapife_tsdmxex_StreamTypemp1a_CONSTANT  4
#define plfapife_tsdmxex_StreamTypemp1v  ((int)1)
#define plfapife_tsdmxex_StreamTypemp1v_CONSTANT  1
#define plfapife_tsdmxex_StreamTypemp2a  ((int)5)
#define plfapife_tsdmxex_StreamTypemp2a_CONSTANT  5
#define plfapife_tsdmxex_StreamTypemp2v  ((int)2)
#define plfapife_tsdmxex_StreamTypemp2v_CONSTANT  2
#define plfapife_tsdmxex_StreamTypemp4a  ((int)6)
#define plfapife_tsdmxex_StreamTypemp4a_CONSTANT  6
#define plfapife_tsdmxex_StreamTypemp4v  ((int)3)
#define plfapife_tsdmxex_StreamTypemp4v_CONSTANT  3
#define plfapife_tsdmxex_StreamTypeOther  ((int)21)
#define plfapife_tsdmxex_StreamTypeOther_CONSTANT  21
#define plfapife_tsdmxex_StreamTypepcr  ((int)9)
#define plfapife_tsdmxex_StreamTypepcr_CONSTANT  9
#define plfapife_tsdmxex_StreamTypesubt  ((int)8)
#define plfapife_tsdmxex_StreamTypesubt_CONSTANT  8
#define plfapife_tsdmxex_StreamTypettxt  ((int)7)
#define plfapife_tsdmxex_StreamTypettxt_CONSTANT  7
#define plfapife_tsdmxex_StreamTypevc1  ((int)13)
#define plfapife_tsdmxex_StreamTypevc1_CONSTANT  13
#define plfapife_tsdmxex_StreamTypewma  ((int)16)
#define plfapife_tsdmxex_StreamTypewma_CONSTANT  16
extern FResult plfapife_tun_EnableAfc( int winid, Bool enable, Nat32 * retval );
extern FResult plfapife_tun_GetAfcEnabled( int winid, Bool * Enabled, Nat32 * retval );
extern FResult plfapife_tun_GetAfcSupp( int winid, Bool * Supp, Nat32 * retval );
extern FResult plfapife_tun_GetAfcValue( int winid, tmFe_AfcValue_t * Value, Nat32 * retval );
extern FResult plfapife_tun_GetChan( int winid, Nat32 * Chan, Nat32 * retval );
extern FResult plfapife_tun_GetChanOffset( int winid, Nat32 * Offset, Nat32 * retval );
extern FResult plfapife_tun_GetChanOffsetRange( int winid, Nat32 * MinOffset, Nat32 * MaxOffset, Nat32 * retval );
extern FResult plfapife_tun_GetFreq( int winid, Nat32 * Freq, Nat32 * retval );
extern FResult plfapife_tun_GetFreqRange( int winid, Nat32 * MinFreq, Nat32 * MaxFreq, Nat32 * retval );
extern FResult plfapife_tun_GetSearchMode( int winid, tmFe_SearchMode_t * Mode, Nat32 * retval );
extern FResult plfapife_tun_GetSearchModeSupp( int winid, tmFe_SearchMode_t mode, Bool * Supp, Nat32 * retval );
extern FResult plfapife_tun_GetSearchState( int winid, tmFe_SearchState_t * State, Nat32 * retval );
extern FResult plfapife_tun_GetStationPresent( int winid, Bool * StationPresent, Nat32 * retval );
extern FResult plfapife_tun_GetTvSystem( int winid, tmFe_TvSystem_t * TvSystem, Nat32 * retval );
extern FResult plfapife_tun_GetTvSystemSupp( int winid, tmFe_TvSystem_t tvSystem, Bool * Supp, Nat32 * retval );
extern FResult plfapife_tun_SetChan( int winid, Nat32 chan, Nat32 offset, Nat32 * retval );
extern FResult plfapife_tun_SetFreq( int winid, Nat32 freq, Bool finetune, Nat32 * retval );
extern FResult plfapife_tun_SetTunerGain( int winid, int gain );
extern FResult plfapife_tun_SetTvSystem( int winid, tmFe_TvSystem_t TvSystem, Nat32 * retval );
extern FResult plfapife_tun_StartSearch( int winid, tmFe_SearchMode_t mode, Nat32 endFreq, Nat32 * retval );
extern FResult plfapife_tun_StopSearch( int winid, Nat32 * retval );
#define plfapife_tun_TunerGainHigh  ((int)0)
#define plfapife_tun_TunerGainHigh_CONSTANT  0
#define plfapife_tun_TunerGainLow  ((int)1)
#define plfapife_tun_TunerGainLow_CONSTANT  1
extern FResult plfapife_vbiins_InsertWss( int winid, int WssData );
#define plfapife_vbiins_WSSBoxCentre14by9  ((int)1)
#define plfapife_vbiins_WSSBoxCentre14by9_CONSTANT  1
#define plfapife_vbiins_WSSBoxCentre16by9  ((int)11)
#define plfapife_vbiins_WSSBoxCentre16by9_CONSTANT  11
#define plfapife_vbiins_WSSBoxGreaterCentre16by9  ((int)13)
#define plfapife_vbiins_WSSBoxGreaterCentre16by9_CONSTANT  13
#define plfapife_vbiins_WSSBoxTop14by9  ((int)2)
#define plfapife_vbiins_WSSBoxTop14by9_CONSTANT  2
#define plfapife_vbiins_WSSBoxTop16by9  ((int)4)
#define plfapife_vbiins_WSSBoxTop16by9_CONSTANT  4
#define plfapife_vbiins_WSSFullFormat16by9  ((int)7)
#define plfapife_vbiins_WSSFullFormat16by9_CONSTANT  7
#define plfapife_vbiins_WSSFullFormat4by3  ((int)8)
#define plfapife_vbiins_WSSFullFormat4by3_CONSTANT  8
#define plfapife_vbiins_WSSFullFormatShortProtect4by3  ((int)14)
#define plfapife_vbiins_WSSFullFormatShortProtect4by3_CONSTANT  14
#define plfapife_vbiins_WSSInvalidateData  ((int)0)
#define plfapife_vbiins_WSSInvalidateData_CONSTANT  0
extern FResult plfapife_vbisl_EnableAutoSlicing( int winid, Bool enable, Nat32 * retval );
extern FResult plfapife_vbisl_GetAutoSlicingEnabled( int winid, Bool * Enabled, Nat32 * retval );
extern FResult plfapife_vbisl_GetVbiLines( int winid, Nat16 size, Nat32 * ActNrVbiLines, Nat32 * Lines, tmVbiSlice2_VbiDataSet_t * pDataTypes, Nat32 * retval );
extern FResult plfapife_vbisl_SetSlicermode( int winid, Nat32 subscriptions, Nat32 * retval );
extern FResult plfapife_vbisl_SetVbiLines( int winid, Nat16 nrVbiLines, Nat32 * pLines, tmVbiSlice2_VbiDataSet_t * DataTypes, Nat32 * retval );
#define plfapife_vbisl_Cc  ((Nat32)1)
#define plfapife_vbisl_Cc_CONSTANT  1
#define plfapife_vbisl_Cgms  ((Nat32)16)
#define plfapife_vbisl_Cgms_CONSTANT  16
#define plfapife_vbisl_Gemstar  ((Nat32)8)
#define plfapife_vbisl_Gemstar_CONSTANT  8
#define plfapife_vbisl_VbiSliceLinesNotSet  ((Nat32)2049)
#define plfapife_vbisl_VbiSliceLinesNotSet_CONSTANT  2049
#define plfapife_vbisl_Vps  ((Nat32)2)
#define plfapife_vbisl_Vps_CONSTANT  2
#define plfapife_vbisl_Wss  ((Nat32)4)
#define plfapife_vbisl_Wss_CONSTANT  4
#define plfapife_vbisl_Wst  ((Nat32)32)
#define plfapife_vbisl_Wst_CONSTANT  32
extern FResult plfapife_vclip_AddData( int winid, Nat32 id, Nat32 size, Address Data, Bool endOfData, Nat32 * retval );
extern FResult plfapife_vclip_EnableClipPlay( int winid, Bool enable, Nat32 * retval );
extern FResult plfapife_vclip_GetAvailableNrBuffers( int winid, Nat32 * AvailableNrBuffers, Nat32 * retval );
extern FResult plfapife_vclip_GetClipPlayEnabled( int winid, Bool * Enable, Nat32 * retval );
extern FResult plfapife_vclip_GetMaxNrBuffers( int winid, Nat32 * MaxNrBuffers, Nat32 * retval );
extern FResult plfapife_vclip_GetState( int winid, tmDigVdec_ClipDecodingState_t * ClipDecodingState, Nat32 * retval );
extern FResult plfapife_vclip_Start( int winid, Nat32 * retval );
extern FResult plfapife_vclip_Stop( int winid, Nat32 * retval );
extern FResult plfapife_vclipex_AddData( int winid, Nat32 id, Nat32 size, Address Data, Bool endOfData, Nat32 * retval );
extern FResult plfapife_vclipex_EnableClipPlay( int winid, Bool enable, Nat32 * retval );
extern FResult plfapife_vclipex_EnableSeek( int winid, Bool enable, Nat32 * retval );
extern FResult plfapife_vclipex_GetAvailableNrBuffers( int winid, Nat32 * AvailableNrBuffers, Nat32 * retval );
extern FResult plfapife_vclipex_GetClipPlayEnabled( int winid, Bool * Enable, Nat32 * retval );
extern FResult plfapife_vclipex_GetMaxNrBuffers( int winid, Nat32 * MaxNrBuffers, Nat32 * retval );
extern FResult plfapife_vclipex_GetSeekEnabled( int winid, Bool * penable, Nat32 * retval );
extern FResult plfapife_vclipex_GetState( int winid, tmDigVdec_ClipDecodingState_t * ClipDecodingState, Nat32 * retval );
extern FResult plfapife_vclipex_GetTotalSeekTime( int winid, Nat32 * ptotalseektime, Nat32 * retval );
extern FResult plfapife_vclipex_Pause( int winid, Nat32 * retval );
extern FResult plfapife_vclipex_Resume( int winid, Nat32 * retval );
extern FResult plfapife_vclipex_Seek( int winid, Nat32 msec, Nat32 * retval );
extern FResult plfapife_vclipex_Start( int winid, Nat32 * retval );
extern FResult plfapife_vclipex_Stop( int winid, Nat32 * retval );
extern FResult plfapife_vfr_FreezeAllowed( int winid, Bool * retval );
extern FResult plfapife_vfr_FreezeSupported( int winid, Bool * retval );
extern FResult plfapife_vfr_GetStrobe( int winid, int * retval );
extern FResult plfapife_vfr_IsFrozen( int winid, Bool * retval );
extern FResult plfapife_vfr_SetFreeze( int winid, Bool mode );
extern FResult plfapife_vfr_SetStrobe( int winid, int period );
extern FResult plfapife_vfr_StrobeAllowed( int winid, Bool * retval );
extern FResult plfapife_vfr_StrobeSupported( int winid, Bool * retval );
extern FResult plfapife_vip_GetFieldFrequency( int winid, int * retval );
extern FResult plfapife_vip_GetImageFormat( int winid, int * retval );
extern FResult plfapife_vip_GetInterlace( int winid, int * retval );
extern FResult plfapife_vip_GetMacroVisionType( int winid, int * retval );
extern FResult plfapife_vip_GetNumberOfFrameLines( int winid, int * retval );
extern FResult plfapife_vip_GetNumberOfVisibleLines( int winid, int * retval );
extern FResult plfapife_vip_GetNumberOfVisiblePixels( int winid, int * retval );
extern FResult plfapife_vip_GetSignalPresent( int winid, int * retval );
extern FResult plfapife_vip_GetVideoCoding( int winid, int * retval );
extern FResult plfapife_vip_GetVideoDetectionSensitivity( int winid, int * retval );
extern FResult plfapife_vip_GetVideoPresent( int winid, int * retval );
extern FResult plfapife_vip_GetVideoProtection( int winid, int * retval );
extern FResult plfapife_vip_IsFilmMode( int winid, Bool * retval );
extern FResult plfapife_vip_IsFromVcr( int winid, Bool * retval );
extern FResult plfapife_vip_IsPCFormat( int winid, int pixels, int lines, int scantype, Bool * retval );
extern FResult plfapife_vip_IsVideoDetectionSensitivitySupported( int winid, int sensitivity, Bool * retval );
extern FResult plfapife_vip_SetVideoDetectionSensitivity( int winid, int sensitivity );
#define plfapife_vip_FieldFrequencyInvalid  ((int)-1)
#define plfapife_vip_FieldFrequencyInvalid_CONSTANT  -1
#define plfapife_vip_FieldFrequencyUnknown  ((int)0)
#define plfapife_vip_FieldFrequencyUnknown_CONSTANT  0
#define plfapife_vip_ImageFormat14by9Center  ((int)3)
#define plfapife_vip_ImageFormat14by9Center_CONSTANT  3
#define plfapife_vip_ImageFormat14by9Top  ((int)2)
#define plfapife_vip_ImageFormat14by9Top_CONSTANT  2
#define plfapife_vip_ImageFormat16by9Center  ((int)5)
#define plfapife_vip_ImageFormat16by9Center_CONSTANT  5
#define plfapife_vip_ImageFormat16by9FullFormat  ((int)9)
#define plfapife_vip_ImageFormat16by9FullFormat_CONSTANT  9
#define plfapife_vip_ImageFormat16by9Top  ((int)4)
#define plfapife_vip_ImageFormat16by9Top_CONSTANT  4
#define plfapife_vip_ImageFormat16by9Use14by9  ((int)7)
#define plfapife_vip_ImageFormat16by9Use14by9_CONSTANT  7
#define plfapife_vip_ImageFormat16by9Use4by3  ((int)8)
#define plfapife_vip_ImageFormat16by9Use4by3_CONSTANT  8
#define plfapife_vip_ImageFormat4by3FullFormat  ((int)1)
#define plfapife_vip_ImageFormat4by3FullFormat_CONSTANT  1
#define plfapife_vip_ImageFormat4by3Use14by9  ((int)6)
#define plfapife_vip_ImageFormat4by3Use14by9_CONSTANT  6
#define plfapife_vip_ImageFormatInvalid  ((int)-1)
#define plfapife_vip_ImageFormatInvalid_CONSTANT  -1
#define plfapife_vip_ImageFormatMoreThan16by9Center  ((int)10)
#define plfapife_vip_ImageFormatMoreThan16by9Center_CONSTANT  10
#define plfapife_vip_ImageFormatUnknown  ((int)0)
#define plfapife_vip_ImageFormatUnknown_CONSTANT  0
#define plfapife_vip_InterlaceFourTwo  ((int)3)
#define plfapife_vip_InterlaceFourTwo_CONSTANT  3
#define plfapife_vip_InterlaceInvalid  ((int)-1)
#define plfapife_vip_InterlaceInvalid_CONSTANT  -1
#define plfapife_vip_InterlaceOneOne  ((int)1)
#define plfapife_vip_InterlaceOneOne_CONSTANT  1
#define plfapife_vip_InterlaceTwoOne  ((int)2)
#define plfapife_vip_InterlaceTwoOne_CONSTANT  2
#define plfapife_vip_InterlaceUnknown  ((int)0)
#define plfapife_vip_InterlaceUnknown_CONSTANT  0
#define plfapife_vip_MacroVisionAgc  ((int)1)
#define plfapife_vip_MacroVisionAgc_CONSTANT  1
#define plfapife_vip_MacroVisionColorstripeType2  ((int)2)
#define plfapife_vip_MacroVisionColorstripeType2_CONSTANT  2
#define plfapife_vip_MacroVisionColorstripeType3  ((int)3)
#define plfapife_vip_MacroVisionColorstripeType3_CONSTANT  3
#define plfapife_vip_MacroVisionInvalid  ((int)-1)
#define plfapife_vip_MacroVisionInvalid_CONSTANT  -1
#define plfapife_vip_MacroVisionUnknown  ((int)0)
#define plfapife_vip_MacroVisionUnknown_CONSTANT  0
#define plfapife_vip_NumberOfLinesInvalid  ((int)-1)
#define plfapife_vip_NumberOfLinesInvalid_CONSTANT  -1
#define plfapife_vip_NumberOfLinesUnknown  ((int)0)
#define plfapife_vip_NumberOfLinesUnknown_CONSTANT  0
#define plfapife_vip_ScanTypeInterlaced  ((int)1)
#define plfapife_vip_ScanTypeInterlaced_CONSTANT  1
#define plfapife_vip_ScanTypeProgressive  ((int)2)
#define plfapife_vip_ScanTypeProgressive_CONSTANT  2
#define plfapife_vip_ScanTypeUnknown  ((int)0)
#define plfapife_vip_ScanTypeUnknown_CONSTANT  0
#define plfapife_vip_SignalPresenceDetected  ((int)1)
#define plfapife_vip_SignalPresenceDetected_CONSTANT  1
#define plfapife_vip_SignalPresenceInvalid  ((int)-1)
#define plfapife_vip_SignalPresenceInvalid_CONSTANT  -1
#define plfapife_vip_SignalPresenceNotDetected  ((int)2)
#define plfapife_vip_SignalPresenceNotDetected_CONSTANT  2
#define plfapife_vip_SignalPresenceUnknown  ((int)0)
#define plfapife_vip_SignalPresenceUnknown_CONSTANT  0
#define plfapife_vip_VideoCodingCvbs  ((int)1)
#define plfapife_vip_VideoCodingCvbs_CONSTANT  1
#define plfapife_vip_VideoCodingInvalid  ((int)-1)
#define plfapife_vip_VideoCodingInvalid_CONSTANT  -1
#define plfapife_vip_VideoCodingRgb  ((int)6)
#define plfapife_vip_VideoCodingRgb_CONSTANT  6
#define plfapife_vip_VideoCodingRgb2FH  ((int)7)
#define plfapife_vip_VideoCodingRgb2FH_CONSTANT  7
#define plfapife_vip_VideoCodingRgb3FH  ((int)8)
#define plfapife_vip_VideoCodingRgb3FH_CONSTANT  8
#define plfapife_vip_VideoCodingUnknown  ((int)0)
#define plfapife_vip_VideoCodingUnknown_CONSTANT  0
#define plfapife_vip_VideoCodingYc  ((int)2)
#define plfapife_vip_VideoCodingYc_CONSTANT  2
#define plfapife_vip_VideoCodingYPbPr  ((int)9)
#define plfapife_vip_VideoCodingYPbPr_CONSTANT  9
#define plfapife_vip_VideoCodingYPbPr2FH  ((int)10)
#define plfapife_vip_VideoCodingYPbPr2FH_CONSTANT  10
#define plfapife_vip_VideoCodingYPbPr3FH  ((int)11)
#define plfapife_vip_VideoCodingYPbPr3FH_CONSTANT  11
#define plfapife_vip_VideoCodingYuv  ((int)3)
#define plfapife_vip_VideoCodingYuv_CONSTANT  3
#define plfapife_vip_VideoCodingYuv2FH  ((int)4)
#define plfapife_vip_VideoCodingYuv2FH_CONSTANT  4
#define plfapife_vip_VideoCodingYuv3FH  ((int)5)
#define plfapife_vip_VideoCodingYuv3FH_CONSTANT  5
#define plfapife_vip_VideoDetectionSensitivityAuto  ((int)4)
#define plfapife_vip_VideoDetectionSensitivityAuto_CONSTANT  4
#define plfapife_vip_VideoDetectionSensitivityIncreased  ((int)3)
#define plfapife_vip_VideoDetectionSensitivityIncreased_CONSTANT  3
#define plfapife_vip_VideoDetectionSensitivityNormal  ((int)2)
#define plfapife_vip_VideoDetectionSensitivityNormal_CONSTANT  2
#define plfapife_vip_VideoDetectionSensitivityReduced  ((int)1)
#define plfapife_vip_VideoDetectionSensitivityReduced_CONSTANT  1
#define plfapife_vip_VideoDetectionSensitivityUnknown  ((int)0)
#define plfapife_vip_VideoDetectionSensitivityUnknown_CONSTANT  0
#define plfapife_vip_VideoPresenceDetected  ((int)1)
#define plfapife_vip_VideoPresenceDetected_CONSTANT  1
#define plfapife_vip_VideoPresenceInvalid  ((int)-1)
#define plfapife_vip_VideoPresenceInvalid_CONSTANT  -1
#define plfapife_vip_VideoPresenceNotDetected  ((int)2)
#define plfapife_vip_VideoPresenceNotDetected_CONSTANT  2
#define plfapife_vip_VideoPresenceUnknown  ((int)0)
#define plfapife_vip_VideoPresenceUnknown_CONSTANT  0
#define plfapife_vip_VideoProtectionCopyProtected  ((int)1)
#define plfapife_vip_VideoProtectionCopyProtected_CONSTANT  1
#define plfapife_vip_VideoProtectionInvalid  ((int)-1)
#define plfapife_vip_VideoProtectionInvalid_CONSTANT  -1
#define plfapife_vip_VideoProtectionMacroVision  ((int)3)
#define plfapife_vip_VideoProtectionMacroVision_CONSTANT  3
#define plfapife_vip_VideoProtectionScrambled  ((int)2)
#define plfapife_vip_VideoProtectionScrambled_CONSTANT  2
#define plfapife_vip_VideoProtectionUnknown  ((int)0)
#define plfapife_vip_VideoProtectionUnknown_CONSTANT  0

/* Functions called by supplier (notifications raised to clients), implemented by clients. */
extern void plfapife_aclipexN_OnBufferAvailable( Nat32 id );
extern void plfapife_aclipexN_OnEndOfData( void );
extern void plfapife_aclipexN_OnPaused( void );
extern void plfapife_aclipexN_OnSeekCompleted( void );
extern void plfapife_aclipexN_OnStarted( void );
extern void plfapife_aclipexN_OnStopped( void );
extern void plfapife_aclipexN_OnTotalSeekTimeChanged( Nat32 totalseektimemsec );
extern void plfapife_aclipN_OnBufferAvailable( Nat32 id );
extern void plfapife_aclipN_OnEndOfData( void );
extern void plfapife_aclipN_OnPaused( void );
extern void plfapife_aclipN_OnStarted( void );
extern void plfapife_aclipN_OnStopped( void );
extern void plfapife_apitestntf_TestResult( Nat32 id, Nat32 result );
extern void plfapife_assmN_OnMeasAborted( void );
extern void plfapife_assmN_OnMeasReady( Nat32 strength );
extern void plfapife_chdec2N_OnBerThresholdCrossed( Nat32 ber, Nat32 berThreshold );
extern void plfapife_chdec2N_OnCarrierPresentChanged( Bool carrier );
extern void plfapife_chdec2N_OnChanBandwidthDetected( tmFe_ChanBandwidth_t bandwith );
extern void plfapife_chdec2N_OnCodeRateDetected( tmFe_CodeRate_t highPrioRate, tmFe_CodeRate_t lowPrioRate );
extern void plfapife_chdec2N_OnConstellationDetected( tmFe_Constellation_t constellation );
extern void plfapife_chdec2N_OnGuardIntervalDetected( tmFe_GuardInterval_t interval );
extern void plfapife_chdec2N_OnHierarchyModeDetected( tmFe_HierarchyMode_t mode );
extern void plfapife_chdec2N_OnIqModeDetected( tmFe_IqMode_t mode );
extern void plfapife_chdec2N_OnTxModeDetected( tmFe_TxMode_t mode );
extern void plfapife_chdecN_OnBerThresholdCrossed( Nat32 ber, Nat32 berThreshold );
extern void plfapife_chdecN_OnCarrierPresentChanged( Bool carrier );
extern void plfapife_chdecN_OnChanBandwidthDetected( tmFe_ChanBandwidth_t bandwith );
extern void plfapife_chdecN_OnCodeRateDetected( tmFe_CodeRate_t highPrioRate, tmFe_CodeRate_t lowPrioRate );
extern void plfapife_chdecN_OnConstellationDetected( tmFe_Constellation_t constellation );
extern void plfapife_chdecN_OnGuardIntervalDetected( tmFe_GuardInterval_t interval );
extern void plfapife_chdecN_OnHierarchyModeDetected( tmFe_HierarchyMode_t mode );
extern void plfapife_chdecN_OnIqModeDetected( tmFe_IqMode_t mode );
extern void plfapife_chdecN_OnTxModeDetected( tmFe_TxMode_t mode );
extern void plfapife_ciplusaintf_AI_ApplicationList( CIPlusHandle handle, Nat16 NbofApplication, CIPlusApplicationInfo_s * list );
extern void plfapife_ciplusammintf_AMMI_AbortRequest( CIPlusHandle handle, Nat16 ammiId, Nat16 byteLen, Nat8 * ptbyte );
extern void plfapife_ciplusammintf_AMMI_AckAbort( CIPlusHandle handle, Nat16 ammiId, Nat16 byteLen, Nat8 * ptbyte );
extern void plfapife_ciplusammintf_AMMI_AckRequest( CIPlusHandle handle, Nat16 ammiId, Nat8 fileOk, CIPlusRequestType_e request_type, Nat32 byteLen, Address shrdmemptByte, Nat16 fileNameLen, Address ptFileName );
extern void plfapife_ciplusammintf_AMMI_Close( CIPlusHandle handle, Nat16 ammiId );
extern void plfapife_ciplusammintf_AMMI_Open( CIPlusHandle handle, Nat16 ammiId );
extern void plfapife_ciplusammintf_AMMI_StartRequest( CIPlusHandle handle, Nat16 ammiId, Nat8 domainLen, Nat8 * ptDomain, Nat8 objectLen, Nat8 * ptObject );
extern void plfapife_cipluscantf_Ca_ListCaSystemId( CIPlusHandle handle, Nat8 nbCaSystemId, CIPlusCaApplicationList_s * listCaSystemId );
extern void plfapife_cipluscantf_Ca_Update( CIPlusHandle handle, Nat16 sessionId, Nat16 programNb, Nat8 versionNb, CIPlusCaEnable_e ProgCaEnable, Nat8 nbStream, CIPlusCaEnableStream_s * streamCaEnable );
extern void plfapife_ciplusccntf_CC_OnBrandID( CIPlusHandle handle, Nat16 brandId );
extern void plfapife_ciplushcntf_HC_ClearRequest( CIPlusHandle handle, Nat16 reference );
extern void plfapife_ciplushcntf_HC_ReplaceRequest( CIPlusHandle handle, Nat16 oldPID, Nat16 newPID, Nat16 reference );
extern void plfapife_ciplushcntf_HC_TuneRequest( CIPlusHandle handle, Nat16 networkId, Nat16 origNetworkId, Nat16 tsId, Nat16 serviceId );
extern void plfapife_ciplusinitntf_ReturnActivate( CIPlusHandle handle, CIPlusResult_e result );
extern void plfapife_ciplusinitntf_ReturnEnd( CIPlusHandle handle, CIPlusResult_e result );
extern void plfapife_ciplusinitntf_ReturnInit( CIPlusHandle handle, CIPlusResult_e result );
extern void plfapife_ciplusmmintf_MMI_Close( CIPlusHandle handle, Nat16 mmiId );
extern void plfapife_ciplusmmintf_MMI_CmdEnquery( CIPlusHandle handle, Nat16 mmiId, Nat16 blind, Nat16 lenAnswer, Nat16 textLen, Nat8 * textPtr );
extern void plfapife_ciplusmmintf_MMI_CmdList( CIPlusHandle handle, Nat16 mmiId, Nat16 nbChoice, Nat16 textLen, Nat8 * textPtr );
extern void plfapife_ciplusmmintf_MMI_CmdMenu( CIPlusHandle handle, Nat16 mmiId, Nat16 nbChoice, Nat16 textLen, Nat8 * textPtr );
extern void plfapife_ciplusmmintf_MMI_Open( CIPlusHandle handle, Nat16 mmiId );
extern void plfapife_ciplusstatusntf_OnStatus( CIPlusHandle handle, CIPlusOrigin_e origin, CIPlusStatus_e status, CIPlusEvent_e event, Nat32 time );
extern void plfapife_ciplusupgrntf_UPGR_Close( CIPlusHandle handle );
extern void plfapife_ciplusupgrntf_UPGR_Open( CIPlusHandle handle );
extern void plfapife_ciplusupgrntf_UPGR_UpgradeComplete( CIPlusHandle handle, CIPlusUPGRReset_e resetRequest );
extern void plfapife_ciplusupgrntf_UPGR_UpgradeProgress( CIPlusHandle handle, Nat16 progress );
extern void plfapife_ciplusupgrntf_UPGR_UpgradeRequest( CIPlusHandle handle, CIPlusUPGRType_e upgrType, Nat16 downloadTime );
extern void plfapife_colN_OnColorSystemChanged( void );
extern void plfapife_colN_OnCombFilterActiveChanged( void );
extern void plfapife_diseqN_OnMsgSent( int cookie );
extern void plfapife_dvbsN_OnLockChanged( int Cookie );
extern void plfapife_feitfN_OnAvailabilityChanged( int nbrgroups, Nat32 * ids );
extern void plfapife_gdripN_OnBufferAvailable( Nat32 id );
extern void plfapife_gdripN_OnEndOfData( void );
extern void plfapife_gdripN_OnFrameDecoded( void );
extern void plfapife_gdripN_OnStarted( void );
extern void plfapife_gdripN_OnStopped( void );
extern void plfapife_hsysN_OnSoundSystemChanged( void );
extern void plfapife_qssmN_OnMeasAborted( void );
extern void plfapife_qssmN_OnMeasReady( Nat32 strength );
extern void plfapife_socN_OnChannelChanged( void );
extern void plfapife_socN_OnSoundPropertiesChanged( int channel );
extern void plfapife_ssmN_OnMeasAborted( void );
extern void plfapife_ssmN_OnMeasReady( Nat32 strength );
extern void plfapife_ssysN_OnSoundSystemChanged( void );
extern void plfapife_stcdecN_OnCancelled( int alarmid );
extern void plfapife_stcdecN_OnDiscontinuity( void );
extern void plfapife_stcdecN_OnExpired( int alarmid, Bool lockState );
extern void plfapife_stcdecN_OnLocked( void );
extern void plfapife_stcdecN_OnUnlocked( void );
extern void plfapife_tsdmxexN_OnAudioDescriptivePidStopped( int winid, Nat16 pid );
extern void plfapife_tsdmxexN_OnAudioPidStopped( int winid, Nat16 pid );
extern void plfapife_tsdmxexN_OnBufferOverflow( int windowid );
extern void plfapife_tsdmxexN_OnPcrPidStopped( int winid, Nat16 pid );
extern void plfapife_tsdmxexN_OnPesArrived( int windowid, Nat32 subscrId, Nat32 Cookie, Nat32 PSize, Address PAddr, Nat32 SSize, Address SAddr, Nat32 DataCookie );
extern void plfapife_tsdmxexN_OnPesCancelled( int windowid, Nat32 subscrId );
extern void plfapife_tsdmxexN_OnPesListArrived( int windowid, Nat32 subscrId, Nat32 Cookie, Nat32 ListCookie, Nat32 nPackets, tmTsDmx_Pes_t * packets );
extern void plfapife_tsdmxexN_OnPesListCancelled( int windowid, Nat32 subscrId );
extern void plfapife_tsdmxexN_OnRequestAllowed( int windowid );
extern void plfapife_tsdmxexN_OnRequestCancelled( int windowid, Nat32 subscrId );
extern void plfapife_tsdmxexN_OnRequestListCancelled( int windowid, Nat32 subscrId );
extern void plfapife_tsdmxexN_OnRequestNotAllowed( int windowid );
extern void plfapife_tsdmxexN_OnScramblingStatusChanged( int winid, int MediaType, int status );
extern void plfapife_tsdmxexN_OnSectionArrived( int windowid, Nat32 subscrId, int Cookie, int CrcStatus, Nat32 PSize, Address PAddr, Nat32 SSize, Address SAddr, Nat32 DataCookie );
extern void plfapife_tsdmxexN_OnSectionListArrived( int windowid, Nat32 subscrId, int Cookie, Nat32 ListCookie, Nat32 nSections, tmTsDmx_Section_t * sections );
extern void plfapife_tsdmxexN_OnSyncLock( int windowid );
extern void plfapife_tsdmxexN_OnSyncLost( int windowid );
extern void plfapife_tsdmxexN_OnVideoPidStopped( int winid, Nat16 pid );
#define plfapife_tsdmxexN_CrcStatusNoCrc  ((int)4)
#define plfapife_tsdmxexN_CrcStatusNoCrc_CONSTANT  4
#define plfapife_tsdmxexN_CrcStatusNotChecked  ((int)3)
#define plfapife_tsdmxexN_CrcStatusNotChecked_CONSTANT  3
#define plfapife_tsdmxexN_CrcStatusNotOk  ((int)2)
#define plfapife_tsdmxexN_CrcStatusNotOk_CONSTANT  2
#define plfapife_tsdmxexN_CrcStatusOk  ((int)1)
#define plfapife_tsdmxexN_CrcStatusOk_CONSTANT  1
extern void plfapife_tsdmxN_OnAudioDescriptivePidStopped( int winid, Nat16 pid );
extern void plfapife_tsdmxN_OnAudioPidStopped( int winid, Nat16 pid );
extern void plfapife_tsdmxN_OnBufferOverflow( int windowid );
extern void plfapife_tsdmxN_OnPcrPidStopped( int winid, Nat16 pid );
extern void plfapife_tsdmxN_OnPesArrived( int windowid, Nat32 subscrId, Nat32 Cookie, Nat32 PSize, Address PAddr, Nat32 SSize, Address SAddr, Nat32 DataCookie );
extern void plfapife_tsdmxN_OnPesCancelled( int windowid, Nat32 subscrId );
extern void plfapife_tsdmxN_OnRequestAllowed( int windowid );
extern void plfapife_tsdmxN_OnRequestCancelled( int windowid, Nat32 subscrId );
extern void plfapife_tsdmxN_OnRequestListCancelled( int windowid, Nat32 subscrId );
extern void plfapife_tsdmxN_OnRequestNotAllowed( int windowid );
extern void plfapife_tsdmxN_OnScramblingStatusChanged( int winid, int MediaType, int status );
extern void plfapife_tsdmxN_OnSectionArrived( int windowid, Nat32 subscrId, int Cookie, int CrcStatus, Nat32 PSize, Address PAddr, Nat32 SSize, Address SAddr, Nat32 DataCookie );
extern void plfapife_tsdmxN_OnSectionListArrived( int windowid, Nat32 subscrId, int Cookie, Nat32 ListCookie, Nat32 nSections, tmTsDmx_Section_t * sections );
extern void plfapife_tsdmxN_OnSyncLock( int windowid );
extern void plfapife_tsdmxN_OnSyncLost( int windowid );
extern void plfapife_tsdmxN_OnVideoPidStopped( int winid, Nat16 pid );
#define plfapife_tsdmxN_CrcStatusNoCrc  ((int)4)
#define plfapife_tsdmxN_CrcStatusNoCrc_CONSTANT  4
#define plfapife_tsdmxN_CrcStatusNotChecked  ((int)3)
#define plfapife_tsdmxN_CrcStatusNotChecked_CONSTANT  3
#define plfapife_tsdmxN_CrcStatusNotOk  ((int)2)
#define plfapife_tsdmxN_CrcStatusNotOk_CONSTANT  2
#define plfapife_tsdmxN_CrcStatusOk  ((int)1)
#define plfapife_tsdmxN_CrcStatusOk_CONSTANT  1
extern void plfapife_tunN_OnAfcFreqChanged( Nat32 freq );
extern void plfapife_tunN_OnAfcLimitReached( Nat32 freq );
extern void plfapife_tunN_OnAfcModeChanged( void );
extern void plfapife_tunN_OnSearchInProgress( tmFe_SearchState_t state );
extern void plfapife_tunN_OnSearchStateChanged( tmFe_SearchState_t state );
extern void plfapife_tunN_OnStationFound( void );
extern void plfapife_tunN_OnStationNotFound( void );
extern void plfapife_tunN_OnTvSystemDetected( tmFe_TvSystem_t tvSystem );
extern void plfapife_vbislN_OnCcData( tmVbiSlice2_Cc_t cctype, Nat32 oLine, Nat32 eLine, Nat16 oField, Nat16 eField );
extern void plfapife_vbislN_OnCcNoData( Bool field );
extern void plfapife_vbislN_OnCgmsData( Bool cgmsPresentOddField, Bool cgmsPresentEvenField, Bool dataValidOddField, Bool dataValidEvenField, Nat8 dataOddField, Nat8 dataEvenField );
extern void plfapife_vbislN_OnCgmsNoData( void );
extern void plfapife_vbislN_OnGemstarData( Nat32 nrLines, Nat32 * pLines, tmVbiSlice2_Gemstar_t * Types, Nat32 size, Nat8 * Buffer );
extern void plfapife_vbislN_OnGemstarNoData( tmVbiSlice2_Gemstar_t gemstarType );
extern void plfapife_vbislN_OnVpsData( Nat8 size, Nat8 * Buffer );
extern void plfapife_vbislN_OnVpsNoData( void );
extern void plfapife_vbislN_OnWssData( tmVbiSlice2_Wss_t wsstype, Bool wssPresentOddField, Bool wssPresentEvenField, Nat16 dataOddField, Nat16 dataEvenField, Nat16 errorBitsOddField, Nat16 errorBitsEvenField );
extern void plfapife_vbislN_OnWssNoData( void );
extern void plfapife_vbislN_OnWstData( tmVbiSlice2_Wst_t wsttype, Nat32 nrLines, Nat32 * pLines, Nat32 sizeFirstBuffer, Nat32 sizeSecondBuffer, Nat8 * FirstBuffer, Nat8 * SecondBuffer );
extern void plfapife_vbislN_OnWstNoData( void );
extern void plfapife_vclipexN_OnBufferAvailable( Nat32 id );
extern void plfapife_vclipexN_OnEndOfData( void );
extern void plfapife_vclipexN_OnPaused( void );
extern void plfapife_vclipexN_OnSeekCompleted( void );
extern void plfapife_vclipexN_OnStarted( void );
extern void plfapife_vclipexN_OnStopped( void );
extern void plfapife_vclipexN_OnTotalSeekTimeChanged( Nat32 totalseektimemsec );
extern void plfapife_vclipN_OnBufferAvailable( Nat32 id );
extern void plfapife_vclipN_OnEndOfData( void );
extern void plfapife_vclipN_OnStarted( void );
extern void plfapife_vclipN_OnStopped( void );
extern void plfapife_vfrN_OnFreezeAllowedChanged( void );
extern void plfapife_vfrN_OnFreezeCompleted( Bool Frozen );
extern void plfapife_vfrN_OnStrobeAllowedChanged( void );
extern void plfapife_vfrN_OnStrobeChanged( int period );
extern void plfapife_vipN_OnFieldFrequencyChanged( void );
extern void plfapife_vipN_OnFilmModeChanged( void );
extern void plfapife_vipN_OnFromVcrChanged( void );
extern void plfapife_vipN_OnImageFormatChanged( void );
extern void plfapife_vipN_OnInterlacedChanged( void );
extern void plfapife_vipN_OnNumberOfFrameLinesChanged( void );
extern void plfapife_vipN_OnNumberOfVisibleLinesChanged( void );
extern void plfapife_vipN_OnNumberOfVisiblePixelsChanged( void );
extern void plfapife_vipN_OnSignalPresentChanged( void );
extern void plfapife_vipN_OnVideoCodingChanged( void );
extern void plfapife_vipN_OnVideoPresentChanged( void );
extern void plfapife_vipN_OnVideoProtectionChanged( void );

/* Functions to indicate which notifications should be raised (for use in clients only!) */
extern void plfapife_EnableNotification_aclipexN( void );
extern void plfapife_DisableNotification_aclipexN( void );
extern void plfapife_EnableNotification_aclipN( void );
extern void plfapife_DisableNotification_aclipN( void );
extern void plfapife_EnableNotification_apitestntf( void );
extern void plfapife_DisableNotification_apitestntf( void );
extern void plfapife_EnableNotification_assmN( void );
extern void plfapife_DisableNotification_assmN( void );
extern void plfapife_EnableNotification_chdec2N( void );
extern void plfapife_DisableNotification_chdec2N( void );
extern void plfapife_EnableNotification_chdecN( void );
extern void plfapife_DisableNotification_chdecN( void );
extern void plfapife_EnableNotification_ciplusaintf( void );
extern void plfapife_DisableNotification_ciplusaintf( void );
extern void plfapife_EnableNotification_ciplusammintf( void );
extern void plfapife_DisableNotification_ciplusammintf( void );
extern void plfapife_EnableNotification_cipluscantf( void );
extern void plfapife_DisableNotification_cipluscantf( void );
extern void plfapife_EnableNotification_ciplusccntf( void );
extern void plfapife_DisableNotification_ciplusccntf( void );
extern void plfapife_EnableNotification_ciplushcntf( void );
extern void plfapife_DisableNotification_ciplushcntf( void );
extern void plfapife_EnableNotification_ciplusinitntf( void );
extern void plfapife_DisableNotification_ciplusinitntf( void );
extern void plfapife_EnableNotification_ciplusmmintf( void );
extern void plfapife_DisableNotification_ciplusmmintf( void );
extern void plfapife_EnableNotification_ciplusstatusntf( void );
extern void plfapife_DisableNotification_ciplusstatusntf( void );
extern void plfapife_EnableNotification_ciplusupgrntf( void );
extern void plfapife_DisableNotification_ciplusupgrntf( void );
extern void plfapife_EnableNotification_colN( void );
extern void plfapife_DisableNotification_colN( void );
extern void plfapife_EnableNotification_diseqN( void );
extern void plfapife_DisableNotification_diseqN( void );
extern void plfapife_EnableNotification_dvbsN( void );
extern void plfapife_DisableNotification_dvbsN( void );
extern void plfapife_EnableNotification_feitfN( void );
extern void plfapife_DisableNotification_feitfN( void );
extern void plfapife_EnableNotification_gdripN( void );
extern void plfapife_DisableNotification_gdripN( void );
extern void plfapife_EnableNotification_hsysN( void );
extern void plfapife_DisableNotification_hsysN( void );
extern void plfapife_EnableNotification_qssmN( void );
extern void plfapife_DisableNotification_qssmN( void );
extern void plfapife_EnableNotification_socN( void );
extern void plfapife_DisableNotification_socN( void );
extern void plfapife_EnableNotification_ssmN( void );
extern void plfapife_DisableNotification_ssmN( void );
extern void plfapife_EnableNotification_ssysN( void );
extern void plfapife_DisableNotification_ssysN( void );
extern void plfapife_EnableNotification_stcdecN( void );
extern void plfapife_DisableNotification_stcdecN( void );
extern void plfapife_EnableNotification_tsdmxexN( void );
extern void plfapife_DisableNotification_tsdmxexN( void );
extern void plfapife_EnableNotification_tsdmxN( void );
extern void plfapife_DisableNotification_tsdmxN( void );
extern void plfapife_EnableNotification_tunN( void );
extern void plfapife_DisableNotification_tunN( void );
extern void plfapife_EnableNotification_vbislN( void );
extern void plfapife_DisableNotification_vbislN( void );
extern void plfapife_EnableNotification_vclipexN( void );
extern void plfapife_DisableNotification_vclipexN( void );
extern void plfapife_EnableNotification_vclipN( void );
extern void plfapife_DisableNotification_vclipN( void );
extern void plfapife_EnableNotification_vfrN( void );
extern void plfapife_DisableNotification_vfrN( void );
extern void plfapife_EnableNotification_vipN( void );
extern void plfapife_DisableNotification_vipN( void );
extern void plfapife_EnableNotification( int notificationId );
extern void plfapife_DisableNotification( int notificationId );

#if !defined(_COMACALLSTUB_)
#define _COMACALLSTUB_
/* The datatype used for stubs in the plfapife_call_stubs */
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

extern void plfapife_RegisterHookGlobal( IpcHookFunction callback );

/* For client: ipchtCall, ipchtCallDone */
/* For supply: ipchtCallReceived, ipchtCallHandled */
extern void plfapife_RegisterHook_aclip( IpcHookFunction callback );
extern void plfapife_RegisterHook_aclipex( IpcHookFunction callback );
extern void plfapife_RegisterHook_apitest( IpcHookFunction callback );
extern void plfapife_RegisterHook_assm( IpcHookFunction callback );
extern void plfapife_RegisterHook_chantab( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdec( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdec2( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdecdvbc( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdecdvbt( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdecisdbt( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdecisdbt2( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdecsel( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusai( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusammi( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusca( IpcHookFunction callback );
extern void plfapife_RegisterHook_cipluscc( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplushc( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplushlc( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusinit( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusmmi( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusstatus( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusupgr( IpcHookFunction callback );
extern void plfapife_RegisterHook_col( IpcHookFunction callback );
extern void plfapife_RegisterHook_diseq( IpcHookFunction callback );
extern void plfapife_RegisterHook_dvbs( IpcHookFunction callback );
extern void plfapife_RegisterHook_errid( IpcHookFunction callback );
extern void plfapife_RegisterHook_feitf( IpcHookFunction callback );
extern void plfapife_RegisterHook_feitfid( IpcHookFunction callback );
extern void plfapife_RegisterHook_gdrip( IpcHookFunction callback );
extern void plfapife_RegisterHook_hsys( IpcHookFunction callback );
extern void plfapife_RegisterHook_prs( IpcHookFunction callback );
extern void plfapife_RegisterHook_qssm( IpcHookFunction callback );
extern void plfapife_RegisterHook_rfamp( IpcHookFunction callback );
extern void plfapife_RegisterHook_sad( IpcHookFunction callback );
extern void plfapife_RegisterHook_siq( IpcHookFunction callback );
extern void plfapife_RegisterHook_snd( IpcHookFunction callback );
extern void plfapife_RegisterHook_soc( IpcHookFunction callback );
extern void plfapife_RegisterHook_ssm( IpcHookFunction callback );
extern void plfapife_RegisterHook_ssys( IpcHookFunction callback );
extern void plfapife_RegisterHook_stcdec( IpcHookFunction callback );
extern void plfapife_RegisterHook_tmc( IpcHookFunction callback );
extern void plfapife_RegisterHook_tsdmx( IpcHookFunction callback );
extern void plfapife_RegisterHook_tsdmxex( IpcHookFunction callback );
extern void plfapife_RegisterHook_tun( IpcHookFunction callback );
extern void plfapife_RegisterHook_vbiins( IpcHookFunction callback );
extern void plfapife_RegisterHook_vbisl( IpcHookFunction callback );
extern void plfapife_RegisterHook_vclip( IpcHookFunction callback );
extern void plfapife_RegisterHook_vclipex( IpcHookFunction callback );
extern void plfapife_RegisterHook_vfr( IpcHookFunction callback );
extern void plfapife_RegisterHook_vip( IpcHookFunction callback );

/* For client: ipchtNotificationReceived, ipchtNotificationHandled */
/* For supply: ipchtNotificationCalled, ipchtNotificationPosted, ipchtNotificationDone */
extern void plfapife_RegisterHook_aclipexN( IpcHookFunction callback );
extern void plfapife_RegisterHook_aclipN( IpcHookFunction callback );
extern void plfapife_RegisterHook_apitestntf( IpcHookFunction callback );
extern void plfapife_RegisterHook_assmN( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdec2N( IpcHookFunction callback );
extern void plfapife_RegisterHook_chdecN( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusaintf( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusammintf( IpcHookFunction callback );
extern void plfapife_RegisterHook_cipluscantf( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusccntf( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplushcntf( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusinitntf( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusmmintf( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusstatusntf( IpcHookFunction callback );
extern void plfapife_RegisterHook_ciplusupgrntf( IpcHookFunction callback );
extern void plfapife_RegisterHook_colN( IpcHookFunction callback );
extern void plfapife_RegisterHook_diseqN( IpcHookFunction callback );
extern void plfapife_RegisterHook_dvbsN( IpcHookFunction callback );
extern void plfapife_RegisterHook_feitfN( IpcHookFunction callback );
extern void plfapife_RegisterHook_gdripN( IpcHookFunction callback );
extern void plfapife_RegisterHook_hsysN( IpcHookFunction callback );
extern void plfapife_RegisterHook_qssmN( IpcHookFunction callback );
extern void plfapife_RegisterHook_socN( IpcHookFunction callback );
extern void plfapife_RegisterHook_ssmN( IpcHookFunction callback );
extern void plfapife_RegisterHook_ssysN( IpcHookFunction callback );
extern void plfapife_RegisterHook_stcdecN( IpcHookFunction callback );
extern void plfapife_RegisterHook_tsdmxexN( IpcHookFunction callback );
extern void plfapife_RegisterHook_tsdmxN( IpcHookFunction callback );
extern void plfapife_RegisterHook_tunN( IpcHookFunction callback );
extern void plfapife_RegisterHook_vbislN( IpcHookFunction callback );
extern void plfapife_RegisterHook_vclipexN( IpcHookFunction callback );
extern void plfapife_RegisterHook_vclipN( IpcHookFunction callback );
extern void plfapife_RegisterHook_vfrN( IpcHookFunction callback );
extern void plfapife_RegisterHook_vipN( IpcHookFunction callback );

#endif /* _PLFAPIFE_H_ */

