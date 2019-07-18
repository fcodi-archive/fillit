/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:57:13 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_available_size(const char *dst, size_t cat_size)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < cat_size)
		++i;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	available_size;
	size_t	i;

	src_size = ft_strlen(src);
	available_size = ft_get_available_size(dst, size);
	if (available_size == size)
		return (size + src_size);
	i = available_size - 1;
	while (++i < (size - 1) && src[i - available_size])
		dst[i] = src[i - available_size];
	dst[i] = NUL;
	return (available_size + src_size);
}
