#include<stdlib.h>
#include<stdio.h>
#include "header.h"

List * init()
{
	List * my_list;
	my_list=(List *)malloc(sizeof(List));
	if(my_list==NULL) return NULL;
	my_list->front=my_list->rear=NULL;
	my_list->count=0;
	return my_list;
}

Node * getnode(int data)
{
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));
	if(newnode==NULL) return NULL;
	newnode->data=data;
	newnode->ptr=NULL;
	return newnode;
}

int enqueue(List *my_list,int data)
{
	Node *my_node;
	my_node=getnode(data);
	if(my_list->count==0)
	{
		my_list->rear=my_list->front=my_node;
		my_list->count++;
	}
	else
	{
		my_list->rear->ptr=my_node;
		my_list->rear=my_node;
		my_list->count++;
	}
	return INSERTED;
}

int dequeue(List * my_list)
{
	Node * temp;
	if(my_list->count==0) return FAILED;
	temp=my_list->front;
	printf("%d DEQUEUED :)\n",my_list->front->data);
	my_list->front=my_list->front->ptr;
	free(temp);
	my_list->count--;
	return DELETED;
}

void display(List * my_list)
{
	printf("\nQueue contains:\n");
	Node *temp;
	for(temp=my_list->front;temp!=NULL;temp=temp->ptr)
		printf("%d ->",temp->data );
	printf("\n");
}

List * deallocate(List * my_list)
{
	Node *temp;
	temp=my_list->front;
	
	while(my_list->front!=NULL)
	{
		my_list->front=my_list->front->ptr;
		free(temp);
		temp=my_list->front;
		
	}	
	free(my_list);
	
	return NULL;
}