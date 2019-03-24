/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:37:04 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 15:43:54 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa_base(int value, int base)
{
	char *str;

	str = ft_strnew(0);
	while (value >= base)
	{
		if ((value % base) < 10)
			str = ft_strjoin(str, ft_itoa(value % base));
		else if ((value % base) > 9)
			str = ft_strjoin(str, ft_chardup(55 + (value % base)));
		value = value / base;
	}
	if ((value % base) < 10)
		str = ft_strjoin(str, ft_itoa(value % base));
	else if ((value % base) > 9)
		str = ft_strjoin(str, ft_chardup(55 + (value % base)));
	ft_strref(str);
	return (str);
}
