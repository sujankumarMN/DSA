#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stu.h"
#include<assert.h>

int main()
{
	List*list;
	Student stu;
	Node*node;
	list=initialize();
	assert(list->status==INIT_SUCCESS);
	//insert
	stu.reg=1;
	//char name[50]="varsha";
	strcpy(stu.name,"varsha");
	assert(insert(list,stu)==1);
	stu.reg=2;
	strcpy(stu.name,"sujan");
	//strcpy(stu.name,name);
	assert(insert(list,stu)==1);
	stu.reg=3;
	strcpy(stu.name,"vishruth");
	//strcpy(stu.name,name);
	assert(insert(list,stu)==1);
	stu.reg=4;
	strcpy(stu.name,"manasa");
	//strcpy(stu.name,name);
	assert(insert(list,stu)==1);
	stu.reg=5;
	strcpy(stu.name,"omg");
	//strcpy(stu.name,name);
	assert(insert(list,stu)==1);
	assert(list->count==5);
	display(list);
	node=search(list,3);
//printf("name:%s",node->Stud->name);
	printf("\n%d,%s\n",node->Stud->reg,node->Stud->name);

	//assert(deletee(list,stu)==0);

	assert(deletee(list,3)==0);
	display(list);
	list=deallocate(list);

}