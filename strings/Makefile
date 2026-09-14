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

test: $(NAME)
	cc $(CFLAGS) -I include tests/test_strlen.c tests/test.c $(NAME) -o test
	./test

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: test clean fclean re
