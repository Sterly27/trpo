#include <ctest.h>
#include <func.h>
#include <string.h>

CTEST (sname, test1){
  const char a[]="Hello world, how you doing?";
  const char b[]="****|*|*-**|*-**|---| |*--|---|*-*|*-**|-**|*-*-*-| |****|---|*--| |-*--|---|**-| |-**|---|**|-*|--*|---*";
    const char* c;
  c=morze(a);
  
  ASSERT_STR(b,c);
    
}

CTEST(sname, test2){
  const char a[]="Hello world, how you doing?";
  const char b[]="****|*|*-**|*-**|---| |*--|---|*-*|*-**|-**|*-*-*-| |****|---|*--| |-*--|---|**-| |-**|---|**|-*|--*|---*";
    const char* c;
  *c=demorze(b);
  
  ASSERT_STR(a,c);
    

}
