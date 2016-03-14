#include <stdlib.h>
#include <string.h>
#include <clocale>
#include <stdio.h>

const int N=1000;

void vig();

int main ()
{setlocale (LC_ALL,"Russian");
char str[N], str1[N];
vig();
system("PAUSE");
}

void vig()
{char a[N], b[N];
int i=0,j=0;
gin(a,N,38,15,35); 
gin(b,N,43,15,460); 
 for (i=0;i<strlen(b);i++)
 {
 if(b[i]<(-98))
 b[i]+=128;
 b[i]-=30;
}
i=0;
 while(a[i]!=0)
 {if(j>=strlen(b))
 j=0;
 a[i]^=(b[j]-30);

 i++;j++;
 }  
gout(a,38,685,35); 
 }
