/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 23:02:58 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if ((new_list = (t_list *)malloc(sizeof(t_list))))
	{
		if ((new_list->content = malloc(content_size)))
		{
			if (content)
			{
				ft_memcpy(new_list->content, content, content_size);
				new_list->content_size = content_size;
			}
			else
			{
				new_list->content = NULL;
				new_list->content_size = 0;
			}
			new_list->next = NULL;
		}
		else
		{
			free(new_list);
			return (NULL);
		}
	}
	return (new_list);
}
