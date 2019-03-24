/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:25:02 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 20:51:15 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	rounding_1(char **str, int *i, int *ch)
{
	if ((*str)[*i] >= '0' && (*str)[*i] <= '8' && *ch == 2)
	{
		(*str)[*i] = (*str)[*i] + 1;
		*ch = 0;
	}
	else if ((*str)[*i] == '9' && *ch == 2)
	{
		(*str)[*i] = '0';
		if ((*str)[*i + 1] == '\0')
		{
			(*str) = ft_strjoin_free((*str), ft_chardup('1'));
			return (1);
		}
		*ch = 2;
	}
	return (0);
}

static void	rounding_2(char **str, int *i, int *ch, int in)
{
	if (in == 1)
	{
		(*str)[*i] = '0';
		(*str)[*i + 1] = (*str)[*i + 1] + 1;
		*ch = 0;
	}
	else if (in == 2)
	{
		(*str)[*i] = '0';
		(*str)[*i + 1] = (*str)[*i + 1] - 9;
		*ch = 1;
	}
	else if (in == 3)
	{
		(*str)[*i] = '0';
		*ch = 2;
		(*i)++;
	}
}

char		*rounding(char *str)
{
	int		i;
	int		ch;

	ch = 0;
	i = 0;
	ft_strref(str);
	if (str[i] >= '5')
		ch = 1;
	while (ch > 0)
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '8' && ch == 1)
			rounding_2(&str, &i, &ch, 1);
		else if (str[i + 1] == '9' && ch == 1)
			rounding_2(&str, &i, &ch, 2);
		else if (str[i + 1] == '.')
			rounding_2(&str, &i, &ch, 3);
		else if (ch == 2)
			if (rounding_1(&str, &i, &ch))
				break ;
		i++;
	}
	ft_strref(str);
	return (str);
}
