NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils_hexa.c

OBJS = $(SRCS:.c=.o)

ICL = libftprintf.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

.c.o:
	gcc $(CFLAGS) -I $(ICL) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re