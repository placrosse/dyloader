DESTDIR ?=
PREFIX ?= /opt/return-infinity
CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar
LD = $(CROSS_COMPILE)gcc
CFLAGS += -Wall -Wextra -Werror -Wfatal-errors
ifdef TOP
CFLAGS += -I $(TOP)/include
endif
