/* Output for trivial things */
#include <ncurses.h>
#include "output.h"
#include "structs.h"
#include "constants.h"

int display(Element *e)
{
	if (e == NULL)
		return -1;
	
	mvaddch(e->y + VERTICAL_OFFSET, e->x + HORIZONTAL_OFFSET, e->vis);	
	return 0;
}

void blankBoard()
{
	int i, j;
	for (i = 0; i < HEIGHT; i++)
	{
		move(i + VERTICAL_OFFSET, HORIZONTAL_OFFSET);
		for (j = 0; j < WIDTH; j++)
			printw("~");
	}
}
