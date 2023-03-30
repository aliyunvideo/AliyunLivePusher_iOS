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
@interface AlivcLivePusherAudioDataSample : NSObject

@property (nonatomic, assign) long dataPtr;//强制转换成(uint8_t*)dataPtr即为PCM数据buffer内存首地址
@property (nonatomic, assign) int numOfSamples;//数据总大小为numOfSamples*bytesPerSample
@property (nonatomic, assign) int bytesPerSample;
@property (nonatomic, assign) int numOfChannels;
@property (nonatomic, assign) int samplesPerSec;

@end

/**
 * @brief 直播连麦播放参数配置
 */
@interface AlivcLivePlayConfig : NSObject
/**
 * @brief 渲染模式
 * default：AlivcLivePlayRenderModeAuto
 */
@property (nonatomic) AlivcLivePlayRenderMode renderMode;

/**
 * @brief 播放是否镜像
 * default：false，非镜像
 */
@property (nonatomic, assign) BOOL mirror;

/**
 * @brief 旋转角度 
 * default： AlivcLivePlayRotationMode_0
 */
@property (nonatomic, assign) AlivcLivePlayRotationMode rotationMode;
@end


/**
 * 云端混流（转码）中每一路子画面的位置信息
 */
@interface AlivcLiveMixStream : NSObject

/**
 参与混流的 userId
 备注：和推拉地址中userId字端相同
 */
@property (nonatomic, copy, nonnull) NSString *userId;

/**
 * 图层位置 x 坐标（绝对像素值）
 */
@property (nonatomic, assign) int x;

/**
 * 图层位置 y坐标（绝对像素值）
 */
@property (nonatomic, assign) int y;

/**
 * 图层宽度（绝对像素值）
 */
@property (nonatomic, assign) int width;

/**
 * 图层高度（绝对像素值）
 */
@property (nonatomic, assign) int height;
/**
 *  图层层次（1 - 15）不可重复
*/
@property (nonatomic, assign) int zOrder;

@end

/**
 * 云端混流（转码）配置
 */
@interface AlivcLiveTranscodingConfig : NSObject

/**
 * 混合后画面的底色颜色，默认为黑色，格式为十六进制数字,0xRRGGBB
 * 默认：0x000000
 */
@property (nonatomic, assign) int backgroundColor;

/**
 * 混合后视频画面裁剪模式
 * 默认：AlivcLiveTranscodingCropModeCrop
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
@property (nonatomic, copy) NSString * _Nonnull userId;

/**
 视频宽度
 */
@property(nonatomic, assign) int videoWidth;

/**
 视频高度
 */
@property(nonatomic, assign) int videoHeight;

/**
 视频解码FPS
 * 单位 : Frames per Second
 */
@property (nonatomic, assign) int decodeFps;

/**
 视频渲染FPS
 * 单位 : Frames per Second
 */
@property (nonatomic, assign) int renderFps;

/**
 视频码率（当前视频码率是所有接收的总码率）
 * Kbps
 */
@property (nonatomic, assign) int videoBitrate;


/**
 音频码率
 * Kbps
 */
@property (nonatomic, assign) int audioBitrate;


/**
 音频丢包率
 * %
 */
@property (nonatomic, assign) int audioLossRate;;

/**
 丢包率 (网络丢包率)
 * %
 */
@property (nonatomic, assign) int lossRate;


@end


NS_ASSUME_NONNULL_END
