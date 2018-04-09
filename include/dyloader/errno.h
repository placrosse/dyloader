// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

/// @file error.h Error Codes

#ifndef DYLOADER_ERRNO_H
#define DYLOADER_ERRNO_H

/// @defgroup errno Error Codes
/// @brief Describes the various error
/// conditions that may happen within
/// the loader.

/// @brief A memory allocation failed.
/// @ingroup errno
#define DYLOADER_ENOMEM 1

/// @brief An invalid argument was passed
/// to a function.
/// @ingroup errno
#define DYLOADER_EINVAL 2

#endif // DYLOADER_ERRNO_H
