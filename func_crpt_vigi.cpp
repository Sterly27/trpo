#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

const int N=1000;

char *vig(char *a,char *b);

int main (){
SetConsoleCP(1251); SetConsoleOutputCP(1251);
char str[N], str1[N];
vig(str,str1);
system("PAUSE");
}

char *vig(char *a,char *b)
{
int i=0,j=0;

 for (i=0;i<strlen(b);i++)
 {
 b[i]-=31;
 }

i=0;
 while(a[i]!=0)
 {if(j>=strlen(b))
 j=0;
 a[i]^=b[j];
 if(a[i]<b[j]+31)
 a[i]=a[i]+95;
 if(a[i]==127 || a[i]<0)
     a[i]=a[i]-95;
 i++;j++;
 }  
for(i=0;b[i]!=0;i++)
      b[i]+=31;  
 }
