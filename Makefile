NAME = libftprintf.a
OUT = *.o
HEAD = header.h
SRC = *.c
all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)
clean:
	rm -rf $(OUT)
fclean: clean
	rm -rf $(NAME)
re: fclean all