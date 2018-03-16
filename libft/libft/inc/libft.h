/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:31:58 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/06 23:01:24 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

# define MIN(a, b) ((a < b) ? a : b)
# define MAX(a, b) ((a > b) ? a : b)
# define ABS(a) ((a < 0) ? a * -1 : a)
# define UNSI unsigned int
# define UNSL unsigned long
# define WCHAR_SIZE sizeof(wchar_t)

int					ft_atoi(char const *str);
void				ft_bzero(void *s, size_t n);
size_t				ft_charcount(const char *s, int c);
int					ft_digitcount(uintmax_t n);
int					ft_digitcount_base(uintmax_t n, unsigned int base);
void				ft_free_2d_array(void ***array, size_t size);
int					ft_gcd(int x, int y);
int					ft_findopt(int argc, char **argv, char flag,
								char **optvalue);
int					ft_findopt_long(int argc, char **argv, char *label,
								char **optvalue);
int					ft_multiple_gcd(size_t size, int *tab);
char				*ft_intmaxtoa(intmax_t n);
char				*ft_intmaxtoa_base(intmax_t n, unsigned int base);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, unsigned int base);
int					ft_isupper(int c);
t_list				*ft_lst_itemcpy(t_list *item);
t_list				*ft_lst_swap(t_list **lst_start, int fi, int si);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstdup(t_list *item);
void				ft_lstiter(t_list *lst, void (*f)(t_list *));
size_t				ft_lstlen(t_list *item);
void				ft_lst_remove_if(t_list **begin_list, void *data_ref,
									int (*cmp)(void *, void*));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_ltoa(long n);
char				*ft_ltoa_base(long n, unsigned int base);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(long long n, unsigned int base);
void				*ft_memalloc(size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
void				*ft_memccpy(void *dds, void const *src, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, void const *src, size_t n);
void				*ft_memrealloc(void *src, size_t size, size_t old_size);
void				*ft_memset(void *b, int c, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_padnumstr(const char *s, int pad_by);
unsigned long		ft_pow(unsigned long base, unsigned long power);
unsigned long		ft_pow_mod(unsigned long x, unsigned long y,
								unsigned long n);
void				ft_printmemory(const void *addr, size_t size);
char				*ft_prompt(const char *prompt);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_reverse_bytes(void *mem, size_t size);
char				*ft_strcat(char *s1, char const *s2);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strchr(char const *s, int c);
char				*ft_strcpy(char *dst, char const *src);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2, int option);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char const *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(char const *big, char const *lit, size_t len);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
size_t				ft_strlen(char const *s);
int					ft_strncmp(char const *s1, char const*s2, size_t n);
char				*ft_strncpy(char *dst, char const *src, size_t len);
char				*ft_strrchr(char const *s, int c);
void				ft_strreplace(char *s, int old, int new);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char const *big, char const *little);
char				*ft_strsub(char const *s1, unsigned int start, size_t len);
char				*ft_strtolow(char *s);
char				*ft_strtoup(char *s);
char				*ft_strtrim(char const *s);
void				ft_swap(int *a, int *b);
char				*ft_uitoa(unsigned int n);
char				*ft_uitoa_base(unsigned int n, unsigned int base);
char				*ft_uintmaxtoa(uintmax_t n);
char				*ft_uintmaxtoa_base(uintmax_t n, unsigned int base);
char				*ft_ultoa(unsigned long n);
char				*ft_ultoa_base(unsigned long n, unsigned int base);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ulltoa_base(unsigned long long n, unsigned int base);
size_t				ft_wstrlen(const wchar_t *s);
char				*ft_xstring(unsigned char c, size_t times);

#endif
