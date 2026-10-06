#include "libft.h"
#include "test.h"
#include <stddef.h>

int main(void)
{
	func_name("ft_strrchr");
    char str[] = "Help";
    char al_l[] = "lllll";
    char empty[] = "";
    check("one letter in str", ft_strrchr(str, 'l') == str + 2, 1);
    check("all letter l in str", ft_strrchr(al_l, 'l') == al_l + 4, 1);
    check("\\0", ft_strrchr(str, '\0') == str + 4, 1);
    check("letter not in str", ft_strrchr(str, 'x') == NULL, 1);
    check("empty str", ft_strrchr(empty, '\0') == empty, 1);
    return (test_result());
}