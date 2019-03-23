/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:25:02 by emeha             #+#    #+#             */
/*   Updated: 2019/03/23 13:25:05 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char *rounding(char *str)
{
	int i;
	int ch;
	char *tmp;

	ch = 0;
	i = 0;
	ft_strref(str);
	if (str[i] >= '5')
		ch = 1;
	while (ch > 0)
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '8' && ch == 1)
		{
			str[i] = '0';
			str[i + 1] = str[i + 1] + 1;
			ch = 0;
		}
		else if (str[i + 1] == '9' && ch == 1)
		{
			str[i] = '0';
			str[i + 1] = str[i + 1] - 9;
			ch = 1;
		}
		else if (str[i + 1] == '.')
		{
			str[i] = '0';
			ch = 2;
			i++;
		}
		else if (ch == 2)
		{
			if (str[i] >= '0' && str[i] <= '8' && ch == 2)
			{
				str[i] = str[i] + 1;
				ch = 0;
			}
			else if (str[i] == '9' && ch == 2)
			{
				str[i] = '0';
				if (str[i + 1] == '\0')
				{
					tmp = str;
					str = ft_strjoin(str, "1");
					free(tmp);
					break ;
				}
				ch = 2;
			}
		}
		i++;
	}
	ft_strref(str);
	return (str);
}
