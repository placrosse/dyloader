// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#ifndef DYLOADER_TEST_H
#define DYLOADER_TEST_H

#include <stdio.h>
#include <stdlib.h>

#define dyloader_assert(expr)        \
	do {                             \
		if (!(expr)) {               \
			fprintf(stderr, "%s:%u: Expression '%s' was false.\n", __FILE__, __LINE__, #expr); \
			abort();                 \
		}                            \
	} while (0)

#endif /* DYLOADER_TEST_H */

