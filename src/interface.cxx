//Interface functionality

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../inc/interface.h"

using namespace std;

CIface::CIface(void)
{
 	;
}
CIface::~CIface(void) 
{
	;
}

int CIface::CreatMask(CmdBits_e arr[MAX_CMDS])
{
	int i, res=0;

	for (i=0; arr[i]; i++)
	{
		res |= (BIT << arr[i]);
	}

	return res;
}


//////////////////////////////Get-Set functions//////////////////////////////
void CIface::SetHeader(char* buff)
{
	strncpy(header, buff, sizeof(header));
}

void CIface::GetHeader(char* buff)
{
	;
}

void CIface::DispHeader(void)
{
	fputs("VIRTUAL WORKS", stdout);
}

void CIface::SetFooter(char* buff)
{
	;
}

void CIface::DispFooter(void) 
{
	;
}