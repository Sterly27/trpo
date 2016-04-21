#include <stdlib.h>
#include "crypt_func.h"
#include <stdio.h>
#include <string.h>

const int N=1024;

int main(){
	int menu,exit=0,i,key2;
	char str[N],*strm,key1[N],paus[1];	
	 
	//---------------------------------------------MENU----------------------------------------//
	while(exit!=1){
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
	    printf("1)Encrypt\n\n");
	    printf("2)Decrypt\n\n");
	    printf("3)Exit\n\n");
		scanf("%i",&menu);
		switch(menu){
			case 1:
	            system("cls||clear");
	            printf("1)Vigener\n\n");
	            printf("2)Caesar\n\n");
	            printf("3)Morze\n\n");
	            printf("4)Back\n\n");
	            scanf("%i",&menu);
	            switch(menu){
	            	case 1://--------------------CRYPT_VIGI-------------------//
	            		system("cls||clear");
	            		printf("Enter text:\n");
	            	    gets(str);
	            	    gets(str);
	            		puts("Enter key:");
						gets(key1);
	            		vig(str,key1);
	            		puts("Encrypted text:");
	            		puts(str);
	            		gets(paus);
	            		break;
	            	case 2://-------------------CRYPT_CEASER------------------//
	            		system("cls||clear");
	            		printf("Enter text:\n");
	            		gets(str);
	            	    gets(str);
	            		printf("Enter key:\n");
						scanf("%i",&key2);
	            		crpt(str,key2);
	            		printf("Encrypted text:\n");
	            		puts(str);
	            		gets(paus);
	            		break;
	            	case 3://-------------------CRYPT_MORZE------------------//
				        system("cls||clear");
	            		printf("Enter text:\n");
	            		gets(str);
	            	    gets(str);
	            		strm=new char [strlen(str)*10];
	            		morze(str,strm);
	            		printf("Encrypted text:\n");
	            		puts(strm);
	            		gets(paus);
	            		break;
	            	case 4://-------------------BUTTON_BACK------------------//
	            		break;
	            	default://----------------OTHER_OPTIONS-----------------//
	            		system("cls||clear");
			            printf("This menu item does not exist.\n\n");
			            gets(paus);
				}
	            break;
			case 2:
				system("cls||clear");
	            printf("1)Vigener\n\n");
	            printf("2)Caesar\n\n");
	            printf("3)Morze\n\n");
	            printf("4)Back\n\n");
	            scanf("%i",&menu);
	            switch(menu){
	            	case 1://-------------------DECRYPT_VIGI------------------//
	            		system("cls||clear");
	            		printf("Enter text:\n");
	            		gets(str);
	            	    gets(str);
	            		printf("Enter key:\n");
						gets(key1);
	            		devig(str,key1);
	            		printf("Decrypted text:\n");
	            		puts(str);
	            		gets(paus);
	            		break;
	            	case 2://------------------DECRYPT_CEASER-----------------//
	            		system("cls||clear");
	            		printf("Enter text:\n");
	            		gets(str);
	            	    gets(str);
	            		printf("Enter key:\n");
						scanf("%i",&key2);
	            		crpt(str,key2);
	            		printf("Decrypted text:\n");
	            		puts(str);
	            		gets(paus);
	            		break;
	            	case 3://------------------DECRYPT_MORZE-----------------//
	            		system("cls||clear");
	            		printf("Enter text:\n");
	            		gets(str);
	            	    gets(str);
	            		demorze(str);
	            		printf("Encrypted text:\n");
	            		puts(str);
	            		gets(paus);
	            		break;
	            	case 4://------------------BUTTON_BACK-------------------//
	            		break;
	            	default://----------------OTHER_OPTIONS-----------------//
	            		system("cls||clear");
			            printf("This menu item does not exist.\n\n");
			            gets(paus);
			            break;
				}
	            break;
			case 3://----------------------------EXIT------------------------------//
				exit=1;
				break;
			default://------------------------OTHER_OPTIONS--------------------------//
			system("cls||clear");
			printf("This menu item does not exist.\n\n");
			gets(paus);
			break;	
		}
	}
	//-----------------------------------------MENU_END-------------------------------------//
return 0;
}
