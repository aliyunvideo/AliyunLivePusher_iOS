//
//  AlivcLivePusher.h
//  AlivcLiveCaptureLib
//
//  Created by TripleL on 17/7/13.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
#import <UIKit/UIKit.h>
#import <ReplayKit/ReplayKit.h>
#import "AlivcLivePushConfig.h"
#import "AlivcLivePushStatsInfo.h"
#import "AlivcLivePushError.h"
#import "AlivcLivePushDef.h"

/// @details 阿里云直播推流SDK从4.4.2版本开始增加license管理，老版本升级到4.4.2及以后版本需要参照阿里云官网获取推流SDK license
///  其SDK接入流程变化：
///  1. 在Info.plist中配置licenseKey和licenseFile
///  2.调用[AlivcLiveBase registerSDK]注册推流SDK
///  3.监听onLicenceCheck回调，确保license校验通过
///  4.创建推流对象，开始直播推流
///  其相关文档参考https://help.aliyun.com/document_detail/431730.html、
///  https://help.aliyun.com/document_detail/94821.html、https://help.aliyun.com/document_detail/94828.html

/// @details From V4.4.2, Alibaba Cloud Push SDK adds the support for license management. If you upgrade Push SDK from a previous version to V4.4.2 or later,
/// you need to obtain a license for the SDK, and there are some minor changes in the procedure of integrating the SDK.
/// 1. Configure licenseKey and licenseFile in the Info.plist file
/// 2. Call [AlivcLiveBase registerSDK] to register Push SDK
/// 3. Listen to the onLicenceCheck callback to ensure that the license verification is passed
/// 4. Create an object to start stream push
/// For more information, see https://help.aliyun.com/document_detail/431730.html、
///  https://help.aliyun.com/document_detail/94821.html、https://help.aliyun.com/document_detail/94828.html

/**
 * @details 错误回调, 网络回调, 状态回调, BGM回调, 滤镜回调
 */

/****
 * @details Error callbacks, network callbacks, status callbacks, BGM callbacks, and filter callbacks
 */

@protocol AlivcLivePusherErrorDelegate,
AlivcLivePusherNetworkDelegate,
AlivcLivePusherInfoDelegate,
AlivcLivePusherBGMDelegate,
AlivcLivePusherCustomFilterDelegate,
AlivcLivePusherCustomDetectorDelegate,
AlivcLivePusherSnapshotDelegate,
AlivcLivePusherAudioSampleDelegate;



/**
 * @defgroup AlivcLivePusher 直播推流引擎
 * @ingroup live
 *  直播推流功能的主要接口类
 *  @{
 */

/****
 * @defgroup AlivcLivePusher Live  pusher engine
 * @ingroup live
 *  Major classes
 *  @{
 */
@interface AlivcLivePusher : NSObject



/**
 * @brief 创建一个推流引擎实例
 * @param config 推流配置信息 {@link AlivcLivePushConfig}
 * @return self:success  nil:failure
 * @note 同一时间只会存在一个主推流引擎实例，引擎销毁对应的接口：{@link AlivcLivePusher::destory }
 */

/****
 * @brief Create a live  pusher engine
 * @param config Configure live pusher {@link AlivcLivePushConfig}
 * @return self:success  nil:failure
 * @note You can create only one primary live pusher engine，The corresponding interface for engine destruction: {@link AlivcLivePusher::destroy}
 */
- (instancetype)initWithConfig:(AlivcLivePushConfig *)config;

/**
 * @brief 设置推流错误监听回调
 * @param delegate {@link AlivcLivePusherErrorDelegate}
 * @note 错误回调和相关处理可参考：https://help.aliyun.com/zh/live/developer-reference/handling-of-exceptions-and-special-scenarios-for-ios
 */

/****
 * @brief Set the callback for live pusher engine errors.
 * @param delegate {@link AlivcLivePusherErrorDelegate}
 * @note error callbacks and related processing can be referred to：https://help.aliyun.com/zh/live/developer-reference/handling-of-exceptions-and-special-scenarios-for-ios
 */
- (void)setErrorDelegate:(id<AlivcLivePusherErrorDelegate>)delegate;


/**
 * @brief 设置推流状态监听回调
 * @param delegate {@link AlivcLivePusherInfoDelegate}
 */

/****
 * @brief Set the callback for live pusher engine status.
 * @param delegate {@link AlivcLivePusherInfoDelegate}
 */
- (void)setInfoDelegate:(id<AlivcLivePusherInfoDelegate>)delegate;

/**
 * @brief 设置推流网络监听回调
 * @param delegate {@link AlivcLivePusherNetworkDelegate}
 * @note 网络监听回调和相关处理可参考：
 * https://help.aliyun.com/zh/live/developer-reference/handling-of-exceptions-and-special-scenarios-for-ios
 */

/****
 * @brief Set the callback for the network status of live pusher engine
 * @param delegate {@link AlivcLivePusherNetworkDelegate}
 * @note For network monitoring callbacks and related processing, please refer to：
 * https://help.aliyun.com/zh/live/developer-reference/handling-of-exceptions-and-special-scenarios-for-ios
 */
- (void)setNetworkDelegate:(id<AlivcLivePusherNetworkDelegate>)delegate;

/**
 * @brief 设置用户自定义滤镜回调
 * @param delegate {@link AlivcLivePusherCustomFilterDelegate}
 * @note 对接美颜SDK相关回调可参考：
 * https://help.aliyun.com/zh/live/developer-reference/handling-of-exceptions-and-special-scenarios-for-ios
 */

/****
 * @brief Set a custom filter callback
 * @param delegate {@link AlivcLivePusherCustomFilterDelegate}
 * @note Please refer to the callbacks related to docking third-party beauty SDK.：
 * https://help.aliyun.com/zh/live/developer-reference/handling-of-exceptions-and-special-scenarios-for-ios
 */
- (void)setCustomFilterDelegate:(id<AlivcLivePusherCustomFilterDelegate>)delegate;


/**
 * @brief 设置用户自定义人脸识别回调
 * @param delegate {@link AlivcLivePusherCustomDetectorDelegate}
 */

/****
 * @brief Set a custom facial recognition callback
 * @param delegate {@link AlivcLivePusherCustomDetectorDelegate}
 */
- (void)setCustomDetectorDelegate:(id<AlivcLivePusherCustomDetectorDelegate>)delegate;

/**
 * @brief 设置背景音乐监听回调
 * @param delegate {@link AlivcLivePusherBGMDelegate}
 */

/****
 * @brief Set the callback for background music
 * @param delegate {@link AlivcLivePusherBGMDelegate}
 */
- (void)setBGMDelegate:(id<AlivcLivePusherBGMDelegate>)delegate;

/**
 * @brief 设置音频裸数据回调
 * @param delegate {@link AlivcLivePusherAudioSampleDelegate}
 */

/****
 * @brief Set the callback for raw audio data
 * @param delegate {@link AlivcLivePusherAudioSampleDelegate}
 */
- (void)setAudioSampleDelegate:(id<AlivcLivePusherAudioSampleDelegate>)delegate;

/* *****************(互动模式下没有同步接口和异步接口区别，同步异步接口调用效果完全相同，只需要选择任意一种API即可)****************** */
/**
 * @brief 开始预览 同步接口
 * @param previewView 预览view
 * @return 0:success  非0:failure
 * @note 该接口对应的回调：{@link AlivcLivePusherInfoDelegate::onPreviewStarted:}
 * @note 预览成功对应的回调：{@link AlivcLivePusherInfoDelegate::onFirstFramePreviewed:}
 * @note 如果需要更新渲染View(例如刚开始在A view上渲染，需要更新到B view上渲染)，可以调用接口：{@link AlivcLivePusher::updateLocalView:}
 * @note 如果需要调整预览现实样式(例如裁剪、拉升)，可参考接口设置：{@link AlivcLivePushConfig::previewDisplayMode} 或 {@link AlivcLivePusher::setpreviewDisplayMode:}
 */

/****
 * @brief Start preview. (This is a synchronous method.)
 * @param previewView view
 * @return
 *  0:success
 *  != 0:failure
 * @note The callback corresponding to this interface：{@link AlivcLivePusherInfoDelegate::onPreviewStarted:}
 * @note Callback corresponding to successful preview：{@link AlivcLivePusherInfoDelegate::onFirstFramePreviewed:}
 * @note If you need to update the rendering View (for example, you just started preview on the A view and need to update it to render on the B view), you can call the interface: {@link AlivcLivePusher::updateLocalView:}
 * @note If you need to adjust the preview style (such as cropping, lifting), please refer to the interface settings：{@link AlivcLivePushConfig::previewDisplayMode} or  {@link AlivcLivePusher::setpreviewDisplayMode:}
 */
- (int)startPreview:(UIView *)previewView;

/**
 * @brief 更新本地摄像头的预览画面
 * @param view 预览view
 * @note 如果需要更新渲染View(例如刚开始在A view上渲染，需要更新到B view上渲染)，可以调用此接口
 * @note 注：该API暂时只支持在livePushMode = AlivcLivePushInteractiveMode 模式下生效，AlivcLivePushBasicMode模式下暂时不支持该API，调用无任何效果
 */

/****
 * @brief Update local camera preview
 * @param view camera preview view
 * @note If you need to update the rendering View (for example, you just started rendering on the A view and need to update it to render on the B view), you can call this interface.
 * @note Note: This API is currently only supported in livePushMode = AlivcLivePushInteractiveMode mode. This API is temporarily not supported in AlivcLivePushBasicMode mode, and the call has no effect.
 */
- (void)updateLocalView:(UIView *)view;


/**
 * @brief 停止预览
 * @return 0:success  非0:failure
 * @note 该接口对应的回调：{@link AlivcLivePusherInfoDelegate::onPreviewStoped:}
 */

/****
 * @brief Stop preview
 * @return
 *  0:success
 *  != 0:failure
 * @note The callback corresponding to this interface：{@link AlivcLivePusherInfoDelegate::onPreviewStoped:}
 */
- (int)stopPreview;


/**
 * @brief 开始推流 同步接口
 * @param pushURL 推流URL
 * @return 0:success  非0:failure
 * @note 该接口调用后可收到的回调:
 * 1. 推流链接建立成功：{@link AlivcLivePusherInfoDelegate::onPushStarted:}
 * 2.发送第一帧音视频流成功回调，可作为推流成功回调: {@link AlivcLivePusherInfoDelegate::onFirstFramePushed:}
 */

/****
 * @brief Start stream push. (This is a synchronous method.)
 * @param pushURL push URL
 * @return
 *  0:success
 *  != 0:failure
 * @note The callbacks that can be received after calling this interface:
 * 1. Push connection established successfully：{@link AlivcLivePusherInfoDelegate::onPushStarted:}
 * 2. Callback for successful sending of the first frame of audio and video stream, which can be used as callback for successful streaming: {@link AlivcLivePusherInfoDelegate::onFirstFramePushed:}
 */
- (int)startPushWithURL:(NSString *)pushURL;


/**
 * @brief 停止推流
 * @return 0:success  非0:failure
 * @note 该接口调用后可收到的回调: {@link AlivcLivePusherInfoDelegate::onPushStoped:}
 */

/****
 * @brief Stop stream push
 * @return
 *  0:success
 *  != 0:failure
 * @note The callbacks that can be received after calling this interface: {@link AlivcLivePusherInfoDelegate::onPushStoped:}
 */
- (int)stopPush;


/**
 * @brief 重新推流 同步接口
 * @return 0:success  非0:failure
 * @note 此接口SDK内部会停止预览再开启预览，预览画面会有黑一下的过程；如果不希望重新预览，仅是重新推流，可以先调用stopPush结束推流，再调用startPushWithURL开启推流
 */

/****
 * @brief Restart stream push. (This is a synchronous method.)
 * @return
 *  0:success
 *  != 0:failure
 * @note This interface SDK will stop previewing and then start previewing, and the preview screen will go black for a while; if you do not want to preview again and just push the stream again, you can first call stopPush to end the push, and then call startPushWithURL to start the push.
 */
- (int)restartPush;


/**
 * @brief 暂停摄像头推流，如果pushCongfig 中设置了pauseImg图片，将推设置的静态图片
 * @return 0:success  非0:failure
 * @note SDK不提供暂停推流的接口，这个接口的含义是暂停摄像头推流切换成推静态图片，只是视频画面发生了变化，声音还是推流
 */

/****
 * @brief Pause stream push from the camera，If you have specified an image by using the pauseImg parameter of the pushConfig class,
 * the specified image is pushed.
 * @return
 *  0:success
 *  != 0:failure
 *  @note The SDK does not provide an interface for pausing streaming. The meaning of this interface is to pause the camera streaming and switch to pushing static pictures. Only the video picture changes, and the sound is still pushed.
 */
- (int)pause;



/**
 * @brief 恢复摄像头推流 同步接口
 * @return 0:success  非0:failure
 */

/****
 * @brief Resume stream push from the camera. (This is a synchronous method.)
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)resume;


/**
 * @brief 重连 异步接口
 * @return 0:success  非0:failure
 */

/****
 * @brief Reconnect. (This is an asynchronous method.)
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)reconnectPushAsync;

/**
 * @brief 推流URL的重连 异步接口
 * @return 0:success  非0:failure
 */

/****
 * @brief Reconnect the push URL. (This is an asynchronous method.)
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)reconnectPushAsync:(NSString *)pushURL;

/**
 * @brief 销毁推流引擎
 */

/****
 * @brief Destroys the live pusher engine
 */
- (void)destory;



/* *****************异步接口(互动模式下没有同步接口和异步接口区别，同步异步接口调用效果完全相同，只需要选择任意一种API即可)****************** */
/**
 * @brief 开始预览 异步接口
 * @param preview 预览view
 * @return 0:success  非0:failure
 * @note 该接口对应的回调：{@link AlivcLivePusherInfoDelegate::onPreviewStarted:}
 * @note 预览成功对应的回调：{@link AlivcLivePusherInfoDelegate::onFirstFramePreviewed:}
 * @note 如果需要更新渲染View(例如刚开始在A view上渲染，需要更新到B view上渲染)，可以调用接口：{@link AlivcLivePusher::updateLocalView:}
 * @note 如果需要调整预览现实样式(例如裁剪、拉升)，可参考接口设置：{@link AlivcLivePushConfig::previewDisplayMode} 或 {@link AlivcLivePusher::setpreviewDisplayMode:}
 */

/****
 * @brief Start preview. (This is an asynchronous method.)
 * @param preview view
 * @return
 *  0:success
 *  != 0:failure
 * @note The callback corresponding to this interface：{@link AlivcLivePusherInfoDelegate::onPreviewStarted:}
 * @note Callback corresponding to successful preview：{@link AlivcLivePusherInfoDelegate::onFirstFramePreviewed:}
 * @note If you need to update the rendering View (for example, you just started preview on the A view and need to update it to render on the B view), you can call the interface: {@link AlivcLivePusher::updateLocalView:}
 * @note If you need to adjust the preview style (such as cropping, lifting), please refer to the interface settings：{@link AlivcLivePushConfig::previewDisplayMode} or  {@link AlivcLivePusher::setpreviewDisplayMode:}
 */
- (int)startPreviewAsync:(UIView *)preview;


/**
 * @brief 开始推流 异步接口
 * @param pushURL 推流URL
 * @return 0:success  非0:failure
 * @note 该接口调用后可收到的回调:
 * 1. 推流链接建立成功：{@link AlivcLivePusherInfoDelegate::onPushStarted:}
 * 2.发送第一帧音视频流成功回调，可作为推流成功回调: {@link AlivcLivePusherInfoDelegate::onFirstFramePushed:}
 */

/****
 * @brief Start stream push. (This is an asynchronous method.)
 * @param pushURL push URL
 * @return
 *  0:success
 *  != 0:failure
 * @note The callbacks that can be received after calling this interface:
 * 1. Push connection established successfully：{@link AlivcLivePusherInfoDelegate::onPushStarted:}
 * 2. Callback for successful sending of the first frame of audio and video stream, which can be used as callback for successful streaming: {@link AlivcLivePusherInfoDelegate::onFirstFramePushed:}
 */
- (int)startPushWithURLAsync:(NSString *)pushURL;


/**
 * @brief 重新推流 异步接口
 * @return 0:success  非0:failure
 * @note 此接口SDK内部会停止预览再开启预览，预览画面会有黑一下的过程；如果不希望重新预览，仅是重新推流，可以先调用stopPush结束推流，再调用startPushWithURLAsync开启推流
 */

/****
 * @brief Restart stream push. (This is an asynchronous method.)
 * @return
 *  0:success
 *  != 0:failure
 * @note This interface SDK will stop previewing and then start previewing, and the preview screen will go black for a while; if you do not want to preview again and just push the stream again, you can first call stopPush to end the push, and then call startPushWithURLAsync to start the push.
 */
