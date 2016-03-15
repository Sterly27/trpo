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
     
char *morze(char* str){
     char* total;
     
     total=new char (4*strlen(str));
     
printf("%i",strlen(str));     

     int j=0;
     
     for(int i=0;i<strlen(str);i++){
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
     if (str[i]=='F'||str[i]=='f'){total[j++]='*';
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
     total[j++]='*';
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
    if (str[i]==' '){ delay(3726);}
     
     delay(621);
     total[j++]='|';
     }
     total[j++]=0;
     printf("\n------------------Crypted successfully!-------------------\n");
     return total;
}

void msg();
void crpt(char* string,int key);
int main()
{
    char a[100],*itog;
    
    scanf("%s",a);
    
    itog=morze(a);
    
    printf("%s\n",itog);
  setlocale(LC_ALL,"Russian");
  system("PAUSE");
}
/*
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
	//(string,key);
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

*/
