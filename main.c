/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:23:16 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/17 21:14:46 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		put_tetramino_write(char **table, t_tetramino *t,
		const int nt, const int size)
{
	int			ns;
	const int	x = t[nt].x[CURRENT];
	const int	y = t[nt].y[CURRENT];

	if (table[y][x] != '.')
		return (ERROR);
	ns = 0;
	while (++ns < 4 && x + t[nt].x[ns] < size && x + t[nt].x[ns] >= 0
	&& y + t[nt].y[ns] < size
	&& y + t[nt].y[ns] >= 0 && table[y + t[nt].y[ns]][x + t[nt].x[ns]] == '.')
		continue;
	if (ns != 4)
		return (ERROR);
	table[y][x] = (char)('A' + nt);
	ns = 0;
	while (++ns < 4)
		table[y + t[nt].y[ns]][x + t[nt].x[ns]] = (char)('A' + nt);
	t[nt].x[LAST_POINT] = x;
	t[nt].y[LAST_POINT] = y;
	return (OK);
}

int		put_tetramino(char **table, t_tetramino t[26],
		const int nt, const int size)
{
	int		x;
	int		y;

	put_tetramino_init(t, nt, &x, &y);
	del_tetramino(table, nt);
	while (y < size)
	{
		if (x-- >= size ? !(x = 0) && ++y : FALSE)
			continue;
		while (++x < size)
		{
			t[nt].x[CURRENT] = x;
			t[nt].y[CURRENT] = y;
			if (put_tetramino_write(table, t, nt, size) == OK)
				return (OK);
		}
	}
	return (NOT_ENOUGH_SPACE);
}

int		fill(t_tetramino t[26], const unsigned int max_tetraminos,
		const unsigned int size)
{
	char			**table;
	unsigned int	ntetramino;
	int				result;

	if (!(table = ft_astr_new(size, size)))
		return (ERROR);
	ntetramino = 0;
	ft_astr_fill_c(table, size, '.');
	while (ntetramino < max_tetraminos)
		if ((result = put_tetramino(table, t, ntetramino, size)) == OK)
			++ntetramino;
		else if (result == NOT_ENOUGH_SPACE && ntetramino == 0)
		{
			ft_astr_del(table);
			return (NOT_ENOUGH_SPACE);
		}
		else
		{
			clear_start_positions(t, ntetramino, max_tetraminos);
			del_tetramino(table, ntetramino--);
		}
	ft_astr_put(table);
	ft_astr_del(table);
	return (OK);
}

int		fillit(t_tetramino t[26], const unsigned int ntetramino)
{
	unsigned int	size;
	int				result;

	result = 777;
	size = min_size_of_table(ntetramino * 4);
	while (result != OK)
		if ((result = fill(t, ntetramino, size)) == ERROR)
			return (ERROR);
		else if (result == NOT_ENOUGH_SPACE)
		{
			clear_start_positions(t, 0, ntetramino);
			++size;
		}
	return (OK);
}

int		main(int argc, char **argv)
{
	t_tetramino		t[26];
	unsigned int	ntetramino;
	int				result;

	result = OK;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit tetramino_file\n");
		return (0);
	}
	if ((result = prelude(argv[1], t, &ntetramino)) != OK)
	{
		ft_putstr("error\n");
		return (result);
	}
	fillit(t, ntetramino);
	return (result);
}
