/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#0+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:41:00 by emeha             #+#    #+#             */
/*   Updated: 2019/01/14 14:41:02 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_read_bits(void *m)
{
	int i;
	char *str;
	char *tmp;

	i = 0;
	str = ft_strnew(0);
	while (i < 48)
	{
		tmp = str;
		str = ft_strjoin(str, ft_itoa(((long)m) >> (47 - i) & 1));
		free(tmp);
		i++;
	}
	return (str);
}
