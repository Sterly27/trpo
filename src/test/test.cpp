#include <string.h>
#include "../crypt.h"

CTEST ( morze, test1 )
{
  const char a[] = "hello world, how you doing?";
  const char b[] = "****|*|*-**|*-**|---| |*--|---|*-*|*-**|-**|*-*-*-| |****|---|*--| |-*--|---|**-| |-**|---|**|-*|--*|**--**|";
  char* c;
  char d[] = "hello world, how you doing?";
	c = new char[strlen(a)*10];
  morze(d, c);
  assert_str(b, c, "a", 1);   
}

CTEST ( morze, test2 )
{
char a[] = "";
char* c;
c = new char [15];
morze(a, c);
	const char b[] = "";
  assert_str(c, b, "a", 1);
}

CTEST ( morze, test3 )
{
char b[] = "*-|*-|--**|--**|*----|**---|***--|****-|*****|-****|--***|---**|----*|-----|*-*-*-|******|**--**|--**--|";
char a[] = "aAzZ1234567890,.?!";
char* c = new char[strlen(a)*10];
morze(a, c);
assert_str(b, c, "a", 1);
}
CTEST ( morze, test4 ){
char b[] = "~Хелло/*--=():%;№&*^$#@";
char a[] = "ERROR";
char* c = new char[strlen(a)*10];
morze (b, c);
assert_str(a, c, "a", 1);
}

CTEST ( demorze, test1 )
{
  const char a[] = "hello world, how you doing?";
  char b[] = "****|*|*-**|*-**|---| |*--|---|*-*|*-**|-**|*-*-*-| |****|---|*--| |-*--|---|**-| |-**|---|**|-*|--*|**--**|";
  demorze(b);
  assert_str(a, b, "a", 1);
}

CTEST ( demorze, test2 )
{
char a[1];
a[0] = 0;
char c[] = "";
demorze (a);
assert_str(c, a, "a", 1);
}

CTEST ( demorze, test3 )
{
char a[] = "aAzZ1234567890,.?!";
char b[] = "*-|*-|--**|--**|*----|**---|***--|****-|*****|-****|--***|---**|----*|-----|*-*-*-|******|**--**|--**--|";
char exp[] = "aazz1234567890,.?!";
demorze(b);
assert_str(exp, b, "a", 1);
}

CTEST ( demorze, test4 )
{
char a[] = "~@$%%^&*()_*^%%*#()#><<";
char b[] = "";
demorze(a);
assert_str (b, a, "a", 1);
}

