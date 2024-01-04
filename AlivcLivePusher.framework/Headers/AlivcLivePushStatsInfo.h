//
//  AlivcLivePushStatusInfo.h
//  AlivcLiveCaptureLib
//
//  Created by TripleL on 2017/9/25.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlivcLivePushConstants.h"

/**
 直播连麦场景RTC相关的上下行数据
 */

/****
 Live push engine  RTC performance
 */
@interface AlivcLiveRTCPushStatsInfo : NSObject

/*! 通话时长(s) */
@property (nonatomic, assign) long long callDuration;

/*! 可用带宽(kb) */
@property (nonatomic, assign) long long availableSentKbitrate;

/*! 总发送码率(kb) */
@property (nonatomic, assign) long long sentKbitrate;

/*! 总接收码率(kb) */
@property (nonatomic, assign) long long rcvdKbitrate;

/*! 总发送数据量(bytes) */
@property (nonatomic, assign) long long sentBytes;

/*! 总接收数据量(bytes) */
@property (nonatomic, assign) long long rcvdBytes;

/*! 视频接受码率(kb) */
@property (nonatomic, assign) long long videoRcvdKbitrate;

/*! 视频发送码率(kb) */
@property (nonatomic, assign) long long videoSentKbitrate;

/*! 客户端到服务器的丢包率(%) */
@property (nonatomic, assign) long long sentLossRate;

/*! 客户端到服务器的丢包数 */
@property (nonatomic, assign) long long sentLossPkts;

/*! 客户端到服务器的总包数 */
@property (nonatomic, assign) long long sentExpectedPkts;

/*! 服务器到客户端的下行丢包率（%） */
@property (nonatomic, assign) long long rcvdLossRate;

/*! 服务器到客户端的下行丢包数 */
@property (nonatomic, assign) long long rcvdLossPkts;

/*! 服务器到客户端的下行总包数 */
@property (nonatomic, assign) long long rcvdExpectedPkts;

/*! 客户端到服务器的延迟(ms) */
@property (nonatomic, assign) long long lastmileDelay;

/*! 进程CPU使用量(%) */
@property (nonatomic, assign) float cpuUsage;

/*! 系统CPU使用量(%) */
@property (nonatomic, assign) float systemCpuUsage;
@end


/**
 推流性能参数类
 */

/****
 Live push engine performance
 */
@interface AlivcLivePushStatsInfo : NSObject

#pragma mark - system

/**
 当前推流CPU占比
 * 单位 : %
 */

/****
 The current CPU usage for live pusher engine
 * 单位 : %
 */
@property (nonatomic, assign) float CPUHold;


/**
 当前推流内存占比
 * 单位 : %
 */

/****
 The current memory usage for  live pusher engine
 * 单位 : %
 */
@property (nonatomic, assign) float memoryHold;



#pragma mark - video capture

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
@property(nonatomic, assign) NSUInteger videoHeight;

/**
 视频采集FPS
 * 单位 : Frames per Second
 */

/****
 The FPS for video capture
 * Uint : Frames per Second
 */
@property (nonatomic, assign) int videoCaptureFps;


/**
 当前视频采集PTS
 */

/****
 The current PTS for video capture
 */
@property (nonatomic, assign) uint64_t currentlyVideoCapturePts;



#pragma mark - audio capture

/**
 当前音频采集PTS
 */

/****
 The current PTS for audio capture
 */
@property (nonatomic, assign) uint64_t currentlyAudioCapturePts;



#pragma mark - audio encode

/**
 音频编码码率
 * 单位 : Kbps
 */

/****
 The audio encode bitrate
 * Unit : Kbps
 */
@property (nonatomic, assign) int audioEncodedBitrate;


/**
 音频编码FPS
 * 单位 : Frames per Second
 */

/****
 The audio encode  FPS
 * Unit : Frames per Second
 */
@property (nonatomic, assign) int audioEncodedFps;


/**
 音频编码队列帧数
 */

/****
 The number of frames in the audio encoding buffer
 */
@property (nonatomic, assign) int audioFramesInEncodeBuffer;

/**
 设置的音频编码模式
 * 0:硬编  1:软编
 */

/****
 The specified audio encoding mode.
 * 0:hard encode  1:soft encode
 */
@property (nonatomic, assign) int audioEncoderMode;

/**
 设置的音频声道数
 */

/****
 The specified number of sound channels
 */
@property (nonatomic, assign) int channel;

/**
 设置的音频采样率
 */

/****
 The specified audio sample rate.
 */
@property (nonatomic, assign) int audioSampleRate;

/**
 音频采集音量
 */

/****
 The volume for  audio captured
 */
@property (nonatomic, assign) int audioCaptureVolume;

