// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/host.h>

#include <dyloader/errno.h>
#include <dyloader/types.h>

struct dyloader_host_data *
dyloader_host_init(const struct dyloader_host *host) {

	if (host->init != DYLOADER_NULL)
		return host->init();
	else
		return DYLOADER_NULL;
}

void
dyloader_host_done(const struct dyloader_host *host,
                   struct dyloader_host_data *host_data) {

	if (host->done != DYLOADER_NULL)
		host->done(host_data);
}

int
dyloader_host_open(const struct dyloader_host *host,
                   struct dyloader_host_data *host_data,
                   struct dyloader_buffer *buffer,
                   const char *path) {

	if (host->open == DYLOADER_NULL)
		return DYLOADER_EFAULT;

	return host->open(host_data, buffer, path);
}

void
dyloader_host_close(const struct dyloader_host *host,
                    struct dyloader_host_data *data,
                    struct dyloader_buffer *buffer) {

	if (host->close != DYLOADER_NULL)
		return host->close(data, buffer);
}

void *
dyloader_host_malloc(const struct dyloader_host *host,
                     struct dyloader_host_data *host_data,
                     dyloader_size size) {

	if (host->malloc == DYLOADER_NULL)
		return DYLOADER_NULL;

	return host->malloc(host_data, size);
}

void
dyloader_host_free(const struct dyloader_host *host,
                   struct dyloader_host_data *host_data,
                   void *addr) {

	if (host->free != DYLOADER_NULL)
		host->free(host_data, addr);
}
