.PHONY: all clean test install
all clean target install:
	$(MAKE) -C lib $@
