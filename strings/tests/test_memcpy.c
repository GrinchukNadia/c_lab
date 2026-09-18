#include "strings.h"
#include "test.h"

int main(void)
{
    unsigned char data_1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    unsigned char data_2[4];
    unsigned char data_3[] = {0, 0, 0, 0, 0, 0};
    unsigned char data_4[] = {6, 7, 8, 9};
    unsigned char data_5[8];
    void *a = ft_memcpy(data_2, data_1, 4);
    check("returns adress", a == data_2, 1);
    check("first el copied", data_1[0] == data_2[0], 1);
    check("last el copied", data_1[3] == data_2[3], 1);
    ft_memcpy(data_3, data_1, 3);
    check("last copied byte", data_1[2] == data_3[2], 1);
    check("byte after n unchanged", data_3[3] == 0, 1);
    void *b = ft_memcpy(data_4, data_1, 0);
    check("n == 0, arr first unchanged", data_4[0] == 6, 1);
    check("n == 0, arr last unchanged", data_4[3] == 9, 1);
    check("unchanged arr returns adress", b == data_4, 1);
    ft_memcpy(data_4, data_1, 1);
    check("n = 1, first changed", data_4[0] == data_1[0], 1);
    check("n = 1, second unchanged", data_4[1] == 7, 1);
    ft_memcpy(data_5, data_1, sizeof(data_5));
    size_t i = 0;
    int y = 0;
    while(i < sizeof(data_5))
    {
        if(data_1[i] != data_5[i])
            y++;
        i++;
    }
    check("all elements are coppied", y == 0, 1);
    return (test_result());
}