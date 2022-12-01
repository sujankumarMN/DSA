#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "h_ll.h"

Stack * init()
{
	Stack *my_stack;
	my_stack=(Stack *)malloc(sizeof(Stack));
	if(my_stack==NULL) return NULL;
	my_stack->top=NULL;
	my_stack->count=0;
}

Node * getnode(int n)
{
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));
	if(newnode==NULL) return NULL;
	newnode->ptr==NULL;
	newnode->data=n;
	return newnode;

}

int push(Stack *my_stack,int n)
{
	Node *my_node;
	my_node=getnode(n);
	if(my_stack->count==0)
	{
		my_stack->top=my_node;
		my_stack->top->ptr=NULL;
		my_stack->count++;
		return 1;
	}
	else
	{
		my_node->ptr=my_stack->top;
		my_stack->top=my_node;
		my_stack->count++;
		return 1;
	}
	

}

int pop(Stack *my_stack)
{
	Node *temp;
	int i;
	if(my_stack->count!=0)
	{
		temp=my_stack->top;
		i=temp->data;
		my_stack->top=my_stack->top->ptr;
		free(temp);
		my_stack->count--;
		return i;
	}
	else
		return 7;
	
}

int peek(Stack *my_stack)
{
	return my_stack->top->data;
}

int search(Stack *my_stack,int data)
{
	Stack *stack2;
	stack2=init();
	Node *temp;
	
	while(my_stack->top!=NULL)
	{
		if(data==peek(my_stack))
		{
			while(stack2->top!=NULL)
				assert(push(my_stack,pop(stack2))==1);
			//printf("\n%d,",my_stack->count);
			//display(my_stack);
			return 1;
		}
		else
		{
			assert(push(stack2,pop(my_stack))==1);
			//printf("%d,",my_stack->count);
		}



	}
	while(stack2->top!=NULL)
		assert(push(my_stack,pop(stack2))==1);
	return 0;
}

void display(Stack *my_stack)
{
	Node *temp;
	printf("\n");
	for(temp=my_stack->top;temp!=NULL;temp=temp->ptr)
		printf("%d ->",temp->data );
	printf("\n");
}

