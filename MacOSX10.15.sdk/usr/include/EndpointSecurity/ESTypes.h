#ifndef __ENDPOINT_SECURITY_TYPES_H
#define __ENDPOINT_SECURITY_TYPES_H

#include <sys/types.h>
#include <stdint.h>

typedef enum {
	ES_ACTION_TYPE_AUTH
  , ES_ACTION_TYPE_NOTIFY
} es_action_type_t;

typedef enum {
	ES_EVENT_TYPE_AUTH_EXEC
  , ES_EVENT_TYPE_AUTH_OPEN
  , ES_EVENT_TYPE_AUTH_KEXTLOAD
  , ES_EVENT_TYPE_AUTH_MMAP
  , ES_EVENT_TYPE_AUTH_MPROTECT
  , ES_EVENT_TYPE_AUTH_MOUNT
  , ES_EVENT_TYPE_AUTH_RENAME
  , ES_EVENT_TYPE_AUTH_SIGNAL
  , ES_EVENT_TYPE_AUTH_UNLINK
  , ES_EVENT_TYPE_NOTIFY_EXEC
  , ES_EVENT_TYPE_NOTIFY_OPEN
  , ES_EVENT_TYPE_NOTIFY_FORK
  , ES_EVENT_TYPE_NOTIFY_CLOSE
  , ES_EVENT_TYPE_NOTIFY_CREATE
  , ES_EVENT_TYPE_NOTIFY_EXCHANGEDATA
  , ES_EVENT_TYPE_NOTIFY_EXIT
  , ES_EVENT_TYPE_NOTIFY_GET_TASK
  , ES_EVENT_TYPE_NOTIFY_KEXTLOAD
  , ES_EVENT_TYPE_NOTIFY_KEXTUNLOAD
  , ES_EVENT_TYPE_NOTIFY_LINK
  , ES_EVENT_TYPE_NOTIFY_MMAP
  , ES_EVENT_TYPE_NOTIFY_MPROTECT
  , ES_EVENT_TYPE_NOTIFY_MOUNT
  , ES_EVENT_TYPE_NOTIFY_UNMOUNT
  , ES_EVENT_TYPE_NOTIFY_IOKIT_OPEN
  , ES_EVENT_TYPE_NOTIFY_RENAME
  , ES_EVENT_TYPE_NOTIFY_SETATTRLIST
  , ES_EVENT_TYPE_NOTIFY_SETEXTATTR
  , ES_EVENT_TYPE_NOTIFY_SETFLAGS
  , ES_EVENT_TYPE_NOTIFY_SETMODE
  , ES_EVENT_TYPE_NOTIFY_SETOWNER
  , ES_EVENT_TYPE_NOTIFY_SIGNAL
  , ES_EVENT_TYPE_NOTIFY_UNLINK
  , ES_EVENT_TYPE_NOTIFY_WRITE
  , ES_EVENT_TYPE_LAST //Special unused type that is always the max value. Used for checking if value in range
} es_event_type_t;

typedef enum {
	ES_AUTH_RESULT_ALLOW
  , ES_AUTH_RESULT_DENY
} es_auth_result_t;

typedef enum {
  ES_RESULT_TYPE_AUTH
  , ES_RESULT_TYPE_FLAGS
} es_result_type_t;

/**
 * ES_RESPOND_RESULT_ERR_INVALID_ARGUMENT One or more invalid arguments were provided
 * ES_RESPOND_RESULT_ERR_DUPLICATE_RESPONSE The provided message has been responded to more than once
 * ES_RESPOND_RESULT_ERR_INTERNAL Indicates communication with the ES subsystem failed
 * ES_RESPOND_RESULT_SUCCESS Indicates success
 */
typedef enum {
	ES_RESPOND_RESULT_ERR_INVALID_ARGUMENT
  , ES_RESPOND_RESULT_ERR_DUPLICATE_RESPONSE
  , ES_RESPOND_RESULT_ERR_INTERNAL
  , ES_RESPOND_RESULT_SUCCESS
} es_respond_result_t;

typedef enum {
	  ES_NEW_CLIENT_RESULT_ERR_INVALID_ARGUMENT
	, ES_NEW_CLIENT_RESULT_ERR_NOT_ENTITLED
	, ES_NEW_CLIENT_RESULT_ERR_NOT_PERMITTED
	, ES_NEW_CLIENT_RESULT_ERR_INTERNAL
	, ES_NEW_CLIENT_RESULT_SUCCESS
} es_new_client_result_t;

/**
 * ES_CLEAR_CACHE_RESULT_ERR_THROTTLE Too many requests have been made to clear the cache
 * ES_CLEAR_CACHE_RESULT_ERR_INTERNAL Communication with the ES subsystem failed
 * ES_CLEAR_CACHE_RESULT_SUCCESS The cache has been successfully cleared
 */
typedef enum {
	ES_CLEAR_CACHE_RESULT_ERR_THROTTLE
  , ES_CLEAR_CACHE_RESULT_ERR_INTERNAL
  , ES_CLEAR_CACHE_RESULT_SUCCESS
} es_clear_cache_result_t;

typedef struct {
	size_t size;
	const uint8_t * data;
} es_token_t;

typedef struct {
	//Size in bytes of this entire struct
	size_t size;
	//Buffer of packed tokens
	uint8_t data[];
} es_packed_token_blob_t;

#endif /* __ENDPOINT_SECURITY_TYPES_H */
