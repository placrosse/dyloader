// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#ifndef DYLOADER_HOST_H
#define DYLOADER_HOST_H

#include <dyloader/arch.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @defgroup host-api Host API
/// @brief Used to implement required
/// system calls on the host system.

/// @brief Describes the host with
/// the information required by the
/// dynamic loader.
/// @ingroup host-api
struct dyloader_host_info {
	/// The architecture of the host system.
	dyloader_arch arch;
};

/// The host platform of the dynamic
/// loader. Used to implemented file
/// system calls and to get information
/// about the system.
/// @ingroup host-api
struct dyloader_host {
	/// A pointer to the host implementation.
	void *host_ptr;
	/// Used to get information about the host.
	int (*get_info)(void *host_ptr, struct dyloader_host_info *info);
};

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* DYLOADER_HOST_H */
