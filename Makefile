CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = utils/ft_putstr.c utils/ft_putnbr_base.c \
utils/ft_putnbr.c utils/ft_putchar.c ft_printf.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
