#include <string.h>
#include "../src/crypt_func.h"
CTEST (vigi,test1){
      // General operability
char a[]=" !\"#$%%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
char b[]=" !\"";
vig (a,b);
char d[]="!#%%$&(')+*,.-/102435768:9;=<>@?ACBDFEGIHJLKMONPRQSUTVXWY[Z\\^]_a`bdcegfhjikmlnpoqsrtvuwyxz|{} ~!";
assert_str(d,a,"",1);
}

CTEST (vigi,test2){
      //double substraction
char a[]="o";
char b[]="o";
vig (a,b);
char d[]=" ";
assert_str(d,a,"",1);
}

CTEST (devigi,test3){
      //double addition
char a[]=" ";
char b[]="o";
devig (a,b);
char d[]="o";
assert_str(d,a,"",1);
}

CTEST (devigi,test3){
      //max result of substraction
char a[]=")";
char b[]="~";
vig (a,b);
char d[]="~";
assert_str(d,a,"",1);
}

CTEST (vigi,test3){
      //max result of addition
char a[]="~";
char b[]="~";
vig (a,b);
char d[]=")";
assert_str(d,a,"",1);
}
