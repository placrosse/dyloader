// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/format.h>

#include <dyloader/buffer.h>
#include <dyloader/errno.h>

struct dyloader_format_data *
dyloader_format_init(const struct dyloader_format *format,
                     const struct dyloader_host *host,
                     struct dyloader_host_data *host_data) {

	if ((format == DYLOADER_NULL) || (host == DYLOADER_NULL))
		return DYLOADER_NULL;

	return format->init(host, host_data);
}

void
dyloader_format_done(const struct dyloader_format *format,
                     struct dyloader_format_data *format_data) {

	if (format->done != DYLOADER_NULL) {
		format->done(format_data);
	}
}

int
dyloader_format_run(const struct dyloader_format *format,
                    struct dyloader_format_data *format_data,
                    const struct dyloader_buffer *buffer) {

	if (format->run == DYLOADER_NULL)
		return DYLOADER_EFAULT;

	return format->run(format_data, buffer);
}
