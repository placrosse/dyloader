// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/dyloader.h>

#include <dyloader/buffer.h>
#include <dyloader/errno.h>
#include <dyloader/format.h>
#include <dyloader/host.h>
#include <dyloader/types.h>

static int
dyloader_open(struct dyloader *dyloader,
              struct dyloader_buffer *buffer,
              const char *path) {

	return dyloader_host_open(dyloader->host,
	                          dyloader->host_data,
	                          buffer,
	                          path);
}

static void
dyloader_close(struct dyloader *dyloader,
               struct dyloader_buffer *buffer) {

	dyloader_host_close(dyloader->host,
	                    dyloader->host_data,
	                    buffer);
}

void
dyloader_init(struct dyloader *dyloader) {
	dyloader->host = DYLOADER_NULL;
	dyloader->host_data = DYLOADER_NULL;
	dyloader->format = DYLOADER_NULL;
	dyloader->format_data = DYLOADER_NULL;
}

void dyloader_done(struct dyloader *dyloader) {

	if (dyloader->host_data != DYLOADER_NULL) {

		dyloader_host_done(dyloader->host,
		                   dyloader->host_data);

		dyloader->host_data = DYLOADER_NULL;
	}

	if (dyloader->format_data != DYLOADER_NULL) {

		dyloader_format_done(dyloader->format,
		                     dyloader->format_data);

		dyloader->format_data = DYLOADER_NULL;
	}
}

void
dyloader_set_format(struct dyloader *dyloader,
                    const struct dyloader_format *format) {

	if (format == DYLOADER_NULL)
		return;

	if (dyloader->format != DYLOADER_NULL)
		dyloader_format_done(dyloader->format, dyloader->format_data);

	dyloader->format = format;

	dyloader->format_data = format->init(dyloader->host, dyloader->host_data);
}

void
dyloader_set_host(struct dyloader *dyloader,
                  const struct dyloader_host *host)
{
	if (host == DYLOADER_NULL)
		return;

	if (dyloader->host != DYLOADER_NULL)
		dyloader_host_done(dyloader->host, dyloader->host_data);

	dyloader->host = host;

	dyloader->host_data = dyloader_host_init(dyloader->host);
}

int
dyloader_run(struct dyloader *dyloader,
             const char *path) {

	if ((dyloader->host == DYLOADER_NULL)
	 || (dyloader->format == DYLOADER_NULL))
		return DYLOADER_ENOSYS;

	struct dyloader_buffer buffer;

	dyloader_buffer_init(&buffer);

	int err = dyloader_open(dyloader, &buffer, path);
	if (err != 0)
		return err;

	err = dyloader_format_run(dyloader->format,
	                          dyloader->format_data,
	                          &buffer);
	if (err != 0) {
		dyloader_close(dyloader, &buffer);
		return err;
	}

	dyloader_close(dyloader, &buffer);

	return 0;
}
