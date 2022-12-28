#define SUCCESS 1
#define FAILURE 0
#define UPI 10
#define CARD 11
#define CASH 12
struct _item_
{
	int item_id;
	char *item_name;
	double item_unit_price;
	int item_current_stock;

};
typedef struct _item_ Item;

struct _store_
{
	Item *items;
	int total_items;
};
typedef struct _store_ Store;

struct _bill_
{
	char *name;
	int phone_number;
	int item_id;
	char *item_name;
	double item_unit_price;
	int quantity;
	double total_price;
	int payment_mode; //UPI or CARD or CASH;
};
tupedef struct _bill_ Bill;

Store * initialisation();
int insert_items(Store *,Item);
Item * search_by_item_name(Store *,char *item_name);
int buy(char *item_name, int quantity);
void display_bill(Bill );