- (int)restartPushAsync;


/**
 * @brief 恢复推流 异步接口
 * @return 0:success  非0:failure
 */

/****
 * @brief Resume stream push. (This is an asynchronous method.)
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)resumeAsync;

/* ****************************************************** */



/**
 * @brief 切换摄像头
 * @return 0:success  非0:failure
 */

/****
 * @brief Switch between the front and rear cameras
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)switchCamera;


/**
 * @brief 设置自动对焦
 * @param autoFocus true:自动对焦 false:手动对焦
 * @return 0:success  非0:failure
 * @note SDK内部默认是自动对焦的
 */

/****
 * @brief Specify whether to enable autofocus
 * @param autoFocus true:autofocus false:Manual focus
 * @return
 *  0:success
 *  != 0:failure
 * @note The SDK internal default is autofocus
 */
- (int)setAutoFocus:(bool)autoFocus;


/**
 * @brief 对焦
 * @param point 对焦的点，point.x和point.y的取值是(0,1)，表示当前点相对于渲染view的相对位置
 * @param autoFocus 是否自动对焦
 * @return 0:success  非0:failure
 */

/****
 * @brief Configure focus
 * @param point The focus point The values ​​of point.x and point.y are (0,1), indicating the relative position of the current point relative to the rendering view
 * @param autoFocus Whether to enable autofocus
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)focusCameraAtAdjustedPoint:(CGPoint)point autoFocus:(bool)autoFocus;


/**
 * @brief 缩放
 * @param zoom 缩放值[0:MaxZoom]
 * @return 0:success  非0:failure
 */

/****
 * @brief Configure zoom
 * @param zoom The zoom value.[0:MaxZoom]
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setZoom:(float)zoom;


/**
 * @brief 获取支持的最大变焦值
 * @return 最大变焦值
 */

/****
 * @brief Query the maximum zoom value that is supported
 * @return The maximum zoom value
 */
- (float)getMaxZoom;


/**
 * @brief 获取当前变焦值
 * @return 当前变焦值
 */

/****
 * @brief Query the current zoom value
 * @return The current zoom value
 */
- (float)getCurrentZoom;


/**
 * @brief 闪光灯开关
 * @param flash true:打开闪光灯 false:关闭闪光灯
 * @return 0:success  非0:failure
 */

/****
 * @brief Specify whether to turn on the flash
 * @param flash true:Turn on the flash. false:Turn off the flash
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setFlash:(bool)flash;


/**
 * @brief 设置曝光度
 * @param exposure 曝光度
 * @return 0:success  非0:failure
 */

/****
 * @brief Specify the exposure level
 * @param exposure The exposure level
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setExposure:(float)exposure;


/**
 * @brief 获取当前曝光度
 * @return  曝光度
 */

/****
 * @brief Query the current exposure level
 * @return  The exposure level
 */
- (float)getCurrentExposure;

/**
 * @brief 获取支持最小曝光度
 * @return  最小曝光度
 */

/****
 * @brief Query the minimum exposure level that is supported
 * @return  The minimum exposure level
 */
- (float)getSupportedMinExposure;

/**
 * @brief 获取支持最大曝光度
 * @return  最大曝光度
 */

/****
 * @brief Query the maximum exposure level that is supported
 * @return  The maximum exposure level
 */
- (float)getSupportedMaxExposure;


/**
 * @brief 推流镜像开关
 * @param mirror true:打开推流镜像 false:关闭推流镜像
 * @note SDK默认推流不镜像
 */

/****
 * @brief Specify whether to enable the mirroring mode for live pusher
 * @param mirror true:Enable the mirroring mode for stream push. false:Disable the mirroring mode for stream push
 * @note SDK default push stream does not mirror
 */
- (void)setPushMirror:(bool)mirror;


/**
 * @brief 预览镜像开关
 * @param mirror true:打开预览镜像 false:关闭预览镜像
 * @note SDK默认前置摄像头预览镜像，后置摄像头预览不镜像
 */

/****
 * @brief Specify whether to enable the mirroring mode for preview
 * @param mirror true:Enable the mirroring mode for preview. false:Disable the mirroring mode for preview.
 * @note By default, the SDK mirrors the front camera preview and does not mirror the rear camera preview.
 */
- (void)setPreviewMirror:(bool)mirror;


/**
 * @brief 静音推流
 * @param mute true:静音推流 false:正常推流
 * @note 调用此接口，控制音频流是否静音；即使在静音时，仍然占用系统麦克风权限，发送静音音频数据
 * @note 如果希望不再占用系统麦克风权限，即：关闭音频采集，可调用接口：{@link AlivcLivePusher::stopAudioCapture }
 */

/****
 * @brief Mute the audio stream
 * @param mute true:mute false:Normal
 * @note Call this interface to control whether the audio stream is muted; Even when muted, the system still occupies microphone permissions and sends muted audio data
 * @note If you want to no longer occupy system microphone permissions, that is, turn off audio collection, please refer to the interface：{@link AlivcLivePusher::stopAudioCapture }
 */
- (void)setMute:(bool)mute;

/**
 * @brief 停止/恢复本地音频数据发送
 * @param mute  YES表示静音本地音频，发送静音帧; NO表示取消静音;
 * @param mode  静音模式，静音模式分三种，详见 {@link AliLiveMuteLocalAudioMode}
 * @return
 * - 0: 成功
 * - 非0: 失败
 * @note 静音是指音频流发送静音帧,采集和编码模块仍然在工作，仍然占用系统麦克风权限
 * @note 如果希望不再占用系统麦克风权限，即：关闭音频采集，可调用接口：{@link AlivcLivePusher::stopAudioCapture }
 */

/****
 * @brief Mute the audio stream
 * @param mute  true:mute false:Normal
 * @param mode  mute mode. There are three types of mute modes. For details, see {@link AliLiveMuteLocalAudioMode}
 * @note Call this interface to control whether the audio stream is muted; Even when muted, the system still occupies microphone permissions and sends muted audio data
 * @note If you want to no longer occupy system microphone permissions, that is, turn off audio collection, please refer to the interface：{@link AlivcLivePusher::stopAudioCapture }
 */
- (void)setMute:(BOOL)mute mode:(AliLiveMuteLocalAudioMode)mode;


/**
 * @brief 设置推流模式
 * @param qualityMode 推流模式 : 选择 ResolutionFirst 模式时，SDK内部会优先保障推流视频的清晰度; 选择 FluencyFirst 模式时，SDK内部会优先保障推流视频的流畅度，此接口只支持这两种模式。设置后码率设置失效。
 * @return 0:success  非0:failure
 * @note 此接口只在基础模式下生效，互动模式下不生效
 */

/****
 * @brief Specify the quality mode
 * @param qualityMode If you select the ResolutionFirst mode, the SDK prioritizes the quality of streams. If you select the FluencyFirst mode, the SDK prioritizes the smoothness of streams. This method supports only the two modes. The bitrate setting becomes invalid after you specify the quality mode.
 * @return
 *  0:success
 *  != 0:failure
 * @note This interface only takes effect in basic mode and does not take effect in interactive mode.
 */
- (int)setQualityMode:(AlivcLivePushQualityMode)qualityMode;


/**
 * @brief 设置目标码率
 * @param targetBitrate 目标码率 [100  5000](Kbps)
 * @return 0:success  非0:failure
 */

/****
 * @brief Specify the target bitrate
 * @param targetBitrate The target bitrate [100  5000](Kbps)
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setTargetVideoBitrate:(int)targetBitrate;


/**
 * @brief 设置最小码率
 * @param minBitrate 最小码率 [100  5000](Kbps)
 * @return 0:success  非0:failure
 */

/****
 * @brief Specify the minimum bitrate
 * @param minBitrate The minimum bitrate. [100  5000](Kbps)
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setMinVideoBitrate:(int)minBitrate;

/**
 * @brief 设置预览显示模式
 * @param displayMode 预览显示模式
 */

/****
 * @brief Specify the preview mode
 * @param displayMode The preview mode
 */
- (void)setpreviewDisplayMode:(AlivcPusherPreviewDisplayMode)displayMode;


/**
 * @brief 设置推流分辨率
 * @param resolution 推流分辨率
 * @note 此接口可以动态调整推流分辨率，例如在多人PK场景，根据PK人数的不同需要动态调整推流分辨率，可以使用该接口
 */

/****
 * @brief Specify the resolution, which takes effect only in preview mode
 * @param resolution The resolution of the ingested stream
 * @note This interface can dynamically adjust the push resolution. For example, in a multi-player PK scenario, you can use this interface to dynamically adjust the push resolution according to the different number of people in the PK.
 */
- (void)setResolution:(AlivcLivePushResolution)resolution;



/* ***********************背景音乐*********************** */

/**
 * @brief 播放背景音乐
 * @param path 背景音乐路径
 * @return 0:success  非0:failure
 */

/****
 * @brief Play background music
 * @param path The path of the background music
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)startBGMWithMusicPathAsync:(NSString *)path;


/**
 * @brief 停止播放背景音乐
 * @return 0:success  非0:failure
 */

/****
 * @brief Stop the playback of background music
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)stopBGMAsync;


/**
 * @brief 暂停播放背景音乐
 * @return 0:success  非0:failure
 */

/****
 * @brief Pause the playback of background music
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)pauseBGM;


/**
 * @brief 恢复播放背景音乐
 * @return 0:success  非0:failure
 */

/****
 * @brief Resume the playback of background music
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)resumeBGM;


/**
 * @brief 设置背景音乐是否循环播放
 * @param isLoop 是否循环  true:循环 false:不循环
 * @return 0:success  非0:failure
 */

/****
 * @brief Specify whether to enable loop playback of background music
 * @param isLoop Whether to loop.  true:Loop false:No loop
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setBGMLoop:(bool)isLoop;


/**
 * @brief 设置背景音乐耳返开关
 * @param isOpen 是否打开耳返  true:开启耳返 false:关闭耳返
 * @return 0:success  非0:failure
 */

/****
 * @brief Specify whether to enable in-ear monitoring for background music
 * @param isOpen Whether to enable in-ear monitoring.  true:Enabled false:Disabled
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setBGMEarsBack:(bool)isOpen;


/**
 * @brief 设置降噪开关
 * @param isOpen 是否打开降噪 true:开启 false:关闭 默认:true
 * @return 0:success  非0:failure
 */

/****
 * @brief Specify whether to enable noise reduction
 * @param isOpen Whether to enable noise reduction. true:Enabled false:Disabled default:true
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setAudioDenoise:(bool)isOpen;

/**
 * @brief 开启智能降噪
 * @return
 * - 0: 成功
 * - 非0: 返回错误码
 * @details
 * - 智能降噪功能以插件形式提供，直播SDK采用插件形式提供音视频增强能力，可通过[官网组件文档] 进行组建下载，参考插件集成文档集成进直播推流引擎
 * https://help.aliyun.com/document_detail/600551.html
 * - 调用该接口前，请确保已集成了直播官网提供的pulginAliDenoise.framework
 * - 此接口可以通话过程中控制打开智能降噪功能，通话过程中可以支持开启和关闭智能降噪
 * - 默认关闭，开启后可能导致功耗增加，智能降噪适合于会议，教育等语音通讯为主的场景，不适合有背景音乐的场景
 */

/****
 * @brief Enable intelligent noise reduction
 * @return
 *  0:success
 *  != 0:failure
 * @details
 * - Push SDK provides audio and video enhancement by using various components. The intelligent noise reduction feature is provided in the form of a component.
 *  You can learn about it in the ApsaraVideo Live documentation. For information about how to integrate the component into the stream ingest engine, see the following topic:
 *  https://help.aliyun.com/document_detail/600551.html
 * - Before you call this method, make sure that pulginAliDenoise.framework provided by ApsaraVideo Live is integrated.
 * - You can call this method to enable intelligent noise reduction during a live pushing.
 * - By default, the intelligent noise reduction feature is disabled. If you enabled this feature, power consumption increases. This feature is suitable for
 *  voice communication scenarios such as conferences and educational activities, but not suitable for scenarios with background music.
 */
- (int)startIntelligentDenoise;

/**
 * @brief 关闭智能降噪
 * @note 此接口可以通话过程中控制关闭智能降噪功能
*/

/****
 * @brief Disable intelligent noise reduction
 * @note You can call this method to disable intelligent noise reduction during a voice call.
*/
- (int)stopIntelligentDenoise;





/**
 * @brief 设置背景音乐混音 音乐音量
 * @param volume 音乐音量大小 范围:[0 ~ 100] 默认:50
 * @return 0:success  非0:failure
 */

/****
 * @brief Set the volume of music in mixed audio
 * @param volume The music volume.:[0 ~ 100] default:50
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setBGMVolume:(int)volume;


/**
 * @brief 设置背景音乐混音 人声音量
 * @param volume 人声音量大小 范围:[0 ~ 100] 默认:50
 * @return 0:success  非0:failure
 */

/****
 * @brief Set the volume of vocal in mixed audio
 * @param volume The vocal volume.:[0 ~ 100] default:50
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setCaptureVolume:(int)volume;

/* **********************开启屏幕分享******************************** */

/**
 * @brief 开始屏幕分享（该接口支持 iOS 11.0 及以上的 iPhone 和 iPad）。
 *
 * @details 该接口开始 iOS 系统的屏幕分享，可以实现录屏推流功能
 *     该接口配合AlivcLibReplayKitExt.framework使用，在Extension进程中添加AlivcLibReplayKitExt.framework库完成屏幕采集和发送
 *     在Host APP中接收音视频数据，完成推流。
 * @param appGroup App group ID 主 App 与 Extension 共享的 Application Group Identifier，当前接口仅支持主 App 与 Extension 属于同一个App *
 * Group的情况，如果不存在App Group， 不可调用该接口。
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode
 * 模式下开始屏幕分享（录屏推流），AlivcLivePushInteractiveMode模式下暂时不支持开始屏幕分享（录屏推流）
 */

/****
 * @brief Start screen sharing. (This method supports iPhones and iPads that run on iOS 11.0 or later.)
 * @details This method is used with AlivcLibReplayKitExt.framework to add the AlivcLibReplayKitExt.framework library to an
 * Extension to implement screen capture and data transmission. Audio and video data is received in the host app for stream pusher.
 * @param appGroup App group ID The ID of the app group to which the host app and the Extension belong. In this case, the host app and the
 *  Extension belong to the same app group. If no app group is available, you cannot call this method.
 * @note ote: The SDK supports screen sharing (screen recording for stream ingest) when livePushMode is set to AlivcLivePushBasicMode,
 *  but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (int)startScreenCapture:(NSString *)appGroup;

/* ***********************外部数据*********************** */

/**
 * @brief 发送自定义video SampleBuffer
 *
 * @param sampleBuffer video sample buffer
 * @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下发送自定义video SampleBuffer，AlivcLivePushInteractiveMode模式下请使用sendVideoData接口向SDK输入自定义视频数据
 */

/****
 * @brief Send custom video SampleBuffer
 * @param sampleBuffer video sample buffer
 * @note The SDK allows you to send custom video SampleBuffer when livePushMode is set to AlivcLivePushBasicMode,
 * but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (void)sendVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/**
 * @brief 发送自定义的audio SampleBuffer
 * @details 只限于replaykit录屏直播使用
 *
 * @param sampleBuffer audio sample buffer
 * @param sampleBufferType audio sample buffer type
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下发送自定义的audio
 * SampleBuffer，AlivcLivePushInteractiveMode模式下暂时不支持发送自定义的audio SampleBuffer，请使用sendPCMData接口向SDK输入自定义音频数据
 */

/****
 * @brief Send custom audio SampleBuffer
 * @details You can call this method only when you use replaykit to stream screen recordings
 * @param sampleBuffer audio sample buffer
 * @param sampleBufferType audio sample buffer type
 * @note Note: The SDK allows you to send custom audio SampleBuffer when livePushMode is set to AlivcLivePushBasicMode,
 * but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (void)sendAudioSampleBuffer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType;

/**
 * @brief 发送自定义视频数据
 *
 * @param data 视频数据
 * @param width 视频宽度
 * @param height 视频高度
 * @param size 数据大小
 * @param pts 时间戳（单位微秒）
 * @param rotation 旋转
 */

/****
 * @brief Send custom video data
 * @param data The video data
 * @param width The width of the video
 * @param height The height of the video
 * @param size The data size
 * @param pts The presentation timestamp. Unit: microsecond
 * @param rotation The rotation degree
 */
- (void)sendVideoData:(char *)data width:(int)width height:(int)height size:(int)size pts:(uint64_t)pts rotation:(int)rotation;

