/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:52:16 by emeha             #+#    #+#             */
/*   Updated: 2019/03/18 19:24:56 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned long long  ft_strlenn(unsigned long long n, unsigned long long *del)
{
    int s;

    s = 0;
    while (del)
    {
        s++;
        if ((n / *del) == 0)
            break ;
        *del = *del * 10;
    }
    return (s);
}

static unsigned long long	ft_utoa_alg(unsigned long long *n, unsigned long long *del, unsigned long long num)
{
    num = *n / (*del /= 10);
    *n -= num * *del;
    return (num);
}

char		*ft_utoa(unsigned long long n)
{
    unsigned long long	del;
    int		i;
    int		s;
    unsigned long long	num;
    char	*nb;

    i = 0;
    del = 10;
    num = 0;
    s = ft_strlenn(n, &del);
    if ((nb = ft_strnew(s += i)) == NULL)
        return (NULL);
    while (i < s)
        nb[i++] = (ft_utoa_alg(&n, &del, num) + 48);
    return (nb);
}

char		*ft_utoa_base(unsigned long long value, unsigned long long  base)
{
    char *str;
    char *tmp;
    char *tmp2;

    str = ft_strnew(0);
    while (value >= base)
    {
        tmp = str;
        if ((value % base) < 10)
        {
            tmp2 = ft_utoa(value % base);
            str = ft_strjoin(str, tmp2);
            free(tmp2);
        }
        else if ((value % base) > 9)
        {
            tmp2 = ft_chardup(55 + (value % base));
            str = ft_strjoin(str, tmp2);
            free(tmp2);
        }
        free(tmp);
        value = value / base;
    }
    tmp = str;
    if ((value % base) < 10)
    {
        tmp2 = ft_utoa(value % base);
        str = ft_strjoin(str, tmp2);
        free(tmp2);
    }
    else if ((value % base) > 9)
    {
        tmp2 = ft_chardup(55 + (value % base));
        str = ft_strjoin(str, tmp2);
        free(tmp2);
    }
    free(tmp);
    ft_strref(str);
    return (str);
}
