cmake_minimum_required(VERSION 3.13)
project(ft_printf C)

set(CMAKE_C_STANDARD 90)
file(GLOB CPPS "ft_*.c")
file(GLOB FLAG "-Wall -Wextra -Werror")

add_executable(ft_printf ${CPPS} ${FLAG} ft_printf.h ft_flist_fun.c ft_itoa_base.c ft_strref.c ft_pow.c ft_chardup.c ft_float_bits.c ft_powneg.c ft_read_double.c trans_dec.c ft_read_float.c ft_read_bits.c ft_print_flag_p.c printf_flag_c.c printf_flag_d.c printf_flag_s.c ft_check_null.c ft_print_memory.c printf_flag_o.c  printf_flag_u.c)