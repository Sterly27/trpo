#include <stdio.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <locale>
#include <graphics.h>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;
const int N=1024;

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

void msg();
void crpt(char* string,int key);
int main()
{
    char a[100];
    scanf("%s",a);
    morze(a);
  setlocale(LC_ALL,"Russian");
  system("PAUSE");
}

void msg()
{
	char string[N];
	int key;
	cout<<"Enter message"<<endl;
	cout<<"> ";
	gets(string);
	cout<<endl;
	cout<<"Enter key(int number)"<<endl;
	cout<<"> ";
	cin>>key;
	scr(string,key);
	cout<<"> ";
	ofstream crypt("crypt.txt",ios_base::app);
	crypt<<"> "<<string<<endl;
	crypt.close();
	cout<<string<<endl;
	return;
}

void crpt(char* string,int key)
{
	for (int i =0; i<strlen(string);++i)
		string[i]^=key;
	return;
}

