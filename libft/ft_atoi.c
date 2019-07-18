/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:05:35 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		init(size_t *n, size_t *size, short *sign)
{
	*n = 0;
	*size = 0;
	*sign = 1;
}

int				ft_atoi(const char *str)
{
	size_t	n;
	size_t	size;
	short	sign;

	if (*str == '\e')
		return (0);
	init(&n, &size, &sign);
	while (*str && ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str && ft_isdigit(*str) && (++size))
		(n = n * 10 + (*str - '0')) ? ++str : ++str;
	if (size > 18)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return ((int)(n * sign));
}
