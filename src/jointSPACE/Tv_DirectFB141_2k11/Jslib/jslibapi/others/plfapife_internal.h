
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


#if !defined(_PLFAPIFE_INTERNAL_H_)
#define _PLFAPIFE_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 id; //in,  
    Nat32 size; //in,  
    Address Data; //in,  
    Bool endOfData; //in,  
    Nat32 retval; //out,  
} aclipAddData;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} aclipContinue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 retval; //out,  
} aclipEnableClipPlay;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 AvailableNrBuffers; //out,  
    Nat32 retval; //out,  
} aclipGetAvailableNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Enable; //out,  
    Nat32 retval; //out,  
} aclipGetClipPlayEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MaxNrBuffers; //out,  
    Nat32 retval; //out,  
} aclipGetMaxNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Supported; //out,  
    Nat32 retval; //out,  
} aclipGetPauseSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmDigAdec_ClipDecodingState_t State; //out,  
    Nat32 retval; //out,  
} aclipGetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} aclipPause;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} aclipStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} aclipStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 id; //in,  
    Nat32 size; //in,  
    Address Data; //in,  
    Bool endOfData; //in,  
    Nat32 retval; //out,  
} aclipexAddData;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} aclipexContinue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 retval; //out,  
} aclipexEnableClipPlay;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 retval; //out,  
} aclipexEnableSeek;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 AvailableNrBuffers; //out,  
    Nat32 retval; //out,  
} aclipexGetAvailableNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Enable; //out,  
    Nat32 retval; //out,  
} aclipexGetClipPlayEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MaxNrBuffers; //out,  
    Nat32 retval; //out,  
} aclipexGetMaxNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Supported; //out,  
    Nat32 retval; //out,  
} aclipexGetPauseSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool penable; //out,  
    Nat32 retval; //out,  
} aclipexGetSeekEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmDigAdec_ClipDecodingState_t State; //out,  
    Nat32 retval; //out,  
} aclipexGetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 ptotalseektime; //out,  
    Nat32 retval; //out,  
} aclipexGetTotalSeekTime;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} aclipexPause;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 msec; //in,  
    Nat32 retval; //out,  
} aclipexSeek;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} aclipexStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} aclipexStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 id; //in,  
    Nat32 param1; //in,  
    Nat32 param2; //in,  
} apitestStartTest;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 id; //in,  
} apitestStopTest;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Valid; //out,  
    Nat32 retval; //out,  
} assmGetMeasValid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Strength; //out,  
    Nat32 retval; //out,  
} assmGetSigStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinStrength; //out,  
    Nat32 MaxStrength; //out,  
    Nat32 retval; //out,  
} assmGetSigStrengthRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Avail; //out,  
    Nat32 retval; //out,  
} assmStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Stopped; //out,  
    Nat32 retval; //out,  
} assmStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 freq; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Chan; //out,  
    Nat32 retval; //out,  
} chantabFreq2Chan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 chan; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Freq; //out,  
    Nat32 retval; //out,  
} chantabGetCarrierFreq;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Chan; //out,  
    Nat32 retval; //out,  
} chantabGetFirstChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanTable_t Table; //out,  
    Nat32 retval; //out,  
} chantabGetFirstTable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 chan; //in,  
    tmFe_ChanTable_t table; //in,  
    Bool IsChan; //out,  
    Nat32 retval; //out,  
} chantabGetIsChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Chan; //out,  
    Nat32 retval; //out,  
} chantabGetLastChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 chan; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Freq; //out,  
    Nat32 retval; //out,  
} chantabGetLowerFreq;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 chan; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Chan; //out,  
    Nat32 retval; //out,  
} chantabGetNextChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanTable_t curtable; //in,  
    tmFe_ChanTable_t Table; //out,  
    Nat32 retval; //out,  
} chantabGetNextTable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 freq; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Chan; //out,  
    Nat32 retval; //out,  
} chantabGetNextValidChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 chan; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Chan; //out,  
    Nat32 retval; //out,  
} chantabGetPrevChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 freq; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Chan; //out,  
    Nat32 retval; //out,  
} chantabGetPrevValidChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 chan; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 LowerBound; //out,  
    Nat32 UpperBound; //out,  
    Nat32 retval; //out,  
} chantabGetSegmentBoundaries;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanTable_t Table; //out,  
    Nat32 retval; //out,  
} chantabGetTable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanTable_t table; //in,  
    Bool Supp; //out,  
    Nat32 retval; //out,  
} chantabGetTableSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 chan; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 Freq; //out,  
    Nat32 retval; //out,  
} chantabGetUpperFreq;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanTable_t table; //in,  
    Nat32 retval; //out,  
} chantabSetTable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_Constellation_t pConstellation; //out,  
    Nat32 retval; //out,  
} chdecGetActualConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_IqMode_t pIqMode; //out,  
    Nat32 retval; //out,  
} chdecGetActualIqMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Ber; //out,  
    Nat32 retval; //out,  
} chdecGetBer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Threshold; //out,  
    Nat32 retval; //out,  
} chdecGetBerThreshold;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinThreshold; //out,  
    Nat32 MaxThreshold; //out,  
    Nat32 retval; //out,  
} chdecGetBerThresholdRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Present; //out,  
    Nat32 retval; //out,  
} chdecGetCarrierPresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_Constellation_t pConstellation; //out,  
    Nat32 retval; //out,  
} chdecGetConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 Error; //out,  
    Nat32 retval; //out,  
} chdecGetFrequencyError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool FreqErrorSupp; //out,  
    Nat32 retval; //out,  
} chdecGetFrequencyErrorSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_IqMode_t pIqMode; //out,  
    Nat32 retval; //out,  
} chdecGetIqMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ConstellationSet_t pConstellations; //out,  
    Nat32 retval; //out,  
} chdecGetSuppConstellations;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_IqModeSet_t pIqModes; //out,  
    Nat32 retval; //out,  
} chdecGetSuppIqModes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 Error; //out,  
    Nat32 retval; //out,  
} chdecGetSymbolError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool SymbolErrorSupp; //out,  
    Nat32 retval; //out,  
} chdecGetSymbolErrorSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 Error; //out,  
    Nat32 retval; //out,  
} chdecGetTimeError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool TimeErrorSupp; //out,  
    Nat32 retval; //out,  
} chdecGetTimeErrorSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 threshold; //in,  
    Nat32 retval; //out,  
} chdecSetBerThreshold;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_Constellation_t constellation; //in,  
    Nat32 retval; //out,  
} chdecSetConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 error; //in,  
    Nat32 retval; //out,  
} chdecSetFrequencyError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_IqMode_t iqMode; //in,  
    Nat32 retval; //out,  
} chdecSetIqMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 error; //in,  
    Nat32 retval; //out,  
} chdecSetSymbolError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 error; //in,  
    Nat32 retval; //out,  
} chdecSetTimeError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_Constellation_t pConstellation; //out,  
    Nat32 retval; //out,  
} chdec2GetActualConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_IqMode_t pIqMode; //out,  
    Nat32 retval; //out,  
} chdec2GetActualIqMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Ber; //out,  
    Nat32 retval; //out,  
} chdec2GetBer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Threshold; //out,  
    Nat32 retval; //out,  
} chdec2GetBerThreshold;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinThreshold; //out,  
    Nat32 MaxThreshold; //out,  
    Nat32 retval; //out,  
} chdec2GetBerThresholdRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Present; //out,  
    Nat32 retval; //out,  
} chdec2GetCarrierPresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_Constellation_t pConstellation; //out,  
    Nat32 retval; //out,  
} chdec2GetConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 Error; //out,  
    Nat32 retval; //out,  
} chdec2GetFrequencyError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool FreqErrorSupp; //out,  
    Nat32 retval; //out,  
} chdec2GetFrequencyErrorSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_IqMode_t pIqMode; //out,  
    Nat32 retval; //out,  
} chdec2GetIqMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ConstellationSet_t pConstellations; //out,  
    Nat32 retval; //out,  
} chdec2GetSuppConstellations;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_IqModeSet_t pIqModes; //out,  
    Nat32 retval; //out,  
} chdec2GetSuppIqModes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 Error; //out,  
    Nat32 retval; //out,  
} chdec2GetSymbolError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool SymbolErrorSupp; //out,  
    Nat32 retval; //out,  
} chdec2GetSymbolErrorSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 Error; //out,  
    Nat32 retval; //out,  
} chdec2GetTimeError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool TimeErrorSupp; //out,  
    Nat32 retval; //out,  
} chdec2GetTimeErrorSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 threshold; //in,  
    Nat32 retval; //out,  
} chdec2SetBerThreshold;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_Constellation_t constellation; //in,  
    Nat32 retval; //out,  
} chdec2SetConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 error; //in,  
    Nat32 retval; //out,  
} chdec2SetFrequencyError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_IqMode_t iqMode; //in,  
    Nat32 retval; //out,  
} chdec2SetIqMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 error; //in,  
    Nat32 retval; //out,  
} chdec2SetSymbolError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 error; //in,  
    Nat32 retval; //out,  
} chdec2SetTimeError;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 rate; //out,  
    Nat32 retval; //out,  
} chdecdvbcGetActualCodeRate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 step; //out,  
    Nat32 retval; //out,  
} chdecdvbcGetFreqStep;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 rate; //out,  
    Nat32 retval; //out,  
} chdecdvbcGetSymbolRate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinSymbolRate; //out,  
    Nat32 MaxSymbolRate; //out,  
    Nat32 retval; //out,  
} chdecdvbcGetSymbolRateRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} chdecdvbcResetFreqStep;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 step; //in,  
    Nat32 retval; //out,  
} chdecdvbcSetFreqStep;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_SearchSymbolRate_t * SearchRate; //in, data ( sizeof( tmFe_SearchSymbolRate_t ) * size ), dynamic ( sizeof( tmFe_SearchSymbolRate_t ) * size ), 
    Nat32 size; //in,  
    Nat32 retval; //out,  
} chdecdvbcSetSearchRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 rate; //in,  
    Nat32 retval; //out,  
} chdecdvbcSetSymbolRate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanBandwidth_t Bandwidth; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetActualChanBandwidth;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_CodeRate_t HighPrioRate; //out,  
    tmFe_CodeRate_t LowPrioRate; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetActualCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_FrequencyOffset_t Offset; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetActualFrequencyOffset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t Interval; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetActualGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_HierarchyMode_t Mode; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetActualHierarchyMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TxMode_t Mode; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetActualTxMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanBandwidth_t Bandwidth; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetChanBandwidth;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 info; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetChannelInformation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_CodeRate_t HighPrioRate; //out,  
    tmFe_CodeRate_t LowPrioRate; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_FrequencyOffset_t Offset; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetFrequencyOffset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t Interval; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_HierarchyMode_t Mode; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetHierarchyMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_StreamPriority_t streamPriority; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetStreamPriority;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanBandwidthSet_t Bandwidths; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetSuppChanBandwidths;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_CodeRateSet_t Rates; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetSuppCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_FrequencyOffsetSet_t Offsets; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetSuppFrequencyOffsets;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardIntervalSet_t Intervals; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetSuppGuardIntervals;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_HierarchyModeSet_t Modes; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetSuppHierarchyModes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TxModeSet_t Modes; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetSuppTxModes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 cellId; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetTpsCellid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TxMode_t Mode; //out,  
    Nat32 retval; //out,  
} chdecdvbtGetTxMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ChanBandwidth_t bandwidth; //in,  
    Nat32 retval; //out,  
} chdecdvbtSetChanBandwidth;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 info; //in,  
    Nat32 retval; //out,  
} chdecdvbtSetChannelInformation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_CodeRate_t highPrioRate; //in,  
    tmFe_CodeRate_t lowPrioRate; //in,  
    Nat32 retval; //out,  
} chdecdvbtSetCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_FrequencyOffset_t offset; //in,  
    Nat32 retval; //out,  
} chdecdvbtSetFrequencyOffset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t interval; //in,  
    Nat32 retval; //out,  
} chdecdvbtSetGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_HierarchyMode_t mode; //in,  
    Nat32 retval; //out,  
} chdecdvbtSetHierarchyMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_StreamPriority_t streamPriority; //in,  
    Nat32 retval; //out,  
} chdecdvbtSetStreamPriority;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TxMode_t mode; //in,  
    Nat32 retval; //out,  
} chdecdvbtSetTxMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_CodeRate_t coderate; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetActualCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_Constellation_t pConstellation; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetActualConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t Interval; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetActualGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 info; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetChannelInformation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_CodeRate_t coderate; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_Constellation_t pConstellation; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t Interval; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //out,  
} chdecisdbtGetLayer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_CodeRateSet_t Rates; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetSuppCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ConstellationSet_t pConstellations; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetSuppConstellations;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardIntervalSet_t Intervals; //out,  
    Nat32 retval; //out,  
} chdecisdbtGetSuppGuardIntervals;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layers; //out,  
} chdecisdbtGetSupportedLayers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 info; //in,  
    Nat32 retval; //out,  
} chdecisdbtSetChannelInformation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_CodeRate_t coderate; //in,  
    Nat32 retval; //out,  
} chdecisdbtSetCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_Constellation_t constellation; //in,  
    Nat32 retval; //out,  
} chdecisdbtSetConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t interval; //in,  
    Nat32 retval; //out,  
} chdecisdbtSetGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
} chdecisdbtSetLayer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_BroadcastType_t BroadcastType; //out,  
    tmFe_Partial_t Partial; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetActualBroadcastType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_CodeRate_t coderate; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetActualCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_Constellation_t pConstellation; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetActualConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t Interval; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetActualGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_NumberofSegments_t segments; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetActualNumberofSegments;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_TimeInterleave_t timeinterleave; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetActualTimeInterleave;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TxMode_t TxMode; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetActualTxMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_BroadcastType_t BroadcastType; //out,  
    tmFe_Partial_t Partial; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetBroadcastType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 info; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetChannelInformation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_CodeRate_t coderate; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_Constellation_t pConstellation; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t Interval; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //out,  
} chdecisdbt2GetLayer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_NumberofSegments_t segments; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetNumberofSegments;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_BroadcastTypeSet_t BroadcastType; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetSuppBroadcastType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_CodeRateSet_t Rates; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetSuppCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_ConstellationSet_t pConstellations; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetSuppConstellations;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardIntervalSet_t Intervals; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetSuppGuardIntervals;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_NumberofSegments_t segments; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetSuppNumberofSegments;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layers; //out,  
} chdecisdbt2GetSupportedLayers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TimeInterleaveSet_t TimeInterleave; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetSuppTimeInterleave;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TxModeSet_t TxMode; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetSuppTxMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_TimeInterleave_t timeinterleave; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetTimeInterleave;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TxMode_t TxMode; //out,  
    Nat32 retval; //out,  
} chdecisdbt2GetTxMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_BroadcastType_t BroadcastType; //in,  
    tmFe_Partial_t Partial; //in,  
    Nat32 retval; //out,  
} chdecisdbt2SetBroadcastType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 info; //in,  
    Nat32 retval; //out,  
} chdecisdbt2SetChannelInformation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_CodeRate_t coderate; //in,  
    Nat32 retval; //out,  
} chdecisdbt2SetCodeRates;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_Constellation_t constellation; //in,  
    Nat32 retval; //out,  
} chdecisdbt2SetConstellation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_GuardInterval_t interval; //in,  
    Nat32 retval; //out,  
} chdecisdbt2SetGuardInterval;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
} chdecisdbt2SetLayer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_NumberofSegments_t segments; //in,  
    Nat32 retval; //out,  
} chdecisdbt2SetNumberofSegments;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int layer; //in,  
    tmFe_TimeInterleave_t timeinterleave; //in,  
    Nat32 retval; //out,  
} chdecisdbt2SetTimeInterleave;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TxMode_t txmode; //in,  
    Nat32 retval; //out,  
} chdecisdbt2SetTxMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 decoder; //out,  
} chdecselGetChanDec;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 decoder; //in,  
    Nat32 retval; //out,  
} chdecselIsChanDecSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 decoder; //in,  
} chdecselSetChanDec;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat32 appli_index; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusaiAI_SelectApplication;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    Nat16 byteLen; //in,  
    Nat8 * ptbyte; //in, data ( sizeof( Nat8 ) * byteLen ), dynamic ( sizeof( Nat8 ) * byteLen ), 
    CIPlusResult_e ciResult; //out,  
} ciplusammiAMMI_Abort;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    Nat16 byteLen; //in,  
    Nat8 * ptbyte; //in, data ( sizeof( Nat8 ) * byteLen ), dynamic ( sizeof( Nat8 ) * byteLen ), 
    CIPlusResult_e ciResult; //out,  
} ciplusammiAMMI_AbortAck;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusammiAMMI_Close;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    CIPlusRequestType_e request_type; //in,  
    Nat32 byteLen; //in,  
    Address shrdmemptByte; //in,  
    Nat16 fileNameLen; //in,  
    Address ptFileName; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusammiAMMI_Request;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    Nat8 ackCode; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusammiAMMI_StartAck;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 sessionid; //in,  
    Nat16 NbOfCADescriptors; //in,  
    CIPlusCaListMng_e listmng; //in,  
    CIPlusCaCommand_e command; //in,  
    Nat16 PMTLength; //in,  
    Nat8 * PMTdata; //in, data ( sizeof( Nat8 ) * PMTLength ), dynamic ( sizeof( Nat8 ) * PMTLength ), 
    CIPlusResult_e Result; //out,  
} cipluscaCa_NotifyPMT;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 brandId; //out,  
} ciplusccCC_GetBrandID;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    CIPlusResult_e Result; //out,  
} ciplushcHC_Release;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 countryCode; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplushlcHLC_SetCountry;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 langCode; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplushlcHLC_SetLanguage;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusinitOnRequestActivate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusinitOnRequestEnd;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusVersion_e CiVersion; //in,  
    Bool LSCActive; //in,  
    Bool SASActive; //in,  
    Bool PVRActive; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusinitOnRequestInit;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusinitResetHard;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusinitResetSoft;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    CIPlusTSMode_e tsmode; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusinitSwitchTS;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusmmiMMI_Close;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
    Nat8 answ; //in,  
    Nat16 textLen; //in,  
    Nat8 * textPtr; //in, data ( sizeof( Nat8 ) * textLen ), dynamic ( sizeof( Nat8 ) * textLen ), 
    CIPlusResult_e ciResult; //out,  
} ciplusmmiMMI_ResponseEnq;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
    Nat16 choice; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusmmiMMI_ResponseList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
    Nat16 choice; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusmmiMMI_ResponseMenu;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    CIPlusStatus_e status; //out,  
    CIPlusResult_e ciResult; //out,  
} ciplusstatusGetStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CIPlusHandle handle; //in,  
    CIPlusUPGRReply_e reply; //in,  
    CIPlusResult_e ciResult; //out,  
} ciplusupgrUPGR_UpgradeReply;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int colorsystem; //in,  
    Bool retval; //out,  
} colColorSystemSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int colorsystem; //in,  
    int carrierfrequency; //in,  
    Bool retval; //out,  
} colColorSystemSupportedEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} colCombFilterActive;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} colCombFilterEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} colCombFilterSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
} colEnableCombFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int colorsystem; //in,  
} colForceColorSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int colorsystem; //in,  
    int carrierfrequency; //in,  
} colForceColorSystemEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} colGetCarrierFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} colGetColorSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} colGetForcedCarrierFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} colGetForcedColorSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} colGetSuggestedCarrierFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} colGetSuggestedColorSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int colorsystem; //in,  
} colSuggestColorSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int colorsystem; //in,  
    int carrierfrequency; //in,  
} colSuggestColorSystemEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int polarisation; //in,  
    int band; //in,  
    int ctrlword1; //in,  
    int bytelen1; //in,  
    int ctrlword2; //in,  
    int bytelen2; //in,  
    int toneburst; //in,  
    int cookie; //in,  
    int CmdResult; //out,  
} diseqSend;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int polarisation; //in,  
    int band; //in,  
    int datalen; //in,  
    Nat8 * buffer; //in, data ( sizeof( Nat8 ) * datalen ), dynamic ( sizeof( Nat8 ) * datalen ), 
    int toneburst; //in,  
    int cookie; //in,  
    int CmdResult; //out,  
} diseqSendMsg;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int Frequency; //in,  
    int SearchRange; //in,  
    int SymbolRate; //in,  
    int ModulationStandard; //in,  
    int ModulationType; //in,  
    int CodeRate; //in,  
    int PunctureRate; //in,  
    int IQMode; //in,  
    int Timeout; //out,  
    int Cookie; //in,  
    int CmdResult; //out,  
} dvbsAttemptLock;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int Frequency; //out,  
    int SymbolRate; //out,  
    int ModulationStandard; //out,  
    int ModulationType; //out,  
    int CodeRate; //out,  
    int PunctureRate; //out,  
    int IQMode; //out,  
    int LockState; //out,  
    int CmdResult; //out,  
} dvbsGetParams;

typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} feitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 id; //in,  
    Nat32 size; //in,  
    Address Data; //in,  
    Bool endOfData; //in,  
    Nat32 retval; //out,  
} gdripAddData;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 AvailableNrBuffers; //out,  
    Nat32 retval; //out,  
} gdripGetAvailableNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 pAlignment; //out,  
    Nat32 retval; //out,  
} gdripGetBufAlignment;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MaxNrBuffers; //out,  
    Nat32 retval; //out,  
} gdripGetMaxNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 reqHorRes; //in,  
    Nat32 reqVertRes; //in,  
    Nat32 horPos; //in,  
    Nat32 vertPos; //in,  
    Nat32 stride; //in,  
    tmPixFmtCls_t formatClass; //in,  
    tmPixFmtType_t formatType; //in,  
    Nat32 bufferSize; //in,  
    Address buffer; //in,  
    Nat32 retval; //out,  
} gdripGetOutputFrame;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 pMaxRequestedHorRes; //out,  
    Nat32 pMaxRequestedVertRes; //out,  
    Nat32 pMinRequestedHorRes; //out,  
    Nat32 pMinRequestedVertRes; //out,  
    Nat32 retval; //out,  
} gdripGetScalingRestrictions;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmDigVdec_ClipDecodingState_t ClipDecodingState; //out,  
    Nat32 retval; //out,  
} gdripGetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPixFmtClsSet_t pFormatClassSet; //out,  
    Nat32 retval; //out,  
} gdripGetSuppFormatClasses;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPixFmtTypeSet_t pFormatTypesSet; //out,  
    Nat32 retval; //out,  
} gdripGetSuppFormatTypes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} gdripStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} gdripStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} hsysGetSoundSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Source_t source; //in,  
    int preset; //in,  
    Nat32 retval; //out,  
} prsFillPreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int preset; //in,  
    tmPlfInstPreset_PresetAttribute_t attribute; //in,  
    int Value; //out,  
    Nat32 retval; //out,  
} prsGetAttribute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int PresetIndex; //out,  
    Nat32 retval; //out,  
} prsGetMaxPreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int PresetIndex; //out,  
    Nat32 retval; //out,  
} prsGetMinPreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Source_t source; //in,  
    int Preset; //out,  
    Nat32 retval; //out,  
} prsGetPreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int preset; //in,  
    Nat32 retval; //out,  
} prsInitPreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int preset; //in,  
    tmPlfInstPreset_PresetAttribute_t attribute; //in,  
    Nat32 retval; //out,  
} prsLoadAttribute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int preset; //in,  
    Nat32 retval; //out,  
} prsLoadPreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int preset; //in,  
    tmPlfInstPreset_PresetAttribute_t attribute; //in,  
    int value; //in,  
    Nat32 retval; //out,  
} prsSetAttribute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_Source_t source; //in,  
    int preset; //in,  
    Nat32 retval; //out,  
} prsSetPreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int preset; //in,  
    tmPlfInstPreset_PresetAttribute_t attribute; //in,  
    Nat32 retval; //out,  
} prsStoreAttribute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPlfInstPreset_PresetAttribute_t attribute; //in,  
    Bool Supported; //out,  
    Nat32 retval; //out,  
} prsStoreAttributeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int preset; //in,  
    Nat32 retval; //out,  
} prsStorePreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Supported; //out,  
    Nat32 retval; //out,  
} prsStorePresetSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int preset1; //in,  
    int preset2; //in,  
    Nat32 retval; //out,  
} prsSwapPreset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Valid; //out,  
    Nat32 retval; //out,  
} qssmGetMeasValid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Strength; //out,  
    Nat32 retval; //out,  
} qssmGetSigStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinStrength; //out,  
    Nat32 MaxStrength; //out,  
    Nat32 retval; //out,  
} qssmGetSigStrengthRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Avail; //out,  
    Nat32 retval; //out,  
} qssmStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Stopped; //out,  
    Nat32 retval; //out,  
} qssmStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 Amp; //out,  
    Nat32 retval; //out,  
} rfampGet;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 MinAmp; //out,  
    Int32 MaxAmp; //out,  
    Nat32 retval; //out,  
} rfampGetRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int32 amp; //in,  
    Nat32 retval; //out,  
} rfampSet;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sadGetADRouting;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sadGetVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sadGetVolumeMax;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sadGetVolumeMin;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} sadIsADRoutingAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} sadIsADRoutingSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} sadIsVolumeControlAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} sadIsVolumeControlSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int outputs; //in,  
} sadSetADRouting;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int volume; //in,  
} sadSetVolume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} siqGetActualNoiseLevel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int system; //in,  
} sndAllowSoundSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} sndGetAllowedSoundSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int retval; //out,  
} socFrontChannels;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} socGetChannel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} socIsDigital;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} socIsDolbyProLogic;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} socIsMono;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} socIsRelated;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} socIsSecondLanguage;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} socIsStereo;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int retval; //out,  
} socLfeChannels;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int retval; //out,  
} socRearChannels;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
} socSetChannel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Valid; //out,  
    Nat32 retval; //out,  
} ssmGetMeasValid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Strength; //out,  
    Nat32 retval; //out,  
} ssmGetSigStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinStrength; //out,  
    Nat32 MaxStrength; //out,  
    Nat32 retval; //out,  
} ssmGetSigStrengthRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Avail; //out,  
    Nat32 retval; //out,  
} ssmStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Stopped; //out,  
    Nat32 retval; //out,  
} ssmStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} ssysGetSoundSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alarmid; //in,  
    tmTimeStamp_t minValue; //in,  
    tmTimeStamp_t maxValue; //in,  
    Bool absolute; //in,  
    Nat32 retval; //out,  
} stcdecActivateAlarm;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alarmid; //out,  
    Nat32 retval; //out,  
} stcdecAllocateAlarm;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int alarmid; //in,  
    Nat32 retval; //out,  
} stcdecCancelAlarm;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 AvailableNrAlarms; //out,  
    Nat32 retval; //out,  
} stcdecGetAvailableNrAlarms;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MaxNrAlarms; //out,  
    Nat32 retval; //out,  
} stcdecGetMaxNrAlarms;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmTimeStamp_t Value; //out,  
    Nat32 retval; //out,  
} stcdecGetTime;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} tmcGetTxtMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
} tmcSetTxtMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 error; //out,  
} tsdmxCancelFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 error; //out,  
} tsdmxCancelListFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 error; //out,  
} tsdmxCancelPes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 listcookie; //in,  
    Nat32 error; //out,  
} tsdmxFreeListBuffer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 datacookie; //in,  
    Nat32 error; //out,  
} tsdmxFreePesBuffer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 datacookie; //in,  
    Nat32 error; //out,  
} tsdmxFreeSectionBuffer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //out,  
    Nat32 error; //out,  
} tsdmxGetAudioDescriptivePid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //out,  
    Nat32 error; //out,  
} tsdmxGetAudioPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //out,  
    Nat32 error; //out,  
} tsdmxGetAudioStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //out,  
    Nat32 error; //out,  
} tsdmxGetPcrPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //out,  
    Nat32 error; //out,  
} tsdmxGetPcrStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int MediaType; //in,  
    Nat32 error; //out,  
    int retval; //out,  
} tsdmxGetScramblingStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //out,  
    Nat32 error; //out,  
} tsdmxGetVideoPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //out,  
    Nat32 error; //out,  
} tsdmxGetVideoStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Bool supported; //out,  
    Nat32 error; //out,  
} tsdmxIsAudioStreamTypeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Bool supported; //out,  
    Nat32 error; //out,  
} tsdmxIsPcrStreamTypeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} tsdmxIsRequestAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Bool supported; //out,  
    Nat32 error; //out,  
} tsdmxIsVideoStreamTypeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pid; //in,  
    int BufferSize; //in,  
    int CrcMode; //in,  
    Bool ContinuousMode; //in,  
    Nat32 cookie; //in,  
    int FilterDepth; //in,  
    Nat8 ModeArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Nat32 retval; //out,  
} tsdmxRequestFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pid; //in,  
    int BufferSize; //in,  
    int CrcMode; //in,  
    Bool ContinuousMode; //in,  
    Nat32 timeout; //in,  
    Nat32 listLength; //in,  
    Nat32 cookie; //in,  
    int FilterDepth; //in,  
    Nat8 ModeArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Nat32 retval; //out,  
} tsdmxRequestListFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pid; //in,  
    int BufferSize; //in,  
    Nat32 cookie; //in,  
    int FilterDepth; //in,  
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Nat32 retval; //out,  
} tsdmxRequestPes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //in,  
    Nat32 error; //out,  
} tsdmxSetAudioDescriptivePid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //in,  
    Nat32 error; //out,  
} tsdmxSetAudioPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Nat32 error; //out,  
} tsdmxSetAudioStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //in,  
    Nat32 error; //out,  
} tsdmxSetPcrPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Nat32 error; //out,  
} tsdmxSetPcrStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //in,  
    Nat32 error; //out,  
} tsdmxSetVideoPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Nat32 error; //out,  
} tsdmxSetVideoStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 error; //out,  
} tsdmxStopAudioDescriptivePid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 error; //out,  
} tsdmxStopAudioPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 error; //out,  
} tsdmxStopPcrPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 error; //out,  
} tsdmxStopVideoPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    int FilterDepth; //in,  
    Nat8 ModeArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Bool retval; //out,  
} tsdmxUpdateFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    int FilterDepth; //in,  
    Nat8 ModeArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Bool retval; //out,  
} tsdmxUpdateListFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 error; //out,  
} tsdmxexCancelFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 error; //out,  
} tsdmxexCancelListFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 error; //out,  
} tsdmxexCancelPes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 error; //out,  
} tsdmxexCancelPesList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 listcookie; //in,  
    Nat32 error; //out,  
} tsdmxexFreeListBuffer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 datacookie; //in,  
    Nat32 error; //out,  
} tsdmxexFreePesBuffer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 listcookie; //in,  
    Nat32 error; //out,  
} tsdmxexFreePesListBuffer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    Nat32 datacookie; //in,  
    Nat32 error; //out,  
} tsdmxexFreeSectionBuffer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //out,  
    Nat32 error; //out,  
} tsdmxexGetAudioDescriptivePid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //out,  
    Nat32 error; //out,  
} tsdmxexGetAudioPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //out,  
    Nat32 error; //out,  
} tsdmxexGetAudioStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //out,  
    Nat32 error; //out,  
} tsdmxexGetPcrPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //out,  
    Nat32 error; //out,  
} tsdmxexGetPcrStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int MediaType; //in,  
    Nat32 error; //out,  
    int retval; //out,  
} tsdmxexGetScramblingStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //out,  
    Nat32 error; //out,  
} tsdmxexGetVideoPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //out,  
    Nat32 error; //out,  
} tsdmxexGetVideoStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Bool supported; //out,  
    Nat32 error; //out,  
} tsdmxexIsAudioStreamTypeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Bool supported; //out,  
    Nat32 error; //out,  
} tsdmxexIsPcrStreamTypeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} tsdmxexIsRequestAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Bool supported; //out,  
    Nat32 error; //out,  
} tsdmxexIsVideoStreamTypeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pid; //in,  
    int BufferSize; //in,  
    int CrcMode; //in,  
    Bool ContinuousMode; //in,  
    Nat32 cookie; //in,  
    int FilterDepth; //in,  
    Nat8 ModeArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Nat32 retval; //out,  
} tsdmxexRequestFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pid; //in,  
    int BufferSize; //in,  
    int CrcMode; //in,  
    Bool ContinuousMode; //in,  
    Nat32 timeout; //in,  
    Nat32 listLength; //in,  
    Nat32 cookie; //in,  
    int FilterDepth; //in,  
    Nat8 ModeArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Nat32 retval; //out,  
} tsdmxexRequestListFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pid; //in,  
    int BufferSize; //in,  
    Nat32 cookie; //in,  
    int FilterDepth; //in,  
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Nat32 retval; //out,  
} tsdmxexRequestPes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pid; //in,  
    int BufferSize; //in,  
    Nat32 timeout; //in,  
    Nat32 listLength; //in,  
    Nat32 cookie; //in,  
    int FilterDepth; //in,  
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Nat32 retval; //out,  
} tsdmxexRequestPesList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //in,  
    Nat32 error; //out,  
} tsdmxexSetAudioDescriptivePid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //in,  
    Nat32 error; //out,  
} tsdmxexSetAudioPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Nat32 error; //out,  
} tsdmxexSetAudioStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //in,  
    Nat32 error; //out,  
} tsdmxexSetPcrPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Nat32 error; //out,  
} tsdmxexSetPcrStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 pid; //in,  
    Nat32 error; //out,  
} tsdmxexSetVideoPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamtype; //in,  
    Nat32 error; //out,  
} tsdmxexSetVideoStreamType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 error; //out,  
} tsdmxexStopAudioDescriptivePid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 error; //out,  
} tsdmxexStopAudioPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 error; //out,  
} tsdmxexStopPcrPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 error; //out,  
} tsdmxexStopVideoPid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    int FilterDepth; //in,  
    Nat8 ModeArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Bool retval; //out,  
} tsdmxexUpdateFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscrId; //in,  
    int FilterDepth; //in,  
    Nat8 ModeArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MatchArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat8 MaskArray[16]; //in, data ( sizeof( Nat8 ) * 16 ), 
    Nat32 error; //out,  
    Bool retval; //out,  
} tsdmxexUpdateListFilter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 retval; //out,  
} tunEnableAfc;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Enabled; //out,  
    Nat32 retval; //out,  
} tunGetAfcEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Supp; //out,  
    Nat32 retval; //out,  
} tunGetAfcSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_AfcValue_t Value; //out,  
    Nat32 retval; //out,  
} tunGetAfcValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Chan; //out,  
    Nat32 retval; //out,  
} tunGetChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Offset; //out,  
    Nat32 retval; //out,  
} tunGetChanOffset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinOffset; //out,  
    Nat32 MaxOffset; //out,  
    Nat32 retval; //out,  
} tunGetChanOffsetRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Freq; //out,  
    Nat32 retval; //out,  
} tunGetFreq;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinFreq; //out,  
    Nat32 MaxFreq; //out,  
    Nat32 retval; //out,  
} tunGetFreqRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_SearchMode_t Mode; //out,  
    Nat32 retval; //out,  
} tunGetSearchMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_SearchMode_t mode; //in,  
    Bool Supp; //out,  
    Nat32 retval; //out,  
} tunGetSearchModeSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_SearchState_t State; //out,  
    Nat32 retval; //out,  
} tunGetSearchState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool StationPresent; //out,  
    Nat32 retval; //out,  
} tunGetStationPresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TvSystem_t TvSystem; //out,  
    Nat32 retval; //out,  
} tunGetTvSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TvSystem_t tvSystem; //in,  
    Bool Supp; //out,  
    Nat32 retval; //out,  
} tunGetTvSystemSupp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 chan; //in,  
    Nat32 offset; //in,  
    Nat32 retval; //out,  
} tunSetChan;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 freq; //in,  
    Bool finetune; //in,  
    Nat32 retval; //out,  
} tunSetFreq;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int gain; //in,  
} tunSetTunerGain;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_TvSystem_t TvSystem; //in,  
    Nat32 retval; //out,  
} tunSetTvSystem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmFe_SearchMode_t mode; //in,  
    Nat32 endFreq; //in,  
    Nat32 retval; //out,  
} tunStartSearch;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} tunStopSearch;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int WssData; //in,  
} vbiinsInsertWss;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 retval; //out,  
} vbislEnableAutoSlicing;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Enabled; //out,  
    Nat32 retval; //out,  
} vbislGetAutoSlicingEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 size; //in,  
    Nat32 ActNrVbiLines; //out,  
    Nat32 * Lines; //out, data ( sizeof( Nat32 ) * size ), dynamic ( sizeof( Nat32 ) * size ), 
    tmVbiSlice2_VbiDataSet_t * pDataTypes; //out, data ( sizeof( tmVbiSlice2_VbiDataSet_t ) * size ), dynamic ( sizeof( tmVbiSlice2_VbiDataSet_t ) * size ), 
    Nat32 retval; //out,  
} vbislGetVbiLines;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 subscriptions; //in,  
    Nat32 retval; //out,  
} vbislSetSlicermode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 nrVbiLines; //in,  
    Nat32 * pLines; //in, data ( sizeof( Nat32 ) * nrVbiLines ), dynamic ( sizeof( Nat32 ) * nrVbiLines ), 
    tmVbiSlice2_VbiDataSet_t * DataTypes; //in, data ( sizeof( tmVbiSlice2_VbiDataSet_t ) * nrVbiLines ), dynamic ( sizeof( tmVbiSlice2_VbiDataSet_t ) * nrVbiLines ), 
    Nat32 retval; //out,  
} vbislSetVbiLines;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 id; //in,  
    Nat32 size; //in,  
    Address Data; //in,  
    Bool endOfData; //in,  
    Nat32 retval; //out,  
} vclipAddData;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 retval; //out,  
} vclipEnableClipPlay;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 AvailableNrBuffers; //out,  
    Nat32 retval; //out,  
} vclipGetAvailableNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Enable; //out,  
    Nat32 retval; //out,  
} vclipGetClipPlayEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MaxNrBuffers; //out,  
    Nat32 retval; //out,  
} vclipGetMaxNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmDigVdec_ClipDecodingState_t ClipDecodingState; //out,  
    Nat32 retval; //out,  
} vclipGetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} vclipStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} vclipStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 id; //in,  
    Nat32 size; //in,  
    Address Data; //in,  
    Bool endOfData; //in,  
    Nat32 retval; //out,  
} vclipexAddData;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 retval; //out,  
} vclipexEnableClipPlay;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 retval; //out,  
} vclipexEnableSeek;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 AvailableNrBuffers; //out,  
    Nat32 retval; //out,  
} vclipexGetAvailableNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool Enable; //out,  
    Nat32 retval; //out,  
} vclipexGetClipPlayEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MaxNrBuffers; //out,  
    Nat32 retval; //out,  
} vclipexGetMaxNrBuffers;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool penable; //out,  
    Nat32 retval; //out,  
} vclipexGetSeekEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmDigVdec_ClipDecodingState_t ClipDecodingState; //out,  
    Nat32 retval; //out,  
} vclipexGetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 ptotalseektime; //out,  
    Nat32 retval; //out,  
} vclipexGetTotalSeekTime;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} vclipexPause;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} vclipexResume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 msec; //in,  
    Nat32 retval; //out,  
} vclipexSeek;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} vclipexStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} vclipexStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vfrFreezeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vfrFreezeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vfrGetStrobe;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vfrIsFrozen;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
} vfrSetFreeze;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int period; //in,  
} vfrSetStrobe;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vfrStrobeAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vfrStrobeSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetFieldFrequency;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetImageFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetInterlace;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetMacroVisionType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetNumberOfFrameLines;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetNumberOfVisibleLines;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetNumberOfVisiblePixels;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetSignalPresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetVideoCoding;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetVideoDetectionSensitivity;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetVideoPresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vipGetVideoProtection;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vipIsFilmMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vipIsFromVcr;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pixels; //in,  
    int lines; //in,  
    int scantype; //in,  
    Bool retval; //out,  
} vipIsPCFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int sensitivity; //in,  
    Bool retval; //out,  
} vipIsVideoDetectionSensitivitySupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int sensitivity; //in,  
} vipSetVideoDetectionSensitivity;

