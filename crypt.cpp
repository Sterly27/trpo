#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int N=663,L=1053; 
char str[N], str1[L], str2[L], nu[9];  
char* total;

//---------------------------Оформление фона окна приложения------------------------
void fon();
//-----------------------------------Функция загрузки-------------------------------
void load(int x, int y, int rad);
//-------------------------Окна ввода и кнопка выхода в меню------------------------
void winf();
void winf_morze();
void winf_crpt();
//---------------Функция посимвольного ввода числа в графическое окно---------------
int inpnum(char* a,int n,int len, int x, int y);
//----------------Функция посимвольного ввода строки в графическое окно-------------
void gin(char a[],int n,int len,int x, int y);
//-------------------Функция посимвольного вывода в глафическое окно----------------
void gout(char a[],int len,int x, int y);
//------------------------------Функция шифра Вижинера------------------------------
void vig(char a[],char b[]);
//-----------------------------Функция шифратора Морзе------------------------------
void morze(char* str); 
//----------------------------Функция дешифратора Морзе-----------------------------
void demorze(char* str);
//-------------------------------Функция шифра Цезаря-------------------------------
void crpt(char* string,char* itog);


int main(){
int menu=-1,i=0;
      initwindow(1280,720);
      
      while(1){                  
      fon();
      for(i=0;str[i]!=0;i++){
      str[i]=0;             
      }
      for(i=0;str2[i]!=0;i++)
      str2[i]=0;
      for(i=0;str1[i]!=0;i++)
      str1[i]=0;
      i=0; 
      setcolor(COLOR(255,255,255));
      settextstyle(8,0,19);
      outtextxy(430,130,"Шифратор");
      outtextxy(385,300,"Дешифратор");
      outtextxy(500,470,"Выйти");
      while(1){
       clearmouseclick(WM_LBUTTONDOWN);
       delay(30);                
       if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>425&&mousex()<840&&mousey()>125&&mousey()<205){
       cleardevice();
       clearmouseclick(WM_LBUTTONDOWN);
      fon();
      outtextxy(310,130,"Шифр Вижинера");
      outtextxy(365,300,"Шифр Цезаря");
      outtextxy(390,470,"Шифр Морзе");
      outtextxy(970,600,"Назад");
      while(1){
        clearmouseclick(WM_LBUTTONDOWN);
        delay(30);       
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>305&&mousex()<940&&mousey()>125&&mousey()<205){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=1;
        break;                                                                                         
        } 
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>360&&mousex()<900&&mousey()>295&&mousey()<375){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=2;
        break;     
        }
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>385&&mousex()<890&&mousey()>465&&mousey()<545){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=3;
        break;     
        }
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>965&&mousex()<1200&&mousey()>595&&mousey()<675){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=4;
        break;                                                                                         
        }       
      }
      if(menu==1||menu==2||menu==3||menu==4) break;
       }
       if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>380&&mousex()<880&&mousey()>295&&mousey()<375){
       cleardevice();
       clearmouseclick(WM_LBUTTONDOWN);
      fon();
      outtextxy(310,130,"Шифр Вижинера");
      outtextxy(365,300,"Шифр Цезаря");
      outtextxy(390,470,"Шифр Морзе");
      outtextxy(970,600,"Назад");
      while(1){
        clearmouseclick(WM_LBUTTONDOWN);
        delay(30);       
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>305&&mousex()<940&&mousey()>125&&mousey()<205){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=5;
        break;                                                                                         
        }
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>360&&mousex()<900&&mousey()>295&&mousey()<375){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=6;
        break;     
        }
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>385&&mousex()<890&&mousey()>465&&mousey()<545){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=7;
        break;     
        }        
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>965&&mousex()<1200&&mousey()>595&&mousey()<675){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=4;
        break;                                                                                         
        }       
      }
      if(menu==5||menu==6||menu==7||menu==4) break;
       }
       if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>495&&mousex()<765&&mousey()>465&&mousey()<535){
       cleardevice();
       menu=0;
       break;
       }
       }
