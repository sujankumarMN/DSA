#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "h_ll.h"

int main()
{
	Stack *my_stack;
	my_stack=init();
	assert(my_stack->count==0);

	assert(push(my_stack,2)==1);
	assert(push(my_stack,4)==1);
	assert(push(my_stack,1)==1);
	//display(my_stack);

	assert(my_stack->top->data==1);
	assert(my_stack->count==3);

	assert(pop(my_stack)==1);
	assert(my_stack->top->data==4);
	assert(my_stack->count==2);
	//display(my_stack);
	assert(pop(my_stack)==4);
	assert(pop(my_stack)==2);
	assert(my_stack->count==0);	
	assert(pop(my_stack)==7);
	assert(pop(my_stack)==7);
	assert(my_stack->top==NULL);
	//display(my_stack);

	assert(push(my_stack,2)==1);
	assert(push(my_stack,4)==1);
	assert(push(my_stack,1)==1);
	assert(push(my_stack,3)==1);
	assert(push(my_stack,6)==1);
	assert(push(my_stack,5)==1);
	//display(my_stack);

	assert(peek(my_stack)==5);

	assert(search(my_stack,4)==1);
	//display(my_stack);
	assert(search(my_stack,44)==0);

	display(my_stack);
	assert(my_stack->count==6);
	//printf("%d\n",my_stack->count );
}