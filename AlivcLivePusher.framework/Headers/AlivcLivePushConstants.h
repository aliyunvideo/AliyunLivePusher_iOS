//
//  AlivcLivePushConstants.h
//  AlivcLiveCaptureLib
//
//  Created by TripleL on 2017/9/25.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 支持模式
 - AlivcLivePushBasicMode:基础模式，默认模式，常规的RTMP推流、RTS推流，不支持连麦、PK等实时互动，如果一场直播没有互动需求，建议使用该模式
 -AlivcLivePushInteractiveMode:互动模式，支持连麦、PK等实时互动，如果一场直播有互动需求，建议使用该模式
 */

/****
 Supported modes:
 - AlivcLivePushBasicMode:The basic mode, which is the default mode. It does not support real-time interaction features such as co-streaming and battle. Use this mode for ordinary RTMP- and RTS-based stream ingest.
 -AlivcLivePushInteractiveMode:The interactive mode, which supports real-time interaction features such as co-streaming and battle. If interaction is required during live streaming, we recommend that you use this mode.
 */
typedef NS_ENUM(NSInteger, AlivcLivePushMode) {
    AlivcLivePushBasicMode    = 0,
    AlivcLivePushInteractiveMode = 1
};

/**
 用户角色
 - AliLiveRoomUserRoleAnchor:主播
 -AliLiveRoomUserRoleInteractiveAudience:互动观众/连麦观众，和主播进行实时互动的观众
 */

/****
 The user role.
 - AliLiveRoomUserRoleAnchor:Anchor
 -AliLiveRoomUserRoleInteractiveAudience:audience
 */
typedef NS_ENUM(NSInteger, AlivcLivePushUserRole) {
    AlivcLivePushUserRoleAnchor                 = 0, //主播
    AlivcLivePushUserRoleInteractiveAudience     = 1, //互动观众/连麦观众
};

/**
 SDK log级别

 - AlivcLivePushLogLevelAll: 全部
 - AlivcLivePushLogLevelVerbose: 冗长
 - AlivcLivePushLogLevelDebug: 调试
 - AlivcLivePushLogLevelInfo: 提示
 - AlivcLivePushLogLevelWarn: 警告
 - AlivcLivePushLogLevelError: 错误
 - AlivcLivePushLogLevelNone: 不输出日志
 */

/****
 SDK log level

 - AlivcLivePushLogLevelAll: all
 - AlivcLivePushLogLevelVerbose: verbose
 - AlivcLivePushLogLevelDebug: debug
 - AlivcLivePushLogLevelInfo: info
 - AlivcLivePushLogLevelWarn: warn
 - AlivcLivePushLogLevelError: error
 - AlivcLivePushLogLevelNone: none
 */
typedef NS_ENUM(NSInteger, AlivcLivePushLogLevel){
    AlivcLivePushLogLevelAll = 0,
    AlivcLivePushLogLevelVerbose,
    AlivcLivePushLogLevelDebug,
    AlivcLivePushLogLevelInfo,
    AlivcLivePushLogLevelWarn,
    AlivcLivePushLogLevelError,
    AlivcLivePushLogLevelNone,
};

/**
 推流状态
 
 - AlivcLivePushStatusIdle: 空闲
 - AlivcLivePushStatusInitialized: 初始化成功
 - AlivcLivePushStatusPreviewing: 打开预览中
 - AlivcLivePushStatusPreviewed: 正在预览
 - AlivcLivePushStatusPushing: 推流连接中
 - AlivcLivePushStatusPushed: 正在推流
 - AlivcLivePushStatusStoping: 停止推流中
 - AlivcLivePushStatusPausing: 暂停推流中
 - AlivcLivePushStatusPaused: 暂停推流
 - AlivcLivePushStatusResuming: 恢复推流中
 - AlivcLivePushStatusRestarting: 重启推流中
 - AlivcLivePushStatusError: 错误状态
 */

/****
 live pusher engine status
 
 - AlivcLivePushStatusIdle: idel
 - AlivcLivePushStatusInitialized: initialized
 - AlivcLivePushStatusPreviewing: previewing
 - AlivcLivePushStatusPreviewed: previewed
 - AlivcLivePushStatusPushing: pushing
 - AlivcLivePushStatusPushed: pushed
 - AlivcLivePushStatusStoping: stoping
 - AlivcLivePushStatusPausing: pausing
 - AlivcLivePushStatusPaused: paused
 - AlivcLivePushStatusResuming: resuming
 - AlivcLivePushStatusRestarting: restarting
 - AlivcLivePushStatusError: error
 */
