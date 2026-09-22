#include "strings.h"
#include "test.h"
#include <limits.h>

int	main(void)
{
	check("positive nmbr", ft_atoi("42"), 42);
	check("negative nmbr", ft_atoi("-42"), -42);
	check("zero", ft_atoi("0"), 0);
	check("negative zero", ft_atoi("-0"), 0);
	check("empty string", ft_atoi(""), 0);
	check("only spaces", ft_atoi("    "), 0);
	check("only +", ft_atoi("+"), 0);
	check("only -", ft_atoi("-"), 0);
	check("+ then letters", ft_atoi("+hello"), 0);
	check("- then letters", ft_atoi("-hello"), 0);
	check("plus sign", ft_atoi("+42"), 42);
	check("letters after nmbr", ft_atoi("42tech24"), 42);
	check("letters before nmbr", ft_atoi("hi azAZ 42 learners"), 0);
	check("whitespace chars", ft_atoi(" \t\n\v\f\r42"), 42);
	check("whitespace chars & 0", ft_atoi(" \t\n\v\f\r0"), 0);
	check("whitespace chars & +", ft_atoi(" \t\n\v\f\r+42"), 42);
	check("whitespace chars & -", ft_atoi(" \t\n\v\f\r-42"), -42);
	check("++nmbr", ft_atoi("++42"), 0);
	check("--nmbr", ft_atoi("--42"), 0);
	check("+-nmbr", ft_atoi("+-42"), 0);
	check("-+nmbr", ft_atoi("-+42"), 0);
	check(" +nmbr", ft_atoi(" +42"), 42);
	check(" -nmbr", ft_atoi(" -42"), -42);
	check("- after nmbr", ft_atoi("42-24"), 42);
	check("space after nmbr", ft_atoi("42 24"), 42);
	check("+ after nmbr", ft_atoi("42+24"), 42);
	check("whitespace after nmbr", ft_atoi("42 \t\n\v\f\r24"), 42);
	check("0 before nmbr", ft_atoi("0042"), 42);
	check("-0 before nmbr", ft_atoi("-0042"), -42);
	check("+0 before nmbr", ft_atoi("+0042"), 42);
	check("INT_MAX", ft_atoi("2147483647"), INT_MAX);
	check("INT_MIN", ft_atoi("-2147483648"), INT_MIN);

	check("zero then letters", ft_atoi("0abc"), 0);
	check("zeros then letters", ft_atoi("000abc"), 0);
	check("zero then digits after space", ft_atoi("0 42"), 0);
	check("zeros then digits after space", ft_atoi("000 42"), 0);
	check("zero then plus", ft_atoi("0+42"), 0);
	check("zero then minus", ft_atoi("0-42"), 0);
	check("spaces after plus", ft_atoi("+ 42"), 0);
	check("spaces after minus", ft_atoi("- 42"), 0);
	check("space after leading zeros", ft_atoi("000 123"), 0);
	return(test_result());
}