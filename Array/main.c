#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#include "array.h"


int main()
{
    Array temp, test;

    temp = initialise_array(8);
    assert(temp.c_size == 0 && temp.t_size == 8);
    assert(temp.op_status == INIT_SUCCESS);

    test = initialise_array(30);
    assert(test.t_size == MAX_SIZE);


    // test indert_data()

    temp = insert_data(temp, 10);
    temp = insert_data(temp, 20);
    temp = insert_data(temp, 30);
    temp = insert_data(temp, 40);
    temp = insert_data(temp, 50);

    assert(temp.c_size == 5);
    assert(temp.arr[3] == 40);
    assert(temp.arr[temp.c_size - 1] == 50);

    temp = insert_data(temp, 20);
    temp = insert_data(temp, 30);
    temp = insert_data(temp, 40);

    assert(temp.c_size == temp.t_size);

    temp = insert_data(temp, 60);

    assert(temp.op_status == FULL);

    assert(search_element(temp, 40) == SUCCESS);
    assert(search_element(temp, 10) == SUCCESS);
    assert(search_element(temp, 50) == SUCCESS);

    assert(search_element(temp, 60) == 0);


    return 0;
}
