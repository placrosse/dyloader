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

dyloader_bool
elf_verify_class(const unsigned char *data,
                 dyloader_size size) {

	if (size < 5)
		return DYLOADER_FALSE;

	unsigned int elf_class = data[5];

	switch (elf_class) {
	case 1:
		// 32-bit class
		break;
	case 2:
		// 64-bit class
		// make sure this is not
		// a 32-bit platform.
		if (sizeof(void *) == 4)
			return DYLOADER_FALSE;
		break;
	default:
		return DYLOADER_FALSE;
	}

	return DYLOADER_TRUE;
}

dyloader_bool
elf_verify_header(const unsigned char *data,
                  dyloader_size size) {

	if (!elf_verify_magic(data, size))
		return DYLOADER_FALSE;

	if (!elf_verify_class(data, size))
		return DYLOADER_FALSE;

	return DYLOADER_TRUE;
}
