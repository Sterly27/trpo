#include <string.h>
#include <stdio.h>


     
void demorze(char* str){
    char* itog;
	itog=new char [strlen(str)+1];
    char temp[8]={0,0,0,0,0,0,0,0};
    
	int f=0,t=0,nbukv=1;
	
	for (unsigned int i=0;i<strlen(str);i++){
		if (str[i]=='|')
			nbukv++;
		if (str[i]!='|'&&str[i]!='*'&&str[i]!='-'
			&&str[i]!=' '&&str[i]!='\n'){
			itog[0]=0;
			strcpy(str,itog);
			return;
			}
			
	}
	unsigned int i=0;

	for (int j=0;j<nbukv;j++){
		f=0;

		while (str[i]!='|'&&i!=strlen(str)){
			if (str[i]!='\n')
				temp[f++]=str[i];
			i++;
		}
		i++;

	if (!strcmp(temp,"******"))itog[t++]='.';
	if (!strcmp(temp,"*-*-*-"))itog[t++]=',';
		if (!strcmp(temp,"--**--"))itog[t++]='!';
		if (!strcmp(temp,"**--**"))itog[t++]='?';

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
		if (!strcmp(temp," "))itog[t++]=' ';
            temp[0]=0;
            temp[1]=0;
            temp[2]=0;
            temp[3]=0;
            temp[4]=0;
            temp[5]=0;
            temp[6]=0;
            temp[7]=0;
			itog[t]=0;
	}
strcpy(str,itog);
delete itog;
}

void morze(char* str, char* total){  
 int j=0;
	//Allowed CHARs************
	int LeftEdge1 = 'a';
	int RightEdge1 = 'z';
	int RightEdge2 = 'Z';
	int LeftEdge2 = 'A';

	int NumLeftEdge = '0';
	int NumRightEdge = '9';
	//**************************
	int stop=0;


for(unsigned int i=0;i<strlen(str);i++){

	if (str[i]=='\n')
		continue;

	if (!(
			(str[i]>=LeftEdge1&&str[i]<=RightEdge1)||
			(str[i]>=LeftEdge2&&str[i]<=RightEdge2)||
			(str[i]>=NumLeftEdge&&str[i]<=NumRightEdge)||
			str[i]=='?'||str[i]=='.'||str[i]==','||
			str[i]=='!'||str[i]==' ')
			) {
		stop=1;
	}


	if(stop){
		total[0]='E';
		total[1]='R';
		total[2]='R';
		total[3]='O';
		total[4]='R';
		total[5]=0;
		return;
	}

	if (str[i]=='.'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
	 }
	 if (str[i]==','){
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='-';
			 }
	 if (str[i]=='!'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
	 }
	 if (str[i]=='?'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
	 }
		 
 if (str[i]=='0'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
     }
 if (str[i]=='1'){
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
     }
     
 if (str[i]=='2'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
     }
 if (str[i]=='3'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
     }
 if (str[i]=='4'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
	 }
 if (str[i]=='5'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
     }
 if (str[i]=='6'){
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
     }
 if (str[i]=='7'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
     }
 if (str[i]=='8'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
     }
 if (str[i]=='9'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
     }

 if (str[i]=='A'||str[i]=='a'){
		 total[j++]='*';
		 total[j++]='-';
     }
 if (str[i]=='B'||str[i]=='b'){
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
     }
 if (str[i]=='C'||str[i]=='c'){
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='*';
     }
 if (str[i]=='D'||str[i]=='d'){
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
     }
 if (str[i]=='E'||str[i]=='e'){
		 total[j++]='*';
	 }
 if (str[i]=='F'||str[i]=='f'){total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='*';
     }
 if (str[i]=='G'||str[i]=='g'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
}
 if (str[i]=='H'||str[i]=='h'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
	 }
 if (str[i]=='I'||str[i]=='i'){
		 total[j++]='*';
		 total[j++]='*';
}
 if (str[i]=='J'||str[i]=='j'){
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
	 }
 if (str[i]=='K'||str[i]=='k'){
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='-';
	 }
 if (str[i]=='L'||str[i]=='l'){
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
	 }
 if (str[i]=='M'||str[i]=='m'){
		 total[j++]='-';
		 total[j++]='-';
	 }
 if (str[i]=='N'||str[i]=='n'){
		 total[j++]='-';
		 total[j++]='*';
	 }
 if (str[i]=='O'||str[i]=='o'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='-';
	 }
 if (str[i]=='P'||str[i]=='p'){
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
	 }
 if (str[i]=='Q'||str[i]=='q'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='-';
	 }
 if (str[i]=='R'||str[i]=='r'){
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='*';
	 }
 if (str[i]=='S'||str[i]=='s'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
	 }
 if (str[i]=='T'||str[i]=='t'){
		total[j++]='*';
	 }
 if (str[i]=='Y'||str[i]=='y'){
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
	 }
 if (str[i]=='U'||str[i]=='u'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
	 }
 if (str[i]=='V'||str[i]=='v'){
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
	 }
 if (str[i]=='W'||str[i]=='w'){
		 total[j++]='*';
		 total[j++]='-';
		 total[j++]='-';
	 }
 if (str[i]=='X'||str[i]=='x'){
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
		 total[j++]='-';
	 }
 if (str[i]=='Z'||str[i]=='z'){
		 total[j++]='-';
		 total[j++]='-';
		 total[j++]='*';
		 total[j++]='*';
	 }
	if (str[i]==' '){
		total[j++]=' ';
	}

	 if (str[i] != '|')
		 total[j++]='|';
}

     total[j]=0;
}
