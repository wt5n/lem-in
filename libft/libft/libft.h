/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:08:24 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:38:10 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include "../inc/printf.h"

# define MAXINT 2147483647
# define MININT -2147483648
# define BUFF_SIZE	8
# define FD_SIZE	10240

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
int					ft_atoi_wr(const char *str);
void				ft_bzero(void *buf, size_t count);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int a);
int					ft_isprint(int c);
int					ft_isupper(int a);
char				*ft_itoa(int nbr);
void				ft_lstadd(t_list **start, t_list *link);
void				ft_lstdel(t_list **link, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **link, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src,\
int ch, size_t count);
void				*ft_memchr(const void *buffer, int ch, size_t count);
int					ft_memcmp(const void *buf1, const void *buf2, size_t count);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t count);
void				*ft_memset(void *buf, int ch, size_t count);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnstr(char *str, int n);
void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);
char				*ft_strcat(char *destptr, const char *srcptr);
char				*ft_strchr(const char *str, int ch);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *str1, const char *str2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strncat(char *str1, const char *str2, size_t count);
char				*ft_strnchr(char *s, char c, int n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *destptr, const char *srcptr, size_t num);
char				*ft_strndup(const char *s1, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strnstr(const char *big, const char *little,\
size_t len);
char				*ft_strrchr(const char *string, int symbol);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_error(void);
int					*ft_intcpy(int *str1, int *str2, int n);
void				ft_quicksort(int *str, int p, int q);
char				**ft_strsplit_str(char const *s, int word);
void				ft_swap(int *a, int *b);
int					get_next_line(const int fd, char **line);
int					ft_words(char const *s);
int					ft_nwords(char const *s, char c);
int					mod_n(int a);
int					max_n(int a, int b);
int					min_n(int a, int b);
void				ft_free_two_demention(char **str, int i);

#endif
