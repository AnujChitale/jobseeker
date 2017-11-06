// Define the interface functionality class

#ifndef __INTERFACE_H_INCLUDED__
#define __INTERFACE_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../inc/commands.h"
#include "../inc/sizes.h"

using namespace std;


/*CIface: An object responsible for info display and allowed capabilities.
*Main parameters-
*#Header buffer- Display the top portion
*#Body buffer- Display the main body
*#Footer buffer- Display the allowed commands
*
*/
class CIface
{
public:
	CIface(void);
	~CIface(void);


//////////////////////////////Get-Set functions//////////////////////////////
	int CreatMask(CmdBits_e arr[MAX_CMDS]);	//Put the command bits in an array to prepare the mask.
											//Returns the integer bit mask if successful. returns -1(ERR) on error
	void SetMask(Bitmask_short mask);
	Bitmask_short GetMask(void);


	void SetHeader(char* buff);			//Set the header of this interface
	void GetHeader(char* buff);
	virtual void DispHeader(void);				//Displaythe header of this interface

	void SetFooter(char* buff);			//Set the footer of this interface
	void DispFooter(void);				//Displaythe footer of this interface

private:
	char header[100];
};

#endif /* __INTERFACE_H_INCLUDED__ */