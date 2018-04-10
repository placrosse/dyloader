// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/builtin-host.h>

#include <dyloader/buffer.h>
#include <dyloader/errno.h>
#include <dyloader/types.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include <stdlib.h>

struct dyloader_host_data {
	// nothing required here for linux
};

static struct dyloader_host_data *
builtin_init(void) {

	struct dyloader_host_data *host_data = malloc(sizeof(*host_data));
	if (host_data == NULL)
		return DYLOADER_NULL;

	return host_data;
}

static void
builtin_done(struct dyloader_host_data *host_data) {
	if (host_data != DYLOADER_NULL)
		free(host_data);
}

static int
builtin_get_info(struct dyloader_host_data *host_data,
                 struct dyloader_host_info *host_info) {

	(void) host_data;

	// assume we're on x86_64
	host_info->arch = DYLOADER_ARCH_x86_64;

	return 0;
}

static int
builtin_open(struct dyloader_host_data *host_data,
             struct dyloader_buffer *buffer,
             const char *path) {

	int fd = open(path, O_RDONLY);
	if (fd < 0) {
		if (errno == EPERM)
			return DYLOADER_EPERM;
		else if (errno == EISDIR)
			return DYLOADER_EISDIR;
		else
			return DYLOADER_ENOENT;
	}

	struct stat stbuf;

	if (fstat(fd, &stbuf) < 0) {
		close(fd);
		// TODO : get a better
		// error code
		return DYLOADER_ENOENT;
	}

	buffer->data = malloc(stbuf.st_size);
	if (buffer->data == NULL) {
		close(fd);
		return DYLOADER_ENOMEM;
	}

	buffer->size = stbuf.st_size;

	size_t read_count = read(fd, buffer->data, buffer->size);
	if (((dyloader_size) read_count) != buffer->size) {
		free(buffer->data);
		close(fd);
		return DYLOADER_EIO;
	}

	close(fd);

	buffer->read_perm = DYLOADER_TRUE;
	buffer->write_perm = DYLOADER_TRUE;
	buffer->exec_perm = DYLOADER_FALSE;

	(void) host_data;

	return 0;
}

static void
builtin_close(struct dyloader_host_data *host_data,
              struct dyloader_buffer *buffer) {

	(void) host_data;

	free(buffer->data);
	buffer->data = NULL;
	buffer->size = 0;
}

static void *
builtin_malloc(struct dyloader_host_data *host_data,
               dyloader_size size) {

	(void) host_data;

	void *addr = malloc(size);
	if (addr == NULL)
		return DYLOADER_NULL;
	else
		return addr;
}

static void
builtin_free(struct dyloader_host_data *host_data,
             void *addr) {

	(void) host_data;

	free(addr);
}

const struct dyloader_host dyloader_builtin_host = {
	builtin_init,
	builtin_done,
	builtin_get_info,
	builtin_open,
	builtin_close,
	builtin_malloc,
	builtin_free
};
