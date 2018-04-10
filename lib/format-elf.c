// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include "format-elf.h"

struct dyloader_format_data {
	const struct dyloader_host *host;
	struct dyloader_host_data *host_data;
};

static struct dyloader_format_data *
elf_init(const struct dyloader_host *host,
         struct dyloader_host_data *host_data) {
	(void) host;
	(void) host_data;
	return DYLOADER_NULL;
}

void
elf_done(struct dyloader_format_data *format_data) {
	(void) format_data;
}

int
elf_run(struct dyloader_format_data *format_data,
        const struct dyloader_buffer *buffer) {
	(void) format_data;
	(void) buffer;
	return 0;
}
 
const struct dyloader_format dyloader_format_elf = {
	elf_init,
	elf_done,
	elf_run
};
