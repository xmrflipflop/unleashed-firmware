#pragma once

#include "base.h"

#define SUBGHZ_PROTOCOL_VERTILUX_NAME "Vertilux"

typedef struct SubGhzProtocolDecoderVertilux SubGhzProtocolDecoderVertilux;
typedef struct SubGhzProtocolEncoderVertilux SubGhzProtocolEncoderVertilux;

extern const SubGhzProtocolDecoder subghz_protocol_vertilux_decoder;
extern const SubGhzProtocolEncoder subghz_protocol_vertilux_encoder;
extern const SubGhzProtocol subghz_protocol_vertilux;

/**
 * Allocate SubGhzProtocolEncoderVertilux.
 * @param environment Pointer to a SubGhzEnvironment instance
 * @return SubGhzProtocolEncoderVertilux* pointer to a SubGhzProtocolEncoderVertilux instance
 */
void* subghz_protocol_encoder_vertilux_alloc(SubGhzEnvironment* environment);

/**
 * Free SubGhzProtocolEncoderVertilux.
 * @param context Pointer to a SubGhzProtocolEncoderVertilux instance
 */
void subghz_protocol_encoder_vertilux_free(void* context);

/**
 * Key generation from simple data.
 * @param context Pointer to a SubGhzProtocolEncoderVertilux instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @param serial Serial number, 24 bit
 * @param btn Button number, 8 bit
 * @param cnt Counter value, 16 bit
 * @param preset Modulation, SubGhzRadioPreset
 * @return true On success
 */
bool subghz_protocol_vertilux_create_data(
    void* context,
    FlipperFormat* flipper_format,
    uint32_t serial,
    uint8_t btn,
    uint16_t cnt,
    SubGhzRadioPreset* preset);

/**
 * Deserialize and generating an upload to send.
 * @param context Pointer to a SubGhzProtocolEncoderVertilux instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return true On success
 */
SubGhzProtocolStatus
    subghz_protocol_encoder_vertilux_deserialize(void* context, FlipperFormat* flipper_format);

/**
 * Forced transmission stop.
 * @param context Pointer to a SubGhzProtocolEncoderVertilux instance
 */
void subghz_protocol_encoder_vertilux_stop(void* context);

/**
 * Getting the level and duration of the upload to be loaded into DMA.
 * @param context Pointer to a SubGhzProtocolEncoderVertilux instance
 * @return LevelDuration 
 */
LevelDuration subghz_protocol_encoder_vertilux_yield(void* context);

/**
 * Allocate SubGhzProtocolDecoderVertilux.
 * @param environment Pointer to a SubGhzEnvironment instance
 * @return SubGhzProtocolDecoderVertilux* pointer to a SubGhzProtocolDecoderVertilux instance
 */
void* subghz_protocol_decoder_vertilux_alloc(SubGhzEnvironment* environment);

/**
 * Free SubGhzProtocolDecoderVertilux.
 * @param context Pointer to a SubGhzProtocolDecoderVertilux instance
 */
void subghz_protocol_decoder_vertilux_free(void* context);

/**
 * Reset decoder SubGhzProtocolDecoderVertilux.
 * @param context Pointer to a SubGhzProtocolDecoderVertilux instance
 */
void subghz_protocol_decoder_vertilux_reset(void* context);

/**
 * Parse a raw sequence of levels and durations received from the air.
 * @param context Pointer to a SubGhzProtocolDecoderVertilux instance
 * @param level Signal level true-high false-low
 * @param duration Duration of this level in, us
 */
void subghz_protocol_decoder_vertilux_feed(void* context, bool level, uint32_t duration);

/**
 * Getting the hash sum of the last randomly received parcel.
 * @param context Pointer to a SubGhzProtocolDecoderVertilux instance
 * @return hash Hash sum
 */
uint8_t subghz_protocol_decoder_vertilux_get_hash_data(void* context);

/**
 * Serialize data SubGhzProtocolDecoderVertilux.
 * @param context Pointer to a SubGhzProtocolDecoderVertilux instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @param preset The modulation on which the signal was received, SubGhzRadioPreset
 * @return status
 */
SubGhzProtocolStatus subghz_protocol_decoder_vertilux_serialize(
    void* context,
    FlipperFormat* flipper_format,
    SubGhzRadioPreset* preset);

/**
 * Deserialize data SubGhzProtocolDecoderVertilux.
 * @param context Pointer to a SubGhzProtocolDecoderVertilux instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return status
 */
SubGhzProtocolStatus
    subghz_protocol_decoder_vertilux_deserialize(void* context, FlipperFormat* flipper_format);

/**
 * Getting a textual representation of the received data.
 * @param context Pointer to a SubGhzProtocolDecoderVertilux instance
 * @param output Resulting text
 */
void subghz_protocol_decoder_vertilux_get_string(void* context, FuriString* output);
