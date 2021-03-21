/* Player stuff */
#include <stdlib.h>
#include <ncurses.h>
#include "player.h"

void movePlayer(char move, Element *player)
{
	Element *next = player->next;		
	int x = player->x, y = player->y;
	
	switch (move)
	{
		case 'h': player->x--; break;
		case 'j': player->y++; break;
		case 'k': player->y--; break;
		case 'l': player->x++; break;
		default: break;
	}
	if (player->x == x && player->y == y) return;
	while (next != NULL)
	{
		if (player->x == next->x && player->y == next->y)
		{
			player->x = x;
			player->y = y;
			break;
		}
		next = next->next;
	}
}
