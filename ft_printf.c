/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:42:56 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 18:22:39 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int g_s;

t_flist				*specifiers(char **format)
{
	short		ch;
	t_flist		*elem;

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
		else if ((**format) == '0')
			elem->zero = 1;
		else if (**format >= '1' && **format <= '9')
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
				ch = 0;
			}
		}
		else if (**format == '.')
		{
			ch = 1;
			elem->dot = ch;
			if (*(*(format) + 1) == '0')
				(*format)++;
		}
		else if (**format == 'h' || **format == 'l' || **format == 'L')
		{
			if (**format == *(*(format) + 1))
			{
				elem->flag = ft_strsub(*format, 0, 2);
				(*format)++;
			}
			else
				elem->flag = ft_strsub(*format, 0, 1);
		}
		else
			break ;
		(*format)++;
	}
	if (**format == 's' || **format == 'c' || **format == 'p' ||
	**format == 'd' || **format == 'i' || **format == 'x' ||
	**format == 'X' || **format == 'u' || **format == 'o' ||
	**format == 'f' || **format == '%')
	{
		elem->spec = **format;
		(*format)++;
	}
	return (elem);
}

long long			param_size(long long n, char *str)
{
	if (str != NULL)
	{
		if (ft_strcmp(str, "h") == 0)
			n = (short int)n;
		else if (ft_strcmp(str, "hh") == 0)
			n = (signed char)n;
		else if (ft_strcmp(str, "l") == 0)
			n = (long int)n;
		else if (ft_strcmp(str, "ll") == 0)
			n = (long long int)n;
		else
			n = (int)n;
	}
	else
		n = (int)n;
	return (n);
}

unsigned long long	param_size_u(unsigned long long n, t_flist *elem)
{
	if (elem->flag != NULL || elem->spec == 'p')
	{
		if (elem->spec == 'p')
			n = (unsigned long long)n;
		else if (ft_strcmp(elem->flag, "h") == 0)
			n = (unsigned short)n;
		else if (ft_strcmp(elem->flag, "hh") == 0)
			n = (unsigned char)n;
		else if (ft_strcmp(elem->flag, "l") == 0)
			n = (unsigned long)n;
		else if (ft_strcmp(elem->flag, "ll") == 0)
			n = (unsigned long long)n;
		else
			n = (unsigned int)n;
	}
	else
		n = (unsigned int)n;
	return (n);
}

int					solve_printf(char *format, va_list ap)
{
	t_flist	*elem;
	char	*tmp;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			elem = specifiers(&format);
			if (elem->spec == 'c')
				g_s += printf_flag_c(va_arg(ap, int), elem);
			else if (elem->spec == 's')
				g_s += printf_flag_s(va_arg(ap, char*), elem);
			else if (elem->spec == 'p')
			{
				tmp = ft_utoa_base(param_size_u(va_arg(ap, unsigned long long),
						elem), 16);
				tmp = ft_strlowcase(tmp);
				g_s += printf_flag_p(tmp, elem);
				free(tmp);
			}
			else if (elem->spec == 'd' || elem->spec == 'i')
				g_s += printf_flag_d(param_size(
						va_arg(ap, long long int), elem->flag), elem);
			else if (elem->spec == 'o')
			{
				tmp = ft_utoa_base(param_size_u(
						va_arg(ap, unsigned long long), elem), 8);
				g_s += printf_flag_o(tmp, elem);
				free(tmp);
			}
			else if (elem->spec == 'u')
				g_s += printf_flag_u(param_size_u(
						va_arg(ap, unsigned long long), elem), elem);
			else if (elem->spec == 'X')
			{
				tmp = ft_utoa_base(param_size_u(
						va_arg(ap, unsigned long long), elem), 16);
				g_s += printf_flag_x(tmp, elem);
				free(tmp);
			}
			else if (elem->spec == 'x')
			{
				tmp = ft_utoa_base(param_size_u(
						va_arg(ap, unsigned long long), elem), 16);
				g_s += printf_flag_x(ft_strlowcase(tmp), elem);
				free(tmp);
			}
			else if (elem->spec == '%')
				g_s += printf_flag_c('%', elem);
			else if (elem->spec == 'f' && (ft_strcmp(elem->flag, "l") == 0 ||
					elem->flag == NULL || ft_strcmp(elem->flag, "ll") == 0))
			{
				tmp = ft_read_double(va_arg(ap, double), elem);
				tmp = rounding(tmp);
				g_s += printf_flag_f(tmp, elem);
			}
			else if (elem->spec == 'f' && ft_strcmp(elem->flag, "L") == 0)
			{
				tmp = ft_read_l_double(va_arg(ap, long double), elem);
				tmp = rounding(tmp);
				g_s += printf_flag_f(tmp, elem);
			}
			else
			{
				tmp = ft_chardup(*format);
				g_s += printf_flag_s(tmp, elem);
				free(tmp);
				if (*format)
					format++;
			}
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

int					ft_printf(char *format, ...)
{
	va_list ap;

	g_s = 0;
	va_start(ap, format);
	solve_printf(format, ap);
	va_end(ap);
	return (g_s);
}
