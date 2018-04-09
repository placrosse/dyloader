// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

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

/// @brief Functionality is not currently
/// implemented.
/// @ingroup errno
#define DYLOADER_ENOSYS 3

/// @brief Indicates that an invalid address
/// was passed to a function.
/// @ingroup errno
#define DYLOADER_EFAULT 4

/// @brief No such file or directory.
/// @ingroup errno
#define DYLOADER_ENOENT 5

/// @brief The path pointed to a directory
/// instead of pointing to a file.
/// @ingroup errno
#define DYLOADER_EISDIR 6

/// @brief Insufficient permission to open
/// a certain file.
/// @ingroup errno
#define DYLOADER_EPERM 7

/// @brief An input or output error occured.
/// @ingroup errno
#define DYLOADER_EIO 8

#endif // DYLOADER_ERRNO_H
