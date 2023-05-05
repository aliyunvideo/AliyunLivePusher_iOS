//
//  AlivcLiveBase.h
//  AlivcLivePusher
//
//  Created by aliyun on 2022/4/11.
//  Copyright © 2022 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlivcLivePushConstants.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @defgroup live 直播SDK
 *  @{
 */
/****
 * @defgroup live Live SDk
 * @{
 */
/** @} */ // end of live

/**
 * @defgroup AlivcLiveBase SDK基础接口
 * @ingroup live
 *  直播基础接口
 *  @{
 */

/****
 * @defgroup AlivcLiveBase SDK Basic Methods
 * @ingroup live
 *  Basic live pusher methods
 *  @{
 */

/**
 * @brief  SDK基础接口回调
 */

/****
 * @brief  Callbacks related to SDK basic methods
 */
@protocol AlivcLiveBaseObserver <NSObject>

/**
 * @brief SDK Licence 校验接口回调
 *
 * @param result 校验 licence 结果 AlivcLiveLicenseCheckResultCodeSuccess 成功，其他表示失败
 * @param reason 校验 licence 失败原因
 */

/****
 * @brief The callback for verification of the SDK license.
 * @param result The verification result  AlivcLiveLicenseCheckResultCodeSuccess success，othres is failure
 * @param reason The reason why the license verification fails.
 */
- (void)onLicenceCheck:(AlivcLiveLicenseCheckResultCode)result Reason:(NSString *)reason;

@end

/**
 * @brief  SDK基础接口
 */

/****
 * @brief  SDK basic methods
 */
@interface AlivcLiveBase : NSObject

/**
 * @brief 获取SDK版本号
 * @return 版本号
 */

/****
 * @brief Query the version number of the SDK.
 * @return version number
 */
+ (NSString *)getSDKVersion;


/**
 * @brief 设置 AlivcLiveBaseObserver 回调接口
 * @param observer 回调信息 {@link AlivcLiveBaseObserver }
 */

/**
 * @brief Set the callback for AlivcLiveBaseObserver
 * @param observer callback info {@link AlivcLiveBaseObserver }
 */
+ (void)setObserver:(id<AlivcLiveBaseObserver>)observer;

/**
 * @brief 设置Log级别
 * @param level Log级别 default:AlivcLivePushLogLevelError
 */

/****
 * @brief Set the log level
 * @param level Log level default:AlivcLivePushLogLevelError
 */
+ (void)setLogLevel:(AlivcLivePushLogLevel)level;

/**
 * @brief 启用或禁用控制台日志打印
 * @param enabled 指定是否启用
 */

/****
 * @brief Enable or disable console log printing.
 * @param enabled
 */
+ (void)setConsoleEnable:(BOOL)enabled;

/**
 * @brief 设置Log路径
 * @param logPath Log路径
 * @param maxPartFileSizeInKB 每个分片最大大小。最终日志总体积是 5*最大分片大小
 */

/****
 * @brief Set the log path
 * @param logPath Log path
 * @param maxPartFileSizeInKB The maximum size of each part. The total volume of logs is five times the maximum part size.
 */
+ (void)setLogPath:(NSString *)logPath maxPartFileSizeInKB:(int)maxPartFileSizeInKB;

/**
 * @brief 注册SDK
 * 请在工程的Info.plist中增加AlivcLicenseKey和AlivcLicenseFile字段
 * 在AlivcLicenseKey中填入您的LicenseKey
 * 在AlivcLicenseFile中填入您的LicenseFile路径（相对于mainBundle）；例如您的LicenseFile为"license.crt"放到mainBundle下，就填入license.crt
 * LicenseKey和LicenseFile的获取请参考文档：https://help.aliyun.com/document_detail/431730.html
 */

/****
 * @brief Register the SDK.
 * Add the AlivcLicenseKey and AlivcLicenseFile fields to the Info.plist file of the project.
 * Enter your license key in the AlivcLicenseKey field
 * Enter the path of your license file (relative to mainBundle) in the AlivcLicenseFile field. For example,
 * if you place your license file license.crt under mainBundle, enter "license.crt".
 * For more information about how to obtain the license key and license file, see:：https://help.aliyun.com/document_detail/431730.html
 */
+ (BOOL)registerSDK;

@end

/** @} */

/**** @} */

NS_ASSUME_NONNULL_END
