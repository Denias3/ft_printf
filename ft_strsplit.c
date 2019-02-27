/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:16:26 by emeha             #+#    #+#             */
/*   Updated: 2019/01/04 10:24:17 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_strlenc(char *str, char c, int *i, int *size)
{
	*size = 0;
	while (str[*i] == c)
		(*i)++;
	while (str[*i + *size] != c)
	{
		if (str[*i + *size] == '\0')
			break ;
		(*size)++;
	}
}

static int	checki(char *str, char c)
{
	int i;
	int s;
	int ch;

	if (str == NULL)
		return (-1);
	i = 0;
	s = 0;
	while (str[i])
	{
		ch = 1;
		while (str[i] != c)
		{
			if (str[i] == '\0')
				return (s);
			if (ch == 1)
			{
				ch = 0;
				s++;
			}
			i++;
		}
		i++;
	}
	return (s);
}

static void	ft_strref_s(char *str, int *j)
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
	(*j)++;
}

static int	ft_arrdel(char **arr, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		it;
	char	**str;
	int		i;
	int		size;
	int		j;

	j = 0;
	i = 0;
	size = 0;
	if ((it = checki((char*)s, c)) == -1)
		return (NULL);
	str = (char**)malloc(sizeof(char*) * (it + 1));
	if (str == NULL)
		return (NULL);
	while (j < it)
	{
		ft_strlenc((char*)s, c, &i, &size);
		if ((str[j] = ft_strnew(size)) == NULL && ft_arrdel(str, j))
			return (str);
		while (size--)
			str[j][size] = s[i++];
		ft_strref_s(str[j], &j);
	}
	str[j] = NULL;
	return (str);
}
