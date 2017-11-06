//Functionality related to keyboard keys

#include <iostream>
#include <stdio.h>
#include <ncurses.h>

#include "commands.h"
#include "sys.h"
#include "keys.h"
#include "sizes.h"


using namespace std;

CKeyIn::CKeyIn()
{
	allwd_keys = NULL;
	key_windo = NULL;
}

CKeyIn::CKeyIn(WINDOW* val_windo, int len, KeyMap_e* val_keys)
{
	int i;
	allwd_keys = NULL;

	key_windo = val_windo;
	val_len = len;
//	i = sizeof(val_keys)/sizeof(KeyMap_e);
//	val_len = i;
	allwd_keys = new KeyMap_e[val_len];

	//KeyMap_e* tmp_arr = allwd_keys;

	for (i=0; i< val_len; i++)
	{
		allwd_keys[i] = val_keys[i];
	}

}

CKeyIn::~CKeyIn()
{
	if (allwd_keys != NULL)
	{	delete[] allwd_keys;
		allwd_keys = NULL;
	}
}

KeyMap_e CKeyIn::ParseKey(void)
{
	int key, i;
	bool valid_key = false;
	KeyMap_e retval = KEY_ERR;
	KeyMap_e* tmp_arr = allwd_keys;

	keypad(key_windo, TRUE);
	key = wgetch(key_windo);

	for (i=0; i< val_len; i++)
	{
		if (key == (int)tmp_arr[i]) {
			//valid_key = true;
			retval = tmp_arr[i];
			break;
		}
	}

	return retval;
}

KeyMap_e CKeyIn::ParseKey(WINDOW* windo)
{
	int key;
	KeyMap_e retval = KEY_ERR;

	keypad(windo, TRUE);
	key = wgetch(windo);

	switch (key)
	{
		case KEY_ERR:
		retval = KEY_ERR;
		break;

		case UP_KEY:
		retval = UP_KEY;
		break;

		case DOWN_KEY:
		retval = DOWN_KEY;
		break;

		case LEFT_KEY:
		retval = LEFT_KEY;
		break;

		case RIGHT_KEY:
		retval = RIGHT_KEY;
		break;

		case ESC_KEY:
		retval = ESC_KEY;
		break;

		case OK_KEY:
		retval = OK_KEY;
		break;

		default:
		retval = KEY_ERR;
		break;
	}

	return retval;
}