/* argument structures for notifications (requires) */
typedef struct {
    Nat32 id; //in,  
} aclipexNOnBufferAvailable;

typedef struct {
    Nat32 totalseektimemsec; //in,  
} aclipexNOnTotalSeekTimeChanged;

typedef struct {
    Nat32 id; //in,  
} aclipNOnBufferAvailable;

typedef struct {
    Nat32 id; //in,  
    Nat32 result; //in,  
} apitestntfTestResult;

typedef struct {
    Nat32 strength; //in,  
} assmNOnMeasReady;

typedef struct {
    Nat32 ber; //in,  
    Nat32 berThreshold; //in,  
} chdec2NOnBerThresholdCrossed;

typedef struct {
    Bool carrier; //in,  
} chdec2NOnCarrierPresentChanged;

typedef struct {
    tmFe_ChanBandwidth_t bandwith; //in,  
} chdec2NOnChanBandwidthDetected;

typedef struct {
    tmFe_CodeRate_t highPrioRate; //in,  
    tmFe_CodeRate_t lowPrioRate; //in,  
} chdec2NOnCodeRateDetected;

typedef struct {
    tmFe_Constellation_t constellation; //in,  
} chdec2NOnConstellationDetected;

typedef struct {
    tmFe_GuardInterval_t interval; //in,  
} chdec2NOnGuardIntervalDetected;

