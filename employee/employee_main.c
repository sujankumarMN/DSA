#include<stdio.h>
#include<string.h>
#include<assert.h>
#include "employee.h"

int main()
{
	Earray *e_array;
	Employee details;
	Employee *empl;
	int state;

	//initialising employee array size to be 5
	e_array=initialise(5);
	assert(e_array->t_size==5);
	assert(e_array->op_status==INIT_SUCCESS);

	//Inserting 1st data
	details.id=1001;
	char name[]="RAJU";
	strcpy(details.name,name);
	details.salary=25000;
	state=insert_data(e_array,details);
	assert(e_array->op_status==SUCCESS);
	
	//Inserting 2nd data
	details.id=1002;
	strcpy(details.name,"RED");
	details.salary=25980;
	assert(insert_data(e_array,details)==SUCCESS);

	//Inserting 3rd data
	details.id=1003;
	strcpy(details.name,"BLACK");
	details.salary=30177.25;
	assert(insert_data(e_array,details)==SUCCESS);

	//Inserting 4th data
	details.id=1004;
	strcpy(details.name,"BLUE");
	details.salary=30178.25;
	assert(insert_data(e_array,details)==SUCCESS);

	//Inserting 5th data
	details.id=1005;
	strcpy(details.name,"PINK");
	details.salary=24220;
	assert(insert_data(e_array,details)==SUCCESS);

	//Trying to insert 6th data
	details.id=1006;
	strcpy(details.name,"YELLOW");
	details.salary=30177.251;
	assert(insert_data(e_array,details)==FULL); //Unable to insert any more data as status = FULL
	assert((e_array->emp + e_array->c_size - 1)->id==1005); //Latest data is 5th inserted data
	assert((e_array->emp +2)->id==1003);
	assert(!strcmp((e_array->emp+4)->name,"PINK"));
	
	//Searching employee array with a employee name. 
	//1.If found -> return the employee data of the searched employee
	//2.If NOT found -> return the employee data of the first employee
	empl = search_by_name(e_array,"BLACK");
	assert(empl->id==1003);
	assert(!strcmp(empl->name,"BLACK"));
	assert(empl->salary==30177.25);

	empl = search_by_name(e_array,"YELLOW");
	assert(empl->id==1001);
	assert(!strcmp(empl->name,"RAJU"));
	assert(empl->salary==25000);

	//Searching the employee with maxiu=mum salary and it returns the employee data of thr employee with highest salary 
	empl = maximum_salary(e_array);
	assert(empl->id==1004);
	assert(!strcmp(empl->name,"BLUE"));
	assert(empl->salary==30178.25);
	
	printf("%p\n",e_array->emp); //Address before memory deallocation
	e_array=deallocate(e_array);
	printf("%p\n",e_array->emp);//Address after deallocation - ENDS UP WITH A SEGMENTATION FAULT
}