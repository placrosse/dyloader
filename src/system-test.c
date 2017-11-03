// =================================================
// libexec -- An executable loader for BareMetal OS
//
// Copyright (C) 2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =================================================

#include <libexec/system.h>

#include <libexec/buffer.h>
#include <libexec/mode.h>

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>

// The values checked by the mock functions
// can be obtained by running the following
// command.
//
// readelf --program-headers sample.elf

// Casts an integer to an address.
#define ADDR(addr) ((void *) addr)

// A mock system that ensures the library
// is working correctly.
struct mock_system {
	// The number of times the alloc callback
	// was called.
	unsigned long long int alloc_count;
	// The number of times the free callback
	// was called.
	unsigned long long int free_count;
	// The number of times the exec callback
	// was called. This should be exactly one
	// at the end of the test.
	unsigned long long int exec_count;
};

static void mock_system_init(struct mock_system *system)
{
	system->alloc_count = 0;
	system->free_count = 0;
	system->exec_count = 0;
}

static void mock_system_done(struct mock_system *system)
{
	// This function should have been
	// called six times.
	assert(system->alloc_count == 2);
	// This function should have been
	// called the same number of times
	// as the alloc function.
	assert(system->free_count == system->alloc_count);
	// This function should have been
	// called exactly once.
	assert(system->exec_count == 1);
}

static void *mock_alloc(void *system_data,
                        void *vaddr,
                        unsigned long long int alignment,
                        unsigned long long int size,
                        unsigned long long int flags)
{
	struct mock_system *system = (struct mock_system *) system_data;

	assert(system->alloc_count <= 1);

	// protection flag to pass to mmap
	int prot = 0;

	if (system->alloc_count == 0)
	{
		assert(vaddr == ADDR(0x400000));
		assert(alignment == 0x200000);
		assert(size == 0x01C8);
		assert(flags == (LIBEXEC_MODE_READ & LIBEXEC_MODE_EXEC));
		prot = PROT_READ | PROT_EXEC;
	}
	else if (system->alloc_count == 1)
	{
		assert(vaddr == ADDR(0x601000));
		assert(alignment == 0x200000);
		assert(size == 0x002C);
		assert(flags == (LIBEXEC_MODE_READ & LIBEXEC_MODE_WRITE));
		prot = PROT_READ | PROT_WRITE;
	}

	system->alloc_count++;

	return mmap(vaddr, size, prot, 0, -1, 0);
}

static void mock_free(void *system_data,
                      void *vaddr)
{
	struct mock_system *system = (struct mock_system *) system_data;

	assert(system->free_count <= 1);

	if (system->free_count == 0)
	{
		assert(vaddr == ADDR(0x400000));
		munmap(vaddr, 0x01C8);
	}
	else if (system->free_count == 1)
	{
		assert(vaddr == ADDR(0x601000));
		munmap(vaddr, 0x02C);
	}

	system->free_count++;
}

static int mock_exec(void *system_data,
                     void *vaddr)
{
	struct mock_system *system = (struct mock_system *) system_data;

	// This should be the first and only
	// time this function is called.
	assert(system->exec_count == 0);
	// There should have been six allocations
	// at this point.
	assert(system->alloc_count == 2);
	// Nothing should have been freed at
	// this point.
	assert(system->free_count == 0);
	// The entry point should be this
	// address.
	assert(vaddr == ADDR(0x400144));

	system->exec_count++;

	return 0;
}

static int readfile(const char *filename,
                    struct libexec_buffer *executable)
{
	FILE *file = fopen(filename, "rb");
	if (file == NULL)
		return -errno;

	int err = fseek(file, 0, SEEK_END);
	if (err != 0)
	{
		err = -errno;
		fclose(file);
		return err;
	}

	long int size = ftell(file);
	if (size < 0L)
	{
		err = -errno;
		fclose(file);
		return err;
	}

	err = fseek(file, 0, SEEK_SET);
	if (err != 0)
	{
		err = -errno;
		fclose(file);
		return err;
	}

	executable->data = malloc(size);
	if (executable->data == NULL)
	{
		err = -errno;
		fclose(file);
		return err;
	}

	executable->size = (unsigned long long int) size;

	size_t read_count = fread(executable->data, 1,
	                          executable->size, file);
	if (read_count != ((size_t) executable->size))
	{
		free(executable->data);
		fclose(file);
		return -EIO;
	}

	fclose(file);

	return 0;
}

int main(int argc, const char **argv)
{
	const char *elf_filename = "sample";

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "--elf-file") == 0)
		{
			elf_filename = argv[i + 1];
			i++;
			continue;
		}
		else
		{
			fprintf(stderr, "Unrecognized option '%s'.\n", argv[i]);
			return EXIT_FAILURE;
		}
	}

	if (elf_filename == NULL)
	{
		fprintf(stderr, "ELF file not specified.\n");
		return EXIT_FAILURE;
	}

	struct libexec_buffer executable;

	int err = readfile(elf_filename, &executable);
	if (err != 0)
	{
		fprintf(stderr, "Failed to read executable: %s\n", strerror(-err));
		return EXIT_FAILURE;
	}

	struct mock_system mock_system;
	mock_system_init(&mock_system);

	struct libexec_system system;
	libexec_system_init(&system);
	system.data = &mock_system;
	system.alloc = mock_alloc;
	system.free = mock_free;
	system.exec = mock_exec;

	mock_system_done(&mock_system);
	free(executable.data);

	return EXIT_SUCCESS;
}
