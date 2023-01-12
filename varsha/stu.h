#define INSERTED 1
#define DELETED 0
#define FAIL -1
#define INIT_SUCCESS 2

typedef struct _student_ 
{
	int reg;
	char name[50];
}Student;

typedef struct _node_ Node;
struct _node_
{
	Student *Stud;
	Node *ptr;
};
struct _tra_
{
	int type_of_operation;
	char transaction_time[10];
	char transaction_date[10];
};
typedef struct _tra_ Tra;

typedef struct _nodee_ Nodee;
struct _nodee_
{
	Tra *trans;
	Node *ptr;
};

struct _linked_
{
	Node *Head;
	Node *Tail;
	Nodee *head;
	Nodee *tail;
	int count;
	int status;
	int insert_count;
	int delete_count;
};
typedef struct _linked_ List;

List* initialize();
Node* getnode(Student);
int insert(List*,Student);
void display(List*);
Node* search(List*,int reg);
int deletee(List*,int reg);
List* deallocate(List*);
