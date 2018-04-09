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

struct dyloader_buffer;
struct dyloader_host_data;

/// @defgroup host-api Host API
/// @brief Used to implement required
/// system calls on the host system.

/// @brief Describes the host with
/// the information required by the
/// dynamic loader.
/// @ingroup host-api
struct dyloader_host_info {
	/// The architecture of the host system.
	enum dyloader_arch arch;
};

/// @brief The host platform of the dynamic
/// loader. Used to implemented file system
/// calls and to get information about the system.
/// @ingroup host-api
struct dyloader_host {
	/// @brief Initializes an instance
	/// of the host implementation.
	struct dyloader_host_data *(*init)(void);
	/// @brief Releases memory allocated
	/// by the host instance.
	void (*done)(struct dyloader_host_data *data);
	/// @brief Used to get information about the host.
	int (*get_info)(struct dyloader_host_data *data,
	                struct dyloader_host_info *info);
	/// @brief Used to open files on the host system.
	int (*open)(struct dyloader_host_data *data,
	            struct dyloader_buffer *buffer,
	            const char *path);
	/// @brief Closes a file that was allocated
	/// by the open function.
	void (*close)(struct dyloader_host_data *data,
	              struct dyloader_buffer *buffer);
};

/// @brief Initializes the host implementation.
/// @param host A host structure that contains the
/// callbacks required to initialize the host.
struct dyloader_host_data *dyloader_host_init(const struct dyloader_host *host);

/// @brief Releases the memory allocated by
/// the host. This is called when the structure
/// is no longer going to be used.
/// @param host An initialized host structure.
/// @param data A pointer to a structure containing
/// the host data that is going to be released.
void dyloader_host_done(const struct dyloader_host *host,
                        struct dyloader_host_data *data);

/// @brief Opens a file on the host system.
/// @param host An initialized host structure.
/// @param data Host implementation data.
/// @param buffer The buffer that the file
/// will be put into, if it is properly opened.
/// @param path The path of the file to open.
/// @returns Zero on success, an errno value
/// on failure.
/// @ingroup host-api
int dyloader_host_open(const struct dyloader_host *host,
                       struct dyloader_host_data *data,
                       struct dyloader_buffer *buffer,
                       const char *path);

/// @brief Closes a file that was opened
/// with @ref dyloader_host_open. This is
/// mainly used to free the memory.
/// @param host An initialized host structure.
/// @param data The host implementation data.
/// @param buffer The buffer containing the file data.
/// @ingroup host-api
void dyloader_host_close(const struct dyloader_host *host,
                         struct dyloader_host_data *data,
                         struct dyloader_buffer *buffer);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* DYLOADER_HOST_H */
