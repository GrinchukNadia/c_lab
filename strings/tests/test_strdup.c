#include "test.h"
#include "strings.h"
#include <stdlib.h>

int main(void)
{
    char str[] = "Hello";
    char *copy = ft_strdup(str);
    char str_empty[] = "";
    char *copy_empty = ft_strdup(str_empty);
    check_str("same content", copy, str);
    check_str("empty string", copy_empty, str_empty);
    check("different memory", copy != str, 1);
    check("empty different memory", copy_empty != str_empty, 1);
    check("empty not NULL", copy_empty != NULL, 1);
    free(copy);
    free(copy_empty);
    return (0);
}