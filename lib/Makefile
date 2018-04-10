TOP ?= $(CURDIR)/..
include $(TOP)/make/config.mk
include $(TOP)/make/patterns.mk

VPATH += $(TOP)/include/dyloader

targets += libdyloader.a
targets += libdyloader-builtin.a
targets += libdyloader-elf.a

.PHONY: all
all: $(targets)

libdyloader.a: dyloader.o

dyloader.o: dyloader.c dyloader.h host.h format.h types.h

host.o: host.c host.h types.h

format.o: format.c format.h host.h types.h

libdyloader-elf.a: dyloader-elf.o format-elf.o

dyloader-elf.o: dyloader-elf.c dyloader.h format-elf.h types.h

format-elf.o: format-elf.c format-elf.h format.h types.h

.PHONY: clean
clean:
	$(RM) $(targets)
	$(RM) *.o

.PHONY: test
test:

.PHONY: install
install:
