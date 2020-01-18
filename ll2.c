#include<stdio.h>
#include<stdlib.h>
 struct Node{
int data;
struct Node* next;
};
struct List{
struct Node* head;
int no_of_nodes;};

void init()
{
struct List* a=(struct List*)malloc(sizeof(struct List*));
a->head=NULL;
no_of_nodes=0;
return a;
}


void print(struct List* ls)
{
struct Node* p=ls->head;
while(
}