/**
 * @brief 发送自定义音频数据
 *
 * @param data 音频数据
 * @param size 数据大小
 * @param sampleRate 采样率
 * @param channel 声道数
 * @param pts 时间戳（单位微秒）
 */

/****
 * @brief Send custom audio data.
 * @param data The audio data
 * @param size The data size
 * @param sampleRate The sample rate
 * @param channel The number of sound channels
 * @param pts The presentation timestamp. Unit: microsecond
 */
- (void)sendPCMData:(char *)data size:(int)size sampleRate:(int)sampleRate channel:(int)channel pts:(uint64_t)pts;

/**
 * @brief 添加视频混流设置
 * @param format 原始视频数据格式
 * @param width 图像宽
 * @param height 图像高
 * @param rotation 图像角度
 * @param displayX 图像要放置到屏幕的左上角坐标x
 * @param displayY 图像要放置到屏幕的左上角坐标y
 * @param displayW 图像显示的宽度
 * @param displayH 图像显示的高度
 * @param adjustHeight 图像自适应的高度
 * @return 返回对应视频混流标识ID
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下添加视频混流设置，AlivcLivePushInteractiveMode模式下暂时不支持添加视频混流设置
 */

/****
 * @brief Add video stream mixing settings
 * @param format The format of the raw video data
 * @param width The width of the video
 * @param height The height of the video
 * @param rotation The angle of the video
 * @param displayX The coordinate value along the x-axis to place the video in the upper-left corner.
 * @param displayY The coordinate value along the y-axis to place the video in the upper-left corner.
 * @param displayW The display width of the video
 * @param displayH The display height of the video
 * @param adjustHeight The adaptive height of the video
 * @return The ID of the mixed video stream
 * @note Note: The SDK allows you to add video stream mixing settings when livePushMode is set to AlivcLivePushBasicMode,
 * but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (int)addMixVideo:(int)format width:(int)width height:(int)height rotation:(int)rotation displayX:(float)displayX displayY:(float)displayY displayW:(float)displayW displayH:(float)displayH adjustHeight:(bool)adjustHeight;

/**
 * @brief 改变视频混流位置
 * @param handler 视频混流标识ID，通过addMixVideo接口获得
 * @param displayX 图像要放置到屏幕的左上角坐标x
 * @param displayY 图像要放置到屏幕的左上角坐标y
 * @param displayW 图像显示的宽度
 * @param displayH 图像显示的高度
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下改变视频混流位置，AlivcLivePushInteractiveMode模式下暂时不支持改变视频混流位置
 */

/****
 * @brief Modify the position of the mixed video stream
 * @param handler The ID of the mixed video stream. You can obtain the ID from the addMixVideo request
 * @param displayX The coordinate value along the x-axis to place the video in the upper-left corner.
 * @param displayY The coordinate value along the y-axis to place the video in the upper-left corner.
 * @param displayW The display width of the video
 * @param displayHThe display height of the video
 * @note Note: The SDK allows you to modify the position of the mixed video stream when livePushMode is set to AlivcLivePushBasicMode,
 *  but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (void)changeMixVideoPosition:(int)handler displayX:(float)displayX displayY:(float)displayY displayW:(float)displayW displayH:(float)displayH;

/**
 * @brief 改变视频混流镜像
 * @param handler 视频混流标识ID，通过addMixVideo接口获得
 * @param isMirror 是否镜像
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下改变视频混流镜像，AlivcLivePushInteractiveMode模式下暂时不支持改变视频混流镜像
 */

/****
 * @brief Modify the mirroring settings for the mixed video stream
 * @param handler The ID of the mixed video stream. You can obtain the ID from the addMixVideo request.
 * @param isMirror Whether to enable mirroring
 * @note Note: The SDK allows you to modify the mirroring settings for the mixed video stream when livePushMode is set to AlivcLivePushBasicMode,
 * but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (void)setMixVideoMirror:(int)handler isMirror:(BOOL)isMirror;

/**
 * @brief 输入视频混流数据
 * @param handler 视频混流标识ID，通过addMixVideo接口获得
 * @param dataptr 数据buffer的地址
 * @param width 图像宽
 * @param height 图像高
 * @param stride 图像存储时内存中每行像素所占用的空间
 * @param size 此帧图像的大小
 * @param pts 时间戳（单位微秒）
 * @param rotation 图像角度
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下输入视频混流数据，AlivcLivePushInteractiveMode模式下暂时不支持输入视频混流数据
 */

/****
 * @brief Import video stream mixing data
 * @param handler The ID of the mixed video stream. You can obtain the ID from the addMixVideo request
 * @param dataptr The address of the data buffer
 * @param width The width of the video
 * @param height The height of the video
 * @param stride stride
 * @param size The space occupied by each row of pixels in memory when the video is stored
 * @param pts The presentation timestamp. Unit: microsecond
 * @param rotationThe angle of the video
 * @note Note: The SDK allows you to import video stream mixing data when livePushMode is set to AlivcLivePushBasicMode,
 * but not when livePushMode is set to AlivcLivePushInteractiveMode
 */
- (void)inputMixVideoData:(int)handler data:(long)dataptr width:(int)width height:(int)height stride:(int)stride size:(int)size pts:(long)pts rotation:(int)rotation;

/**
 * @brief 移除视频混流设置
 * @param handler 视频混流标识ID，通过addMixVideo接口获得
 */

/****
 * @brief Delete video stream mixing settings
 * @param handler The ID of the mixed video stream. You can obtain the ID from the addMixVideo request.
 */
- (void)removeMixVideo:(int) handler;

/**
 * @brief 添加音频混流设置
 * @param channels 声道数
 * @param format 音频格式  AlivcLivePushAudioFormat
 * @param audioSample 音频采样率
 * @return 返回对应音频混流标识ID
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下添加音频混流，AlivcLivePushInteractiveMode模式下暂时不支持添加音频混流
 */

/****
 * @brief Add audio stream mixing settings
 * @param channels The number of sound channels
 * @param format The format of the audio AlivcLivePushAudioFormat
 * @param audioSample The audio sample rate
 * @return The ID of the mixed audio stream is returned
 * Note: The SDK allows you to add audio stream mixing settings when livePushMode is set to AlivcLivePushBasicMode,
 *  but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (int)addMixAudio:(int)channels format:(int)format audioSample:(int)audioSample;

/**
 * @brief 输入音频混流数据
 * @param handler 音频混流标识ID，通过addMixAudio接口获得
 * @param dataptr 数据buffer的地址
 * @param size 音频数据的大小
 * @param pts 时间戳（单位微秒）
 * @return success:true, failed:false
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下输入音频混流数据，AlivcLivePushInteractiveMode模式下暂时不支持输入音频混流数据
 */

/****
 * @brief Import audio stream mixing data
 * @param handler The ID of the mixed audio stream. You can obtain the ID from the addMixAudio request
 * @param dataptr The address of the data buffer
 * @param size The size of the audio data
 * @param pts The presentation timestamp. Unit: microsecond
 * @return success:true, failed:false
 * @note Note: The SDK allows you to import audio stream mixing data when livePushMode is set to AlivcLivePushBasicMode,
 * but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (bool)inputMixAudioData:(int)handler data:(long)dataptr size:(int)size pts:(long)pts;

/**
 * @brief 移除音频混流
 * @param handler 音频混流标识ID，通过addMixAudio接口获得
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下移除音频混流，AlivcLivePushInteractiveMode模式下暂时不支持移除音频混流
 */

/****
 * @brief Delete audio stream mixing settings
 * @param handler The ID of the mixed audio stream. You can obtain the ID from the addMixAudio request
 * @note Note: The SDK allows you to delete audio stream mixing settings when livePushMode is set to AlivcLivePushBasicMode,
 * but not when livePushMode is set to AlivcLivePushInteractiveMode.
 */
- (void)removeMixAudio:(int)handler;

/* ****************************************************** */

/**
 * @brief 设置自定义Message (SEI)
 * @param msg 用户推流消息
 * @param count 重复次数
 * @param time 延时时间，单位毫秒
 * @param isKeyFrame 是否只发关键帧，该参数只支持在livePushMode = AlivcLivePushBasicMode 模式下设置，AlivcLivePushInteractiveMode模式下暂时不支持设置，互动模式下传入false
 * @return 0:success  非0:failure
 * @note 该接口sei 的payloadType为5
 */

/****
 * @brief Set a custom SEI message
 * @param msg The message
 * @param count The number of repetitions
 * @param time The latency. Unit: millisecond
 * @param isKeyFrame Whether to send only keyframes，This parameter only supports setting in livePushMode = AlivcLivePushBasicMode mode, and temporarily does not support setting in AlivcLivePushInteractiveMode mode, Pass false in interactive mode
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)sendMessage:(NSString *)msg repeatCount:(int)count delayTime:(int)time KeyFrameOnly:(bool)isKeyFrame;

/**
 * @brief 设置自定义Message (SEI)
 * @param msg 用户推流消息
 * @param count 重复次数
 * @param time 延时时间，单位毫秒
 * @param isKeyFrame 是否只发关键帧，该参数只支持在livePushMode = AlivcLivePushBasicMode 模式下设置，AlivcLivePushInteractiveMode模式下暂时不支持设置, ，互动模式下传入false
 * @param payloadType 类型，可设置的值为5或者[100..254]范围区间，如果设置5，则在内容前面会有一个16字节的UUID
 * @return 0:success  非0:failure
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushInteractiveMode 模式下生效，AlivcLivePushBasicMode模式下暂时不支持设置payloadType
 */

/****
 * @brief Set a custom SEI message
 * @param msg The message
 * @param count The number of repetitions
 * @param time The latency. Unit: millisecond
 * @param isKeyFrame Whether to send only keyframes，This parameter only supports setting in livePushMode = AlivcLivePushBasicMode mode, and temporarily does not support setting in AlivcLivePushInteractiveMode mode, , Pass false in interactive mode
 * @param payloadType payloadType type, the settable value is 5 or the range  [100..254]. If 5 is set, there will be a 16-byte UUID in front of the content.
 * @return
 *  0:success
 *  != 0:failure
 * @note The current SDK only supports the livePushMode = AlivcLivePushInteractiveMode mode. Setting the payloadType in the AlivcLivePushBasicMode mode is temporarily not supported.
 */
- (int)sendMessage:(NSString *)msg repeatCount:(int)count delayTime:(int)time KeyFrameOnly:(bool)isKeyFrame payloadType:(int)payloadType;

/**
 * @brief 开启SEI视频流，内部将使用16x16全黑图片流/20fps
 * @note 在互动模式下，如果把摄像头采集关闭(调用enableLocalCamera接口)，纯音频场景，默认不会发送视频，
 * 但是如果后续调用了sendMessage接口发送SEI信息，SDK内部默认会发送16x16全黑图片流/20fps的视频流来承载SEI信息，
 * 可以通过调用enableSEIVideoStream来关闭SDK默认的推送16x16全黑图片逻辑，关闭后纯音频场景将发送不了SEI信息
 * @param enable true=开启 false=关闭
 * @return
 * - 0: 成功
 * - 非0: 失败
 */
-(int)enableSEIVideoStream:(bool)enable;

/**
 * @brief 获取是否正在推流
 * @return YES:正在推流 NO:未推流
 * @note 可以用该方法判断是否在推流
 */

/****
 * @brief Query whether the stream is pushing
 * @return YES:pushing NO:not pushing
 */
- (BOOL)isPushing;


/**
 * @brief 获取当前推流URL
 * @return 推流URL
 */

/****
 * @brief Query the push URL
 * @return The push URL
 */
- (NSString *)getPushURL;

/**
 * @brief 获取当前推流状态
 * @return 推流状态 AlivcLivePushStatus
 */

/****
 * @brief Query the live push status
 * @return The live push status.
 */
- (AlivcLivePushStatus)getLiveStatus;

/**
 * @brief 获取推流数据统计
 * @return 推流数据 {@link AlivcLivePushStatsInfo}
 */

/****
 * @brief Query the statistics on live pusher
 * @return The stream  data. {@link AlivcLivePushStatsInfo}
 */
- (AlivcLivePushStatsInfo *)getLivePushStatusInfo;


/**
 * @brief 设置Log级别
 * @param level Log级别 default:AlivcLivePushLogLevelError
 * @return 0:success  非0:failure
 */

/****
 * @brief Set the log level
 * @param level Log default:AlivcLivePushLogLevelError
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setLogLevel:(AlivcLivePushLogLevel)level __deprecated_msg("Use AlivcLiveBase->setLogLevel instead.");

/**
 * @brief 设置Log路径
 * @param logPath Log路径
 * @param maxPartFileSizeInKB 每个分片最大大小。最终日志总体积是 5*最大分片大小
 * @return 0:success  非0:failure
 */

/****
 * @brief Set the log path
 * @param logPath Log path
 * @param maxPartFileSizeInKB The maximum size of each part. The total volume of logs is five times the maximum part size.
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setLogPath:(NSString *)logPath maxPartFileSizeInKB:(int)maxPartFileSizeInKB __deprecated_msg("Use AlivcLiveBase->setLogPath:maxPartFileSizeInKB instead.");

/**
 * @brief 获取SDK版本号
 * @return 版本号
 */

/****
 * @brief Query the version number of the SDK
 * @return The version number
 */
+ (NSString *)getSDKVersion __deprecated_msg("Use AlivcLiveBase->getSDKVersion instead.");

/**
 * @brief 添加水印 最多支持3个水印
 * @param path 水印路径
 * @param coordX 水印左上顶点x的相对坐标 [0,1]
 * @param coordY 水印左上顶点y的相对坐标 [0,1]
 * @param width 水印的相对宽度 (水印会根据水印图片实际大小和水印宽度等比缩放) (0,1]
 * @return 0:success  非0:failure
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下添加水印，AlivcLivePushInteractiveMode模式下使用setWatermark添加水印
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
- (int)addWatermarkWithPath:(NSString *)path
             watermarkCoordX:(CGFloat)coordX
             watermarkCoordY:(CGFloat)coordY
              watermarkWidth:(CGFloat)width;

/**
 * @brief 设置水印显示和隐藏
 * @param visable true:显示水印，false:隐藏水印
 */

/****
 * @brief Specify whether to show or hide watermarks
 * @param visable true:Show watermarks.，false:Hide watermarks.
 */
- (void)setWatermarkVisible:(bool) visable;

/**
 * @brief 添加动态贴纸,最多支持添加5个贴纸
 * @param waterMarkDirPath：贴纸图片sequence目录
 * @param 显示屏幕x位置（0~1.0f)
 * @param 显示屏幕y位置（0~1.0f)
 * @param 显示屏幕宽
 * @param 显示屏幕高
 * @note 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下添加动态贴纸，AlivcLivePushInteractiveMode模式下暂时不支持添加动态贴纸
 * @return 返回动态贴纸的id号，删除贴纸传此id
 */

/****
 * @brief Add animated stickers. You can add up to five animated stickers.
 * @param waterMarkDirPath：The sequence path of the animated sticker.
 * @param The position x of the display screen.（0~1.0f)
 * @param The position y of the display screen.（0~1.0f)
 * @param The width of the display screen
 * @param The height of the display screen
 * @note Note: The SDK allows you to add animated stickers when livePushMode is set to AlivcLivePushBasicMode,
 *  but not when livePushMode is set to AlivcLivePushInteractiveMode.
 * @return The ID of the animated sticker is returned. If you want to delete this animated sticker, specify this ID in the corresponding request.
 */
- (int)addDynamicWaterMarkImageDataWithPath:(NSString *)waterMarkDirPath x:(float)x y:(float)y w:(float)w h: (float)h;

/**
 * @brief 删除动态贴纸
 * @param vid:贴纸id，addDynamicWaterMarkImageDataWithPath时返回
 */

/****
 * @brief Remove an animated sticker
 * @param vid:The animated sticker id，addDynamicWaterMarkImageDataWithPath return
 */
- (void)removeDynamicWaterMark:(int)vid;

/**
 * @brief 截图
 * @param count截图次数
 * @param interval 截图间隔
 * @note livePushMode = AlivcLivePushBasicMode 基础模式下可以指定count和interval，
 * AlivcLivePushInteractiveMode模式下暂时不支持指定count和interval，传递任何值都不做解析，每次只截图一张画面
 */

/****
 * @brief Configure snapshot settings
 * @param count The number of snapshots
 * @param interval The interval between snapshots
 * @note lYou can specify the count and interval parameters only when livePushMode is set to AlivcLivePushBasicMode.
 * When livePushMode is set to AlivcLivePushInteractiveMode, the count and interval parameters that you pass are not parsed.
 * In this case, only one snapshot is captured.
 */
- (void)snapshot:(int)count interval:(int)interval;


