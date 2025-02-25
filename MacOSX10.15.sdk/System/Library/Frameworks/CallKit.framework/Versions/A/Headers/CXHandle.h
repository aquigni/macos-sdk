//
//  CXHandle.h
//  CallKit
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CXHandleType) {
    CXHandleTypeGeneric = 1,
    CXHandleTypePhoneNumber = 2,
    CXHandleTypeEmailAddress = 3,
} API_AVAILABLE(ios(10.0), uikitformac(13.0)) API_UNAVAILABLE( tvos) API_UNAVAILABLE(macos, watchos);

CX_EXTERN API_AVAILABLE(ios(10.0), uikitformac(13.0)) API_UNAVAILABLE( tvos) API_UNAVAILABLE(macos, watchos)
@interface CXHandle : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, readonly) CXHandleType type;
@property (nonatomic, readonly, copy) NSString *value;

- (instancetype)initWithType:(CXHandleType)type value:(NSString *)value NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

- (BOOL)isEqualToHandle:(CXHandle *)handle;

@end

NS_ASSUME_NONNULL_END
