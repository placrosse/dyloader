// ==================================================
// dyloader -- A platform-independent dynamic loader.
//
// Copyright (C) 2017 Return Infinity -- see LICENSE
// ==================================================

/// @file arch.h Architecture Enumeration

#ifndef DYLOADER_ARCH_H
#define DYLOADER_ARCH_H

#ifdef __cplusplus
extern "C"
{
#endif

/// @brief Enumerates a list of
/// supported architectures.
enum dyloader_arch {
	/// @brief Architecture was not specified
	/// by the executable.
	DYLOADER_ARCH_none,
	/// @brief Architecture is x86_64.
	DYLOADER_ARCH_x86_64 = 0x83
};

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DYLOADER_ARCH_H
