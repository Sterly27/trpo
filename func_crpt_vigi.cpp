#include <stdlib.h>
#include <string.h>
#include <clocale>
#include <stdio.h>

char str[1000], str1[1000];

void vig();

int main ()
{setlocale (LC_ALL,"Russian");
vig();
system("PAUSE");
}

void vig()
{char str[1000], str1[1000];
int i=0,j=0;
printf("������� �����: \n");
gets(str);
 printf("������� ����: \n");  
 gets(str1);
 while(str[i]!=0)
 {if(j>=strlen(str1))
 j=0;
 str[i]^=(str1[j]-30);
 if (str[i]<=0)
 str[i]+=126;
 i++;j++;
 }  
 puts (str);
 }
