// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/buffer.h>

void dyloader_buffer_init(struct dyloader_buffer *buffer) {
	buffer->data = DYLOADER_NULL;
	buffer->size = 0;
	buffer->read_perm = DYLOADER_TRUE;
	buffer->write_perm = DYLOADER_TRUE;
	buffer->exec_perm = DYLOADER_FALSE;
}
