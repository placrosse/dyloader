// =================================================
// libexec -- An executable loader for BareMetal OS
//
// Copyright (C) 2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =================================================

/// @file arch.h Architecture Enumeration

#ifndef LIBEXEC_ARCH_H
#define LIBEXEC_ARCH_H

#ifdef __cplusplus
extern "C"
{
#endif

/// @brief Enumerates a list of
/// supported architectures.
enum libexec_arch {
	/// @brief Architecture was not specified
	/// by the executable.
	LIBEXEC_ARCH_UNSPECIFIED = 0,
	/// @brief Architecture is x86_64.
	LIBEXEC_ARCH_X86_64 = 0x83
};

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LIBEXEC_ARCH_H
