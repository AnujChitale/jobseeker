//Functionality of program commands

#include <iostream>
#include <stdio.h>
#include <ncurses.h>
#include "commands.h"
#include "menus.h"
#include "style.h"
#include "sys.h"
#include "keys.h"

using namespace std;

//////////////////////////////Class functions//////////////////////////////
CCmdMenu::CCmdMenu(void) : CMenu()	//The default constructor will store nothing, resulting in a blank display.
{	
	;
}

CCmdMenu::CCmdMenu(int len, int mask) : CMenu(len)
{

	FillCmds(mask);
}

CCmdMenu::CCmdMenu(WINDOW* windo, int len, CmdBits_e arr[]) : CMenu(len)
{
	menu_win = windo;
	FillCmds(arr);		//Add all the passed commands as new items.
	CreatMenu();		//Menu from the items.
	//CMD_TXT_LEN
	
}

CCmdMenu::~CCmdMenu(void)
{
	if (menu_win != NULL) {
		menu_win = NULL;
	}
}

//TODO
void CCmdMenu::FillCmds(int mask)
{
	int i;

	for (i=1; i<(MAX_CMDS-1); i++)
	{
		if (mask & (BIT << i))
			{
				;
			}
		else {
			;			
		}
	}
}
void CCmdMenu::FillCmds(CmdBits_e cmd_arr[])
{
	int i;
	CmdBits_e tmp_cmd;

	//SetCurrCmd(0);

	for (i=0; cmd_arr[i] && i< list_len; i++)
	{
		tmp_cmd = cmd_arr[i];
		AddItem((char*)ALLWD_CMDS[tmp_cmd], NULL);
	}
}

//////////////////////////////Get-Set functions//////////////////////////////
void CCmdMenu::SetCurrCmd(int cmd)
{
	curr_cmd = cmd;
}

int CCmdMenu::GetCurrCmd(void)
{
	return curr_cmd;
}