typedef struct {
    tmFe_HierarchyMode_t mode; //in,  
} chdec2NOnHierarchyModeDetected;

typedef struct {
    tmFe_IqMode_t mode; //in,  
} chdec2NOnIqModeDetected;

typedef struct {
    tmFe_TxMode_t mode; //in,  
} chdec2NOnTxModeDetected;

typedef struct {
    Nat32 ber; //in,  
    Nat32 berThreshold; //in,  
} chdecNOnBerThresholdCrossed;

typedef struct {
    Bool carrier; //in,  
} chdecNOnCarrierPresentChanged;

typedef struct {
    tmFe_ChanBandwidth_t bandwith; //in,  
} chdecNOnChanBandwidthDetected;

typedef struct {
    tmFe_CodeRate_t highPrioRate; //in,  
    tmFe_CodeRate_t lowPrioRate; //in,  
} chdecNOnCodeRateDetected;

typedef struct {
    tmFe_Constellation_t constellation; //in,  
} chdecNOnConstellationDetected;

typedef struct {
    tmFe_GuardInterval_t interval; //in,  
} chdecNOnGuardIntervalDetected;

typedef struct {
    tmFe_HierarchyMode_t mode; //in,  
} chdecNOnHierarchyModeDetected;

typedef struct {
    tmFe_IqMode_t mode; //in,  
} chdecNOnIqModeDetected;

