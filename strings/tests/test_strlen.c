#include "strings.h"
#include "test.h"
#include <stdio.h>

int main(void)
{
    char *a = "Hello";
    char *b = "   h";
    char *c = "";

    check("\"Hello\"", ft_strlen(a), 5);
    check("spaces + h", ft_strlen(b), 4);
    check("empty \"\"", ft_strlen(c), 0);

    return (0);
}