typedef NS_ENUM(NSInteger, AlivcLivePushStatus){
    AlivcLivePushStatusIdle = 0,
    AlivcLivePushStatusInitialized,
    AlivcLivePushStatusPreviewing,
    AlivcLivePushStatusPreviewed,
    AlivcLivePushStatusPushing,
    AlivcLivePushStatusPushed,
    AlivcLivePushStatusStoping,
    AlivcLivePushStatusPausing,
    AlivcLivePushStatusPaused,
    AlivcLivePushStatusResuming,
    AlivcLivePushStatusRestarting,
    AlivcLivePushStatusError,
};

/**
 分辨率

 - AlivcLivePushResolution180P: 180P
 - AlivcLivePushResolution240P: 240P
 - AlivcLivePushResolution360P: 360P
 - AlivcLivePushResolution480P: 480P
 - AlivcLivePushResolution540P: 540P
 - AlivcLivePushResolution720P: 720P
 - AlivcLivePushResolution1080P:1080P
 - AlivcLivePushResolutionPassThrough: pass through only used for external main video stream
 */

/****
 Resolution

 - AlivcLivePushResolution180P: 180P
 - AlivcLivePushResolution240P: 240P
 - AlivcLivePushResolution360P: 360P
 - AlivcLivePushResolution480P: 480P
 - AlivcLivePushResolution540P: 540P
 - AlivcLivePushResolution720P: 720P
 - AlivcLivePushResolution1080P:1080P
 - AlivcLivePushResolutionPassThrough: pass through only used for external main video stream
 */
typedef NS_ENUM(NSInteger, AlivcLivePushResolution){
    AlivcLivePushResolution180P = 0,
    AlivcLivePushResolution240P,
    AlivcLivePushResolution360P,
    AlivcLivePushResolution480P,
    AlivcLivePushResolution540P,
    AlivcLivePushResolution720P,
    AlivcLivePushResolution1080P,
    AlivcLivePushResolutionPassThrough,
};

/**
Image format
 */
typedef NS_ENUM(NSInteger, AlivcLivePushVideoFormat){
    AlivcLivePushVideoFormatUnknown   = -1,
    AlivcLivePushVideoFormatBGR       = 0,
    AlivcLivePushVideoFormatRGB,
    AlivcLivePushVideoFormatARGB,
    AlivcLivePushVideoFormatBGRA,
    AlivcLivePushVideoFormatRGBA,
    AlivcLivePushVideoFormatYUV420P,
    AlivcLivePushVideoFormatYUVYV12,
    AlivcLivePushVideoFormatYUVNV21,
    AlivcLivePushVideoFormatYUVNV12,
    AlivcLivePushVideoFormatYUVJ420P,
    AlivcLivePushVideoFormatYUVJ420SP,
    AlivcLivePushVideoFormatYUVJ444P,
    AlivcLivePushVideoFormatYUV444P,
};


/**
 sound format
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioFormat){
    AlivcLivePushAudioFormatUnknown   = -1,
    AlivcLivePushAudioFormatU8       = 0,
    AlivcLivePushAudioFormatS16,
    AlivcLivePushAudioFormatS32,
    AlivcLivePushAudioFormatF32,
    AlivcLivePushAudioFormatU8P,
    AlivcLivePushAudioFormatS16P,
    AlivcLivePushAudioFormatS32P,
    AlivcLivePushAudioFormatF32P,
};


/**
 推流模式

 - AlivcLivePushQualityModeResolutionFirst: 清晰度优先模式
 - AlivcLivePushQualityModeFluencyFirst: 流畅度优先模式
 - AlivcLivePushQualityModeCustom: 自定义模式
 */

/****
 Push quality mode

 - AlivcLivePushQualityModeResolutionFirst: Quality-first mode
 - AlivcLivePushQualityModeFluencyFirst: Smoothness-first mode
 - AlivcLivePushQualityModeCustom: Custom mode
 */
typedef NS_ENUM(NSInteger, AlivcLivePushQualityMode){
    AlivcLivePushQualityModeResolutionFirst = 0,
    AlivcLivePushQualityModeFluencyFirst,
    AlivcLivePushQualityModeCustom,
};



typedef NS_ENUM(NSInteger, AlivcLivePushFPS) {
    AlivcLivePushFPS8  = 8,
    AlivcLivePushFPS10 = 10,
    AlivcLivePushFPS12 = 12,
    AlivcLivePushFPS15 = 15,
    AlivcLivePushFPS20 = 20,
    AlivcLivePushFPS25 = 25,
    AlivcLivePushFPS30 = 30,
};


/**
 推流屏幕方向

 - AlivcLivePushOrientationPortrait: 竖屏推流
 - AlivcLivePushOrientationLandscapeLeft: 横屏Left方向
 - AlivcLivePushOrientationLandscapeRight: 横屏Right方向
 */

/****
 Push orientation

 - AlivcLivePushOrientationPortrait: Portrait:
 - AlivcLivePushOrientationLandscapeLeft: LandscapeLeft
 - AlivcLivePushOrientationLandscapeRight: LandscapeRight
 */
