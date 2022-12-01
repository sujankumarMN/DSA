
typedef struct _node_ Node;
struct _node_
{
	int data;
	Node * ptr;
};

typedef struct _stack_ Stack;
struct _stack_
{
	Node *top;
	int count;
};

Stack * init();
Node * getnode(int n);
int push(Stack *,int);
int pop(Stack *);
int peek(Stack *);
int search(Stack *,int);
void display(Stack *);


