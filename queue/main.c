#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "header.h"

int main()
{
	List *list;
	list=init();
	assert(list->count==0);
	
	assert(enqueue(list,3)==INSERTED);
	assert(enqueue(list,2)==INSERTED);
	assert(enqueue(list,5)==INSERTED);
	assert(enqueue(list,1)==INSERTED);
	assert(enqueue(list,4)==INSERTED);
	assert(list->count==5);

	display(list);

	assert(dequeue(list)==DELETED);
	assert(dequeue(list)==DELETED);
	/*assert(dequeue(list)==DELETED);
	assert(dequeue(list)==DELETED);
	assert(dequeue(list)==DELETED);
	assert(dequeue(list)==FAILED);
	assert(list->count==0);*/


	display(list);
	printf("%d\n",list );
	list=deallocate(list);
	printf("%d\n",list );

}