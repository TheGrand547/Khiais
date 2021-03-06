/* Output for trivial things */
#include <ncurses.h>
#include "output.h"
#include "structs.h"

int display(Element *e)
{
	if (e == NULL)
		return -1;
	/* 5, 3, and 1 are placeholders while I figure out 
	 * what's going on */
	mvaddch(5 + e->y, e->x * 3 + 1, e->vis);	
	return 0;
}
