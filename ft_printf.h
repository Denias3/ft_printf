/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:42:41 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 18:39:39 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct		s_flist
{
	char			spec;
	int				accu_l;
	short			dot;
	int				accu_r;
	char			*flag;
	short			hash;
	short			zero;
	short			plus;
	short			minus;
	short			space;
}					t_flist;

t_flist				*flist_new_pf(void);
int					printf_flag_c(int	c, t_flist *elem);
int					printf_flag_s(char *n, t_flist *elem);
int					printf_flag_p(char *n, t_flist *elem);
int					printf_flag_d(long long int n, t_flist *elem);
int					printf_flag_o(char *str, t_flist *elem);
int					printf_flag_u(unsigned long long n, t_flist *elem);
int					printf_flag_x(char *str, t_flist *elem);
void				flist_free(t_flist *elem);
char				*ft_read_double(long double n, t_flist *elem);
char				*ft_read_l_double(long double n, t_flist *elem);
int					printf_flag_f(char *str, t_flist *elem);
int					ft_printf(char *format, ...);
char				*rounding(char *str);
t_flist				*specifiers(char **format);
int					solve_printf(char *format, va_list ap);
long long			param_size(long long n, char *str);
unsigned long long	param_size_u(unsigned long long n, t_flist *elem);
void				solve_dop_1(t_flist *elem, va_list ap);
void				solve_dop_2(t_flist *elem, va_list ap);
void				solve_dop_3(t_flist *elem, va_list ap);
void				solve_dop_4(t_flist *elem, va_list ap);
void				solve_dop_5(t_flist *elem, char **format);
void				specifiers_5(char **format, short *ch, t_flist *elem);

#endif
