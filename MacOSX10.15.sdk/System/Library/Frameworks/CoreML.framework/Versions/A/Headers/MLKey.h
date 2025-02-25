//
//  MLKey.h
//  CoreML
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreML/MLExport.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * A class representing key used to store any value against
 */
API_AVAILABLE(macos(10.15), ios(13.0))
@interface MLKey : NSObject <NSCopying>

// Name of the key
@property (readonly, nonatomic) NSString *name;

// cannot construct MLKey without parameters.
- (instancetype)init NS_UNAVAILABLE;

// cannot construct MLKey without parameters.
+ (id)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

