#include "strings.h"
#include "test.h"

int main(void)
{
    char big[] = "Hello world, hello you";
    char little[] = "world";
    char *p;
    p = ft_strnstr(big, little, 5);
    check("match is not found", p == NULL, 1);
    p = ft_strnstr(big, little, 11);
    check("return adress", p == &big[6], 1);
    p = ft_strnstr(big, little, 0);
    check("len == 0", p == NULL, 1);
    p = ft_strnstr(big, little, 8);
    check("little bigger than len", p == NULL, 1);

    char little_1[] = "";
    p = ft_strnstr(big, little_1, sizeof(big));
    check("retun big, little is empty", p == &big[0], 1);

    char big_1[] = "hello bbig";
    char little_2[] = "big";
    p = ft_strnstr(big_1, little_2, sizeof(big_1));
    check("word after the same letter", p == &big_1[7], 1);

    char big_2[] = "big_little";
    char little_3[] = "big_little";
    p = ft_strnstr(big_2, little_3, sizeof(big_2));
    check("little == big", p == &big_2[0], 1);

    char big_3[] = "little big little big";
    char little_4[] = "big";
    p = ft_strnstr(big_3, little_4, sizeof(big_3));
    check("returns first match", p == &big_3[7], 1);

    char big_4[] = "little bin little big";
    p = ft_strnstr(big_4, little_4, sizeof(big_4));
    check("find match after partial match", p == &big_4[18], 1);

    char big_5[] = "";
    p = ft_strnstr(big_5, little_4, 4);
    check("big is empty", p == NULL, 1);

    char big_6[] = "Hello";
    char little_5[] = "ll";
    p = ft_strnstr(big_6, little_5, 100);
    check("len is bigger than big size", p == &big_6[2], 1);

    char little_6[] = "";
    p = ft_strnstr(big_6, little_6, 0);
    check("string empty, len == 0", p == big_6, 1);
    return (test_result());
}