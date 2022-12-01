#include <stdio.h>
#include<assert.h>
#include"dynamic.h"

int main()
{
	/*Array *test_ptr,*arr_one,*arr_two;
	test_ptr = initialize_array(5);
	arr_one = initialize_array(10);
	arr_two = initialize_array(15);

	assert(test_ptr!=NULL);
	assert(arr_one->c_size ==0 && arr_one->t_size == 10);
	assert(test_ptr->op_status == INIT_SUCCESS);

	assert(insert_data(test_ptr,10)==SUCCESS);
	assert(insert_data(test_ptr,30)==SUCCESS);
	assert(insert_data(test_ptr,40)==SUCCESS);
	assert(insert_data(test_ptr,20)==SUCCESS);
	assert(insert_data(test_ptr,60)==SUCCESS);
	assert(test_ptr->c_size == 5);
	assert(insert_data(test_ptr,100)==FULL);
	assert(search(test_ptr,30) == FOUND);
	assert(search(test_ptr,60) == FOUND);
	assert(search(test_ptr,100) == FAIL);
	//merge array
	assert(insert_data(arr_one,10));
	assert(insert_data(arr_one,30));
	assert(insert_data(arr_one,20));
	assert(insert_data(arr_one,50));
	assert(insert_data(arr_one,20));
	assert(insert_data(arr_one,60));
	assert(insert_data(arr_one,10));
	assert(arr_one->c_size == 7);
	assert(insert_data(arr_two,90));
	assert(insert_data(arr_two,90));
	assert(insert_data(arr_two,90));
	assert(insert_data(arr_two,90));
	assert(insert_data(arr_two,30));
	assert(insert_data(arr_two,90));
	assert(insert_data(arr_two,50));
	assert(insert_data(arr_two,90));
	assert(insert_data(arr_two,10));
	assert(insert_data(arr_two,80));
	assert(arr_two->c_size == 10);

	arr_two = merge_array(arr_one,arr_two);
	assert(arr_one->c_size == 17);
	assert(arr_one->t_size == 17);
	assert(arr_two == NULL);*/

	//split array
	Array *arr_one, *arr_two;
    int i;
    arr_one = initialize_array(10);
    
    assert(insert_data(arr_one, 10));
    assert(insert_data(arr_one, 30));
    assert(insert_data(arr_one, 20));
    assert(insert_data(arr_one, 50));
    assert(insert_data(arr_one, 20));
    assert(insert_data(arr_one, 60));
    assert(insert_data(arr_one, 10));


//split index 15 > 10 must fail
    assert(split_array(arr_one , 15) == NULL);


    arr_two = split_array(arr_one , 4);

    // check array a
    assert(arr_one->arr[3] == 50);
    assert(arr_one->c_size == 4);
    assert(arr_one->t_size == 4);
   // check array b
    assert(arr_two->arr[0] == 20);
    assert(arr_two->arr[1] == 60);
    assert(arr_two->arr[2] == 10);
    assert(arr_two->c_size == 3);
    assert(arr_two->t_size == 3);


	return 0;
}