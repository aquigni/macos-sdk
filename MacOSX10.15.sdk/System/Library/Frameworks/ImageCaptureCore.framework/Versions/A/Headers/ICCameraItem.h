//------------------------------------------------------------------------------------------------------------------------------
//
//  ICCameraItem.h
//  ImageCaptureCore
//
//  Copyright (c) 2008-2019 Apple Inc., all rights reserved.
//
//  Best viewed with the following settings: Tab width 4, Indent width 2, Wrap lines, Indent wrapped lines by 3, Page guide 128.
//
//------------------------------------------------------------------------------------------------------------------------------

#pragma once

#import <ImageCaptureCore/ImageCapturePlatform.h>
#import <ImageCaptureCore/ImageCaptureConstants.h>
#import <ImageCaptureCore/ICDevice.h>
#import <CoreGraphics/CoreGraphics.h>

@class ICCameraDevice;
@class ICCameraFolder;
@class ICCameraFile;

CF_ASSUME_NONNULL_BEGIN

//----------------------------------------------------------------------------------------------------------------- ICCameraItem
/*!
  @class ICCameraItem
  @abstract ICCameraItem is an abstract class that represents an item in an ICCameraDevice object. ICCameraDevice object creates
  instances of two concrete subclasses of ICCameraItem: ICCameraFolder and ICCameraFile.
*/

@protocol ICCameraDeviceDownloadDelegate;

typedef NSString* ICCameraItemMetadataOption NS_TYPED_ENUM IC_AVAILABLE(macos(10.15), ios(13.0));
typedef NSString* ICCameraItemThumbnailOption NS_TYPED_ENUM IC_AVAILABLE(macos(10.15), ios(13.0));

IMAGECAPTURE_EXTERN ICCameraItemThumbnailOption const ICImageSourceThumbnailMaxPixelSize IC_AVAILABLE(macos(10.15), ios(13.0));
IMAGECAPTURE_EXTERN ICCameraItemThumbnailOption const ICImageSourceShouldCache IC_AVAILABLE(macos(10.15), ios(13.0));

typedef NSString* ICDownloadOption NS_TYPED_ENUM IC_AVAILABLE(macos(10.15), ios(13.0));

//------------------------------------------------------------------------------------------------------------------------------
// Allowed keys in the options dictionary used when downloading a file from the camera

/*!
  @const      ICDownloadsDirectoryURL
  @abstract   ICDownloadsDirectoryURL
  @discussion The value for this key should be an NSURL object referencing a writable directory. The downloaded files will be saved in that directory.
*/
IMAGECAPTURE_EXTERN ICDownloadOption const ICDownloadsDirectoryURL IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @const      ICSaveAsFilename
  @abstract   ICSaveAsFilename
  @discussion The value for this key should be an NSString object containing the name to be used for the downloaded file.
*/
IMAGECAPTURE_EXTERN ICDownloadOption const ICSaveAsFilename IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @const      ICSavedFilename
  @abstract   ICSavedFilename
  @discussion The value for this key will be an NSString object containing the actual name of the saved file. The options dictionary returned in didDownloadFile:error:options:contextInfo: will have this key.
*/
IMAGECAPTURE_EXTERN ICDownloadOption const ICSavedFilename IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @const      ICSavedAncillaryFiles
  @abstract   ICSavedAncillaryFiles
  @discussion The value for this key will be an NSArray object containing names of files associated with the primary file that is downloaded. The options dictionary returned in didDownloadFile:error:options:contextInfo: may have this key.
*/
IMAGECAPTURE_EXTERN ICDownloadOption const ICSavedAncillaryFiles IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @const      ICOverwrite
  @abstract   ICOverwrite
  @discussion The value for this key should be an NSNumber object representing a boolean value. If this value is YES, the downloaded file will overwrite an existing file with the same name and extension.
*/
IMAGECAPTURE_EXTERN ICDownloadOption const ICOverwrite IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @const      ICDeleteAfterSuccessfulDownload
  @abstract   ICDeleteAfterSuccessfulDownload
  @discussion The value for this key should be an NSNumber object representing a boolean value. If this value is YES, the file will be deleted from the device after it is succcessfully downloaded.
*/
IMAGECAPTURE_EXTERN ICDownloadOption const ICDeleteAfterSuccessfulDownload IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @const      ICDownloadSidecarFiles
  @abstract   ICDownloadSidecarFiles
  @discussion The value for this key should be an NSNumber object representing a boolean value. If this value is YES, all sidecar files will be downloaded along with the media file.
*/
IMAGECAPTURE_EXTERN ICDownloadOption const ICDownloadSidecarFiles IC_AVAILABLE(macos(10.4), ios(13.0));

IC_AVAILABLE(macos(10.4), ios(13.0))
@interface ICCameraItem : NSObject
{
}

/*!
  @property device
  @abstract ￼Parent device of this item.
*/
@property (nonatomic, readonly, nullable) ICCameraDevice* device IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @property parentFolder
  @abstract ￼Parent folder of this folder. The root folder's parentFolder is nil.
*/
@property (nonatomic, readonly, nullable) ICCameraFolder* parentFolder IC_AVAILABLE(macos(10.4),ios(13.0));

/*!
  @property name
  @abstract ￼Name of this item.
*/
@property (nonatomic, readonly, nullable) NSString* name IC_AVAILABLE(macos(10.4),ios(13.0));

/*!
  @property UTI
  @abstract ￼Item UTI. This is an Uniform Type Identifier string. It is one of: kUTTypeFolder, kUTTypeImage, kUTTypeMovie, kUTTypeAudio, or kUTTypeData.
*/
@property (nonatomic, readonly, nullable) NSString* UTI IC_AVAILABLE(macos(10.4),ios(13.0));

