#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__

/* If using the ncurses library, use the menu library as well.
 *
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <menu.h>
#include <form.h>

#include "../inc/sizes.h"
#include "../inc/keys.h"

#define DEF_MENU_LEN 2
#define LIST_EMPTY -1
#define MAX_ITEM_TXT 20



//////////////////////////////Class definitions//////////////////////////////

/*CMenu: Responsible for menu display functionality and detecting defined key presses.
*
*/
class CMenu
{
public:
	CMenu(void);		//Use the default number of menu items.
	CMenu(int len);		//Declare the number of menu items to be used.
	~CMenu(void);

	int AddItem(char* text, void* data);	//Add a new item to the menu
	int CreatMenu(void);					//Creates menu only if atleast one item added.
	int ShowMenu(void);						//Display the menu
	int RemoveMenu(void);						//Remove menu from display.

	//////////////////////////////Get-Set functions//////////////////////////////
	ITEM* GetCurrItem(void);			//Return the currently selected ITEM.
	void SetCurrItembyId(int id);		//Set the current menu item by passing it's index.	//TODO
	MENU* GetMenu(void);				//Return the Menu pointer

//TODO Do we need private members for this base class?
protected:
	ITEM** item_list;		//Pointer to the array of menu items.
	MENU* menu;				//the menu pointer associated with this
	ITEM* curr_item;		//The integer corresponding to the currently selected item.
	int list_len;			//number of menu items
	int pos;				//Keep track of how many list items are filled.
};



#endif /* __MENU_H_INCLUDED__ */
