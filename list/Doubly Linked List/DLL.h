/*
* Doubly Linked list implementation in C
* M Janaki Meena
* 28-09-2021
*/
#include<stdio.h>
#include<stdlib.h>
#ifndef DLL
#define DLL
typedef struct node
{
    struct node* prev;
    int data;
    struct node* next;
}node;
typedef struct dllist
{
    node* head;
    node* tail;
}dllist;
node* CreateNode(int data);
void CreateList(dllist *l);
int IsEmpty(dllist l);
#endif






























/*int InsertBeg(cllist* l,int data);
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
*/