/*
 * Copyright (c) 2018 Apple Inc. All rights reserved.
 */

#ifndef LOGGING_OS_LOG_ENTRY_SIGNPOST_H
#define LOGGING_OS_LOG_ENTRY_SIGNPOST_H

#ifndef __INDIRECT_LOGGING_HEADER_USER__
#error "Please use <Logging/Logging.h> instead of directly using this file."
#endif

NS_ASSUME_NONNULL_BEGIN

/*!
 * @enum OSLogEntrySignpostType
 *
 * @discussion
 * The kind of of signpost emitted.
 */
typedef NS_ENUM(NSInteger, OSLogEntrySignpostType) {
    OSLogEntrySignpostTypeUndefined,
    OSLogEntrySignpostTypeIntervalBegin,
    OSLogEntrySignpostTypeIntervalEnd,
    OSLogEntrySignpostTypeEvent,
}
API_AVAILABLE(macos(10.15))
NS_SWIFT_NAME(OSLogEntrySignpost.SignpostType);

/*!
 * @class OSLogEntrySignpost
 *
 * @abstract
 * Entries made by the os_signpost API.
 */
API_AVAILABLE(macos(10.15))
OS_EXPORT
@interface OSLogEntrySignpost : OSLogEntry <OSLogEntryFromProcess, OSLogEntryWithPayload>

/*!
 * @property signpostIdentifier
 *
 * @abstract
 * The signpost ID associated with this entry.
 */
@property (nonatomic, readonly) os_signpost_id_t signpostIdentifier;

/*!
 * @property signpostName
 *
 * @abstract
 * The signpost name associated with this entry.
 */
@property (nonatomic, readonly) NSString *signpostName;

/*!
 * @property signpostType
 *
 * @abstract
 * The signpost type associated with this entry.
 */
@property (nonatomic, readonly) OSLogEntrySignpostType signpostType;

@end

NS_ASSUME_NONNULL_END

#endif /* LOGGING_OS_LOG_ENTRY_SIGNPOST_H */