typedef struct {
    tmFe_TxMode_t mode; //in,  
} chdecNOnTxModeDetected;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 NbofApplication; //in,  
    CIPlusApplicationInfo_s * list; //in, data ( sizeof( CIPlusApplicationInfo_s ) * NbofApplication ), dynamic ( sizeof( CIPlusApplicationInfo_s ) * NbofApplication ), 
} ciplusaintfAI_ApplicationList;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    Nat16 byteLen; //in,  
    Nat8 * ptbyte; //in, data ( sizeof( Nat8 ) * byteLen ), dynamic ( sizeof( Nat8 ) * byteLen ), 
} ciplusammintfAMMI_AbortRequest;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    Nat16 byteLen; //in,  
    Nat8 * ptbyte; //in, data ( sizeof( Nat8 ) * byteLen ), dynamic ( sizeof( Nat8 ) * byteLen ), 
} ciplusammintfAMMI_AckAbort;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    Nat8 fileOk; //in,  
    CIPlusRequestType_e request_type; //in,  
    Nat32 byteLen; //in,  
    Address shrdmemptByte; //in,  
    Nat16 fileNameLen; //in,  
    Address ptFileName; //in,  
} ciplusammintfAMMI_AckRequest;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
} ciplusammintfAMMI_Close;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
} ciplusammintfAMMI_Open;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 ammiId; //in,  
    Nat8 domainLen; //in,  
    Nat8 * ptDomain; //in, data ( sizeof( Nat8 ) * domainLen ), dynamic ( sizeof( Nat8 ) * domainLen ), 
    Nat8 objectLen; //in,  
    Nat8 * ptObject; //in, data ( sizeof( Nat8 ) * objectLen ), dynamic ( sizeof( Nat8 ) * objectLen ), 
} ciplusammintfAMMI_StartRequest;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat8 nbCaSystemId; //in,  
    CIPlusCaApplicationList_s * listCaSystemId; //in, data ( sizeof( CIPlusCaApplicationList_s ) * nbCaSystemId ), dynamic ( sizeof( CIPlusCaApplicationList_s ) * nbCaSystemId ), 
} cipluscantfCa_ListCaSystemId;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 sessionId; //in,  
    Nat16 programNb; //in,  
    Nat8 versionNb; //in,  
    CIPlusCaEnable_e ProgCaEnable; //in,  
    Nat8 nbStream; //in,  
    CIPlusCaEnableStream_s * streamCaEnable; //in, data ( sizeof( CIPlusCaEnableStream_s ) * nbStream ), dynamic ( sizeof( CIPlusCaEnableStream_s ) * nbStream ), 
} cipluscantfCa_Update;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 brandId; //in,  
} ciplusccntfCC_OnBrandID;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 reference; //in,  
} ciplushcntfHC_ClearRequest;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 oldPID; //in,  
    Nat16 newPID; //in,  
    Nat16 reference; //in,  
} ciplushcntfHC_ReplaceRequest;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 networkId; //in,  
    Nat16 origNetworkId; //in,  
    Nat16 tsId; //in,  
    Nat16 serviceId; //in,  
} ciplushcntfHC_TuneRequest;

