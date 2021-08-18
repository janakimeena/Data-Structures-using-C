/*
* Array implementation of list in C
* Janaki Meena
* 08 - 08 - 2021
*/
#include<stdio.h>
#include<stdlib.h>
int deletion_success = 1;
int reterieve_sucess = 1;
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
	printf("Elements in the list are\n");
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
int DeleteBeg(list* l)
{
	int i,x=0;
	deletion_success = 1;
	if (IsEmpty(*l))
	{
	deletion_success = 0;
	return 0;
	}
	x = l->elements[0];
	for(i=1;i<l->no_of_elements;i++)
	l->elements[i-1] = l->elements[i];
	l->no_of_elements--;
	return x;
}

int DeleteEnd(list* l)
{
	int x=0;
	deletion_success = 1;
	if(IsEmpty(*l))
	{
		deletion_success = 0;
		return x;
	}
	x = l->elements[l->no_of_elements-1];
	l->no_of_elements--;
	return x;
}
int DeletePos(list* l,int pos)
{
	int x=0,i;
	deletion_success = 1;
	if(IsEmpty(*l)||(pos<1)||(pos>l->no_of_elements))
	{
		deletion_success = 0;
		return x;
	}
	x = l->elements[pos-1];
	for(i=pos;i<l->no_of_elements;i++)
	l->elements[i-1] = l->elements[i];
	l->no_of_elements--;
	return x;
}


int Locate(list l,int ele)
{
	int i;
	if(IsEmpty(l))
	return -1;
	for(i=0;i<l.no_of_elements;i++)
	{
		if(ele==l.elements[i])
		return i+1;
	}
	return -1;
}
int Retrieve(list l,int pos)
{
	reterieve_sucess = 1;
	if(IsEmpty(l)||(pos<1)||(pos>l.no_of_elements))
	{
		reterieve_sucess = 0;
		return -1;
	}
	return l.elements[pos-1];
}
int main()
{
	list l;
	int n,x;
	scanf("%d",&n);
	l = CreateList(n);	
	InsertBeg(&l,3);
	InsertEnd(&l,2);
	InsertBeg(&l,1);
	//PrintList(l);
	x = DeletePos(&l,10);
	if(deletion_success)
	printf("%d is deleted\n",x);
	else
	printf("Deletion failed");
	//PrintList(l);
	if (!InsertPos(&l,4,10))
	printf("Insert pos failed\n");
	if (!InsertEnd(&l,4))
	printf("Insertion failed\n");
	PrintList(l);
	printf("Locate called %d",Locate(l,20));
	x = Retrieve(l,20);
	if (reterieve_sucess==1)
	printf("Element taken is %d\n",x);
	else
	printf("Failed\n");

	/*printf("After deletion\n");
	x = DeleteBeg(&l);
	if(deletion_success)
	printf("%d is deleted\n",x);
	else
	printf("Deletion failed\n");
	PrintList(l);
	x = DeleteEnd(&l);
	if(deletion_success==1)
	printf("%d is deleted end",x);
	else
	printf("Delete end failed\n");
	PrintList(l);
	InsertBeg(&l,4);
	x = DeleteEnd(&l);
	printf("Actually %d",x);
	if(deletion_success==1)
	printf("%d element is deleted end\n",x);
	else
	printf("Delete end failed\n");*/
	
}