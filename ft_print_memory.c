/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:16:32 by emeha             #+#    #+#             */
/*   Updated: 2019/01/21 17:16:35 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_print_memory(char *str_bit)
{
	char	*str;
	int 	i;
	int 	j;
	int		num;
	int     ch = 0;

	i = 0;
	str = ft_strnew(0);
	while (i < 48)
	{
		num = 0;
		j = 3;
		while (j >= 0)
		{
			if (str_bit[i] == '1')
				num = num + (ft_pow(2, j));
			i++;
			j--;
		}
		if (num != 0)
			ch = 1;
		if (ch || i == 44)
		{
			if (num <= 9 && num >= 0)
				str = ft_strjoin(str, ft_itoa(num));
			else if (num <= 15 && num >= 10)
				str = ft_strjoin(str, ft_chardup(num + 87));
		}
	}
	return (str);
}