typedef struct {
    CIPlusHandle handle; //in,  
    CIPlusResult_e result; //in,  
} ciplusinitntfReturnActivate;

typedef struct {
    CIPlusHandle handle; //in,  
    CIPlusResult_e result; //in,  
} ciplusinitntfReturnEnd;

typedef struct {
    CIPlusHandle handle; //in,  
    CIPlusResult_e result; //in,  
} ciplusinitntfReturnInit;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
} ciplusmmintfMMI_Close;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
    Nat16 blind; //in,  
    Nat16 lenAnswer; //in,  
    Nat16 textLen; //in,  
    Nat8 * textPtr; //in, data ( sizeof( Nat8 ) * textLen ), dynamic ( sizeof( Nat8 ) * textLen ), 
} ciplusmmintfMMI_CmdEnquery;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
    Nat16 nbChoice; //in,  
    Nat16 textLen; //in,  
    Nat8 * textPtr; //in, data ( sizeof( Nat8 ) * textLen ), dynamic ( sizeof( Nat8 ) * textLen ), 
} ciplusmmintfMMI_CmdList;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
    Nat16 nbChoice; //in,  
    Nat16 textLen; //in,  
    Nat8 * textPtr; //in, data ( sizeof( Nat8 ) * textLen ), dynamic ( sizeof( Nat8 ) * textLen ), 
} ciplusmmintfMMI_CmdMenu;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 mmiId; //in,  
} ciplusmmintfMMI_Open;

