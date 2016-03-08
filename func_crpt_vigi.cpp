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
int i,j;
printf("Введите текст: \n");
gets(str);
 printf("Введите ключ: \n");  
 gets(str1);
 while(str[i]!=0)
 {if(j>=strlen(str1))
 j=0;
 str[i]^=(str1[j]-20);
 i++;j++;
 }  
 puts (str);
 }
