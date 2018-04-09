// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#ifndef DYLOADER_BUFFER_H
#define DYLOADER_BUFFER_H

#include <dyloader/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @defgroup buffer-api Buffer API
/// @brief The interface for dealing
/// with memory buffers.

/// @brief A general purpose buffer.
/// The buffer structure is used for
/// allocations and can describe page
/// permissions as well.
/// @ingroup buffer-api
struct dyloader_buffer {
	/// @brief The data associated with
	/// the buffer.
	void *data;
	/// @brief The number of bytes used
	/// by the buffer.
	dyloader_size size;
	/// @brief Whether or not the memory
	/// can be read from.
	dyloader_bool read_perm;
	/// @brief Whether or not the memory
	/// can be written to.
	dyloader_bool write_perm;
	/// @brief Whether or not the memory
	/// can be executed.
	dyloader_bool exec_perm;
};

/// @brief Initializes the buffer's fields
/// to reasonable default values.
/// @param buffer The buffer structure to initialize.
/// @ingroup buffer-api
void dyloader_buffer_init(struct dyloader_buffer *buffer);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DYLOADER_BUFFER_H
