NAME = libstrings.a

SRCS = src/ft_strlen.c src/ft_isalpha.c \
	   src/ft_strdup.c src/ft_strncmp.c \
	   src/ft_strchr.c src/ft_strrchr.c \
	   src/ft_memchr.c src/ft_memcmp.c \
	   src/ft_memset.c src/ft_bzero.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(CFLAGS) -I include -c $< -o $@

all:  $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
