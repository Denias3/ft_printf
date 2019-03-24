/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:16:50 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 09:49:00 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		t1;
	int		t2;
	int		size;
	char	*str;

	size = 0;
	t1 = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	while (s[t1] == '\n' || s[t1] == '\t' || s[t1] == ' ')
		t1++;
	t2 = size - 1;
	while (s[t2] == '\n' || s[t2] == '\t' || s[t2] == ' ')
		t2--;
	t2++;
	if (t1 == size)
		t2 = t1;
	size = t2 - t1;
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	str = ft_memmove((void*)&str[0], &s[t1], size);
	return (str);
}
