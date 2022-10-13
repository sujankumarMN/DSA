#include<stdio.h>
#include<stdlib.h>
#include "header.h"

Kantara * init()
{
	Kantara *kan;
	kan=(Kantara *)malloc(sizeof(Kantara));
	if(NULL==kan) return NULL;
	kan->c_size=0;
	kan->t_size=TOTAL_SCREENS;
	kan->screen=(Screen *)malloc(sizeof(Screen)*TOTAL_SCREENS);

	//screen1 initialisation
	kan->screen->num=1;
	kan->screen->seat=1;
	kan->screen->vip=30;
	kan->screen->gold=80;
	kan->screen->silver=40;
	kan->screen->total=150;
	kan->screen->status=AVAILABLE;

	//screen 2 initialisation
	(kan->screen+1)->num=2;
	(kan->screen+1)->seat=1;
	(kan->screen+1)->vip=20;
	(kan->screen+1)->gold=60;
	(kan->screen+1)->silver=40;
	(kan->screen+1)->total=120;
	(kan->screen+1)->status=AVAILABLE;

	//screen 3 initialisation
	(kan->screen+2)->num=3;
	(kan->screen+2)->seat=1;
	(kan->screen+2)->vip=20;
	(kan->screen+2)->gold=60;
	(kan->screen+2)->silver=40;
	(kan->screen+2)->total=120;
	(kan->screen+2)->status=AVAILABLE;
	return kan;
}
//----------------------------------------------------------------------
void screen_details(Kantara *kan,int screen_no)
{
	
	if(screen_no<1 && screen_no>3)
		printf("\n SCREEN NOT FOUND!!!! \n" );
	printf("\n ---------------------------------\n" );

	if(screen_no==1)
	{
		printf("SCREEN NUMBER: %d \n",kan->screen->num);
		printf("TOTAL SEATS AVAILABLE: %d \n",(kan->screen)->total);
		printf("VIP CLASS: %d \n",kan->screen->vip);
		printf("GOLD CLASS: %d \n",kan->screen->gold);
		printf("SILVER CLASS: %d \n",kan->screen->silver);

	}

	if(screen_no==2)
	{
		printf("SCREEN NUMBER: %d\n",(kan->screen+1)->num);
		printf("TOTAL SEATS AVAILABLE: %d \n",(kan->screen+1)->total);
		printf("VIP CLASS: %d \n",(kan->screen+1)->vip);
		printf("GOLD CLASS: %d \n",(kan->screen+1)->gold);
		printf("SILVER CLASS: %d \n",(kan->screen+1)->silver);

	}

	if(screen_no==3)
	{
		printf("SCREEN NUMBER: %d \n",(kan->screen+2)->num);
		printf("TOTAL SEATS AVAILABLE: %d \n",(kan->screen+2)->total);
		printf("VIP CLASS: %d \n",(kan->screen+2)->vip);
		printf("GOLD CLASS: %d \n",(kan->screen+2)->gold);
		printf("SILVER CLASS: %d \n",(kan->screen+2)->silver);

	}
	printf("\n ---------------------------------\n" );
}
//------------------------------------------------------------------------------------
Kantara * book_now()
{
	int screen_no,class,tickets;
	Kantara *kan;
	printf("screen num:\n");
	scanf("%d",&screen_no);

	printf("class:\n");
	scanf("%d",&class);

	printf("tickets:\n");
	scanf("%d",&tickets);

	//printf("%d %d %d",screen_no,class,tickets);

	//kan=screen1(screen_no,class,tickets);
	return kan;
}

	
Kantara * buy(int screen_no,char class,int tickets)
{
	Kantara *kan;
	int i,n;
	
	n=screen_no-1;
	switch(class)
			{
				case 'v': 
					if(tickets > (kan->screen+n)->vip)
					{
						printf("seats not available\n");
						return kan;
					}
					else
					{
						(kan->screen+n)->vip = ((kan->screen+n)->vip)-tickets;
						(kan->screen+n)->total = ((kan->screen+n)->total)-tickets;
						printf("\n%d Tickets booked successfully.\n ",tickets);
						for(i=0;i<tickets;i++)
							printf("seat  no:%d\n ", (kan->screen+n)->seat++);
						return kan;			
					} 
				case 'g': 
					if(tickets > (kan->screen+n)->vip)
					{
						printf("seats not available\n");
						return kan;
					}
					else
					{
						(kan->screen+n)->gold = ((kan->screen+n)->gold)-tickets;
						(kan->screen+n)->total = ((kan->screen+n)->total)-tickets;
						printf("\n%d Tickets booked successfully.\n ",tickets);
						for(i=0;i<tickets;i++)
							printf("seat  no:%d\n ", (kan->screen+n)->seat++);
						return kan;			
					} 
				case 's': 
					if(tickets > (kan->screen+n)->vip)
					{
						printf("seats not available\n");
						return kan;
					}
					else
					{
						(kan->screen+n)->silver = ((kan->screen+n)->silver)-tickets;
						(kan->screen+n)->total = ((kan->screen+n)->total)-tickets;
						printf("\n%d Tickets booked successfully.\n ",tickets);
						for(i=0;i<tickets;i++)
							printf("seat  no:%d\n ", (kan->screen+n)->seat++);
						return kan;			
					} 		
				
			}

}

Kantara * deallocate(Kantara *kan)
{

	free(kan->screen);
	free(kan);
	return NULL;
}

			
					
					
