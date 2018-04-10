// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#ifndef DYLOADER_ELF_H
#define DYLOADER_ELF_H

#include <dyloader/types.h>

#ifdef __cplusplus
extern "C" {
#endif

dyloader_bool
elf_verify_magic(const unsigned char *data,
                 dyloader_size size);

dyloader_bool
elf_verify_class(const unsigned char *data,
                 dyloader_size size);

dyloader_bool
elf_verify_header(const unsigned char *data,
                  dyloader_size size);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* DYLOADER_ELF_H */
