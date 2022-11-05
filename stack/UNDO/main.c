#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "header.h"
int main()
{
	Stack stack;
	stack=init(5);
	assert(stack.top==-1 && stack.t_size==4);

	stack=push(stack,2);
	stack=push(stack,4);
	stack=push(stack,3);
	assert(stack.arr[1]==4);
	assert(stack.arr[2]==3);

	stack=push(stack,22);
	stack=push(stack,44);
	stack=push(stack,33);
	stack=push(stack,44);
	stack=push(stack,33);
	assert(peek(stack)==44);
	

	stack=pop(stack);
	stack=pop(stack);
	stack=pop(stack);

	assert(peek(stack)==4);

	int i;
	for(i=0;i<=stack.top;i++)
		printf("%d,",stack.arr[i] );
	



}