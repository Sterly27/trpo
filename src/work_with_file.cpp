#include <stdio.h>
void scan(char* fileName,char* str,int n){
    FILE* f;
    f=fopen(fileName,"r");
    fgets(str,n,f);
    fclose(f);
}

void print(char* fileName,char* str){
    FILE* f;
    f=fopen(fileName,"w");
    fputs(str,f);
    fclose(f);
}
