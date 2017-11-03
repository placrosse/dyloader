// =================================================
// libexec -- An executable loader for BareMetal OS
//
// Copyright (C) 2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =================================================

/// @file arch.h Architecture Enumeration

#ifndef LIBEXEC_BUFFER_H
#define LIBEXEC_BUFFER_H

#ifdef __cplusplus
extern "C"
{
#endif

/// @brief A general purpose buffer.
struct libexec_buffer {
	/// @brief The data associated with
	/// the buffer.
	void *data;
	/// @brief The number of bytes used
	/// by the buffer.
	unsigned long long int size;
};

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LIBEXEC_BUFFER_H
