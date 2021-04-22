/* Gaming */
#include "headers.h"

/* Should be put elsewhere */
#define PLAYER_FLAGS A_BOLD

void adjust(Element *e);
int setup();

int main(int argc, char **argv)
{
	int x, y; /* Arbitrary for loop indicies */
	Element e = clearElement(), *gg;	
	char inp = '\0';	

	Linked list;
	Wall *wall;
	
	if (!setup())
		return -1;
	/* Header thingy that kinda sucks rn but we'll fix it */
	/*
	printHeader();
	getch();
	*/
	curs_set(0);
	e.vis = '?';

	wall = calloc(1, sizeof(Wall));
	wall->data = &e; 
	wall->width = 10;
	wall->height = 1;

	list.head = NULL;
	list.tail = NULL;

	for (x = 0; x < 10; x++)
		for (y = 0; y < 10; y++)
			addElementTo(&list, 6 + y, 10 + x);	
	
	gg = addElementTo(&list, 10, 5);
	if (gg) gg->vis = 'X';

	do
	{
		move(0, 0);
		/* Buffer for status effects and such */
		printw("Welcome to epic gamin inc.\n");
		blankBoard();
		movePlayer(inp, &e, &list);
		/* this is kinda cringe */	
		adjust(&e);
		/* Display Player */
		displayFlags(&e, PLAYER_FLAGS);		
		iterate(&list, display);
		displayWall(wall);

		emptyRectangle(5, 5, 5, 5, '!');
		
		/* Refresh the screen and stuff */
		refresh();
	} while ((inp = getch()) != 'q');
	endwin();
	return 0;
}

void adjust(Element *e)
{
	if (!e) return;
	if (e->x == UINT_MAX) e->x = WIDTH - 1;
	if (e->x == WIDTH) e->x = 0;
	if (e->y == UINT_MAX) e->y = HEIGHT - 1;
	if (e->y == HEIGHT) e->y = 0;
}

int setup()
{
	int value = 0;	
	if (initscr() != NULL)
		value = noecho() | cbreak();
	return !value;
}
