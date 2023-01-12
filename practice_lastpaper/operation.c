#include<stdlib.h>
#include<stdio.h>
#include "header.h"

List * init()
{
	List *my_list;
	my_list=(List *)malloc(sizeof(List));
	if(my_list==NULL) return NULL;
	my_list->head=my_list->tail=NULL;
	my_list->status=INIT_SUCCESS;
	return my_list;

}

Node * getnode(int n)
{
	Node * newnode;
	newnode=(Node *)malloc(sizeof(Node));
	if(newnode==NULL) return NULL;
	newnode->data=n;
	newnode->is_insert=-1;
	newnode->ptr=NULL;
	return newnode;
}

int  insert_at_end(List *my_list,int n, List *my_stack)
{
	Node *newnode;
	newnode=getnode(n);
	newnode->is_insert=1;
	if(my_list->count==0)
	{
		my_list->head=my_list->tail=newnode;
		my_list->count++;
		my_list->status=SUCCESS;
	}
	else
	{
		my_list->tail->ptr=newnode;
		my_list->tail=newnode;
		my_list->count++;
		my_list->status=SUCCESS;
	}
	push(my_stack,n);

	return 1;
}

int  push(List *my_list,int n)
{
	Node *newnode;
	newnode=getnode(n);
	if(my_list->count==0)
	{
		my_list->head=my_list->tail=newnode;
		my_list->count++;
		my_list->status=SUCCESS;
	}
	else
	{
		my_list->tail->ptr=newnode;
		my_list->tail=newnode;
		my_list->count++;
		my_list->status=SUCCESS;
	}
	
	return 1;
}

int  insert_at_beg(List *my_list,int n,List *my_stack)
{
	Node *newnode;
	newnode=getnode(n);
	newnode->is_insert=1;
	if(my_list->count==0)
	{
		my_list->head=my_list->tail=newnode;
		my_list->count++;
		my_list->status=SUCCESS;
	}
	else
	{
		newnode->ptr=my_list->head;
		my_list->head=newnode;
		my_list->count++;
		my_list->status=SUCCESS;
	}
	push(my_stack,n);
	return 1;


}

int  insert_at_beg_undo(List *my_list,int n)
{
	Node *newnode;
	newnode=getnode(n);
	newnode->is_insert=1;
	if(my_list->count==0)
	{
		my_list->head=my_list->tail=newnode;
		my_list->count++;
		my_list->status=SUCCESS;
	}
	else
	{
		newnode->ptr=my_list->head;
		my_list->head=newnode;
		my_list->count++;
		my_list->status=SUCCESS;
	}
	
	return 1;


}

int delete_at_beg(List *my_list, List *my_stack)
{
	Node *temp;
	if(my_list->count==0)
		return 0;
	else if(my_list->count==1)
	{
		temp=my_list->head;
		temp->is_insert=0;
		push(my_stack,temp->data);
		free(temp);
		my_list->count--;
	}
	else
	{
		temp=my_list->head;
		my_list->head=my_list->head->ptr;
		my_list->count--;
		temp->is_insert=0;
		push(my_stack,temp->data);
		free(temp);
	}
	//push(my_stack,n);
	return 1;
}
int delete_at_end(List *my_list,List *my_stack)
{
	Node *temp;
	if(my_list->count==0)
		return 0;
	else if(my_list->count==1)
	{
		temp=my_list->head;
		temp->is_insert=0;
		push(my_stack,temp->data);
		free(temp);
		my_list->count--;
	}
	else
	{
		

		for(temp=my_list->head;temp->ptr->ptr!=NULL;temp=temp->ptr);
		Node * temp1=temp->ptr;
		temp->ptr=NULL;
		my_list->tail=temp;
		my_list->count--;
		temp1->is_insert=0;
		push(my_stack,temp1->data);
		free(temp1);
	}
	return 1;
}
int delete_at_end_undo(List *my_list)
{
	Node *temp;
	if(my_list->count==0)
		return 0;
	else if(my_list->count==1)
	{
		temp=my_list->head;
		temp->is_insert=0;
		
		free(temp);
		my_list->count--;
	}
	else
	{
		

		for(temp=my_list->head;temp->ptr->ptr!=NULL;temp=temp->ptr);
		Node * temp1=temp->ptr;
		temp->ptr=NULL;
		my_list->tail=temp;
		my_list->count--;
		temp1->is_insert=0;
		
		free(temp1);
	}
	return 1;
}

Node * pop(List *my_list)
{
	Node *temp;
	int n;
	if(my_list->count==0)
		return NULL;
	else if(my_list->count==1)
	{
		temp=my_list->head;
		n=temp->data;
		//free(temp);
		my_list->count--;
		return temp;
	}
	else
	{
		

		for(temp=my_list->head;temp->ptr->ptr!=NULL;temp=temp->ptr);
		Node * temp1=temp->ptr;
		n=temp1->data;
		temp->ptr=NULL;
		my_list->tail=temp;
		my_list->count--;
		temp1->is_insert=0;
		
		//free(temp1);
		return temp1;
	}
	//return n;
}

void undo(List *my_list,List *my_stack)
{
	Node *temp;
	int n;
	temp=pop(my_stack);
	if(temp->is_insert==1)
		n=delete_at_end_undo(my_list);
	else if(temp->is_insert==0)
		n=insert_at_beg_undo(my_list,temp->data);

}

void display(List *my_list)
{
	Node *temp;
	for(temp=my_list->head;temp!=NULL;temp=temp->ptr)
		printf("%d\t",temp->data );
}