/* Player stuff */
#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "constants.h"

void movePlayer(char move, Element *player, Linked *l)
{
	int x = player->x, y = player->y;

	/* TODO: Make this portable */
	switch (move)
	{
		case 'h': player->x--; break;
		case 'j': player->y++; break;
		case 'k': player->y--; break;
		case 'l': player->x++; break;
		default: break;
	}
	if (boolIterate(l, player, collideElement))
	{
		player->x = x;
		player->y = y;
	}
}
