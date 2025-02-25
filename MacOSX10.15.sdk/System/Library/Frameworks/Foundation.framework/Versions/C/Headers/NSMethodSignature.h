/*	NSMethodSignature.h
	Copyright (c) 1994-2018, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_UNAVAILABLE("NSInvocation and related APIs not available")
@interface NSMethodSignature : NSObject
#if !__OBJC2__
{
@private
    void *_private;
    void *_reserved[5];
    unsigned long _flags;
}
#endif

+ (nullable NSMethodSignature *)signatureWithObjCTypes:(const char *)types;

@property (readonly) NSUInteger numberOfArguments;
- (const char *)getArgumentTypeAtIndex:(NSUInteger)idx NS_RETURNS_INNER_POINTER;

@property (readonly) NSUInteger frameLength;

- (BOOL)isOneway;

@property (readonly) const char *methodReturnType NS_RETURNS_INNER_POINTER;
@property (readonly) NSUInteger methodReturnLength;

@end

NS_ASSUME_NONNULL_END
