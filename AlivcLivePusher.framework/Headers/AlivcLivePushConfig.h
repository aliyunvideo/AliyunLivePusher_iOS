//
//  AlivcLivePushConfig.h
//  AlivcLiveCaptureLib
//
//  Created by TripleL on 2017/9/26.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AlivcLivePushConstants.h"

#define ALIVCLIVEPUSH_DEPRECAETD_WATERMARK_API __deprecated_msg("Use AlivcLivePusher->addWatermarkWithPath:watermarkCoordX:watermarkCoordY:watermarkWidth instead.")

/**
 * @defgroup AlivcLivePushConfig 直播推流引擎参数配置
 * @ingroup live
 *  直播推流引擎参数配置接口
 *  @{
 */

/****
 * @defgroup AlivcLivePushConfig Live  pusher engine configuration settings
 * @ingroup live
 *  Methods to configure live  pusher engine parameters
 *  @{
 */


/**
 * @brief 直播推流参数配置类
 */

/****
 * @brief Class for live  pusher engine configuration parameter settings
 */
@interface AlivcLivePushConfig : NSObject

/**
 * @brief 直播SDK推流模式
 * @details SDK 的工作模式，SDK提供基础模式和互动模式
 * 基础模式不支持连麦、PK等实时互动需求，常规的RTMP推流、RTS推流使用次模式即可
 * 互动模式，支持连麦、PK等实时互动，如果一场直播有互动需求，建议使用该模式
 * default:AlivcLivePushBasicMode
 */

/****
 * @brief The mode of the live  pusher engine
 * @details The mode in which the SDK works. Basic mode and interactive mode are supported.
 * The basic mode does not support real-time interaction features such as co-streaming and battle. Use this mode for ordinary RTMP- and RTS-based stream ingest.
 * The interactive mode supports real-time interaction features such as co-streaming and battle. If interaction is required during live streaming,
 * we recommend that you use this mode.
 * default:AlivcLivePushBasicMode
 */
@property (nonatomic, assign) AlivcLivePushMode livePushMode;

/**
 * @brief 推流分辨率设置分辨率
 * default : AlivcLivePushDefinition540P
 */

/****
 * @brief The resolution for the ingested stream.
 * default : AlivcLivePushDefinition540P
 */
@property (nonatomic, assign) AlivcLivePushResolution resolution;


/**
 * @brief 直播推流SDK工作模式
 * @details 选择 ResolutionFirst 模式时，SDK内部会优先保障推流视频的清晰度; 选择 FluencyFirst 模式时，SDK内部会优先保障推流视频的流畅度; 以上两种模式下，所有码率与帧率的设置均不生效，SDK会根据您设置的分辨率做出默认设置。 选择 Custom 模式时，SDK会根据您自定义设置的帧率与码率进行推流。
 * default:AlivcLivePushQualityModeResolutionFirst
 */

/****
 * @brief Set the live pusher engine quality mode.
 * @details If you select the ResolutionFirst mode, the SDK prioritizes the quality of streams. If you select the FluencyFirst mode,
 * the SDK prioritizes the smoothness of streams. In the two modes, the SDK specifies the bitrate and frame rate by default.
 * If you select the Custom mode, the SDK ingests streams at the bitrate and frame rate that you specify.
 * default:AlivcLivePushQualityModeResolutionFirst
 */
@property (nonatomic, assign) AlivcLivePushQualityMode qualityMode;


/**
 * @brief 是否打开码率自适应
 * default : true
 */

/****
 * @brief Whether to enable adaptive bitrate streaming
 * default : true
 */
@property (nonatomic, assign) bool enableAutoBitrate;


/**
 * @brief 是否打开分辨率自适应 (动态分辨率)
 * default : false
 * @note qualityMode在custom模式下，分辨率自适应无效
 */

/****
 * @brief Whether to enable adaptive resolution (dynamic resolution)
 * default : false
 * @note This feature does not take effect if qualityMode is set to Custom.
 */
