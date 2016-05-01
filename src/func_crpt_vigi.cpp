#include <string.h>

int vig(char a[],char b[]){
int i=0,j=0;
if((!strlen(a)) || (!strlen(b))) {return -1;}
for (i=0;i<strlen(a);i++)
{
    if((a[i] < 32) || (a[i] == 127) || ) {
        if(a[i] != 13)
            return 1;
    }
}
for (i=0;i<strlen(b);i++)
{
    if((b[i] < 32) || (b[i] == 127)) {return 1;}
}

for (i=0;i<strlen(b);i++){
 b[i]=b[i]-31;
}
i=0;
 while(a[i] != 0){
     if(b[j] == 0)
     j=0;
     if(a[i] != 13){
        a[i] = a[i] + b[j];
        while(a[i] == 127 || a[i] < 32)
                a[i] = a[i] - 95;
        j++;
    }
    i++;
}
for(i=0;b[i]!=0;i++)
      b[i]+=31; 
      return 0;               
}


int devig(char a[],char b[]){
int i=0,j=0;
if((!strlen(a)) || (!strlen(b))) {return -1;}
for (i=0;i<strlen(a);i++)
{
    if((a[i] < 32) || (a[i] == 127)) {
        if(a[i] != 13)
            return 1;
    }
}
for (i=0;i<strlen(b);i++)
{
    if((b[i] < 32) || (b[i] == 127)) {return 1;}
}
for (i=0;i<strlen(b);i++){
 b[i]=b[i]-31;
}
i=0;
while(a[i]!=0){
    if(b[j]==0)
    j=0;
    if(a[i] != 13){
       a[i] = a[i] - b[j];
       while(a[i] == 127 || a[i] < 32)
               a[i] = a[i] + 95;
       j++;
   }
   i++;
}
for(i=0;b[i]!=0;i++)
      b[i]+=31;   
      return 0;             
}