/**
 * @brief 设置截图回调
 * @param delegate {@link AlivcLivePusherSnapshotDelegate }
 */

/****
 * @brief Set the callback for snapshot capture
 * @param delegate {@link AlivcLivePusherSnapshotDelegate }
 */
- (void)setSnapshotDelegate:(id<AlivcLivePusherSnapshotDelegate>)delegate;

/* **********************互动模式下特定API******************************** */
/* **********************Specific methods in interactive mode******************************** */

// 以下API是只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
// 非互动模式调用以下API将无任何效果，特定API包括：
// setLiveMixTranscodingConfig
// muteLocalCamera
// enableSpeakerphone
// isEnableSpeakerphone
// refreshPushURLToken
// isCameraAutoFocusFaceModeSupported
// setCameraAutoFocusFaceModeEnabled
//enableAudioVolumeIndication
//setWatermark
//startRecording
//stopRecording
//startScreenShare
//stopScreenShare
//setAudioProfile
//updateLocalView
//stopAudioCapture
//startAudioCapture
//getParameter
//getCurrentEncoderManufacturer
//startBGMWithMusicPathAsync:config

// Some methods are available only when livePushMode is set to AlivcLivePushInteractiveMode,
// that is, only when Push SDK is working in interactive mode. Calling these methods in non-interactive
// mode have no effect. These methods include:
// setLiveMixTranscodingConfig
// muteLocalCamera
// enableSpeakerphone
// isEnableSpeakerphone
// refreshPushURLToken
// isCameraAutoFocusFaceModeSupported
// setCameraAutoFocusFaceModeEnabled
//enableAudioVolumeIndication
//setWatermark
//startRecording
//stopRecording
//startScreenShare
//stopScreenShare
//setAudioProfile
//updateLocalView
//stopAudioCapture
//startAudioCapture
//getParameter
//getCurrentEncoderManufacturer
//startBGMWithMusicPathAsync:config

/**
 * @brief 设置云端的混流（转码）参数
 * 一个直播间中可能有不止一位主播，而且每个主播都有自己的画面和声音，但对于 CDN 观众来说，他们只需要一路直播流
 * 所以您需要将多路音视频流混成一路标准的直播流，这就需要混流转码
 * 在连麦场景下，需要将主播和连麦观众音视频流混成一路标准的直播流，供CDN观众观看
 * 在PK场景下，需要将进行PK的多个主播的音视频流混成一路标准的直播流，供CDN观众观看
 * @param config 参考AlivcLiveDef.h中关于{@link AlivcLiveTranscodingConfig}的介绍，如果传入nil，则取消云端混流转码
 * @return 0:success  非0:failure
 * @note 若主播还在房间中但不再需要混流，请务必传入 nil 进行取消，因为当发起混流后，云端混流模块就会开始工作，
 * 不及时取消混流可能会引起不必要的计费损失
 */

/****
 * @brief Set mixed-stream transcoding parameters
 * There may be more than one streamer in a live room, and each streamer has a separate audio and video stream
 * However, viewers may just want to watch one stream. Therefore, you need to mix multiple audio and video streams
 * into one standard live stream, which requires mixed-stream transcoding
 * In co-streaming scenarios, you need to mix the audio and video streams of the streamer and co-streamer into a standard live stream for viewers to watch
 * In battle scenarios, you need to mix the audio and video streams of multiple streamers engaging in the battle into a standard live stream for viewers to watch
 * @param config Refer to the description about AlivcLiveTranscodingConfig in the AlivcLiveDef.h file
 * If you pass nil to the parameter, mixed-stream transcoding is disabled
 * @return
 *  0:success
 *  != 0:failure
 * @note If the streamer is still streaming but stream mixing is no longer required, be sure to pass nil to the parameter to disable mixed-stream transcoding.
 * When the feature is enabled, the mixed-stream transcoding module continues to work, which may incur unnecessary fees for you.
 */
- (int)setLiveMixTranscodingConfig:(AlivcLiveTranscodingConfig *)config;

/**
 * @brief 禁用或启用本地视频采集（非互动模式暂不支持该API，调用无任何效果）
 * @param enabled
 * - YES : 启用本地视频采集
 * - NO : 禁用本地视频采集
 * @return
 * - 0 : 成功
 * - < 0 : 失败
 * @note 摄像头采集会被关闭掉
 */

/****
 * @brief Disable or enable local video capture
 * @param enabled
 * - YES : Enable local video capture
 * - NO : Disable local video capture
 * @return
 * - 0 : Success
 * - < 0 : Failure
 * @note Camera capture will be turned off
 */
- (int)enableLocalCamera:(BOOL)enabled;

/**
 * @brief 关闭/打开视频（非互动模式暂不支持该API，调用无任何效果）
 * @param mute  YES表示不发送视频数据；NO表示恢复正常
 * @return
 * - 0: 表示Success
 * - 非0: 表示Failure
 * @note 发送黑色的视频帧。采集，编码，发送模块仍然工作，只是视频内容是黑色帧
 */

/****
 * @brief Specify whether to disable video capture from the camera. (This method is not supported in basic mode.)
 * @param mute  YES No video data is sent from the camera.；NO Video data is sent from the camera.
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)muteLocalCamera:(BOOL)mute;

/**
 * @brief 设置音频输出为听筒还是扬声器
 * @param enable
 * - YES: 扬声器模式(默认)
 * - NO: 听筒模式
 * @return
 * - 0: 成功
 * - <0: 失败
 */

/****
 * @brief Set the headset or speaker as the audio output device
 * @param enable YES: (Default) Speaker; NO:Headset
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)enableSpeakerphone:(BOOL)enable;

/**
 * @brief 获取当前音频输出为听筒还是扬声器
 * @return
 * - YES: 扬声器模式；
 * - NO: 听筒模式
 */

/****
 * @brief Query whether the current audio output device is the headset or the speaker
 * @return - YES: Speaker；- NO: Headset
 */
- (BOOL)isEnableSpeakerphone;

/**
 * @brief 刷新Token鉴权信息，传入一个新的推流URL，包含未过期的新token信息，房间ID/用户ID/sdkAppId需要和之前保持一样
 * @details 该方法用于更新鉴权信息推流URL中的token信息，主要为了防止鉴权过期，导致推流失败，当我们收到  onPushURLTokenWillExpire 回调时，应用应当更新鉴权信息
 * @param pushURL 推流URL
 * @return
 * - 0: 成功
 * - <0: 失败
 */

/****
 * @brief Refresh the authentication information, pass in a new streaming URL, including token information that has not expired,
 * and the room ID/user ID/sdkAppId need to be the same as before
 * @details This method is used to update the token information in the push URL of the authentication information,
 *  mainly to prevent the authentication from expiring and causing the push to fail. When we receive
 *  the onPushURLTokenWillExpire callback, the application should update the authentication information
 * @param pushURL push URL
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)refreshPushURLToken:(NSString *_Nonnull)pushUrl;

/**
 * @brief 摄像头是否支持人脸聚焦
 * @return
 * - YES: 支持
 * - NO: 不支持
 * @note 在camera没有打开的情况下返回 NO，
 *    在camera打开的情况下，如果当前camera同时支持人脸识别和对焦功能则返回 YES
*/

/****
 * @brief Does the camera support face focusing?
 * @note Return NO if the camera is not open, and return YES if the current camera supports both face recognition and
 * focus functions if the camera is open
 * @return
 * - YES: success
 * - NO: failure
 */
- (BOOL)isCameraAutoFocusFaceModeSupported;

/**
 * @brief 设置摄像头人脸对焦
 * @param enable  YES: 开启; NO:关闭
 * @return
 * - YES: 成功
 * - NO: 失败
 * @note 如果  isCameraAutoFocusFaceModeSupported 返回 YES
 *      且此调用enable为 YES 的情况下，实时对焦到采集到数据的人脸上
*/

/****
 * @brief Set camera face focus
 * @param enable  YES: open; NO:close
 * @return
 * - YES: success
 * - NO: failure
*/
- (BOOL)setCameraAutoFocusFaceModeEnabled:(BOOL)enable;

/**
 * @brief 设置音量回调频率和平滑系数
 * @param interval 时间间隔，单位毫秒，最小值不得小于10ms, 建议设置300-500ms, <= 0表示不启用音量提示和说话人提示功能
 * @param smooth 平滑系数，数值越大平滑程度越高，反之越低，实时性越好，建议设置3，范围[0, 9];
 * @param reportVad 说话人检测开关
 * - 1: 打开本地人声检测
 * - 0: 关闭本地人声检测
 * @return
 *  - 0: 成功
 *  - <0: 失败
 * @note 设置之后，音频音量和说话人uid会分别通过 {@link AlivcLivePusherInfoDelegate::onMicrophoneVolumeUpdate:volume: }回调
 * @note 可以通过调用该接口及相关回调，可以实现声音波纹效果
 */
- (int)enableAudioVolumeIndication:(int)interval smooth:(int)smooth reportVad:(int)reportVad;

/**
 * @brief 添加水印(互动模式下使用该接口添加水印)
 * @note 水印位置是通过 rect 参数来指定，rect 是一个四元组参数，其格式为 (x，y，width，height)，其中x和y是水印的坐标，取值范围为0 1的浮点数。width：水印的宽度，取值范围为0 - 1的浮点数，height：不需要设置的，SDK 内部会根据水印图片的宽高比自动计算高度。
 * 例如：当推流分辨率是 720 × 1280时，rect 参数为（0.1，0.1，0.3，0.0），则水印的左上角坐标点就是（720 × 0.1，1280 × 0.1）即（72，128），水印的宽度是720x0.3=216，水印高度是根据水印图片的宽高比自动算出来。
 * @param  image 水印图片， 使用透明底色的 png 格式。
 * @param rect 水印相对于推流分辨率的相对坐标，x，y，width，height 取值范围0 - 1。
 */
- (void)setWatermark:(nullable UIImage *)image rect:(CGRect)rect;

/**
 * @brief 开启本地音视频流录制
 * @note 开启后把直播中的音视频内容录制到本地的一个文件。调用接口后，通过onMediaRecordEvent回调通知录制状态
 * @param config 本地录制参数，参见AlivcLiveLocalRecoderConfig
 */

/****
 * @brief Enable local media recording
 * @note After turning it on, record the audio and video content in the live broadcast to a local file. After calling the interface, the recording status is notified through the onMediaRecordEvent callback.
 * @param config Local recording parameters, see AlivcLiveLocalRecoderConfig
 */
- (BOOL)startRecording:(AlivcLiveLocalRecoderConfig *_Nullable)config;

/**
 * @brief 停止本地音视频流录制
 * @note 如果录制任务在结束推流前尚未通过本接口停止，则结束推流后录制任务会自动被停止。
*/

/****
 * @brief Stoplocal media recording
 * @note If the recording task has not been stopped through this interface before the streaming is ended, the recording task will be automatically stopped after the streaming is ended.
*/
- (void)stopRecording;

/**
 * @brief 启动屏幕分享
 * @note 直播连麦场景开启第二路视频推送，可以通过setExternalVideoSource设置外部视频源，通过pushExternalVideoFrame向第二路视频通道输入视频数据
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Start screen share
 * @return
 * - YES: success
 * - NO: failure
*/
- (int)startScreenShare;

/**
 * @brief 停止屏幕分享
 * @note 停止第二路视频推送
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief stop screen share
 * @return
 * - YES: success
 * - NO: failure
*/
- (int)stopScreenShare;

/**
 * @brief 开启第二路音频流推送
 * @note 开启后第二路音频流推送后，可以调用addExternalAudioStream添加音频数据源，使用pushExternalAudioStream向第二路音频通道输入音频数据基础
 * @note 直播连麦场景使用，基础直播不可用
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Enable the second audio stream push
 * @note After the second audio stream is turned on and pushed, you can call addExternalAudioStream to add an audio data source, and use pushExternalAudioStream to input audio data to the second audio channel.
 * @return
 * - 0：成功
 * - 非0：失败
 */
- (int)startLocalDualAudioStream;

/**
 * @brief 停止第二路音频流推送
 * @note 直播连麦场景使用，基础直播不可用
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Stop pushing the second audio stream
 * @return
 * - YES: success
 * - NO: failure
 */
- (int)stopLocalDualAudioStream;

/**
 * @brief 设置音频profile
 * @param audio_profile 音频采集/编码模式参数, 详见AlivcLiveAudioProfile
 * @return
 * - 0: 成功
 * - 其他: 失败
 * @note 只支持  startPushWithURL 前设置有效；
 */

/****
 * @brief set audio profile
 * @param audio_profile Audio capture/encoding mode parameters, see for details  AlivcLiveAudioProfile
 * @return
 * @return
 * - YES: success
 * - NO: failure
 * @note Only valid settings before startPushWithURL are supported;
 */
- (int)setAudioProfile:(AlivcLiveAudioProfile)audio_profile;







/**
 * @brief 获取当前视频编码格式
 * @return
 * - AlivcLivePushVideoEncoderModeHardCodecH264: H264
 * - AlivcLivePushVideoEncoderModeHardCodecHEVC: HEVC
 */

/****
 * @brief Get the current video encoding format
 * @return
 * - AlivcLivePushVideoEncoderModeHardCodecH264: H264
 * - AlivcLivePushVideoEncoderModeHardCodecHEVC: HEVC
 */
- (AlivcLivePushVideoEncoderModeHardCodec)getVideoCodecType;


/**
 * @brief 关闭音频采集
 * @note 调用此接口后，采集设备关闭
 * @note 调用此接口，关闭音频采集，不再占用系统麦克风权限，且不再发送音频数据
 * @note 如果调用此接口后系统仍显示有麦克风权限的占用，请检查是否由其它功能引起
 * @note 开启音频采集，对应接口：{@link AlivcLivePusher::startAudioCapture:}
 * @note 如果只需要静音，不关闭音频采集，请参考以下接口：{@link AlivcLivePusher::setMute: }
 */

/****
 * @brief Stop microphone capture
 * @note After calling this interface, the  microphone device is closed
 * @note Call this interface to turn off audio collection, no longer occupy system microphone permissions, and no longer send audio data
 * @note If the system still shows microphone permission occupied after calling this interface, please check if it is caused by other functions
 * @note startAudioCapture, corresponding to the interface: {@link AlivcLivePusher::startAudioCapture:}
 * @note If you only need to mute without turning off audio capture, please refer to the following interfaces: {@link AlivcLivePusher::setMute:  }
 */
- (void)stopAudioCapture;

/**
 * @brief 开启音频采集
 * @param keepAlive YES: 停止推流后麦克风采集设备保持开启状态；NO: 停止推流后麦克风采集设备关闭
 * @note 调用此接口，开始采集音频数据并发送，将会占用系统麦克风权限
 * @note 关闭音频采集，对应接口：{@link AlivcLivePusher::stopAudioCapture }
 * @note 如果只需要静音，不关闭音频采集，请参考以下接口：{@link AlivcLivePusher::setMute: }
 */

/****
 * @brief Start microphone capture
 * @param keepAlive YES:
 The microphone  device remains on after stopping push ；NO: The microphone  device is turned off after stopping push
 * @note Calling this interface to start audio capture and transmission, it will occupy system microphone permissions
 * @note stopAudioCapture, corresponding to the interface: {@link AlivcLivePusher::stopAudioCapture}
 * @note If you only need to mute without turning off audio capture, please refer to the following interfaces: {@link AlivcLivePusher::setMute:  }
 */
- (void)startAudioCapture:(BOOL)keepAlive;

/**
 * @brief 开启音频播放
 * @note 此接口可以控制提前打开音频播放，如果不设置，则SDK会在订阅到音频流后自动打开音频播放
 */

/****
 * @brief Enable audio playback
 * @note This interface can control the opening of audio playback in advance. If not set, the SDK will automatically open audio playback after subscribing to the audio stream.
 */
- (void)startAudioPlayer;

/**
 * @brief 关闭音频播放
 * @note 此接口可以控制关闭音频播放，与 {@link startAudioPlayer} 对应
 */

/****
 * @brief Turn off audio playback
 * @note This interface can control turning off audio playback, corresponding to {@link startAudioPlayer}
 */
- (void)stopAudioPlayer;

/**
 * @brief 设置频道模式
 * @details 根据业务需求可以配置不同的频道模式，AliRTC会根据不用的频道模式模式采用不用的策略，目前主要提供通信模式(默认)、互动模式、低延迟互动直播模式
 *
 * @param profile 频道模式类型, 详细请参考  AlivcLiveChannelProfile
 * @return
 * - 0: 成功
 * - 非0: 失败
 *
 * @note
 *  - 该方法只在startPushWithURLAsync前调用有效，推流中不可以重新设置，stopPush 后可以重新设置
 */
