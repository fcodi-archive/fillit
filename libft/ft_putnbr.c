/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 05:24:23 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static unsigned int		ft_get_factor(unsigned int index)
{
	unsigned int	factor;

	factor = ++index ? 1 : FALSE;
	while (--index > 0)
		factor *= 10;
	return (factor);
}

void					ft_putnbr(int n)
{
	unsigned int	factor;
	unsigned int	un;
	unsigned int	size;

	un = n < 0 ? (unsigned int)(n * -1) : (unsigned int)n;
	n < 0 ? ft_putchar('-') : FALSE;
	size = (unsigned int)ft_uintlen(un);
	factor = ft_get_factor(size);
	while (un > 9 ? --size && (factor = ft_get_factor(size))
		: factor > 0 && (factor /= 10))
	{
		ft_putchar((char)(un / factor + '0'));
		un %= factor;
	}
}
