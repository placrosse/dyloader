// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#ifndef DYLOADER_FORMAT_H
#define DYLOADER_FORMAT_H

#include <dyloader/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct dyloader_buffer;
struct dyloader_host;
struct dyloader_host_data;
struct dyloader_format_data;

/// @defgroup format-api Format API
/// @brief Deals with a single executable
/// file format.

/// @brief Used to contain the implementation
/// specific code of a certain executable format.
/// @ingroup format-api
struct dyloader_format {
	/// @brief Initializes the format structure.
	struct dyloader_format_data *(*init)(const struct dyloader_host *host,
	                                     struct dyloader_host_data *host_data);
	/// @brief Releases memory from the format structure.
	void (*done)(struct dyloader_format_data *format_data);
	/// @brief Runs the file passed in a buffer.
	int (*run)(struct dyloader_format_data *format_data,
	           const struct dyloader_buffer *buffer);
};

/// @brief Initializes a format implementation.
/// @param format The format callbacks, used to perform
/// the initialization.
/// @param host The host callbacks for the system.
/// @param host_data The host implementation data.
/// @returns A pointer to the format implementation data.
/// @ingroup format-api
struct dyloader_format_data *
dyloader_format_init(const struct dyloader_format *format,
                     const struct dyloader_host *host,
                     struct dyloader_host_data *host_data);

/// @brief Releases memory allocated by a format implementation.
/// @param format The format callbacks for the implementation.
/// @param format_data The format implementation data.
/// @ingroup format-api
void
dyloader_format_done(const struct dyloader_format *format,
                     struct dyloader_format_data *format_data);

/// @brief Loads a runs the executable contained within a buffer.
/// @param format An initialized format structure.
/// @param format_data Format implementation data.
/// @param buffer The buffer containing the file to run.
/// @returns Zero on success, an error code from @ref errno on failure.
/// @ingroup format-api
int
dyloader_format_run(const struct dyloader_format *format,
                    struct dyloader_format_data *format_data,
                    const struct dyloader_buffer *buffer);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* DYLOADER_FORMAT_H */
