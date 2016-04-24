#include <stdlib.h>
#include "crypt_func.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

const int N=1024;

int main(){
	int menu,exit=0,i,key2;
	char str[N],*strm,key1[N],paus[1];	
	 
	//---------------------------------------------MENU----------------------------------------//
	while(!exit){
		//----------------------------------------RESET--------------------------------//
		key2=0;
		for(i=0;str[i]!=0;i++){
		    str[i]=0;
	    } 
		for(i=0;str[i]!=0;i++){
		    strm[i]=0;
	    } 
		for(i=0;str[i]!=0;i++){
		    key1[i]=0;
	    } 
	    //---------------------------------------END_RESET-----------------------------------//
	    system("cls||clear");
	    cout<<"1)Encrypt\n\n";
	    cout<<"2)Decrypt\n\n";
	    cout<<"3)Exit\n\n";
		scanf("%i",&menu);
		switch(menu){
			case 1:
				while(menu!=4){
					system("cls||clear");
					cout<<"1)Vigener\n\n";
					cout<<"2)Caesar\n\n";
					cout<<"3)Morze\n\n";
					cout<<"4)Back\n\n";
					scanf("%i",&menu);
					switch(menu){
						case 1://--------------------CRYPT_VIGI-------------------//
							system("cls||clear");
							cout<<"Enter text:\n";
							cin.getline(str,N);
							cin.getline(str,N);
							cout<<"Enter text:\n";
							cin.getline(key1,N);
							if(vig(str,key1) > 0){
								system("cls||clear");
								cout<<"Error: invalid symbols.";
								cin>>paus;
								break;
							} 
							else if(vig(str,key1) < 0){
								system("cls||clear");
								cout<<"Error: string/key is empty.";
								cin>>paus;
								break;                 
							} 
							cout<<"Encrypted text:\n" << str;
							cin>>paus;
							break;
						case 2://-------------------CRYPT_CEASER------------------//
							system("cls||clear");
							cout<<"Enter text:\n";
							cin.getline(str,N);
							cin.getline(str,N);
							cout<<"Enter key:\n";
							scanf("%i",&key2);
							crpt(str,key2);
							cout<<"Encrypted text:\n" << str;
							cin>>paus;
							break;
						case 3://-------------------CRYPT_MORZE------------------//
							system("cls||clear");
							cout<<"Enter text:\n";
							cin.getline(str,N);
							cin.getline(str,N);
							strm=new char [strlen(str)*10];
							morze(str,strm);
							cout<<"Encrypted text:\n" << strm;
							cin>>paus;
							break;
						case 4://-------------------BUTTON_BACK------------------//
							break;
						default://----------------OTHER_OPTIONS-----------------//
							system("cls||clear");
							cout<<"This menu item does not exist.\n\n";
							cin>>paus;
					}
				}
				break;
			case 2:
				while(menu!=4){
					system("cls||clear");
					cout<<"1)Vigener\n\n";
					cout<<"2)Caesar\n\n";
					cout<<"3)Morze\n\n";
					cout<<"4)Back\n\n";
					scanf("%i",&menu);
					switch(menu){
						case 1://-------------------DECRYPT_VIGI------------------//
							system("cls||clear");
							cout<<"Enter text:\n";
							cin.getline(str,N);
							cin.getline(str,N);
							cout<<"Enter key:\n";
							cin.getline(key1,N);
							if(devig(str,key1) > 0){
								system("cls||clear");
								cout<<"Error: invalid symbols.";
								cin>>paus;
								break;
							}
							else if(devig(str,key1) < 0){
								system("cls||clear");
								cout<<"Error: string/key is empty.";
								cin>>paus;
								break;                 
							}        
							cout<<"Decrypted text:\n" << str;
							cin>>paus;
							break;
						case 2://------------------DECRYPT_CEASER-----------------//
							system("cls||clear");
							cout<<"Enter text:\n";
							cin.getline(str,N);
							cin.getline(str,N);
							cout<<"Enter key:\n";
							scanf("%i",&key2);
							crpt(str,key2);
							cout<<"Decrypted text:\n" << str;
							cin>>paus;
							break;
						case 3://------------------DECRYPT_MORZE-----------------//
							system("cls||clear");
							cout<<"Enter text:\n";
							cin.getline(str,N);
							cin.getline(str,N);
							demorze(str);
							cout<<"Decrypted text:\n" << str;
							cin>>paus;
							break;
						case 4://------------------BUTTON_BACK-------------------//
							break;
						default://----------------OTHER_OPTIONS-----------------//
							system("cls||clear");
							cout<<"This menu item does not exist.\n\n";
							cin>>paus;
					}
				}
				break;
			case 3://----------------------------EXIT------------------------------//
				exit=1;
				system("cls||clear");
				break;
			case 45:
			    system("cls||clear");
				cout<<"Group IP-513 thanks you for using our software!";
				cin>>paus;
				break;
			default://------------------------OTHER_OPTIONS--------------------------//
				system("cls||clear");
				cout<<"This menu item does not exist.\n\n";
				cin>>paus;
				break;	
		}
	}
	//-----------------------------------------MENU_END-------------------------------------//
return 0;
}
