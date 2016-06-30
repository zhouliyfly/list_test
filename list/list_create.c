#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"

struct node* head_init()
{
    struct node* head;

    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("error\n");
	exit(-1);
    }

    head->next = head;
    return head;
}

int node_add(struct node* head, int data)
{
    struct node* p = head;
    struct node* p1;
    if(p == NULL)
        return -1;

    if(p->next == p)
    {
        p->data = data;
	p->next = NULL;

	return 0;
    }

    while(p->next != NULL)
    {
        p = p->next;
    }

    p1 = (struct node*)malloc(sizeof(struct node));
    p1->data = data;
    p1->next = NULL;
    p->next = p1;

    return 0;
}

int node_del(struct node* head, int data)
{
    struct node* p1 = head;
    struct node* p2 = head;

    if(p1==NULL)
        return -1;

    while(p1 != NULL && p1->data != data)
    {
        p2 = p1;
	p1 = p1->next;
    }
    if(p1 == NULL)
    {
        printf("not found!\n");
	return 0;
    }

    if(p1->data == data)
    {
        p2->next = p1->next;
	free(p1);
    }

    return 0;
}

int node_insert_after(struct node* head, int data, int newdata)
{
   if(head == NULL)
       return -1;
   struct node* p = head;

   while(p!=NULL && p->data != data)
   {
       p = p->next;
   }
   if(p == NULL)
   {
       printf("data not found!, insert faiure!\n");
   }
   else
   {
       struct node* tmp = (struct node*)malloc(sizeof(struct node));
       tmp->data = newdata;
       tmp->next = p->next;
       p->next = tmp;
   }
   
   return 0;
}

int node_insert_before(struct node** head, int data, int newdata)
{
    if(head == NULL)
        return -1;

    struct node* p1 = *head;
    struct node* p2 = p1;
    
    while((p1 != NULL) && (p1->data != data))
    {
        p2 = p1;
        p1 = p1->next;
    }
    if(p1 == NULL)
    {
        printf("not found, data insert before faiure!\n");
	return -1;
    }
    else
    {
        struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = newdata;
	tmp->next = p1;
	if(p1 == *head)
	{
            *head = tmp;	    
	}
	else
	{
	    p2->next = tmp;
	}
    }

    return 0;
}

int node_reverse(struct node** head)
{
    if((*head == NULL) || ((*head)->next == NULL))
        return 0;
    
    struct node* p1 = *head;
    struct node* p2 = p1->next;

    while(p2 != NULL)
    {
        struct node* p3 = p2->next;
        p2->next = p1;
	p1 = p2;
	p2 = p3;
    }
    (*head)->next = NULL;
    *head = p1;
    
    return 0;
}

int node_reverse_by_test(struct node** head)
{
    struct node* p = *head;
    struct node* p1 = p->next;

    if((p == NULL) || (p->next == NULL))
        return 0;
    
    p = p1->next;
    while(p != NULL)
    {
        node_insert_after(*head, (*head)->data, p->data);
	struct node* tmp = p;
	p = p->next;
	free(tmp);
    }
    p = (*head)->next;
    p1->next = (*head);
    (*head)->next = NULL;
    *head = p;
}

void Remove_head(struct node** head)
{
    if(head == NULL)
        return;
    
    struct node* tmp = *head;
    (*head) = tmp->next;
    free(tmp);

}

/* search middle node */
struct node* search_mid_node(struct node* head)
{
    struct node* p1 = head;
    struct node* p2 = head;

    if(head == NULL)
        return NULL;
    
    struct node* tmp = p1;

    while((p2 != NULL) && (p2->next != NULL))
    {
        tmp = p1;
        p1 = p1->next;
	p2 = p2->next->next;
    }
    if(p2 == NULL)
        return tmp;
    if(p2->next == NULL)
        return p1;
}
void printf_list(struct node* head)
{
   struct node* p1 = head;

   while(p1!=NULL)
   {
       printf("%d ", p1->data);    
       p1 = p1->next;
   }
   printf("\n");
}



