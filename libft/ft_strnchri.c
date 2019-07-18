/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnchri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:26:47 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnchri(const char *string, const char c, const size_t i)
{
	size_t	n;

	if (!string)
		return (0);
	n = i;
	while (string[n] && string[n] != c)
		++n;
	return (string[n] != c ? ERROR : n);
}