typedef struct {
    CIPlusHandle handle; //in,  
    CIPlusOrigin_e origin; //in,  
    CIPlusStatus_e status; //in,  
    CIPlusEvent_e event; //in,  
    Nat32 time; //in,  
} ciplusstatusntfOnStatus;

typedef struct {
    CIPlusHandle handle; //in,  
} ciplusupgrntfUPGR_Close;

typedef struct {
    CIPlusHandle handle; //in,  
} ciplusupgrntfUPGR_Open;

typedef struct {
    CIPlusHandle handle; //in,  
    CIPlusUPGRReset_e resetRequest; //in,  
} ciplusupgrntfUPGR_UpgradeComplete;

typedef struct {
    CIPlusHandle handle; //in,  
    Nat16 progress; //in,  
} ciplusupgrntfUPGR_UpgradeProgress;

typedef struct {
    CIPlusHandle handle; //in,  
    CIPlusUPGRType_e upgrType; //in,  
    Nat16 downloadTime; //in,  
} ciplusupgrntfUPGR_UpgradeRequest;

typedef struct {
    int cookie; //in,  
} diseqNOnMsgSent;

typedef struct {
    int Cookie; //in,  
} dvbsNOnLockChanged;

typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} feitfNOnAvailabilityChanged;

typedef struct {
    Nat32 id; //in,  
} gdripNOnBufferAvailable;

typedef struct {
    Nat32 strength; //in,  
} qssmNOnMeasReady;

typedef struct {
    int channel; //in,  
} socNOnSoundPropertiesChanged;

typedef struct {
    Nat32 strength; //in,  
} ssmNOnMeasReady;

typedef struct {
    int alarmid; //in,  
} stcdecNOnCancelled;

typedef struct {
    int alarmid; //in,  
    Bool lockState; //in,  
} stcdecNOnExpired;

typedef struct {
    int winid; //in,  
    Nat16 pid; //in,  
} tsdmxexNOnAudioDescriptivePidStopped;

typedef struct {
    int winid; //in,  
    Nat16 pid; //in,  
} tsdmxexNOnAudioPidStopped;

typedef struct {
    int windowid; //in,  
} tsdmxexNOnBufferOverflow;

typedef struct {
    int winid; //in,  
    Nat16 pid; //in,  
} tsdmxexNOnPcrPidStopped;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
    Nat32 Cookie; //in,  
    Nat32 PSize; //in,  
    Address PAddr; //in,  
    Nat32 SSize; //in,  
    Address SAddr; //in,  
    Nat32 DataCookie; //in,  
} tsdmxexNOnPesArrived;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
} tsdmxexNOnPesCancelled;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
    Nat32 Cookie; //in,  
    Nat32 ListCookie; //in,  
    Nat32 nPackets; //in,  
    tmTsDmx_Pes_t * packets; //in, data ( sizeof( tmTsDmx_Pes_t ) * nPackets ), dynamic ( sizeof( tmTsDmx_Pes_t ) * nPackets ), 
} tsdmxexNOnPesListArrived;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
} tsdmxexNOnPesListCancelled;

