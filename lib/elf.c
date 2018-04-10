// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include "elf.h"

dyloader_bool
elf_verify_magic(const unsigned char *data,
                 dyloader_size size) {

	if (size < 4)
		return DYLOADER_FALSE;

	if ((data[0] != 0x7f)
	 || (data[1] != 'E')
	 || (data[2] != 'L')
	 || (data[3] != 'F'))
		return DYLOADER_FALSE;

	return DYLOADER_TRUE;
}
