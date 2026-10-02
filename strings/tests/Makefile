NAME = libstrings.a

CFLAGS = -Wall -Wextra -Werror

FILES = $(filter-out %_bonus.c, $(wildcard test_*.c))
TESTS = $(FILES:.c=)

BONUS = $(wildcard test_*_bonus.c)
BONUS_TESTS = $(BONUS:.c=)

ALL = $(wildcard test_*.c)
ALL_TESTS = $(ALL:.c=)

%: %.c test.c ../src/$(NAME)
	cc $(CFLAGS) -g -I ../src $<  test.c ../src/$(NAME) -o $@

../src/$(NAME):
	$(MAKE) -C ../src

t:
	$(MAKE) -C ../src re
	$(MAKE) $(TESTS)
	./test_toupper

t_bonus:
	$(MAKE) -C ../src re
	$(MAKE) -C ../src bonus
	$(MAKE) $(ALL_TESTS)
	./test_lstnew_bonus
	
asan:
	$(MAKE) -C ../src fclean
	$(MAKE) -C ../src all CFLAGS="$(CFLAGS) -g -fsanitize=address"
	$(MAKE) clean
	$(MAKE) $(TESTS) CFLAGS="$(CFLAGS) -g -fsanitize=address"
	for t in $(TESTS); do ./$$t > /dev/null; done

asan_all:
	$(MAKE) -C ../src fclean
	$(MAKE) -C ../src all CFLAGS="$(CFLAGS) -g -fsanitize=address"
	$(MAKE) -C ../src bonus CFLAGS="$(CFLAGS) -g -fsanitize=address"
	$(MAKE) clean
	$(MAKE) $(ALL_TESTS) CFLAGS="$(CFLAGS) -g -fsanitize=address"
	for t in $(ALL_TESTS); do ./$$t > /dev/null; done

asan_bonus:
	$(MAKE) -C ../src fclean
	$(MAKE) -C ../src all CFLAGS="$(CFLAGS) -g -fsanitize=address"
	$(MAKE) -C ../src bonus CFLAGS="$(CFLAGS) -g -fsanitize=address"
	$(MAKE) clean
	$(MAKE) $(BONUS_TESTS) CFLAGS="$(CFLAGS) -g -fsanitize=address"
	for t in $(BONUS_TESTS); do ./$$t > /dev/null; done
	
help:
	@echo "Available targets:"
	@echo " clean"
	@echo " t, t_bonus"
	@echo " test, test_all, bonus"
	@echo " valgrin, val_all, val_bonus"
	@echo " asan, asan_all, asan_bonus"

test: 
	$(MAKE) -C ../src re
	$(MAKE) $(TESTS)
	for t in $(TESTS); do ./$$t; done

bonus: 
	$(MAKE) -C ../src re
	$(MAKE) -C ../src bonus
	$(MAKE) $(BONUS_TESTS)
	for t in $(BONUS_TESTS); do ./$$t; done

test_all:
	$(MAKE) -C ../src re
	$(MAKE) -C ../src bonus
	$(MAKE) $(ALL_TESTS)
	for t in $(ALL_TESTS); do ./$$t; done

clean:
	rm -f $(ALL_TESTS)

valgrind:
	$(MAKE) -C ../src re
	$(MAKE) $(TESTS)
	for t in $(TESTS); do valgrind --leak-check=full --show-leak-kinds=all ./$$t > /dev/null; done

val_bonus:
	$(MAKE) -C ../src re
	$(MAKE) -C ../src bonus
	$(MAKE) $(BONUS_TESTS)
	for t in $(BONUS_TESTS); do valgrind --leak-check=full --show-leak-kinds=all ./$$t > /dev/null; done

val_all:
	$(MAKE) -C ../src re
	$(MAKE) -C ../src bonus
	$(MAKE) $(ALL_TESTS)
	for t in $(ALL_TESTS); do valgrind --leak-check=full --show-leak-kinds=all ./$$t > /dev/null; done
	
.PHONY: t t_bonus test bonus test_all clean \
	valgrind val_bonus val_all \
	asan asan_bonus asan_all help
