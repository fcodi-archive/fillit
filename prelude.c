/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prelude.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:09:10 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/17 21:14:48 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate_file(const char *file, const int nread,
		unsigned int *ntetramino)
{
	int		i;

	if (nread > FILE_MAX_LENGTH || (nread + 1) % 21 != 0)
		return (FILE_BAD_LENGTH);
	i = 0;
	while (file[i] == '.' || file[i] == '#' || file[i] == '\n')
		++i;
	if (file[i] != NUL)
		return (CONTAIN_WRONG_SYMBOLS);
	i = nread;
	while ((i -= 21) >= 0 && file[i] == '\n')
		continue;
	if (i != -1)
		return (ERROR);
	*ntetramino = (unsigned int)((nread + 1) / 21);
	if (ft_nsym(file, '#') != (4 * *ntetramino)
		|| ft_nsym(file, '.') != (12 * *ntetramino)
		|| ft_nsym(file, '\n') != ((4 * *ntetramino) + (*ntetramino - 1)))
		return (INVALID_GRID);
	return (OK);
}

int		count_neighbours(const char *file, const int i, const int nread)
{
	const int	top = (i / 21) * 21;
	const int	bottom = ((i / 21) + 1) * 21;
	int			count;

	count = 0;
	if (i + 1 <= nread && i + 1 <= bottom && file[i + 1] && file[i + 1] == '#')
		++count;
	if (i - 1 >= 0 && i - 1 >= top && file[i + 1] && file[i - 1] == '#')
		++count;
	if (i + 5 <= nread && i + 5 <= bottom && file[i + 5] && file[i + 5] == '#')
		++count;
	if (i - 5 >= 0 && i - 5 >= top && file[i - 5] && file[i - 5] == '#')
		++count;
	return (count);
}

int		validate_tetraminos(const char *file, const int nread)
{
	int		i;
	int		count;
	int		nsharp;
	int		sharp_neighbours;

	i = (int)ft_strnchri(file, '#', 0);
	count = 0;
	nsharp = 0;
	while (i >= 0 && file[i] && file[i] == '#')
	{
		if ((sharp_neighbours = count_neighbours(file, i, nread)) < 1)
			return (BAD_TETRAMINOS);
		count += sharp_neighbours;
		++nsharp;
		if (nsharp == 4 ? !(nsharp = 0) : nsharp == 4)
			if (count >= 6 && count <= 8 ? (count = 0) : count)
				return (BAD_TETRAMINOS);
		i = (int)ft_strnchri(file, '#', (size_t)i + 1);
	}
	return (OK);
}

void	tetramino_fill(const char *file, t_tetramino t[26])
{
	const int	max_tetraminos = ((int)ft_strlen(file) + 1) / 21;
	int			ntetramino;
	int			nsharp;
	int			i;
	int			sampler[2];

	i = (int)ft_strnchri(file, '#', 0);
	ntetramino = -1;
	while (++ntetramino < max_tetraminos)
	{
		sampler[SAMPLER_X] = (i - (ntetramino * 21)) % 5;
		sampler[SAMPLER_Y] = (i - (ntetramino * 21)) / 5;
		nsharp = -1;
		while (++nsharp < 4)
		{
			t[ntetramino].x[nsharp] =
					((i - (ntetramino * 21)) % 5) - sampler[SAMPLER_X];
			t[ntetramino].y[nsharp] =
					((i - (ntetramino * 21)) / 5) - sampler[SAMPLER_Y];
			i = (int)ft_strnchri(file, '#', (unsigned int)i + 1);
		}
		t[ntetramino].x[LAST_POINT] = -1;
		t[ntetramino].y[LAST_POINT] = -1;
	}
}

int		prelude(const char *path, t_tetramino t[26], unsigned int *ntetramino)
{
	char	file[FILE_MAX_LENGTH + 1];
	int		result;
	int		nread;
	int		fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (VALIDATION_IO_ERROR);
	if ((nread = (int)read(fd, file, FILE_MAX_LENGTH + 1)) < 0)
		return (VALIDATION_IO_ERROR);
	file[nread] = NUL;
	close(fd);
	if ((result = validate_file(file, nread, ntetramino)) != OK)
		return (result);
	if ((result = validate_tetraminos(file, nread)) != OK)
		return (result);
	tetramino_fill(file, t);
	return (result);
}
