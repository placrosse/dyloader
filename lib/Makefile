TOP ?= $(CURDIR)/..
include $(TOP)/make/config.mk
include $(TOP)/make/patterns.mk

VPATH += $(TOP)/include/dyloader

.PHONY: all
all: libdyloader.a

libdyloader.a: dyloader.o

dyloader.o: dyloader.c dyloader.h types.h

.PHONY: clean
clean:
	$(RM) libdyloader.a
	$(RM) *.o

.PHONY: test
test:

.PHONY: install
install:
