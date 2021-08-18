/*
* Array implementation of list in C
* Janaki Meena
* 08 - 08 - 2021
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int *elements;
	int no_of_elements;
	int capacity;
}list;
list CreateList(int c)
{
	list l;
	l.capacity = c;
	l.elements = (int*)malloc(sizeof(int)*c);
	l.no_of_elements=0;
	return l;
}
void PrintList(list l)
{
	int i;
	for(i=0;i<l.no_of_elements;i++)
	printf("%d\n",l.elements[i]);
}
void DestroyList(list l)
{
	free(l.elements);
}
int IsEmpty(list l)
{
	if(l.no_of_elements==0)
	return 1;
	return 0;
}
int IsFull(list l)
{
	if (l.capacity==l.no_of_elements)
	return 1;
	return 0;
}
int InsertBeg(list *l,int x)
{
	int i;
	if(IsFull(*l))
	return 0;
	for(i=l->no_of_elements-1;i>=0;i--)
	l->elements[i+1] = l->elements[i];
	l->elements[0] = x;
	l->no_of_elements++;
	return 1;
}
int InsertEnd(list*l, int x)
{
	if(IsFull(*l))
	return 0;
	l->elements[l->no_of_elements++] = x;
	return 1;
}
int InsertPos(list* l, int pos, int x)
{
	int i;
	if((IsFull(*l))||(pos<=0)||(pos>l->no_of_elements+1))
	return 0;
	for(i=l->no_of_elements-1;i>=pos-1;i--)
	{
		l->elements[i+1] = l->elements[i];
	}
	l->elements[pos-1] = x;
	l->no_of_elements++;
	return 1;
}
int main()
{
	list l;
	int n;
	scanf("%d",&n);
	l = CreateList(n);	
	InsertBeg(&l,3);
	InsertEnd(&l,2);
	InsertBeg(&l,1);
	if (!InsertPos(&l,4,10))
	printf("Insert pos failed\n");
	if (!InsertEnd(&l,4))
	printf("Insertion failed\n");
	PrintList(l);
}