/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:42:56 by emeha             #+#    #+#             */
/*   Updated: 2019/01/04 11:42:59 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

#include <stdio.h>

int g_s;

t_flist *specifiers(char **format)
{
	short		ch;
	t_flist     *elem;

	ch = 0;
	elem = flist_new_pf();
	while (**format != '\0')
	{
		if (**format == '#' || **format == ' ' ||
			**format == '+' || **format == '-')
		{
			if (**format == '#')
				elem->hash = 1;
			if (**format == ' ')
				elem->space = 1;
			if (**format == '+')
				elem->plus = 1;
			if (**format == '-')
				elem->minus = 1;
		}
		else if (**format >= '0' && **format <= '9')
		{
			if (**format == '0')
				elem->zero = 1;
			else
			{
				if (ch == 0)
				{
					elem->accu_l = ft_atoi(*format);
					*format = *format + ft_numlen(elem->accu_l) - 1;
				}
				else
				{
					elem->accu_r = ft_atoi(*format);
					*format = *format + ft_numlen(elem->accu_r) - 1;
				}
			}
		}
		else if (**format == '.')
		{
			ch = 1;
			elem->dot = ch;
		}
		else if (**format == 'h' || **format == 'l' || **format == 'L')
		{
			if (**format == *(*(format) + 1))
			{
				elem->flag = ft_strsub(*format, 0, 2);
				(*format)++;;
			}
			else
				elem->flag = ft_strsub(*format, 0, 1);
		}
		else
			break ;
		(*format)++;
	}
	elem->spec = **format;
	(*format)++;
	return (elem);

}


//void    flist_print(t_flist *elem)
//{
//	printf("spec - %c\n", elem->spec);
//	printf("accu_l - %d\n", elem->accu_l);
//	printf("accu_r - %d\n", elem->accu_r);
//	printf("dot - %d\n", elem->dot);
//	printf("flag - %s\n", elem->flag);
//	printf("hash - %d\n", elem->hash);
//	printf("zero - %d\n", elem->zero);
//	printf("plus - %d\n", elem->plus);
//	printf("minus - %d\n", elem->minus);
//	printf("space - %d\n", elem->space);
//	printf("\n\n");
//}


int     solve_printf(char *format, va_list ap)
{
	t_flist *elem;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			elem = specifiers(&format);
//			flist_print(elem);
			if (elem->spec == 'c')
				g_s += printf_flag_c(va_arg(ap, int), elem);
			else if (elem->spec == 's')
				g_s += printf_flag_s(va_arg(ap, char*), elem);
			else if (elem->spec == 'p')
				g_s += printf_flag_p(ft_print_memory(ft_read_bits(va_arg(ap, void*))), elem);
			else if (elem->spec == 'd' || elem->spec == 'i')
				g_s += printf_flag_d(va_arg(ap, int), elem);
			else if (elem->spec == 'o')
				g_s += printf_flag_d(ft_atoi(ft_itoa_base(va_arg(ap, unsigned int), 8)), elem);
			else if (elem->spec == 'u')
				g_s += printf_flag_d(va_arg(ap, unsigned int), elem);
//			else if (format[g_s] == 'x')
//			{
//				if ((data = printf_flag_s(ft_strlowcase(ft_itoa_base(va_arg(ap, unsigned int), 16)), l, r, tmp->dot)) == NULL)
//					return (-1);
//				tmp->data = data;
//				tmp->spec = 'x';
//				break ;
//			}
//			else if (format[g_s] == 'X')
//			{
//				if ((data = printf_flag_s(ft_itoa_base(va_arg(ap, unsigned int), 16), l, r, tmp->dot)) == NULL)
//					return (-1);
//				tmp->data = data;
//				tmp->spec = 'X';
//				break ;
//			}
//			else if (format[g_s] == '%')
//			{
//				if ((data = printf_flag_s(ft_itoa_base(va_arg(ap, unsigned int), 16), l, r, tmp->dot)) == NULL)
//					return (-1);
//				tmp->data = data;
//				tmp->spec = '%';
//				break;
//			}
//			else if (format[g_s] == 'f')
//			{
//				data = ft_read_double(va_arg(ap, double));
//				push_back_pf(&head, flist_new_pf(data, 'f', l, r));
//				break ;
//			}
			flist_free(elem);
		}
		if (*format && *format != '%')
		{
			ft_putchar(*format);
			format++;
			g_s++;
		}
	}
	return (0);
}


int	ft_printf(char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	solve_printf(format, ap);
	va_end (ap);
	return (g_s);
}
//
//int main()
//{
//	int s1 = ft_printf("|%#o|", 230);
//	printf("\nsize - %d", s1);
//    printf("\n|%#o|", 230);
//}