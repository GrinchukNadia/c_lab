#include "libft.h"
#include "test.h"
#include <stdlib.h>

void capitalize(void *c)
{
    char    *str;
    str = (char *) c;
    str[0] = ft_toupper(str[0]);   
}

int main(void)
{
    func_name("ft_lstiter");

    t_list  *head;
    t_list  *next;
    t_list  *next1;

    char str0[] = "head";
    char str1[] = "next";
    char str2[] = "next1";

    head = ft_lstnew(str0);
    next = ft_lstnew(str1);
    next1 = ft_lstnew(str2);

    ft_lstadd_back(&head, next);
    ft_lstadd_back(&head, next1);
    ft_lstiter(head, &capitalize);

    check_str("3 el linked list, 1", head->content, "Head");
    check_str("3 el linked list, 2", next->content, "Next");
    check_str("3 el linked list, 3", next1->content, "Next1");

    t_list  *one;
    char    str3[] = "one";

    one = ft_lstnew(str3);
    ft_lstiter(one, &capitalize);
    check_str("only 1 el in linked list", one->content, "One");

    ft_lstiter(NULL, &capitalize);
    check("function called with null linked list, doesn't crash", 1, 1);

    t_list  *two;
    char    str4[] = "two";
    two = ft_lstnew(str4);
    ft_lstiter(two, NULL);
    check("function doesnt exist doesn't crash", 1, 1);

    free(head);
    free(next);
    free(next1);
    free(one);
    free(two);
    return (test_result());

}