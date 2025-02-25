/*
 File:       UTCoreTypes.h
 
 Contains:   String constants for core uniform type identifiers
 
 Copyright:  (c) 2004-2012 by Apple Inc. All rights reserved.
 
 Bugs?:      For bug reports, consult the following page on
 the World Wide Web:
 
 http://developer.apple.com/bugreporter/
 
 */

#if TARGET_OS_IPHONE && (TARGET_OS_EMBEDDED || TARGET_OS_SIMULATOR || !TARGET_OS_UIKITFORMAC)
#import <CoreServices/UTCoreTypes.h>
#else
#import <CoreServices/CoreServices.h>
#endif

