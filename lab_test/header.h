#define TOTAL_SCREENS 3
#define AVAILABLE 1
#define HOUSEFULL -1


struct _screen_
{
	int num,seat,vip,gold,silver,total,status;
};
typedef struct _screen_ Screen;

struct _kantara_
{
	Screen *screen;
	int c_size,t_size;
};
typedef struct _kantara_ Kantara;

Kantara * init();
void screen_details(Kantara *, int);
Kantara * book_now();
Kantara * buy(int,char ,int);
Kantara * deallocate(Kantara *);
