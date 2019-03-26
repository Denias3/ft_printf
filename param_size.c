/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:49:40 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 17:53:01 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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
