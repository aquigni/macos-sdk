/*
        NSTableHeaderCell.h
        Application Kit
        Copyright (c) 1995-2018, Apple Inc.
        All rights reserved.
*/
#import <AppKit/NSTextFieldCell.h>

NS_ASSUME_NONNULL_BEGIN
API_UNAVAILABLE_BEGIN(ios)

@interface NSTableHeaderCell : NSTextFieldCell

/* Draws a sorting indicator given a cellFrame. If priority is 0, this is the primary sort indicator. If ascending is YES, a "^" indicator will be drawn.  Override this routine to customimze the sorting UI.
*/
- (void)drawSortIndicatorWithFrame:(NSRect)cellFrame inView:(NSView *)controlView ascending:(BOOL)ascending priority:(NSInteger)priority;

/* Returns the location to display the sorting indicator given the cellFrame.
*/
- (NSRect)sortIndicatorRectForBounds:(NSRect)rect;

@end

API_UNAVAILABLE_END
NS_ASSUME_NONNULL_END
