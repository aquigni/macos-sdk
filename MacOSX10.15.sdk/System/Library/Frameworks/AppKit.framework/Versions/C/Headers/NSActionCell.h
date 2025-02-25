/*
        NSActionCell.h
	Application Kit
	Copyright (c) 1994-2018, Apple Inc.
	All rights reserved.
*/

#import <AppKit/NSCell.h>

NS_ASSUME_NONNULL_BEGIN
API_UNAVAILABLE_BEGIN(ios)

@interface NSActionCell : NSCell

@property (nullable, weak) id target; // Target is weak for zeroing-weak compatible objects in apps linked on 10.10 or later. Otherwise the behavior of this property is 'assign’.
@property (nullable) SEL action;
@property NSInteger tag;

@end

API_UNAVAILABLE_END
NS_ASSUME_NONNULL_END
