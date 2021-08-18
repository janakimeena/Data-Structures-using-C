/*
* Linked list implementation in C++
* M Janaki Meena
* 16-8-2021
*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
class llist
{
    node* head;
    public:
    llist();
    bool IsEmpty();
    bool InsertBeg(int);
    bool InsertEnd(int);
    void PrintList();
};
node* CreateNode(int data)
{
    node* new_node;
    new_node = new node;
    if(new_node==NULL)
    return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
llist::llist()
{
   head = NULL;
}
bool llist::IsEmpty()
{
    if(!head)
    return true;
    return false;
}
bool llist::InsertBeg(int data)
{
    node* new_node;
    new_node = CreateNode(data);
    if(new_node==NULL)
    return false;
    new_node->next = head;
    head = new_node;
    return true;
}
bool llist::InsertEnd(int data)
{
    node *temp, *new_node;
    if(IsEmpty())
    return InsertBeg(data);
    new_node = CreateNode(data);
    if(new_node==NULL)
    return false;
    temp = head;
    while(temp->next!=NULL)
    temp = temp->next;
    temp->next = new_node;
    return true;
}
void llist::PrintList()
{
    node* temp;
    temp = head;
    cout<<"List is printed"<<endl;
    while(temp)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
int main()
{
    llist l;
    cout<<"Isempty returned "<<l.IsEmpty()<<endl;
    //l.InsertBeg(1);
    //l.InsertBeg(2);
    l.InsertEnd(5);
    l.PrintList();

}