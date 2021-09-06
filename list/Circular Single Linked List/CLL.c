#include "CLL.h"
#include<stdio.h>
int delete_error_flag = 0;
int retrieve_error_flag = 0;
int previous_error_flag = 0;
int next_error_flag = 0;

node* CreateNode(int data)
{
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    if(new_node==NULL)
    {
    return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void CreateList(cllist* l)
{
    l->head = NULL;
}
int IsEmpty(cllist l)
{
    if(l.head==NULL)
    return 1;
    return 0;
}
int InsertBeg(cllist* l,int data)
{
    node* new_node,*temp;
    new_node = CreateNode(data);
    if(new_node==NULL)
    {
        return 0;
    }
    if(IsEmpty(*l))
    {
        new_node->next = new_node;
        l->head = new_node;
        return 1;
    }
    new_node->next = l->head;
    temp =l->head;
    while(temp->next!=l->head)
    temp = temp->next;
    temp->next = new_node;
    l->head = new_node;
    return 1;
}
int InsertEnd(cllist* l, int d)
{
    node *temp, *new_node;
    if(IsEmpty(*l))
    {
        return InsertBeg(l,d);
    }
    new_node = CreateNode(d);
    if(!new_node)
    {
        return 0;
    }
    temp = l->head;
    while(temp->next!=l->head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = l->head;
    
    return 1;
}
int Insert_Position(cllist* l, int pos, int data)
{
    
    node *new_node,*temp;
    int counter;
    if(IsEmpty(*l))
        return InsertBeg(l,data);
    new_node = CreateNode(data);
    if (new_node==NULL)
        return 0;
    temp = l->head;
    counter = 1;
    while(temp->next!=l->head)
    {
        if(counter==pos-1)
            break;
        counter++;
        temp = temp->next;        
    }
    if(counter==pos-1)
    {
        
        new_node->next = temp->next;
        temp->next = new_node;
        return 1;
    }
    return 0;
}
void PrintList(cllist l)
{
    printf("List is printed...\n");
    node* temp = l.head;
    while(temp->next!=l.head)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}