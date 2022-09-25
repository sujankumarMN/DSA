#include "pixel.h"

Array initialisation(int size)
{
	Array arr;
	arr.c_size=0;
	arr.t_size= size>=0&&size<=MAXSIZE?size:MAXSIZE;
	arr.op_status=INIT_SUCCESS;
	return arr;

}
//-----------------------------------------------------------------------------------------------------------------
Array insert_data(Array arr,int r, int g, int b, float opacity, int transparency)
{
	
	if(arr.c_size==arr.t_size)
		arr.op_status=FULL;
	else
	{
		arr.p[arr.c_size].r=r;
		arr.p[arr.c_size].g=g;
		arr.p[arr.c_size].b=b;
		arr.p[arr.c_size].opacity=opacity;
		arr.p[arr.c_size].transparency=transparency;
		arr.op_status=SUCCESS;
		arr.c_size++;
	}	
	return arr;
}
//------------------------------------------------------------------------------------------------------------------
int count_red_pixels(Array arr)
{
	int i,count=0;
	for(i=0;i<arr.c_size;i++)
	{
		if(arr.p[i].r==1 && arr.p[i].g==0 && arr.p[i].b==0)
			count++;
		
	}
	return count;
}
//-------------------------------------------------------------------------------------------------------------------