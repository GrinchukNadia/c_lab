#include "strings.h"
#include "test.h"

int main(void)
{
	unsigned char data_1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	unsigned char data_2[4];
    unsigned char data_3[] = {0, 0, 0, 0, 0, 0};
	unsigned char data_4[] = {6, 7, 8, 9};
    unsigned char data_5[8];
	void *a = ft_memmove(data_2, data_1, 4);
    check("returns address", a == data_2, 1);
	check("first el copied", data_1[0] == data_2[0], 1);
    check("last el copied", data_1[3] == data_2[3], 1);
	ft_memmove(data_3, data_1, 3);
    check("last copied byte", data_1[2] == data_3[2], 1);
    check("byte after n unchanged", data_3[3] == 0, 1);
	void *b = ft_memmove(data_4, data_1, 0);
    check("n == 0, arr first unchanged", data_4[0] == 6, 1);
    check("n == 0, arr last unchanged", data_4[3] == 9, 1);
    check("unchanged arr returns address", b == data_4, 1);
    ft_memmove(data_4, data_1, 1);
    check("n = 1, first changed", data_4[0] == data_1[0], 1);
    check("n = 1, second unchanged", data_4[1] == 7, 1);
    ft_memmove(data_5, data_1, sizeof(data_5));
    size_t i = 0;
    int m = 0;
    while(i < sizeof(data_5))
    {
        if(data_1[i] != data_5[i])
            m++;
        i++;
    }
    check("all elements are coppied", m == 0, 1);

	unsigned char overlap_1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	ft_memmove(overlap_1 + 1, overlap_1, 3);
	check("overlap from second, first el", overlap_1[1] == 1, 1);
	check("overlap from second, last el", overlap_1[3] == 3, 1);
	check("after overlap from second, unchanged", overlap_1[4] == 5, 1);
	unsigned char overlap_2[] = {1, 2, 3, 4, 5, 6, 7, 8};
	ft_memmove(overlap_2, overlap_2 + 1, 3);
	check("overlap from first, first el", overlap_2[0] == 2, 1);
	check("overlap from first, last el", overlap_2[2] == 4, 1);
	check("after overlap from first, unchanged", overlap_2[3] == 4, 1);
    unsigned char overlap_3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ft_memmove(overlap_3 + 1, overlap_3, 7);
    i = 0;
    m = 0;
    if (overlap_3[i] != 1)
        m++;
    i++;
    while(i < sizeof(overlap_3))
    {
        if(overlap_3[i] != i)
            m++;
        i++;
    }
    check("overlap, all elements coppied", m == 0, 1);
    unsigned char overlap_4[] = {10, 20, 30, 40};
    ft_memmove(overlap_4, overlap_4, sizeof(overlap_4));
    m = 0;
    if(overlap_4[0] != 10 || overlap_4[1] != 20 
        || overlap_4[2] != 30 || overlap_4[3] != 40)
        m++;
    check("all overlap, same range, unchanged", m == 0, 1);
	return(test_result());

}