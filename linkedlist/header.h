#define INIT_SUCCESS 1
#define INSERTED 2
#define DELETED -2
#define FAIL 10

typedef struct _node_ Node;
struct _node_
{
	int data;
	Node *ptr;
};

typedef struct _linkedlist_ List;
struct _linkedlist_
{
	Node *head;
	Node *tail;
	int count;
	int status;
};

List * initialise();
Node * getnode(int);
void list_display(List *);

int insert_at_beg(List *, int);
int insert_at_end(List *, int);
int insert_after_element(List *, int,int);
int insertion_sort(List *, int);

Node * search(List *,int);

int delete_at_beg(List *);
int delete_at_end(List *);
int delete_element(List *, int);

List * deallocate(List *);

