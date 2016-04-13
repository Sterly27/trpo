#include "crypt_func.h"
#include <cstring>

const int ERROR = -1;
const int NO_ERROR = 0;
const int EMPTY = 1;

int crpt(char* string,int key)
{ 
	if (string == NULL) return EMPTY;
	else if(string!=NULL)
	{
		for (int i =0; i<strlen(string);++i)
		{
			string[i]^=key;
			if(string[i]<32) string[i]+=95;
			if(string[i]>126) string[i]-=95;
		}
		return NO_ERROR;
	}
	else if (key==NULL) return ERROR;
}
