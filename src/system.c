// =================================================
// libexec -- An executable loader for BareMetal OS
//
// Copyright (C) 2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =================================================

#include <libexec/system.h>

#include <libexec/error.h>

#ifndef NULL
#define NULL ((void *) 0x00)
#endif

void libexec_system_init(struct libexec_system *system)
{
	system->alloc = NULL;
	system->free = NULL;
	system->exec = NULL;
	system->arch = LIBEXEC_ARCH_UNSPECIFIED;
}

int libexec_system_run(struct libexec_system *system,
                       const struct libexec_buffer *executable)
{
	(void) system;
	(void) executable;
	return LIBEXEC_ERROR_UNKNOWN;
}
