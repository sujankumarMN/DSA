#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "header.h"

int main()
{
	List *list;
	//Stack *stack;
	list=init();
	assert(list->status==INIT_SUCCESS);
	assert(insert_at_end(list,7)==SUCCESS);
	assert(insert_at_end(list,1)==SUCCESS);
	assert(insert_at_end(list,3)==SUCCESS);
	assert(insert_at_end(list,2)==SUCCESS);

	assert(list->count==4);
	assert(list->tail->ele->n==2);
	assert(list->head->ele->n==7);
	assert(list->tail->ele->insert==1 && list->tail->ele->active==1);
	
	assert(insert_at_beg(list,10)==SUCCESS);
	assert(insert_at_beg(list,20)==SUCCESS);
	assert(insert_at_beg(list,30)==SUCCESS);
	assert(insert_at_beg(list,40)==SUCCESS);
	
	assert(list->tail->ele->pos==8);
	assert(list->head->ele->pos==1);

	assert(insert_at_pos(list,111,4)==SUCCESS);

	assert(list->tail->ele->pos==9);
	assert(list->head->ele->pos==1);

	assert(delete_at_end(list)==SUCCESS);
	assert(delete_at_end(list)==SUCCESS);
	assert(delete_at_end(list)==SUCCESS);
	assert(list->tail->ele->pos==6);

	assert(delete_at_beg(list)==SUCCESS);
	assert(delete_at_beg(list)==SUCCESS);
	assert(list->tail->ele->pos==4);
	assert(list->head->ele->pos==1);


	display(list);

}