typedef NS_ENUM(NSInteger, AlivcLivePushOrientation){
    AlivcLivePushOrientationPortrait = 0,
    AlivcLivePushOrientationLandscapeLeft,
    AlivcLivePushOrientationLandscapeRight,
};


/**
 摄像头方向

 - AlivcLivePushCameraTypeBack: 后置摄像头
 - AlivcLivePushCameraTypeFront: 前置摄像头
 */

/****
 Camera type

 - AlivcLivePushCameraTypeBack: The rear camera.
 - AlivcLivePushCameraTypeFront: The front camera.
 */
typedef NS_ENUM(NSInteger, AlivcLivePushCameraType){
    AlivcLivePushCameraTypeBack = 0,
    AlivcLivePushCameraTypeFront,
};


/**
 缩放模式
 
 - AlivcLivePushScallingModeFit: 填充
 - AlivcLivePushScallingModeCrop: 裁剪
 */

/****
 Scalling Mode
 
 - AlivcLivePushScallingModeFit: Fit
 - AlivcLivePushScallingModeCrop: Crop
 */
typedef NS_ENUM(NSInteger, AlivcLivePushScallingMode){
    AlivcLivePushScallingModeFit = 0,
    AlivcLivePushScallingModeCrop,
};


/**
 视频编码模式
 
 - AlivcLivePushVideoEncoderModeHard: 硬编码
 - AlivcLivePushVideoEncoderModeSoft: 软编码
 */

/****
 Video Encoder Mode
 
 - AlivcLivePushVideoEncoderModeHard: Hard
 - AlivcLivePushVideoEncoderModeSoft: Soft
 */
typedef NS_ENUM(NSInteger, AlivcLivePushVideoEncoderMode){
    AlivcLivePushVideoEncoderModeHard = 0,
    AlivcLivePushVideoEncoderModeSoft,
};

/**
 硬编码方式
 - AlivcLivePushVideoEncoderModeHardTypeH264: 使用H264硬编码
 - AlivcLivePushVideoEncoderModeHardTypeHEVC: 使用H265硬编码
 */

/****
 Video encoder type
 - AlivcLivePushVideoEncoderModeHardTypeH264: H264
 - AlivcLivePushVideoEncoderModeHardTypeHEVC: HEVC
 */
typedef NS_ENUM(NSInteger, AlivcLivePushVideoEncoderModeHardCodec) {
    AlivcLivePushVideoEncoderModeHardCodecH264 = 0,
    AlivcLivePushVideoEncoderModeHardCodecHEVC
};

/**
 音频编码模式
 
 - AlivcLivePushAudioEncoderModeHard: 硬编码
 - AlivcLivePushAudioEncoderModeSoft: 软编码
 */

/****
 Audio encoder mode
 
 - AlivcLivePushAudioEncoderModeHard: hard
 - AlivcLivePushAudioEncoderModeSoft: soft
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioEncoderMode){
    AlivcLivePushAudioEncoderModeHard = 0,
    AlivcLivePushAudioEncoderModeSoft,
};


/**
 音频编码格式

 - AlivcLivePushAudioEncoderProfile_AAC_LC: AAC_LC
 - AlivcLivePushAudioEncoderProfile_HE_AAC: HE_AAC
 - AlivcLivePushAudioEncoderProfile_HE_AAC_V2: HE_AAC_V2
 - AlivcLivePushAudioEncoderProfile_AAC_LD: AAC_LD
 */

/****
 Audio encoder profile

 - AlivcLivePushAudioEncoderProfile_AAC_LC: AAC_LC
 - AlivcLivePushAudioEncoderProfile_HE_AAC: HE_AAC
 - AlivcLivePushAudioEncoderProfile_HE_AAC_V2: HE_AAC_V2
 - AlivcLivePushAudioEncoderProfile_AAC_LD: AAC_LD
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioEncoderProfile){
    AlivcLivePushAudioEncoderProfile_AAC_LC = 2,
    AlivcLivePushAudioEncoderProfile_HE_AAC = 5,
    AlivcLivePushAudioEncoderProfile_HE_AAC_V2 = 29,
    AlivcLivePushAudioEncoderProfile_AAC_LD = 23,
};


/**
 音频采样率
 
 - AlivcLivePushAudioSample32000: 32000Hz
 */

/****
 Audio  sample rate
 
 - AlivcLivePushAudioSample32000: 32000Hz
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioSampleRate){
    AlivcLivePushAudioSampleRate16000 = 16000,
    AlivcLivePushAudioSampleRate32000 = 32000,
    AlivcLivePushAudioSampleRate44100 = 44100,
    AlivcLivePushAudioSampleRate48000 = 48000,
};


/**
 声道数

 - AlivcLivePushAudioChannelOne: 单声道
 - AlivcLivePushAudioChannelTwo: 双声道
 */

