//
//  PKToolPicker.h
//  PencilKit
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PKTool, PKToolPicker;

@protocol PKToolPickerObserver <NSObject>

@optional
/// Tells the delegate that the selected tool was changed by the user.
///
/// @param toolPicker  The tool picker that changed.
- (void)toolPickerSelectedToolDidChange:(PKToolPicker *)toolPicker;

/// Tells the delegate that the ruler active state was changed by the user.
///
/// @param toolPicker  The tool picker that changed.
- (void)toolPickerIsRulerActiveDidChange:(PKToolPicker *)toolPicker;

/// Tells the delegate that the tool picker UI changed visibility.
///
/// @param toolPicker  The tool picker that changed.
- (void)toolPickerVisibilityDidChange:(PKToolPicker *)toolPicker;

/// Tells the delegate that the frames the tool picker obscures changed.
/// Note, the obscured frames for a view can also change when that view
/// changes, not just when this delegate method is called.
///
/// @param toolPicker  The tool picker that changed.
- (void)toolPickerFramesObscuredDidChange:(PKToolPicker *)toolPicker;

@end


/// A user interface for selecting a PKTool.
@interface PKToolPicker : NSObject

/// Add an observer for a tool picker changes.
///
/// Adding a `PKCanvasView` as an observer, will also set its initial state.
/// Observers are held weakly.
- (void)addObserver:(id<PKToolPickerObserver>)observer NS_SWIFT_NAME(addObserver(_:));

/// Remove an observer for a tool picker changes.
- (void)removeObserver:(id<PKToolPickerObserver>)observer NS_SWIFT_NAME(removeObserver(_:));

/// Sets when this tool picker should be visible.
///
/// @param visible  The visible state of this tool picker.
/// @param responder  The first responder for which this visible state applies.
- (void)setVisible:(BOOL)visible forFirstResponder:(UIResponder *)responder;

/// The currently selected tool.
@property (nonatomic, strong) PKTool *selectedTool;

/// Is the ruler toggled such that it should be active on canvases.
@property (nonatomic, getter=isRulerActive) BOOL rulerActive;

/// Is the tool picker visible.
@property (nonatomic, readonly) BOOL isVisible;

/// The frame within a specific view that the tool picker covers.
///
/// @param view The view in which to return the frame to avoid.
/// @return The rect in `view` that the tool picker obscures. Will return
/// `CGRectNull` if no rect is obscured, or the tool picker is movable.
- (CGRect)frameObscuredInView:(UIView *)view;

/// Returns the shared `PKToolPicker` instance for a window.
/// The returned tool picker object is typically shared between window in the same UIWindowScene.
+ (nullable PKToolPicker *)sharedToolPickerForWindow:(UIWindow *)window;

- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
