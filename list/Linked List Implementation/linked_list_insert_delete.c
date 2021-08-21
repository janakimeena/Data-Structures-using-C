/*
* Linked list implementation in C
* M Janaki Meena
* 16-8-2021
*/
#include<stdio.h>
#include<stdlib.h>
int delete_error_flag = 0;
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
int Insert_Position(llist* l, int pos, int data)
{
    node *temp,*new_node;
    int counter = 1,chk;
    if (pos==1)
    return InsertBeg(l,data);
    temp = l->head;
    printf("Before loop %p\n",temp);
    while(counter<pos-1)
    {
        temp = temp->next;
        if(temp==NULL)
        return 0;
        
        counter++;
    }
    printf("I am outside\n");
    new_node = CreateNode(data);
    if(new_node==NULL)
    return 0;
    new_node->next = temp->next;
    temp->next = new_node;
    return 1;
}
void PrintList(llist l)
{
    node* temp;
    temp =l.head;
    printf("List is getting printed\n");
    while(temp)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
int DeleteBeg(llist* l)
{
    node* temp;
    int tempint;
    delete_error_flag = 0;
    if(IsEmpty(*l))
    {
        delete_error_flag = 1;
        return -1;
    }
    temp = l->head;
    tempint = l->head->data;
    l->head = l->head->next;
    free(temp);
    return tempint;
}
int main()
{
    llist l;
    int t;
    printf("%d returned by isempty\n",IsEmpty(l));
    CreateList(&l);
    printf("%d returned after create\n",IsEmpty(l));
    InsertBeg(&l,1);
    InsertBeg(&l,2);
    InsertEnd(&l,5);
    Insert_Position(&l,2,10);
    PrintList(l);
    t = DeleteBeg(&l);
    if(delete_error_flag)
    printf("Delettion failed\n");
    else
    printf("Value deleted is %d\n",t);
    PrintList(l);
}
