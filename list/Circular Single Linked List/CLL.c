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
int DeleteBeg(cllist *l)
{
    node *temp,*temp1;
    int data;
    delete_error_flag = 0;
    if(IsEmpty(*l))
    {
        delete_error_flag = 1;
        return -1;
    }
    data = l->head->data;
    if(l->head->next==l->head)
    {
        free (l->head);
        l->head = NULL;
        return data;
    }
    temp = l->head;
    while(temp->next!=l->head)
        temp = temp->next;
    temp->next = l->head->next;
    temp1 = l->head;
    l->head = l->head->next;
    free(temp1);
    return data;
}
int IsSingleNode(cllist *l)
{
    return(l->head->next==l->head);
}
int DeleteEnd(cllist* l)
{
    node *temp,*temp1;
    int d;
    // Step 1: If list is empty or there is only one in the list 
    // return after calling Insert Beginning
    if(IsEmpty(*l)||IsSingleNode(l))
    {
        return DeleteBeg(l);
    }
    // Step 2: Make temp to point to head
    temp = l->head;
    // Step 3: Move temp to last but one node
    while(temp->next->next!=l->head)
        temp = temp->next;
    // Step 4: Let temp1 hold address of last node
    temp1 = temp->next;
    // Step 5: Make next part of temp as head
    temp->next = l->head;
    // Step 7: Let d= data part of temp1
    d = temp1->data;
    // Step 8: Free piece of memory with address temp1
    free(temp1);
    // Step 9: return d
    return d;
}
int DeletePos(cllist* l,int pos)
{
    node* temp, *temp1;
    int d,counter;
    delete_error_flag = 0;
    if(pos<1)
    {
        delete_error_flag=1;
        return -1;
    }   
    // Step 1: If list is empty or pos =1 then 
    // Call DeleteBeg and return
    if(IsEmpty(*l))
    {
        delete_error_flag=1;
        return -1;
    }
    // Step 2: Let temp = head, counter =1
    temp = l->head;
    counter = 1;
    // Step 3: While counter < pos-1 and temp is not in last node 
    // repeat Step 4
    while((temp->next!=l->head)&&(counter<pos-1))
    // Step 4: Increment counter and move temp to next node
    {
        counter++;
        temp = temp->next;
    }
    // Step 5: If counter = pos-1 do step 8 to 11
    
    // Step 6: Let temp1 = temp->next
    temp1 = temp->next;
    // Step 7: If temp1 is head, communicate failure and return -1
    if(temp1==l->head)
    {
        delete_error_flag=1;
        return -1;
    }
    if(counter==pos-1)
    {
    // Step 8: Make next part of temp = next part of temp1
    temp->next = temp1->next;
    // Step 9: Let d = data part of temp1
    d = temp1->data;
    
    // Step 10: Free memory pointed by temp1
    free(temp1);
    // Step 11: Return d
    return d;
    }
}
int locate(cllist l,int ele)
{
    node* temp;
    int counter;
    // Step 1: If list is empty then communicate failure 
    // and return -1
    if(IsEmpty(l))
        return -1;
    // Step 2: Declare a temporary pointer, temp and integer counter
    // Step 3: Initialize temp to point to first node and 
    // counter to 1
    temp = l.head;
    counter = 1;
    // Step 4: While next part of temp not equal to head repeat 
    // Step 5 and Step 6
    while(temp->next!=l.head)
    {
    // Step 5: If data part of node pointed by temp is equal to 
    // Element return counter 
        if(temp->data == ele)
            return counter;
    // Step 6: Move temp to next node and increment counter
        temp = temp->next;
        counter++;
    }
    // Step 7: If data part of temp is equal to Element 
    if (temp->data==ele)
        return counter;
    // return counter
    // Step 8: return -1
    return -1;

}
int retrieve(cllist l,int pos)
{
    node *temp;
    int counter;
    retrieve_error_flag = 0;
    // Step 1: If list is empty then communicate failure 
    // and return -1
    if(IsEmpty(l))
    {
        retrieve_error_flag=1;
        return -1;
    }
    // Step 2: Declare a temporary pointer, temp and 
    // integer counter
    // Step 3: Initialize temp to point to first node 
    // and counter to 1
    temp = l.head;
    counter = 1;
    // Step 4: While counter<position repeat Step 5 and Step 6
    while(counter<pos)
    {
    // Step 5: If next part of temp is head then break
        if(temp->next==l.head)
        {
            retrieve_error_flag = 1;
            return -1;
        }
    // Step 6: Move temp to next node and increment counter
        temp = temp->next;
        counter++;
    }
    // Step 7: If pos == counter then return data part of temp 
    if(counter==pos)
        return temp->data;
    // and communicate failure otherwise
    retrieve_error_flag = 1;
    return -1;
}
int previous(cllist l,int ele)
{
    node * temp;
    previous_error_flag = 0;
    // Step 1: If list is empty then Indicate failure 
    // to callee function and return -1
    if(IsEmpty(l))
    {
            previous_error_flag = 1;
            return -1;
    }
    // Step 2: Declare a temporary pointer, temp
    // Step 3: Initialize temp to point to first node
    temp = l.head;
    // Step 4: When next part of temp is not head repeat Step 5 
    // and Step 6
    while(temp->next!=l.head)
    {
        if(temp->next->data==ele)
            return temp->data;
    // Step 5: If data in next node of temp is equal 
    // to Element then return data part of temp
    // Step 6: Move temp to next node
        temp = temp->next;
    }
    // Step 7: Indicate failure to callee function and return -1
    previous_error_flag = 1;
    return -1;
}
int next(cllist l, int ele)
{
    node* temp;
    next_error_flag = 0;
    // Step 1: If list is empty then Indicate failure 
    // to callee function and return -1
    if(IsEmpty(l))
    {
        next_error_flag=1;
        return -1;
    }
    // Step 2: Declare a temporary pointer, temp
    // Step 3: Initialize temp to point to first node
    temp = l.head;
    // Step 4: While next part of temp != head (i.e.) 
    // when temp is not in the last node then repeat 
    // Step 5 and Step 6
    while(temp->next!=l.head)
    {
    // Step 5: If data of temp is equal to Element 
    if(temp->data==ele)
        return temp->next->data;
    // then return data part of next node of temp
    // Step 6: Move temp to next node
    temp=temp->next;
    }
    // Step 7: Indicate failure to callee function and return -1
    next_error_flag=1;
    return -1;
}
void DestroyList(cllist *l)
{
    node* temp;
    // Step 1: Initialize temp to head
    temp = l->head;
    // Step 2: Move temp to last node and make 
    // next part of last node as NULL
    while(temp->next!=l->head)
    {
        temp = temp->next;
    }
    temp->next=NULL;
    
    while(l->head->next!=NULL)
    {
    // Step 3: While head->next != NULL repeat steps 4 and 5
    // Step 4: temp = head
    temp = l->head;
    // Step 5: Move head to next node, delete temp
    l->head = l->head->next;
    delete temp;
    }
    temp = l->head;
    // Step 6: Delete temp
    delete temp;
    // Step 7: Make head as NULL
    l->head = NULL;
}
void PrintList(cllist l)
{
    printf("List is printed...\n");
    node* temp = l.head;
    if(IsEmpty(l))
        return;
    while(temp->next!=l.head)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
