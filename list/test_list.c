#include <stdio.h>
#include "my_list.h"

int main()
{
    struct node* head = head_init();
    int i;

    for(i=0; i<5; i++)
    {
        node_add(head, i);
    }

    printf_list(head);
    node_del(head, 3);
    printf_list(head);
    node_insert_after(head,2,6);
    printf_list(head);
    node_insert_before(&head,0,5);
    printf_list(head);
    node_insert_before(&head,6,8);
    printf_list(head);
    node_reverse(&head);
    printf_list(head);
    node_reverse_by_test(&head);
    printf_list(head);
    
    struct node* p = search_mid_node(head);
    printf("mid=%d\n", p->data);
   /* delete head emlement */
    Remove_head(&head);
    printf_list(head);

    
    for(i=7; i<10; i++)
    {
        node_add(head, i);
    }	
    printf_list(head);
    p = search_mid_node(head);
    printf("mid=%d\n", p->data);
    return 0;
}
