// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include "format-elf.h"

#include <dyloader/buffer.h>
#include <dyloader/errno.h>
#include <dyloader/host.h>

#include "elf.h"

struct dyloader_format_data {
	const struct dyloader_host *host;
	struct dyloader_host_data *host_data;
};

static struct dyloader_format_data *
elf_init(const struct dyloader_host *host,
         struct dyloader_host_data *host_data) {

	struct dyloader_format_data *format_data;
	
	format_data = dyloader_host_malloc(host, host_data, sizeof(*format_data));
	if (format_data == DYLOADER_NULL)
		return DYLOADER_NULL;

	format_data->host = host;
	format_data->host_data = host_data;

	return format_data;
}

void
elf_done(struct dyloader_format_data *format_data) {

	dyloader_host_free(format_data->host, format_data->host_data, format_data);
}

int
elf_run(struct dyloader_format_data *format_data,
        const struct dyloader_buffer *buffer) {

	const unsigned char *data = (const unsigned char *) buffer->data;

	dyloader_size size = buffer->size;

	if (!elf_verify_magic(data, size)) {
		return DYLOADER_EINVAL;
	}

	(void) format_data;

	return 0;
}
 
const struct dyloader_format dyloader_format_elf = {
	elf_init,
	elf_done,
	elf_run
};
