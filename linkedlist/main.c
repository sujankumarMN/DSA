#include<assert.h>
#include<stdio.h>
#include "header.h"
int main()
{
	List *list;
	List *list2;
	Node *node;
	list=initialise();
	list2=initialise();
	assert(list->status==INIT_SUCCESS);

	assert(insert_at_beg(list,3)==2);
	assert(insert_at_beg(list,1)==2);
	assert(insert_at_beg(list,5)==2);
	assert(insert_at_beg(list,4)==2);
	assert(insert_at_beg(list,5)==2);
	assert(list->count==5);

	assert(insert_at_end(list,11)==2);
	assert(insert_at_end(list,12)==2);
	assert(insert_at_end(list,21)==2);
	assert(insert_at_end(list,22)==2);
	assert(list->count==9);

	node=search(list,3);
	assert(node->ptr->data==11);

	assert(insert_after_element(list,5,30));
	assert(insert_after_element(list,22,31));
	assert(insert_after_element(list,1,32));
	assert(insert_after_element(list,11,33));
	assert(list->count==13);
	int i;
	Node *temp;
	//temp=list->head;

	for(temp=list->head;temp!=NULL;temp=temp->ptr)
	
		assert(insertion_sort(list2,temp->data)==INSERTED);
		
	assert(list2->count==13);
	list_display(list);
	list_display(list2);

	assert(delete_at_beg(list2)==DELETED);
	assert(delete_at_beg(list2)==DELETED);
	assert(delete_at_beg(list2)==DELETED);

	assert(delete_at_end(list2)==DELETED);
	assert(delete_at_end(list2)==DELETED);
	assert(delete_at_end(list2)==DELETED);
	assert(list2->count==7);


	assert(delete_element(list2,21)==DELETED);

	list_display(list);
	list_display(list2);
	list=deallocate(list);
	list2=deallocate(list2);





}