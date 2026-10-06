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

    head = ft_lstnew("head");
    next = ft_lstnew("next");
    next1 = ft_lstnew("next1");

    ft_lstadd_back(&head, next);
    ft_lstadd_back(&head, next1);
    ft_lstclear(&head, &del);
    check("all linked list is cleard", head == NULL, 1);

    t_list *head0;
    t_list *n_next;
    t_list *n_next1;
    t_list *copy;

    head0 = ft_lstnew("head0");
    copy = head0;
    n_next = ft_lstnew("n_next");
    n_next1 = ft_lstnew("n_next1");

    ft_lstadd_back(&head0, n_next);
    ft_lstadd_back(&head0, n_next1);
    ft_lstclear(&head->next, &del);
    check("second el deleted, head untached", head0 == copy, 1);
    check("second el deleted, next null", head0->next == NULL, 1);


    ft_lstclear(NULL, &del);
    check("function called with null linked list, doesn't crash", 1, 1);

    t_list *null_head = NULL;
    ft_lstclear(&null_head, &del);
    check("*lst is null, doesn't crash", 1, 1);

    return(test_result());
}