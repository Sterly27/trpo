#include <string.h>
#include "../src/crypt_func.h"
CTEST (vigi,test1){
char a[]="a";
char b[]="a";
vig (a,b);

assert_str(a,b,"",1);
}
