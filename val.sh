make re
make clean
cd test
gcc main.c ../libftprintf.a
valgrind --leak-check=full ./a.out
cd ..

