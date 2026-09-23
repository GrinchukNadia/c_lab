#include "strings.h"
#include "test.h"

int main(void)
{
	check("a to A", ft_toupper('a'), 'A');
	check("z to Z", ft_toupper('z'), 'Z');
	check("before a", ft_toupper('`'), '`');
	check("m return M", ft_toupper('m'), 'M');
	check("after z", ft_toupper('{'), '{');
	check("A return A", ft_toupper('A'), 'A');
	check("Z return Z", ft_toupper('Z'), 'Z');
	check("non letter, return without change", ft_toupper('4'), '4');
	return (test_result());
}