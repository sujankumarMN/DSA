#include <stdlib.h>
#include "dynamic.h"


Array* initialize_array(int size)
{
	Array *my_arr;
	my_arr=(Array *)malloc(sizeof(Array));

	if(NULL==my_arr)
		return NULL;
	my_arr->c_size=0;
	my_arr->t_size=size;
	my_arr->arr=(int *)malloc(sizeof(int)*size);
	my_arr->op_status = INIT_SUCCESS;
	return my_arr;
}

int insert_data(Array *my_arr,int data)
{
	if(my_arr->c_size == my_arr->t_size)
		return FULL;

	*(my_arr->arr + my_arr->c_size) = data;
	my_arr->c_size++;

	return SUCCESS;
}

Array * deallocate(Array *my_arr)
{
	free(my_arr->arr);
	free(my_arr);
	return NULL;
}

int search(Array *my_arr, int element)
{
	int i;

	if(my_arr == NULL)
		return FAIL;
	if(my_arr->arr == NULL)
		return FAIL;

	for(i=0;i<my_arr->c_size;i++)
	{
		if(*(my_arr->arr + i) == element)
			return FOUND;
	}
	return FAIL;

}

// Assumption : both array A and B have elements
Array * merge_array(Array *arr_a,Array *arr_b)
{
	int updated_c_size_a,i,j;
	if(arr_a == NULL)
		return arr_b;
	if(arr_b == NULL)
		return arr_b;
	updated_c_size_a = arr_a->c_size + arr_b->c_size;
	if(updated_c_size_a > arr_a->t_size)
	{
		arr_a->arr = realloc(arr_a->arr,(updated_c_size_a)*(sizeof(int)));
	    arr_a->t_size = updated_c_size_a;
	}
	for(i=0;i<arr_b->c_size;i++)
	{
		insert_data(arr_a,*(arr_b->arr +i));
	}
	arr_b = deallocate(arr_b);
	return arr_b;
	
}

Array * split_array(Array * arr_a, int split_index)
{

    int i;

    if(arr_a == NULL || arr_a->c_size < split_index) return NULL;

    //the number of indices to be allocated to arr_b 
    int difference = arr_a->c_size - split_index;


    //create an array to hold the split numbers 
    Array *arr_b;
    arr_b = initialize_array(difference);


    //insert data into arr_b
    for(i = split_index ; i < split_index + difference ; i++)
           insert_data(arr_b ,*(arr_a->arr+i));

    //shrink a
    arr_a->arr = realloc(arr_a->arr , sizeof(int) * split_index );    
    arr_a->c_size = split_index;
    arr_a->t_size = split_index;


    return arr_b;

}