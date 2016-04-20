#include <string.h>

const int ERROR = -1;
const int NO_ERROR = 0;
const int EMPTY = 1;

int crpt(char* string,int key){ 
	if (string == NULL) return EMPTY;
	else if (key==NULL) return ERROR;
	else{
		for (int i =0; i<strlen(string);++i)
			string[i]^=key;
		return NO_ERROR;
	}
}
