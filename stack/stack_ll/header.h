#define INIT_SUCCESS 1
#define SUCCESS 2
#define FAILURE -2



struct _data_
{
	int n,pos,insert,active;
};
typedef struct _data_ Data;

typedef struct _node_ Node;
struct _node_
{
	Data *ele;
	Node *ptr;
};

typedef struct _list_ List;
struct _list_
{
	Node *head;
	Node *tail;
	int count;
	int status;
};

List * init();
Node * getnode(int);

int insert_at_end(List *,int);
int insert_at_beg(List *,int);
int insert_at_pos(List *,int,int);

int delete_at_end(List *);
int delete_at_beg(List *);

void update_pos_insert(List *,int);
void update_pos_delete(List *,int);
void display(List *);
List * dealloc(List *);


