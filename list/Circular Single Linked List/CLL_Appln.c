/*
* Circular Linked list implementation in C
* M Janaki Meena
* 02-09-2021
*/
#include "CLL.h"
#include<stdio.h>
#include<stdio.h>
int main()
{
    cllist l;
    int t;
    printf("%d returned by isempty\n",IsEmpty(l));
    CreateList(&l);
    printf("%d returned after create\n",IsEmpty(l));    
    InsertBeg(&l,1);
    //InsertBeg(&l,2);
    //InsertEnd(&l,5);
    //InsertBeg(&l,3);
    //InsertEnd(&l,4);
    //Insert_Position(&l,3,10);
    t = DeleteEnd(&l);
    if(delete_error_flag)
        printf("Deletion failed\n");
    else
        printf("Value deleted is %d",t);
    PrintList(l);

    /*InsertBeg(&l,2);
    InsertEnd(&l,5);
    Insert_Position(&l,2,10);
    PrintList(l);
    DestroyList(&l);
    t = next(l,1);
    if(next_error_flag)
    printf("Invalid");
    else
    printf("Next element is %d\n", t);
    
    /*t = locate(l,20);
    if(t==-1)
    printf("Element not found\n");
    else
    printf("Element found at %d\n",t);
    /*t = DeletePos(&l,5);
    if(delete_error_flag)
    printf("Deletion failed\n");
    else
    printf("Value deleted is %d\n",t);
    PrintList(l);
    /*t = DeleteBeg(&l);
    if(delete_error_flag)
    printf("Delettion failed\n");
    else
    printf("Value deleted is %d\n",t);
    PrintList(l);
    t = DeleteEnd(&l);
    if(delete_error_flag)
    printf("Delettion failed\n");
    else
    printf("Value deleted is %d\n",t);
    PrintList(l);*/
}
