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
 *  直播推流引擎参数配置接口
 *  @{
 */


/**
 * @brief 直播推流参数配置类
 */
@interface AlivcLivePushConfig : NSObject

/**
 * @brief 直播SDK推流模式
 * @details SDK 的工作模式，SDK提供基础模式和互动模式
 * 基础模式不支持连麦、PK等实时互动需求，常规的RTMP推流、RTS推流使用次模式即可
 * 互动模式，支持连麦、PK等实时互动，如果一场直播有互动需求，建议使用该模式
 * default:AlivcLivePushBasicMode
 */
@property (nonatomic, assign) AlivcLivePushMode livePushMode;

/**
 * @brief 推流分辨率设置分辨率
 * default : AlivcLivePushDefinition540P
 */
@property (nonatomic, assign) AlivcLivePushResolution resolution;


/**
 * @brief 直播推流SDK工作模式
 * @details 选择 ResolutionFirst 模式时，SDK内部会优先保障推流视频的清晰度; 选择 FluencyFirst 模式时，SDK内部会优先保障推流视频的流畅度; 以上两种模式下，所有码率与帧率的设置均不生效，SDK会根据您设置的分辨率做出默认设置。 选择 Custom 模式时，SDK会根据您自定义设置的帧率与码率进行推流。
 * default:AlivcLivePushQualityModeResolutionFirst
 */
@property (nonatomic, assign) AlivcLivePushQualityMode qualityMode;


/**
 * @brief 是否打开码率自适应
 * default : true
 */
@property (nonatomic, assign) bool enableAutoBitrate;


/**
 * @brief 是否打开分辨率自适应 (动态分辨率)
 * default : false
 * @note qualityMode在custom模式下，分辨率自适应无效
 */
@property (nonatomic, assign) bool enableAutoResolution;

/**
 * @brief 是否在抓屏推流场景下打开窄带高清(更低的带宽，更高的清晰度)开关
 * default : true
 */
@property (nonatomic, assign) bool enableNarrowbandAndHDForScreenPusher;


/**
 * @brief 视频采集帧率
 * defalut : AlivcLivePushFPS20
 * @note : Frames per Second
 */
@property (nonatomic, assign) AlivcLivePushFPS fps;


/**
 * @brief 最小视频采集帧率
 * default : AlivcLivePushFPS8
 * @note 不可大于 视频采集帧率fps
 */
@property (nonatomic, assign) AlivcLivePushFPS minFps;


/**
 * @brief 目标视频编码码率
 * default : 800
 * @note 范围 : [100,5000], 单位 : Kbps
 */
@property (nonatomic, assign) int targetVideoBitrate;


/**
 * @brief 最小视频编码码率
 * default : 200
 * @note 范围 : [100,5000], 单位 : Kbps
 */
@property (nonatomic, assign) int minVideoBitrate;


/**
 * @brief 初始视频编码码率
 * default : 800
 * @note 范围 : [100,5000], 单位 : Kbps
 */
@property (nonatomic, assign) int initialVideoBitrate;


/**
 * @brief 音频编码码率
 * default : 64
 * @note 范围 : [10,1000], 单位 : Kbps
 */
@property (nonatomic, assign) int audioBitrate;


/**
 * @brief 音频采样率
 * default : AlivcLivePushAudioSampleRate48000
 */
@property (nonatomic, assign) AlivcLivePushAudioSampleRate audioSampleRate;


/**
 * @brief 声道数
 * default : AlivcLivePushAudioChannel_1 单声道
 */
@property (nonatomic, assign) AlivcLivePushAudioChannel audioChannel;

/**
 * @brief 音频应用场景
 * default：AlivcLivePusherAudioScenarioDefaultMode 默认模式
 */
@property (nonatomic, assign) AlivcLivePusherAudioScenario audioScene;

/**
 * @brief 关键帧间隔
 * default : AlivcLivePushVideoEncodeGOP_2
 * @note 单位 : s
 */
@property (nonatomic, assign) AlivcLivePushVideoEncodeGOP videoEncodeGop;


/**
 * @brief 重连次数
 * default : 5
 * @note 范围 : [0,100]
 */
@property (nonatomic, assign) int connectRetryCount;


/**
 * @brief 重连时长
 * default : 1000
 * @note 范围 : (0,10000], 单位 : ms
 */
@property (nonatomic, assign) float connectRetryInterval;


/**
 * @brief 网络发送数据超时
 * default : 3000
 * @note 单位 : ms
 */
@property (nonatomic, assign) int sendDataTimeout;


/**
 * @brief 推流方向 : 竖屏、90度横屏、270度横屏
 * default : AlivcLivePushOrientationPortrait
 */
@property (nonatomic, assign) AlivcLivePushOrientation orientation;


/**
 * @brief 摄像头类型
 * default : AlivcLivePushCameraTypeFront
 */
@property (nonatomic, assign)AlivcLivePushCameraType cameraType;


/**
 * @brief 推流镜像
 * default : false 关闭镜像
 */
@property (nonatomic, assign) bool pushMirror;


/**
 * @brief 预览镜像
 * default : false 关闭镜像
 */
@property (nonatomic, assign) bool previewMirror;


/**
 * @brief 纯音频推流
 * default : false
 */
@property (nonatomic, assign) bool audioOnly;


/**
 * @brief 纯视频推流，只有RTMP推流才支持纯视频推流，当前RTC不支持纯视频推流
 * default : false
 * @note : 与 audioOnly互斥, 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置videoOnly，AlivcLivePushInteractiveMode模式下暂时不支持纯视频推流
 */
@property (nonatomic, assign) bool videoOnly;

/**
 * @brief 自动聚焦
 * default : true
 */
@property (nonatomic, assign) bool autoFocus;

/**
 * @brief 设置背景音乐使用阿里云播放器来播放，默认使用内置播放
 * 内置播放支持大部分场景，若有需要特别的格式，可以切换至阿里云播放器，需要app添加阿里云播放器5.4.1及以上版本的依赖
 * default：false
 */
@property (nonatomic, assign) bool useAliyunPlayerForBGM;


/**
 * @brief 暂停推流图片
 */
@property(nonatomic, retain) UIImage *pauseImg;


/**
 * @brief 码率低图片
 */
@property(nonatomic, retain) UIImage *networkPoorImg;


/**
 * @brief 是否开启闪光灯
 * default : false
 */
@property (nonatomic, assign) bool flash;


/**
 * @brief 视频编码模式
 * default : AlivcLivePushVideoEncoderModeHard
 */
@property (nonatomic, assign) AlivcLivePushVideoEncoderMode videoEncoderMode;

/**
 * @brief 视频硬编码方式
 * @details（当videoEncoderMode设置为AlivcLivePushVideoEncoderModeHard时，有两种可选的视频硬件编码方式：H264和HEVC(H265)）
 * default：AlivcLivePushVideoEncoderModeHardCodecH264，使用H264进行硬件编码
 */
@property (nonatomic, assign)AlivcLivePushVideoEncoderModeHardCodec videoHardEncoderCodec;

/**
 * @brief 视频硬编模式下是否开启B帧
 * default：NO
 */
@property (nonatomic, assign) bool openBFrame;

/**
 * @brief 音频编码格式
 * default : AlivcLivePushAudioEncoderProfile_AAC_LC
 */
@property (nonatomic, assign) AlivcLivePushAudioEncoderProfile audioEncoderProfile;

/**
 * @brief 设置SDK对AVAudioSession的控制权限
 * default : AlivcLivePusherAudioSessionOperationRestrictionNone
 */
@property (nonatomic, assign) AlivcLivePusherAudioSessionOperationRestriction audioSessionOperationRestriction;


/**
 * @brief 音频编码模式
 * default : AlivcLivePushAudioEncoderModeSoft
 */
@property (nonatomic, assign) AlivcLivePushAudioEncoderMode audioEncoderMode;


/**
 * @brief 是否外部自定义数据推流
 * default  : false
 * @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置externMainStream，AlivcLivePushInteractiveMode模式下暂时不支持外部音视频推流
 */
@property (nonatomic, assign) bool externMainStream;

/**
 * @brief 外部自定义视频数据
 * default : unknown
 */
@property (nonatomic, assign) AlivcLivePushVideoFormat externVideoFormat;

/**
 * @brief 外部自定义音频数据
 * default : unknown
 */
@property (nonatomic, assign) AlivcLivePushAudioFormat externAudioFormat;

/**
 * @brief 外部自定义数据是否包含音频
 * default: YES
 * @note 在ios录屏推流中，可以将audioFromExtern设置成NO，这样音频由sdk负责，视频由插件负责
 * 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置audioFromExternal，AlivcLivePushInteractiveMode模式下暂时不支持外部音视频推流
 */
@property (nonatomic, assign) BOOL audioFromExternal;

/**
 * @brief 外部自定义数据时，针对不包含在AlivcLivePushResolution枚举中提供的通用长宽比，为了避免图像被裁剪，可以指定输入视频的长宽比为输出视频的长宽比
 * @note 该字段可以用在ios屏幕推流中，只有enableExternBufferSize设置为YES后，才将sampleBufferSize作为目标分辨率
 * 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置sampleBufferSize，AlivcLivePushInteractiveMode模式下暂时不支持外部音视频推流
 */
@property(nonatomic, assign) CGSize sampleBufferSize;

/**
 * @brief 外部自定义数据时，针对不包含在AlivcLivePushResolution枚举中提供通用的长宽比，
 * 为了避免图像被裁剪，开启enableExternSampleBufferSize开关，SDK将使用sampleBufferSize 输入的分辨率为目标分辨率
 * @note 仅用于外部自定义数据推流，并且输入的视频不是通用长宽比，避免图像被裁剪，例如在ios录屏推流中可使用
 * default：NO
 * @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下 设置sampleBufferSize，AlivcLivePushInteractiveMode模式下暂时不支持外部音视频推流
 */
@property(nonatomic, assign) BOOL enableExternSampleBufferSize;

/**
 * @brief 预览显示模式
 * default : ALIVC_LIVE_PUSHER_PREVIEW_ASPECT_FIT
 */
@property (nonatomic, assign) AlivcPusherPreviewDisplayMode previewDisplayMode;

/**
 * @brief开启 openGL Shared Context 模式
 * default : false
 */
@property (nonatomic, assign) BOOL requireGLSharedContext;


/**
 * @brief 业务信息
 */

@property (nonatomic, copy) NSDictionary *businessInfo;

/**
 * @brief SDK质量监控等级，针对嵌入式场景，可以指定精简的监控信息
 */
@property (nonatomic, assign) AlivcLivePushMonitorLevel monitorLevel;

/**
 * @brief init 分辨率 其余值为默认值
 * @param resolution 推流分辨率
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
- (void)addWatermarkWithPath:(NSString *)path
             watermarkCoordX:(CGFloat)coordX
             watermarkCoordY:(CGFloat)coordY
              watermarkWidth:(CGFloat)width ALIVCLIVEPUSH_DEPRECAETD_WATERMARK_API;

/**
 * @brief 移除水印
 * @param path 水印路径
 */
- (void)removeWatermarkWithPath:(NSString *)path ALIVCLIVEPUSH_DEPRECAETD_WATERMARK_API;


/**
 * @brief 获取全部水印
 * key:watermarkPath value:水印图片路径
 * key:watermarkCoordX value:x值
 * key:watermarkCoordY value:y值
 * key:watermarkWidth value:width值
 @return 全部水印配置数组
 */
- (NSArray<NSDictionary *> *)getAllWatermarks;


/**
 * @brief 获取推流宽高具体数值
 * @return 推流宽高Rect
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
