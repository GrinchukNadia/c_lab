#include "libft.h"
#include "test.h"
#include <stddef.h>

int main(void)
{
	func_name("ft_strchr");
    char str[] = "Hello";
    char empty[] = "";
    check("letter in str", ft_strchr(str, 'l') == str + 2, 1);
    check("\\0", ft_strchr(str, '\0') == str + 5, 1);
    check("letter not in str", ft_strchr(str, 'x') == NULL, 1);
    check("empty str", ft_strchr(empty, '\0') == empty, 1);
    check("int to char conversion", ft_strchr(str, 'H' + 256) == str, 1);
    check("\\0, int to char conversion", ft_strchr(str, '\0' + 256) == str + 5, 1);
    return (test_result());
}