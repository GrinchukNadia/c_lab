#ifndef TEST_H
#define TEST_H
# include <stddef.h>

void    check(const char *name, int actual, int expected);
void    check_str(const char *name, char *actual, char *expected);
void	check_fd(const char *name, int fd, const char *expected, size_t len);
int     test_result(void);

#endif