#include "strings.h"
#include "test.h"

int main(void)
{
    unsigned char data_5[5];
    unsigned char data_6[] = {1, 2, 3, 4, 5, 6};
    unsigned char data[] = {1, 2, 3, 4};
    check("returns adress", ft_memset(data_5, 0, 5) == data_5, 1);
    check("first data == 0", data_5[0] == 0, 1);
    check("last data == 0", data_5[4] == 0, 1);
    ft_memset(data_6, 0, 3);
    check("fill half data last el", data_6[2] == 0, 1);
    check("fill half data out of range", data_6[3] == 4, 1);
    ft_memset(data, 0, 0);
    check("first el in arr, n == 0", data[0] == 1, 1);
    check("last el in arr, n == 0", data[3] == 4, 1);
    ft_memset(data, 456, 2);
    check("first el, c > 255", data[0] == 200, 1);
    check("last el, c > 255", data[1] == 200, 1);
    return (test_result());
}