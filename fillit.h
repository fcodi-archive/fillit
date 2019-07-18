/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 05:02:05 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/17 21:14:58 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# define BUFF_SIZE 1
# include "libft/libft.h"
# include <fcntl.h>
# define OK 0
# define FILE_MAX_LENGTH 545
# define NORMINETTE_MAX_WIDTH 80
# define WRONG_ARGC 2
# define CONTAIN_WRONG_SYMBOLS 3
# define FILE_BAD_LENGTH 4
# define BAD_TETRAMINOS 5
# define INVALID_GRID 6
# define VALIDATION_IO_ERROR 7
# define SHOW_USAGE_IO_ERROR 8
# define SAMPLER_X 0
# define SAMPLER_Y 1
# define LAST_POINT 0
# define CURRENT 4
# define NOT_ENOUGH_SPACE -2

typedef struct	s_tetramino
{
	int			x[5];
	int			y[5];
}				t_tetramino;

int				validate_file(const char *file, const int nread,
				unsigned int *ntetramino);
int				validate_tetraminos(const char *file, const int nread);
int				count_neighbours(const char *file, const int i,
				const int nread);
int				prelude(const char *path, t_tetramino t[26],
				unsigned int *ntetramino);
int				min_size_of_table(const int nsharps);
void			del_tetramino(char **table, const int ntetramino);
void			put_tetramino_init(t_tetramino t[26],
				const unsigned int ntetramino, int *x, int *y);
void			clear_start_positions(t_tetramino t[26],
				unsigned int ntetramino, const unsigned int max_tetraminos);
int				put_tetramino_check(char **table, const unsigned int size,
				const int x, const int y);

#endif
