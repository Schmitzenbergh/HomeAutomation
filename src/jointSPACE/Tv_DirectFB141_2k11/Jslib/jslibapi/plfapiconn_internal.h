
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


#if !defined(_PLFAPICONN_INTERNAL_H_)
#define _PLFAPICONN_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamid; //out,  
    Nat32 retval; //out,  
} cmdmxAllocateClientStream;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamid; //in,  
    Nat32 datacookie; //in,  
    Nat32 retval; //out,  
} cmdmxFree;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 AvailClientStr; //out,  
    Nat32 retval; //out,  
} cmdmxGetAvailableClientStreams;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmCmDmx_PlatformStreamType_t platformStreamType; //in,  
    int streamid; //out,  
    Nat32 retval; //out,  
} cmdmxGetPlatformStream;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 streamIndex; //in,  
    Nat16 langSize; //in,  
    tmCmDmx_StreamType_t StreamType; //out,  
    char * streamLanguage; //out, data ( sizeof( char ) * langSize ), dynamic ( sizeof( char ) * langSize ), 
    Nat32 retval; //out,  
} cmdmxGetStreamInfo;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 NumberOfStreams; //out,  
    Nat32 retval; //out,  
} cmdmxGetStreamMapSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmCmDmx_SuppPlatformStreamTypes_t SuppPlatformStreams; //out,  
    Nat32 retval; //out,  
} cmdmxGetSupportedPlatformStreams;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamid; //in,  
    tmCmDmx_BufferType_t bufferType; //in,  
    Nat32 bufferSize; //in,  
    Nat32 granularity; //in,  
    tmCmDmx_Buffer_t buffer; //in,  
    Nat32 retval; //out,  
} cmdmxSetBuffer;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamid; //in,  
    Nat32 streamIndex; //in,  
    Nat32 retval; //out,  
} cmdmxSetStreamIndex;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamid; //in,  
    Nat32 retval; //out,  
} cmdmxStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int streamid; //in,  
    Nat32 retval; //out,  
} cmdmxStop;

typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} connitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 * key; //in, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    int size; //in,  
    Bool retval; //out,  
} dcfSetAesContentKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 requestedHorRes; //in,  
    Nat32 requestedVertRes; //in,  
    Nat32 stride; //in,  
    tmPixFmtCls_t formatClass; //in,  
    tmPixFmtType_t formatType; //in,  
    Bool useImageArea; //in,  
    tmImageDec2_ImageArea_t requestedImageArea; //in,  
    Nat32 bufferSize; //in,  
    tmImageDec_Buffer_t Buffer; //in,  
    Nat32 retval; //out,  
} imgdecDecodeImage;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 requestedHorRes; //in,  
    Nat32 requestedVertRes; //in,  
    Nat32 stride; //in,  
    tmPixFmtCls_t formatClass; //in,  
    tmPixFmtType_t formatType; //in,  
    Nat32 bufferSize; //in,  
    tmImageDec_Buffer_t Buffer; //in,  
    Nat32 retval; //out,  
} imgdecDecodeThumbnail;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 BufAlignment; //out,  
    Nat32 retval; //out,  
} imgdecGetBufAlignment;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MaxHorRes; //out,  
    Nat32 MaxVertRes; //out,  
    Nat32 retval; //out,  
} imgdecGetMaxResolution;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool MetaDataPresent; //out,  
    Nat32 retval; //out,  
} imgdecGetMetaDataPresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} imgdecGetOrgFullResolution;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 Numerator; //out,  
    Nat16 Denominator; //out,  
    Nat32 retval; //out,  
} imgdecGetOrgImageAspectRatio;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmImageDec2_Orientation_t Orientation; //out,  
    Nat32 retval; //out,  
} imgdecGetOrgImageOrientation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 HorRes; //out,  
    Nat32 VertRes; //out,  
    Nat32 retval; //out,  
} imgdecGetOrgThumbnailResolution;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmImageDec2_ImageFormat_t ImageFormat; //out,  
    Nat32 retval; //out,  
} imgdecGetRawMetaData;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmImageDec2_RotationMode_t Mode; //out,  
    tmImageDec2_Orientation_t Orientation; //out,  
    Nat32 retval; //out,  
} imgdecGetRotationMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 MinHorPercentage; //out,  
    Nat32 MinVertPercentage; //out,  
    Nat32 MaxHorPercentage; //out,  
    Nat32 MaxVertPercentage; //out,  
    Nat32 retval; //out,  
} imgdecGetScaleRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPixFmtClsSet_t FormatClasses; //out,  
    Nat32 retval; //out,  
} imgdecGetSuppFormatClasses;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmPixFmtCls_t formatClass; //in,  
    tmPixFmtTypeSet_t FormatTypes; //out,  
    Nat32 retval; //out,  
} imgdecGetSuppFormatTypes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmImageDec2_ImageFormats_t Formats; //out,  
    Nat32 retval; //out,  
} imgdecGetSuppImageFormats;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmImageDec2_RotationModes_t Modes; //out,  
    Nat32 retval; //out,  
} imgdecGetSupportedRotationModes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} imgdecGetThumbnailPresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmImageDec2_RotationMode_t mode; //in,  
    tmImageDec2_Orientation_t orientation; //in,  
    Nat32 retval; //out,  
} imgdecSetRotationMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * url; //in, string,  dynamic ( ( url == NULL ? 0 : strlen( url ) ) + 1 ), 
    Nat32 cookie; //out,  
} mdGetAvType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} netschemecfgGetNetworkJitter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 milliseconds; //in,  
} netschemecfgSetNetworkJitter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcjpgAbortAction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcjpgCloseUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_StepModes_t AvailStepModes; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetAvailStepModes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 BufferFullness; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetBufferFullness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Time; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetPosition;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_SeekMode_t seekMode; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetSeekMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 timeDuration; //in,  
    Nat32 numberOfBytes; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetSizeForDuration;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int8 requestedSpeedNum; //out,  
    Nat8 requestedSpeedDenom; //out,  
    Int8 ActualSpeedNum; //out,  
    Nat8 ActualSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetSpeed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool ReverseSupp; //out,  
    Nat8 MinSpeedNum; //out,  
    Nat8 MinSpeedDenom; //out,  
    Nat8 MaxSpeedNum; //out,  
    Nat8 pMaxSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetSpeedRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_Schemes_t SupportedSchemes; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetSuppSchemes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 TotalDuration; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetTotalDuration;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat64 TotalSize; //out,  
    Nat32 retval; //out,  
} urlsrcjpgGetTotalSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 size; //in,  
    Nat32 ActualSize; //out,  
    Nat8 * url; //out, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    Nat32 retval; //out,  
} urlsrcjpgGetUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * url; //in, string,  dynamic ( ( url == NULL ? 0 : strlen( url ) ) + 1 ), 
    Nat32 timeOut; //in,  
    Nat32 retval; //out,  
} urlsrcjpgOpenUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcjpgPause;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcjpgResume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 requestedTime; //in,  
    tmUrlSrc_Rounding_t rounding; //in,  
    Nat32 retval; //out,  
} urlsrcjpgSetPosition;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_SeekMode_t seekMode; //in,  
    Nat32 retval; //out,  
} urlsrcjpgSetSeekMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int8 requestedSpeedNum; //in,  
    Nat8 requestedSpeedDenom; //in,  
    Int8 ActualSpeedNum; //out,  
    Nat8 ActualSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcjpgSetSpeed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcjpgStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcjpgStepBackward;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcjpgStepForward;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcjpgStop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcmp3AbortAction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcmp3CloseUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_StepModes_t AvailStepModes; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetAvailStepModes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 BufferFullness; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetBufferFullness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Time; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetPosition;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_SeekMode_t seekMode; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetSeekMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 timeDuration; //in,  
    Nat32 numberOfBytes; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetSizeForDuration;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int8 requestedSpeedNum; //out,  
    Nat8 requestedSpeedDenom; //out,  
    Int8 ActualSpeedNum; //out,  
    Nat8 ActualSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetSpeed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool ReverseSupp; //out,  
    Nat8 MinSpeedNum; //out,  
    Nat8 MinSpeedDenom; //out,  
    Nat8 MaxSpeedNum; //out,  
    Nat8 pMaxSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetSpeedRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_Schemes_t SupportedSchemes; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetSuppSchemes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 TotalDuration; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetTotalDuration;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat64 TotalSize; //out,  
    Nat32 retval; //out,  
} urlsrcmp3GetTotalSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 size; //in,  
    Nat32 ActualSize; //out,  
    Nat8 * url; //out, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    Nat32 retval; //out,  
} urlsrcmp3GetUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * url; //in, string,  dynamic ( ( url == NULL ? 0 : strlen( url ) ) + 1 ), 
    Nat32 timeOut; //in,  
    Nat32 retval; //out,  
} urlsrcmp3OpenUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcmp3Pause;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcmp3Resume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 requestedTime; //in,  
    tmUrlSrc_Rounding_t rounding; //in,  
    Nat32 retval; //out,  
} urlsrcmp3SetPosition;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_SeekMode_t seekMode; //in,  
    Nat32 retval; //out,  
} urlsrcmp3SetSeekMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int8 requestedSpeedNum; //in,  
    Nat8 requestedSpeedDenom; //in,  
    Int8 ActualSpeedNum; //out,  
    Nat8 ActualSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcmp3SetSpeed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcmp3Start;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcmp3StepBackward;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcmp3StepForward;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcmp3Stop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcvidAbortAction;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcvidCloseUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_StepModes_t AvailStepModes; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetAvailStepModes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 BufferFullness; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetBufferFullness;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 Time; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetPosition;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_SeekMode_t seekMode; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetSeekMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 timeDuration; //in,  
    Nat32 numberOfBytes; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetSizeForDuration;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int8 requestedSpeedNum; //out,  
    Nat8 requestedSpeedDenom; //out,  
    Int8 ActualSpeedNum; //out,  
    Nat8 ActualSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetSpeed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool ReverseSupp; //out,  
    Nat8 MinSpeedNum; //out,  
    Nat8 MinSpeedDenom; //out,  
    Nat8 MaxSpeedNum; //out,  
    Nat8 pMaxSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetSpeedRange;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_Schemes_t SupportedSchemes; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetSuppSchemes;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 TotalDuration; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetTotalDuration;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat64 TotalSize; //out,  
    Nat32 retval; //out,  
} urlsrcvidGetTotalSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 size; //in,  
    Nat32 ActualSize; //out,  
    Nat8 * url; //out, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    Nat32 retval; //out,  
} urlsrcvidGetUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * url; //in, string,  dynamic ( ( url == NULL ? 0 : strlen( url ) ) + 1 ), 
    Nat32 timeOut; //in,  
    Nat32 retval; //out,  
} urlsrcvidOpenUrl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcvidPause;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcvidResume;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 requestedTime; //in,  
    tmUrlSrc_Rounding_t rounding; //in,  
    Nat32 retval; //out,  
} urlsrcvidSetPosition;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmUrlSrc_SeekMode_t seekMode; //in,  
    Nat32 retval; //out,  
} urlsrcvidSetSeekMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Int8 requestedSpeedNum; //in,  
    Nat8 requestedSpeedDenom; //in,  
    Int8 ActualSpeedNum; //out,  
    Nat8 ActualSpeedDenom; //out,  
    Nat32 retval; //out,  
} urlsrcvidSetSpeed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcvidStart;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcvidStepBackward;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcvidStepForward;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} urlsrcvidStop;

