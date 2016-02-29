#include <stdio.h>
#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;
const int N=1024;
void msg();
void crpt(char* string,int key);
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

void crpt(char* string,int key)
{
	for (int i =0; i<strlen(string);++i)
		string[i]^=key;
	return;
}