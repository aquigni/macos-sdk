//
//  MTLArgumentEncoder.h
//  Metal
//
//  Copyright (c) 2016 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/MTLDefines.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MTLDevice;
@protocol MTLBuffer;
@protocol MTLTexture;
@protocol MTLSamplerState;
@protocol MTLRenderPipelineState;
@protocol MTLComputePipelineState;
@protocol MTLIndirectCommandBuffer;


/*!
 * @protocol MTLArgumentEncoder
 * @discussion MTLArgumentEncoder encodes buffer, texture, sampler, and constant data into a buffer.
 */
API_AVAILABLE(macos(10.13), ios(11.0))
@protocol MTLArgumentEncoder <NSObject>

/*!
 @property device
 @abstract The device this argument encoder was created against.
 */
@property (readonly) id <MTLDevice> device;

/*!
 @property label
 @abstract A string to help identify this object.
 */
@property (nullable, copy, atomic) NSString *label;

/*!
 * @property encodedLength
 * @abstract The number of bytes required to store the encoded resource bindings.
 */
@property (readonly) NSUInteger encodedLength;

/*!
 * @property alignment
 * @abstract The alignment in bytes required to store the encoded resource bindings.
 */
@property (readonly) NSUInteger alignment;

/*!
 * @method setArgumentBuffer:offset:
 * @brief Sets the destination buffer and offset at which the arguments will be encoded.
 */
- (void)setArgumentBuffer:(nullable id <MTLBuffer>)argumentBuffer offset:(NSUInteger)offset;

/*!
 * @method setArgumentBuffer:offset:arrayElement:
 * @brief Sets the destination buffer, starting offset and specific array element arguments will be encoded into. arrayElement represents
          the desired element of IAB array targetted by encoding
 */
- (void)setArgumentBuffer:(nullable id <MTLBuffer>)argumentBuffer startOffset:(NSUInteger)startOffset arrayElement:(NSUInteger)arrayElement;

/*!
 * @method setBuffer:offset:atIndex:
 * @brief Set a buffer at the given bind point index.
 */
- (void)setBuffer:(nullable id <MTLBuffer>)buffer offset:(NSUInteger)offset atIndex:(NSUInteger)index;

/*!
 * @method setBuffers:offsets:withRange:
 * @brief Set an array of buffers at the given bind point index range.
 */
- (void)setBuffers:(const id <MTLBuffer> __nullable [__nonnull])buffers offsets:(const NSUInteger [__nonnull])offsets withRange:(NSRange)range;

/*!
 * @method setTexture:atIndex:
 * @brief Set a texture at the given bind point index.
 */
- (void)setTexture:(nullable id <MTLTexture>)texture atIndex:(NSUInteger)index;

/*!
 * @method setTextures:withRange:
 * @brief Set an array of textures at the given bind point index range.
 */
- (void)setTextures:(const id <MTLTexture> __nullable [__nonnull])textures withRange:(NSRange)range;

/*!
 * @method setSamplerState:atIndex:
 * @brief Set a sampler at the given bind point index.
 */
- (void)setSamplerState:(nullable id <MTLSamplerState>)sampler atIndex:(NSUInteger)index;

/*!
 * @method setSamplerStates:withRange:
 * @brief Set an array of samplers at the given bind point index range.
 */
- (void)setSamplerStates:(const id <MTLSamplerState> __nullable [__nonnull])samplers withRange:(NSRange)range;

/*!
 * @method constantDataAtIndex:
 * @brief Returns a pointer to the constant data at the given bind point index.
 */
- (void*)constantDataAtIndex:(NSUInteger)index;


/*!
 * @method setRenderPipelineState:atIndex
 * @brief Sets a render pipeline state at a given bind point index
 */
- (void)setRenderPipelineState:(nullable id <MTLRenderPipelineState>)pipeline atIndex:(NSUInteger)index API_AVAILABLE(macos(10.14), uikitformac(13.0)) API_UNAVAILABLE(ios);

/*!
 * @method setRenderPipelineStates:withRange
 * @brief Set an array of render pipeline states at a given bind point index range
 */
- (void)setRenderPipelineStates:(const id <MTLRenderPipelineState> __nullable [__nonnull])pipelines withRange:(NSRange)range API_AVAILABLE(macos(10.14), uikitformac(13.0)) API_UNAVAILABLE(ios);


/*!
 * @method setIndirectCommandBuffer:atIndex
 * @brief Sets an indirect command buffer at a given bind point index
 */
- (void)setIndirectCommandBuffer:(nullable id <MTLIndirectCommandBuffer>)indirectCommandBuffer atIndex:(NSUInteger)index API_AVAILABLE(macos(10.14), ios(12.0));

/*!
 * @method setIndirectCommandBuffers:withRange:
 * @brief Set an array of indirect command buffers at the given bind point index range.
 */
- (void)setIndirectCommandBuffers:(const id <MTLIndirectCommandBuffer> __nullable [__nonnull])buffers withRange:(NSRange)range API_AVAILABLE(macos(10.14), ios(12.0));

/*!
 * @method newArgumentEncoderForBufferAtIndex:
 * @brief Returns a pointer to a new MTLArgumentEncoder that can be used to encode the an argument buffer
 * in the buffer associated with a given index.
 * Returns nil if the resource at the given index is not an argument buffer.
 */
- (nullable id<MTLArgumentEncoder>)newArgumentEncoderForBufferAtIndex:(NSUInteger)index API_AVAILABLE(macos(10.13), ios(11.0));

@end

NS_ASSUME_NONNULL_END

