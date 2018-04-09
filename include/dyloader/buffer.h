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

/// @brief A general purpose buffer.
/// The buffer structure is used for
/// allocations and can describe page
/// permissions as well.
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

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DYLOADER_BUFFER_H
