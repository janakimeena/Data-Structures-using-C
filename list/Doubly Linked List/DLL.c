#include "DLL.h"
#include<stdio.h>
int DELETE_ERROR_FLAG = 0;
int RETRIEVE_ERROR_FLAG = 0;
node* CreateNode(int data)
{
   node* new_node;
   new_node = (node*) malloc(sizeof(node));
   if (new_node==NULL)
    return NULL;
   new_node->data = data;
   new_node->prev = NULL;
   new_node->next = NULL;
   return new_node;
}
void CreateList(dllist* l)
{
    l->head = NULL;
    l->tail = NULL;
}
int IsEmpty(dllist l)
{
    if( (l.head==NULL)  && (l.tail==NULL))
        return 1;
    return 0;
}
int InsertBeg(dllist* l,int data)
{
    node* new_node;
    // Step 1: Call createnode function and get address returned in new_node
    new_node = CreateNode(data);
    // Step 2: If new_node is Null is returned return false
    if (new_node==NULL)
        return 0;
    // Step 3: If list is empty then make both head and tail to point to new_node
    if(IsEmpty(*l))
    {
        l->head = new_node;
        l->tail = new_node;
        return 1;
    }

    // Step 4: Make next part of new_node to store head
    new_node->next = l->head;
    // Step 5: Make prev part of head to point to new_node
    l->head->prev = new_node;
    l->head = new_node;
    // Step 6: return true
    return true;

}
int InsertPos(dllist* l,int pos,int data)
{
    node *new_node,*temp;
    int counter=0;
    // Step 1: If pos =1 then Call InsertBeg and return
    if (pos==1)
        return InsertBeg(l,data);
    // Step 2: Call createnode function and get address returned in new_node
    new_node = CreateNode(data);
    // Step 3: If new_node is Null then return false
    if(new_node==NULL)
        return false;
    // Step 4: Let temp = head, counter =1
    temp = l->head; counter = 1;
    // Step 5: While temp is not tail repeat Step 6 and 7
    while(temp!=l->tail)
    {
    // Step 6: If counter = pos -1 then break
        if(counter==pos-1)
            break;
    // Step 7: Increment counter and move temp to next node
        counter++;
        temp=temp->next;
    }
    if(counter==pos-1)
    {
    // Step 8: If counter = pos-1 do step 9 to 14
    // Step 9: If temp==tail then return InsertEnd
    if (temp==l->tail)
        return InsertEnd(l,data);
    // Step 10: Next part of new_node = next part of temp
    new_node->next = temp->next;
    // Step 11: Prev part of new_node is temp
    new_node->prev = temp;
    // Step 12: Previous part of next node of temp is new_node
    temp->next->prev = new_node;
    // Step 13: Next part of temp = new_node
    temp->next = new_node;
    
    // Step 14: Return true
    return true;
    }
    // Step 15: Return false
    return false;



}
int InsertEnd(dllist* l,int data)
{
    node* new_node;
    // Step 1: Call createnode function and get address returned in new_node
    new_node = CreateNode(data);
    // Step 2: If new_node is Null is returned return false
    if (new_node==NULL)
        return 0;
    // Step 3: If list is empty then Call Insert beginning and return
    if (IsEmpty(*l))
        return InsertBeg(l,data);
    // Step 4: Make next part of tail to have address of new_node
    l->tail->next = new_node;
    // Step 5: Make prev part of new_node to contain tail
    new_node->prev = l->tail;
    // Step 6: Make new_node as tail
    l->tail = new_node;
    return 1;
}
int IsSingleNode(dllist l)
{
    // return true if head==tail and false otherwise
    return (l.head==l.tail);
}
int DeleteBeg(dllist* l)
{
    node *temp;
    int d;
    DELETE_ERROR_FLAG = 0;
    // Step 1: If list is empty indicate failure and return -1
    if(IsEmpty(*l))
    {
        DELETE_ERROR_FLAG = 1;
        return -1;
    }
    // Step 2: Let data = data part of head
    d = l->head->data;
    if(IsSingleNode(*l))
    {
    // Step 3: If there is only one in the list (i.e.) if head == tail then 
    //	  (i) Free memory pointed by head
        free(l->head);
	//    (ii) Make head and tail as NULL
        l->head=l->tail=NULL;
	//    (iii) return data
        return d;
    }
    // Step 4: Make temp to point to head 
    temp = l->head;
    // Step 5: Move head to next node
    l->head = l->head->next;
    // Step 6: Free piece of memory pointed by temp
    free(temp);
    // Step 7: Return data
    return d;
}
int DeleteEnd(dllist *l)
{
    node *temp;
    int d;
    DELETE_ERROR_FLAG = 0;
    // Step 1: If list is empty or there is only one in the list return after calling Delete Beginning
    if(IsEmpty(*l)||(IsSingleNode(*l)))
    {
        return DeleteBeg(l);
    }
    temp = l->tail;
    // Step 2: Make temp to point to tail
    // Step 3: Move tail to previous node
    l->tail = l->tail->prev;
    l->tail->next = NULL;
    d = temp->data;
    // Step 4: Free memory pointed by tail
    free(temp);
    // Step 5: Return data
    return d;
}
int DeletePos(dllist *l,int pos)
{
    node* temp,*temp1;
    int counter,d;
    DELETE_ERROR_FLAG=0;
    // Step 1: If list is empty or pos =1 then Call DeleteBeg and return
    if(IsEmpty(*l)||(pos==1))
    {
        return DeleteBeg(l);
    }
    // Step 2: Let temp = head, counter =1
    temp = l->head; counter = 1;
    while(counter<pos-1)
    {
    // Step 3: While counter < pos-1 and temp is not in last node repeat Step 4
    if(temp==l->tail)
        break;
    temp=temp->next;
    counter++;
    // Step 4: Increment counter and move temp to next node
    }
    // Step 5: If counter = pos-1 do step 8 to 12
    if(counter==pos-1)
    {
    // Step 6: Let temp1  be next node of temp (i.e.) node to be deleted
    temp1=temp->next;
    // Step 7: If temp1 is NULL communicate failure and return -1
    if(!temp1)
    {
        DELETE_ERROR_FLAG = 1;
        return -1;
    }
    // If node to be delted is last node, call DeleteEnd
    if(temp1==l->tail)
        return DeleteEnd(l);
    // Step 8: Make next part of temp = next part of temp1
    temp->next = temp1->next;

    // Step 9: Make prev part next node of temp1 as previous part of temp
    temp1->next->prev = temp->prev;
    d = temp1->data;
    free(temp1);
    return d;
    }
    DELETE_ERROR_FLAG = 1;
    return -1;
}
int Locate(dllist l, int ele)
{
    node* temp;
    int pos;
    if(IsEmpty(l))
    {
    // Step 1: If list is empty then communicate failure and return -1
    return -1;
    }
    temp = l.head;
    pos=1;
    // Step 2: Declare a temporary pointer, temp and integer counter
    // Step 3: Initialize temp to point to first node and counter to 1
    while(temp!=NULL)
    {
    // Step 4: While temp not equal to null repeat Step 5 and Step 6
    // Step 5: If data part of node pointed by temp is equal to Element return counter 
    if(temp->data==ele)
        return pos;
    // Step 6: Move temp to next node and increment counter
    temp = temp->next;
    pos++;
    }
    return -1;
    // Step 8: return -1

}
int Retrieve(dllist l, int pos)
{
    node* temp;
    int counter;
    RETRIEVE_ERROR_FLAG = 0;
    // Step 1: If list is empty then communicate failure and return -1
    if(IsEmpty(l))
    {
        RETRIEVE_ERROR_FLAG = 1;
        return -1;
    }
    // Step 2: Declare a temporary pointer, temp and integer counter
    
    // Step 3: Initialize temp to point to first node and counter to 1
    temp = l.head;counter=1;
    // Step 4: While counter<position repeat Step 5 and Step 6
    while(counter<pos)
    {
    // Step 5: If temp is tail then break
    if(temp==l.tail)
    {
        break;
    }
    temp=temp->next;
    counter++;
    }
    // Step 6: Move temp to next node and increment counter
    // Step 7: If pos == counter then return data part of temp and communicate failure otherwise
    if(pos==counter)
        return temp->data;
    RETRIEVE_ERROR_FLAG = 1;
    return -1;

}
void PrintList(dllist l)
{
    node* temp;
    // Step 1: If list is empty return
    if(IsEmpty(l))
        return;
    // Step 2: Declare a temporary pointer, temp and make it to point to head
    temp = l.head;
    // Step 3: While temp is not NULL repeat step 4 and 5
    while(temp)
    {
    // Step 4: Print data part of temp
        printf("%d\n",temp->data);
    // Step 5: Move temp to next node
        temp = temp->next;
    }

}






























/*int delete_error_flag = 0;
int retrieve_error_flag = 0;
int previous_error_flag = 0;
int next_error_flag = 0;

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
*/