@property (nonatomic, assign) bool enableAutoResolution;

/**
 * @brief 是否在抓屏推流场景下打开窄带高清(更低的带宽，更高的清晰度)开关
 * default : true
 */

/****
 * @brief Whether to enable Narrowband HD™ that provides higher resolution with less bandwidth in scenarios where you stream screen recordings.
 * default : true
 */
@property (nonatomic, assign) bool enableNarrowbandAndHDForScreenPusher;


/**
 * @brief 视频采集帧率
 * defalut : AlivcLivePushFPS20
 * @note : Frames per Second
 */

/****
 * @brief The frame rate for video capture
 * defalut : AlivcLivePushFPS20
 * @note : Frames per Second
 */
@property (nonatomic, assign) AlivcLivePushFPS fps;


/**
 * @brief 最小视频采集帧率
 * default : AlivcLivePushFPS8
 * @note 不可大于 视频采集帧率fps
 */

/****
 * @brief The minimum frame rate for video capture
 * default : AlivcLivePushFPS8
 * @note The value cannot be greater than the frame rate for video collection
 */
@property (nonatomic, assign) AlivcLivePushFPS minFps;


/**
 * @brief 目标视频编码码率
 * default : 800
 * @note 范围 : [100,5000], 单位 : Kbps
 */

/****
 * @brief The video target bitrate
 * default : 800
 * @note Range: [100,5000], Unit : Kbps
 */
@property (nonatomic, assign) int targetVideoBitrate;


/**
 * @brief 最小视频编码码率
 * default : 200
 * @note 范围 : [100,5000], 单位 : Kbps
 */

/****
 * @brief The minimum video bitrate
 * default : 200
 * @note Range : [100,5000], Unit : Kbps
 */
@property (nonatomic, assign) int minVideoBitrate;


/**
 * @brief 初始视频编码码率
 * default : 800
 * @note 范围 : [100,5000], 单位 : Kbps
 */

/****
 * @brief The initial video bitrate
 * default : 800
 * @note Range : [100,5000], Unit : Kbps
 */
@property (nonatomic, assign) int initialVideoBitrate;


/**
 * @brief 音频编码码率
 * default : 64
 * @note 范围 : [10,1000], 单位 : Kbps
 * @note 互动模式下如果设置了AlivcLivePushAudioChannel_2 双声道，建议audioBitrate设置128
 */

/****
 * @brief  The audio bitrate.
 * default : 64
 * @note Range : [10,1000], Unit : Kbps
 * @note  When livePushMode is set to AlivcLivePushInteractiveMode, If AlivcLivePushAudioChannel_2 dual channel is set, it is recommended that the audioBitrate is set to 128
 */
@property (nonatomic, assign) int audioBitrate;


/**
 * @brief 音频采样率
 * default : AlivcLivePushAudioSampleRate48000
 */

/****
 * @brief The audio sample rate.
 * default : AlivcLivePushAudioSampleRate48000
 */
@property (nonatomic, assign) AlivcLivePushAudioSampleRate audioSampleRate;


/**
 * @brief 声道数
 * default : AlivcLivePushAudioChannel_1 单声道
 * @note 互动模式下如果设置了AlivcLivePushAudioChannel_2 双声道，建议audioBitrate设置128
 */

/****
 * @brief The number of sound channels.
 * default : AlivcLivePushAudioChannel_1 Mono
 * @note  When livePushMode is set to AlivcLivePushInteractiveMode, If AlivcLivePushAudioChannel_2 dual channel is set, it is recommended that the audioBitrate is set to 128
 */
@property (nonatomic, assign) AlivcLivePushAudioChannel audioChannel;

/**
 * @brief 音频应用场景
 * default：AlivcLivePusherAudioScenarioMusicMode 默认自适应音乐模式
 */

/****
 * @brief The audio scenario
 * default：AlivcLivePusherAudioScenarioMusicMode
 */
@property (nonatomic, assign) AlivcLivePusherAudioScenario audioScene;

