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


NS_ASSUME_NONNULL_END
