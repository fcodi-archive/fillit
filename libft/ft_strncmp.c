/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:38:34 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = -1;
	while (++i < (int)n && s1[i] == s2[i] && s1[i] && s2[i])
		continue;
	if (i == (int)n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
