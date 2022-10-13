#include<stdlib.h>
#include<assert.h>
#include "header.h"
int main()
{
	Kantara *kanta;
	kanta=init();
	assert(kanta->t_size==3);
	assert(kanta->screen->gold==80);
	assert((kanta->screen+1)->total==120);
	assert((kanta->screen+2)->num==3);

	//displaying the screen 1 details
	screen_details(kanta,1);	
	
	//here for buy() function input arguments are screen number,class,number of tickets respectively.
	//v=vip , g=gold, s=silver 

	kanta=buy(3,'s',5); //trying to book 5 tickets in Screen 3 for silver class
	screen_details(kanta,3); //checking the availabily of screen 3;
	kanta=buy(3,'s',5);
	screen_details(kanta,3);

	kanta=buy(2,'v',31);
	screen_details(kanta,2);
	kanta=buy(2,'v',20);
	screen_details(kanta,2);

	kanta=deallocate(kanta);


}