typedef struct {
    int windowid; //in,  
} tsdmxexNOnRequestAllowed;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
} tsdmxexNOnRequestCancelled;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
} tsdmxexNOnRequestListCancelled;

typedef struct {
    int windowid; //in,  
} tsdmxexNOnRequestNotAllowed;

typedef struct {
    int winid; //in,  
    int MediaType; //in,  
    int status; //in,  
} tsdmxexNOnScramblingStatusChanged;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
    int Cookie; //in,  
    int CrcStatus; //in,  
    Nat32 PSize; //in,  
    Address PAddr; //in,  
    Nat32 SSize; //in,  
    Address SAddr; //in,  
    Nat32 DataCookie; //in,  
} tsdmxexNOnSectionArrived;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
    int Cookie; //in,  
    Nat32 ListCookie; //in,  
    Nat32 nSections; //in,  
    tmTsDmx_Section_t * sections; //in, data ( sizeof( tmTsDmx_Section_t ) * nSections ), dynamic ( sizeof( tmTsDmx_Section_t ) * nSections ), 
} tsdmxexNOnSectionListArrived;

typedef struct {
    int windowid; //in,  
} tsdmxexNOnSyncLock;

typedef struct {
    int windowid; //in,  
} tsdmxexNOnSyncLost;

typedef struct {
    int winid; //in,  
    Nat16 pid; //in,  
} tsdmxexNOnVideoPidStopped;

typedef struct {
    int winid; //in,  
    Nat16 pid; //in,  
} tsdmxNOnAudioDescriptivePidStopped;

typedef struct {
    int winid; //in,  
    Nat16 pid; //in,  
} tsdmxNOnAudioPidStopped;

typedef struct {
    int windowid; //in,  
} tsdmxNOnBufferOverflow;

typedef struct {
    int winid; //in,  
    Nat16 pid; //in,  
} tsdmxNOnPcrPidStopped;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
    Nat32 Cookie; //in,  
    Nat32 PSize; //in,  
    Address PAddr; //in,  
    Nat32 SSize; //in,  
    Address SAddr; //in,  
    Nat32 DataCookie; //in,  
} tsdmxNOnPesArrived;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
} tsdmxNOnPesCancelled;

typedef struct {
    int windowid; //in,  
} tsdmxNOnRequestAllowed;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
} tsdmxNOnRequestCancelled;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
} tsdmxNOnRequestListCancelled;

typedef struct {
    int windowid; //in,  
} tsdmxNOnRequestNotAllowed;

typedef struct {
    int winid; //in,  
    int MediaType; //in,  
    int status; //in,  
} tsdmxNOnScramblingStatusChanged;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
    int Cookie; //in,  
    int CrcStatus; //in,  
    Nat32 PSize; //in,  
    Address PAddr; //in,  
    Nat32 SSize; //in,  
    Address SAddr; //in,  
    Nat32 DataCookie; //in,  
} tsdmxNOnSectionArrived;

typedef struct {
    int windowid; //in,  
    Nat32 subscrId; //in,  
    int Cookie; //in,  
    Nat32 ListCookie; //in,  
    Nat32 nSections; //in,  
    tmTsDmx_Section_t * sections; //in, data ( sizeof( tmTsDmx_Section_t ) * nSections ), dynamic ( sizeof( tmTsDmx_Section_t ) * nSections ), 
} tsdmxNOnSectionListArrived;

typedef struct {
    int windowid; //in,  
} tsdmxNOnSyncLock;

typedef struct {
    int windowid; //in,  
} tsdmxNOnSyncLost;

typedef struct {
    int winid; //in,  
    Nat16 pid; //in,  
} tsdmxNOnVideoPidStopped;

typedef struct {
    Nat32 freq; //in,  
} tunNOnAfcFreqChanged;

typedef struct {
    Nat32 freq; //in,  
} tunNOnAfcLimitReached;

typedef struct {
    tmFe_SearchState_t state; //in,  
} tunNOnSearchInProgress;

typedef struct {
    tmFe_SearchState_t state; //in,  
} tunNOnSearchStateChanged;

typedef struct {
    tmFe_TvSystem_t tvSystem; //in,  
} tunNOnTvSystemDetected;

typedef struct {
    tmVbiSlice2_Cc_t cctype; //in,  
    Nat32 oLine; //in,  
    Nat32 eLine; //in,  
    Nat16 oField; //in,  
    Nat16 eField; //in,  
} vbislNOnCcData;

typedef struct {
    Bool field; //in,  
} vbislNOnCcNoData;

typedef struct {
    Bool cgmsPresentOddField; //in,  
    Bool cgmsPresentEvenField; //in,  
    Bool dataValidOddField; //in,  
    Bool dataValidEvenField; //in,  
    Nat8 dataOddField; //in,  
    Nat8 dataEvenField; //in,  
} vbislNOnCgmsData;

typedef struct {
    Nat32 nrLines; //in,  
    Nat32 * pLines; //in, data ( sizeof( Nat32 ) * nrLines ), dynamic ( sizeof( Nat32 ) * nrLines ), 
    tmVbiSlice2_Gemstar_t * Types; //in, data ( sizeof( tmVbiSlice2_Gemstar_t ) * nrLines ), dynamic ( sizeof( tmVbiSlice2_Gemstar_t ) * nrLines ), 
    Nat32 size; //in,  
    Nat8 * Buffer; //in, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
} vbislNOnGemstarData;

typedef struct {
    tmVbiSlice2_Gemstar_t gemstarType; //in,  
} vbislNOnGemstarNoData;

typedef struct {
    Nat8 size; //in,  
    Nat8 * Buffer; //in, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
} vbislNOnVpsData;

typedef struct {
    tmVbiSlice2_Wss_t wsstype; //in,  
    Bool wssPresentOddField; //in,  
    Bool wssPresentEvenField; //in,  
    Nat16 dataOddField; //in,  
    Nat16 dataEvenField; //in,  
    Nat16 errorBitsOddField; //in,  
    Nat16 errorBitsEvenField; //in,  
} vbislNOnWssData;

typedef struct {
    tmVbiSlice2_Wst_t wsttype; //in,  
    Nat32 nrLines; //in,  
    Nat32 * pLines; //in, data ( sizeof( Nat32 ) * nrLines ), dynamic ( sizeof( Nat32 ) * nrLines ), 
    Nat32 sizeFirstBuffer; //in,  
    Nat32 sizeSecondBuffer; //in,  
    Nat8 * FirstBuffer; //in, data ( sizeof( Nat8 ) * sizeFirstBuffer ), dynamic ( sizeof( Nat8 ) * sizeFirstBuffer ), 
    Nat8 * SecondBuffer; //in, data ( sizeof( Nat8 ) * sizeSecondBuffer ), dynamic ( sizeof( Nat8 ) * sizeSecondBuffer ), 
} vbislNOnWstData;

typedef struct {
    Nat32 id; //in,  
} vclipexNOnBufferAvailable;

typedef struct {
    Nat32 totalseektimemsec; //in,  
} vclipexNOnTotalSeekTimeChanged;

typedef struct {
    Nat32 id; //in,  
} vclipNOnBufferAvailable;

typedef struct {
    Bool Frozen; //in,  
} vfrNOnFreezeCompleted;

typedef struct {
    int period; //in,  
} vfrNOnStrobeChanged;

#endif /* _PLFAPIFE_INTERNAL_H_ */

