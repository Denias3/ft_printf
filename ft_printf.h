/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:42:41 by emeha             #+#    #+#             */
/*   Updated: 2019/03/21 16:50:27 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
#include <stdarg.h>

typedef	struct	s_flist
{
	char			spec;
	int		        accu_l;
	short 			dot;
	int 			accu_r;
	char            *flag;
	short           hash;
	short           zero;
	short           plus;
	short           minus;
	short           space;
}				t_flist;

t_flist			*flist_new_pf();
int             printf_flag_c(int	c, t_flist *elem);
int             printf_flag_s(char *n, t_flist *elem);
int             printf_flag_p(char *n, t_flist *elem);
int             printf_flag_d(long long int n, t_flist *elem);
int				printf_flag_o(char *str, t_flist *elem);
int             printf_flag_u(unsigned long long n, t_flist *elem);
int             printf_flag_x(char *str, t_flist *elem);
void            flist_free(t_flist *elem);
char			*ft_read_double(long double n, t_flist *elem);
int				printf_flag_f(char *str, t_flist *elem);
int				ft_printf(char *format, ...);
char			*rounding(char *str);

#endif
