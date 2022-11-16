#include<stdlib.h>
#include<stdio.h>
#include "header.h"

List * init()
{
	List *my_list;
	my_list =(List *)malloc(sizeof(List));
	if(my_list==NULL) return NULL;
	my_list->head=NULL;
	my_list->tail=NULL;
	my_list->status=INIT_SUCCESS;
	my_list->count=0;
	return my_list;

}

Node * getnode(int n)
{
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));
	if(newnode==NULL) return NULL;
	newnode->ptr==NULL;
	newnode->ele=(Data *)malloc(sizeof(Data));
	newnode->ele->n=n;
	return newnode;

}
int insert_at_end(List *my_list,int n)
{
	Node *my_node;
	my_node=getnode(n);

	if(my_list->count==0)
	{
		my_list->count++;
		my_node->ele->pos=my_list->count;
		my_node->ele->insert=1;
		my_node->ele->active=1;
		my_list->head=my_list->tail=my_node;
		my_list->status=SUCCESS;

	}
	else
	{
		my_list->count++;
		my_node->ele->pos=my_list->count;
		my_node->ele->insert=1;
		my_node->ele->active=1;
		my_list->tail->ptr=my_node;
		my_list->tail=my_node;
		my_list->status=SUCCESS;
	}
	//push(my_stack,my_node);

	return SUCCESS;
	
}
void update_pos_insert(List *my_list,int pos)
{
	Node *temp=my_list->head;
	int i;
	for(i=1;i<=pos;i++) temp=temp->ptr;
	while(temp!=NULL)
	{
		temp->ele->pos=temp->ele->pos+1;
		temp=temp->ptr;
	}
}
int insert_at_beg(List *my_list,int n)
{
	Node *my_node;
	my_node=getnode(n);

	if(my_list->count==0)
	{
		my_list->count++;
		my_node->ele->pos=my_list->count;
		my_node->ele->insert=1;
		my_node->ele->active=1;
		my_list->head=my_list->tail=my_node;
		my_list->status=SUCCESS;

	}
	else
	{
		my_list->count++;
		my_node->ele->pos=1;
		my_node->ele->insert=1;
		my_node->ele->active=1;
		my_node->ptr=my_list->head;
		my_list->head=my_node;
		my_list->status=SUCCESS;
		update_pos_insert(my_list,1);

	}
	//push(my_stack,my_node);
	return SUCCESS;
	
}
int insert_at_pos(List *my_list,int n,int pos)
{
	Node *my_node;
	my_node=getnode(n);

	if(my_list->count==0)
	{
		my_list->count++;
		my_node->ele->pos=my_list->count;
		my_node->ele->insert=1;
		my_node->ele->active=1;
		my_list->head=my_list->tail=my_node;
		my_list->status=SUCCESS;

	}
	else
	{
		if(pos==1) return insert_at_beg(my_list,n);
		if(pos==my_list->count) return insert_at_end(my_list,n);
		if(pos >=2 && pos <my_list->count)
		{
			my_list->count++;
			my_node->ele->pos=1;
			my_node->ele->insert=1;
			my_node->ele->active=1;
			int i;
			Node *temp=my_list->head;
			for(i=1;i<pos-1;i++) temp=temp->ptr;
			my_node->ptr= temp->ptr;
			temp->ptr=my_node;
			update_pos_insert(my_list,pos);
		}
				
	}
	//push(my_stack,my_node);
	return SUCCESS;


}

int delete_at_end(List *my_list)
{
	Node *my_node,*temp=my_list->head;
	//my_node=getnode(n);

	if(my_list->count==0) return FAILURE;
	if(my_list->count==1) 
	{
		my_list->head->ele->insert=0;
		my_list->head->ele->active=0;
		my_list->head=my_list->tail=NULL;
		free(temp);
		my_list->count--;


	}
	else
	{
		for(temp=my_list->head;temp->ptr->ptr!=NULL;temp=temp->ptr);
	
		my_list->tail->ele->insert=0;
		my_list->tail->ele->active=0;
		

		my_list->tail=temp;
		my_list->tail->ptr=NULL;
		free(temp->ptr);
		my_list->count--;
	}
	//push(my_stack,my_node);
	return SUCCESS;
}

void update_pos_delete(List *my_list,int pos)
{
	Node *temp=my_list->head;
	int i;
	for(i=1;i<=pos;i++) temp=temp->ptr;
	while(temp!=NULL)
	{
		temp->ele->pos=temp->ele->pos-1;
		temp=temp->ptr;
	}
}
int delete_at_beg(List *my_list)
{
	Node *my_node,*temp=my_list->head;
	//my_node=getnode(n);

	if(my_list->count==0) return FAILURE;
	if(my_list->count==1) 
	{
		my_list->head->ele->insert=0;
		my_list->head->ele->active=0;
		my_list->head=my_list->tail=NULL;
		free(temp);
		my_list->count--;


	}
	else
	{
		my_list->head->ele->insert=0;
		my_list->head->ele->active=0;
		update_pos_delete(my_list,1);
		my_list->head=my_list->head->ptr;
		free(temp);
		my_list->count--;
		
	}
	//push(my_stack,my_node);
	return SUCCESS;
}



void display(List *my_list)
{
	Node *temp;
	for(temp=my_list->head;temp!=NULL;temp=temp->ptr)
	{
		printf("%d -> ",temp->ele->n);
	}
}

List * dealloc(List *my_list)
{

	Node *temp;
	temp=my_list->head;

	while(my_list->head!=NULL)
	{
		my_list->head=my_list->head->ptr;
		free(temp->ele);
		free(temp);
		
		temp=my_list->head;
	}
	free(my_list);
	return NULL;

}