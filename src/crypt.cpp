#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <locale>
#include <conio.h>
//#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;
const int N=1024;
void msg();
char crpt(char* string,int key);
int main()
{
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

char crpt(char* string,int key)
{ 
	for (int i =0; i<strlen(string);++i)
	{
		if(string[i]<key) string[i]+=95
		string[i]^=key;
		if(string[i]>126) string[i]-=95;
	}
	return string;
}
