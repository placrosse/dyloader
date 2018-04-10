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
struct dyloader_host_data;
struct dyloader_format;
struct dyloader_format_data;

/// @defgroup dyloader-api Dynamic Loader API
/// @brief The high level API used for loading
/// executables and libraries.

/// @brief Used for loading executables and
/// shared object files.
/// @ingroup dyloader-api
struct dyloader {
	/// @brief A pointer to the host callbacks.
	const struct dyloader_host *host;
	/// @brief A pointer to the host implementation data.
	struct dyloader_host_data *host_data;
	/// @brief The format to expect when loading executables.
	const struct dyloader_format *format;
	/// @brief The format implementation data.
	struct dyloader_format_data *format_data;
};

/// @brief Initializes the dynamic loader.
/// This function should be called right after declaring
/// the structure.  After calling this function, call the
/// function @ref dyloader_set_host, so that the loader
/// has the callbacks it needs for basic operation.
/// @param loader The loader structure to initialize.
/// @ingroup dyloader-api
void dyloader_init(struct dyloader *loader);

/// @brief Releases memory allocated by the
/// loader. This should be called when the library
/// is no longer going to be used.
/// @param loader An initialize loader structure.
/// @ingroup dyloader-api
void
dyloader_done(struct dyloader *loader);

/// @brief Sets the host callbacks for the loader.
/// This allows the loader to make file system calls
/// and allocate memory. Host implementation data is
/// also allocated during this function.
/// @param loader An initialized structure.
/// @param host An initialized host structure.
/// @ingroup dyloader-api
void
dyloader_set_host(struct dyloader *loader,
                  const struct dyloader_host *host);

/// @brief Sets the format to expect when loading executables.
/// @param loader An initialized loader structure.
/// @param format The format to expect for executables.
/// This parameter should not be @ref DYLOADER_NULL.
/// @ingroup dyloader-api
void
dyloader_set_format(struct dyloader *loader,
                    const struct dyloader_format *format);

/// @brief Tells the loader to use the builtin
/// host implementation. This requires that the
/// buitlin host library be linked, as well.
/// @param dyloader An initialized loader structure.
/// @ingroup dyloader-api
void
dyloader_set_builtin(struct dyloader *dyloader);

/// @brief Tells the dynamic loader to expect ELF files.
/// This function requires that the caller links with
/// the dyloader ELF library.
/// @param dyloader An initialized loader structure.
/// @ingroup dyloader-api
void
dyloader_set_elf(struct dyloader *dyloader);

/// @brief This function loads and runs a program.
/// @param loader An initialized loader structure.
/// @param path The path of the program to load.
/// @returns Zero on success, an errno value on failure.
/// @ingroup dyloader-api
int
dyloader_run(struct dyloader *loader,
             const char *path);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif // DYLOADER_H
