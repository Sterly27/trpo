//#include "/home/me/TRPO/thirdparty/ctest.h"
//#include "/home/me/TRPO/src/crypt_func.h"
#include <string.h>
#include "crypt_func.h"
#include "ctest.h"
CTEST (sname, test1){
  const char a[]="hello world, how you doing?";
  const char b[]="****|*|*-**|*-**|---| |*--|---|*-*|*-**|-**|*-*-*-| |****|---|*--| |-*--|---|**-| |-**|---|**|-*|--*|**--**|";
  char* c;
  char d[]="hello world, how you doing?";
	c=new char[strlen(a)*10];
  morze(d,c);
  
  assert_str(b,c,"a",1);
    
}

CTEST(sname, test2){
  const char a[]="hello world, how you doing?";
  char b[]="****|*|*-**|*-**|---| |*--|---|*-*|*-**|-**|*-*-*-| |****|---|*--| |-*--|---|**-| |-**|---|**|-*|--*|**--**|";
  demorze(b);
  
  assert_str(b,a,"a",1);
    

}
