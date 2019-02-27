/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:40:09 by emeha             #+#    #+#             */
/*   Updated: 2019/01/16 17:03:10 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int s;

	s = 0;
	i = 0;
	while (s1[s] != '\0')
		s++;
	while (s2[i] != '\0')
	{
		s1[s] = s2[i];
		i++;
		s++;
	}
	s1[s] = '\0';
	return (s1);
}