/* argument structures for notifications (requires) */
typedef struct {
    Nat32 dataCookie; //in,  
    Nat32 primaryDataSize; //in,  
    tmCmDmx_Buffer_t PrimaryDataStartAddress; //in,  
    Nat32 secondaryDataSize; //in,  
    tmCmDmx_Buffer_t SecondaryDataStartAddress; //in,  
} cmdmxNOnDataArrived;

typedef struct {
    Nat32 bitRate; //in,  
} cmdmxNOnSystemBitRateChanged;

typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} connitfNOnAvailabilityChanged;

typedef struct {
    tmDigAdec_Error_t err; //in,  
} digadecNOnError;

typedef struct {
    tmDigVdec_Error_t err; //in,  
} digvdecNOnError;

typedef struct {
    tmDigVdec_CompressionStandard_t standard; //in,  
    tmDigVdec_Profile_t profile; //in,  
    tmDigVdec_Level_t level; //in,  
} digvdecNOnStandardDataChanged;

typedef struct {
    tmImageDec2_Status_t status; //in,  
} imgdecNOnFullImageDecoded;

typedef struct {
    Nat32 size; //in,  
    tmImageDec_Buffer_t RawData; //in,  
} imgdecNOnMetaDataFound;

typedef struct {
    tmImageDec2_Status_t status; //in,  
    Nat32 horRes; //in,  
    Nat32 vertRes; //in,  
} imgdecNOnResolutionObtained;