if(menu==1){
load(900,690,4);                             
settextstyle(8,0,1);   
winf();
while(1){
clearmouseclick(WM_LBUTTONDOWN);
delay(30);         
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>5&&mousex()<605&&mousey()>5&&mousey()<400){         
vig(str,str1);
}
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>965&&mousex()<1200&&mousey()>595&&mousey()<675){
cleardevice();
clearmouseclick(WM_LBUTTONDOWN);
menu=4;
settextstyle(8,0,19);
load(900,690,4);
break;                                                                                         
}
}
}  
if(menu==2){
load(900,690,4);                             
settextstyle(8,0,1);   
winf_crpt();
while(1){
clearmouseclick(WM_LBUTTONDOWN);
delay(30);         
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>5&&mousex()<605&&mousey()>5&&mousey()<585)         
crpt(str2,str1);
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>1015&&mousex()<1250&&mousey()>605&&mousey()<685){
cleardevice();
clearmouseclick(WM_LBUTTONDOWN);
menu=-1;
settextstyle(8,0,19);
load(900,690,4);
break;                                                                                         
}
}
}
if(menu==3){
load(900,690,4);                             
settextstyle(8,0,1);   
winf_morze();
while(1){
clearmouseclick(WM_LBUTTONDOWN);
delay(30);         
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>5&&mousex()<1275&&mousey()>5&&mousey()<265)         
morze(str);
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>995&&mousex()<1230&&mousey()>595&&mousey()<675){
cleardevice();
clearmouseclick(WM_LBUTTONDOWN);
menu=-1;
settextstyle(8,0,19);
load(900,690,4);
break;                                                                                         
}
}
}
if(menu==0)break;
}
}

//-----------------------------------ФУНКЦИИ-----------------------------------------

void fon(){
     setfillstyle(9,COLOR(255,255,255));
      floodfill(100,0,COLOR(255,255,255));
      setlinestyle(1,1,5);
      setcolor(COLOR(10,106,209));
      line(0,0,1280,720);
      setfillstyle(9,COLOR(10,106,209));
      floodfill(0,100,COLOR(10,106,209));
      setcolor(COLOR(255,0,0));
      line(600,720,1280,0);
      setcolor(COLOR(255,255,255));
      setfillstyle(9,COLOR(255,0,0));
      floodfill(1270,100,COLOR(255,0,0));
     }

void load(int x, int y, int rad){
       int i,tick=0;
       fon();
       setlinestyle(0,0,0);
       setcolor(COLOR(255,255,255));
       outtextxy(x-100,y-100,"Загрузка ");
       for(i=0;i<(rad*2+2)*11;i+=rad*2+2){
       if(tick<(rad*2+2)*4){setfillstyle(9,COLOR(255,255,255)); circle(x+310+tick,y-45,rad);floodfill(x+310+tick,y-45,COLOR(255,255,255));}
       tick+=rad*2+2;
       if(tick==(rad*2+2)*4){setfillstyle(1,0); bar(x+310-rad,y-45-rad,x+300+tick+rad,y-45+rad); tick=0;}
       delay(250);
       }
       delay(60);
       cleardevice();
      }

void winf(){          
      fon();
      setfillstyle(1,0);
      bar(10,10,600,395);
      outtextxy(15,15,"Введите текст и нажмите ввод :");  
      bar(680,10,1270,395); 
      outtextxy(685,15,"Итог :");
      bar(10,435,680,710); 
      outtextxy(15,440,"Введите ключ и нажмите ввод :");
      settextstyle(8,0,19);
      outtextxy(970,600,"Назад");
      settextstyle(8,0,1);
      }

