#include "strings.h"
#include "test.h"

int main(void)
{
	int i = 0;
	int m = 0;

	while(i <= 127)
	{
		if(!ft_isascii(i))
			m++;
		i++;
	}
	check("is ascii, whole range", m == 0, 1);
	check("below ascii", ft_isascii(-1), 0);
	check("above ascii", ft_isascii(128), 0);
	check("negative", ft_isascii(-42), 0);
	check("above range", ft_isascii(1000), 0);
	return (test_result());
}