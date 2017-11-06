//Functions related to the text styling

#ifndef __STYLE_H_INCLUDED__
#define __STYLE_H_INCLUDED__

#include <iostream>
#include <stdio.h>

#include "../inc/sizes.h"

/********************Standard terminal related********************/
void offset_col(int col);		//Enter the column offset for cursor placement.
void offset_row(int row);		//Enter the row offset for cursor placement.

/********************Window related********************/
void border_win(WINDOW* windo, int y, int x);

/********************Screen related********************/
void nextline(WINDOW* windo);	//Jump the cursor to next row/line with same column
void nextcol(WINDOW* windo);	//Jump to next column in the same row/line


#endif /* __STYLE_H_INCLUDED__ */
