#include <string.h>
#include <conio.h>
#include <graphics.h>
void tire(){
putch(7);
delay(207);
putch(7);
delay(207);
putch(7);
delay(621);
     }
     
void tchk(){
putch(7);
delay(621);
     }
char* demorze(char* str){
    char* itog;
    itog=new char[strlen(str)/4];
    char* temp;
    int f=0,t=0;
    temp=new char [5];
    for (int i=0;i<strlen(str);i++){
        if (str[i]!='|') temp[f++]=str[i];
        else {
            f=0;
            if (strcmp(temp,"*-"))itog[t++]='a';
            if (strcmp(temp,"-***"))itog[t++]='b';
            if (strcmp(temp,"-*-*"))itog[t++]='c';
            if (strcmp(temp,"-**"))itog[t++]='d';
            if (strcmp(temp,"*"))itog[t++]='e';
            if (strcmp(temp,"**-*"))itog[t++]='f';
            if (strcmp(temp,"--*"))itog[t++]='g';
            if (strcmp(temp,"****"))itog[t++]='h';
            if (strcmp(temp,"**"))itog[t++]='i';
            if (strcmp(temp,"*---"))itog[t++]='j';
            if (strcmp(temp,"-*-"))itog[t++]='k';
            if (strcmp(temp,"*-**"))itog[t++]='l';
            if (strcmp(temp,"--"))itog[t++]='m';
            if (strcmp(temp,"-*"))itog[t++]='n';
            if (strcmp(temp,"---"))itog[t++]='o';
            if (strcmp(temp,"**-"))itog[t++]='p';
            if (strcmp(temp,"**-"))itog[t++]='q';
            if (strcmp(temp,"**-"))itog[t++]='r';
            if (strcmp(temp,"**-"))itog[t++]='s';
            if (strcmp(temp,"**-"))itog[t++]='t';
            if (strcmp(temp,"**-"))itog[t++]='u';
            if (strcmp(temp,"**-"))itog[t++]='v';
            if (strcmp(temp,"**-"))itog[t++]='w';
            if (strcmp(temp,"**-"))itog[t++]='x';
            if (strcmp(temp,"**-"))itog[t++]='y';
            if (strcmp(temp,"**-"))itog[t++]='z';
            
            
            }
        
        }
    
    }
void morze(char* str){
     for(int i=0;i<strlen(str);i++){
     if (str[i]=='A'||str[i]=='a'){printf("*-|");tchk();tire();}
     if (str[i]=='B'||str[i]=='b'){printf("-***|");tire();tchk();tchk();tchk();}
     if (str[i]=='C'||str[i]=='c'){printf("-*-*|");tire();tchk();tire();tchk();}
     if (str[i]=='D'||str[i]=='d'){printf("-**|");tire();tchk();tchk();}
     if (str[i]=='E'||str[i]=='e'){printf("*|");tchk();}
     if (str[i]=='F'||str[i]=='f'){printf("**-*|");tchk();tchk();tire();tchk();}
     if (str[i]=='G'||str[i]=='g'){printf("--*|");tire();tire();tchk();}
     if (str[i]=='H'||str[i]=='h'){printf("****|");tchk();tchk();tchk();tchk();}
     if (str[i]=='I'||str[i]=='i'){printf("**|");tchk();tchk();}
     if (str[i]=='J'||str[i]=='j'){printf("*---|");tchk();tire();tire();tire();}
     if (str[i]=='K'||str[i]=='k'){printf("-*-|");tire();tchk();tire();}
     if (str[i]=='L'||str[i]=='l'){printf("*-**|");tchk();tire();tchk();tchk();}
     if (str[i]=='M'||str[i]=='m'){printf("--|");tire();tire();}
     if (str[i]=='N'||str[i]=='n'){printf("-*|");tire();tchk();}
     if (str[i]=='O'||str[i]=='o'){printf("---|");tire();tire();tire();}
     if (str[i]=='P'||str[i]=='p'){printf("*--*|");tchk();tire();tire();tchk();}
     if (str[i]=='Q'||str[i]=='q'){printf("--*-|");tire();tire();tchk();tire();}
     if (str[i]=='R'||str[i]=='r'){printf("*-*|");tchk();tire();tchk();}
     if (str[i]=='S'||str[i]=='s'){printf("***|");tchk();tchk();tchk();}
     if (str[i]=='T'||str[i]=='t'){printf("-|");tire();}
     if (str[i]=='Y'||str[i]=='y'){printf("-*--|");tire();tchk();tire();tire();}
     if (str[i]=='U'||str[i]=='u'){printf("**-|");tchk();tchk();tire();}
     if (str[i]=='V'||str[i]=='v'){printf("***-|");tchk();tchk();tchk();tire();}
     if (str[i]=='W'||str[i]=='w'){printf("*--|");tchk();tire();tire();}
     if (str[i]=='X'||str[i]=='x'){printf("-**-|");tire();tchk();tchk();tire();}
     if (str[i]=='Z'||str[i]=='z'){printf("--**|");tire();tire();tchk();tchk();}
     delay(621);
     }
     printf("\n------------------Crypted successfully!-------------------\n");
}
int main(){
    char a[1009];
    demorze(a);
    }
