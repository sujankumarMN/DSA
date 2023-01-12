#include "stu.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

List* initialize()
{
	List* my_list;
	my_list=(List*)malloc(sizeof(List));
	if(my_list==NULL) return NULL;
	my_list->Head=my_list->Tail=NULL;
	my_list->count=0;
	my_list->status=INIT_SUCCESS;
	return my_list;
}

Node* getnode(Student stu)
{
	Node* my_node;
	my_node=(Node*)malloc(sizeof(Node));
	if(my_node==NULL) return NULL;
	my_node->Stud=(Student*)malloc(sizeof(Student));
	my_node->ptr=NULL;
	my_node->Stud->reg=stu.reg;
	strcpy(my_node->Stud->name,stu.name);
	return my_node;
}

int insert(List* my_list, Student stu)
{
	Node* my_node;
	my_node=getnode(stu);
	if(my_list->count==0)
		my_list->Head=my_list->Tail=my_node;
	else
		my_node->ptr=my_list->Head;
		my_list->Head=my_node;
		my_list->count++;
		my_list->status=INSERTED;
		//my_list->insert_count++;
		return INSERTED;
}

void display(List* my_list)
{

	Node *temp;
	printf("\n");
	for(temp=my_list->Head;temp!=NULL;temp=temp->ptr)
	{
		printf("\nreg=%d\n",temp->Stud->reg);
		printf("\nname=%s\n",temp->Stud->name);
	}
	printf("\n");
	//printf("\ninsert_count=%d\n",my_list->insert_count);
	//printf("\ndelete_count=%d\n",my_list->delete_count);
}


Node * search(List * my_list, int reg)
{
	Node * temp;
	for(temp=my_list->Head;temp->ptr!=NULL;temp=temp->ptr)
	{
		if(reg == temp->ptr->Stud->reg)
		{
			//if(!strcmp(name,temp->ptr->Stud->name))
			//printf("name:%s",temp->Stud->name);
			//printf("id:%d",temp->Stud->reg);
			//printf("\nid:%d,name:%s\n",temp->Stud->reg,temp->Stud->reg);
			return temp;
		}	
	}
	return NULL;
}
int deletee(List* my_list, int reg)
{

	Node *temp=search(my_list,reg);
	Node *extra;
	extra=temp->ptr;
	temp->ptr=temp->ptr->ptr;
	free(extra);
	my_list->count--;
	//my_list->delete_count++;
	return DELETED;
}

List* deallocate(List* my_list)
{
	Node *temp;
	temp=my_list->Head;

	while(my_list->Head!=NULL)
	{
		my_list->Head=my_list->Head->ptr;
		free(temp);
		
		temp=my_list->Head;
	}
	free(my_list);
	return NULL;
}