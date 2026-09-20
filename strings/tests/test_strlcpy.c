#include "strings.h"
#include "test.h"
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    char str[] = "hello";
    char dest[] = "world";

    size_t s = ft_strlcpy(dest, str, 3);

    check("returns size of src", s == 5, 1);
    check_str("checks normal copy", dest, "he");

    char dest_1[6];
    ft_strlcpy(dest_1, str, 6);
    check_str("full src copy", dest_1, "hello");
    
    ft_strlcpy(dest_1, str, 1);
    check_str("n = 1, empty string", dest_1, "");

    char dest_2[] = "world";
    ft_strlcpy(dest_2, str, 0);
    check_str("unchanged result, n = 0", dest_2, "world");

    char str_1[] = "";
    char dest_3[] = "world";
    s = ft_strlcpy(dest_3, str_1, sizeof(dest_3));
    check("empty src returns 0", s == 0, 1);
    check_str("empty src", dest_3, "");

    char dest_4[] = "apple";
    ft_strlcpy(dest_4, str_1, 0);
    check_str("empty src and empty n", dest_4, "apple");

    char str_2[] = "hi";
    char dest_5[100];
    ft_strlcpy(dest_5, str_2, 100);
    check_str("n > than src length", dest_5, "hi");

    return (test_result());
}