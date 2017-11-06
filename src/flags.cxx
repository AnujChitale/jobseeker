//Flags functionality

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../inc/flags.h"

using namespace std;

CBitflag::CBitflag()
{
	//Default values in absence of explicit values
	SetMask(0x00);		//All 16 flags unset in default mode
	max_flags = 16;
	place = 0;
}

CBitflag::CBitflag(int msk, int max)
{
	SetMask((Bitmask_short)msk);
	max_flags = max;
	place = 0;
}

CBitflag::~CBitflag(void)
{
	;
}



////////////////////////////////////////////
bool CBitflag::IncPlace(void)
{
	bool ret = false;
	if (place < (max_flags - 1)) {	//Do not increment beyond this to avoid breaking the limit.
		++place;
		ret = true;
	}
	else {
		max_reach = true;
	}
	return ret;
}

bool CBitflag::DecPlace(void)
{
	bool ret = false;
	if (place > 0) {				//Can't decrement below 0
		--place;
		ret = true;
	}
	else {
		;
	}
	return ret;
}

bool CBitflag::SetPlace(int pos)
{
	bool ret = false;

	if (pos == (max_flags - 1)) {
		place = pos;
		max_reach = true;
		ret = true;
	}
	else if (pos >= 0 || pos < (max_flags - 1)) {
		place =pos;
		ret = true;
	}
	else {
		;
	}
	return ret;
}

bool CBitflag::MaxReach(void)
{
	bool ret = false;
	if (max_reach == true) {
		ret = true;
	}
	return ret;
}

bool CBitflag::ChkFlag(void)
{
	bool ret = false;

	if (mask & (BIT << place)) {
		ret = true;
	}
	return ret;
}

//////////////////////////////Get-Set functions//////////////////////////////
void CBitflag::SetMask(int msk)
{
	mask = msk;
}

int CBitflag::GetMask(void)
{
	return mask;
}


int CBitflag::GetPlace(void)
{
	return place;
}
