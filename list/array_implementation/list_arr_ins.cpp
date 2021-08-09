/*
* Array implementation of list in C++
* Janaki Meena
* 08 - 08 - 2021
*/
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
	for(i=0;i<capacity;i++)
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
int main()
{
	int n;
	cin>>n;
	list l(n);	
	
	cout<<l.IsEmpty()<<endl;
	cout<<l.IsFull()<<endl;
	l.InsertBeg(3);
	l.InsertBeg(2);
	l.InsertBeg(1);
	l.PrintList();
	if(!l.InsertBeg(4))
	cout<<"Insertion failed"<<endl;
}