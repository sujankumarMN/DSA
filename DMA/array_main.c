#include<assert.h>
#include "array.h"
#include<stdio.h>
int main()
{
	Array *my_array;
	my_array = initialise(10);
	assert(my_array->t_size == 10);

	insert_data(my_array,232);
	insert_data(my_array,1);
	insert_data(my_array,7);
	
	assert(my_array->c_size==3);
    assert(*(my_array->arr + 2)==7);
    assert(*(my_array->arr + 1)==1);
    
    assert(insert_data(my_array,9)==SUCCESS);
    
    assert(my_array->c_size==4);
    
    int i;
    for(i=0;i<3;i++)
    {
    	insert_data(my_array,i);
    }

    assert(*(my_array->arr+4)==0);




	


	
}