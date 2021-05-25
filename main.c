/* Gaming */
#include "headers.h"

/* Should be put elsewhere */
#define PLAYER_FLAGS A_BOLD

void adjust(Element *e);
void health();
int setup();


int main(int argc, char **argv)
{
	/* int x, y; */ /* Arbitrary for loop indicies */
	Element e = clearElement(), *gg;	
	char inp = '\0';	
	Linked *list = makeLinked(), *list2 = makeLinked();
	Wall *wall;

	Point p;
	if (argc > 1)
	{
		printf("usage: %s\n", argv[0]);
		return -1;
	}
	if (!setup())
		return -1;
	/* Header thingy that kinda sucks rn but we'll fix it */
	/*
	printHeader();
	getch();
	*/
	curs_set(0);
	setVis(&e, '?');
	
	p.x = 10;
	p.y = 11;
	INSERT(list2, p);
	p.x = 11;
	INSERT(list2, p);

	wall = makeWall(5, 2, 10, 1, '-');

	insert(list, wall->data);
	insert(list, makeWall(5, 9, 10, 1, '-')->data);
	insert(list, makeWall(4, 2, 1, 8, '|')->data);
	insert(list, makeWall(15, 2, 1, 8, '|')->data);

	gg = addElementTo(list, 6, 5);
	if (gg) setVis(gg, 'X');
	
	e.vis[0][0] = '/';
	e.vis[0][1] = '\\';
	e.vis[1][0] = '\\';
	e.vis[1][1] = '/';
	start_color();
	
	/* 40, 254, 20 */
	init_color(GREEN, 156, 996, 78);	
	init_color(RED, 0, 0, 1000);	
	init_pair(HIGHLIGHT, RED, COLOR_BLACK);
	init_pair(STANDARD, GREEN, COLOR_BLACK);
	color_set(HIGHLIGHT, NULL);
	do
	{
		erase();
		move(0, 0);
		
		printw("HP: ?/?\nEnergy: ??%\n");
		movePlayer(inp, &e, list);
			
		/* Display Player */
		displayFlagsColorblind(&e, PLAYER_FLAGS);		
		iterate(list, display);
		iterate(list2, drawBlank);
		move(2, 0);
		printw("%.2X %.2X", e.x, e.y);
		
		/* Refresh the screen and stuff */
		refresh();
	} while ((inp = getch()) != 'q');
	endwin();
	return 0;
}

int setup()
{
	int value = 0;	
	if (initscr() != NULL)
		value = noecho() | cbreak();
	return !value;
}

void health()
{
	attron(COLOR_PAIR(HIGHLIGHT));
	move(0, 4);
	addch('5');
	move(0, 6);
	addch('5');
	attroff(COLOR_PAIR(HIGHLIGHT));
}
