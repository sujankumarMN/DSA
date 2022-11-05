#include<stdlib.h>
#include "header.h"

Stack init(int size)
{
	Stack my_stack;
	my_stack.top=-1;
	my_stack.t_size= size>0 && size<=MAXSIZE?size-1:MAXSIZE-1;
	return my_stack;
}

void push(Stack *my_stack,int data)
{
	if(my_stack->op == my_stack->t_size)
		return my_stack;
	my_stack->top++;
	my_stack->arr[my_stack->top]=data;
	//return my_stack;
}

Stack pop(Stack my_stack)
{
	if(my_stack.top==-1)
		return my_stack;
	my_stack.top--;
	return my_stack;
}

int peek(Stack my_stack)
{
	if(my_stack.top==-1)
		return -111;
	return my_stack.arr[my_stack.top];
}

Array insert_at_beg(Array my_array,int data)
{
    if(my_array.c_size == my_array.t_size){
        my_array.op_status = FULL;
        return my_array;
    }
    if(my_array.c_size==0)
        return insert_data(my_array,data);
    my_array.c_size++;
    int i;
    for(i=my_array.c_size-1;i>0;i--)
    {
        my_array.arr[i]=my_array.arr[i-1];
    }
    my_array.arr[0]=data;
    my_array.op_status = SUCCESS;

    return my_array;


}