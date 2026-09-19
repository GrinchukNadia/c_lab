NAME = libstrings.a

CFLAGS = -Wall -Wextra -Werror

FILES = $(wildcard test_*.c)

TESTS = $(FILES:.c=)

%: %.c test.c ../$(NAME)
	cc $(CFLAGS) -I ../include $<  test.c ../$(NAME) -o $@

../$(NAME):
	$(MAKE) -C ..

help:
	@echo "Available targets:"
	@echo " re"
	@echo " test"
	@echo " clean"
	@echo " valgrind"

re: $(TESTS)

test: test_build
	for t in $(TESTS); do ./$$t; done

clean:
	rm -f $(TESTS)

valgrind: test_build
	for t in $(TESTS); do valgrind --leak-check=full ./$$t; done

.PHONY: help re test clean valgrind
