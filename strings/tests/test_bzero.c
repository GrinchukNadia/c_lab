#include "strings.h"
#include "test.h"

int main(void)
{
    int i = 0;
    int c = 0;
    unsigned char data[] = {1, 2, 3, 4, 5, 6};
    ft_bzero(data, 0);
    check("none changed", data[0] == 1, 1);
    ft_bzero(data, 4);
    while(i < 4)
    {
        if(data[i] == 0)
            c++;
        i++;
    }
    check("all 0", c == 4, 1);
    check("after n", data[4] == 5, 1);
    check("last el", data[5] == 6, 1);
    return (0);
}