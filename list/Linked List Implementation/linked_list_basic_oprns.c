/*
* Linked list implementation in C
* M Janaki Meena
* 16-8-2021
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
typedef struct llist
{
    node* head;
}llist;
void CreateList(llist *l)
{
    l->head = NULL;
}
int IsEmpty(llist l)
{
    if(l.head==NULL)
    return 1;
    return 0;
}


int main()
{
    llist l;
    printf("%d returned by isempty\n",IsEmpty(l));
    CreateList(&l);
    printf("%d returned after create",IsEmpty(l));
}