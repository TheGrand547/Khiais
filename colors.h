/* colors.h */
#ifndef COLORS_H
#define COLORS_H
#include <curses.h>
#include "debug.h"

/* Color Name Declarations */
#define RED 10
#define GREEN 11

/* Color Value Definitions */
/* Basic Green */
#define GREEN_R 156
#define GREEN_G 996
#define GREEN_B 1000

/* Basic Red */
#define RED_R 1000
#define RED_G 0
#define RED_B 0 

/* Color Pair Name Definitions */
#define STANDARD 2 
#define HIGHLIGHT 3 

/* Color Pair Color Definitions */
/* Standard Pair */
#define STANDARD_FG GREEN 
#define STANDARD_BG COLOR_BLACK

/* Pair for highlighted information */
#define HIGHLIGHT_FG RED
#define HIGHLIGHT_BG COLOR_BLACK

void colorSetup();
#endif

