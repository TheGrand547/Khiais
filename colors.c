/* colors.c */
#include "colors.h"

/* Macro thingy for compact color definition */
#define INIT_COLOR(c) init_color(c, c ## _R, c ## _G, c ## _B)
#define INIT_PAIR(p) init_pair(p, p ## _FG, p ## _BG)

void colorSetup()
{
	if (start_color() != ERR)
	{
		/* Initialize colors */
		INIT_COLOR(GREEN);
		INIT_COLOR(RED);
		/* Initialize color pairs */		
		INIT_PAIR(STANDARD);
		INIT_PAIR(HIGHLIGHT);
	}
}

#undef INIT_COLOR
#undef INIT_PAIR
