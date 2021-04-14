/* Player stuff */
#include <stdlib.h>
#include <ncurses.h>
#include "player.h"

static int collisionCheck(void *data, void *data2)
{
	int result = 0;
	Element *e, *p;
	if (data && data2)
	{
		e = (Element*) data;
		p = (Element*) data2;
		result = (e->x == p->x) && (e->y == p->y);

	}
	return result;
}

void movePlayer(char move, Element *player, Linked *l)
{
	int x = player->x, y = player->y;
	
	switch (move)
	{
		case 'h': player->x--; break;
		case 'j': player->y++; break;
		case 'k': player->y--; break;
		case 'l': player->x++; break;
		default: break;
	}
	if (boolIterate(l, player, collisionCheck))
	{
		player->x = x;
		player->y = y;
	}
}