/*!
  @property fileSystemPath
  @abstract ￼The file system path of the item for items on a device with transportType of ICTransportTypeMassStorage.
*/
@property (nonatomic, readonly, nullable) NSString* fileSystemPath IC_AVAILABLE(macos(10.4),ios(13.0));

/*!
  @property locked
  @abstract ￼Indicates the protection state of this item. It is locked if the storage card in the camera is locked.
*/
@property (nonatomic, readonly, getter=isLocked) BOOL locked IC_AVAILABLE(macos(10.4),ios(13.0));

/*!
  @property raw
  @abstract ￼Indicates if the file is a raw image file.
*/
@property (nonatomic, readonly, getter=isRaw) BOOL raw IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @property inTemporaryStore
  @abstract ￼Indicates if this folder is in a temporary store. A temporary store may be used by the device when images are
   captures on the device when it is tethered to the computer.
*/
@property (nonatomic, readonly, getter=isInTemporaryStore) BOOL inTemporaryStore IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @property creationDate
  @abstract ￼Creation date of this file. This information is usually the same as the EXIF creation date.
*/
@property (nonatomic, readonly, nullable) NSDate* creationDate IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @property modificationDate
  @abstract ￼Modification date of this file. This information is usually the same as the EXIF modification date.
*/
@property (nonatomic, readonly, nullable) NSDate* modificationDate IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
 @property thumbnail
 @abstract ￼Thumbnail for the item. The value of this property is NULL unless a 'requestThumbnail' message is sent to this object.
*/
@property (nonatomic, readonly, nullable) CGImageRef thumbnail IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
 @property metadata
 @abstract ￼Metadata for the item. The value of this property is NULL unless a 'requestMetadata' message is sent to this object.
*/
@property (nonatomic, readonly, nullable) NSDictionary* metadata IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @property userData
  @abstract ￼A mutable dictionary to store arbitrary key-value pairs associated with a camera item object. This can be used by
   view objects that bind to this object to store "house-keeping" information.
*/
@property (nonatomic, readonly, nullable) NSMutableDictionary* userData IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
  @property ptpObjectHandle
  @abstract PTP object handle value if the item is on a camera that uses PTP protocol. The value of this property is set to 0
   if the camera does not use PTP protocol.
*/
@property (nonatomic, readonly) unsigned int ptpObjectHandle IC_AVAILABLE(macos(10.4), ios(13.0));

/*!
 @property addedAfterContentCatalogCompleted
 @abstract This property is set if the file is captured on the device after the device's content is fully enumerated. This does
 not apply to files added as a result of adding a new store to the device.
 */
@property (nonatomic, readonly, getter=wasAddedAfterContentCatalogCompleted) BOOL addedAfterContentCatalogCompleted IC_AVAILABLE(macos(10.4),ios(13.0));

/*!
  @method requestThumbnail
  @abstract This method requests thumbnail for the item. If one is not readily available, accessing this property will send a message to the device requesting a thumbnail for the file. The delegate of the device will be notified via method "cameraDevice:didReceiveThumbnail:forItem:error:", if this method is implemented by the delegate.
*/
- (void)requestThumbnail IC_AVAILABLE(macos(10.15), ios(13.0));

/*!
 @method requestMetadata
 @abstract ￼Metadata for the file if one is readily available. If one is not readily available, accessing this property will send a message to the device requesting metadata for the file. The delegate of the device will be notified via method "cameraDevice:didReceiveMetadata:forItem:error:", if this method is implemented by the delegate.
*/
- (void)requestMetadata  IC_AVAILABLE(macos(10.15), ios(13.0));

/*!
 @method flushThumbnailCache
 @abstract ￼Deletes cached thumbnail for the item.
*/
- (void)flushThumbnailCache  IC_AVAILABLE(macos(10.15), ios(13.0));

/*!
 @method flushMetadataCache
 @abstract ￼Deletes cached metadata for the item.
*/
- (void)flushMetadataCache IC_AVAILABLE(macos(10.15), ios(13.0));

#pragma mark - Deprecated

/*!
 @property thumbnailIfAvailable
 @abstract ￼Thumbnail for the item if one is readily available. If one is not readily available, accessing this property will
 send a message to the device requesting a thumbnail for the file. The delegate of the device will be notified via method
 "cameraDevice:didReceiveThumbnailForItem:", if this method is implemented on by the delegate.
*/
@property (nullable, readonly) CGImageRef thumbnailIfAvailable IC_DEPRECATED_WITH_REPLACEMENT(
    "Use requestThumbnail, or requestThumbnailWithOptions:completion", macos(10.4,10.15));

/*!
 @property largeThumbnailIfAvailable
 @abstract Large thumbnail for the item if one is readily available. If one is not readily available, accessing this property
 will send a message to the device requesting a thumbnail for the file. The delegate of the device will be notified via method
 "cameraDevice:didReceiveThumbnailForItem:", if this method is implemented on by the delegate.
 */
@property (nullable, readonly) CGImageRef largeThumbnailIfAvailable IC_DEPRECATED_WITH_REPLACEMENT(
    "Use requestThumbnail, or requestThumbnailWithOptions:completion", macos(10.4, 10.15));

/*!
 @property metadataIfAvailable
 @abstract ￼Metadata for the file if one is readily available. If one is not readily available, accessing this property will
 send a message to the device requesting metadata for the file. The delegate of the device will be notified via method
 "cameraDevice:didReceiveMetadataForItem:", if this method is implemented on by the delegate.
*/
@property (nullable, readonly) NSDictionary<NSString*, id>* metadataIfAvailable IC_DEPRECATED_WITH_REPLACEMENT(
    "Use requestMetadata for the delegate based API, or requestMetadataDictionaryWithOptions:completion", macos(10.4, 10.15));

@end

CF_ASSUME_NONNULL_END
