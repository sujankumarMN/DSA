#define MAXSIZE 10

struct _arraycontent_
{
	int data;
	int pos;
	int insert;
};
typedef struct _array_ A_content;

struct _array_
{
	
}

struct _stack_
{
	Array arr[MAXSIZE];
	int top,t_size;
};
typedef struct _stack_ Stack;


Stack init(int);
Stack push(Stack,int);
Stack pop(Stack);
int peek(Stack);

Array insert_at_beg(Array, int data);