- (int)setChannelProfile:(AlivcLiveChannelProfile)profile;

/**
 * @brief 通过数据通道发送自定义消息
 *
 * @param message 自定义消息
 * @return
 * - 0: 成功
 * - 非0: 失败
 */
- (int)sendDataChannelMessage:(NSString *)message;


/**
 * @brief 获取自定义参数
 * @param param   自定义参数
 * @return 自定义参数值
 */
- (NSString *)getParameter:(NSString *)param;

/**
* @brief 获取当前使用的编码器类型,如未开始推流，返回无效类型
* @param isCameraStreem YES: 获取摄像头流的编码器类型;  NO: 获取共享流的编码器类型
* @return AlivcLiveVideoCodecManufacturer 编码器类型
*/
- (AlivcLiveVideoCodecManufacturer)getCurrentEncoderManufacturer:(BOOL)isCameraStreem;

/**
 * @brief 播放背景音乐
 * @param path 背景音乐路径
 * @param config 背景音乐播放配置
 * @return 0:success  非0:failure
 */

/****
 * @brief Play background music
 * @param path The path of the background music
 * @param config The config of the background music
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)startBGMWithMusicPathAsync:(NSString *)path config:(AlivcLiveBGMConfig *_Nonnull)config;

/**
 * @brief 获取伴奏文件时长, 单位为毫秒
 * @return
 * - >=0: 伴奏文件时长
 * - <0: 返回错误码
 */

/****
 * @brief Get the duration of the music file, in milliseconds
 * @return
 * - >=0: Music file duration
 * - <0: Return error code
 */
- (int)getBGMDuration;

/**
 * @brief 获取伴奏文件播放进度，单位为毫秒
 * @return
 * - >=0: 伴奏文件播放进度
 * - <0: 返回错误码
 */

/****
 * @brief Get the music file playback progress, in milliseconds
 * @return
 * - >=0: Music file playback progress
 * - <0: Return error code
 */
- (int)getBGMCurrentPosition;

/**
 * @brief 启用外部视频输入源
 * @param enable
 * - YES 开启
 * - NO 关闭
 * @param type 流类型，详见 AliLiveVideoSource
 * - AliLiveVideoSourceCameraType 外部输入视频数据走相机流通道，如果当前相机采集打开中，调用该接口设置enable为YES，sdk会替换掉相机采集
 * - AliLiveVideoSourceScreenShareType 外部输入视频数据走屏幕流通道，如果当前屏幕共享采集打开中，调用该接口设置enable为YES，sdk会替换掉屏幕共享采集
 * @param renderMode 处理模式，外部输入视频源宽高比和推流profile不一致时，会按照对应的rendermode做对应处理，详见AliLiveRenderMode
 * - AliLiveRenderModeAuto 自动（默认） 如果外部输入的视频宽高比和推流设置的宽高比不一致时，维持外部输入的视频宽高比，等比例缩放宽高到推流设置的宽高范围内，注意此模式下为了保证原始视频的比例和内容完整性，会导致实际推流的分辨率和设置的不一致
 * - AliLiveRenderModeStretch 拉伸平铺，如果外部输入的视频宽高比和推流设置的宽高比不一致时，将输入视频拉伸到推流设置的比例，画面会变形
 * - AliLiveRenderModeFill 填充黑边，如果外部输入的视频宽高比和推流设置的宽高比不一致时，将输入视频上下或者左右填充黑边
 * - AliLiveRenderModeCrop 裁剪，如果外部输入的视频宽高比和推流设置的宽高比不一致时，将输入视频宽或者高进行裁剪，画面内容会丢失
 * @return
 * - 0: 成功
 * - 非0: 失败
 * @note 通过pushExternalVideoFrame接口向SDK 输入自定义数据
*/

/****
 * @brief Enable external video input source
 * @param enable
 * - YES turn on
 * - NO turn off
 * @param type stream type，see AliLiveVideoSource
 * - AliLiveVideoSourceCameraType external input video data goes through the camera stream channel. If the current camera collection is open, call this interface and set enable to YES, and the SDK will replace the camera collection.
 * - AliLiveVideoSourceScreenShareType external input video data goes through the screen stream channel. If the current screen sharing collection is open, call this interface and set enable to YES, and the SDK will replace the screen sharing collection.
 * @param renderMode render mode. When the aspect ratio of the external input video source is inconsistent with the push profile, the corresponding rendermode will be used for processing. For details, see AliLiveRenderMode
 * - AliLiveRenderModeAuto auto（default） If the aspect ratio of the externally input video is inconsistent with the aspect ratio of the push setting, the aspect ratio of the external input video is maintained and the width and height are scaled proportionally to the width and height range of the push setting. Note that in this mode, in order to ensure the original The proportion and content integrity of the video will lead to inconsistencies in the actual resolution and settings of the stream.
 * - AliLiveRenderModeStretch Stretch Mode, if the aspect ratio of the external input video is inconsistent with the aspect ratio set by the push stream, the input video will be stretched to the ratio set by the push stream, and the picture will be deformed.
 * - AliLiveRenderModeFill Fill black borders. If the aspect ratio of the external input video is inconsistent with the aspect ratio set by the push stream, the input video will be filled with black borders on the top, bottom or left and right.
 * - AliLiveRenderModeCrop Cropping, if the aspect ratio of the external input video is inconsistent with the aspect ratio of the push setting, the width or height of the input video will be cropped, and the screen content will be lost.
 * @return
 *  0:success
 *  != 0:failure
 * @note Enter custom data into the SDK through the pushExternalVideoFrame interface
*/
- (int)setExternalVideoSource:(BOOL)enable sourceType:(AliLiveVideoSource)type renderMode:(AliLiveRenderMode)renderMode;

/**
 * @brief 输入视频数据
 * @param frame 帧数据，详见 AlivcLiveVideoDataSample
 * @param type 流类型，详见 AliLiveVideoSource
 * - AliLiveVideosourceCameraType 外部输入视频数据走相机流通道
 * - AliLiveVideosourceScreenShareType 外部输入视频数据走屏幕流通道
 *  @return
 * - 0: 成功
 * - 非0: 失败
 * @note 如果返回值为0x01070102，代表当前buffer队列塞满，需要等待后再继续输送数据
*/

/****
 * @brief input video raw data
 * @param frame video raw data，see AlivcLiveVideoDataSample
 * @param type stream type，see AliLiveVideoSource
 * - AliLiveVideosourceCameraType external input video data goes through the camera stream channel
 * - AliLiveVideosourceScreenShareType external input video data goes through the screen stream channel
 *  @return
 *  0:success
 *  != 0:failure
 * @note If the return value is 0x01070102, it means that the current buffer queue is full and you need to wait before continuing to transmit data.
*/
- (int)pushExternalVideoFrame:(AlivcLiveVideoDataSample *_Nonnull)frame sourceType:(AliLiveVideoSource)type;

/**
 * @brief 设置是否启用外部音频输入源
 * @param enable YES:开启; NO:关闭
 * @param sampleRate 采样率 16k, 48k...
 * @param channelsPerFrame 声道数 1:单声道; 2:双声道
 * @return
 * - >=0: 成功
 * - <0: 失败
 */

/****
 * @brief Set whether to enable external audio input source
 * @param enable YES: Enable; NO: Disable
 * @param sampleRate samplerate 16k, 48k...
 * @param channelsPerFrame Channels: 1: mono; 2:stereo
 * @return
 * - >=0: success
 * - <0: failure
 */
- (int)setExternalAudioSource:(BOOL)enable withSampleRate:(NSUInteger)sampleRate channelsPerFrame:(NSUInteger)channelsPerFrame;

/**
 * @brief 新增外部音频流
 * @param config 外部音频流配置
 * @return
 * - <=0: 表示失败;
 * - >0: 表示成功;
 * - 返回值为 外部音频流Id
 * @note 通过pushExternalAudioStream接口向SDK 输入自定义数据
 */

/****
 * @brief add external audio stream
 * @param config external audio stream configuration
 * @return
 * - <=0: failed;
 * - >0:  success;
 * - The return value is the external audio stream Id.
 * @note Input custom data to the SDK through the pushExternalAudioStream interface
 */
- (int)addExternalAudioStream:(AliLiveExternalAudioStreamConfig *_Nonnull)config;

/**
 * @brief 输入外部音频流数据
 * @param streamId 外部音频流Id（addExternalAudioStream的返回值）
 * @param audioFrame 音频数据
 * @return
 * - <0: 表示失败;
 * - 0: 表示成功;
 * - 返回值为0x01070101 时，需要在间隔投递数据时间长度后再次重试投递
 * @note 为了保证语音连续性，sdk内部会有buffer缓存送进来的音频数据，以每次送10ms数据为例，如果返回 0x01070101 时，说明内部缓冲区已满，建议等待20ms后再重新送当前数据帧；
 */

/****
 * @brief Input external audio stream data
 * @param streamId external audio stream ID（addExternalAudioStream return）
 * @param audioFrame audio data
 * @return
 * - <0:failed;
 * - 0:success;
 * - When the return value is 0x01070101, you need to retry delivery after the interval of data delivery time.
 * @note In order to ensure voice continuity, there will be a buffer buffer inside the SDK to buffer the audio data sent in. Taking 10ms of data sent each time as an example, if 0x01070101 is returned, it means that the internal buffer is full. It is recommended to wait for 20ms before resending the current data frame;
 */
- (int)pushExternalAudioStream:(int)streamId
                       rawData:(AlivcLivePusherAudioDataSample * _Nonnull)audioFrame;

/**
 * @brief 设置是否与麦克风采集音频混合
 * @param mixed YES：混音；NO：完全替换麦克风采集数据
 * @return
 * - 0: 成功
 * - 非0: 失败
 */

/****
 * @brief Set whether to mix audio collected with the microphone
 * @param mixed YES：mix；NO：Completely replace the microphone to collect data
 * @return
 * - <0:failed;
 * - 0:success;
 */
- (int)setMixedWithMic:(BOOL)mixed;

/**
 * @brief 设置外部音频流播放音量
 * @param streamId 外部音频流Id
 * @param playoutVolume 播放音量，取值范围[0, 100]
 * @return
 * - <0: 表示失败;
 * - 0: 表示成功;
 */

/****
 * @brief Set external audio stream playback volume
 * @param streamId external audio stream ID
 * @param playoutVolume Playback volume, value range [0, 100]
 * @return
 * - <0:failed;
 * - 0:success;
 */
- (int)setExternalAudioStream:(int)streamId
                playoutVolume:(int)playoutVolume;

/**
 * @brief 设置外部音频流推流音量
 * @param streamId 外部音频流Id
 * @param publishVolume 推流音量，取值范围[0, 100]
 * @return
 * - <0: 表示失败;
 * - 0: 表示成功;
 */

/****
 * @brief Set external audio streaming volume
 * @param streamId external audio stream ID
 * @param publishVolume Push volume, value range [0, 100]
 * @return
 * - <0:failed;
 * - 0:success;
 */
- (int)setExternalAudioStream:(int)streamId
                publishVolume:(int)publishVolume;

/**
 * @brief 删除外部音频流
 * @param streamId 外部音频流Id
 * @return
 * - <0: 表示失败;
 * - 0: 表示成功;
 */

/****
 * @brief Remove external audio stream
 * @param streamId external audio stream ID
 * @return
 * - <0:failed;
 * - 0:success;
 */
- (int)removeExternalAudioStream:(int)streamId;

/**
 * @brief 设置视频自定义分辨率(直播连麦场景可用，基础直播不可用)
 * @param videoSize 视频宽高
 * @return
 * - <0: 表示失败;
 * - 0: 表示成功;
 */
- (int)setCustomVideoResolution:(CGSize)videoSize;

/**
 * @brief 设置音频回调参数
 * @param enable 是否允许数据回调
 * @param audioSource 回调数据源类型，详见 AliLiveAudioSource
 * @param config 回调参数设置，详见AliLiveAudioFrameObserverConfig, null时默认参数为48000，1，ReadOnly
 * @details
 *  - AliLiveAudioSourcePub、AliLiveAudioSourceMixedAll只支持ReadOnly模式
 *  - AliLiveAudioSourceRemoteUser不支持修改采样率、通道数
 * @return 0: sucess
 *
 */
- (int)enableAudioFrameObserver:(bool)enable audioSource: (AliLiveAudioSource)audioSource config:(AliLiveAudioFrameObserverConfig*_Nullable)config;


/**
 * @brief 设置相机流视频编码属性
 * @details 该方法用于设置相机流视频编码属性对应的视频参数，如分辨率、帧率、码率等
 * 所有设置的参数都有相应的范围限制，如果设置的参数不在有效范围内，SDK会自动调节
 * @param config 预定义的编码属性，详见 {@link AliLiveVideoEncoderConfiguration}
*/

/****
 * @brief Set the camera stream video encoding properties
 * @details This method is used to set the video parameters corresponding to the camera stream video encoding properties, such as resolution, frame rate, bit rate, etc.
 * All set parameters have corresponding range limits. If the set parameters are not within the valid range, the SDK will automatically adjust
 * @param config Predefined encoding properties, see {@link AliLiveVideoEncoderConfiguration}
*/
- (void)setVideoEncoderConfiguration:(AliLiveVideoEncoderConfiguration* _Nonnull)config;

/**
 * @brief 设置自定义参数
 * @param param   自定义参数
 * @return
 * - 0: 成功
 * - 非0: 失败
 */

/****
 * @brief Set custom parameters
 * @param param   Custom parameters
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setParameter:(NSString * _Nonnull)param;


/**
 * @brief 订阅视频数据
*/
- (void)registerVideoSampleObserver;

/**
 * @brief 取消订阅视频数据，调用后onProcessVideoSampleBuffer不回回调
*/
- (void)unregisterVideoSampleObserver;

/**
 * @brief 设置预览和推流镜像能力
 * @param mirrorMode 设置镜像的模式
 * @return
 * - 0: 设置成功
 * - <0: 设置失败
 *
 * @note
 * - 此接口在入会前和入会后均可以动态设置，SDK内部会记录状态，并在可以操作预览及编码的时候对视频进行操作；
 * - 此接口与setPreviewMirror & setPushMirror里面的mirror重合，使用时只要使用其中一个即可
 */

/****
 * @brief Set up preview and pushing mirror
 * @param mirrorMode mirror mode
 * @return
 *  0:success
 *  != 0:failure
 *
 * @note
 * - This interface can be dynamically set before and after joining the meeting. The SDK will record the status internally and operate the video when preview and encoding can be operated;
 * - This interface overlaps with the mirror in setPreviewMirror & setPushMirror. You only need to use one of them when using it.
 */
- (int)setVideoMirrorMode:(AliLiveVideoPipelineMirrorMode)mirrorMode;

#pragma mark - "音乐伴奏音效"
/**
 * @brief 设置变调参数
 * @param value 变调参数，范围：[0.5, 2.0]，1.0表示音调不变，小于1.0表示音调降低，大于1.0表示音调升高，默认1.0
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Set audio pitch parameters
 * @param value  audio pitch parameters，value：[0.5, 2.0]，1.0 means the pitch remains unchanged, less than 1.0 means the pitch decreases, greater than 1.0 means the pitch increases, the default is 1.0
 * @return
 * - YES: success
 * - NO: failure
 */
- (int)setAudioEffectPitchValue:(double)value;

/**
 * @brief 设置变声音效模式
 * @param mode 参考AlivcLivePushAudioEffectVoiceChangerMode对应的变声音效模式值
 * @return
 * - 0：成功
 * - 非0：失败
 * @note 推流前和推流过程中调用都生效
 */

/****
 * @brief Set the voice change mode
 * @param mode Reference  AlivcLivePushAudioEffectVoiceChangerMode Values that specify the voice change effects.
 * @return
 *  0:success
 *  != 0:failure
 * @note You can call this method before or during live push.
 */
- (int)setAudioEffectVoiceChangeMode:(AlivcLivePushAudioEffectVoiceChangeMode)mode;

/**
 * @brief 设置混响音效模式
 * @param mode 参考AlivcLivePushAudioEffectReverbMode 对应的混响模式
 * @return
 * - 0：成功
 * - 非0：失败
 * @note 推流前和推流过程中调用都生效
 */

/****
 * @brief Set the reverberation mode
 * @param mode Reference AlivcLivePushAudioEffectReverbMode Values that specify the reverberation effects.
 * @return
 *  0:success
 *  != 0:failure
 * @note You can call this method before or during live push.
 */
- (int)setAudioEffectReverbMode:(AlivcLivePushAudioEffectReverbMode)mode;

/**
 * @brief 设置美声音效模式
 * @param mode 参考 AliLiveAudioEffectBeautifyMode 对应的美声模式
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Set the sound mode
 * @param mode see AliLiveAudioEffectBeautifyMode
 * @return
 * - YES: success
 * - NO: failure
 */
