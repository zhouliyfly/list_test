#ifndef _MY_LIST_H_
#define _MY_LIST_H_

typedef struct node {
    int data;
    struct node* next;
} Node;

extern struct node* head_init();
extern int node_add(struct node* head, int data);
extern int node_del(struct node* head, int data);
extern int node_insert_after(struct node* head, int data, int newdata);
extern int node_reverse(struct node** head);
extern void printf_list(struct node* head);

extern int node_reverse_by_test(struct node** head);
extern void Remove_head(struct node** head);
extern struct node* search_mid_node(struct node* head);
#endif