/**
 * @brief 关键帧间隔
 * default : AlivcLivePushVideoEncodeGOP_2
 * @note 单位 : s
 */

/****
 * @brief The keyframe interval
 * default : AlivcLivePushVideoEncodeGOP_2
 * @note Unit : s
 */
@property (nonatomic, assign) AlivcLivePushVideoEncodeGOP videoEncodeGop;


/**
 * @brief 重连次数
 * default : 5
 * @note 范围 : [0,100]
 */

/****
 * @brief The number of reconnections.
 * default : 5
 * @note Range : [0,100]
 */
@property (nonatomic, assign) int connectRetryCount;


/**
 * @brief 重连时长
 * default : 1000
 * @note 范围 : (0,10000], 单位 : ms
 */

/****
 * @brief The duration for reconnection.
 * default : 1000
 * @note Range : (0,10000], Unit : ms
 */
@property (nonatomic, assign) float connectRetryInterval;


/**
 * @brief 网络发送数据超时
 * default : 3000
 * @note 单位 : ms
 */

/****
 * @brief The timeout for data transmission.
 * default : 3000
 * @note Unit : ms
 */
@property (nonatomic, assign) int sendDataTimeout;


/**
 * @brief 推流方向 : 竖屏、90度横屏、270度横屏
 * default : AlivcLivePushOrientationPortrait
 */

/****
 * @brief The direction for stream push: portrait, 90° landscape, and 270° landscape.
 * default : AlivcLivePushOrientationPortrait
 */
@property (nonatomic, assign) AlivcLivePushOrientation orientation;


/**
 * @brief 摄像头类型
 * default : AlivcLivePushCameraTypeFront
 */

/****
 * @brief The camera type.
 * default : AlivcLivePushCameraTypeFront
 */
@property (nonatomic, assign)AlivcLivePushCameraType cameraType;


/**
 * @brief 推流镜像
 * default : false 关闭镜像
 */

/****
 * @brief Whether to enable mirroring for stream push.
 * default : false Mirroring disabled.
 */
@property (nonatomic, assign) bool pushMirror;


/**
 * @brief 预览镜像
 * default : true 前置摄像头默认预览镜像，后置摄像头预览不镜像
 */

/****
 * @brief Whether to enable mirroring for preview.
 * default : true Mirroring enabled.
 */
@property (nonatomic, assign) bool previewMirror;


/**
 * @brief 纯音频推流
 * default : false
 */

/****
 * @brief Whether to enable audio-only stream push.
 * default : false
 */
@property (nonatomic, assign) bool audioOnly;


/**
 * @brief 纯视频推流，只有RTMP推流才支持纯视频推流，当前RTC不支持纯视频推流
 * default : false
 * @note : 与 audioOnly互斥, 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置videoOnly，AlivcLivePushInteractiveMode模式下暂时不支持纯视频推流
 */

/****
 * @brief Video-only stream push is supported for RTMP, but not for RTC.
 * default : false
 * @note : This parameter is mutually exclusive with audioOnly. The SDK allows you to enable video-only stream ingest when
 *  livePushMode is set to AlivcLivePushBasicMode, but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
@property (nonatomic, assign) bool videoOnly;

/**
 * @brief 自动聚焦
 * default : true
 */

/****
 * @brief Whether to enable autofocus
 * default : true
 */
@property (nonatomic, assign) bool autoFocus;

/**
 * @brief 微距对焦，适用多个摄像头的高端机型，近距离拍摄对焦
 * default : false
 */

/****
 * @brief Macro focus, suitable for high-end models with multiple cameras, close-range shooting focus
 * default : false
 */
@property (nonatomic, assign) bool macroFocus;

/**
 * @brief 设置背景音乐使用阿里云播放器来播放，默认使用内置播放
 * 内置播放支持大部分场景，若有需要特别的格式，可以切换至阿里云播放器，需要app添加阿里云播放器5.4.1及以上版本的依赖
 * default：false
 */

