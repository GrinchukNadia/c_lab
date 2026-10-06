#include "libft.h"
#include "test.h"
#include <stdlib.h>

static int used = 0;
static void del(void *c)
{
    used = 1;
    (void)c;
}

int main(void)
{
	func_name("ft_lstdelone");
    t_list *head;
    t_list *next;
    t_list *next1;
    t_list *copy;

    head = ft_lstnew("head");
    next = ft_lstnew("next");
    copy = next;
    next1 = ft_lstnew("next1");

    ft_lstadd_back(&head, next);
    ft_lstadd_back(&head, next1);

    head->next = next1;
    ft_lstdelone(copy, &del);
    check("delete in the middle", head->next == next1, 1);
    check("passed function was used", used, 1);


    t_list  *head_one;
    head_one = ft_lstnew("one element");
    ft_lstdelone(head_one, &del);
    //with valgrind will be visible if there are some leaks 

    ft_lstdelone(NULL, &del);
    check("function called with null linked list, doesn't crash", 1, 1);

    free(head);
    free(next1);
    return (test_result());
}