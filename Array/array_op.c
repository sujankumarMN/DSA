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

Array insert_at_beg(Array my_array,int data)
{
    if(my_array.c_size == my_array.t_size){
        my_array.op_status = FULL;
        return my_array;
    }
    if(my_array.c_size==0)
        return insert_data(my_array,data);
    my_array.c_size++;
    int i;
    for(i=my_array.c_size-1;i>0;i--)
    {
        my_array.arr[i]=my_array.arr[i-1];
    }
    my_array.arr[0]=data;
    my_array.op_status = SUCCESS;

    return my_array;


}

Array insert_at_pos(Array my_array,int data,int pos)
{
    if(my_array.c_size == my_array.t_size){
        my_array.op_status = FULL;
        return my_array;
    }
    if(my_array.c_size==0)
        return insert_data(my_array,data);
    my_array.c_size++;
    int i;
    for(i=my_array.c_size-1;i>pos;i--)
    {
        my_array.arr[i]=my_array.arr[i-1];
    }
    my_array.arr[pos]=data;
    my_array.op_status = SUCCESS;

    return my_array;


}

Array delete_element(Array my_array,int data)
{
    if(my_array.c_size==0) return my_array;
    int position;
    position=search_pos(my_array,data);
    if(position==-1) return my_array;
     int i;
    for(i=position;i<my_array.c_size-1;i++)
        my_array.arr[i]=my_array.arr[i+1];
    my_array.c_size--;
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

int search_pos(Array my_array, int element)
{
    int i;

    for(i=0;i<my_array.c_size;i++)
    {
        if(element == my_array.arr[i])
        {
            return i;
        }
    }

    return -1;

}
/*
int max(Array my_array)
{
    int i;
    int max=my_array.arr[0];

    for(i=0;i<my_array.c_size;i++)
    {
        if(my_array.arr[i]>max)
        {
            max=my_array.arr[i];
           
        }
    }

    return max;

}

int max_min(Array my_array,int *max,int *min)
{
    int i;
    int max,min;
    max=min=my_array.arr[0];
    for(i=0;i<my_array.c_size;i++)
    {
        if(my_array.arr[i]>max)
        {
            *max=my_array.arr[i];
           
        }
        if(my_array.arr[i]<min)
        {
            *min=my_array.arr[i];
           
        }
    }
    return 1;


}*/