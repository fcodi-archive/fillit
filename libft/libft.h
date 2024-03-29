/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:18:57 by fcodi             #+#    #+#             */
/*   Updated: 2019/07/06 01:00:45 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# define NUL '\0'
# define ERROR -1
# define TRUE 1
# define FALSE 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memchr(const void *s, int c, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(const char *str);
char			*ft_strtrim(const char *s);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
void			ft_strclr(char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strstr(const char *haystack, const char *needle);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_astrdel(char **astr, size_t nstr);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_putstr(const char *str);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putchar(char c);
unsigned int	ft_strnlen(unsigned int n);
void			ft_putchar_fd(char c, int fd);
void			*ft_memdel(void **ap);
int				ft_strequ(const char *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *string, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcpy(char *dst, const char *src);
int				ft_isupper(int c);
int				ft_islower(int c);
size_t			ft_strlenc(const char *s, char c);
char			**ft_strsplit(char const *s, char c);
int				ft_isdigit(int c);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
size_t			ft_uintlen(unsigned int n);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(const void *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *string);
ssize_t			ft_nsym(const char *string, char c);
size_t			ft_strnchri(const char *string, const char c, const size_t i);
char			**ft_astr_new(const unsigned int size_x,
		const unsigned int size_y);
void			ft_astr_del(char **astr);
void			ft_astr_fill_c(char **astr, const int size, const char c);
void			ft_astr_put(char **astr);

#endif
