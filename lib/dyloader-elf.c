// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/dyloader.h>

#include "format-elf.h"

void dyloader_set_elf(struct dyloader *dyloader) {
	dyloader_set_format(dyloader, &dyloader_format_elf);
}
