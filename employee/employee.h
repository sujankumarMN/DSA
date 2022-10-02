#define FAIL 0
#define INIT_SUCCESS 1
#define SUCCESS 2
#define FULL 3
#define NAME_SIZE 10

struct _employee_
{
	int id;
	char name[NAME_SIZE];
	float salary;
};
typedef struct _employee_ Employee;

struct _employee_array_
{
	Employee *emp;
	int c_size,t_size,op_status;
};
typedef struct _employee_array_ Earray;

Earray * initialise(int size);
int insert_data(Earray *, Employee);
Employee * search_by_name(Earray *, char*);
Employee * maximum_salary(Earray *);
Earray * deallocate(Earray *);