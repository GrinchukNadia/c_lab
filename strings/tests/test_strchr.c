#include "strings.h"
#include "test.h"
#include <stddef.h>

int main(void)
{
    char str[] = "Hello";
    char empty[] = "";
    check("letter in str", ft_strchr(str, 'l') == str + 2, 1);
    check("\\0", ft_strchr(str, '\0') == str + 5, 1);
    check("letter not in str", ft_strchr(str, 'x') == NULL, 1);
    check("empty str", ft_strchr(empty, '\0') == empty, 1);
    return (0);
}