#pragma mark - video render

/**
 视频渲染FPS
 * 单位 : Frames per Second
 */

/****
  Video render frames per second
 * Unit : Frames per Second
 */
@property (nonatomic, assign) int videoRenderFps;


/**
 视频渲染队列帧数
 */

/****
 The number of frames in the video rendering buffer
 */
@property (nonatomic, assign) int videoFramesInRenderBuffer;


/**
 平均每帧渲染耗时
 */

/****
 The average time consumed for rendering of each frame
 */
@property (nonatomic, assign) int videoRenderConsumingTimePerFrame;



#pragma mark - video encode

/**
 视频编码码率
 * 单位 :基础模式：Kbps ，互动模式：bps
 */

/****
 The video encoded bitrate
 * 单位 : Kbps
 */
@property (nonatomic, assign) int videoEncodedBitrate;


/**
 视频编码队列帧数
 */

/****
 The number of frames in the video encoding buffer
 */
@property (nonatomic, assign) int videoFramesInEncodeBuffer;


/**
 视频编码FPS
 * 单位 : Frames per Second
 */

/****
 video encoded frames per second
 * Unit : Frames per Second
 */
@property (nonatomic, assign) int videoEncodedFps;


/**
 视频编码总帧数
 */

/****
 The total number of frames for video encoded
 */
@property (nonatomic, assign) uint64_t totalFramesOfEncodedVideo;


/**
 视频编码总耗时
 * 单位 : ms
 */

/****
 The total Time of encoded video
 * Unit : ms
 */
@property (nonatomic, assign) uint64_t totalTimeOfEncodedVideo;


/**
 设置的视频编码码率参数
 * 单位 : Kbps
 */

/****
 Set the video encode rate parameters
 * 单位 : Kbps
 */
@property (nonatomic, assign) int videoEncodeParam;

/**
 每秒平均QP
 */

@property (nonatomic, assign)  int videoAvgQp;


/**
 设置的视频编码模式
 * 0:硬编  1:软编
 */

/****
 Set the video encode mode parameters
 * 0:硬编  1:软编
 */
@property (nonatomic, assign) int videoEncoderMode;

/**
 设置的视频GOP大小
 */

/****
 video gop size
 */
@property (nonatomic, assign) int videoGop;


#pragma mark - pusher

/**
 当前推流协议
 */

/****
  live push engine protocol
 */
@property (nonatomic, assign) AlivcLivePushPublishType publishType;

/**
 音频上传码率
 * 单位 : Kbps
 */

/****
 audio send bitrate
 * Unit : Kbps
 */
@property (nonatomic, assign) int audioUploadBitrate;


/**
 视频上传码率
 *  单位 :基础模式：Kbps ，互动模式：bps
 */

/****
 video send itrate
 * Unit : Kbps
 */
@property (nonatomic, assign) int videoUploadBitrate;


/**
 推流队列中的音频buffer个数
 */

/****
 The number of frames in the audio sending buffer
 */
@property (nonatomic, assign) int audioPacketsInUploadBuffer;


/**
 推流队列中的视频buffer个数
 */

/****
 The number of frames in the video sending buffer
 */
@property (nonatomic, assign) int videoPacketsInUploadBuffer;


/**
 当前视频上传FPS
 * 单位 : Frames per Second
 */

/****
 Current video upload FPS
 * Unit : Frames per Second
 */
@property (nonatomic, assign) int videoUploadFps;


/**
 当前音频上传FPS
 * 单位 : Frames per Second
 */

/****
 Current audio upload FPS
 * Unit : Frames per Second
 */
@property (nonatomic, assign) int audioUploadFps;


/**
 当前上传视频帧PTS
 */

/****
 Current video upload PTS
 */
@property (nonatomic, assign) uint64_t currentlyUploadedVideoFramePts;


/**
 当前上传音频帧PTS
 */

/****
 Current audio upload PTS
 */
@property (nonatomic, assign) uint64_t currentlyUploadedAudioFramePts;


/**
 当前最近一次上传的关键帧PTS
 */

/****
 The keyframe PTS of the latest upload
 */
@property (nonatomic, assign) uint64_t previousVideoKeyframePts;


/**
 推流队列中最后一帧视频PTS
 */

/****
 PTS of the last frame of video in the streaming queue
 */
@property (nonatomic, assign) uint64_t lastVideoPtsInBuffer;


/**
 推流队列中最后一帧音频PTS
 */

/****
 The audio PTS of the last frame in the streaming queue
 */
@property (nonatomic, assign) uint64_t lastAudioPtsInBuffer;


/**
 推流数据总大小
 */

/****
 The total size of streaming data
 */
@property (nonatomic, assign) uint64_t totalSizeOfUploadedPackets;