typedef struct {
    tmImageDec2_Status_t status; //in,  
} imgdecNOnThumbnailDecoded;

typedef struct {
    tmImageDec2_Status_t status; //in,  
    Bool presence; //in,  
} imgdecNOnThumbnailPresence;

typedef struct {
    int winid; //in,  
    Nat32 cookie; //in,  
    MediaDetect_Format_t fmt; //in,  
} mdNOnAvTypeNotify;

typedef struct {
    tmUrlSrc_BufferingState_t bufferState; //in,  
} urlsrcjpgNOnBufferingStatusChanged;

typedef struct {
    Nat64 bytesConsumed; //in,  
} urlsrcjpgNOnDataConsumed;

typedef struct {
    tmUrlSrc_NotAccessibleCause_t cause; //in,  
} urlsrcjpgNOnNotAccessible;

typedef struct {
    Nat32 timePlayed; //in,  
} urlsrcjpgNOnPlayTimeChanged;

typedef struct {
    Nat32 actualTime; //in,  
    Bool endOfStreamReached; //in,  
} urlsrcjpgNOnSetPositionCompleted;

typedef struct {
    tmUrlSrc_BufferingState_t bufferState; //in,  
} urlsrcmp3NOnBufferingStatusChanged;

typedef struct {
    Nat64 bytesConsumed; //in,  
} urlsrcmp3NOnDataConsumed;

typedef struct {
    tmUrlSrc_NotAccessibleCause_t cause; //in,  
} urlsrcmp3NOnNotAccessible;

typedef struct {
    Nat32 timePlayed; //in,  
} urlsrcmp3NOnPlayTimeChanged;

typedef struct {
    Nat32 actualTime; //in,  
    Bool endOfStreamReached; //in,  
} urlsrcmp3NOnSetPositionCompleted;

typedef struct {
    tmUrlSrc_BufferingState_t bufferState; //in,  
} urlsrcvidNOnBufferingStatusChanged;

typedef struct {
    Nat64 bytesConsumed; //in,  
} urlsrcvidNOnDataConsumed;

typedef struct {
    tmUrlSrc_NotAccessibleCause_t cause; //in,  
} urlsrcvidNOnNotAccessible;

typedef struct {
    Nat32 timePlayed; //in,  
} urlsrcvidNOnPlayTimeChanged;

typedef struct {
    Nat32 actualTime; //in,  
    Bool endOfStreamReached; //in,  
} urlsrcvidNOnSetPositionCompleted;

#endif /* _PLFAPICONN_INTERNAL_H_ */

