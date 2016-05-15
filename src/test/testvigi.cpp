#include <string.h>
#include "../crypt.h"

CTEST (vigi,test1pt1){
      // General operability
char a[]=" !##$'&'()*+,-./0123456789:;<=>?@ABC";
char b[]=" !\"";
vig (a,b);
char d[]="!#&$&*')+*,.-/102435768:9;=<>@?ACBDF";
assert_str(d,a,"",1);
}

CTEST (vigi,test1pt2){
      // General operability
char a[]="DEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
char b[]=" !\"";
vig (a,b);
char d[]="EGIHJLKMONPRQSUTVXWY[Z\\^]_a`bdcegfhjikmlnpoqsrtvuwyxz|{} ~!";
assert_str(d,a,"",1);
}

CTEST (devigi,testde1pt1){
      // General operability
char a[]="!#&$&*')+*,.-/102435768:9;=<>@?ACBDF";
char b[]=" !\"";
char d[]=" !##$'&'()*+,-./0123456789:;<=>?@ABC";
devig (a,b);
assert_str(d,a,"",1);
}

CTEST (devigi,testde1pt2){
      // General operability
char a[]="DEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
char b[]=" !\"";
char d[]="EGIHJLKMONPRQSUTVXWY[Z\\^]_a`bdcegfhjikmlnpoqsrtvuwyxz|{} ~!";
devig (d,b);
assert_str(a,d,"",1);
}


CTEST (vigi,test2){
      //double substraction
char a[]="o";
char b[]="o";
vig (a,b);
char d[]="`";
assert_str(d,a,"",1);
}

CTEST (devigi,testde2){
      //double addition
char a[]="`";
char b[]="o";
devig (a,b);
char d[]="o";
assert_str(d,a,"",1);
}

CTEST (vigi,test3){
      //max result of substraction
char a[]="~";
char b[]="~";
vig (a,b);
char d[]="~";
assert_str(d,a,"",1);
}

CTEST (devigi,testde3){
      //max result of addition
char a[]="~";
char b[]="~";
devig (a,b);
char d[]="~";
assert_str(d,a,"",1);
}



CTEST (vigi,test4){
      //max result of substraction
char a[]="%";
char b[]="\"";
vig (a,b);
char d[]="(";
assert_str(d,a,"",1);
}

CTEST (devigi,testde4){
      //max result of addition
char a[]="(";
char b[]="\"";
devig (a,b);
char d[]="%";
assert_str(d,a,"",1);
}


CTEST (vigi,bd_er1){
char a[]="фывапро";
char b[]="\"";
int i=vig (a,b);
int d=1;
assert_dbl_near(d,i,0.5,"",1);
}



CTEST (devigi,bd_er1){
char a[]="фывапро";
char b[]="\"";
devig (a,b);
int i = devig(a,b);
int d=1;
assert_dbl_near(d,i,0.5,"",1);
}

CTEST (vigi,bd_er_minus1){
char a[]="";
char b[]="\"";
devig (a,b);
int i = vig(a,b);
int d=-1;
assert_dbl_near(d,i,0.5,"",1);
}

CTEST (devigi,bd_er_minus1){
char a[]="фывапро";
char b[]="";
devig (a,b);
int i = devig(a,b);
int d=-1;
assert_dbl_near(d,i,0.5,"",1);
}

