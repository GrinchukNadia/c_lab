#include "strings.h"
#include "test.h"
#include <stddef.h>

int main(void)
{
    unsigned char data[] = {10, 20, 0, 30, 40};
    unsigned char str[] = "hello world";
    unsigned char u_data[] = {10, 200, 0, 40, 50};

    check("data pos in range", ft_memchr(data, 20, 2) == data + 1, 1);
    check("data pos after 0", ft_memchr(data, 30, 5) == data + 3, 1);
    check("data pos not in range", ft_memchr(data, 30, 2) == NULL, 1);
    check("data zero byte", ft_memchr(data, 10, 0) == NULL, 1);
    check("data unsigned char", ft_memchr(u_data, 456, 3) == u_data + 1, 1);
    check("str pos in range", ft_memchr(str, 'l', 5) == str + 2, 1);
    check("str pos not in range", ft_memchr(str, 'o', 2) == NULL, 1);
    check("str find \\0", ft_memchr(str, '\0', 12) == str + 11, 1);
    return (0);
}