/*
* Linked list implementation in C
* M Janaki Meena
* 16-8-2021
*/
#include<stdio.h>
#include<stdlib.h>
#ifndef SLL
#define SLL
extern int delete_error_flag;
extern int retrieve_error_flag;
extern int previous_error_flag;
extern int next_error_flag;
typedef struct node
{
    int data;
    struct node* next;
}node;
typedef struct llist
{
    node* head;
}llist;

void CreateList(llist *l);
int IsEmpty(llist l);
node* CreateNode(int data);
int InsertBeg(llist* l,int data);
//Insert End 
int InsertEnd(llist* l,int data);
int Insert_Position(llist* l, int pos, int data);
void PrintList(llist l);
int DeleteBeg(llist* l);
int DeleteEnd(llist *l);
int DeletePos(llist* l,int pos);
int locate(llist l,int ele);
int retrieve(llist l,int pos);
int previous(llist l,int ele);
int next(llist l, int ele);
void DestroyList(llist *l);
#endif