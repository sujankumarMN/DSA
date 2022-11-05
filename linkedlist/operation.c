#include<stdlib.h>
#include<stdio.h>
#include "header.h"

List * initialise()
{
	List *my_list;
	my_list=(List *)malloc(sizeof(List));
	if(my_list==NULL) return NULL;
	my_list->head=my_list->tail=NULL;
	my_list->count=0;
	my_list->status=INIT_SUCCESS;
	return my_list;
}

Node * getnode(int data)
{
	Node *my_node;
	my_node=(Node *)malloc(sizeof(Node));
	if(my_node==NULL) return NULL;
	my_node->ptr=NULL;
	my_node->data=data;
	return my_node;
}

int insert_at_beg(List *my_list,int data)
{
	Node *my_node;
	my_node=getnode(data);

	if(my_list->count==0)
		my_list->head=my_list->tail=my_node;
	else
	{
		my_node->ptr=my_list->head;
		my_list->head=my_node;
	}
	my_list->count++;
	my_list->status=INSERTED;

	return INSERTED;

}

int insert_at_end(List *my_list,int data)
{
	Node *my_node;
	my_node=getnode(data);

	if(my_list->count==0)
		my_list->head=my_list->tail=my_node;
	else
	{
		//my_node->ptr=my_list->tail;
		my_list->tail->ptr=my_node;
		my_list->tail=my_node;
	}
	my_list->count++;
	my_list->status=INSERTED;

	return INSERTED;

}

Node * search(List * my_list, int element)
{
	Node * temp;
	for(temp=my_list->head;temp!=NULL;temp=temp->ptr)
	{
		if(element == temp->data)
			return temp;
	}
	return NULL;
}

int insert_after_element(List *my_list,int element,int data)
{
	Node *temp,*newnode;
	if(my_list->count==0)
		return FAIL;
	if(element==my_list->tail->data)
		return insert_at_end(my_list,data);
	newnode=getnode(data);
	temp=search(my_list,element);
	newnode->ptr=temp->ptr;
	temp->ptr=newnode;
	my_list->count++;
	return INSERTED;

}

int insertion_sort(List *my_list,int data)
{
	if(my_list->count==0 || data <= my_list->head->data)
	{
		return insert_at_beg(my_list,data);
	}
	if(my_list->count == 1 && data >my_list->head->data)
		return insert_at_end(my_list,data);
	if(my_list->tail->data<data)
		return insert_at_end(my_list,data);
	Node *temp,*newnode;
	for(temp=my_list->head;temp->ptr!=NULL;temp=temp->ptr)
	{
		if(data<=temp->ptr->data && data>temp->data)
		{
			newnode=getnode(data);
			newnode->ptr=temp->ptr;
			temp->ptr=newnode;
			my_list->count++;
			return INSERTED;
		}

	}


}

int delete_at_beg(List *my_list)
{
	Node *temp=my_list->head;
	my_list->head=my_list->head->ptr;
	free(temp);
	my_list->count--;
	return DELETED;
}

int delete_at_end(List *my_list)
{
	Node *temp=my_list->head;

	if(my_list->count==0)
		return 0;
	if(my_list->count==1)
	{
		my_list->head=my_list->tail=NULL;
		free(temp);
		my_list->count--;
		return DELETED;
	}

	for(temp=my_list->head;temp->ptr->ptr!=NULL;temp=temp->ptr);
	
	my_list->tail=temp;
	my_list->tail->ptr=NULL;
	free(temp->ptr);
	my_list->count--;
	return DELETED;
	
	
}

int delete_element(List *my_list, int data)
{
	if(my_list->count==0)
		return 0;
	if(my_list->head->data==data)
		return delete_at_beg(my_list);
	if(my_list->tail->data==data)
		return delete_at_end(my_list);

	Node *temp,*extra;
	for(temp=my_list->head;temp->ptr!=NULL;temp=temp->ptr)
	{
		if(temp->ptr->data == data)
		{
			extra=temp->ptr;
			temp->ptr=extra->ptr;
			free(extra);
			my_list->count--;
			return DELETED;

		}
	}	
}


void list_display(List *my_list)
{
	Node *temp;
	printf("\n");
	for(temp=my_list->head;temp!=NULL;temp=temp->ptr)
	{
		printf("%d ->",temp->data);
	}
	printf("\n");
}

List * deallocate(List *my_list)
{
	Node *temp;
	temp=my_list->head;

	while(my_list->head!=NULL)
	{
		my_list->head=my_list->head->ptr;
		free(temp);
		
		temp=my_list->head;
	}
	free(my_list);
	return NULL;

}