- (int)setAudioEffectBeautifyMode:(AliLiveAudioEffectBeautifyMode)mode;

/**
 * @brief 设置混响音效类型
 * @param type 参考AliLiveAudioEffectReverbParamType 对应的混响类型
 * @param value 混响参数值，不同混响类型的取值范围参考 AliLiveAudioEffectReverbParamType中取值说明
 * @return
 * - 0：成功
 * - 非0：失败
 * @note 需要在 setAudioEffectReverbMode之后调用
 */

/****
 * @brief Set the reverb audio effect type
 * @param type see  AliLiveAudioEffectReverbParamType
 * @param value
 * @return
 * - YES: success
 * - NO: failure
 */
- (int)setAudioEffectReverbParamType:(AliLiveAudioEffectReverbParamType)type value:(float)value;

/**
 * @brief 设置均衡器参数
 * @param bandIndex 均衡器段数[0,9]  center frequency [31,62,125,250,500,1000,2000,4000,8000,16000] Hz AliLiveAudioEffectEqualizationBandFrequency
 * @param gain 均衡器增益db   [-15,15]  default 0
 * @return
 * - 0：成功
 * - 非0：失败
 * @note 需要在 setAudioEffectBeautifyMode 之后调用
 */
- (int)setAudioEffectEqualizationParam:(AliLiveAudioEffectEqualizationBandFrequency)bandIndex gain:(float)gain;


/**
 * @brief 预加载音效文件
 * @param soundId 用户给该音效文件分配的ID
 * @param filePath 音效文件路径，支持本地文件和网络url
 * @return
 * - 0：成功
 * - 非0：失败
 * @note 音效相关接口为同步接口, 建议使用本地文件
 */

/****
 * @brief Preload audio effect files
 * @param soundId The ID assigned by the user to the audio effect file
 * @param filePath audio effect file path, supports local files and network URLs
 * @return
 * - 0：success
 * - 非0：failure
 * @note The audio effect related interface is a synchronous interface. It is recommended to use local files.
 */
- (int)preloadAudioEffectWithSoundId:(NSInteger)soundId filePath:(NSString *_Nonnull)filePath;

/**
 * @brief 删除预加载的音效文件
 * @param soundId 用户给该音效文件分配的ID
 * @return
 * - 0：成功
 * - !=0：失败
 * @note 音效soundId应与预加载 {@link preloadAudioEffectWithSoundId:filePath:} 时传入的ID相同
 */

/****
 * @brief Delete preloaded audio effect files
 * @param soundId The ID assigned by the user to the audio effect file
 * @return
 * - 0：success
 * - !=0：failure
 * @note The audio effect soundId should be the same as the ID passed in when preloading {@link preloadAudioEffectWithSoundId:filePath:}
 */
- (int)unloadAudioEffectWithSoundId:(NSInteger)soundId;

/**
 * @brief 开始播放音效
 * @details 开始播放音效接口，可以多次调用该方法传入不同的soundId和filePath，同时播放多个音效文件，音效文件播放结束后，SDK 会触发 {@link onAudioEffectFinished:} 回调
 * @param soundId 用户给该音效文件分配的ID，每个音效均有唯一的ID，如果你已通过 {@link preloadAudioEffectWithSoundId:filePath:} 将音效加载至内存，确保这里的soundId与 {@link preloadAudioEffectWithSoundId:filePath:} 设置的soundId相同
 * @param filePath 文件路径，支持本地文件和网络url
 * @param config 音效播放配置，详见{@link AliLiveAudioEffectConfig}
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Start playing audio effects
 * @details Start playing the audio effect interface. You can call this method multiple times to pass in different soundId and filePath to play multiple audio effect files at the same time. After the audio effect file is played, the SDK will trigger the {@link onAudioEffectFinished:} callback.
 * @param soundId The ID assigned by the user to the audio effect file. Each audio effect has a unique ID. If you have loaded the audio effect into memory through {@link preloadAudioEffectWithSoundId:filePath:}, make sure the soundId here is set with {@link preloadAudioEffectWithSoundId:filePath:} The soundId is the same
 * @param filePath File path, supports local files and network URLs
 * @param config Audio effect playback configuration, see {@link AliLiveAudioEffectConfig} for details
 * @return
 * - 0：success
 * - !=0：failure
 */

- (int)playAudioEffectWithSoundId:(NSInteger)soundId filePath:(NSString *_Nonnull)filePath config:(AliLiveAudioEffectConfig *_Nonnull)config;


/**
 * @brief 停止播放音效
 * @param soundId 用户给该音效文件分配的ID，每个音效均有唯一的ID，如果你已通过 {@link preloadAudioEffectWithSoundId:filePath:} 将音效加载至内存，确保这里的soundId与 {@link preloadAudioEffectWithSoundId:filePath:} 设置的soundId相同
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Stop playing audio effects
 * @param soundId The ID assigned by the user to the audio effect file. Each audio effect has a unique ID. If you have loaded the audio effect into memory through {@link preloadAudioEffectWithSoundId:filePath:}, make sure the soundId here is set with {@link preloadAudioEffectWithSoundId:filePath:} The soundId is the same
 * @return
 * - 0：success
 * - !=0：failure
 */
- (int)stopAudioEffectWithSoundId:(NSInteger)soundId;

/**
 * @brief 停止播放所有音效
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Stop playing all audio effect
 * @return
 * - 0：success
 * - !=0：failure
 */
- (int)stopAllAudioEffects;

/**
 * @brief 设置音效推流混音音量
 * @param soundId 用户给该音效文件分配的ID
 * @param volume 推流混音音量，范围是：[0, 100]，默认值：50
 * @return
 * - 0：成功
 * - 非0：失败
 * @note 该方法需要在 {@link playAudioEffectWithSoundId:filePath:config:} 后调用
 */

/****
 * @brief Set audio effect push mixing volume
 * @param soundId The ID assigned by the user to the audio effect file
 * @param volume Push mix volume, range is: [0, 100], default value: 50
 * @return
 * - 0：success
 * - !=0：failure
 * @note This method needs to be called after {@link playAudioEffectWithSoundId:filePath:config:}
 */
- (int)setAudioEffectPublishVolumeWithSoundId:(NSInteger)soundId volume:(NSInteger)volume;

/**
 * @brief 获取音效推流混音音量
 * @param soundId 用户给该音效文件分配的ID
 * @return
 * - [0, 100]：音效推流混音音量
 * - 其他：错误值
 * @note 音效推流混音音量有效范围为：[0, 100]，该方法需要在  {@link playAudioEffectWithSoundId:filePath:config:} 后调用
 */

/****
 * @brief Get the audio effect push mixing volume
 * @param soundId The ID assigned by the user to the audio effect file
 * @return
 * - [0, 100]：audio effect push mixing volume
 * - Other: error value
 * @note The valid range of audio effect push mixing volume is: [0, 100]. This method needs to be called after {@link playAudioEffectWithSoundId:filePath:config:}
 */
- (int)getAudioEffectPublishVolumeWithSoundId:(NSInteger)soundId;

/**
 * @brief 设置音效本地播放音量
 * @param soundId 用户给该音效文件分配的ID
 * @param volume 音效本地播放音量，范围：[0, 100]，默认值：50
 * @return
 * - 0：成功
 * - 非0：失败
 * @note 该方法需要在 {@link playAudioEffectWithSoundId:filePath:cycles:publish:} 后调用
 */

/****
 * @brief Set the local playback volume of audio effects
 * @param soundId The ID assigned by the user to the audio effect file
 * @param volume playback mix volume, range is: [0, 100], default value: 50
 * @return
 * - 0：success
 * - !=0：failure
 * @note This method needs to be called after {@link playAudioEffectWithSoundId:filePath:config:}
 */
- (int)setAudioEffectPlayoutVolumeWithSoundId:(NSInteger)soundId volume:(NSInteger)volume;

/**
 * @brief 获取音效本地播放音量
 * @param soundId 用户给该音效文件分配的ID
 * @return
 * - [0, 100]：音效本地播放音量
 * - 其他：错误值
 * @note 音效本地播放音量有效范围为：[0, 100]，该方法需要在 {@link playAudioEffectWithSoundId:filePath:cycles:publish:} 后调用
 */

/****
 * @brief Get the local playback volume of audio effects
 * @param soundId The ID assigned by the user to the audio effect file
 * @return
 * - [0, 100]：audio effect push mixing volume
 * - Other: error value
 * @note The valid range of audio effect push mixing volume is: [0, 100]. This method needs to be called after {@link playAudioEffectWithSoundId:filePath:config:}
 */
- (int)getAudioEffectPlayoutVolumeWithSoundId:(NSInteger)soundId;

/**
 * @brief 设置所有音效本地播音量
 * @param volume 音效本地播放音量，范围：[0, 100]，默认值：50
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Set the local playback volume of all audio effects
 * @param volume Audio effect local playback volume, range: [0, 100], default value: 50
 * @return
 * - 0：success
 * - !=0：failure
 */
- (int)setAllAudioEffectsPlayoutVolume:(NSInteger)volume;

/**
 * @brief 设置所有音效推流混音音量
 * @param volume 推流混音音量，范围是：[0, 100]，默认值：50
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Set the mixing volume of all audio effects push streaming
 * @param volume Push mix volume, range is: [0, 100], default value: 50
 * @return
 * - 0：success
 * - !=0：failure
 */
- (int)setAllAudioEffectsPublishVolume:(NSInteger)volume;

/**
 * @brief 暂停音效
 * @param soundId 用户给该音效文件分配的ID
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Pause specified audio effect files
 * @param soundId The ID assigned by the user to the audio effect file
 * @return
 * - 0：success
 * - !=0：failure
 */
- (int)pauseAudioEffectWithSoundId:(NSInteger)soundId;

/**
 * @brief 暂停所有音效
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Pause all audio effects
 * @return
 * - 0：success
 * - !=0：failure
 */
- (int)pauseAllAudioEffects;

/**
 * @brief 恢复指定音效文件
 * @param soundId 用户给该音效文件分配的ID
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Resume specified audio effect files
 * @param soundId The ID assigned by the user to the audio effect file
 * @return
 * - 0：success
 * - !=0：failure
 */
- (int)resumeAudioEffectWithSoundId:(NSInteger)soundId;

/**
 * @brief 恢复所有音效文件
 * @return
 * - 0：成功
 * - 非0：失败
 */

/****
 * @brief Resume all audio effect files
 * @return
 * - 0：success
 * - !=0：failure
 */
- (int)resumeAllAudioEffects;

#pragma mark - "网络测试"

/**
 * @brief 开始网络质量探测
 * @param config 网络探测配置，AliLiveNetworkQualityProbeConfig
 * @details 网络质量探测需要在未推流 startPush之前调用，探测结果，开始推流后不能调用startLastmileDetect
 * @note 在3s左右，粗略的结果会在  {@link AlivcLivePusherNetworkDelegate::onLastmileDetectResultWithQuality:networkQuality:} 中回调
 * @note 在30s左右，更多的结果会在 {@link AlivcLivePusherNetworkDelegate::onLastmileDetectResultWithBandWidth:code:result:} 中回调
 * @return
 * - 0: 成功
 * - <0: 失败
 */

/****
 * @brief Start network quality detection
 * @param config Network detection configuration，AliLiveNetworkQualityProbeConfig
 * @details Network quality detection needs to be called before startPush. As a result of the detection, startLastmileDetect cannot be called after startPush
 * @note In about 3s, the rough result will be called back in {@link AlivcLivePusherNetworkDelegate::onLastmileDetectResultWithQuality:networkQuality:}
 * - In about 30s, more results will be called back in  {@link AlivcLivePusherNetworkDelegate::onLastmileDetectResultWithBandWidth:code:result:}
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)startLastmileDetect:(AliLiveNetworkQualityProbeConfig *_Nonnull)config;

/**
 * @brief 停止网络质量探测
 * @return
 * - 0: 成功
 * - <0: 失败
 */

/****
 * @brief Stop network quality detection
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)stopLastmileDetect;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      美颜相关api，在v4.2.0版本已删除，推流SDK不再提供内置美颜功能，请使用阿里云Queen提供的美颜服务
//      详见：https://help.aliyun.com/document_detail/211047.html?spm=a2c4g.11174283.6.736.79c5454ek41M8B
//
//
//      From V4.2.0, methods related to face retouching are deleted. Push SDK no longer provides a
//      built-in face retouching   feature. Please use Queen SDK to implement face
//      retouching.：https://help.aliyun.com/document_detail/211047.html?spm=a2c4g.11174283.6.736.79c5454ek41M8B
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        从v6.10.0版本开始，Debug悬浮窗相关接口废弃，此块功能已移植到最新的源码demo中，请下载最新的源码demo查看
//        详见：https://help.aliyun.com/zh/live/developer-reference/sdk-download-and-release-notes
//
//        Starting from version v6.10.0, the interface related to the Debug floating window is abandoned. This
//        function has been transplanted to the latest source code demo. Please download the latest source code
//        demo to view. See:https://help.aliyun.com/zh/live/developer-reference/sdk-download-and-release-notes
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 显示调试悬浮窗(已废弃)
 * @note 已废弃使用
 * @deprecated
 */

/****
 * @brief Show the debugging window
 * @deprecated
 */
+ (void)showDebugView;



/**
 * @brief 隐藏调试悬浮窗(已废弃)
 * @note 已废弃使用
 * @deprecated
 */

/****
 * @brief Hide the debugging window
 * @deprecated
 */
+ (void)hideDebugView;

@end

/** @} */

/**** @} */

/**
 * @defgroup AlivcLivePusher_Delegate 直播推流引擎回调
 * @ingroup live
 *  直播推流引擎回调
 *  @{
 */

/****
 * @defgroup AlivcLivePusher_Delegate Live pusher engine callbacks
 * @ingroup live
 *  @{
 */

/**
 * 推流错误回调
 */

/****
 * Live pusher engine error callbacks
 */
@protocol AlivcLivePusherErrorDelegate <NSObject>

@required

/**
 * @brief 系统设备异常回调
 * @param pusher 推流引擎对象
 * @param error 错误信息，参考 AlivcPusherErrorCode
 * @note 系统设备异常回调，需要销毁引擎重新尝试(stopPush & destory)。
 */

/****
 * @brief The system error callback
 * @param pusher The live pusher engine object
 * @param error The error message {@link AlivcLivePushError}
 */
- (void)onSystemError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 * @brief SDK错误回调
 * @param pusher 推流引擎对象
 * @param error 错误信息，{@link AlivcLivePushError}
 */

/****
 * @brief The SDK error callback
 * @param pusher The live pusher engine object
 * @param error The error message {@link AlivcLivePushError}
 */
- (void)onSDKError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;

@end


/**
 * 推流网络相关回调
 */

/****
 * Callbacks related to network status
 */
@protocol AlivcLivePusherNetworkDelegate <NSObject>

@required

/**
 * @brief 网络差回调
 * @param pusher 推流引擎对象
 * @note 此回调表示当前主播网络差
 */

/****
 * @brief The callback for poor network
 * @param pusher The live pusher engine object
 * @note This callback indicates that the streamer has a poor network
 */
- (void)onNetworkPoor:(AlivcLivePusher *)pusher;


/**
 * @brief 推流链接失败
 * @param pusher 推流引擎对象
 * @param error 错误信息，{@link AlivcLivePushError}
 */

/****
 * @brief The callback for failed pusher engine
 * @param pusher The live pusher engine object
 * @param error The error message {@link AlivcLivePushError}
 */
- (void)onConnectFail:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 * @brief 网络恢复
 * @param pusher 推流引擎对象
 * @note 此回调表示当前主播网络恢复
 */

/****
 * @brief The callback for network recovery
 * @param pusher The live pusher engine object
 * @note This callback indicates that the streamer's network is recovered
 */
- (void)onConnectRecovery:(AlivcLivePusher *)pusher;


/**
 * @brief 重连开始回调
 * @param pusher 推流引擎对象
 * @note 此回调表示当前推流链接断开，正在开始重连
 */

/****
 * @brief The callback for reconnection attempt
 * @param pusher The live pusher engine object
 * @note This callback indicates that the push stream is disconnected and being reconnected
 */
- (void)onReconnectStart:(AlivcLivePusher *)pusher;


/**
 * @brief 重连成功回调
 * @param pusher 推流引擎对象
 * @note 此回调表示重连成功
 */

/****
 * @brief The callback for successful reconnection
 * @param pusher The live pusher engine object
 * @note This callback indicates that reconnection is successful
 */
- (void)onReconnectSuccess:(AlivcLivePusher *)pusher;

