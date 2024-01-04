//
//  AlivcLivePushDef.h
//  AlivcLivePusher
//
//  Created by siheng on 2022/7/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AlivcLivePushConstants.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 音频裸数据
 */

/****
 * @brief Raw audio data
 */
@interface AlivcLivePusherAudioDataSample : NSObject

@property (nonatomic, assign) long dataPtr;//强制转换成(uint8_t*)dataPtr即为PCM数据buffer内存首地址 Forcefully converted to (uint8_t*)dataPtr, which is the memory address of the PCM data buffer
@property (nonatomic, assign) int numOfSamples;//数据总大小为numOfSamples*bytesPerSample Total data size numOfSamples*bytesPerSample
@property (nonatomic, assign) int bytesPerSample;
@property (nonatomic, assign) int numOfChannels;
@property (nonatomic, assign) int samplesPerSec;

@end

/**
 * @brief 外部音频流配置
 */
@interface AliLiveExternalAudioStreamConfig : NSObject
/** 声道数，默认值：1 */
@property (nonatomic, assign) int channels;
/** 采样率，默认值：48000 */
@property (nonatomic, assign) int sampleRate;
/** 播放音量，取值范围[0-100]，默认值：50 */
@property (nonatomic, assign) int playoutVolume;
/** 推流音量，取值范围[0-100]，默认值：50 */
@property (nonatomic, assign) int publishVolume;
/** 指定绑定的音频流 1-第二音频流，0-MIC流  默认值：0*/
@property (nonatomic, assign) int publishStream;
@end

/**
 * @brief 网络探测的参数配置
 */
@interface AliLiveNetworkQualityProbeConfig : NSObject
/** 是否探测上行，默认值：NO */
@property (nonatomic, assign) BOOL probeUplink;
/** 是否探测下行，默认值：NO  暂不支持 */
@property (nonatomic, assign) BOOL probeDownlink;
/** 探测上行带宽峰值，单位kbps 默认值：1000 */
@property (nonatomic, assign) int upLinkBandWidth;
/** 探测下行带宽峰值，单位kbps 默认值：1000  暂不支持 */
@property (nonatomic, assign) int DownLinkBandWidth;
@end

/**
 * @brief 网络探测的结果
 */
@interface AliLiveNetworkQualityProbeResult : NSObject
/** 探测链路的rtt  单位ms*/
@property (nonatomic, assign) int rtt;
/** 上行的丢包率 最大值100 */
@property (nonatomic, assign) int upLinkLossRate;
/** 探测上行链路的jitter 单位ms  */
@property (nonatomic, assign) int upLinkJitter;
/** 探测上行链路的带宽，单位kbps */
@property (nonatomic, assign) int upLinkBandWidth;
/** 下行的丢包率 最大值100 暂不支持 */
@property (nonatomic, assign) int downLinkLossRate;
/** 探测下行链路的jitter 单位ms  暂不支持 */
@property (nonatomic, assign) int downLinkJitter;
/** 探测下行链路的带宽，单位kbps 暂不支持 */
@property (nonatomic, assign) int downLinkBandWidth;
@end


/**
 * @brief 直播连麦播放参数配置
 */

/****
 * @brief Live play parameter settings
 */
@interface AlivcLivePlayConfig : NSObject
/**
 * @brief 渲染模式
 * default：AlivcLivePlayRenderModeAuto
 */

/****
 * @brief The rendering mode
 * default：AlivcLivePlayRenderModeAuto
 */
@property (nonatomic) AlivcLivePlayRenderMode renderMode;

/**
 * @brief 播放是否镜像
 * default：false，非镜像
 */

/****
 * @brief Whether play is mirrored.
 * default：false
 */
@property (nonatomic, assign) BOOL mirror;

/**
 * @brief 旋转角度
 * default： AlivcLivePlayRotationMode_0
 */

/****
 * @brief The rotation angle
 * default： AlivcLivePlayRotationMode_0
 */
@property (nonatomic, assign) AlivcLivePlayRotationMode rotationMode;