/****
 * @brief Use ApsaraVideo Player to play background music. By default, the built-in player is used to play background music
 * The built-in player supports most scenarios. If special formats are required, you can switch to ApsaraVideo Player.
 * You need to add the dependency of ApsaraVideo Player 5.4.1 or later to the app.
 * default：false
 */
@property (nonatomic, assign) bool useAliyunPlayerForBGM;


/**
 * @brief 暂停推流图片
 */

/****
 * @brief The image used when live pusher engine is paused.
 */
@property(nonatomic, retain) UIImage *pauseImg;


/**
 * @brief 码率低图片
 */

/****
 * @brief The image used when the network is low.
 */
@property(nonatomic, retain) UIImage *networkPoorImg;


/**
 * @brief 是否开启闪光灯
 * default : false
 */

/****
 * @brief Whether to turn on the flash
 * default : false
 */
@property (nonatomic, assign) bool flash;


/**
 * @brief 视频编码模式
 * default : AlivcLivePushVideoEncoderModeHard
 */

/****
 * @brief The video encoding mode
 * default : AlivcLivePushVideoEncoderModeHard
 */
@property (nonatomic, assign) AlivcLivePushVideoEncoderMode videoEncoderMode;

/**
 * @brief 视频硬编码方式
 * @details（当videoEncoderMode设置为AlivcLivePushVideoEncoderModeHard时，有两种可选的视频硬件编码方式：H264和HEVC(H265)）
 * default：AlivcLivePushVideoEncoderModeHardCodecH264，使用H264进行硬件编码
 */

/****
 * @brief The video hardware encoding format.
 * @details When videoEncoderMode is set to AlivcLivePushVideoEncoderModeHard, there are two optional video hardware encoding formats: H.264 and HEVC (H.265).
 * default：AlivcLivePushVideoEncoderModeHardCodecH264
 */
@property (nonatomic, assign)AlivcLivePushVideoEncoderModeHardCodec videoHardEncoderCodec;

/**
 * @brief 允许视频编码自动降级
 * @details 当设置HEVC硬件编码但当前设备不支持时，SDK会自动降级成H264，此开关可以控制SDK不自动降级成H264
 * default：true，允许自动降级
 */

/****
 * @brief Allow video encoding to automatically downgrade
 * @details When HEVC hardware encoding is set but the current device does not support it, the SDK will automatically downgrade to H264. This switch can control the SDK not to automatically downgrade to H264.
 * default：true, Allow video codec  automatic downgrade
 */
@property (nonatomic, assign) bool enableVideoCodecDowngrade;

/**
 * @brief 视频硬编模式下是否开启B帧
 * default：NO
 */

/****
 * @brief Whether to support B-frames for video hardware encoding
 * default：NO
 */
@property (nonatomic, assign) bool openBFrame;

/**
 * @brief 音频编码格式
 * default : AlivcLivePushAudioEncoderProfile_AAC_LC
 */

/****
 * @brief The audio encoding format
 * default : AlivcLivePushAudioEncoderProfile_AAC_LC
 */
@property (nonatomic, assign) AlivcLivePushAudioEncoderProfile audioEncoderProfile;

/**
 * @brief 设置SDK对AVAudioSession的控制权限
 * default : AlivcLivePusherAudioSessionOperationRestrictionNone
 */

/****
 * @brief The control permission of the SDK on AVAudioSession
 * default : AlivcLivePusherAudioSessionOperationRestrictionNone
 */
@property (nonatomic, assign) AlivcLivePusherAudioSessionOperationRestriction audioSessionOperationRestriction;


/**
 * @brief 音频编码模式
 * default : AlivcLivePushAudioEncoderModeSoft
 */

/****
 * @brief The audio encoding mode
 * default : AlivcLivePushAudioEncoderModeSoft
 */
@property (nonatomic, assign) AlivcLivePushAudioEncoderMode audioEncoderMode;

