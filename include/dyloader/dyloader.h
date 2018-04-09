// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#ifndef DYLOADER_DYLOADER_H
#define DYLOADER_DYLOADER_H

#ifdef __cplusplus
extern "C" {
#endif

struct dyloader_host;

/// @defgroup dyloader Dynamic Loader API
/// @brief The high level API used for loading
/// executables and libraries.

/// @brief Used for loading executables and
/// shared object files.
/// @ingroup dyloader
struct dyloader {
	/// @brief A pointer to the host system
	/// implementation.
	struct dyloader_host *host;
};

/// @brief Initializes the dynamic loader.
/// This function should be called right after declaring
/// the structure.  After calling this function, call the
/// function @ref dyloader_set_host, so that the loader
/// has the callbacks it needs for basic operation.
/// @param loader The loader structure to initialize.
/// @ingroup dyloader
void dyloader_init(struct dyloader *loader);

/// @brief Releases memory allocated by the
/// loader. This should be called when the library
/// is no longer going to be used.
/// @param loader An initialize loader structure.
/// @ingroup dyloader
void dyloader_done(struct dyloader *loader);

/// @brief Sets the host callbacks for the loader.
/// This allows the loader to make file system calls
/// and allocate memory.
/// @param loader An initialized structure.
/// @param host An initialized host structure.
void dyloader_set_host(struct dyloader *loader,
                       struct dyloader_host *host);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif // DYLOADER_H
