void vig(char a[],char b[],int flag){
int i=0,j=0;
for (i=0;i<strlen(b);i++){
 b[i]=b[i]-29;
}
i=0;
 while(a[i]!=0){
 if(b[j]==0)
 j=0;
 a[i]=a[i]+b[j];
 if(a[i]==127 || a[i]<0)
     a[i]=a[i]-95;
 if(a[i]<32)
     a[i]=a[i]+95;
 i++;j++;
 }     
for(i=0;b[i]!=0;i++)
      b[i]+=29;                
}


void devig(char a[],char b[],int flag){
int i=0,j=0;
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
}