/**
 * @brief 链接断开
 * @param pusher 推流引擎对象
 * @note 此回调表示推流链接断开
 */

/****
 * @brief The callback for disconnected stream pusher
 * @param pusher The live pusher engine object
 * @note This callback indicates that the  stream is disconnected
 */
- (void)onConnectionLost:(AlivcLivePusher *)pusher;


/**
 * @brief 重连失败回调
 * @param pusher 推流引擎对象
 * @param error 错误信息，{@link AlivcLivePushError}
 * @note 此回调表示重连失败
 */

/****
 * @brief The callback for failed reconnection
 * @param pusher The live pusher engine object
 * @param error The error message {@link AlivcLivePushError}
 * @note This callback indicates that reconnection fails
 */
- (void)onReconnectError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 * @brief 发送数据超时
 * @param pusher 推流引擎对象
 * @note 此回调表示发送数据超时
 */

/****
 * @brief The callback for data transmission timeout
 * @param pusher The live pusher engine object
 * @note This callback indicates that data transmission times out
 */
- (void)onSendDataTimeout:(AlivcLivePusher *)pusher;


/**
 * @brief 推流URL的鉴权时长即将过期(将在过期前1min内发送此回调)
 * @param pusher 推流引擎对象
 * @return 新的重新生成鉴权URL的推流URL
 * @note 此回调当前推流URL鉴权过期，需要给SDK传递一个新的URL
 */

/****
 * @brief The callback for expiring signed URL. (This callback is sent 1 minute before the signed URL expires.)
 * @param pusher The live pusher engine object
 * @return A new signed ingest URL is generated
 * @note This callback indicates that the signed URL is about to expire. You need to pass a new signed URL to the SDK.
 */
- (NSString *)onPushURLAuthenticationOverdue:(AlivcLivePusher *)pusher;

/**
 * @brief 连麦推流URL的token即将过期(将在过期前30s内发送此回调)
 * @param pusher 推流引擎对象
 * @note 此回调只在互动模式下生效，该回调在鉴权信息30秒前触发，收到该回调后应该及时将新的token的URL传入SDK，参考refreshPushURLToken
 */

/****
 * @brief The token of the streaming URL is about to expire (this callback will be sent within 30s before expiration)
 * @param pusher The live pusher engine object
 * @note This callback only takes effect in the interactive mode. The callback is triggered 30 seconds before the authentication information.
 * After receiving the callback, the URL of the new token should be passed to the SDK in time refreshPushURLToken
 */
- (void)onPushURLTokenWillExpire:(AlivcLivePusher *)pusher;

/**
 * @brief 连麦推流URL的token已经过期
 * @param pusher 推流引擎对象
 * @note 此回调只在互动模式下生效，该回调触发代表鉴权信息已过期，需要调用结束推流后使用新的token的URL重新推流
 */

/****
 * @brief The token of the streaming URL has expired
 * @param pusher The live pusher engine object
 * @note This callback only takes effect in the interactive mode. The trigger of this callback means that the authentication
 *  information has expired, and it needs to be called to re-push the stream with the URL of the new token after the push ends.
 */
- (void)onPushURLTokenExpired:(AlivcLivePusher *)pusher;


/**
 * @brief 发送SEI Message 通知
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for prompt to send an SEI message
 * @param pusher The live pusher engine object
 */
- (void)onSendSeiMessage:(AlivcLivePusher *)pusher;

/**
 * @brief 网络质量变化时发出的消息
 * @param pusher pusher 推流引擎对象
 * @param upQuality  上行网络质量
 * @param downQuality 下行网络质量
 * @note 当本端网络质量发生变化时触发, 此回调只在互动模式下生效
 */

/****
 * @brief The message that is sent when the network quality changes.
 * @param pusher The live pusher engine object
 * @param upQuality  up network quality
 * @param downQuality down network quality
 * @note Triggered when peer network quality changes.This callback only takes effect in the interactive mode.
 */
- (void)onPusherNetworkQualityChanged:(AlivcLivePusher *)pusher upNetworkQuality:(AlivcLiveNetworkQuality)upQuality downNetworkQuality:(AlivcLiveNetworkQuality)downQuality;

/**
 * @brief 网络连接状态改变的回调
 * @param pusher pusher 推流引擎对象
 * @param status 当前状态值, 对应值参考枚举 AliLiveConnectionStatus
 * @param reason 引起状态变化的具体原因, 对应值参考枚举AliLiveConnectionStatusChangeReason
 * @note 此回调只在互动模式下生效
 */

/****
 * @brief Callback when network connection status changes
 * @param pusher The live pusher engine object
 * @param status Current status value, corresponding value reference enumeration AliLiveConnectionStatus
 * @param reason The specific reason causing the status change, the corresponding value refers to the enumeration AliLiveConnectionStatusChangeReason
 * @note This callback only takes effect in interactive mode
 */
- (void)onConnectionStatusChange:(AlivcLivePusher *)pusher
                connectionStatus:(AliLiveConnectionStatus)status reason:(AliLiveConnectionStatusChangeReason)reason;

/**
 * @brief 网络质量探测回调
 * @param pusher pusher 推流引擎对象
 * @param networkQuality 网络质量 AlivcLiveNetworkQuality
 * @note 在开始推流前调用 startLastmileDetect 后会触发该回调,  此回调只在互动模式下生效
 */

/****
 * @brief Network quality detection callback
 * @param pusher The live pusher engine object
 * @param networkQuality  network quality AlivcLiveNetworkQuality
 * @note This callback will be triggered after calling startLastmileDetect before startPush
 */
- (void)onLastmileDetectResultWithQuality:(AlivcLivePusher *)pusher networkQuality:(AlivcLiveNetworkQuality)networkQuality;

/**
 * @brief 网络质量探测结果的回调
 * @param pusher pusher 推流引擎对象
 * @param code 探测结果，0: 成功，-1: DNS获取失败，-2: ICMP模块初始化失败,  -3: ICMP 发送长时间失败, -4: ICMP 无法接收(建议允许开播)
 * @param result 网络质量 AliLiveNetworkQualityProbeResult
 * @note 当调用 startLastmileDetect后会触发该回调, 此回调只在互动模式下生效
 * @details code 错误码处理建议：
 * 1. 如果是直接回抛了-1、-2、-3错误码，可以阻止开播；
 * 2. 由于有些特定网络可能设置阻止网络探测，会返回-4错误码，为了避免探测误伤导致主播无法开播，因此返回-4错误码也建议允许开播推流
 */

/****
 * @brief Callback of network quality detection results
 * @param pusher The live pusher engine object
 * @param code Detection results，0: success, -1: DNS acquisition failed, -2: ICMP module initialization failed, -3: ICMP sending failed for a long time, -4: ICMP cannot be accepted(It is recommended to allow broadcasting)
 * @param result network result AliLiveNetworkQualityProbeResult
 * @note This callback will be triggered when startLastmileDetect is called.
 * @details code Error code handling suggestions:：
 * 1. If -1, -2, -3 error codes are directly thrown back, broadcasting can be prevented;
 * 2. Because some specific networks may be configured to prevent network detection, a -4 error code will be returned. In order to avoid detection errors that may cause the host to be unable to start broadcasting, it is recommended to allow the broadcasting and push streaming if a -4 error code is returned.
 */
- (void)onLastmileDetectResultWithBandWidth:(AlivcLivePusher *)pusher code:(int)code result:(AliLiveNetworkQualityProbeResult* _Nonnull)result;

@optional

/**
 * @brief 网络原因导致音视频丢包
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for audio/video packet loss due to network reasons
 * @param pusher The live pusher engine object
 */
- (void)onPacketsLost:(AlivcLivePusher *)pusher;


@end



/**
 * 推流基本信息相关回调
 */

/****
 * Callbacks related to stream pusher basic info
 */
@protocol AlivcLivePusherInfoDelegate <NSObject>

@optional

/**
 * @brief 预览开始
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for preview start
 * @param pusher The live pusher engine object
 */
- (void)onPreviewStarted:(AlivcLivePusher *)pusher;



/**
 * @brief 停止预览回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for preview stop
 * @param pusher The live pusher engine object
 */
- (void)onPreviewStoped:(AlivcLivePusher *)pusher;


/**
 * @brief 渲染第一帧回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for first frame rendering
 * @param pusher The live pusher engine object
 */
- (void)onFirstFramePreviewed:(AlivcLivePusher *)pusher;


/**
 * @brief 发送第一帧音视频流回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for the first frame being sent
 * @param pusher The live pusher engine object
 */
- (void)onFirstFramePushed:(AlivcLivePusher *)pusher;

/**
 * @brief 推流开始回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for start of stream push
 * @param pusher The live pusher engine object
 */
- (void)onPushStarted:(AlivcLivePusher *)pusher;


/**
 * @brief 摄像头推流暂停回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for pause of stream pusher from the camera
 * @param pusher The live pusher engine object
 */
- (void)onPushPaused:(AlivcLivePusher *)pusher;


/**
 * @brief 摄像头推流恢复回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for resume of stream push from the camera
 * @param pusher The live pusher engine object
 */
- (void)onPushResumed:(AlivcLivePusher *)pusher;


/**
 * @brief 重新推流回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for restart of stream push
 * @param pusher The live pusher engine object
 */
- (void)onPushRestart:(AlivcLivePusher *)pusher;


/**
 * @brief 推流停止回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for end of stream push
 * @param pusher The live pusher engine object
 */
- (void)onPushStoped:(AlivcLivePusher *)pusher;

/**
 * @brief 直播推流器统计数据回调（每2秒回调一次）
 *
 * @param pusher 推流引擎对象
 * @param statistics 推流器统计数据 {@link AlivcLivePushStatsInfo}
 */

/****
 * @brief The callback for statistics on stream push. (This callback is invoked every 2 seconds.)
 *
 * @param pusher The live pusher engine object
 * @param statistics The statistics data {@link AlivcLivePushStatsInfo}
 */
- (void)onPushStatistics:(AlivcLivePusher *)pusher statsInfo:(AlivcLivePushStatsInfo*)statistics;

/**
 * @brief 设置云端的混流（转码）参数回调，对应于setLiveMixTranscodingConfig接口
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param isSuccess YES表示成功，NO表示失败
 * @param msg 具体错误原因
 */

/****
 * @brief The callback for mixed-stream transcoding, which corresponds to the setLiveMixTranscodingConfig method
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher The live pusher engine object
 * @param isSuccess YES success; NO failure
 * @param msg The error cause
 */
- (void)onSetLiveMixTranscodingConfig:(AlivcLivePusher *)pusher status:(BOOL)isSuccess message:(NSString *)msg;


/**
 * @brief 被服务侧强制踢掉回调
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param code 具体被踢掉原因
 */

/****
 * @brief The reason for being kicked out by the server callback
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher pusher The live pusher engine object
 * @param code The specific reason for being kicked out
 */
- (void)onKickedOutByServer:(AlivcLivePusher *)pusher reason:(AlivcLivePushKickedOutType)code;

/**
 * @brief 麦克风音量回调
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param volume 音量大小, 取值范围[0,255]
 * @note  调用 enableAudioVolumeIndication 打开音量回调频率后，会收到这个回调通知。
 */

/****
 * @brief Microphone volume callback
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher  The live pusher engine object
 * @param volume volume, value [0,255]
 * @note  After calling enableAudioVolumeIndication to enable the volume callback frequency, you will receive this callback notification.
 */
- (void)onMicrophoneVolumeUpdate:(AlivcLivePusher *)pusher volume:(int)volume;


/**
 * @brief 加入频道回调
 * @details 互动模式下调用startPushWithURL时，会先加入RTC频道，该回调表示成功/失败加入频道，并且返回频道加入的相关信息
 * @param pusher 推流引擎对象
 * @param result 加入频道结果
 * - 0：成功
 * - 非0：失败
 * @param channel 加入频道名
 * @param userId   用户ID
 */

/****
 * @brief Join channel callback
 * @details When startPushWithURL is called in interactive mode, the RTC channel will be added first. This callback indicates success/failure to join the channel and returns relevant information about channel joining
 * @param pusher The live pusher engine object
 * @param result Join channel results
 *  0:success
 *  != 0:failure
 * @param channel channel id
 * @param userId   user id
 */
- (void)onJoinChannelResult:(AlivcLivePusher *)pusher result:(int)result channel:(NSString *_Nonnull)channel userId:(NSString *_Nonnull)userId;

/**
 * @brief 有用户加入房间回调(只针对直播连麦场景生效)
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param userId 加入房间的用户ID
 * @param isOnline 加入房间状态：YES表示加入了房间，NO表示离开了房间
 * @note
 *  主播和观众连麦时，连麦观众开始推流后，在主播侧可以收到该回调，主播拿到回调后，可以向其
 *  业务server请求该userId的连麦拉流地址，使用AlivcLivePlayer的startPlayWithURL接口进行拉流
 */

/****
 * @brief A user room has been added to the callback
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher  The live pusher engine object
 * @param userId User ID to join the room
 * @param isOnline Joining room status: YES means joining the room, NO means leaving the room
 * @note
 * When the anchor and the audience are connected to each other, after the audience starts to push the stream, the anchor can receive the callback. After getting the callback, the anchor can request the userId's streaming address from its business server, using the startPlayWithURL interface of AlivcLivePlayer pull flow
 */
- (void)onRemoteUserEnterRoom:(AlivcLivePusher *)pusher userId:(NSString *)userId state:(BOOL)isOnline;

/**
 * @brief 有用户在房间内开启摄像头或共享流回调，可以是屏幕共享流或者unity流(只针对直播连麦场景生效)
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param userId 加入房间的用户ID
 * @param videoStreamType 视频类型，摄像头流或者屏幕共享流
 * @param isPushing 推流状态：YES表示开始推流，NO表示停止推流
 * @note
 * 主播拿到共享流回调后，可以创建AliLivePlayer对象，指定videoStreamType为AlivcLivePlayVideoStreamTypeScreen，
 * 使用该userId的连麦拉流地址，用AlivcLivePlayer的startPlayWithURL接口进行拉流
 */

/****
 * @brief A user opens a camera stream or  share screen stream callback in the room, which can be a screen sharing stream or a unity stream
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher  The live pusher engine object
 * @param userId User ID to join the room
 * @param videoStreamType Video type, camera stream or screen sharing stream
 * @param isPushing push state：YES start pushing，NO stop push
 * @note
 * After the anchor gets the shared stream callback, he can create an AliLivePlayer object, specify the videoStreamType as AlivcLivePlayVideoStreamTypeScreen, use the userId's link address to pull the stream, and use the startPlayWithURL interface of AlivcLivePlayer to pull the stream.
 */
- (void)onRemoteUserVideoStream:(AlivcLivePusher *)pusher userId:(NSString *)userId type:(AlivcLivePlayVideoStreamType)videoStreamType state:(BOOL)isPushing;

/**
 * @brief 有用户在房间内成员推送音频流回调(只针对直播连麦场景生效)
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param userId 加入房间的用户ID
 * @param isPushing 推流状态：YES表示开始推流，NO表示停止推流
 * @note
 */

/****
 * @brief A user opens a audio stream callback in the room
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher  The live pusher engine object
 * @param userId User ID to join the room
 * @param isPushing push state：YES start pushing，NO stop push
 */
- (void)onRemoteUserAudioStream:(AlivcLivePusher *)pusher userId:(NSString *)userId  state:(BOOL)isPushing;

/**
 * @brief 本地媒体录制状态回调
 * 注：录制开始或者录制异常都是通过该回调回抛
 * @param pusher 推流引擎对象
 * @param event 本地录制状态和错误回调, 参见AlivcLiveRecordMediaEventCode
 * @param storagePath 录制文件存储路径
 */

/**
 * @brief Local media recording status callback
 * Note: The recording start or recording exception will be thrown through this callback.
 * @param pusher The live pusher engine object
 * @param event Local recording status and error callback, see AlivcLiveRecordMediaEventCode
 * @param storagePath Recording file storage path
 */
- (void)onMediaRecordEvent:(AlivcLivePusher *)pusher event:(AlivcLiveRecordMediaEventCode)event recoderStoragePath:(NSString *_Nullable)storagePath;

/**
 * @brief 音频推流变更回调
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param oldState 之前的推流状态，详见  AliLivePublishState
 * @param newState 当前的推流状态，详见 AliLivePublishState
 */

/****
 * @brief The callback for the  audio frame being sent
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher The live pusher engine object
 * @param oldState Previous push status，See  AliLivePublishState
 * @param newState Current push status，See AliLivePublishState
 */
- (void)onAudioPublishStateChanged:(AlivcLivePusher *)pusher oldState:(AliLivePublishState)oldState newState:(AliLivePublishState)newState;

