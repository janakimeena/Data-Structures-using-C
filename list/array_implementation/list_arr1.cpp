/*
* Array implementation of list in C
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
int main()
{
	int n;
	cin>>n;
	list l(n);	
	l.PrintList();
	cout<<l.IsEmpty()<<endl;
	cout<<l.IsFull()<<endl;
}