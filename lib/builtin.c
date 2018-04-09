// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/dyloader.h>
#include <dyloader/builtin-host.h>

void dyloader_set_builtin(struct dyloader *dyloader) {
	dyloader_set_host(dyloader, &dyloader_builtin_host);
}
