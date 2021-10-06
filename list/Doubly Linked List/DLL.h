/*
* Doubly Linked list implementation in C
* M Janaki Meena
* 28-09-2021
*/

#include<stdio.h>
#include<stdlib.h>
#ifndef DLL
#define DLL
extern int DELETE_ERROR_FLAG;
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
int IsSingleNode(dllist l);
int InsertBeg(dllist* l,int data);
void PrintList(dllist l);
int InsertEnd(dllist* l,int data);
int InsertPos(dllist* l,int pos,int data);
int DeleteBeg(dllist* l);
int DeleteEnd(dllist *l);
int DeletePos(dllist *l,int pos);
#endif




























/*

int Insert_Position(cllist* l, int pos, int data);

int DeleteBeg(cllist* l);
int DeleteEnd(cllist *l);
int DeletePos(cllist* l,int pos);
int locate(cllist l,int ele);
int retrieve(cllist l,int pos);
int previous(cllist l,int ele);
int next(cllist l, int ele);
void DestroyList(cllist *l);
*/