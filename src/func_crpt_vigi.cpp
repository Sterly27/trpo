#include <string.h>

int vig(char a[],char b[]){
int i=0,j=0;
if((!strlen(a)) || (!strlen(b))) {return -1;}
for (i=0;i<strlen(a);i++)
{
    if((a[i] < 32) || (a[i] == 127)) {return 1;}  
}
for (i=0;i<strlen(b);i++){
 b[i]=b[i]-29;
}
i=0;
 while(a[i]!=0){
 if(b[j]==0)
 j=0;
 a[i]=a[i]+b[j];
 while(a[i]==127 || a[i]<32)
     a[i]=a[i]-95;
 i++;j++;
 }     
for(i=0;b[i]!=0;i++)
      b[i]+=29; 
      return 0;               
}


int devig(char a[],char b[]){
int i=0,j=0;
if((!strlen(a)) || (!strlen(b))) {return -1;}
for (i=0;i<strlen(a);i++)
{
    if((a[i] < 32) || (a[i] == 127)) {return 1;}  
}
for (i=0;i<strlen(b);i++){
 b[i]=b[i]-29;
}
i=0;
 while(a[i]!=0){
 if(b[j]==0)
 j=0;
  a[i]=a[i]-b[j];
 if(a[i]<b[j]+29)
 	a[i]=a[i]+95;
 i++;j++;
 }
for(i=0;b[i]!=0;i++)
      b[i]+=29;   
      return 0;             
}
