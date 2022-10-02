#include "array.h"

Array initialise_array(int size)
{
    Array my_array;

    my_array.c_size = 0;
    my_array.t_size = size > 0 && size <= MAX_SIZE?size: MAX_SIZE;
    my_array.op_status = INIT_SUCCESS;

    return my_array;
}

Array insert_data(Array my_array, int data)
{

    if(my_array.c_size == my_array.t_size){
        my_array.op_status = FULL;
        return my_array;
    }

    my_array.arr[my_array.c_size] = data;
    my_array.c_size++;
    my_array.op_status = SUCCESS;

    return my_array;
}

int search_element(Array my_array, int element)
{
    int i;

    for(i=0;i<my_array.c_size;i++)
    {
        if(element == my_array.arr[i])
        {
            return SUCCESS;
        }
    }

    return 0;

}