void winf_crpt(){          
      fon();
      setfillstyle(1,0);
      bar(10,10,600,580);
      outtextxy(15,15,"Введите текст и нажмите ввод :");  
      bar(680,10,1270,580); 
      outtextxy(685,15,"Итог :");
      bar(10,600,600,710); 
      outtextxy(15,605,"Введите ключ-число и нажмите ввод :");
      settextstyle(8,0,19);
      outtextxy(1020,610,"Назад");
      settextstyle(8,0,1);
      }

void winf_morze(){          
      fon();
      setfillstyle(1,0);
      bar(10,10,1270,260);
      outtextxy(15,15,"Введите текст и нажмите ввод :");  
      bar(10,280,960,710); 
      outtextxy(15,285,"Итог :");
      settextstyle(8,0,19);
      outtextxy(1000,600,"Назад");
      settextstyle(8,0,1);
      }

void gin(char a[],int n,int len,int x, int y){
     int key,i=0,nx=x,ny=y;
     for(i=0;a[i]!=0;i++){
     if(x>(15*len)+nx){
        y+=20;
        x=nx;
        }
       x+=15;                                         
     }
     while(1){
     if(key==8&&i!=0){                 
     a[i-1]=0;
     setfillstyle(0,0);
     bar(x,y,x-16,y+18);
     i--;
     if(y!=ny&&x==(nx+15)){y-=20;x=(15*(len+2))+nx;}
     x-=15;                
     }
     key=getch();        
       if((key>64&&key<91)||(key>96&&key<123)||(key==32)||(key>47&&key<58)){
       a[i]=key;
       i++;
       a[i]=0;
        if(x>(15*len)+nx){
        y+=20;
        x=nx;
        }
       printf("%i ",a[i-1]);
       outtextxy(x,y,&a[i-1]);
       x+=15;       
       }
       if(i==n)
       while(key!=13){
       key=getch();
       if(key==8) break;
       }
       if(key==13) break;
      }
     }
     
int inpnum(char* a,int n,int len, int x, int y){
     int key,i=0,j=0,nx=x,ny=y,step=0,num=0;
     for(i=0;a[i]!=0;i++){
     if(x>(15*len)+nx){
        y+=20;
        x=nx;
        }
       x+=15;                                         
     }
     while(1){
     if(key==8&&i!=0){                 
     a[i-1]=0;
     setfillstyle(0,0);
     bar(x,y,x-16,y+18);
     i--;
     if(y!=ny&&x==(nx+15)){y-=20;x=(15*(len+2))+nx;}
     x-=15;                
     }
     key=getch();        
       if(key>47&&key<58){                                           
       a[i]=key;              
       i++;
       a[i]=0;
        if(x>(15*len)+nx){
        y+=20;
        x=nx;
        }
       outtextxy(x,y,&a[i-1]);
       x+=15;       
       }
       if(i==n)
       while(key!=13){
       key=getch();
       if(key==8) break;
       }
       if(key==13){
       step=pow(10,strlen(a))+1;                           
       for(j=0;j<strlen(a);j++){            
        num=num+((a[j]-48)*(step/10));
        step=step/10;
        }
        if(num<=255) 
         return (num);
         else num=0;
        }
      }
     }
     
void gout(char a[],int len,int x, int y){
     int i=0,nx=x,ny=y,key;
     char b[1];
      while(a[i]!=0){
      b[0]=a[i];
      b[1]=0;
      
      //if(b[0]==' '&&x==nx) x-=15;    УБИРАЕТ ПРОБЕЛЫ В НАЧАЛЕ СТРОКИ        
      outtextxy(x,y,&b[0]);
      x+=15;
      //if(a[i]==' '&&a[i+1]==' ')  x-=15;      УБИРАЕТ ЛИШНИЕ ПРОБЕЛЫ
      i++;
       if(x>(15*len)+nx){
       y+=20;
       x=nx;         
       }
      }                
    }

