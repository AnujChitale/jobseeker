//File reading and writing classes. Managing, editing, reading the app data!


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <ncurses.h>

#include "files.h"

using namespace std;

const char* TAG_LB = "<";
const char* TAG_RB = ">";
const char* TAG_END = "/";

#ifdef C_FILE_OPS

#endif
#ifdef CXX_FILE_OPS


CTxtTag::CTxtTag()
{
	name = NULL;
}
CTxtTag::CTxtTag(const char* txt)
{
	name = txt;
	CreatTag(name);
}

CTxtTag::~CTxtTag()
{
	;
}

void CTxtTag::CreatTag(const char* txt)
{
	s_tag = TAG_LB;
	if (name) {
		s_tag.append(name);
	}
	s_tag.append(TAG_RB);

	e_tag = TAG_LB;
	e_tag.append(TAG_END);
	if (name) {
		e_tag.append(name);
	}
	e_tag.append(TAG_RB);
}

char* CTxtTag::GetName(void)
{
	if (name) {
		return (char*)name;
	}
	else {
		return NULL;
	}
}

const char* CTxtTag::GetS_Tag(void)
{
	return s_tag.c_str();
}

const char* CTxtTag::GetE_Tag(void)
{
	return e_tag.c_str();
}


CFile::CFile()
{
	file_data = NULL;
}

CFile::CFile(char* fname, FileOper_e oper)
{
	file_data = NULL;

	SetName(fname);		//Store the passed name.
	name_len = file_name.length();
	SetDataLen();		//Store the file size in bytes
}

CFile::~CFile()
{
	if (file_data != NULL) {
		delete[] file_data;
	}
}


bool CFile::ReadFile(void)
{
	ifstream stream;
	bool retval = false;
	int len = GetFileLen();

	if (!file_data && len> 0) {
		file_data = new char[len];
	}
	stream.open(file_name.c_str());
	if (stream.is_open())
	{
		stream.read(file_data, len);
		stream.close();
		retval = true;
	}
	return retval;
}

bool CFile::WritFile(void)
{
	ofstream stream;
	bool retval = false;


	return retval;
}

void CFile::SetName(char* name)
{
	if (MAX_FILE_NAME >strnlen(name, MAX_FILE_NAME)) {
		file_name = name;
	}
}

const char* CFile::GetName(void)
{
	return file_name.c_str();
}

char* CFile::GetData(const char* start, const char* end)
{
	string tmp_data;
	int s=0, e=0;

	tmp_data = file_data;
	if (!start && !end)
	{
		curr_data = tmp_data;
	}

	else if (start && !end)
	{
		s = tmp_data.find(start) + strlen(start);
		if (s!=tmp_data.npos) {
			curr_data = tmp_data.substr(s);
		}
	}

	else if (!start && end)
	{
		e = tmp_data.find(end);
		if (e!=tmp_data.npos) {
			curr_data = tmp_data.substr(0,e);
		}
	}

	else if (start && end)
	{
		s = tmp_data.find(start) + strlen(start);
		e = tmp_data.find(end);

		if (s!=tmp_data.npos && e!=tmp_data.npos) {
			curr_data = tmp_data.substr(s, e-s);
		}
	}
	return (char*)curr_data.c_str();
}

char* CFile::GetData(CTxtTag tag)
{
	string tmp_data;
	int s=0, e=0;

	tmp_data = file_data;

	s = tmp_data.find(tag.GetS_Tag()) + strlen(tag.GetS_Tag());
	e = tmp_data.find(tag.GetE_Tag());

	if (s!=tmp_data.npos && e!=tmp_data.npos) {
		curr_data = tmp_data.substr(s, e-s);
	}
	return (char*)curr_data.c_str();
}

bool CFile::SetDataLen(void)
{
	;	//TODO This should set the custom data length to read/ write
}

int CFile::GetDataLen(void)
{
	return data_len;
}

int CFile::GetFileLen(void)
{
	int len = 0;

	if (!file_name.empty())
	{
		ifstream stream(file_name.c_str());
		while (stream.get() != EOF) {
			len++;
		}
		stream.close();
	}
	return len;
}


void CFile::SetStart(char* str)
{
	s_pos = str;
}

void CFile::SetEnd(char* str)
{
	e_pos = str;
}


#endif