/**
 推流总时长
 */

/****
 Total streaming push time
 */
@property (nonatomic, assign) uint64_t totalTimeOfUploading;


/**
 视频推流总帧数
 */

/****
 The total number of frames of video streaming
 */
@property (nonatomic, assign) uint64_t totalFramesOfUploadedVideo;


/**
 视频丢帧总数
 */

/****
 Total number of dropped video frames
 */
@property (nonatomic, assign) int totalDurationOfDropingVideoFrames;


/**
 音频丢帧总数
 */

/****
 Total number of dropped audio frames
 */
@property (nonatomic, assign) int totalDurationOfDropingAudioFrames;


/**
 视频丢帧总次数
 */

/****
 Total video frame drops
 */
@property (nonatomic, assign) int totalTimesOfDropingVideoFrames;


/**
 断网总次数
 */

/****
 Total number of network disconnections
 */
@property (nonatomic, assign) int totalTimesOfDisconnect;


/**
 重连总次数
 */

/****
 Total number of reconnections
 */
@property (nonatomic, assign) int totalTimesOfReconnect;


/**
 视频从采集到上传耗时
 * 单位 : ms
 */

/****
 Time-consuming from video capture to upload
 * Unit : ms
 */
@property (nonatomic, assign) uint64_t videoDurationFromCaptureToUpload;


/**
 音频从采集到上传耗时
 * 单位 : ms
 */

/**
 Time-consuming from audio capture to upload
 * Unit : ms
 */
@property (nonatomic, assign) uint64_t audioDurationFromCaptureToUpload;


/**
 推流队列当前上传帧大小
 */

/****
 Current upload frame size of the streaming queue
 */
@property (nonatomic, assign) uint64_t currentUploadPacketSize;


/**
 当前音视频PTS差异
 */

/****
 Current audio and video PTS difference
 */
@property (nonatomic, assign) uint64_t audioVideoPtsDiff;


/**
 修正前视频帧PTS
 */

/****
 Video frame PTS before correction
 */
@property (nonatomic, assign) uint64_t beforeAdjustVideoPts;


/**
 修正前音频帧PTS
 */

/****
 Audio frame PTS before correction
 */
@property (nonatomic, assign) uint64_t beforeAdjustAudioPts;


/**
 修正后视频帧PTS
 */

/****
 Corrected video frame PTS
 */
@property (nonatomic, assign) uint64_t afterAdjustVideoPts;


/**
 修正后音频帧PTS
 */

/****
 Corrected audio frame PTS
 */
@property (nonatomic, assign) uint64_t afterAdjustAudioPts;


/**
 缓冲队列中曾经最大的视频帧size
 */

/****
 The largest video frame size ever in the buffer queue
 */
@property (nonatomic, assign) uint64_t maxSizeOfVideoPacketsInBuffer;


/**
 缓冲队列中曾经最大的音频帧size
 */

/****
 The largest audio frame size ever in the buffer queue
 */
@property (nonatomic, assign) uint64_t maxSizeOfAudioPacketsInBuffer;


/**
 推流队列最近一次视频发送码率
 */

/****
 The bitrate of the last video sent by the streaming queue
 */
@property (nonatomic, assign) int latestUploadedVideoBitrate;


/**
 推流队列最近一次音频发送码率
 */

/****
 The last audio sending bit rate of the streaming queue
 */
@property (nonatomic, assign) int latestUploadedAudioBitrate;


/**
 推流队列最近一次发送包大小
 */

/****
 The size of the last packet sent by the push queue
 */
@property (nonatomic, assign) int lastUploadedSendSize;


/**
 推流队列最近一次发送时间戳
 */

/****
 The latest sending timestamp of the streaming queue
 */
@property (nonatomic, assign) int lastUploadedSendTime;

/**
 网络往返延时（ms）
 */

/****
 Network round-trip delay (ms)
 */
@property (nonatomic, assign) int rtt;

/**
 视频丢包率（%）
 */

/****
 Video loss rate
 */
@property (nonatomic, assign) int videoLostRate;

/**
 音频丢包率（%）
 */

/****
 Audio loss rate
 */
@property (nonatomic, assign) int audioLostRate;

/**
视频重传码率（kbps）
*/

/****
Video resend bitrate（kbps）
*/
@property (nonatomic, assign) int videoReSendBitRate;

/**
音频重传码率（kbps）
*/

/**
Audio resend bitrate（kbps）
*/
@property (nonatomic, assign) int audioReSendBitRate;

/**
 直播连麦场景RTC相关的上下行数据
 */
@property (nonatomic, strong) AlivcLiveRTCPushStatsInfo *rtcPushStatsInfo;

@end
