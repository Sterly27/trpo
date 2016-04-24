#include <string.h>
#include "../src/crypt_func.h"

CTEST (vigi,test1ver1){
      // General operability
char a[]=" !##$'&'()*+,-./0123456789:;<=>?@ABC";
char b[]=" !\"";
vig (a,b);
char d[]="!#&$&*')+*,.-/102435768:9;=<>@?ACBDF";
assert_str(d,a,"",1);
}

CTEST (vigi,test1ver2){
      // General operability
char a[]="DEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
char b[]=" !\"";
vig (a,b);
char d[]="EGIHJLKMONPRQSUTVXWY[Z\\^]_a`bdcegfhjikmlnpoqsrtvuwyxz|{} ~!";
assert_str(d,a,"",1);
}

CTEST (vigi,test2){
      //double substraction
char a[]="o";
char b[]="o";
vig (a,b);
char d[]="'";
assert_str(d,a,"",1);
}

CTEST (devigi,test3){
      //double addition
char a[]="'";
char b[]="o";
devig (a,b);
char d[]="o";
assert_str(d,a,"",1);
}

CTEST (vigi,test4){
      //max result of substraction
char a[]="~";
char b[]="~";
vig (a,b);
char d[]="~";
assert_str(d,a,"",1);
}

CTEST (devigi,test3){
      //max result of addition
char a[]="~";
char b[]="~";
devig (a,b);
char d[]="~";
assert_str(d,a,"",1);
}

CTEST (devigi,test5ver5){
      // General operability
char a[]=" !\"#$%%&'()*+,-./0123456789:;<=>?@ABC";
char b[]=" !\"";
char d[]="!#%%$&(')+*,.-/102435768:9;=<>@?ACBDF";
devig (d,b);
assert_str(a,d,"",1);
}

CTEST (devigi,test5ver2){
      // General operability
char a[]="DEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
char b[]=" !\"";
char d[]="EGIHJLKMONPRQSUTVXWY[Z\\^]_a`bdcegfhjikmlnpoqsrtvuwyxz|{} ~!";
devig (d,b);
assert_str(a,d,"",1);
}

CTEST (vigi,test6){
      //max result of substraction
char a[]="%%";
char b[]="\"";
vig (a,b);
char d[]="(";
assert_str(d,a,"",1);
}

CTEST (devigi,testde6){
      //max result of addition
char a[]="(";
char b[]="\"";
devig (a,b);
char d[]="%%";
assert_str(d,a,"",1);
}
