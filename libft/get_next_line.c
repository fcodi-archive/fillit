/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 08:30:13 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*tfile_new(const int fd, const int flag)
{
	t_file	*tfile;

	if ((tfile = (t_file *)malloc(sizeof(t_file))))
	{
		tfile->fd = fd;
		if (flag == TFILE_HEAD)
			tfile->head = tfile;
		else
			tfile->head = NULL;
		tfile->string = NULL;
		tfile->next = NULL;
	}
	return (tfile);
}

static t_file	*tfile_fd(const int fd, t_file *tfile)
{
	while (tfile && tfile->fd != fd && tfile->next)
		tfile = tfile->next;
	if (tfile && tfile->fd != fd)
	{
		if ((tfile->next = tfile_new(fd, TFILE_NONE)) == NULL)
			return (NULL);
		tfile->next->head = tfile->head;
		tfile = tfile->next;
	}
	return (tfile);
}

static int		cook_next_line(t_file *tfile, char **line, const int fd,
	ssize_t result)
{
	char	*tmp;
	size_t	size;

	size = ft_strlenc(tfile->string, '\n');
	if (tfile->string[size] == '\n')
	{
		*line = ft_strsub(tfile->string, 0, size);
		tmp = ft_strdup(tfile->string + size + 1);
		ft_strdel(&tfile->string);
		tfile->string = tmp;
		if (tfile->string[0] == NUL)
			ft_strdel(&tfile->string);
	}
	else if (tfile->string[size] == NUL)
	{
		if (result == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(tfile->string);
		ft_strdel(&tfile->string);
	}
	return (TRUE);
}

static int		read_next_line(const int fd, char **line, t_file *tfile)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		result;

	while ((result = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[result] = NUL;
		if (tfile->string == NULL && (tfile->string = ft_strnew(0)) == NULL)
			return (ERROR);
		if ((tmp = ft_strjoin(tfile->string, buff)) == NULL)
			return (ERROR);
		ft_strdel(&tfile->string);
		tfile->string = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (result < 0)
		return (ERROR);
	else if (result == 0 && (tfile->string == NULL || tfile->string[0] == NUL))
		return (FALSE);
	return (cook_next_line(tfile, line, fd, result));
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*tfile = NULL;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (ERROR);
	if (tfile)
	{
		if (!(tfile = tfile_fd(fd, tfile->head)))
			return (ERROR);
	}
	else if (!(tfile = tfile_new(fd, TFILE_HEAD)))
		return (ERROR);
	return (read_next_line(fd, line, tfile));
}