void vig(char a[],char b[]){
int i=0,j=0;
char c[N];
outtextxy(685,15,"Итог :");
setcolor(COLOR(10,106,209));
outtextxy(15,15,"Введите текст и нажмите ввод :");
setcolor(COLOR(255,255,255));
gin(a,N,38,15,35);
outtextxy(15,15,"Введите текст и нажмите ввод :");
setcolor(COLOR(10,106,209));
outtextxy(15,440,"Введите ключ и нажмите ввод :");
setcolor(COLOR(255,255,255)); 
gin(b,N,43,15,460);
outtextxy(15,440,"Введите ключ и нажмите ввод :"); 
for (i=0;i<strlen(b);i++){
 if(b[i]<(-85))
 b[i]+=98;
 b[i]-=40;
}

i=0;
 while(a[i]!=0){
 if(j>=strlen(b))
 j=0;
 c[i]=a[i]^b[j];
 i++;j++;
 }
 c[i]=0;
setfillstyle(1,COLOR(0,0,0));
bar(685,35,1270,395); 
setcolor(COLOR(10,106,209));
outtextxy(685,15,"Итог :");
setcolor(COLOR(255,255,255));  
gout(c,38,685,35);
for(i=0;c[i]!=0;i++)   
      c[i]=0; 
      
for(i=0;b[i]!=0;i++)
      b[i]+=40;                
}

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
void demorze(char* str){
    gin(str,N,82,15,35);  
    char* itog;
    itog=new char [strlen(str)];
    char temp[5]={0,0,0,0,0};
    
    int f=0,t=0;
    for (int i=0;i<strlen(str);i++){
        if (str[i]!='|') temp[f++]=str[i];
        if (str[i]==' '||str[i]=='|'||i==strlen(str)-1) {
            f=0;
            if (!strcmp(temp,"*----"))itog[t++]='1';
            if (!strcmp(temp,"**---"))itog[t++]='2';
            if (!strcmp(temp,"***--"))itog[t++]='3';
            if (!strcmp(temp,"****-"))itog[t++]='4';
            if (!strcmp(temp,"*****"))itog[t++]='5';
            if (!strcmp(temp,"-****"))itog[t++]='6';
            if (!strcmp(temp,"--***"))itog[t++]='7';
            if (!strcmp(temp,"---**"))itog[t++]='8';
            if (!strcmp(temp,"----*"))itog[t++]='9';
            if (!strcmp(temp,"-----"))itog[t++]='0';
            
            if (!strcmp(temp,"*-"))itog[t++]='a';
            if (!strcmp(temp,"-***"))itog[t++]='b';
            if (!strcmp(temp,"-*-*"))itog[t++]='c';
            if (!strcmp(temp,"-**"))itog[t++]='d';
            if (!strcmp(temp,"*"))itog[t++]='e';
            if (!strcmp(temp,"**-*"))itog[t++]='f';
            if (!strcmp(temp,"--*"))itog[t++]='g';
            if (!strcmp(temp,"****"))itog[t++]='h';
            if (!strcmp(temp,"**"))itog[t++]='i';
            if (!strcmp(temp,"*---"))itog[t++]='j';
            if (!strcmp(temp,"-*-"))itog[t++]='k';
            if (!strcmp(temp,"*-**"))itog[t++]='l';
            if (!strcmp(temp,"--"))itog[t++]='m';
            if (!strcmp(temp,"-*"))itog[t++]='n';
            if (!strcmp(temp,"---"))itog[t++]='o';
            if (!strcmp(temp,"*--*"))itog[t++]='p';
            if (!strcmp(temp,"--*-"))itog[t++]='q';
            if (!strcmp(temp,"*-*"))itog[t++]='r';
            if (!strcmp(temp,"***"))itog[t++]='s';
            if (!strcmp(temp,"-"))itog[t++]='t';
            if (!strcmp(temp,"**-"))itog[t++]='u';
            if (!strcmp(temp,"***-"))itog[t++]='v';
            if (!strcmp(temp,"*--"))itog[t++]='w';
            if (!strcmp(temp,"-**-"))itog[t++]='x';
            if (!strcmp(temp,"-*--"))itog[t++]='y';
            if (!strcmp(temp,"--**"))itog[t++]='z';

            temp[0]=0;
            temp[1]=0;
            temp[2]=0;
            temp[3]=0;
            temp[4]=0;
            itog[t]=0;
            }
        if (str[i]==' ') itog[t++]=' ';
        
        }
    gout(itog,70,685,35);
    }
    
