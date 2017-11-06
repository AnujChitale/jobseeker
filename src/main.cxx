#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/interface.h"
#include "../inc/sys.h"
#include "../inc/flags.h"
#include "../inc/screen.h"
#include "../inc/sizes.h"
#include "../inc/menus.h"
#include "../inc/style.h"
#include "../inc/keys.h"
#include "files.h"
#include <ncurses.h>


using namespace std;

CIface Mainface_i;
//CScreen MainScreen_s;


int main(void)
{

	{
		int scr_y, scr_x;
		KeyMap_e chn;
		WINDOW* curr_wind;
		
		initscr();
		cbreak();
		noecho();
		clear();
		curs_set(0);

		getmaxyx(stdscr, scr_y, scr_x);
		CScreen scr_1(MAIN_SCR, scr_y, scr_x, 0, 0);
		border_win(scr_1.GetWindo(), 0, 0);
		nextline(scr_1.GetWindo());
		nextcol(scr_1.GetWindo());
		wprintw(scr_1.GetWindo(), "Welcome to the new jobseeker version using ncurses.");
		//refresh();

		// CCmdMenu testmenu(2);
		curr_wind = scr_1.GetWindo();

		while ((chn = CKeyIn::ParseKey(curr_wind)) != OK_KEY);

		//CScreen menu_wind(CMD_SCR, 6, 10, (scr_y/2)-10 ,(scr_x/2)-20);

		//border_win(menu_wind.GetWindo(), 0 ,0);
		curr_wind = scr_1.GetWindo();


		CmdBits_e tmp_arr[] = {HELP,ESCP,CMDS,QUIT};
		KeyMap_e allowed_keys[] = {OK_KEY,DOWN_KEY,UP_KEY,ESC_KEY,LEFT_KEY};
		char* fil_nm = "testfile.txt";
		CFile abc_file("testfile.txt", INOUT);
		CTxtTag t1("a2");
		ITEM* tmp_item;
		bool prog_quit = false;
		bool tog_cmd = false;
		CCmdMenu tst_men_g(curr_wind, ARRAY_SIZE(tmp_arr), tmp_arr);
		CKeyIn tst_key_inp(curr_wind,ARRAY_SIZE(allowed_keys), allowed_keys);

		set_menu_win(tst_men_g.GetMenu(), curr_wind);
		set_menu_sub(tst_men_g.GetMenu(), derwin(curr_wind, 4, 8, (scr_y/2)-10 ,(scr_x/2)-20));
		set_menu_format(tst_men_g.GetMenu(), 5, 1);
		set_menu_mark(tst_men_g.GetMenu(), " >>");
		nextline(curr_wind);
		wrefresh(curr_wind);
		tst_men_g.ShowMenu();
		tmp_item = current_item(tst_men_g.GetMenu());

		mvwprintw(curr_wind,2,1,"Current item number ==> %d", tmp_item->index);
		mvwprintw(curr_wind,3,1,"Current item name ==> %s", tmp_item->name);
		wrefresh(curr_wind);

		while (!prog_quit)
		{
			chn = tst_key_inp.ParseKey();
			switch (chn)
			{
			case UP_KEY:
				menu_driver(tst_men_g.GetMenu(), REQ_PREV_ITEM);
				break;

			case DOWN_KEY:
				menu_driver(tst_men_g.GetMenu(), REQ_NEXT_ITEM);
				break;

			case ESC_KEY:
				tog_cmd = !tog_cmd;
				if(!tog_cmd) {
					tst_men_g.ShowMenu();
				}
				else {
					tst_men_g.RemoveMenu();
				}
				break;

			case LEFT_KEY:
				abc_file.ReadFile();
				mvwprintw(curr_wind,5,1,"%s", abc_file.GetData(t1));
				break;

			case OK_KEY:
				if (0 == strncmp(ALLWD_CMDS[11], item_name(tmp_item), 4)) {
					prog_quit = true;
				}
				break;


			case KEY_ERR:
				mvwprintw(scr_1.GetWindo(),4,1,"NON_ALLOWED KEY PRESS");
				wrefresh(scr_1.GetWindo());
				break;
			}
			wrefresh(curr_wind);
			tmp_item = current_item(tst_men_g.GetMenu());
			mvwprintw(curr_wind,2,1,"Current item number ==> %d", tmp_item->index);
			mvwprintw(curr_wind,3,1,"Current item name ==> %s", tmp_item->name);
			wrefresh(curr_wind);

		}
		tst_men_g.RemoveMenu();
		curr_wind = NULL;
		endwin();
	}
	return 0;
	//exit(0);
}
