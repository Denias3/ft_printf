/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strref.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:54:24 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 17:05:27 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strref(char *str)
{
	int		i;
	int		s;
	char	temp;

	s = ft_strlen(str) - 1;
	i = 0;
	while (i < s)
	{
		temp = str[s];
		str[s] = str[i];
		str[i] = temp;
		i++;
		s--;
	}
}
