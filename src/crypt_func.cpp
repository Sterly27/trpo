#include <string.h>

const char ERROR_KEY[] = "EMPTY_KEY";
const int NO_ERROR = 0;
const char EMPTY_STR[] = "EMPTY_STRING";

char crpt(char* string,int key)
{ 
	if (string == NULL) return EMPTY_STR;
	else if (key==NULL) return ERROR_KEY;
	else
	{
		for (int i =0; i<strlen(string);++i)
			string[i]^=key;
	}
}
