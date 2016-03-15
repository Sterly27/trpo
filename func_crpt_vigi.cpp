#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

const int N=1000;

void vig();
int main ()
{SetConsoleCP(1251); SetConsoleOutputCP(1251);
char str[N], str1[N];
vig();
system("PAUSE");
}

void vig()
{char a[N], b[N];
int i=0,j=0;
gets (a);

gets (b); 

 for (i=0;i<strlen(b);i++)
 {
 if(b[i]<(-85))
 b[i]+=98;
 b[i]-=40;
}

i=0;
 while(a[i]!=0)
 {if(j>=strlen(b))
 j=0;
 a[i]^=b[j];

 i++;j++;
 }  
puts (a); 

 }
