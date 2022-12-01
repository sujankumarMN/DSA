#define INSERTED 1
#define DELETED -1
#define FAILED -2


typedef struct _node_ Node;
struct _node_
{
	int data;
	Node *ptr;
};


typedef struct _list_ List;
struct _list_
{
	Node *front,*rear;
	int count;
};

List * init();
Node * getnode(int);
int enqueue(List *,int);
int dequeue(List *);
void display(List *);
List * deallocate(List *);
