/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:04:52 by emeha             #+#    #+#             */
/*   Updated: 2019/03/20 16:10:59 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static unsigned long long	ft_numlen_u(unsigned long long n)
{
    long long  s;
    long long del;

    del = 10;
    s = 1;
    while (n > 9)
    {
        s++;
        n = n / del;
    }
    return (s);
}

int printf_flag_u(unsigned long long n, t_flist *elem)
{
    int z;
    int s;
    int i;

    i = 0;
    if (n == 0 && elem->accu_r == 0)
        s = 1;
    else if ((int)ft_numlen_u(n) > elem->accu_r)
        s = ft_numlen_u(n);
    else
        s = elem->accu_r;
    z = 0;
    if (elem->minus == 0)
    {
        while (i < elem->accu_l - z - s&& (elem->dot == 1 || (elem->accu_r == 0 && elem->zero == 0)))
        {
            ft_putchar(' ');
            i++;
        }
        while (i < elem->accu_l - z - s && elem->dot == 0)
        {
            ft_putchar('0');
            i++;
        }
        s = ft_numlen_u(n);
        while (elem->accu_r - s > 0)
        {
            ft_putchar('0');
            s++;
        }
        if (n == 0 && elem->dot == 1 && elem->accu_r == 0)
            s = 0;
        else
            ft_putnbr_u(n);
        return (s + i + z);
    }
    else
    {
        s = ft_numlen_u(n);
        while (elem->accu_r - s > 0)
        {
            ft_putchar('0');
            s++;
        }
        ft_putnbr_u(n);
        while (i < elem->accu_l - z - s && (elem->dot == 1 || elem->accu_r == 0))
        {
            ft_putchar(' ');
            i++;
        }
        return (s + i + z);
    }
}
