#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#include "array.h"


int main()
{
    Array temp, test, asdf;

    temp = initialise_array(8);
    assert(temp.c_size == 0 && temp.t_size == 8);
    assert(temp.op_status == INIT_SUCCESS);
    asdf=initialise_array(5);
    test = initialise_array(30);
    assert(test.t_size == MAX_SIZE);
    
    assert(asdf.t_size == 5);
    asdf = insert_at_beg(asdf,1);
    asdf = insert_at_beg(asdf,2);
    asdf = insert_at_beg(asdf,3);
    asdf = insert_at_pos(asdf,11,0);
    asdf = insert_at_pos(asdf,12,2);
     int i;
    for(i=0;i<asdf.c_size;i++)
        printf("%d,",asdf.arr[i]);
    printf("\n");

    asdf=delete_element(asdf,12);

    for(i=0;i<asdf.c_size;i++)
        printf("%d,",asdf.arr[i]);
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
/*
    assert(max(temp)==50);
    int *max,*min;
    max_min(temp,max,min);
    assert(*max==50&& *min==10);
    return 0;*/
}
