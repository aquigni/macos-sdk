#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIFontPickerViewController.h>)
//
//  UIFontPickerViewController.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIFontDescriptor.h>
#import <UIKit/UIFontPickerViewControllerConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

@class UIFontPickerViewController;

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(tvos, watchos) @protocol UIFontPickerViewControllerDelegate <NSObject>

@optional

- (void)fontPickerViewControllerDidCancel:(UIFontPickerViewController *)viewController;

- (void)fontPickerViewControllerDidPickFont:(UIFontPickerViewController *)viewController;

@end

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(tvos, watchos) @interface UIFontPickerViewController : UIViewController

/*
  UIFontPickerViewController allows selecting a font family or specific face based on the configuration provided. Mutating the configuration after invoking the initializer has no effect on the view controller.
*/
- (instancetype)initWithConfiguration:(UIFontPickerViewControllerConfiguration *)configuration NS_DESIGNATED_INITIALIZER;

@property (readonly, copy, nonatomic) UIFontPickerViewControllerConfiguration *configuration;

@property (nullable, weak, nonatomic) id<UIFontPickerViewControllerDelegate> delegate;

@property (nullable, strong, nonatomic) UIFontDescriptor *selectedFontDescriptor;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIFontPickerViewController.h>
#endif
