#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "header.h"

int main()
{
	List *list;
	List *stack;
	list=init();
	stack=init();
	assert(list->status==INIT_SUCCESS);
	assert(insert_at_end(list,4,stack)==1);
	assert(insert_at_end(list,9,stack)==1);
	assert(insert_at_end(list,3,stack)==1);
	assert(insert_at_end(list,6,stack)==1);
	assert(list->count==4);

	assert(delete_at_beg(list,stack)==1);
	assert(delete_at_beg(list,stack)==1);
	assert(list->count==2);
	/*
	assert(insert_at_beg(list,11,stack)==1);
	assert(insert_at_beg(list,33,stack)==1);
	assert(insert_at_beg(list,22,stack)==1);
	assert(insert_at_beg(list,66,stack)==1);
	assert(list->count==6);

	assert(delete_at_end(list,stack)==1);
	assert(delete_at_end(list,stack)==1);
	assert(list->count==4);
	*/
	display(list);
	printf("\n" );
	display(stack);
	undo(list,stack);
	undo(list,stack);
	printf("\n" );
	display(list);
}