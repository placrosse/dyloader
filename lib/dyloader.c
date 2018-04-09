// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/dyloader.h>

#include <dyloader/types.h>

void dyloader_init(struct dyloader *dyloader) {
	dyloader->host = DYLOADER_NULL;
}

void dyloader_done(struct dyloader *dyloader) {
	(void) dyloader;
}

void dyloader_set_host(struct dyloader *dyloader,
                       struct dyloader_host *host)
{
	if (host != DYLOADER_NULL)
		dyloader->host = host;
}
