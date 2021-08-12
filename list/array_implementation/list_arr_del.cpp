/*
* Array implementation of list in C++
* Janaki Meena
* 08 - 08 - 2021
*/
bool deletion_success=true;
#include<iostream>
using namespace std;
class list
{
	int *elements;
	int capacity;
	int no_of_elements;
	public:
	list();
	list(int c);
	~list();
	
	void PrintList()const;
	bool IsEmpty()const;
	bool IsFull()const;
	bool InsertBeg(int x);
	bool InsertEnd(int x);
	bool InsertPos(int pos, int x);
	int DeleteBeg();
	int DeleteEnd();
};
list::list()
{
	capacity = 10;
	elements = new int[capacity];
	no_of_elements=0;
}
list::list(int c)
{
	capacity=c;
	elements=new int[capacity];
	no_of_elements=0;
}
list::~list()
{
	delete [] elements;
}
void list::PrintList()const
{
	int i;
	for(i=0;i<no_of_elements;i++)
	cout<<elements[i]<<endl;
}
bool list::IsEmpty()const
{
	if(no_of_elements==0)
	return true;
	return false;
}
bool list::IsFull()const
{
	return (capacity==no_of_elements);
}
bool list::InsertBeg(int x)
{
	
	int i;
	if (IsFull())
	return false;
	for(i=no_of_elements-1;i>=0;i--)
	elements[i+1] = elements[i];
	elements[0] = x;
	no_of_elements++;
	return true;
}
bool list::InsertEnd(int x)
{
	if(IsFull())
	return false;
	elements[no_of_elements++] = x;
	return true;
}
bool list::InsertPos(int pos, int x)
{
	int i;	
	if(IsFull()||(pos<1)||(pos>no_of_elements+1))
	return false;
	for(i=no_of_elements-1;i>=pos-1;i--)
	elements[i+1] = elements[i];
	elements[pos-1] = x;
	no_of_elements++;
	return true;
}
int list::DeleteBeg()
{
	int x=0,i;
	deletion_success = true;
	if(IsEmpty())
	{
		deletion_success = false;
		return x;
	}
	x = elements[0];
	for(i=1;i<no_of_elements;i++)
	elements[i-1] = elements[i];
	no_of_elements--;
	return x;
}
int list::DeleteEnd()
{
	int x;
	deletion_success = true;
	if(IsEmpty())
	{
	deletion_success = false;
	return x;
	}
	x = elements[no_of_elements-1];
	no_of_elements--;
	return x;
}
int main()
{
	int n,x;
	cin>>n;
	list l(n);		
	l.InsertBeg(3);
	l.InsertEnd(2);
	l.InsertBeg(1);
	if (!l.InsertPos(5,10))
	cout<<"Insert Position failed\n";	
	if(!l.InsertBeg(4))
	cout<<"Insertion failed"<<endl;
	l.PrintList();
	cout<<"After deletion\n"<<endl;
	x = l.DeleteBeg();
	if(deletion_success)
	cout<<x<<" is deleted\n";
	else
	cout<<"deletion failed\n";
	l.PrintList();
	x = l.DeleteEnd();
	if(deletion_success==true)
	cout<<x<<"is deleted"<<endl;
	else
	cout<<"Deletion failed"<<endl;
	l.InsertBeg(4);
	l.PrintList();
	x = l.DeleteEnd();
	cout<<x<<endl;
	if(deletion_success==true)
	cout<<x<<"is deleted"<<endl;
	else
	cout<<"Deletion failed"<<endl;
}
