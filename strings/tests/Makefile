NAME = libstrings.a

CFLAGS = -Wall -Wextra -Werror

FILES = $(wildcard test_*.c)

TESTS = $(FILES:.c=)

%: %.c test.c ../$(NAME)
	cc $(CFLAGS) -I ../include $<  test.c ../$(NAME) -o $@

../$(NAME):
	$(MAKE) -C ..

test_build: $(TESTS)

test: test_build
	for t in $(TESTS); do ./$$t; done

clean:
	rm -f $(TESTS)

valgrind: test_build
	for t in $(TESTS); do valgrind --leak-check=full ./$$t; done

.PHONY: test_build test valgrind
