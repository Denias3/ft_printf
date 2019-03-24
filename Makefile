NAME = libftprintf.a
FILEC = *.c ./libft/*.c

FILEO = *.o

LIB = ft_printf.h ./libft/libft.h 

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILEC)
	gcc $(FLAG) -c $(FILEC) -I $(LIB)
	ar rc $(NAME) $(FILEO)
	ranlib $(NAME)

clean:
	rm -rf $(FILEO)

fclean: clean
	rm -rf $(NAME)

re: fclean all