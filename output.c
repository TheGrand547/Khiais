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

void displayElements(Element *e)
{
	if (e == NULL) return;
	display(e);
	while ((e = e->next)) display(e);
}

void emptyRectangle(unsigned int x, unsigned int y, 
			unsigned int width, unsigned int height, char display)
{
	int i, j;	
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
		{
			move(i + VERTICAL_OFFSET + y, j + HORIZONTAL_OFFSET + x);
			if (!i | !j | i == height - 1 | j == width - 1)
				addch(display);
		}
}


void emptyCircle(unsigned int x, unsigned int y, unsigned int radius, char display)
{
	int i, j;
	int product = radius * radius;
	for (i = 0; i <= 2 * radius; i++)
		for (j = 0; j <= 2 * radius; j++)
		{
			int dist = (i - radius) * (i - radius) + (j - radius) * (j - radius);			
			move(i + VERTICAL_OFFSET + y, j + HORIZONTAL_OFFSET + x);
			if (dist <= product)
			{
				addch(display);
			}
		}
}
