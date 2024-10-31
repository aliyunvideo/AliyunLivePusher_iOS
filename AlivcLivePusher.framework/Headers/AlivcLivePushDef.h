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

@property (nonatomic, assign) void* _Nullable dataPtr;
@property (nonatomic, assign) int numOfSamples;//数据总大小为numOfSamples*bytesPerSample*numOfChannels Total data size numOfSamples*bytesPerSample*numOfChannels
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
/** 送入数据的时延控制，单位10ms */
@property (nonatomic, assign) int pushBufferSize;
@end

/**
 * @brief 音频数据回调参数设置
 *
 */
@interface AliLiveAudioFrameObserverConfig : NSObject
/* 回调音频采样率 */
@property (nonatomic, assign)AlivcLivePushAudioSampleRate sampleRate;
/* 回调音频声道数 */
@property (nonatomic, assign)AlivcLivePushAudioChannel channels;
/* 回调模式 */
@property (nonatomic, assign)AliLiveAudioFrameObserverOperationMode mode;
/* 自定义参数 */
@property (nonatomic, assign)AliLiveAudioFrameObserverUserDefinedInfoBitMask userDefinedInfo;
@end

@interface AliLiveVideoEncoderConfiguration : NSObject

/*! 视频分辨率，默认值540x960，最大值1920x1080
*/
@property (nonatomic, assign) CGSize dimensions;

/*! 视频帧率，默认值15, 最大值30
*/
@property (nonatomic, assign) NSInteger frameRate;

