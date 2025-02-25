//
//  RPScreenRecorder.h
//  ReplayKit
//
//  ReplayKit is a high level framework that can be used to add video and audio recording and broadcast capabilities to an application. An application supplied user interface can use the RPScreenRecorder singleton to start and stop recording or broadcasting.
//
//  Optionally the framework allows the user to also record microphone content as well as content from the front facing camera.
//
//  When local recording stops, the framework will vend an instance of RPPreviewViewController that can be presented using [UIViewController presentViewController:animated:completion:]. The view controller allows the user to preview, trim and share the movie.
//
//  When broadcasting stops, the framework will return a url that can be used to view a broadcast.
//
//  Copyright © 2016 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ReplayKit/RPPreviewViewController.h>
#import <ReplayKit/RPBroadcastExtension.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos)
typedef NS_ENUM(NSInteger, RPCameraPosition) {
    RPCameraPositionFront = 1,
    RPCameraPositionBack,
};

API_AVAILABLE(ios(9.0), tvos(10.0))

@protocol RPScreenRecorderDelegate;
@class RPBroadcastActivityViewController;

/*! @class RPScreenRecorder
 @abstract Singleton class used to control app recording.
 */
@interface RPScreenRecorder : NSObject

/* @abstract Shared instance of the screen recorder. */
+ (RPScreenRecorder *)sharedRecorder;

- (instancetype)init API_UNAVAILABLE(ios,tvos); // Use sharedRecorder instead

/*! 
 Deprecated. Use startRecordingWithHandler: instead.
 
 @abstract Starts app recording with a completion handler. Note that before recording actually starts, the user may be prompted with UI to confirm recording.
 @param microphoneEnabled Determines whether the microphone input should be included in the recorded movie audio.
 @result handler Called after user interactions are complete. Will be passed an optional NSError in the RPRecordingErrorDomain domain if there was an issue starting the recording.
 */
- (void)startRecordingWithMicrophoneEnabled:(BOOL)microphoneEnabled handler:(nullable void(^)(NSError * _Nullable error))handler API_DEPRECATED("Use microphoneEnabaled property", ios(9.0, 10.0));

/*! @abstract Starts app recording with a completion handler. Note that before recording actually starts, the user may be prompted with UI to confirm recording.
 @result handler Called after user interactions are complete. Will be passed an optional NSError in the RPRecordingErrorDomain domain if there was an issue starting the recording.
 */
- (void)startRecordingWithHandler:(nullable void(^)(NSError * _Nullable error))handler API_AVAILABLE(ios(10.0), tvos(10.0));

/*! @abstract Stops app recording with a completion handler.
 @result handler Called when the movie is ready. Will return an instance of RPPreviewViewController on success which should be presented using [UIViewController presentViewController:animated:completion:]. Will be passed an optional NSError in the RPRecordingErrorDomain domain if there was an issue stopping the recording.
 */
- (void)stopRecordingWithHandler:(nullable void(^)(RPPreviewViewController * _Nullable previewViewController, NSError * _Nullable error))handler;

/*! @abstract Discards the current recording. This can only be called after the handler block in stopRecordingWithHandler: is executed.
 */
- (void)discardRecordingWithHandler:(void(^)(void))handler;

/*! @abstract Starts screen and audio capture and continually calls the supplied handler with the current sampleBuffer and bufferType and passed it back to the application. Note that before recording actually starts, the user may be prompted with UI to confirm recording.
 @result handler Called continually with sampleBuffers and the bufferType. Will be passed an optional NSError in the RPRecordingErrorDomain domain if there was an issue starting the capture.
 */
- (void)startCaptureWithHandler:(nullable void(^)(CMSampleBufferRef sampleBuffer, RPSampleBufferType bufferType, NSError * _Nullable error))captureHandler completionHandler:(nullable void(^)(NSError * _Nullable error))completionHandler API_AVAILABLE(ios(11.0), tvos(11.0));

/*! @abstract Stops screen capture with a completion handler
 @result handler Called after the screen capture has stopped. Will be passed an optional NSError in the RPRecordingErrorDomain domain if there was an issue stopping the capture
 */
- (void)stopCaptureWithHandler:(nullable void(^)(NSError * _Nullable error))handler API_AVAILABLE(ios(11.0), tvos(11.0));

/* @abstract Delegate instance for RPScreenRecorder. */
@property (nonatomic, weak, nullable) id<RPScreenRecorderDelegate> delegate;

/* @abstract Check if ReplayKit is available on the device. Implement the screenRecorderDidChangeAvailability: on the delegate to listen for changes to this property. Can be used for key value observing. */
@property (nonatomic, readonly, getter=isAvailable) BOOL available;

/* @abstract Check if a recording session is in progress. Can be used for key value observing. */
@property (nonatomic, readonly, getter=isRecording) BOOL recording;

/* @abstract Specify or query whether the microphone should be enabled during recording. Can be used for key value observing. Default is NO. */
@property (nonatomic, getter=isMicrophoneEnabled) BOOL microphoneEnabled API_UNAVAILABLE(tvos);

/* @abstract Specify or query whether the camera should be enabled during recording. Can be used for key value observing. Default is NO. */
@property (nonatomic, getter=isCameraEnabled) BOOL cameraEnabled API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(tvos);

/* @abstract Specify or query camera position. Can be used for key value observing. Default is RPCameraPositionFront. */
@property (nonatomic) RPCameraPosition cameraPosition API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos);

/* @abstract A UIView instance that renders the front or back facing camera contents. This will be nil if the camera has not been enabled */
@property (nonatomic, readonly, nullable) UIView *cameraPreviewView API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(tvos);

@end

API_AVAILABLE(ios(9.0), tvos(10.0))
@protocol RPScreenRecorderDelegate <NSObject>
@optional

/*! @abstract Called when recording has stopped due to an error.
 @param screenRecorder The instance of the screen recorder.
 @param error An NSError describing why recording has stopped in the RPRecordingErrorDomain.
 @param previewViewController If a partial movie is available before it was stopped, an instance of RPPreviewViewController will be returned.
 */
- (void)screenRecorder:(RPScreenRecorder *)screenRecorder didStopRecordingWithError:(NSError *)error previewViewController:(nullable RPPreviewViewController *)previewViewController API_DEPRECATED("No longer supported", ios(9.0, 10.0), tvos(10.0,10.0));
- (void)screenRecorder:(RPScreenRecorder *)screenRecorder didStopRecordingWithPreviewViewController:(nullable RPPreviewViewController *)previewViewController error:(nullable NSError *)error API_AVAILABLE(ios(11.0), tvos(11.0));

/*! @abstract Called when the recorder becomes available or stops being available. Check the screen recorder's availability property to check the current availability state. Possible reasons for the recorder to be unavailable include an in-progress Airplay/TVOut session or unsupported hardware.
 @param screenRecorder The instance of the screen recorder.
 */
- (void)screenRecorderDidChangeAvailability:(RPScreenRecorder *)screenRecorder;
@end
NS_ASSUME_NONNULL_END


