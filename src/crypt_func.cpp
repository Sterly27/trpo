#include <string.h>

const int ERROR_KEY = 1;
const int NO_ERROR = 0;
const int EMPTY_STR = 1;

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
