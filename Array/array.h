
#define MAX_SIZE 20
#define SUCCESS 1
#define FULL 0
#define INIT_SUCCESS 2

typedef struct _array_ Array;


struct _array_
{
    int arr[MAX_SIZE];
    int c_size, t_size;
    int op_status;
};

Array initialise_array(int size);
Array insert_data(Array, int data);
int search_element(Array, int element);

int find_max(Array);
int find_min_max(Array, int *, int *); // pass address of max and min
int find_sum_of_array(Array);
int count_number_of_prime_numbers(Array);
int is_palindrome(Array);

