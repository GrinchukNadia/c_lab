#include "strings.h"
#include "test.h"


int main(void)
{
    unsigned char data_0[] = {10, 20, 0, 30, 40};
    unsigned char data_1[] = {10, 20, 0, 30, 40};
    unsigned char data_2[] = {10, 20, 0, 40, 40};
    unsigned char data_3[] = {50, 60, 70, 80, 90};
    char s1[] = {(char)0201, '\0'};
    check("str diff after n", ft_memcmp("hello", "help", 3), 0);
    check("str diff before n", ft_memcmp("hello", "help", 4) < 0, 1);
    check("str n == 0", ft_memcmp("abc", "xbn", 0), 0);
    check("str unsigned char", ft_memcmp(s1, "a", 1) > 0, 1);
    
    check("data equal", ft_memcmp(data_0, data_1, 5), 0);
    check("data diff after n", ft_memcmp(data_2, data_0, 3), 0);
    check("data diff before n", ft_memcmp(data_0, data_2, 4) < 0, 1);
    check("data return positive", ft_memcmp(data_3, data_0, 4) > 0, 1);
    check("data n == 0", ft_memcmp( data_0,  data_3, 0), 0);
    return (test_result());
}