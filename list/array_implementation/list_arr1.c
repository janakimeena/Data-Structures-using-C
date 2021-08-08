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
	for(i=0;i<l.capacity;i++)
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
int main()
{
	list l;
	int n;
	scanf("%d",&n);
	l = CreateList(n);
	PrintList(l);
	printf("%d\n",IsEmpty(l));
	printf("%d\n",IsFull(l));
}