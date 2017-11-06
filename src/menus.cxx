//Functionality of the menu class

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "../inc/commands.h"
#include "../inc/menus.h"
#include "../inc/style.h"
#include "../inc/sys.h"
#include "../inc/keys.h"

using namespace std;

//////////////////////////////Class functions//////////////////////////////
CMenu::CMenu(void)
{
	menu = NULL;
	curr_item = NULL;
	pos = LIST_EMPTY;
	list_len = DEF_MENU_LEN;
	item_list = (ITEM **)calloc(list_len +1, sizeof(ITEM *));
}
CMenu::CMenu(int len)
{
	menu = NULL;
	curr_item = NULL;
	item_list = NULL;
	pos = LIST_EMPTY;
	list_len = len;
	item_list = (ITEM **)calloc(list_len +1, sizeof(ITEM *));
}

CMenu::~CMenu(void)
{
	int i;
	for (i = 0; i <= list_len; i++) {
		if (item_list[i]) {
			free_item(item_list[i]);
//			free(item_list[i]);
		}
	}
	//free(item_list);
	if (menu != NULL) {
		free_menu(menu);
	}
}


int CMenu::AddItem(char* text, void* data)
{
	int ret_val = -1;
	++pos;
	if (pos < list_len)
	{
		//item_list[pos].index = pos;	//Check if menu init automtically assigns an index
		item_list[pos] = new_item(text, "");
		ret_val = 0;

		if (data) {
			item_list[pos]->userptr = data;
		}
	}
	else {
		cout <<"ERROR: list items exceed max allowed" <<endl;	//ERROR_MSG
	}
	return ret_val;
}

int CMenu::CreatMenu(void)
{
	int ret_val = -1;
	if (pos >= 0) {
		menu = new_menu(item_list);
		ret_val = 0;
	}

	return ret_val;
}

int CMenu::ShowMenu(void)
{
	post_menu(menu);
	return 0;
}

int CMenu::RemoveMenu(void)
{
	unpost_menu(menu);
	return 0;
}

//////////////////////////////Get-Set functions//////////////////////////////
ITEM* CMenu::GetCurrItem(void)
{
	curr_item = current_item(menu);
	return curr_item;
}

MENU* CMenu::GetMenu(void)
{
	return menu;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