/*! 视频编码码率(Kbps)
- 默认值 512
- 设置为0，表示由SDK内部根据视频分辨率和码率计算合适的编码码率
- 码率设置根据分辨率和帧率有对应的合理范围，该值设置在合理范围内有效，否则SDK会自动调节码率到有效值

@note
以下码表列举常见的分辨率、帧率对应的编码码率设置的区间

 | 分辨率                  | 帧率(fps)     | 最小码率 (Kbps)                    | 推荐码率(Kbps)             |最大码率(Kbps)
 |--------------------- |--------------|---------------------------------|----------------------------|------------
 | 120 * 120              | 5                 | 10                                         | 25                                    | 75
 | 120 * 120              | 10               | 17                                         | 50                                    | 150
 | 120 * 120              | 15               | 25                                         | 70                                    | 210
 | 120 * 120              | 20               | 34                                         | 90                                    | 270
 | 120 * 120              | 30               | 50                                         | 115                                  | 345
 | 160 * 120              | 5                 | 10                                         | 30                                    | 90
 | 160 * 120              | 10               | 20                                         | 55                                    | 165
 | 160 * 120              | 15               | 30                                         | 80                                    | 240
 | 160 * 120              | 20               | 40                                         | 100                                  | 300
 | 160 * 120              | 30               | 60                                         | 130                                  | 390
 | 180 * 180              | 5                 | 10                                         | 50                                    | 150
 | 180 * 180              | 10               | 17                                         | 70                                    | 210
 | 180 * 180              | 15               | 26                                         | 100                                  | 300
 | 180 * 180              | 20               | 34                                         | 130                                  | 390
 | 180 * 180              | 30               | 51                                         | 180                                  | 540
 | 240 * 180              | 5                 | 15                                         | 60                                    | 180
 | 240 * 180              | 10               | 30                                         | 90                                    | 270
 | 240 * 180              | 15               | 45                                         | 130                                  | 390
 | 240 * 180              | 20               | 60                                         | 165                                  | 495
 | 240 * 180              | 30               | 90                                         | 230                                  | 690
 | 320 * 180              | 5                 | 15                                         | 65                                    | 195
 | 320 * 180              | 10               | 30                                         | 110                                  | 330
 | 320 * 180              | 15               | 45                                         | 170                                  | 510
 | 320 * 180              | 20               | 60                                         | 220                                  | 660
 | 320 * 180              | 30               | 90                                         | 300                                  | 900
 | 240 * 240              | 5                 | 15                                         | 70                                    | 140
 | 240 * 240              | 10               | 30                                         | 100                                  | 200
 | 240 * 240              | 15               | 45                                         | 150                                  | 300
 | 240 * 240              | 20               | 60                                         | 200                                  | 400
 | 240 * 240              | 30               | 90                                         | 256                                  | 512
 | 320 * 240              | 5                 | 20                                         | 100                                  | 200
 | 320 * 240              | 10               | 40                                         | 170                                  | 340
 | 320 * 240              | 15               | 60                                         | 256                                  | 512
 | 320 * 240              | 20               | 80                                         | 320                                  | 640
 | 320 * 240              | 30               | 120                                       | 400                                  | 800
 | 424 * 240              | 5                 | 26                                         | 100                                  | 200
 | 424 * 240              | 10               | 53                                         | 170                                  | 340
 | 424 * 240              | 15               | 79                                         | 260                                  | 520
 | 424 * 240              | 20               | 105                                       | 340                                  | 680
 | 424 * 240              | 30               | 158                                       | 430                                  | 860
 | 360 * 360              | 5                 | 30                                         | 120                                  | 240
 | 360 * 360              | 10               | 60                                         | 180                                  | 360
 | 360 * 360              | 15               | 90                                         | 260                                  | 520
 | 360 * 360              | 20               | 120                                       | 330                                  | 660
 | 360 * 360              | 30               | 180                                       | 400                                  | 800
 | 480 * 360              | 5                 | 40                                         | 150                                  | 300
 | 480 * 360              | 10               | 80                                         | 240                                  | 480
 | 480 * 360              | 15               | 120                                       | 350                                  | 700
 | 480 * 360              | 20               | 160                                       | 430                                  | 860
 | 480 * 360              | 30               | 240                                       | 512                                  | 1024
 | 640 * 360              | 5                 | 83                                         | 200                                  | 400
 | 640 * 360              | 10               | 165                                       | 340                                  | 680
 | 640 * 360              | 15               | 248                                       | 512                                  | 1024
 | 640 * 360              | 20               | 330                                       | 600                                  | 1200
 | 640 * 360              | 30               | 495                                       | 700                                  | 1400
 | 480 * 480              | 5                 | 83                                         | 170                                  | 340
 | 480 * 480              | 10               | 165                                       | 260                                  | 520
 | 480 * 480              | 15               | 248                                       | 400                                  | 800
 | 480 * 480              | 20               | 330                                       | 470                                  | 940
 | 480 * 480              | 30               | 495                                       | 600                                  | 1200
 | 640 * 480              | 5                 | 110                                       | 200                                  | 400
 | 640 * 480              | 10               | 220                                       | 350                                  | 700
 | 640 * 480              | 15               | 330                                       | 512                                  | 1024
 | 640 * 480              | 20               | 440                                       | 600                                  | 1200
 | 640 * 480              | 30               | 660                                       | 700                                  | 1400
 | 840 * 480              | 5                 | 180                                       | 256                                  | 512
 | 840 * 480              | 10               | 360                                       | 512                                  | 1024
 | 840 * 480              | 15               | 540                                       | 610                                  | 1220
 | 840 * 480              | 20               | 720                                       | 800                                  | 1600
 | 840 * 480              | 30               | 1080                                     | 930                                  | 1860
 | 960 * 720              | 5                 | 250                                       | 250                                  | 600
 | 960 * 720              | 10               | 500                                       | 500                                  | 750
 | 960 * 720              | 15               | 750                                       | 750                                  | 1125
 | 960 * 720              | 20               | 1000                                     | 1000                                | 1500
 | 960 * 720              | 30               | 1500                                     | 1500                                | 2250
 | 1280 * 720            | 5                 | 400                                       | 400                                  | 600
 | 1280 * 720            | 10               | 800                                       | 800                                  | 1200
 | 1280 * 720            | 15               | 1200                                     | 1200                                | 1800
 | 1280 * 720            | 20               | 1600                                     | 1600                                | 2400
 | 1280 * 720            | 30               | 2400                                     | 2400                                | 3600
 | 1920 * 1080          | 5                 | 500                                       | 500                                  | 750
 | 1920 * 1080          | 10               | 1000                                     | 1000                                | 1500
 | 1920 * 1080          | 15               | 1500                                     | 1500                                | 2250
 | 1920 * 1080          | 20               | 2000                                     | 2000                                | 3000
 | 1920 * 1080          | 30               | 3000                                     | 3000                                | 4500
 | 2560 * 1440          | 5                 | 800                                       | 800                                  | 1200
 | 2560 * 1440          | 10               | 1600                                     | 1600                                | 2400
 | 2560 * 1440          | 15               | 2400                                     | 2400                                | 3600
 | 2560 * 1440          | 20               | 3200                                     | 3200                                | 4800
 | 2560 * 1440          | 30               | 4800                                     | 4800                                | 7200
 | 3840 * 2160          | 5                 | 1000                                     | 1000                                | 1500
 | 3840 * 2160          | 10               | 2000                                     | 2000                                | 3000
 | 3840 * 2160          | 15               | 3000                                     | 3000                                | 4500
 | 3840 * 2160          | 20               | 4000                                     | 4000                                | 6000
 | 3840 * 2160          | 30               | 6000                                     | 6000                                | 9000
*/
@property (nonatomic, assign) NSInteger bitrate;
/** 最小视频编码码率(Kbps)
 * 默认值 0
 * 设置为0，表示由SDK内部根据视频分辨率和码率计算合适的编码码率
 */
