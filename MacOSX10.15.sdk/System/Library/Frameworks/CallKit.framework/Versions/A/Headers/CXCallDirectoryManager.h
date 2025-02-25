//
//  CXCallDirectoryManager.h
//  CallKit
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CXCallDirectoryEnabledStatus) {
    CXCallDirectoryEnabledStatusUnknown = 0,
    CXCallDirectoryEnabledStatusDisabled = 1,
    CXCallDirectoryEnabledStatusEnabled = 2,
} API_AVAILABLE(ios(10.0), uikitformac(13.0)) API_UNAVAILABLE( tvos) API_UNAVAILABLE(macos, watchos);

CX_EXTERN API_AVAILABLE(ios(10.0), uikitformac(13.0)) API_UNAVAILABLE( tvos) API_UNAVAILABLE(macos, watchos)
@interface CXCallDirectoryManager : NSObject

@property (readonly, class) CXCallDirectoryManager *sharedInstance;

- (void)reloadExtensionWithIdentifier:(NSString *)identifier completionHandler:(nullable void (^)(NSError *_Nullable error))completion;
- (void)getEnabledStatusForExtensionWithIdentifier:(NSString *)identifier completionHandler:(void (^)(CXCallDirectoryEnabledStatus enabledStatus, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
