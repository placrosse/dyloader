// =================================================
// libexec -- An executable loader for BareMetal OS
//
// Copyright (C) 2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =================================================

/// @file system.h System Structure

#ifndef LIBEXEC_SYSTEM_H
#define LIBEXEC_SYSTEM_H

#include <libexec/arch.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct libexec_buffer;

/// @brief Contains system callbacks
/// that are required to load the executable.
struct libexec_system {
	/// @brief Contains system-specific data.
	void *data;
	/// @brief Allocates a block of memory.
	/// @param system_data The system-specific
	/// data, part of this structure.
	/// @param vaddr The virtual address to
	/// map the memory too.
	/// @param alignment The alignment required
	/// by the allocation
	/// @returns On success, a block of memory
	/// specified by the caller. On failure,
	/// a null-pointer.
	void *(*alloc)(void *system_data,
	               void *vaddr,
	               unsigned long long int alignment,
	               unsigned long long int size,
	               unsigned long long int flags);
	/// @brief Releases a block of memory.
	/// @param system_data The system specific
	/// data, part of this structure.
	/// @param vaddr The virtual address passed to @ref alloc.
	void (*free)(void *system_data,
	             void *vaddr);
	/// @brief Runs the executable.
	/// @param system_data The system specific data,
	/// part of this structure.
	/// @param vaddr The entry point of the executable.
	int (*exec)(void *system_data,
	            void *vaddr);
	/// @brief Indicates the architecture of
	/// the system.
	enum libexec_arch arch;
};

/// @brief Initializes the system with
/// default values. The caller will still
/// need to set the callbacks, so that the
/// library can correctly load an executable
/// on their system.
/// @param system An uninitialized system.
void libexec_system_init(struct libexec_system *system);

/// @brief Runs an executable.
/// @param system An initialized system.
/// @param executable A buffer containing
/// the executable file.
/// @returns Zero on success, an error code
/// otherwise.
int libexec_system_run(struct libexec_system *system,
                       const struct libexec_buffer *executable);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LIBEXEC_SYSTEM_H