/**
 * @brief 视频推流变更回调
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param oldState 之前的推流状态，详见  AliLivePublishState
 * @param newState 当前的推流状态，详见 AliLivePublishState
 */

/****
 * @brief The callback for the  video frame being sent
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher The live pusher engine object
 * @param oldState Previous push status，See  AliLivePublishState
 * @param newState Current push status，See AliLivePublishState
 */
- (void)onVideoPublishStateChanged:(AlivcLivePusher *)pusher oldState:(AliLivePublishState)oldState newState:(AliLivePublishState)newState;

/**
 * @brief 屏幕分享推流变更回调
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param oldState 之前的推流状态，详见  AliLivePublishState
 * @param newState 当前的推流状态，详见 AliLivePublishState
 */

/****
 * @brief The callback for the  screen frame being sent
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher The live pusher engine object
 * @param oldState Previous push status，See  AliLivePublishState
 * @param newState Current push status，See AliLivePublishState
 */
- (void)onScreenSharePublishStateChanged:(AlivcLivePusher *)pusher oldState:(AliLivePublishState)oldState newState:(AliLivePublishState)newState;

/**
 * @brief 发送第二路音频推送状态回调
 * 注：此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
 * @param pusher 推流引擎对象
 * @param isPushing 推流状态：YES表示开始推流，NO表示停止推流
 */

/****
 * @brief The callback for the  the second audio stream push state
 * Note: This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 * @param pusher The live pusher engine object
 * @param isPushing push state：YES start pushing，NO stop push
 */
- (void)onLocalDualAudioStreamPushState:(AlivcLivePusher *)pusher state:(BOOL)isPushing;

/**
 * @brief 本地音频采集设备状态回调
 * @param pusher 推流引擎对象
 * @param state  设备状态，AliLiveLocalAudioStateType类型
 * @note startAudioCapture 和 stopAudioCapture的结果回调
 */

/****
 * @brief Local audio record device status callback
 * @param pusher The live pusher engine object
 * @param state  Device status, AliLiveLocalAudioStateType type
 * @note The result callbacks of startAudioCapture and stopAudioCapture
 */
- (void)onLocalAudioStateChanged:(AlivcLivePusher *)pusher state:(AliLiveLocalAudioStateType)state message:(NSString *_Nullable)msg;

/**
 * @brief 本地视频采集设备状态回调
 * @param pusher 推流引擎对象
 * @param state  设备状态，AliLiveLocalVideoStateType类型
 * @note enableLocalCamera的结果回调
 */

/****
 * @brief Local video capture device status callback
 * @param pusher The live pusher engine object
 * @param state  Device status, AliLiveLocalVideoStateType type
 * @note  The result callbacks of enableLocalCamera
 */
- (void)onLocalVideoStateChanged:(AlivcLivePusher *)pusher state:(AliLiveLocalVideoStateType)state message:(NSString *_Nullable)msg;
@end

/**
 * 背景音乐相关回调
 */

/****
 * Background music callbacks
 */
@protocol AlivcLivePusherBGMDelegate <NSObject>

@required

/**
 * @brief 背景音乐开始播放
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback indicating that background music starts to play
 * @param pusher The live pusher engine object
 */
- (void)onStarted:(AlivcLivePusher *)pusher;


/**
 * @brief 背景音乐停止播放
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback indicating that background music stops playing
 * @param pusher The live pusher engine object
 */
- (void)onStoped:(AlivcLivePusher *)pusher;


/**
 * @brief 背景音乐暂停播放
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback indicating that playback of background music is paused
 * @param pusher The live pusher engine object
 */
- (void)onPaused:(AlivcLivePusher *)pusher;


/**
 * @brief 背景音乐恢复播放
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback indicating that playback of background music is resumed
 * @param pusher The live pusher engine object
 */
- (void)onResumed:(AlivcLivePusher *)pusher;


/**
 * @brief 背景音乐当前播放进度
 * @param pusher 推流引擎对象
 * @param progress 播放时长
 * @param duration 总时长
 */

/****
 * @brief The callback for playback progress
 * @param pusher The live pusher engine object
 * @param progress play progress
 * @param duration duration
 */
- (void)onProgress:(AlivcLivePusher *)pusher progress:(long)progress duration:(long)duration;


/**
 * @brief 背景音乐播放完毕
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for complete playback of background music
 * @param pusher The live pusher engine object
 */
- (void)onCompleted:(AlivcLivePusher *)pusher;


/**
 * @brief 背景音乐开启失败
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback indicating that background music fails to play
 * @param pusher The live pusher engine object
 */
- (void)onOpenFailed:(AlivcLivePusher *)pusher;


/**
 * @brief 背景音乐下载播放超时
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback indicating that the download of background music times out
 * @param pusher The live pusher engine object
 */
- (void)onDownloadTimeout:(AlivcLivePusher *)pusher;


/**
 * @brief 本地音效播放结束回调
 * @param soundId 用户给该音效文件分配的唯一ID
 */

/****
 * @brief Local audio effect playback end callback
 * @param soundId The unique ID assigned by the user to the audio effect file
 */
- (void)onAudioEffectFinished:(int)soundId;
@end

/**
 * 外置滤镜相关回调
 */

/****
 * Callbacks related to external filters
 */
@protocol AlivcLivePusherCustomFilterDelegate <NSObject>
@required
/**
 * @brief 通知外置滤镜创建回调
 * @param pusher 推流引擎对象
 * @param context 上下文环境
 */

/****
 * @brief The callback for creation of an external filter
 * @param pusher The live pusher engine object
 * @param context The context.
 */
- (void)onCreate:(AlivcLivePusher *)pusher context:(void*)context;
/**
 * @brief 通知外置滤镜处理回调(纹理回调)
 * @param pusher 推流引擎对象
 * @param texture 纹理ID
 * @param width 图像宽
 * @param height 图像高
 * @param extra 额外信息
 * @return 返回处理后的纹理ID
 * @note 互动模式下默认是回抛CVPixelBuffer用于美颜，如果想要回调纹理ID，需要设置enableLocalVideoTexture，设置后，互动模式会回抛纹理ID
 */

/****
 * @brief The callback for processing of an external filter. The current version of the SDK uses onProcess to process face retouching requests in non-interactive mode.
 * @param pusher The live pusher engine object
 * @param texture The ID of the processed texture
 * @param width The width of the video
 * @param height The height of the video
 * @param extra extra info
 * @return The ID of the processed texture is returned
 * @note In the interactive mode, the default is to throw back the CVPixelBuffer for beauty. If you want to call back the texture, you need to set enableLocalVideoTexture. After setting, the interactive mode will throw back the texture ID.
 */
- (int)onProcess:(AlivcLivePusher *)pusher texture:(int)texture textureWidth:(int)width textureHeight:(int)height extra:(long)extra;
/**
 * @brief 通知外置滤镜处理回调，当前版本SDK在互动模式下默认回抛CVPixelBuffer，需要使用onProcessVideoSampleBuffer处理美颜，如果想要回抛纹理ID，需要设置enableLocalVideoTexture
 * @param pusher 推流引擎对象
 * @param sampleBuffer 视频sample data {@link AlivcLiveVideoDataSample}
 * @note 美颜SDK有两种处理方式：1.在SDK抛出的sampleBuffer.pixelBuffer上直接处理数据，不生成新的pixbuffer; 2.生成新的newPixelBuffer，在新的newPixelBuffer上处理美颜，这种情况需要将新生成的newPixelBuffer写会SDK，可以参考如下示例代码：
 *  - (BOOL)onProcessVideoSampleBuffer:(AlivcLivePusher *)pusher sampleBuffer:(AlivcLiveVideoDataSample *)sampleBuffer{
 *       CVPixelBufferRef newPixelBuffer = thirdparty_process(sampleBuffer.pixelBuffer);
        sampleBuffer.pixelBuffer = newPixelBuffer;
        return YES;
 *  }
 * @return
 * - YES: 需要写回SDK
 * - NO: 不需要写回SDK
 * @note 此回调只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才回回调
 */

/****
 * @brief The callback for processing of an external filter. The current version of the SDK uses onProcessVideoSampleBuffer
 * to process face retouching requests in interactive mode
 * @param pusher The live pusher engine object
 * @param sampleBuffer video sample data {@link AlivcLiveVideoDataSample}
 * @return - YES: Written back to the SDK；- NO: Not written back to the SDK
 * @note This callback is available only when livePushMode is set to AlivcLivePushInteractiveMode, that is, when Push SDK is working in interactive mode.
 */
- (BOOL)onProcessVideoSampleBuffer:(AlivcLivePusher *)pusher sampleBuffer:(AlivcLiveVideoDataSample *)sampleBuffer;

/**
 * @brief 通知外置滤镜销毁回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for destruction of an external filter
 * @param pusher The live pusher engine object
 */
- (void)onDestory:(AlivcLivePusher *)pusher;

@end

/**
 * 外置人脸识别算法相关回调
 */

/****
 * Callbacks related to external facial recognition algorithms
 */
@protocol AlivcLivePusherCustomDetectorDelegate <NSObject>

@required
/**
 * @brief 通知外置识别器创建回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for creation of an external recognizer
 * @param pusher The live pusher engine object
 */
- (void)onCreateDetector:(AlivcLivePusher *)pusher;

/**
 * @brief 通知外置识别器处理回调
 * @param pusher 推流引擎对象
 * @param data 数据buffer地址
 * @param w图像宽
 * @param h图像高
 * @param rotation 图像角度
 * @param format 图像格式
 * @param extra 额外信息
 * @return 处理后的数据buffer地址
 */

/****
 * @brief The callback for processing of an external recognizer
 * @param pusher The live pusher engine object
 * @param data The data buffer
 * @param width The width of the video
 * @param height The height of the video
 * @param rotation The rotation degree
 * @param format video format
 * @param extra extra info
 * @return The processed data buffer
 */
- (long)onDetectorProcess:(AlivcLivePusher *)pusher data:(long)data w:(int)w h:(int)h rotation:(int)rotation format:(int)format extra:(long)extra;

/**
 * @brief 通知外置识别器销毁回调
 * @param pusher 推流引擎对象
 */

/****
 * @brief The callback for destruction of an external recognizer
 * @param pusher The live pusher engine object
 */
- (void)onDestoryDetector:(AlivcLivePusher *)pusher;

@end

/**
 * 截图相关回调
 */

/****
 * Snapshot-related callbacks
 */
@protocol AlivcLivePusherSnapshotDelegate <NSObject>

@required

/**
 * @brief 截图回调
 * @param pusher 推流引擎对象
 * @param image 截图
 */

/****
 * @brief Snapshot callbacks
 * @param pusher The live pusher engine object
 * @param image
 */
- (void)onSnapshot:(AlivcLivePusher *)pusher image:(UIImage *)image;
@end

/**
 * 音频裸数据相关回调
 */

/****
 * Callbacks related to raw audio data
 */
@protocol AlivcLivePusherAudioSampleDelegate <NSObject>
/**
 * @brief 设备采集的原始音频数据，支持修改，采集裸数据回调
 * @details 默认关闭，需要通过enableAudioFrameObserver : YES audioSource: AliLiveAudioSourceCaptured 开启
 *
 *  - 该接口支持设置采样率、声道数
 *  - 该接口支持读写模式
 *
 * @param pusher 推流引擎对象
 * @param audioSample 音频数据sample, {@link AlivcLivePusherAudioDataSample}
 * @note 请不要在此回调函数中做任何耗时操作，否则可能导致声音异常
 */

/****
 * @brief The original audio data collected by the device, You can modify the data.
 * @details It is turned off by default and needs to be turned on by enableAudioFrameObserver: YES audioSource: AliLiveAudioSourceCaptured
 *  - This interface supports setting the sampling rate and number of channels
 *  - This interface supports read and write modes
 * @param pusher The live pusher engine object
 * @param audioSample audio sample data {@link AlivcLivePusherAudioDataSample}
 * @note Please do not do any time-consuming operations in this callback function, otherwise it may cause abnormal sound
 */
- (void)onAudioSampleCallback:(AlivcLivePusher *)pusher audioSample:(AlivcLivePusherAudioDataSample*)audioSample;

/**
 * @brief 3A后数据回调
 * @details 默认关闭，需要通过enableAudioFrameObserver : YES audioSource: AliLiveAudioSourceProcessCaptured 开启
 *
 *  - 该接口支持设置采样率、声道数
 *  - 该接口支持读写模式
 *
 * @param pusher 推流引擎对象
 * @param audioSample 音频数据sample, {@link AlivcLivePusherAudioDataSample}
 * @note 请不要在此回调函数中做任何耗时操作，否则可能导致声音异常
 */

/****
 * @brief Data callback after 3A
 * @details It is turned off by default and needs to be turned on by enableAudioFrameObserver: YES audioSource: AliLiveAudioSourceProcessCaptured
 *  - This interface supports setting the sampling rate and number of channels
 *  - This interface supports read and write modes
 * @param pusher The live pusher engine object
 * @param audioSample audio sample data {@link AlivcLivePusherAudioDataSample}
 * @note Please do not do any time-consuming operations in this callback function, otherwise it may cause abnormal sound
 */
- (void)onProcessAudioSampleCallback:(AlivcLivePusher *)pusher audioSample:(AlivcLivePusherAudioDataSample*)audioSample;

/**
 * @brief 推流数据回调
 * @details 默认关闭，需要通过enableAudioFrameObserver : YES audioSource: AliLiveAudioSourcePub 开启
 *
 *  - 该接口支持设置采样率、声道数
 *  - 该接口只支持只读模式
 *
 * @param pusher 推流引擎对象
 * @param audioSample 音频数据sample, {@link AlivcLivePusherAudioDataSample}
 * @note 请不要在此回调函数中做任何耗时操作，否则可能导致声音异常
 */

/****
 * @brief Push data callback
 * @details It is turned off by default and needs to be turned on by enableAudioFrameObserver: YES audioSource: AliLiveAudioSourcePub
 *  - This interface supports setting the sampling rate and number of channels
 *  - This interface supports read only modes
 * @param pusher The live pusher engine object
 * @param audioSample audio sample data {@link AlivcLivePusherAudioDataSample}
 * @note Please do not do any time-consuming operations in this callback function, otherwise it may cause abnormal sound
 */
- (void)onPublishAudioSampleCallback:(AlivcLivePusher *)pusher audioSample:(AlivcLivePusherAudioDataSample*)audioSample;

/**
 * @brief 播放数据回调
 * @details 默认关闭，需要通过enableAudioFrameObserver : YES audioSource: AliLiveAudioSourcePlayback 开启
 *
 *  - 该接口支持设置采样率、声道数
 *  - 该接口只支持只读模式
 *
 * @param pusher 推流引擎对象
 * @param audioSample 音频数据sample, {@link AlivcLivePusherAudioDataSample}
 * @note 请不要在此回调函数中做任何耗时操作，否则可能导致声音异常
 */

/****
 * @brief Play data callback
 * @details It is turned off by default and needs to be turned on by enableAudioFrameObserver: YES audioSource: AliLiveAudioSourcePlayback
 *  - This interface supports setting the sampling rate and number of channels
 *  - This interface supports read only modes
 * @param pusher The live pusher engine object
 * @param audioSample audio sample data {@link AlivcLivePusherAudioDataSample}
 * @note Please do not do any time-consuming operations in this callback function, otherwise it may cause abnormal sound
 */
- (void)onPlaybackAudioSampleCallback:(AlivcLivePusher *)pusher audioSample:(AlivcLivePusherAudioDataSample*)audioSample;

/**
 * @brief 推流数据和播放数据混音后回调
 * @details 默认关闭，需要通过enableAudioFrameObserver : YES audioSource: AliLiveAudioSourceMixedAll 开启
 *
 *  - 该接口支持设置采样率、声道数
 *  - 该接口只支持只读模式
 *
 * @param pusher 推流引擎对象
 * @param audioSample 音频数据sample, {@link AlivcLivePusherAudioDataSample}
 * @note 请不要在此回调函数中做任何耗时操作，否则可能导致声音异常
 */

/****
 * @brief Callback after mixing of push data and playback data
 * @details It is turned off by default and needs to be turned on by enableAudioFrameObserver: YES audioSource: AliLiveAudioSourceMixedAll
 *  - This interface supports setting the sampling rate and number of channels
 *  - This interface supports read only modes
 * @param pusher The live pusher engine object
 * @param audioSample audio sample data {@link AlivcLivePusherAudioDataSample}
 * @note Please do not do any time-consuming operations in this callback function, otherwise it may cause abnormal sound
 */
- (void)onMixedAllAudioSampleCallback:(AlivcLivePusher *)pusher audioSample:(AlivcLivePusherAudioDataSample*)audioSample;


@end

/** @} */

/**** @} */
