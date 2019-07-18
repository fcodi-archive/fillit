/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsym.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:18:55 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count symbols c in constant array of char string
*/

ssize_t				ft_nsym(const char *string, char c)
{
	ssize_t			n;
	size_t			i;

	if (string)
	{
		n = 0;
		i = 0;
		while (string[i])
			if (string[i++] == c)
				++n;
	}
	else
		return (ERROR);
	return (n);
}
