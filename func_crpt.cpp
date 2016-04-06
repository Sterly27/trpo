void crpt(char* string,int key)
{ 
	for (int i =0; i<strlen(string);++i)
	{
		if(string[i]<key) string[i]+=95
		string[i]^=key;
		if(string[i]>126) string[i]-=95;
	}
	return;
}
