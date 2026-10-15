NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SOURCE_TESTS = $(patsubst ../src/ft_%.c,test_%.c,$(wildcard ../src/ft_*.c))

FILES = $(filter $(SOURCE_TESTS),$(wildcard test_*.c))

TESTS = $(FILES:.c=)

ALL_TESTS = $(patsubst %.c,%,$(wildcard test_*.c))

%: %.c test.c ../src/$(NAME)
	cc $(CFLAGS) -g -I ../src $<  test.c ../src/$(NAME) -o $@

../src/$(NAME):
	$(MAKE) -C ../src

t:
	$(MAKE) -C ../src re
	$(MAKE) $(TESTS)
	./test_atoi
	
asan:
	$(MAKE) -C ../src fclean
	$(MAKE) -C ../src all CFLAGS="$(CFLAGS) -g -fsanitize=address"
	$(MAKE) clean
	$(MAKE) $(TESTS) CFLAGS="$(CFLAGS) -g -fsanitize=address"
	for t in $(TESTS); do ./$$t > /dev/null; done

sum:
	$(MAKE) -C ../src re
	$(MAKE) clean
	$(MAKE) $(TESTS)
	for t in $(TESTS); do ./$$t > /dev/null; done
	@bash ./summary.sh $(TESTS)
	
help:
	@echo "Available targets:"
	@echo " clean fclean"
	@echo " t"
	@echo " test"
	@echo " valgrind"
	@echo " asan"
	@echo " sum"

test: 
	$(MAKE) -C ../src re
	$(MAKE) clean
	@if [ -z "$(strip $(TESTS))" ]; then \
	 echo "No matching tests found"; \
	else \
	 $(MAKE) $(TESTS) || exit $$?; \
	 status=0; \
	 for t in $(TESTS); do \
	  ./$$t || status=1; \
	 done; \
	 exit $$status; \
	fi

clean:
	rm -f $(ALL_TESTS)

fclean:
	$(MAKE) -C ../src fclean
	$(MAKE) clean

valgrind:
	$(MAKE) -C ../src re
	$(MAKE) $(TESTS)
	for t in $(TESTS); do valgrind --leak-check=full --show-leak-kinds=all ./$$t > /dev/null; done
	
.PHONY: t test clean fclean valgrind asan help sum
