NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

FILES = test_isalpha.c test_isdigit.c test_isalnum.c test_isascii.c test_isprint.c \
	test_strlen.c test_memset.c test_bzero.c test_memcpy.c test_memmove.c \
	test_strlcpy.c test_strlcat.c test_toupper.c test_tolower.c test_strchr.c \
	test_strrchr.c test_strncmp.c test_memchr.c test_memcmp.c test_strnstr.c \
	test_atoi.c test_calloc.c test_strdup.c test_substr.c test_strjoin.c \
	test_strtrim.c test_split.c test_itoa.c test_strmapi.c test_striteri.c \
	test_putchar_fd.c test_putstr_fd.c test_putendl_fd.c test_putnbr_fd.c \
	test_lstnew.c test_lstadd_front.c test_lstsize.c test_lstlast.c \
	test_lstadd_back.c test_lstdelone.c test_lstclear.c test_lstiter \
	test_lstmap.c

TESTS = $(FILES:.c=)

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

	
help:
	@echo "Available targets:"
	@echo " clean fclean"
	@echo " t, t_bonus"
	@echo " test, test_all, bonus"
	@echo " valgrin, val_all, val_bonus"
	@echo " asan, asan_all, asan_bonus"

test: 
	$(MAKE) -C ../src re
	$(MAKE) $(TESTS)
	for t in $(TESTS); do ./$$t; done

clean:
	rm -f $(TESTS)

fclean:
	$(MAKE) -C ../src fclean
	$(MAKE) clean

valgrind:
	$(MAKE) -C ../src re
	$(MAKE) $(TESTS)
	for t in $(TESTS); do valgrind --leak-check=full --show-leak-kinds=all ./$$t > /dev/null; done
	
.PHONY: t test clean fclean valgrind asan help
