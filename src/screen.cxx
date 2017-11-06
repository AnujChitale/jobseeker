//Functionality of the screen

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../inc/screen.h"


using namespace std;

CScreen::CScreen(void)
{
	scr_win = NULL;
	scr_menu = NULL;
	scr_keys = NULL;
}

CScreen::CScreen(ScrType_e type, int height, int width, int starty, int startx)
{
	scr_menu = NULL;
	scr_keys = NULL;

	curr_scr = type;
	scr_height = height;
	scr_width = width;
	init_y = starty;
	init_x = startx;
	curr_y = starty;
	curr_x = startx;
	max_y = starty + scr_height;
	max_x = startx + scr_width;
	scr_win = newwin(scr_height, scr_width, init_y, init_x);
	getmaxyx(scr_win, max_y, max_x);
}

CScreen::~CScreen()
{
	if (scr_win != NULL) {
		delwin(scr_win);
	}
}

WINDOW* CScreen::GetWindo(void)
{
	return scr_win;
}

int CScreen::GetMaxY(void)
{
	return max_y;
}

int CScreen::GetMaxX(void)
{
	return max_x;
}

int CScreen::GetInitY(void)
{
	return init_y;
}

int CScreen::GetInitX(void)
{
	return init_x;
}


// void CScreen::DispHeader(void)
// {
// 	int i;
// 	fputs(header_arr[MAIN_SCR], stdout);
// 	cout <<endl;
// 	for (i=0; i< 30; i++)
// 	{
// 		fputs("\r\n", stdout);
// 	}
// }
