/**
 * @brief 音频编码器类型
 * default : AlivcLivePushAudioEncoderCodecOpus
 * @note 该配置参数只在互动模式(直播连麦或PK)下生效，基础模式只支持音频AAC编码；互动模式默认是Opus编码，可以通过设置audioEncoderCodec切换成AAC编码
 */

/****
 * @brief The audio encoder codec
 * default : AlivcLivePushAudioEncoderCodecOpus
 * @note This configuration parameter only takes effect in the interactive mode (live broadcast or PK). The basic mode only supports AAC audio encoding; the interactive mode defaults to Opus encoding, and can be switched to AAC encoding by setting audioEncoderCodec.
 */
@property (nonatomic, assign) AlivcLivePushAudioEncoderCodec audioEncoderCodec;


/**
 * @brief 是否外部自定义数据推流
 * default  : false
 */

/****
 * @brief Whether to allow live pusher engine for external custom data.
 * default  : false
 */
@property (nonatomic, assign) bool externMainStream;

/**
 * @brief 外部自定义视频数据
 * default : unknown
 */

/****
 * @brief The external custom video data
 * default : unknown
 */
@property (nonatomic, assign) AlivcLivePushVideoFormat externVideoFormat;

/**
 * @brief 外部自定义音频数据
 * default : unknown
 */

/****
 * @brief The external custom audio data
 * default : unknown
 */
@property (nonatomic, assign) AlivcLivePushAudioFormat externAudioFormat;

/**
 * @brief 外部自定义数据是否包含音频
 * default: YES
 * @note 在ios录屏推流中，可以将audioFromExtern设置成NO，这样音频由sdk负责，视频由插件负责
 * 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置audioFromExternal，AlivcLivePushInteractiveMode模式下暂时不支持外部音视频推流
 */

/****
 * @brief Whether the external custom data contains audio
 * default: YES
 * @note In screen recording streaming scenarios on iOS, you can set audioFromExtern to NO, so that the audio is
 * processed by the SDK and the video is processed by components. The SDK allows you to set audioFromExternal when livePushMode is
 * set to AlivcLivePushBasicMode, but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
@property (nonatomic, assign) BOOL audioFromExternal;

/**
 * @brief 外部自定义数据时，针对不包含在AlivcLivePushResolution枚举中提供的通用长宽比，为了避免图像被裁剪，可以指定输入视频的长宽比为输出视频的长宽比
 * @note 该字段可以用在ios屏幕推流中，只有enableExternBufferSize设置为YES后，才将sampleBufferSize作为目标分辨率
 * 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置sampleBufferSize，AlivcLivePushInteractiveMode模式下暂时不支持外部音视频推流
 */

/****
 * @brief When you set external custom data, if the aspect ratio of the video is not one of the values of AlivcLivePushResolution,
 * you can specify the aspect ratio of the input video as that of the output video to avoid cropping.
 * @note This field is applicable in screen recording streaming scenarios on iOS. sampleBufferSize is used as the target resolution
 * only when enableExternBufferSize is set to YES.
 * The SDK allows you to set sampleBufferSize when livePushMode is set to AlivcLivePushBasicMode, but not when livePushMode
 * is set to AlivcLivePushInteractiveMode.
 */
@property(nonatomic, assign) CGSize sampleBufferSize;

/**
 * @brief 外部自定义数据时，针对不包含在AlivcLivePushResolution枚举中提供通用的长宽比，
 * 为了避免图像被裁剪，开启enableExternSampleBufferSize开关，SDK将使用sampleBufferSize 输入的分辨率为目标分辨率
 * @note 仅用于外部自定义数据推流，并且输入的视频不是通用长宽比，避免图像被裁剪，例如在ios录屏推流中可使用
 * default：NO
 * @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置sampleBufferSize，AlivcLivePushInteractiveMode模式下暂时不支持外部音视频推流
 */

