//Define the class for handling flag related functions.

#ifndef __FLAGS_H_INCLUDED__
#define __FLAGS_H_INCLUDED__

#include <iostream>
#include <stdio.h>

#include "../inc/sizes.h"

using namespace std;

/*CBitflag: Flag class using bit fields for values.
*Main parameters-
*Bit mask variable
*Flags limit- Number of max. flags to be packed in.
*Flag Set indicator- returns true if the particular flag is SET else returns false.
*
*/
class CBitflag
{
public:
	CBitflag();
	CBitflag(int msk, int max);
	~CBitflag(void);

	bool IncPlace(void);	//Increment the bit place, in effect check the next flag.
	bool DecPlace(void);	//Dec the bit place, in effect check the previous flag.
	bool SetPlace(int pos);	//Set the bit position to check directly.

	bool MaxReach(void);	//If the bit place equals the max allowed flags minus 1, it returns true.

	bool ChkFlag(void);		//Check the flag at particular place "place" against the bitmask "mask".
							//Return true if the bit is set, else false.

	//////////////////////////////Get-Set functions//////////////////////////////

	void SetMask(int msk);	//Set the flag bitmask
	int GetMask(void);		//Return the flag bitmask

	int GetPlace(void);			//Return the currentbit place 


private:
	int max_flags;		//Store the max number of flags allowed for this class.
	int place;			//Bit place which needs to be checked.
	Bitmask_short mask;	//The actual mask associated with this flag object.
	bool max_reach;		//Set to true when "place" = (max_flags - 1).
};

#endif /* __FLAGS_H_INCLUDED__ */