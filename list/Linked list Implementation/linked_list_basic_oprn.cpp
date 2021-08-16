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
};
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
int main()
{
    llist l;
    cout<<"Isempty returned "<<l.IsEmpty()<<endl;
}