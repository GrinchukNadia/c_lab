#ifndef STRINGS_H
# define STRINGS_H
# include <stddef.h>

int     ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int     ft_strlen(char *str);
char    *ft_strdup(char *src);
int     ft_strncmp(char *s1, char *s2, size_t n);
char    *ft_strchr(char *str, int c);
char    *ft_strrchr(char *str, int c);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
void    *ft_memset(void *s, int c, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
size_t  ft_strlcpy(char *dst, const char *restrict src, size_t dsize);
size_t  ft_strlcat(char *dst, const char *restrict src, size_t dsize);
char    *ft_strnstr(const char *big, const char *little, size_t len);
int     ft_atoi(const char *nptr);
void	*ft_calloc(size_t count, size_t size);

#endif
