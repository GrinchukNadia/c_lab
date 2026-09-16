#include "strings.h"
#include "test.h"


int main(void)
{
    char s1[] = {(char)0201, '\0'};
    check("equal", ft_strncmp("hello", "hello", 5), 0);
    check("less", ft_strncmp("abc", "abd", 3) < 0, 1);
    check("greater", ft_strncmp("abd", "abc", 3) > 0, 1);
    check("diff after n", ft_strncmp("hello", "help", 3), 0);
    check("diff before n", ft_strncmp("hello", "help", 4) < 0, 1);
    check("s1 longer", ft_strncmp("abcd", "abc", 4) > 0, 1);
    check("s2 longer", ft_strncmp("abc", "abcd", 4) < 0, 1);
    check("n == 0", ft_strncmp("abc", "xbn", 0), 0);
    check("unsigned char", ft_strncmp(s1, "a", 1) > 0, 1);
    return(0);
}