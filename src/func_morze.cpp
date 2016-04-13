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
    itog=new char [strlen(str)];
    char temp[5]={0,0,0,0,0};
    
    int f=0,t=0;
    for (int i=0;i<strlen(str);i++){
        if (str[i]!='|') temp[f++]=str[i];
        if (str[i]==' '||str[i]=='|'||i==strlen(str)-1) {
            f=0;
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

            temp[0]=0;
            temp[1]=0;
            temp[2]=0;
            temp[3]=0;
            temp[4]=0;
            itog[t]=0;
            }
        if (str[i]==' ') itog[t++]=' ';
        
        }
    return itog;
    }
char* morze(char* str){
     char* total;
     total=new char [strlen(str)*8];  
     int j=0;
     for(int i=0;i<strlen(str);i++){
            
     if (strp[i]=='.'){
	 total[j++]='*';
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
	 tchk();
	 }
     if (str[i]==','){
	 total[j++]='*';
	 total[j++]='-';
	 total[j++]='*';
	 total[j++]='-';
	 total[j++]='*';
	 total[j++]='-';
	 tchk();
	 tire();
	 tchk();
	 tire();
	 tchk();
	 tire();
		 }
	 if (strp[i]=='!'){
	 total[j++]='-';
	 total[j++]='-';
	 total[j++]='*';
	 total[j++]='*';
	 total[j++]='-';
	 total[j++]='-';
	 tire();
	 tire();
	 tchk();
	 tchk();
	 tire();
	 tire();
	 }
	 if (strp[i]=='?'){
	 total[j++]='*';
	 total[j++]='*';
	 total[j++]='-';
	 total[j++]='-';
	 total[j++]='*';
	 total[j++]='*';
	 tchk();
	 tchk();
	 tire();
	 tire();
	 tchk();
	 tchk();
	 }
		 
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
    if (str[i]==' '){total[j++]=' ';delay(3726);}
     
     delay(621);
     if (str[i]!='|')total[j++]='|';
     }
     total[j]=0;
     return total;
}
