/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:07:07 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 18:08:26 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	specifiers_5(char **format, short *ch, t_flist *elem)
{
	*ch = 1;
	elem->dot = *ch;
	if (*(*(format) + 1) == '0')
		(*format)++;
}
