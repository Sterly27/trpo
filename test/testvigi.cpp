#include <string.h>
#include "../src/crypt_func.h"
CTEST (vigi,test1){
char a[]=" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
char b[]=" !\"";
vig (a,b);
char d[]="!#%$&(')+*,.-/102435768:9;=<>@?ACBDFEGIHJLKMONPRQSUTVXWY[Z\\^]_a`bdcegfhjikmlnpoqsrtvuwyxz|{} ~!"
assert_str(d,a,"",1);
}

CTEST (vigi,test2){
char a[]="o";
char b[]="o";
vig (a,b);
char d[]=" "
assert_str(d,a,"",1);
}

CTEST (devigi,test3){
char a[]=" ";
char b[]="o";
devig (a,b);
char d[]="o"
assert_str(d,a,"",1);
}

CTEST (devigi,test3){
char a[]=")";
char b[]="~";
vig (a,b);
char d[]="~"
assert_str(d,a,"",1);
}

CTEST (vigi,test3){
char a[]="~";
char b[]="~";
vig (a,b);
char d[]=")"
assert_str(d,a,"",1);
}