/****
 Audio channel number

 - AlivcLivePushAudioChannelOne: One
 - AlivcLivePushAudioChannelTwo: Two
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioChannel){
    AlivcLivePushAudioChannel_1 = 1,
    AlivcLivePushAudioChannel_2 = 2,
};


/**
 关键帧间隔

 - AlivcLivePushVideoEncodeGOP_1: 1s
 - AlivcLivePushVideoEncodeGOP_2: 2s
 - AlivcLivePushVideoEncodeGOP_3: 3s
 - AlivcLivePushVideoEncodeGOP_4: 4s
 - AlivcLivePushVideoEncodeGOP_5: 5s
 */

/****
 video gop

 - AlivcLivePushVideoEncodeGOP_1: 1s
 - AlivcLivePushVideoEncodeGOP_2: 2s
 - AlivcLivePushVideoEncodeGOP_3: 3s
 - AlivcLivePushVideoEncodeGOP_4: 4s
 - AlivcLivePushVideoEncodeGOP_5: 5s
 */
typedef NS_ENUM(NSInteger, AlivcLivePushVideoEncodeGOP){
    AlivcLivePushVideoEncodeGOP_1 = 1,
    AlivcLivePushVideoEncodeGOP_2 = 2,
    AlivcLivePushVideoEncodeGOP_3 = 3,
    AlivcLivePushVideoEncodeGOP_4 = 4,
    AlivcLivePushVideoEncodeGOP_5 = 5,
};


/**
 接口返回值错误码
 */

/****
 Error code
 */
typedef NS_ENUM(NSInteger, AlivcPusherErrorCode){
    ALIVC_LIVE_PUSHER_INTERFACE_ERROR   = -1, // 接口调用内部错误
    ALIVC_LIVE_PUSHER_PARAM_ERROR       = -2, // 接口调用传入参数错误
    ALIVC_LIVE_PUSHER_UNKNOW_ERROR      = -3, // 接口调用未知错误
    ALIVC_LIVE_PUSHER_SEQUENCE_ERROR    = -4, // 接口调用顺序错误
    ALIVC_LIVE_PUSHER_RTC_NOT_SUPPORT_AUDIO_OR_VIDEOONLY_PUSH = -5, //RTS协议暂不支持纯音频或纯视频推流
    ALIVC_LIVE_PUSHER_API_NOT_SUPPORT_FOR_INTERACTIVEMODE = -6,//当前API在互动模式下不支持
    
    /* ***********************设备异常相关错误码(onSystemError 回调)*********************** */
    
    /** 麦克风打开失败 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_MicOpenFail = 1,
    /** 麦克风被打断 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_MicInterrupt = 2,
    /** 麦克风无权限 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_MicAuthFail = 3,
    /** 无可用麦克风 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_MicNotAvailable = 4,
    /** 扬声器打开失败 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_SpeakerOpenFail = 5,
    /** 扬声器被打断 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_SpeakerInterrupt = 6,
    /** 无可用扬声器 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_SpeakerNotAvailable = 7,
    /** 音频设备异常 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_AudioDeviceException = 8,
    /** 摄像头打开失败 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_CameraOpenFail = 9,
    /** 摄像头被打断 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_CameraInterrupt = 10,
    /** 摄像头无权限 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_CameraAuthFail = 11,
    /** 显示设备异常 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_DisplayExecption = 12,
    /** 视频设备异常 */
    ALIVC_LIVE_PUSHER_DEVICE_ERROR_VideoDeviceException = 13
};

/**
 预览窗口显示模式
 */

/****
 Preview Display Mde
- ALIVC_LIVE_PUSHER_PREVIEW_SCALE_FILL: Fills the entire preview window. If the aspect ratio of the video is not the same as the aspect ratio of the preview window, the preview image is deformed.
- ALIVC_LIVE_PUSHER_PREVIEW_ASPECT_FIT: Maintains the original aspect ratio of the video. If the aspect ratio of the video is not the same as the aspect ratio of the preview window, black bars appear on the preview window.
- ALIVC_LIVE_PUSHER_PREVIEW_ASPECT_FILL:Crops the video to fit the preview window. If the aspect ratio of the video is not the same as the aspect ratio of the preview window, the video is cropped.
 */
typedef NS_ENUM(NSInteger, AlivcPusherPreviewDisplayMode){
    ALIVC_LIVE_PUSHER_PREVIEW_SCALE_FILL= 0, // 铺满窗口，视频比例和窗口比例不一致时预览会有变形
    ALIVC_LIVE_PUSHER_PREVIEW_ASPECT_FIT= 1, // 保持视频比例，视频比例和窗口比例不一致时有黑边
    ALIVC_LIVE_PUSHER_PREVIEW_ASPECT_FILL = 2, //剪切视频以适配窗口比例，视频比例和窗口比例不一致时会裁剪视频
};

