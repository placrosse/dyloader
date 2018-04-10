// ==================================================
// dyloader -- A platform independent dynamic loader.
//
// Copyright (C) 2018 Return Infinity -- see LICENSE
// ==================================================

#include <dyloader/dyloader.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
run(const char *program) {

	struct dyloader dyloader;

	dyloader_init(&dyloader);

	/// Use builtin host
	dyloader_set_builtin(&dyloader);

	/// Use ELF file format
	dyloader_set_elf(&dyloader);

	int err = dyloader_run(&dyloader, program);
	if (err != 0) {
		fprintf(stderr, "Failed to execute '%s'.\n", program);
		dyloader_done(&dyloader);
		return EXIT_FAILURE;
	}

	dyloader_done(&dyloader);

	return EXIT_SUCCESS;
}

int
main(int argc, const char **argv) {

	const char *program = NULL;

	for (int i = 1; i < argc; i++) {
		if (argv[i][0] != '-') {
			program = argv[i];
			break;
		} else {
			fprintf(stderr, "Unknown option '%s'.\n", argv[i]);
			return EXIT_FAILURE;
		}
	}

	if (program == NULL) {
		fprintf(stderr, "No program specified.\n");
		return EXIT_FAILURE;
	}

	return run(program);
}
