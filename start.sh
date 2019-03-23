make re
make clean
cd test
gcc main.c ../libftprintf.a
./a.out
cd ..