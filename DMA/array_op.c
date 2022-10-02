#include<stdlib.h>
#include "array.h"


Array * initialise(int size)
{
	Array *array;
	array=(Array *)malloc(sizeof(Array));
	if(NULL==array) return NULL;
	array->arr=(int *)malloc(sizeof(int)*size);
	array->c_size=0;
	array->t_size=size;
	array->op_status = INIT_SUCCESS;
	//return array;
}
//----------------------------------------------------------------------------
int insert_data(Array *array,int data)
{
	if(array->c_size==array->t_size)
	{
		array->op_status=FULL;
	}	
	return FULL;


	*(array->arr + array->c_size) = data;
	array->c_size++;
	array->op_status=SUCCESS;
	return SUCCESS; 
}
//-----------------------------------------------------------------------------