/**
 推流协议

 - AlivcLivePushPublishType_RTMP: RTMP协议推流
 - AlivcLivePushPublishType_RTP: RTP协议推流
 */

/****
 Live push protocol

 - AlivcLivePushPublishType_RTMP: RTMP
 - AlivcLivePushPublishType_RTP: RTP
 */
typedef NS_ENUM(NSInteger, AlivcLivePushPublishType){
    AlivcLivePushPublishType_RTMP = 1,
    AlivcLivePushPublishType_RTP = 2,
};

/**
 音频应用场景
 
 - AlivcLivePusherAudioScenarioDefaultMode 默认场景，一般的直播场景推荐使用
 - AlivcLivePusherAudioScenarioMediaMode 媒体场景，保真人声与音乐音质等 推荐使用
 - AlivcLivePusherAudioScenarioMusicMode 音乐场景，高保真音乐音质，乐器教学等对音乐音质有要求的场景推荐使用
 
 */

/****
 Audio scenario
 
 - AlivcLivePusherAudioScenarioDefaultMode The default scene. We recommend that you use this for ordinary live streaming.
 - AlivcLivePusherAudioScenarioMediaMode The media scene. We recommend that you use this if you want to maintain the vocal fidelity and music sound quality.
 - AlivcLivePusherAudioScenarioMusicMode The music scene. High fidelity is ensured for music. We recommend that you use this in scenarios that require high sound quality, such as instrument teaching.
 */
typedef NS_ENUM(NSInteger, AlivcLivePusherAudioScenario) {
    AlivcLivePusherAudioScenarioDefaultMode = 1,
    AlivcLivePusherAudioScenarioMediaMode   = 2,
    AlivcLivePusherAudioScenarioMusicMode   = 3
};

/**
  SDK对Audio Session的控制权限
 - AlivcLivePusherAudioSessionOperationRestrictionNone 默认，无限制，SDK完全控制AVAudioSession
 - AlivcLivePusherAudioSessionOperationRestrictionSetCategory SDK不能修改AVAudioSession的Category
 - AlivcLivePusherAudioSessionOperationRestrictionConfigureSession SDK不能修改AVAudioSession的配置，包括Category，Mode，CategoryOptions
 - AlivcLivePusherAudioSessionOperationRestrictionDeactivateSession SDK不能关闭AVAudioSession的活动状态，离开频道时，AVAudioSession依然处于活动状态
 */

/****
  Audio Session OperationRestriction
 - AlivcLivePusherAudioSessionOperationRestrictionNone
 - AlivcLivePusherAudioSessionOperationRestrictionSetCategory
 - AlivcLivePusherAudioSessionOperationRestrictionConfigureSession
 - AlivcLivePusherAudioSessionOperationRestrictionDeactivateSession
 */
typedef NS_ENUM(NSInteger, AlivcLivePusherAudioSessionOperationRestriction) {
    AlivcLivePusherAudioSessionOperationRestrictionNone              = 0,
    AlivcLivePusherAudioSessionOperationRestrictionSetCategory       = 1 << 0,
    AlivcLivePusherAudioSessionOperationRestrictionConfigureSession  = 1 << 1,
    AlivcLivePusherAudioSessionOperationRestrictionDeactivateSession = 1 << 2,
};
/**
 SDK License 校验枚举
 - AlivcLiveLicenseCheckResultCodeSuccess SDK校验license成功，可使用SDK功能
 - AlivcLiveLicenseCheckResultCodeCertInvalid licenseFile证书非法
 - AlivcLiveLicenseCheckResultCodeCertExpired licenseFile证书过期
 - AlivcLiveLicenseCheckResultCodeLicenseExpired licenseKey过期
 - AlivcLiveLicenseCheckResultCodeAppIdInvalid   APPID非法
 - AlivcLiveLicenseCheckResultCodeLicenseError license错误，license key或者 license file 非法
 - AlivcLiveLicenseCheckResultCodeBusinessInvalid 无效的业务信息
 - AlivcLiveLicenseCheckResultCodePlatformInvalid 该平台未购买
 - AlivcLiveLicenseCheckResultCodeUninitialized 未初始化
 */

