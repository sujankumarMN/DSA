#define MAXSIZE 10



struct _stack_
{
	int arr[MAXSIZE];
	int top,t_size;
};
typedef struct _stack_ Stack;


Stack init(int);
void push(Stack *,int);
Stack pop(Stack);
int peek(Stack);

