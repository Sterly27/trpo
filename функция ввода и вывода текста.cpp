#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int N=663; 

void fon(){
     //---------------------------------------
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
      //---------------------------------------------
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
      outtextxy(685,15,"Зашифрованный текст :");
      bar(10,435,680,710); 
      outtextxy(15,440,"Введите ключ и нажмите ввод :");
      settextstyle(8,0,19);
      outtextxy(970,600,"Назад");
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
       if((key>64&&key<91)||(key>96&&key<123)||(key==32)||(key==-72||key==-88)||(key>-65&&key<0)){
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

char str[N], str1[N], str2[N];

void vig(char a[],char b[],char c[]){
int i=0,j=0;
outtextxy(685,15,"Зашифрованный текст :");
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
setcolor(COLOR(10,106,209));
outtextxy(685,15,"Зашифрованный текст :");
setcolor(COLOR(255,255,255));  
gout(c,38,685,35);
for(i=0;c[i]!=0;i++)   
      c[i]=0; 
      
for(i=0;b[i]!=0;i++)
      b[i]+=40;                
}
 

int main(){
int menu=-1,i=0;

      initwindow(1280,720);
      while(1){                  
      fon();
      for(i=0;str[i]!=0;i++){
      str[i]=0;
      if(str1[i]!=0)
      str1[i]=0;                
      }
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
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>965&&mousex()<1200&&mousey()>595&&mousey()<675){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=4;
        break;                                                                                         
        }       
      }
      if(menu==1||menu==4) break;
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
        menu=2;
        break;                                                                                         
        }        
        if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>965&&mousex()<1200&&mousey()>595&&mousey()<675){
        cleardevice();
        clearmouseclick(WM_LBUTTONDOWN);
        menu=4;
        break;                                                                                         
        }       
      }
      if(menu==2||menu==4) break;
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
vig(str,str1,str2);
}
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>965&&mousex()<1200&&mousey()>595&&mousey()<675){
cleardevice();
clearmouseclick(WM_LBUTTONDOWN);
menu=-1;
settextstyle(8,0,19);
load(900,690,4);
break;                                                                                         
}
}
}  
if(menu==2){
load(900,690,4);                             
settextstyle(8,0,1);   
winf();
while(1){
clearmouseclick(WM_LBUTTONDOWN);
delay(30);         
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>5&&mousex()<605&&mousey()>5&&mousey()<400)         
vig(str,str1,str2);
if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>965&&mousex()<1200&&mousey()>595&&mousey()<675){
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