void morze(char* str){
     outtextxy(15,285,"Итог :");
     setcolor(COLOR(10,106,209));
     outtextxy(15,15,"Введите текст и нажмите ввод :"); 
     setcolor(COLOR(255,255,255));
     gin(str,N,82,15,35);
     outtextxy(15,15,"Введите текст и нажмите ввод :"); 

     char* total;
     total=new char [6*strlen(str)];  
     int j=0;
     for(int i=0;i<strlen(str);i++){
            
            if (str[i]=='0'){
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     tire();
     tire();
     tire();
     tire();
     tire();
     }
     if (str[i]=='1'){
     total[j++]='*';
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     tchk();
     tire();
     tire();
     tire();
     tire();
     }
     
     if (str[i]=='2'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     tchk();
     tchk();
     tire();
     tire();
     tire();
     }
     if (str[i]=='3'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     total[j++]='-';
     total[j++]='-';
     tchk();
     tchk();
     tchk();
     tire();
     tire();
     }
     
     if (str[i]=='4'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     total[j++]='-';
     tchk();
     tchk();
     tchk();
     tchk();
     tire();
     }
     if (str[i]=='5'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     tchk();
     tchk();
     tchk();
     tchk();
     tchk();
     }
     if (str[i]=='6'){
     total[j++]='-';
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     tire();
     tchk();
     tchk();
     tchk();
     tchk();
     }
     if (str[i]=='7'){
     total[j++]='-';
     total[j++]='-';
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     tire();
     tire();
     tchk();
     tchk();
     tchk();
     }
     if (str[i]=='8'){
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     total[j++]='*';
     total[j++]='*';
     tire();
     tire();
     tire();
     tchk();
     tchk();
     }
     if (str[i]=='9'){
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     total[j++]='*';
     tire();
     tire();
     tire();
     tire();
     tchk();
     }
            
     if (str[i]=='A'||str[i]=='a'){
     total[j++]='*';
     total[j++]='-';
     tchk();
     tire();
     }
     if (str[i]=='B'||str[i]=='b'){
     total[j++]='-';
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     tire();
     tchk();
     tchk();
     tchk();
     }
     if (str[i]=='C'||str[i]=='c'){
     total[j++]='-';
     total[j++]='*';
     total[j++]='-';
     total[j++]='*';
     tire();
     tchk();
     tire();
     tchk();
     }
     if (str[i]=='D'||str[i]=='d'){
     total[j++]='-';
     total[j++]='*';
     total[j++]='*';
     tire();
     tchk();
     tchk();
     }
     if (str[i]=='E'||str[i]=='e'){
     total[j++]='*';
     tchk();}
     if (str[i]=='F'||str[i]=='f'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='-';
     total[j++]='*';
     tchk();
     tchk();
     tire();
     tchk();
     }
     if (str[i]=='G'||str[i]=='g'){
     total[j++]='-';
     total[j++]='-';
     total[j++]='*';
     tire();tire();tchk();}
     if (str[i]=='H'||str[i]=='h'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     tchk();tchk();tchk();tchk();}
     if (str[i]=='I'||str[i]=='i'){
     total[j++]='*';
     total[j++]='*';
     tchk();tchk();}
     if (str[i]=='J'||str[i]=='j'){
     total[j++]='*';
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     tchk();tire();tire();tire();}
     if (str[i]=='K'||str[i]=='k'){
     total[j++]='-';
     total[j++]='*';
     total[j++]='-';
     tire();tchk();tire();}
     if (str[i]=='L'||str[i]=='l'){
     total[j++]='*';
     total[j++]='-';
     total[j++]='*';
     total[j++]='*';
     tchk();tire();tchk();tchk();}
     if (str[i]=='M'||str[i]=='m'){
     total[j++]='-';
     total[j++]='-';
     tire();tire();}
     if (str[i]=='N'||str[i]=='n'){
     total[j++]='-';
     total[j++]='*';
     tire();tchk();}
     if (str[i]=='O'||str[i]=='o'){
     total[j++]='-';
     total[j++]='-';
     total[j++]='-';
     
     tire();tire();tire();}
     if (str[i]=='P'||str[i]=='p'){
     total[j++]='*';
     total[j++]='-';
     total[j++]='-';
     total[j++]='*';
     tchk();tire();tire();tchk();}
     if (str[i]=='Q'||str[i]=='q'){
     total[j++]='-';
     total[j++]='-';
     total[j++]='*';
     total[j++]='-';
     tire();tire();tchk();tire();}
     if (str[i]=='R'||str[i]=='r'){
     total[j++]='*';
     total[j++]='-';
     total[j++]='*';
     tchk();tire();tchk();}
     if (str[i]=='S'||str[i]=='s'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     tchk();tchk();tchk();}
     if (str[i]=='T'||str[i]=='t'){
     total[j++]='*';
     tire();}
     if (str[i]=='Y'||str[i]=='y'){
     total[j++]='-';
     total[j++]='*';
     total[j++]='-';
     total[j++]='-';
     tire();tchk();tire();tire();}
     if (str[i]=='U'||str[i]=='u'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='-';
     tchk();tchk();tire();}
     if (str[i]=='V'||str[i]=='v'){
     total[j++]='*';
     total[j++]='*';
     total[j++]='*';
     total[j++]='-';
     tchk();tchk();tchk();tire();}
     if (str[i]=='W'||str[i]=='w'){
     total[j++]='*';
     total[j++]='-';
     total[j++]='-';
     tchk();tire();tire();}
     if (str[i]=='X'||str[i]=='x'){
     total[j++]='-';
     total[j++]='*';
     total[j++]='*';
     total[j++]='-';
     tire();tchk();tchk();tire();}
     if (str[i]=='Z'||str[i]=='z'){
     total[j++]='-';
     total[j++]='-';
     total[j++]='*';
     total[j++]='*';
     tire();tire();tchk();tchk();}
    if (str[i]==' '){total[j++]=' ';
    delay(3726);
    }
    delay(621);
     if (str[i]!='|')total[j++]='|';
     }
     setfillstyle(1,COLOR(0,0,0));
     bar(15,315,960,710);
     setcolor(COLOR(10,106,209));
     outtextxy(15,285,"Итог :");
     setcolor(COLOR(255,255,255)); 
     total[j]=0;
     gout(total,70,15,320);
}

void crpt(char* string,char* itog){  
int key,i;
    outtextxy(685,15,"Итог :");
    setcolor(COLOR(10,106,209));
    outtextxy(15,15,"Введите текст и нажмите ввод :");
    setcolor(COLOR(255,255,255));
    gin(string,L,38,15,35);
    outtextxy(15,15,"Введите текст и нажмите ввод :");
    setcolor(COLOR(10,106,209));
    outtextxy(15,605,"Введите ключ-число и нажмите ввод :");
    setcolor(COLOR(255,255,255)); 
    key=inpnum(nu,3,2,15,625);
    outtextxy(15,605,"Введите ключ-число и нажмите ввод :");
	for (int i =0; i<strlen(string);++i)
		itog[i]=string[i]^key;
		setfillstyle(1,COLOR(0,0,0));
        bar(685,35,1270,580);  
        setcolor(COLOR(10,106,209));
        outtextxy(685,15,"Итог :");
        setcolor(COLOR(255,255,255));  
		gout(itog,38,685,35);
		for(i=0;itog[i]!=0;i++)   
        itog[i]=0;
}
