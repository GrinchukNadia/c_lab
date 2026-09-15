NAME = libstrings.a

SRCS = src/ft_strlen.c \
	   src/ft_isalpha.c \
	   src/ft_strdup.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(CFLAGS) -I include -c $< -o $@

all:  $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

test_build: $(NAME)
	cc $(CFLAGS) -I include tests/test_strdup.c tests/test.c $(NAME) -o test
	
test: test_build
	./test

valgrind: test_build
	valgrind --leak-check=full ./test

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all test_build test valgrind clean fclean re
