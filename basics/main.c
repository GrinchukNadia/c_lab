//Views an int's memory byte by byte using an unsigned char pointer.
//Prints the decimal value of each byte.
#include <stdio.h>
#include "strings.h"

int main()
{
    size_t r;
    r = ft_atoi("42");
    printf("%d", (int)r);
    //printf("%s, %d\n", dest_5, (int) r);
    /*
    int x;
    unsigned char *p;

    x = 16843009;
    p = (unsigned char *)&x;
    p[0] = 3;

    printf("x = %d\n", x);

	printf("byte 0 = %u\n", p[0]);
	printf("byte 1 = %u\n", p[1]);
	printf("byte 2 = %u\n", p[2]);
	printf("byte 3 = %u\n", p[3]);
    */

    return(0);
}