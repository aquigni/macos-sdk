/*
    NSUserInterfaceLayout.h
    Application Kit
    Copyright (c) 2015-2018, Apple Inc.
    All rights reserved.
 */

#import <AppKit/AppKitDefines.h>

API_UNAVAILABLE_BEGIN(ios)

typedef NS_ENUM(NSInteger, NSUserInterfaceLayoutDirection) {
    NSUserInterfaceLayoutDirectionLeftToRight = 0,
    NSUserInterfaceLayoutDirectionRightToLeft = 1
};

typedef NS_ENUM(NSInteger, NSUserInterfaceLayoutOrientation) {
    NSUserInterfaceLayoutOrientationHorizontal = 0,
    NSUserInterfaceLayoutOrientationVertical = 1
} API_AVAILABLE(macos(10.9));

API_UNAVAILABLE_END
