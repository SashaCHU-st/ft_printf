NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_print_num.c \
			ft_print_ptr.c \
			ft_printf_strchar.c \
			ft_printf.c \
			ft_print_hexa.c \

OBJ = ${SOURCES:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re