/****
 SDK License Check Result Code
 - AlivcLiveLicenseCheckResultCodeSuccess success
 - AlivcLiveLicenseCheckResultCodeCertInvalid licenseFile invalid
 - AlivcLiveLicenseCheckResultCodeCertExpired licenseFile expired
 - AlivcLiveLicenseCheckResultCodeLicenseExpired licenseKey expired
 - AlivcLiveLicenseCheckResultCodeAppIdInvalid   APPID invalid
 - AlivcLiveLicenseCheckResultCodeLicenseError license error
 - AlivcLiveLicenseCheckResultCodeBusinessInvalid bussiness invalid
 - AlivcLiveLicenseCheckResultCodePlatformInvalid platform invalid
 - AlivcLiveLicenseCheckResultCodeUninitialized uninitialized
 */

typedef NS_ENUM(NSInteger, AlivcLiveLicenseCheckResultCode) {
    AlivcLiveLicenseCheckResultCodeSuccess = 0,
    AlivcLiveLicenseCheckResultCodeCertInvalid = 1,
    AlivcLiveLicenseCheckResultCodeCertExpired = 2,
    AlivcLiveLicenseCheckResultCodeLicenseExpired = 3,
    AlivcLiveLicenseCheckResultCodeAppIdInvalid   = 4,
    AlivcLiveLicenseCheckResultCodeLicenseError = 5,
    AlivcLiveLicenseCheckResultCodeBusinessInvalid = 6,
    AlivcLiveLicenseCheckResultCodePlatformInvalid = 7,
    AlivcLiveLicenseCheckResultCodeUninitialized = 8,
};

/**
 视图显示模式
 - AlivcLivePlayRenderModeAuto 自动模式
 - AlivcLivePlayRenderModeStretch 延伸模式
 - AlivcLivePlayRenderModeFill 填充模式
 - AlivcLivePlayRenderModeCrop 裁剪模式
 */

/****
 The view render mode
 - AlivcLivePlayRenderModeAuto Automatic mode
 - AlivcLivePlayRenderModeStretch Stretch mode
 - AlivcLivePlayRenderModeFill Fill mode
 - AlivcLivePlayRenderModeCrop Crop mode
 */
typedef NS_ENUM(NSUInteger, AlivcLivePlayRenderMode) {
    AlivcLivePlayRenderModeAuto    = 0,
    AlivcLivePlayRenderModeStretch = 1,
    AlivcLivePlayRenderModeFill    = 2,
    AlivcLivePlayRenderModeCrop    = 3,
};


/**
 视频旋转角度
 - AlivcLivePlayRotationMode_0 视频旋转角度 - 0
 - AlivcLivePlayRotationMode_90 视频旋转角度 - 90
 - AlivcLivePlayRotationMode_180 视频旋转角度 - 180
 - AlivcLivePlayRotationMode_270 视频旋转角度 - 270
 */

/****
 The video rotation angle
 - AlivcLivePlayRotationMode_0  The video rotation angle - 0
 - AlivcLivePlayRotationMode_90  The video rotation angle - 90
 - AlivcLivePlayRotationMode_180  The video rotation angle - 180
 - AlivcLivePlayRotationMode_270  The video rotation angle - 270
 */
typedef NS_ENUM(NSInteger, AlivcLivePlayRotationMode) {
    AlivcLivePlayRotationMode_0    = 0,
    AlivcLivePlayRotationMode_90   = 90,
    AlivcLivePlayRotationMode_180  = 180,
    AlivcLivePlayRotationMode_270  = 270,
};

/**
 云端混流（转码）裁剪模式
 - AlivcLiveTranscodingCropModeCrop 剪裁
 - AlivcLiveTranscodingCropModeFill 填充
*/

/****
 mixed-stream transcoding
 - AlivcLiveTranscodingCropModeCrop Crop mode
 - AlivcLiveTranscodingCropModeFill Fill mode
*/
typedef NS_ENUM(NSInteger, AlivcLiveTranscodingCropMode) {
    AlivcLiveTranscodingCropModeCrop = 1,
    AlivcLiveTranscodingCropModeFill = 2
};

/**
 互动模式拉流错误码
 - AlivcLivePlayErrorStreamNotFound 播放URL指定的播放流不存在
 - AlivcLivePlayErrorStreamStopped 播放URL指定的播放流已停止推流
 */

/****
 Live interaction player engine play error code
 - AlivcLivePlayErrorStreamNotFound The stream specified by the streaming URL does not exist.
 - AlivcLivePlayErrorStreamStopped The stream specified by the streaming URL is stopped.
 */
typedef NS_ENUM(NSInteger, AlivcLivePlayerError) {
    AlivcLivePlayErrorStreamNotFound = 1,
    AlivcLivePlayErrorStreamStopped = 2
};

/**
 * @brief 视频数据类型
 */

/****
 * @brief video format type
 */
typedef NS_ENUM(NSInteger, AlivcLiveBufferType) {
    /** YUV */
    AlivcLiveBufferType_Raw_Data = 0,
    /** CVPixelBuffer */
    AlivcLiveBufferType_CVPixelBuffer,
};

