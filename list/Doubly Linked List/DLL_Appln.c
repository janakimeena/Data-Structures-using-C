/*
* Doubly Linked list implementation in C
* M Janaki Meena
* 28-09-2021
*/
#include "DLL.h"
#include<stdio.h>
#include<stdio.h>
int main()
{
    dllist l;
    int t;
    printf("%d returned by isempty\n",IsEmpty(l));
    CreateList(&l);
    printf("%d returned by isempty\n",IsEmpty(l));
    InsertEnd(&l,1);
    //InsertEnd(&l,2);
    //InsertEnd(&l,3);
    printf("List before deletion is \n");
    PrintList(l);
    t = DeleteEnd(&l);
    if(DELETE_ERROR_FLAG)
        printf("Deletion failed\n");
    else
        printf("Element deleted is %d\n",t);
    t = DeleteEnd(&l);
    if(DELETE_ERROR_FLAG)
        printf("Deletion failed");
    else
        printf("Element deleted is %d\n",t);
    printf("List after deletion is \n");
    PrintList(l);
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 /*   printf("%d returned after create\n",IsEmpty(l));    
    InsertEnd(&l,1);
    InsertEnd(&l,2);
    InsertEnd(&l,3);
    InsertEnd(&l,4);
    InsertEnd(&l,5);
    //Insert_Position(&l,3,10);
    t = next(l,6);
    if(next_error_flag)
        printf("Position not valid\n");
    else
        printf("Next element at position is %d",t);
    PrintList(l);
    DestroyList(&l);
    printf("%d",IsEmpty(l));
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
//}
