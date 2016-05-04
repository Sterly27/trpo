#include <string.h>

const int ERROR_SYMBOLS=-1;
const int NO_ERROR = 0;
const int EMPTY = 1;

int crpt(char* string,int key)
{ 
    if ((string[0]==0)||(!key)) return EMPTY;

	for(int i=0;i<strlen(string);i++)
        if((string[i] < 32) && (string[i]!='\n') || (string[i] == 127)) {return 1;}

    if(key>100||key<0) return ERROR_SYMBOLS;
    if(key>96) key-=96;

    for (int i =0; i<strlen(string);++i){
            if(string[i]=='\n') continue;

            string[i]+=key;
    }
    return NO_ERROR;
}


int decrpt(char* string,int key)
{
    if ((string[0]==0)||(!key)) return EMPTY;

    for(int i=0;i<strlen(string);i++)
        if((string[i] < 32) && (string[i]!='\n') || (string[i] == 127)) {return 1;}

    if(key>100||key<0) return ERROR_SYMBOLS;
    if(key>96) key-=96;

    for (int i =0; i<strlen(string);++i){
            if(string[i]=='\n') continue;

            string[i]-=key;
    }
    return NO_ERROR;
}
