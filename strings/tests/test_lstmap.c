#include "libft.h"
#include "test.h"
#include <stdlib.h>

void *capitalize(void *c)
{
    char    *str;
    char    *new;

    str = (char *) c;
    new = ft_strdup(str);
    if  (!new)
        return (NULL);
    new[0] = ft_toupper(str[0]);
    return (new);  
}

void    del(void *c)
{
    free(c);
}

int main(void)
{
    func_name("ft_lstmap");

    t_list  *head;
    t_list  *next;
    t_list  *next1;
    t_list  *new;

    char str0[] = "head";
    char str1[] = "next";
    char str2[] = "next1";

    head = ft_lstnew(str0);
    next = ft_lstnew(str1);
    next1 = ft_lstnew(str2);

    ft_lstadd_back(&head, next);
    ft_lstadd_back(&head, next1);
    new = ft_lstmap(head, &capitalize, &del);
    
    check("1st, new linked list was created", head != new, 1);
    check_str("1st, content was changed", new->content, "Head");
    check_str("1st, old content wasn't changed", head->content, "head");
    check("1st, content adresses are not same", new->content != head->content, 1);
    
    check("2nd, new linked list was created", next != new->next, 1);
    check_str("2nd, content was changed", new->next->content, "Next");
    check_str("2nd, old content wasn't changed", next->content, "next");
    check("2nd, content adresses are not same", new->next->content != next->content, 1);
    
    
    check("3rd, new linked list was created", next1 != new->next->next, 1);
    check_str("3rd, content was changed", new->next->next->content, "Next1");
    check_str("3rd, old content wasn't changed", next1->content, "next1");
    check("3rd, content adresses are not same", new->next->next->content != next1->content, 1);

    check("new linked list, NULL after last", new->next->next->next == NULL, 1);

    t_list  *new1;
    new1 = ft_lstmap(NULL, &capitalize, &del);
    check("function called with null linked list, doesn't crash", new1 == NULL, 1);

    free(head);
    free(next);
    free(next1);
    ft_lstclear(&new, &del);
    return (test_result());
}