/**
 * @brief SDK监控多个质量信息，针对嵌入式场景，可以指定精简的监控信息
 * AlivcLivePushMonitorLevelAll 监控全量质量信息
 * AlivcLivePushMonitorLevelCut 监控精简质量信息
 * AlivcLivePushMonitorLevelNone 不上传任何质量信息
 */

/****
 * @brief SDK The SDK provides quality monitoring. For embedment scenarios, you can specify specific monitoring metrics
 * AlivcLivePushMonitorLevelAll monitoring all quality information
 * AlivcLivePushMonitorLevelCut monitoring cut quality information
 * AlivcLivePushMonitorLevelNone monitoring none quality information
 */
typedef NS_ENUM(NSInteger, AlivcLivePushMonitorLevel) {
    AlivcLivePushMonitorLevelAll = 0,
    AlivcLivePushMonitorLevelCut = 1,
    AlivcLivePushMonitorLevelNone = 2
};

/**
 * @brief 变声音效模式
 * AlivcLivePushAudioEffectvVoiceChange_OFF 关闭变声音效
 * AlivcLivePushAudioEffectvVoiceChange_OLD_MAN 老人
 * AlivcLivePushAudioEffectvVoiceChange_BABYBOY 男孩
 * AlivcLivePushAudioEffectvVoiceChange_BABYGILR 女孩
 * AlivcLivePushAudioEffectvVoiceChange_ROBOT 机器人
 * AlivcLivePushAudioEffectvVoiceChange_DAIMO 大魔王
 * AlivcLivePushAudioEffectvVoiceChange_KTV KTV
 * AlivcLivePushAudioEffectvVoiceChangeR_ECHO 回声
 * AlivcLivePushAudioEffectvVoiceChange_MAX 占位符
 */

/****
 * @brief Voice Changer Mode
 * AlivcLivePushAudioEffectvVoiceChange_OFF turn off voice changer
 * AlivcLivePushAudioEffectvVoiceChange_OLD_MAN old man
 * AlivcLivePushAudioEffectvVoiceChange_BABYBOY baby boy
 * AlivcLivePushAudioEffectvVoiceChange_BABYGILR baby girl
 * AlivcLivePushAudioEffectvVoiceChange_ROBOT robot
 * AlivcLivePushAudioEffectvVoiceChange_DAIMO demon king
 * AlivcLivePushAudioEffectvVoiceChange_KTV KTV
 * AlivcLivePushAudioEffectvVoiceChangeR_ECHO echo
 * AlivcLivePushAudioEffectvVoiceChange_MAX max
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioEffectVoiceChangeMode) {
    AlivcLivePushAudioEffectvVoiceChange_OFF = 0,
    AlivcLivePushAudioEffectvVoiceChange_OLD_MAN,
    AlivcLivePushAudioEffectvVoiceChange_BABYBOY,
    AlivcLivePushAudioEffectvVoiceChange_BABYGILR,
    AlivcLivePushAudioEffectvVoiceChange_ROBOT,
    AlivcLivePushAudioEffectvVoiceChange_DAIMO,
    AlivcLivePushAudioEffectvVoiceChange_KTV,
    AlivcLivePushAudioEffectvVoiceChangeR_ECHO,
    AlivcLivePushAudioEffectvVoiceChange_MAX,
};

/**
 * @brief 音效混响模式
 * AlivcLivePushAudioEffectReverb_Off 关闭混响
 * AlivcLivePushAudioEffectReverb_Vocal_I 人声I
 * AlivcLivePushAudioEffectReverb_Vocal_II 人声II
 * AlivcLivePushAudioEffectReverb_Bathroom 澡堂
 * AlivcLivePushAudioEffectReverb_Small_Room_Bright 明亮小房间
 * AlivcLivePushAudioEffectReverb_Small_Room_Dark 黑暗小房间
 * AlivcLivePushAudioEffectReverb_Medium_Room 中等房间
 * AlivcLivePushAudioEffectReverb_Large_Room 大房间
 * AlivcLivePushAudioEffectReverb_Church_Hall 教堂走廊
 * AlivcLivePushAudioEffectReverb_Mode_Max 占位符 
 */

