/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:02 by emeha             #+#    #+#             */
/*   Updated: 2019/02/27 17:46:04 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int printf_flag_o(int n, t_flist *elem)
{
    int z;
    int s;
    int i;

    i = 0;
    if (ft_numlen(n) > elem->accu_r)
        s = ft_numlen(n);
    else
        s = elem->accu_r;
    z = 0;
    if (elem->hash)
        z = 1;
    if (elem->minus == 0)
    {
        while (i < elem->accu_l - z - s && (elem->dot == 1 || elem->accu_r == 0) && elem->zero == 0)
        {
            ft_putchar(' ');
            i++;
        }
        if (elem->hash == 1)
            ft_putchar('0');
        while (i < elem->accu_l - z - s && elem->dot == 0)
        {
            ft_putchar('0');
            i++;
        }
        s = ft_numlen(n);
        while (elem->accu_r - s > 0)
        {
            ft_putchar('0');
            s++;
        }
        if (n == 0 && elem->dot == 1)
            s = 0;
        else
            ft_putnbr(n);
        return (s + i + z);
    }
    else
    {
        if (elem->hash == 1)
            ft_putchar('0');
        s = ft_numlen(n);
        while (elem->accu_r - s > 0)
        {
            ft_putchar('0');
            s++;
        }
        if (n != 0)
            ft_putnbr(n);
        else
            s = 0;
        while (i < elem->accu_l - z - s && (elem->dot == 1 || elem->accu_r == 0))
        {
            ft_putchar(' ');
            i++;
        }
        return (s + i + z);
    }
}
