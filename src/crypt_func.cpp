#include <string.h>

const int ERROR_SYMBOLS=-1;
const int ERROR_KEY = 1;
const int NO_ERROR = 0;
const int EMPTY_STR = 1;

int crpt(char* string,int key)
{ 
	if ((string[0]==0)||(!key)) return EMPTY_STR;
    for(int i=0;i<strlen(string);i++)
    if((string[i] < 32) || (string[i] == 127)) {return 1;}
	if(key>70||key<0) return ERROR_SYMBOLS;
	else
	{
		for (int i =0; i<strlen(string);++i)
			string[i]^=key;
	}
	return NO_ERROR;
}
