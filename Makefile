NAME = libftprintf.a
FILEC = *.c

FILEO = *.o

LIB = libft.h

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