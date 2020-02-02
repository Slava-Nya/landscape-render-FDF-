/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:56:21 by hlorrine          #+#    #+#             */
/*   Updated: 2020/02/02 18:19:24 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 300

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "fcntl.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*str;
	int				lst_fd;
}					t_lst;

void				*ft_memset(void *tmp, int val, size_t num);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, void const *str, size_t n);
void				*ft_memccpy(void *dest, void const *source,
					int ch, size_t n);
void				*ft_memmove(void *dest, void const *source, size_t num);
void				*ft_memchr(void const *str, int c, size_t n);
int					ft_memcmp(void const *str1, void const *str2, size_t n);
size_t				ft_strlen(char const *str);
char				*ft_strdup(char const *str);
char				*ft_strcpy(char *dest, char const *str);
char				*ft_strncpy(char *dest, char const *str, size_t n);
char				*ft_strcat(char *dest, char const *src);
char				*ft_strncat(char *dest, char const *str, size_t n);
size_t				ft_strlcat(char *dest, char const *str, size_t n);
char				*ft_strchr(char const *str, int c);
char				*ft_strrchr(char const *str, int c);
char				*ft_strstr(char const *str, char const *find);
char				*ft_strnstr(char const *str, char const *find, size_t n);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					ft_atoi(char const *str);
int					ft_isalpha(int c);
int					ft_isdigit(int ch);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *s));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				**ft_freesher(char **str, int len);
int					ft_wordcount(char const *s, char c);
t_list				*ft_reverselst(t_list *lst);
void				*ft_realloc(void *old, size_t new_len);
int					ft_countalpha(char a);
int					get_next_line(const int fd, char **a);
int					ft_atoi_base(char *str);
void				ft_put_errno(char *str);

#endif
