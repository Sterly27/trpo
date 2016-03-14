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
printf("Введите текст: \n");
gets(str);
 printf("Введите ключ: \n");  
 gets(str1);
 for (i=0;i<strlen(str1);i++)
 {
 if(str1[i]<(-98))
 str1[i]+=128;
 str1[i]-=30;
}
i=0;
 while(str[i]!=0)
 {if(j>=strlen(str1))
 j=0;
 str[i]^=(str1[j]-30);

 i++;j++;
 }  
 puts (str);
 }
