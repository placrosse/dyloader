CFLAGS += -Wall -Wextra -Werror -Wfatal-errors -std=c99
CFLAGS += -I../include

VPATH += ../include/libexec

.PHONY: all
all: libexec.a sample system-test

libexec.a: system.o
	$(AR) $(ARFLAGS) $@ $^

system.o: system.c system.h arch.h error.h

system-test: system-test.o libexec.a

system-test.o: system-test.c system.h arch.h buffer.h error.h

sample: sample.c

sample: CFLAGS=-static -nodefaultlibs -nostartfiles

.PHONY: clean
clean:
	$(RM) libexec.a
	$(RM) system.o
	$(RM) system-test system-test.o
	$(RM) sample.o sample

.PHONY: test
test: system-test
	./system-test