/**
 * @brief 视频流类型
 * default: AlivcLivePlayVideoStreamTypeCamera
 */

/****
 * @brief Video stream type
 * default: AlivcLivePlayVideoStreamTypeCamera
 */
@property (nonatomic, assign) AlivcLivePlayVideoStreamType videoStreamType;
@end


/**
 * 云端混流（转码）中每一路子画面的位置信息
 */

/****
 * Position information of each layer in mixed-stream transcoding
 */
@interface AlivcLiveMixStream : NSObject

/**
 参与混流的 userId
 备注：和推拉地址中userId字端相同
 */

/****
 * The ID of the user who performs stream mixing.
 * Note: It is the same as the user ID in the source URL and ingest URL.
 */
@property (nonatomic, copy, nonnull) NSString *userId;

/**
 * 图层位置 x 坐标（绝对像素值）
 */

/****
 * The X coordinate value of the layer (absolute pixels).
 */
@property (nonatomic, assign) int x;

/**
 * 图层位置 y坐标（绝对像素值）
 */

/****
 * The Y coordinate value of the layer (absolute pixels).
 */
@property (nonatomic, assign) int y;

/**
 * 图层宽度（绝对像素值）
 */

/****
 * The width of the layer (absolute pixels).
 */
@property (nonatomic, assign) int width;

/**
 * The height of the layer (absolute pixels).
 */
@property (nonatomic, assign) int height;
/**
 *  图层层次（1 - 15）不可重复
 */

/****
 *  The sequence number of the layer. Valid values: 1 to 15. The sequence numbers of any two layers cannot be the same
 */
@property (nonatomic, assign) int zOrder;

/**
 * 混入的流类型
 */

/****
 * mixed-in stream type
 */
@property (nonatomic, assign) AlivcLiveMixStreamType streamType;

/**
 * 混入的流类型
 */

/****
 * mixed-in stream type
 */
@property (nonatomic, assign) AlivcLiveMixSourceType sourceType;

@end

/**
 * 云端混流（转码）配置
 */

/****
 * Mixed-stream transcoding configuration
 */
@interface AlivcLiveTranscodingConfig : NSObject

/**
 * 混合后画面的底色颜色，默认为黑色，格式为十六进制数字,0xRRGGBB
 * 默认：0x000000
 */

/****
 * The background color of the mixed stream. The default value is black. The format is hexadecimal.
 * default：0x000000
 */
@property (nonatomic, assign) int backgroundColor;

/**
 * 混合后视频画面裁剪模式
 * 默认：AlivcLiveTranscodingCropModeCrop
 */

/****
 * The video cropping mode of the mixed stream.
 * default：AlivcLiveTranscodingCropModeCrop
 */
@property (nonatomic, assign) AlivcLiveTranscodingCropMode cropMode;


@property (nonatomic, strong, nonnull) NSArray<AlivcLiveMixStream *> *mixStreams;

@end

@interface AlivcLiveVideoDataSample : NSObject

@property (nonatomic, assign) AlivcLivePushVideoFormat format;
@property (nonatomic, assign) AlivcLiveBufferType type;
@property (nonatomic, assign) CVPixelBufferRef _Nullable pixelBuffer;
@property (nonatomic, assign) long dataPtr;
@property (nonatomic, assign) long dataYPtr;
@property (nonatomic, assign) long dataUPtr;
@property (nonatomic, assign) long dataVPtr;
@property (nonatomic, assign) long dataLength;
@property (nonatomic, assign) int strideY;
@property (nonatomic, assign) int strideU;
@property (nonatomic, assign) int strideV;
@property (nonatomic, assign) int stride;
@property (nonatomic, assign) int height;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int rotation;
@property (nonatomic, assign) long long timeStamp;
@property (nonatomic, assign) int encodeCostMs;

@end

