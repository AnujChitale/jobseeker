#ifndef __KEYS_H_INCLUDED__
#define __KEYS_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>



//////////////////////////////enum definitions//////////////////////////////
/*KeyMap_e: Assign action names to various keys.
* Default is the ncurses mapping
*/
#ifdef __NCURSES_H
typedef enum
{
	KEY_ERR = -1,
	UP_KEY = KEY_UP,
	DOWN_KEY = KEY_DOWN,
	LEFT_KEY = KEY_LEFT,
	RIGHT_KEY = KEY_RIGHT,
	ESC_KEY = 27,
	OK_KEY = 10,
	NO_KEY_INP = 0
}KeyMap_e;
#else
typedef enum
{
	KEY_ERR = -1,
	UP_KEY = 'w',
	DOWN_KEY = 'z',
	LEFT_KEY = 'a',
	RIGHT_KEY = 's',
	ESC_KEY = 27,
	OK_KEY = 10/*0x0d*/,
}KeyMap_e;
#endif


//////////////////////////////class definitions//////////////////////////////
class CKeyIn
{
public:
	CKeyIn();
	CKeyIn(WINDOW* val_windo, int len, KeyMap_e* val_keys);
	~CKeyIn();

	KeyMap_e ParseKey(void);					//Default key checker for this class. Checks from the "key_windo" window passed in constructor.
	static KeyMap_e ParseKey(WINDOW* windo);	//Check input. If not one of inputs from "allwd_keys" buffer, return error.


	KeyMap_e* allwd_keys;		//The array of allowed keys for this specific input.
//	KeyMap_e allwd_keys[15];
	WINDOW* key_windo;			//The associated window with this key input.
	int val_len;				//Stores the number of valid keys
};


#endif /* __KEYS_H_INCLUDED__ */
