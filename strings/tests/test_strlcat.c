#include "strings.h"
#include "test.h"
#include <stdio.h>

int main(void)
{
    char src[] = " world";
    char dest[10] = "Hi";
    size_t r;
    r = ft_strlcat(dest, src, sizeof(dest));
    check("whole copy, return size", r == 8, 1);
    check_str("whole copy", dest, "Hi world");

    char dest_1[7] = "Hi";
    r = ft_strlcat(dest_1, src, sizeof(dest_1));
    check("part copy, return size", r == 8, 1);
    check_str("part copy", dest_1, "Hi wor");

    char dest_2[] = "Hi";
    r = ft_strlcat(dest_2, src, sizeof(dest_2));
    check("no copy, return size", r == 8, 1);
    check_str("no copy", dest_2, "Hi");

    char dest_3[20] = "Hi";
    r = ft_strlcat(dest_3, src, 0);
    check("n = 0, return size", r == 6, 1);
    check_str("n = 0, no copy", dest_3, "Hi");

    char src_1[] = "";
    char dest_4[6] = "Hi";
    r = ft_strlcat(dest_4, src_1, sizeof(dest_4));
    check("empty src, return size", r == 2, 1);
    check_str("empty src", dest_4, "Hi");

    char dest_5[10] = "Hi";
    r = ft_strlcat(dest_5, src, 1);
    check("n = 1, return size", r == 7, 1);
    check_str("n = 1, no copy", dest_5, "Hi");

    char dest_6[10] = "";
    r = ft_strlcat(dest_6, src, sizeof(dest_6));
    check("empty dest, return size", r == 6, 1);
    check_str("empty dest", dest_6, " world");

    char dest_7[9] = "Hi";
    r = ft_strlcat(dest_7, src, sizeof(dest_7));
    check("exact size, return size", r == 8, 1);
    check_str("exact size", dest_7, "Hi world");

    char dest_8[10] = "Hello";
    r = ft_strlcat(dest_8, src, 3);
    check("size smaller than dst, return size", r == 9, 1);
    check_str("size smaller than dst", dest_8, "Hello");
    return (test_result());
}