@interface AlivcLiveBGMConfig : NSObject
/** 是否只本地播放，默认值：NO */
@property (nonatomic, assign) BOOL onlyLocalPlay;
/** 是否替换掉MIC，默认值：NO */
@property (nonatomic, assign) BOOL replaceMic;
/** 循环次数，可以设置-1(无限循环)或者>0的正整数次，其他值无效，默认值：-1 */
@property (nonatomic, assign) int loopCycles;
/** 起播位置，单位：ms，默认值：0 */
@property (nonatomic, assign) NSInteger startPosMs;
/** 推流音量，取值范围[0-100]，默认值：50 */
@property (nonatomic, assign) int publishVolume;
/** 播放音量，取值范围[0-100]，默认值：50 */
@property (nonatomic, assign) int playoutVolume;

@end

@interface AlivcLivePlayerStatsInfo : NSObject

#pragma mark - system
/**
 用户ID
 */

/****
 * User ID
 */
@property (nonatomic, copy) NSString * _Nonnull userId;

/**
 视频宽度
 */

/****
 The width of the video
 */
@property(nonatomic, assign) int videoWidth;

/**
 视频高度
 */

/****
 The height of the video
 */
@property(nonatomic, assign) int videoHeight;

/**
 视频解码FPS
 * 单位 : Frames per Second
 */

/****
 The FPS for video decode
 * 单位 : Frames per Second
 */
@property (nonatomic, assign) int decodeFps;

/**
 视频渲染FPS
 * 单位 : Frames per Second
 */

/****
 The FPS for video render
 * 单位 : Frames per Second
 */
@property (nonatomic, assign) int renderFps;

/**
 视频码率（当前视频码率是所有接收的总码率）
 * Kbps
 */

/****
 video bitrate
 * Kbps
 */
@property (nonatomic, assign) int videoBitrate;

/**
 * 视频播放的累计卡顿时长，单位ms
 */

/****
 total video frozen times
 */
@property (nonatomic, assign)  int totalVideoFrozenTime;

/**
 视频播放的卡顿率，单位% 计算方法 视频播放卡顿率=视频播放的累计卡顿时长/视频播放的总时长
 */
@property (nonatomic, assign)  int videoFrozenRate;

/**
 远端用户加入频道后音频卡顿的累计时长(ms)
 */
@property (nonatomic, assign) int totalAudioFrozenTime;

/**
  音频播放卡顿率 单位% 计算方法 音频播放卡顿率=音频播放的累计卡顿时长/音频播放的总时长
 */
@property (nonatomic, assign)  int audioFrozenRate;

/**
 音频链路发送端到接收端的网络延时（ms)
 */
@property (nonatomic, assign) int networkTransportDelay;

/**
 音频链路接收端到网络抖动缓存的网络延时（ms)
 */
@property (nonatomic, assign) int jitterBufferDelay;

/**
 音频码率
 * Kbps
 */

/****
 audio bitrate
 * Kbps
 */
@property (nonatomic, assign) int audioBitrate;


/**
 音频丢包率
 * %
 */

/****
 audio loss rate
 * %
 */
@property (nonatomic, assign) int audioLossRate;;

/**
 丢包率 (网络丢包率)
 * %
 */

/****
 loss rate
 * %
 */
@property (nonatomic, assign) int lossRate;


@end


@interface AlivcLiveLocalRecoderConfig : NSObject

/**
 * 录音文件在本地保存的绝对路径，需精确到文件名及格式（必填）。请确保路径有读写权限且合法，否则录制文件无法生成。
 * 该路径需要精确到文件名及格式后缀，格式后缀用于决定录制出的文件格式。
 * 例如 /App Sandbox/Library/Caches/local.mp4, 请确保你指定的路径存在并且可写, 目前支持的视频录制格式只有MP4。
 */
/****
 * Absolute path to local recording files
 *
 * @note Please ensure that the path has read and write permissions and is legal, otherwise local recording files will not be generated
 * @note The absolute path of the local recording file, which needs to be precise to the file name and format
*/
@property (nonatomic, copy) NSString *_Nonnull storagePath;


/**
 * 媒体录制类型，默认是AlivcLiveRecordTypeAudioAndVideo， 即同时录制音频和视频
 */
