NAME = libstrings.a

SRCS = $(wildcard src/ft_*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(CFLAGS) -I include -c $< -o $@

help:
	@echo "Available targets:"
	@echo " all"
	@echo " clean"
	@echo " fclean"
	@echo " re"

all:  $(NAME)
 
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re help
