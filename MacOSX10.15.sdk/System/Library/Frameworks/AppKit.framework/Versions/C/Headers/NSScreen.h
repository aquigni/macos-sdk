/*
	NSScreen.h
	Application Kit
	Copyright (c) 1994-2018, Apple Inc.
	All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSGeometry.h>
#import <Foundation/NSNotification.h>
#import <AppKit/NSGraphics.h>

NS_ASSUME_NONNULL_BEGIN
API_UNAVAILABLE_BEGIN(ios)

@class NSColorSpace;

@interface NSScreen : NSObject

@property (class, readonly, copy) NSArray<NSScreen *> *screens;	/* All screens; first one is "zero" screen */
@property (class, readonly, nullable, strong) NSScreen *mainScreen;	/* Screen with key window */
@property (class, readonly, nullable, strong) NSScreen *deepestScreen;

/* screensHaveSeparateSpaces returns YES if each screen has its own set of spaces.  This is a system setting and does not necessarily imply that there are multiple screens, nor that there are multiple spaces on any one screen
*/
@property (class, readonly) BOOL screensHaveSeparateSpaces API_AVAILABLE(macos(10.9));

@property (readonly) NSWindowDepth depth;
@property (readonly) NSRect frame;
@property (readonly) NSRect visibleFrame;
@property (readonly, copy) NSDictionary<NSDeviceDescriptionKey, id> *deviceDescription;
@property (nullable, readonly, strong) NSColorSpace *colorSpace API_AVAILABLE(macos(10.6));

@property (readonly) const NSWindowDepth *supportedWindowDepths NS_RETURNS_INNER_POINTER; /* 0 terminated */

/* canRepresentDisplayGamut: returns YES if the colorSpace of the receiving screen is capable of representing the given display gamut
 */
- (BOOL)canRepresentDisplayGamut:(NSDisplayGamut)displayGamut API_AVAILABLE(macos(10.12));

/* Convert to/from the device pixel aligned coordinates sytem of a display 
 */
- (NSRect)convertRectToBacking:(NSRect)rect API_AVAILABLE(macos(10.7));
- (NSRect)convertRectFromBacking:(NSRect)rect API_AVAILABLE(macos(10.7));

/* Uses NSIntegralRectWithOptions() to produce a pixel aligned rectangle on the target screen from the given input rectangle in global screen coordinates.
 */
- (NSRect)backingAlignedRect:(NSRect)rect options:(NSAlignmentOptions)options API_AVAILABLE(macos(10.7));

/* Returns the scale factor representing the number of backing store pixels corresponding to each linear unit in screen space on this NSScreen. This method is provided for rare cases when the explicit scale factor is needed.  Please use -convert*ToBacking: methods whenever possible. 
 */
@property (readonly) CGFloat backingScaleFactor API_AVAILABLE(macos(10.7)); 

@property (readonly, copy) NSString *localizedName API_AVAILABLE(macos(10.15));

@end


/* Notifications */
APPKIT_EXTERN NSNotificationName const NSScreenColorSpaceDidChangeNotification API_AVAILABLE(macos(10.6)); /* The notification object is the screen whose profile has changed */


// Extended Dynamic Range
@interface NSScreen ()

/* Returns the current maximum color component value for the screen. Typically the maximum is 1.0, but if any rendering context on the screen has requested extended dynamic range, it may return a value greater than 1.0, depending on system capabilities and other conditions. Only rendering contexts that support extended dynamic range can use values greater than 1.0. When the value changes, NSApplicationDidChangeScreenParametersNotification will be posted.
 */
@property (readonly) CGFloat maximumExtendedDynamicRangeColorComponentValue API_AVAILABLE(macos(10.11));

/* Returns the maximum color component value that the screen is capable of when extended dynamic range is enabled, regardless of whether or not extended dynamic range is currently enabled.
 */
@property (readonly) CGFloat maximumPotentialExtendedDynamicRangeColorComponentValue API_AVAILABLE(macos(10.14.6));

/* Returns the current maximum color component value for reference rendering to the screen. If values beyond this are used, the display hardware may adjust content to fit into its dynamic range. For screens that do not support reference rendering, this will return 0.
 */
@property (readonly) CGFloat maximumReferenceExtendedDynamicRangeColorComponentValue API_AVAILABLE(macos(10.14.6));

@end


@interface NSScreen (NSDeprecated)

/*  This method is deprecated and should not be used by applications targeting Mac OS X 10.7 or later.
 The implementation of this method will always return 1.0.  Please use -convertRectToBacking: or -backingScaleFactor instead.
 */
- (CGFloat)userSpaceScaleFactor API_DEPRECATED("Use -convertRectToBacking: or -backingScaleFactor instead", macos(10.4,10.7));

@end

API_UNAVAILABLE_END
NS_ASSUME_NONNULL_END
