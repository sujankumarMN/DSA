#define INIT_SUCCESS 1
#define SUCCESS 2
typedef struct _node_ Node;
struct _node_
{
	int data;
	Node *ptr;
	int is_insert;
};

typedef struct _list_ List;
struct _list_
{
	Node *head,*tail;
	int count,status;
};

List * init();
Node * getnode(int );
int insert_at_end(List *, int, List *);
int delete_at_beg(List *,List *);
int insert_at_beg(List *,int ,List *);
int delete_at_end(List *,List *);

int delete_at_end_undo(List *my_list);
int insert_at_beg_undo(List *my_list,int n);



int push(List *, int);
Node * pop(List *);

void undo(List *,List *);
void display(List *);