#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int inpnum(int n){
 int key,i=0,j=0,step=0,num=0;
 char a[n];
     while(key!=13){
     key=cin.get();        
       if(key>47&&key<58){                                           
       a[i]=key;              
       i++;
       a[i]=0;      
       }
       if(i==n){
       step=pow(10,strlen(a))+1;                           
       for(j=0;j<strlen(a);j++){            
        num=num+((a[j]-48)*(step/10));
        step=step/10;
        }
        if(num<=70) 
         return num;
         else num=0;
        }
      }
}
