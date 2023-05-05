//
//  AlivcLivePushError.h
//  AlivcLiveCaptureLib
//
//  Created by TripleL on 2017/9/25.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface AlivcLivePushError : NSObject


/**
 错误描述
 */

/****
 error description
 */
@property (nonatomic, strong) NSString* errorDescription;


/**
 错误码
 */

/****
 error code
 */
@property (nonatomic, assign) NSInteger errorCode;

@end
