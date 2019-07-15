/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:24:11 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int			ft_word_counter(char const *s, char c)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if ((i == 0 && *(s + i) != c)
			|| (*(s + i + 1) && *(s + i + 1) != c && *(s + i) == c))
			count++;
		i++;
	}
	return (count);
}

static void			ft_splitcore(char const *s, char c, char **astr, int nword)
{
	int				wordsize;
	int				i;
	int				j;

	i = 0;
	j = -1;
	while (++j < nword)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			wordsize = 0;
			while (s[i + wordsize] && s[i + wordsize] != c)
				wordsize++;
			if (wordsize <= 0 || !(astr[j] = ft_strnew((size_t)wordsize)))
			{
				ft_astr_del(astr);
				break ;
			}
			wordsize = 0;
			while (s[i] && s[i] != c)
				astr[j][wordsize++] = s[i++];
		}
	}
}

char				**ft_strsplit(char const *s, char c)
{
	char			**astr;
	int				nword;

	astr = NULL;
	if (s)
	{
		nword = ft_word_counter(s, c);
		if ((astr = (char **)malloc(sizeof(char *) * (nword + 1))))
		{
			astr[nword] = NULL;
			if (nword > 0)
				ft_splitcore(s, c, astr, nword);
		}
	}
	return (astr);
}