@property (nonatomic, assign) NSInteger min_bitrate;

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

/**
 * @brief 播放的音频流类型
 * @note AliLiveAudioStreamTypeNo枚举无意义，不要设置该值
 * default: AliLiveAudioStreamTypeMic 麦克风流
 */

/****
 * @brief audio stream type
 * default: AliLiveAudioStreamTypeMic microphone stream
 */
@property (nonatomic, assign) AliLiveAudioStreamType audioStreamType;

/**
 * @brief 远端用户退出房间后是否自动停止播放
 * default：true
 * @note 远端用户退出房间后，当前SDK是自动调用了停止播放(stopPlay)；如果不想要自动停止播放，可以将该开关设置成false，SDK将不在自动停止播放
 */

/****
 * @brief Whether the remote user will automatically stop playing after leaving the room
 * default：true
 * @note After the remote user leave the room, the current SDK automatically calls stopPlay; if you do not want to automatically stop playback, you can set the switch to false, and the SDK will no longer automatically stop playback.
 */
@property (nonatomic, assign) BOOL autoStoppedPlayWhenUserLeaved;
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

/**
 * 子画面的背景图URL
 *  当用户关闭摄像头或未进入房间时，会在布局位置填充为此图片。
 */

/****
 * background image url
 */
@property (nonatomic, copy) NSString *backgroundImageUrl;

@end

/**
 * 云端混流（转码）配置
 */

/****
 * Mixed-stream transcoding configuration
 */
@interface AlivcLiveTranscodingConfig : NSObject

/**
 * 指定云端混流转码的目标分辨率（宽度）
 * 取值范围：[0, 1920]，默认：0
 * 如果不设置videoWidth的值，SDK内部会使用当前推流分辨率的视频宽
 */

/****
 * Specify the target resolution (width) of cloud mixed-stream transcoding
 * Value range: [0, 1920]，default：0
 * If the value of videoWidth is not set, the SDK will internally use the video width of the current push resolution.
 */
@property (nonatomic, assign) int videoWidth;

/**
 * 指定云端转码的目标分辨率（高度）
 * 取值范围：[0, 1920]，默认：0
 * 如果不设置videoHeigth的值，SDK内部会使用当前推流分辨率的视频高
 */

/****
 * Specifies the target resolution (height) for cloud transcoding
 * Value range: [0, 1920]，default：0
 * If the value of videoHeigth is not set, the SDK will internally use the video height of the current push resolution.
 */
@property (nonatomic, assign) int videoHeigth;

