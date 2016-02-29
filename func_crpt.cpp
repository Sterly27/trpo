void crpt(char* string,int key)
{
	for (int i =0; i<strlen(string);++i)
		string[i]^=key;
	return;
}