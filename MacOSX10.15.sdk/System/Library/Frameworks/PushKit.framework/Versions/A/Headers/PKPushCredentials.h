//
//  PKPushCredentials.h
//  PushKit
//
//  Copyright (c) 2014 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PushKit/PKDefines.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(10.15), uikitformac(13.0), ios(8.0), watchos(6.0), tvos(13.0))
@interface PKPushCredentials : NSObject

@property (readonly,copy) PKPushType type;
@property (readonly,copy) NSData *token;

@end

NS_ASSUME_NONNULL_END
