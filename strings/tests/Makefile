NAME = libstrings.a

CFLAGS = -Wall -Wextra -Werror

FILES = $(wildcard test_*.c)

TESTS = $(FILES:.c=)

ASAN_TESTS = $(TESTS:%=%_asan)

%: %.c test.c ../$(NAME)
	cc $(CFLAGS) -I ../include $<  test.c ../$(NAME) -o $@

%_asan: %.c test.c ../$(NAME)
	cc $(CFLAGS) -g -fsanitize=address -I ../include $< test.c ../$(NAME) -o $@

../$(NAME):
	$(MAKE) -C ..

t:
	$(MAKE) -C .. re
	$(MAKE) re
	./test_strtrim
	
asan:
	$(MAKE) -C .. fclean
	$(MAKE) -C .. all CFLAGS="$(CFLAGS) -g -fsanitize=address"
	$(MAKE) clean
	$(MAKE) re CFLAGS="$(CFLAGS) -g -fsanitize=address"
	for t in $(TESTS); do ./$$t > /dev/null; done
	
help:
	@echo "Available targets:"
	@echo " re"
	@echo " test"
	@echo " clean"
	@echo " valgrind"
	@echo " asan"
	@echo " t"
	@echo " val_t"

re: $(TESTS)

test: re
	for t in $(TESTS); do ./$$t; done

clean:
	rm -f $(TESTS) $(ASAN_TESTS)

val_t: re
	valgrind --leak-check=full --show-leak-kinds=all ./test_strjoin
	
valgrind: re
	for t in $(TESTS); do valgrind --leak-check=full --show-leak-kinds=all ./$$t > /dev/null; done

.PHONY: asan help re test clean valgrind t
