#include "libft.h"
#include "test.h"

static int used = 0;
static void del(void *c)
{
    used = 1;
    (void)c;
}

int main(void)
{
	func_name("ft_lstclear");
    t_list *head;
    t_list *next;
    t_list *next1;
    t_list *copy;

    head = ft_lstnew("head");
    next = ft_lstnew("next");
    next1 = ft_lstnew("next1");

    ft_lstadd_back(&head, next);
    ft_lstadd_back(&head, next1);
    ft_lstclear()

    return(test_result());
}