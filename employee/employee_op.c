#include<stdlib.h>
#include "employee.h"
#include <string.h>

Earray * initialise(int size)
{
	Earray *e_arr;
	e_arr=(Earray *)malloc(sizeof(Earray));
	if(e_arr==NULL) return NULL;
	e_arr->c_size=0;
	e_arr->t_size=size;
	e_arr->op_status=INIT_SUCCESS;
	e_arr->emp=(Employee *)malloc(sizeof(Employee)*size);
	return e_arr;
}
//-----------------------------------------------------------------------------
int  insert_data(Earray *e_arr, Employee details)
{
	if(e_arr->c_size==e_arr->t_size)
	{
		e_arr->op_status=FULL;
		return FULL;
	}

	(e_arr->emp + e_arr->c_size)->id=details.id;
	strcpy(((e_arr->emp + e_arr->c_size)->name), details.name);
	(e_arr->emp + e_arr->c_size)->salary=details.salary;
	e_arr->c_size++;
	e_arr->op_status=SUCCESS;
	return SUCCESS;

}
//-------------------------------------------------------------------------------
Employee * search_by_name(Earray *e_arr,char *name)
{
	int i,flag=0,position;
	for(i=0;i<e_arr->c_size;i++)
	{
		if(!strcmp(name,(e_arr->emp + i)->name))
		{
			flag=1;
			position=i;
		}
	}
	if(flag==1)
		//if employee name is found, return searched Employee data.
		return (e_arr->emp + position); 
	else
		//Assumption: if employee name is NOT found, return FIRST Employee data.
		return (e_arr->emp ); 
}
//-------------------------------------------------------------------------------
Employee * maximum_salary(Earray *e_arr)
{
	int i,max,position=0;
	max= e_arr->emp->salary;
	for(i=0;i<e_arr->c_size;i++)
	{
		if((e_arr->emp + i)->salary > max)
		{
			max=(e_arr->emp + i)->salary;
			position=i;

		}	

	}
	return (e_arr->emp + position);
}
//-----------------------------------------------------------------------------------
Earray * deallocate(Earray * e_arr)
{
	free(e_arr->emp);
	free(e_arr);
	return NULL;
}