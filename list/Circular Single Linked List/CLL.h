/*
* Circular Linked list implementation in C
* M Janaki Meena
* 02-09-2021
*/
#include<stdio.h>
#include<stdlib.h>
#ifndef CLL
#define CLL
extern int delete_error_flag;
extern int retrieve_error_flag;
extern int previous_error_flag;
extern int next_error_flag;
typedef struct node
{
    int data;
    struct node* next;
}node;
typedef struct cllist
{
    node* head;
}cllist;

void CreateList(cllist *l);
int IsEmpty(cllist l);
node* CreateNode(int data);
int InsertBeg(cllist* l,int data);
int InsertEnd(cllist* l,int data);
int Insert_Position(cllist* l, int pos, int data);
void PrintList(cllist l);
int DeleteBeg(cllist* l);
int DeleteEnd(cllist *l);
int DeletePos(cllist* l,int pos);
int locate(cllist l,int ele);
int retrieve(cllist l,int pos);
int previous(cllist l,int ele);
int next(cllist l, int ele);
void DestroyList(cllist *l);
#endif