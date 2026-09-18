#include "strings.h"
#include "test.h"
#include <stdio.h>

int main(void)
{
    check("\"Hello\"", ft_strlen("Hello"), 5);
    check("spaces + h", ft_strlen("   h"), 4);
    check("empty \"\"", ft_strlen(""), 0);
    check("one char", ft_strlen("a"), 1);
    check("only spaces", ft_strlen("       "), 7);
    check("special chars", ft_strlen("\n\t"), 2);
    return (test_result());
}