/**
 * 指定云端转码的目标视频码率（kbps）
 * 取值范围：[1, 10000]，默认：0
 * 如果不设置videoBitrate的值，SDK内部会使用当前推流的AlivcLivePushConfig->targetVideoBitrate值
 */

/****
 * Specify the target video bitrate (kbps) for cloud transcoding（kbps）
 * Value range：[1, 10000]，default：0
 * If the videoBitrate value is not set, the SDK will internally use the AlivcLivePushConfig->targetVideoBitrate value of the current push stream.
 */
@property (nonatomic, assign) int videoBitrate;

/**
 * 指定云端转码的目标视频帧率（FPS）
 * 取值范围：[1, 60]，默认：0
 * 如果不设置videoFramerate的值，SDK内部会使用当前推流的AlivcLivePushConfig->fps值
 */

/****
 * Specify Specify the target video frame rate (FPS) for cloud transcoding
 * Value range：[1, 60]，default：0
 * If the value of videoFramerate is not set, the SDK will internally use the AlivcLivePushConfig->fps value of the current push stream.
 */
@property(nonatomic, assign) int videoFramerate;

/**
 * 指定云端转码的目标视频关键帧间隔（GOP）
 * 取值范围：[1, 60]，默认：0
 * 如果不设置videoGOP的值，SDK内部会使用当前推流的AlivcLivePushConfig->videoEncodeGop*videoFramerate来设置该值
 * 如果想要目标视频关键帧间隔为2s，videoFramerate为20，那么videoGOP需要传入的值是2*20=40
 */

/****
 * Specify Specify the target video frame rate (FPS) for cloud transcoding
 * Value range：[1, 60]，default：0
 * If the value of videoFramerate is not set, the SDK will internally use the AlivcLivePushConfig->fps value of the current push stream.
 * If you want the target video key frame interval to be 2s and the videoFramerate to be 20, then the value that videoGOP needs to pass in is 2*20=40
 */
@property(nonatomic, assign) int videoGOP;

/**
 * 指定云端转码的目标音频采样率
 * 音频采样率，默认值：48000，支持设置：8000、16000、32000、44100、48000，单位：Hz
 */

/****
 * Specify the target audio sample rate for cloud transcoding
 * Audio sample rate, default value: 48000, supported settings: 8000, 16000, 32000, 44100, 48000, unit: Hz
 */
@property(nonatomic, assign) int audioSampleRate;

/**
 * 指定云端转码的音频声道数
 * 默认值：1，代表单声道。可设定的数值只有两个数字：1-单声道，2-双声道。
 * 如果设置了 双声道，建议audioBitrate设置128，否则可能会有音质损伤
 */

/****
 * Specify the number of audio channels for cloud transcoding
 * Default: 1, for mono. There are only two numbers that can be set: 1-mono, 2-stereo.
 * If two channels are set up, it is recommended that the audioBitrate is set to 128, otherwise the sound quality may be damaged
 */
@property(nonatomic, assign) int audioChannels;

/**
 * 指定云端转码的目标音频码率（kbps）
 * 取值范围：[8, 500]，默认：64，单位：kbps。
 * 如果设置了 双声道，建议audioBitrate设置128，否则可能会有音质损伤
 */

/****
 * Specify the target audio bitrate (kbps) for cloud transcoding
 * Value range: [8, 500], default: 64, unit: kbps.
 * If two channels are set up, it is recommended that the audioBitrate is set to 128, otherwise the sound quality may be damaged
 */
@property(nonatomic, assign) int audioBitrate;
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

@property (nonatomic, assign) uint8_t* _Nullable dataPtr;
@property (nonatomic, assign) uint8_t* _Nullable dataYPtr;
@property (nonatomic, assign) uint8_t* _Nullable dataUPtr;
@property (nonatomic, assign) uint8_t* _Nullable dataVPtr;
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

/**
 * @brief 音频音效播放配置
 */
@interface AliLiveAudioEffectConfig : NSObject
/** 是否推流，默认值：NO */
@property (nonatomic, assign) BOOL needPublish;
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
