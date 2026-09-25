//Views an int's memory byte by byte using an unsigned char pointer.
//Prints the decimal value of each byte.
#include <stdio.h>
#include "strings.h"
#include <stdlib.h>

int main()
{
    char *w1;
	w1 = ft_strjoin("Hello ", "world");
    printf("%s", w1);

    free(w1);
    return(0);
}