/****
 * @brief When you set external custom data, if the aspect ratio of the video is not one of the values of AlivcLivePushResolution, you can configure
 * enableExternSampleBufferSize so that the SDK uses the resolution specified by sampleBufferSize as the output resolution.
 * @note This parameter is applicable to only stream ingest for external custom data. We recommend that you use it
 * when the aspect ratio of input video is not an ordinary aspect ratio, for example, in screen recording streaming scenarios on iOS.
 * default：NO
 * @note The SDK allows you to set sampleBufferSize when livePushMode is set to AlivcLivePushBasicMode,
 *  but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
@property(nonatomic, assign) BOOL enableExternSampleBufferSize;

/**
 * @brief 预览显示模式
 * default : ALIVC_LIVE_PUSHER_PREVIEW_ASPECT_FILL
 */

/****
 * @brief The preview mode
 * default : ALIVC_LIVE_PUSHER_PREVIEW_ASPECT_FILL
 */
@property (nonatomic, assign) AlivcPusherPreviewDisplayMode previewDisplayMode;

/**
 * @brief开启 openGL Shared Context 模式
 * default : false
 */

/****
 * @brief Whether to enable the openGL Shared Context mode
 * default : false
 */
@property (nonatomic, assign) BOOL requireGLSharedContext;


/**
 * @brief 业务信息
 */

/****
 * @brief The business information.
 */

@property (nonatomic, copy) NSDictionary *businessInfo;

/**
 * @brief SDK质量监控等级，针对嵌入式场景，可以指定精简的监控信息
 */

/****
 * @brief The SDK quality monitoring level. For embedment scenarios, you can specify specific monitoring metrics.
 */
@property (nonatomic, assign) AlivcLivePushMonitorLevel monitorLevel;


/**
 * @brief 互动模式下开启RTS推拉裸流(直推&直拉，不同于直播连麦)
 */
@property (nonatomic, assign) BOOL enableRTSForInteractiveMode;
/**
 * @brief 互动模式下默认回调pixbuffer，通过enableLocalVideoTexture可以指定纹理回调
 */

/****
 * @brief when livePushMode is set to AlivcLivePushLiveMode, pixbuffer is called back by default, and texture callback can be specified by enableLocalVideoTexture
 */

@property (nonatomic, assign) BOOL enableLocalVideoTexture;

/**
 * @brief 互动模式下enableLocalVideoTexture指定纹理回调后，可以设置enableLocalVideoRawBuffer打开视频裸数据的回调，格式是I420
 */

/****
 * @brief After enableLocalVideoTexture specifies the texture callback in interactive mode, enableLocalVideoRawBuffer can be set to enable the callback of video raw data, the format is I420
 */
@property (nonatomic, assign) BOOL enableLocalVideoRawBuffer;

/**
 * @brief 设置H5兼容模式
 * @details 互动模式下，是否需要与Web 连麦互通，则必须使用H5兼容模式,否则，Web用户查看Native用户将是黑屏。
 * @param h5CompatibleMode
 * - YES: 兼容H5。
 * - NO: 传统模式，不兼容H5。
 * default : false
 * @note 不支持在创建AlivcLivePusher实例之后更改H5兼容模式，必须在创建实例之前就调用此方法。
 */

/****
 * @brief Set H5 compatibility mode
 * @note In the interactive mode, if you need to communicate with the Web, you must use the H5 compatibility mode, otherwise, the Web user will see a black screen when viewing the Native user.
 * @param enable  YES: open; NO:close
 * default : false
 * @return
 * - YES: success
 * - NO: failure
*/
@property (nonatomic, assign) BOOL h5CompatibleMode;

/**
 * @brief 打开数据通道收到自定义消息
 * default : false
 */

/****
 * @brief Open the data channel and receive a custom message
 * default : false
*/
@property (nonatomic, assign) BOOL enableDataChannelMessage;

/**
 * @brief 用户名
 */

/****
 * @brief userName
 */
@property (nonatomic, copy) NSString *userName;

/**
 * @brief 远端视频裸数据回调开关(互动模式下有效)
 * default : false
 * @note 如果此开关打开，则可在AliLivePlayerDelegate->onRemoteVideoSample中回调远端视频裸数据
 */

