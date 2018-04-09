// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#ifndef DYLOADER_TYPES_H
#define DYLOADER_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/// @defgroup types Types
/// @brief Common types used across the library.

/// @brief Used to indicate the size of something.
/// It is the largest unsigned integer in the C language,
/// and at least 64-bits long.
/// @ingroup types
typedef unsigned long long int dyloader_size;

/// @brief Used to indicate a boolean value.
/// Use @ref DYLOADER_TRUE and @ref DYLOADER_FALSE
/// to modify this type.
/// @ingroup types
typedef unsigned char dyloader_bool;

/// @brief A boolean false value.
/// Used with the @ref dyloader_bool type.
/// @ingroup types
#define DYLOADER_FALSE 0

/// @brief A boolean true value.
/// Used with the @ref dyloader_bool type.
/// @ingroup types
#define DYLOADER_TRUE 1

/// @brief Used to indicate an invalid
/// memory address.
/// @ingroup types
#define DYLOADER_NULL ((void *) 0x00)

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* DYLOADER_TYPES_H */
