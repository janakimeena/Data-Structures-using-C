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
node* CreateNode(int data)
{
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    if (new_node==NULL)
    return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
int InsertBeg(llist* l,int data)
{
    node* new_node;
    new_node = CreateNode(data);
    if(!new_node)
    return 0;
    new_node->next = l->head;
    l->head = new_node;
    return 1;
}
//Insert End 
int InsertEnd(llist* l,int data)
{
    node *temp,*new_node;
    if(IsEmpty(*l))   
    return InsertBeg(l,data);
    temp = l->head;
    new_node = CreateNode(data);
    if (new_node==NULL)
    return 0;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = new_node;
    return 1;
}
void PrintList(llist l)
{
    node* temp;
    temp =l.head;
    printf("List is getting printed\t");
    while(temp)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
int main()
{
    llist l;
    printf("%d returned by isempty\n",IsEmpty(l));
    CreateList(&l);
    printf("%d returned after create\n",IsEmpty(l));
    //InsertBeg(&l,1);
    //InsertBeg(&l,2);
    InsertEnd(&l,5);
    PrintList(l);
}