/****
 * @brief Remote video frame callback switch in interactive mode
 * default : false
 * @note If this switch is turned on, the remote video raw data can be called back in AliLivePlayerDelegate->onRemoteVideoSample.
 */
@property (nonatomic, assign) BOOL enableRemoteVideoFrameObserver;

/**
 * @brief 是否开启高清预览 （高清预览模式下，调整推流分辨率不重启采集）
 * default : true
 */

/****
 * @brief Whether to enable HD preview (In HD preview mode, adjusting the streaming resolution does not restart the collection)
 * default : true
 */
@property (nonatomic, assign) BOOL enableHDPreview;

/**
 * @brief 直播连麦场景透传RTC extra信息字段
 */
@property (nonatomic, copy) NSDictionary *extras;

/**
 * @brief init 分辨率 其余值为默认值
 * @param resolution 推流分辨率
 * @return self
 */

/****
 * @brief init Specify the resolution. Default values are used for other parameters of the instance type.
 * @param resolution The resolution of the live pusher stream
 * @return self
 */
- (instancetype)initWithResolution:(AlivcLivePushResolution)resolution;


/**
 * @brief 添加水印 最多支持3个水印
 * @param addWatermarkWithPath 水印路径
 * @param watermarkCoordX 水印左上顶点x的相对坐标 [0,1]
 * @param watermarkCoordY 水印左上顶点y的相对坐标 [0,1]
 * @param watermarkWidth 水印的相对宽度 (水印会根据水印图片实际大小和水印宽度等比缩放) (0,1]
 * @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置水印相关接口，AlivcLivePushInteractiveMode模式下暂时不支持设置水印
 */

/****
 * @brief Add watermarks. You can add up to three watermarks
 * @param path The path of the watermark
 * @param coordX The coordinate of the watermark along the x-axis relative to the vertex in the upper-left corner
 * @param coordY The coordinate of the watermark along the y-axis relative to the vertex in the upper-left corner
 * @param width The relative width of the watermark. (The watermark is proportionally scaled based on the actual width of the watermark image.) (0,1]
 * @return
 *  0:success
 *  != 0:failure
 * @note Note: The SDK allows you to add watermarks when livePushMode is set to AlivcLivePushBasicMode,
 * but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (void)addWatermarkWithPath:(NSString *)path
             watermarkCoordX:(CGFloat)coordX
             watermarkCoordY:(CGFloat)coordY
              watermarkWidth:(CGFloat)width ALIVCLIVEPUSH_DEPRECAETD_WATERMARK_API;

/**
 * @brief 移除水印
 * @param path 水印路径
 */

/****
 * @brief  Remove watermarks
 * @param path The path of the watermark
 */
- (void)removeWatermarkWithPath:(NSString *)path ALIVCLIVEPUSH_DEPRECAETD_WATERMARK_API;


/**
 * @brief 获取全部水印
 * key:watermarkPath value:水印图片路径
 * key:watermarkCoordX value:x值
 * key:watermarkCoordY value:y值
 * key:watermarkWidth value:width值
 * @return 全部水印配置数组
 */

/****
 * @brief Query all watermarks
 * key:watermarkPath value:The path of the watermark
 * key:watermarkCoordX value:x
 * key:watermarkCoordY value:y
 * key:watermarkWidth value:width
 */
- (NSArray<NSDictionary *> *)getAllWatermarks;


/**
 * @brief 获取推流宽高具体数值
 * @return 推流宽高Rect
 */

/****
 * @brief Query the width and height of the push stream.
 */
- (CGSize)getPushResolution;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      美颜参数设置，在v4.2.0版本已删除，推流SDK不再提供内置美颜功能，请使用阿里云Queen提供的美颜服务
//      详见：https://help.aliyun.com/document_detail/211047.html?spm=a2c4g.11174283.6.736.79c5454ek41M8B
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@end

/** @} */

/**** @} */
