#ifndef __SCREEN_H_INCLUDED__
#define __SCREEN_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "interface.h"
#include "commands.h"
#include "keys.h"

using namespace std;


/* ScrType: This will effectively control what parameters to pass to the interface.
*
*/
typedef enum
{
	MAIN_SCR = 0,
	CMD_SCR,
	ESC_SCR,
	LIST_SCR,
	EDIT_SCR,
	HELP_SCR,
	MAX_SCRS	
}ScrType_e;

const char header_arr[MAX_SCRS][100] =
{
	/*MAIN_SCR*/
	"		Welcome to the job seeker app\r\n \
		version 1.0\r\n \
		created by- Anuj C",

	/*ESC_SCR*/
	"		Quit already?\r\n \
		(y/n)"
};



/*CScreen: The class that contains all the screen info
*
*/
class CScreen : public CIface 
{
public:
	CScreen();
	CScreen(ScrType_e type, int height, int width, int starty, int startx);
	~CScreen();

	WINDOW* GetWindo(void);		//Return scr_win pointer for use.
	int GetMaxY(void);			//Maximum allowed column for the window.
	int GetMaxX(void);			//Maximum allowed row for the window.

	int GetInitY(void);			//The starting/ initial y position of screen.
	int GetInitX(void);			//The starting/ initial x position of screen.

private:
	ScrType_e curr_scr;	/*Know which kind of screen it is.
	 	 	 	 	 	In future set all the init parameters just by checking the type.*/
	WINDOW* scr_win;	//The associated ncurses window with this screen.
	CCmdMenu* scr_menu;	//The command menu related with a particular screen.
	CKeyIn* scr_keys;	//Key input params associated with this screen.

	int scr_height;		//Screen height
	int scr_width;		//Screen width
	int max_y;			//max vertical position of cursor. max_y <= scr_height
	int max_x;			//max horizontal position of cursor. max_x <= scr_width
	int init_y;			//The starting cursor y position for this screen.
	int init_x;			//The starting cursor x position for this screen.
	int curr_y;			//Current y position of cursor.
	int curr_x;			//Current x position of cursor.



		

};




#endif /* __INTERFACE_H_INCLUDED__ */
