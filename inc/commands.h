//Just mention the commands here?

#ifndef __COMMANDS_H_INCLUDED__
#define __COMMANDS_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <ncurses.h>
#include "../inc/menus.h"

//////////////////////////////Size macros//////////////////////////////
#define MAX_CMDS 15
#define CMD_TXT_LEN 7

using namespace std;

/*Enumtype to toggle the bitmask for bottom- avail bar 
and also to track the state of program.
*/
typedef enum
{
	NO_CMD = 0,
	ESCP,
	HELP,
	LIST,
	ADDE,
	DELE,
	EDIT,
	SAVE,
	NEXT,
	PREV,
	CMDS,
	QUIT
}
CmdBits_e;

//Commands array to compare with the input.
const char ALLWD_CMDS[MAX_CMDS][CMD_TXT_LEN] = {"NO_CMD", "ESCP", "HELP", "LIST", "ADDE", "DELE", "EDIT", "SAVE", "NEXT", "PREV", "CMDS", "QUIT", "\0"};


/*CCmdMenu: Menu for the input commands
*
*/
class CCmdMenu : public CMenu
{
public:
	CCmdMenu(void);
	CCmdMenu(int len, int mask);				//The mask of allowed items.
	CCmdMenu(WINDOW* windo, int len, CmdBits_e arr[]);		//The array list must be ended with the enum value 'NO_CMD' for recognising end of array.
	~CCmdMenu(void);

	/*TODO*/void FillCmds(int mask);					//Populate the command array from provide command mask.
	void FillCmds(CmdBits_e cmd_arr[]);		//Populate the command array from the CmdBits_e array.
	//////////////////////////////Get-Set functions//////////////////////////////
	void SetCurrCmd(int cmd);	//Set the currently selected command.
	int GetCurrCmd(void);		//Return the currently selected command.

private:
	int curr_cmd;			//Stores the currently selected item from the menu.
	int menu_width;
	int menu_height;
	WINDOW* menu_win;		//The asociated window with this menu.
};

#endif /* __COMMANDS_H_INCLUDED__ */
