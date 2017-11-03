// =================================================
// libexec -- An executable loader for BareMetal OS
//
// Copyright (C) 2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =================================================

/// @file mode.h Memory Modes

#ifndef LIBEXEC_MODE_H
#define LIBEXEC_MODE_H

#ifdef __cplusplus
extern "C"
{
#endif

/// @brief A read-enabled mode.
#define LIBEXEC_MODE_READ 1

/// @brief A write-enabled mode.
#define LIBEXEC_MODE_WRITE 2

/// @brief An execute-enabled mode.
#define LIBEXEC_MODE_EXEC 4

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LIBEXEC_MODE_H
