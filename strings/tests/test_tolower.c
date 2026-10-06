#include "libft.h"
#include "test.h"

int main(void)
{
	func_name("ft_tolower");
	check("A to a", ft_tolower('A'), 'a');
	check("Z to z", ft_tolower('Z'), 'z');
	check("M return m", ft_tolower('M'), 'm');
	check("before A", ft_tolower('@'), '@');
	check("after Z", ft_tolower('['), '[');
	check("a return a", ft_tolower('a'), 'a');
	check("z return z", ft_tolower('z'), 'z');
	check("non letter, return without change", ft_tolower('4'), '4');
	return (test_result());
}