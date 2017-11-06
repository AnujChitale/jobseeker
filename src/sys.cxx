//System related wrapper functions

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "../inc/sys.h"

using namespace std;

void clearscr(void)
{
	system("clear");
}

void nokeybuff(void)
{
    struct termios t;	
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}