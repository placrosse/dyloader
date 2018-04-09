// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/dyloader.h>

#include "test.h"

#include <string.h>

static void test_run(const char *sample_path) {

	struct dyloader loader;

	dyloader_init(&loader);

	// This should fail, because
	// there is not a host attached yet.
	int err = dyloader_run(&loader, "./fake-program");
	dyloader_assert(err != 0);

	dyloader_set_builtin(&loader);

	err = dyloader_run(&loader, sample_path);
	dyloader_assert(err == 0);

	dyloader_done(&loader);
}

int main(int argc, const char **argv) {

	const char *sample_path = "sample";

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--sample-path") == 0) {
			if ((i + 1) >= argc) {
				fprintf(stderr, "Sample path not specified.\n");
				return EXIT_FAILURE;
			}
		}
	}

	test_run(sample_path);

	return 0;
}