/****
    * Stream type for local recording
    *
    * @note Default AlivcLiveRecordTypeAudioAndVideo, which means recording audio and video simultaneously
    * @see AlivcLiveRecordType
    */
@property (nonatomic, assign) AlivcLiveRecordType recordType;

/**
 * 录制视频最大文件长度，单位：字节，默认是0
 * 1. 如果设置为0或者-1，SDK内部按照2G大小进行分块，录制文件超过2G则回调相应事件，并在设置的文件尾上追加块编号重新在新的文件上进行录制；
 * 2. 如果设置了>0的值，则发现文件超过该值后停止录制，同时在onMediaRecordEvent回调消息；
 * 如果需要控制录制文件大小，可以设置该字段
 * 注：该字段只有在recordType=AlivcLiveRecordTypeAudioAndVideo，即需要生成AlivcLiveRecordFormatMP4格式的Mp4文件时生效；如果recordType=AlivcLiveRecordTypePureAudio，设置该字段无效
 */
/****
 * Maximum file length for local recording, in bytes
 *
 * @note If you need to control the recording file size, you can set this field
 * @note 1. If set to 0 or -1, the SDK will be divided into blocks according to the size of 2G internally.
 * @note If the recorded file exceeds 2G, the corresponding event will be recalled, and the block number will be added to the end of the set file to record on a new file;
 * @note 2. If a value>0 is set, the recording will stop after the file exceeds this value, and a callback message will be sent to onMediaRecordEvent;
*/
@property (nonatomic, assign) NSInteger maxSize;

/**
 * 录制视频最大时长, 单位：秒，默认是0
 * 如果等于0或者小于0，则不对录制时长做限制
 * 如果设置了时间长度限制，则超过限制时长停止录制，同时onMediaRecordEvent回调消息；
 * 如果需要控制录制文件时长，可以设置该字段
 * 注：该字段只有在recordType=AlivcLiveRecordTypeAudioAndVideo，即需要生成AlivcLiveRecordFormatMP4格式的Mp4文件时生效；如果recordType=AlivcLiveRecordTypePureAudio，设置该字段无效
 */
/****
 * The maximum duration of local recording, in seconds, defaults to 0
 *
 * @note If equal to or less than 0, there is no limit on the recording duration
 * @note If a time limit is set, recording will stop if the limit is exceeded, and an onMediaRecordEvent callback message will be sent;
 * @note If you need to control the duration of recording files, you can set this field
 * @note Note: This field only takes effect when generating MP4 files; If generating a pure audio local file, setting this field is invalid
 */
@property (nonatomic, assign) NSInteger maxDuration;

/**
 * 录制音频的质量，详见 AlivcLiveRecordAudioQuality
 * 默认：AlivcLiveRecordAudioQualityMidium
 */
/****
 * Local recording audio quality
 *
 * @note Default: AlivcLiveRecordAudioQualityMidium
 * @see AlivcLiveRecordAudioQuality
*/
@property (nonatomic, assign) AlivcLiveRecordAudioQuality recordAudioQuality;

/**
 * 录制格式，默认：AlivcLiveRecordFormatMP4
 * 注：如果record指定为AlivcLiveRecordTypePureAudio，则recordFormat不能指定为AlivcLiveRecordFormatMP4；
 *   如果record指定为AlivcLiveRecordTypeAudioAndVideo，则recordFormat需要指定为AlivcLiveRecordFormatMP4；
 */
/****
 * Local recording media format
 *
 * @note Default: AlivcLiveRecordFormatMP4
 * @see AlivcLiveRecordFormat
*/
@property (nonatomic, assign) AlivcLiveRecordFormat recordFormat;

/**
 * 录制音频的采样率，默认：AlivcLivePushAudioSampleRate48000
 */
/****
 * Local recording audio sampling rate
 *
 * @note Default: AlivcLivePushAudioSampleRate48000
 * @see AlivcLivePushAudioSampleRate
*/
@property (nonatomic, assign) AlivcLivePushAudioSampleRate recordAudioSamplerate;

@end

NS_ASSUME_NONNULL_END
