SRC=$(filter-out src/%.test.c, $(wildcard src/*.c))
TESTS=$(wildcard src/*.test.c)

CFLAGS?=

ifeq (1,$(DEBUG))
CFLAGS+=-DDEBUG
endif

.PHONY: default
default: example

# Don't do this in a real project
example: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Compile, run and cleanup of unit tests
.PHONY: tests
tests: $(TESTS) ../include/test.h
	for TEST in $(TESTS); do \
		NAME=$$(echo $$TEST | sed 's/.test.c$$//g') && \
		$(CC) $(CFLAGS) -I../include -o $$NAME $$TEST && \
		./$$NAME && \
		rm $$NAME ; \
	done

.PHONY: clean
clean:
	rm -f example
