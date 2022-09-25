#include<stdio.h>
#include<assert.h>
#include "pixel.h"

int main()
{
	
	Array my_arr;
	my_arr=initialisation(8);
	assert(my_arr.t_size==8);
	assert(my_arr.op_status==2);

	my_arr=insert_data(my_arr,1,2,1,0.4,1);
	my_arr=insert_data(my_arr,10,67,211,1,1);
	my_arr=insert_data(my_arr,1,2,1,0.9,0);
	assert(my_arr.c_size==3);
	assert(my_arr.p[my_arr.c_size-2].transparency==1);
	assert(my_arr.op_status==SUCCESS);

	my_arr=insert_data(my_arr,1,0,0,0.2,1);
	my_arr=insert_data(my_arr,111,99,83,0,0);
	my_arr=insert_data(my_arr,10,67,211,1,1);
	my_arr=insert_data(my_arr,1,2,1,0,1);
	my_arr=insert_data(my_arr,1,0,0,1,0);
	assert(my_arr.c_size==8);
	assert(my_arr.p[my_arr.c_size-2].transparency==1);
	assert(my_arr.op_status==SUCCESS);

	my_arr=insert_data(my_arr,1,0,0,1,1);
	assert(my_arr.op_status==FULL);
	assert(my_arr.c_size==8);
	assert(my_arr.p[my_arr.c_size-1].transparency==0);

	int count;
	count=count_red_pixels(my_arr);
	assert(count==2);





}