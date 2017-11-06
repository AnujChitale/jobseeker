//Functions for the styling 
//TODO- shouldn't these be included within a class?

#include <iostream>
#include <stdio.h>
#include <ncurses.h>

#include "style.h"


using namespace std;

/********************Standard terminal related********************/
void offset_col(int col)
{
	int i;

	for (i= col;i> 0;i--)
	{
		fputs(" ", stdout);
	}
}

void offset_row(int row)
{
	int i;

	for (i= row;i> 0;i--)
	{
		fputs("\n", stdout);
		//cout <<"\n" <<endl;
	}
}

/********************Window related********************/
void border_win(WINDOW* windo, int y, int x)
{
	box(windo, y, x);
}

void nextline(WINDOW* windo)
{
	int x,y;
	getyx(windo, y , x);
	wmove(windo, y+1, x);
}

void nextcol(WINDOW* windo)
{
	int x,y;
	getyx(windo, y, x);
	wmove(windo, y, x+1);
}

/********************Screen related********************/
