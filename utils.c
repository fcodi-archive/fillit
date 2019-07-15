/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:23:13 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/09 21:42:07 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void			clear_start_positions(t_tetramino *t, int ntetramino,
		const int max_tetraminos)
{
	while (ntetramino < max_tetraminos)
	{
		t[ntetramino].x[LAST_POINT] = -1;
		t[ntetramino].y[LAST_POINT] = -1;
		++ntetramino;
	}
}

void			put_tetramino_init(t_tetramino *t,
		const int ntetramino, int *x, int *y)
{
	if (t[ntetramino].x[LAST_POINT] != -1)
		*x = t[ntetramino].x[LAST_POINT] + 1;
	else
		*x = 0;
	if (t[ntetramino].y[LAST_POINT] != -1)
		*y = t[ntetramino].y[LAST_POINT];
	else
		*y = 0;
}

void			del_tetramino(char **table, const int ntetramino)
{
	int		x;
	int		y;

	y = -1;
	while (table[++y])
	{
		x = -1;
		while (table[y][++x])
			if (table[y][x] == 'A' + ntetramino)
				table[y][x] = '.';
	}
}

int				min_size_of_table(const int nsharps)
{
	int	n;

	n = 1;
	while (++n)
		if (n * n >= nsharps)
			break ;
	return (n);
}
