//Define the functionality related to external files.

#ifndef __FILES_H_INCLUDED__
#define __FILES_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <ncurses.h>
#include <string>

#include "sizes.h"

using namespace std;

//#define C_FILE_OPS
#define CXX_FILE_OPS

//////////////////////////////enum definitions//////////////////////////////
/*FileOper_e: type of file operations to be allowed/ made.
 *
 */
typedef enum
{
	IN = 0,
	OUT,
	INOUT
}FileOper_e;

#ifdef C_FILE_OPS

#endif
#ifdef CXX_FILE_OPS
//////////////////////////////class definitions//////////////////////////////
/*CTxtTag: Class for the text identifier tags within the data files.
 *
 */
class CTxtTag
{
public:
	CTxtTag();
	CTxtTag(const char* txt);
	~CTxtTag();

	void CreatTag(const char* txt);	//Format the tag from the tag "name".
	char* GetName(void);			//Return the tag "name".
	const char* GetS_Tag(void);		//Return the full start tag.
	const char* GetE_Tag(void);		//Return the full end tag.

	const char* name;				//Tag name.
	string s_tag;					//The start tag.
	string e_tag;					//The end tag with an '/'.

};


/*CFile: Main class related with file reading/writing operations
 *
 */
class CFile
{
public:
	CFile();
	CFile(char* fname, FileOper_e oper);
	~CFile();

	bool ReadFile(void);			//Read file contents into "data"
	bool WritFile(void);			//Write to file from "data".
	void Display(void);			//Print the contents of "data".

	void SetName(char* name);	//Set filename associated with this object.
	const char* GetName(void);		//Return the filename from this object.

	bool ClrData(void);			//Delete the
	/* Return info from data buffer.
	 * if !start && !end	return==> full "file_data".
	 * if start && !end		return==> start to last of "file_data".
	 * if !start && end		return==> first of "file_data" to end
	 * if start && end		return==> start to end within "file_data".
	 */
	char* GetData(const char* start, const char* end);
	char* GetData(CTxtTag tag);		//Search "file_data" buffer for the passed tags.

	bool SetDataLen(void);		//store file size in bytes in "data_len".
	int GetDataLen(void);

	int GetFileLen(void);		//Return the file size.

	/*Identifier tags for data parsing*/
	bool SetS_Tag(char* tag);
	char* GetS_Tag(void);
//	char* ClrS_Tag(void);		//TODO Do we need to clear tags each time?
	bool SetE_Tag(char* tag);
	char* GetE_Tag(void);
//	char* ClrE_Tag(void);		//TODO Do we need to clear tags each time?

	/*Start and End pointers for data chunks.*/
	void SetStart(char* str);
	void ClrStart(void);
	void SetEnd(char* str);
	void ClrEnd(void);

private:
	int file_size;
	short name_len;
	string file_name;		//Store the filename.
	string file_path;		//The folder to search file_name into. Is it really required?
	string s_tag;			//Identifier string tag to start parsing.
	string e_tag;			//Identifier string tag to stop parsing.
	short path_len;
	int data_len;

	char* file_data;		//Read/ write the actual file data into this.
	string curr_data;		//All read-write-modify operations should be done on this, not the "file_data" char array.
	string s_pos;			//Start position within data.
	string e_pos;			//End position within data.



};

#endif

#endif /* __FILES_H_INCLUDED__ */