/****
 * @brief Sound Reverb Mode
 * AlivcLivePushAudioEffectReverb_Off turn off reverb
 * AlivcLivePushAudioEffectReverb_Vocal_I vocal I
 * AlivcLivePushAudioEffectReverb_Vocal_II vocal II
 * AlivcLivePushAudioEffectReverb_Bathroom bath room
 * AlivcLivePushAudioEffectReverb_Small_Room_Bright small bright room
 * AlivcLivePushAudioEffectReverb_Small_Room_Dark samll dark room
 * AlivcLivePushAudioEffectReverb_Medium_Room
 * AlivcLivePushAudioEffectReverb_Large_Room large room
 * AlivcLivePushAudioEffectReverb_Church_Hall church hall
 * AlivcLivePushAudioEffectReverb_Mode_Max max
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioEffectReverbMode) {
    AlivcLivePushAudioEffectReverb_Off = 0,
    AlivcLivePushAudioEffectReverb_Vocal_I,
    AlivcLivePushAudioEffectReverb_Vocal_II,
    AlivcLivePushAudioEffectReverb_Bathroom,
    AlivcLivePushAudioEffectReverb_Small_Room_Bright,
    AlivcLivePushAudioEffectReverb_Small_Room_Dark,
    AlivcLivePushAudioEffectReverb_Medium_Room,
    AlivcLivePushAudioEffectReverb_Large_Room,
    AlivcLivePushAudioEffectReverb_Church_Hall,
    AlivcLivePushAudioEffectReverb_Mode_Max,
};

/**
 * @brief 网络质量
 * AlivcLiveNetworkQualityExcellent 网络极好，流程度清晰度质量好
 * AlivcLiveNetworkQualityGood 网络好，流畅度清晰度和极好差不多
 * AlivcLiveNetworkQualityPoor 网络较差，音视频流畅度清晰度有瑕疵，不影响沟通
 * AlivcLiveNetworkQualityBad 网络差，视频卡顿严重，音频能正常沟通
 * AlivcLiveNetworkQualityVeryBad 网络极差，基本无法沟通
 * AlivcLiveNetworkQualityDisconnect 网络中断
 * AlivcLiveNetworkQualityUnknow 未知
 */

/****
 * @brief Network quality
 * AlivcLiveNetworkQualityExcellent The network is excellent, and the stream definition and quality are good
 * AlivcLiveNetworkQualityGood The network is good, and the fluency and clarity are about the same as excellent
 * AlivcLiveNetworkQualityPoor The network is poor, and the audio and video fluency and clarity are flawed, which does not affect communication
 * AlivcLiveNetworkQualityBad The network is poor, the video freezes seriously, but the audio can communicate normally
 * AlivcLiveNetworkQualityVeryBad The network is extremely poor, and it is basically impossible to communicate
 * AlivcLiveNetworkQualityDisconnect Network interruption
 * AlivcLiveNetworkQualityUnknow Unknow
 */
typedef NS_ENUM(NSUInteger, AlivcLiveNetworkQuality) {
    AlivcLiveNetworkQualityExcellent  = 0,
    AlivcLiveNetworkQualityGood       = 1,
    AlivcLiveNetworkQualityPoor       = 2,
    AlivcLiveNetworkQualityBad        = 3,
    AlivcLiveNetworkQualityVeryBad    = 4,
    AlivcLiveNetworkQualityDisconnect = 5,
    AlivcLiveNetworkQualityUnknow     = 6,
};

/**
 * @brief 被踢掉原因
 * AlivcLivePushKickedOutTypeKickedOut 当前user被踢出房间，需要退出直播间
 * AlivcLivePushKickedOutTypeChannelTerminated 直播间被删除，需要退出直播间
 * AlivcLivePushKickedOutTypeUserReplaced 相同userID在其他设备进入直播间，当前设备被下线
 */

/****
 * @brief The specific reason for being kicked out
 * AlivcLivePushKickedOutTypeKickedOut The current user is kicked out of the room and needs to exit the live broadcast room
 * AlivcLivePushKickedOutTypeChannelTerminated The live room is deleted, you need to exit the live room
 * AlivcLivePushKickedOutTypeUserReplaced The same userID enters the live broadcast room on other devices, and the current device is offline
 */
typedef NS_ENUM(NSInteger, AlivcLivePushKickedOutType) {
    AlivcLivePushKickedOutTypeKickedOut          = 1,
    AlivcLivePushKickedOutTypeChannelTerminated    = 2,
    AlivcLivePushKickedOutTypeUserReplaced         = 3,
};

/**
 * @brief  混流成员流类型
 * AlivcLiveMixStreamTypeAudioVideo 混入音视频
 * AlivcLiveMixStreamTypePureAudio 混入音频， 不混视频
 * AlivcLiveMixStreamTypePureVideo 混入视频，不混音频
 */

/****
 * @brief  Mixed member stream type
 * AlivcLiveMixStreamTypeAudioVideo Mix audio and video
 * AlivcLiveMixStreamTypePureAudio Mix audio, don't mix video
 * AlivcLiveMixStreamTypePureVideo Mix  video, don't mix audio
 */
typedef NS_ENUM(NSInteger, AlivcLiveMixStreamType) {
    AlivcLiveMixStreamTypeAudioVideo          = 0,
    AlivcLiveMixStreamTypePureAudio           = 1,
    AlivcLiveMixStreamTypePureVideo           = 2,
};

