#include "../thirdparty/ctest.h"
#include "../src/crypt_func.h"
//crypt
CTEST(distance_suite, NO_ERROR_CRYPT)
{	
	char str[] = "1234567890+-qwertyuiop[]';?><}{[]:lkjhgfdsazxcvbnm,./%@!$^&*()_=";
	int key = 3;
	
	char distance = crpt(str,key);

	char expected_d = "2107654;:3(.rtfqwzvjlsX^$8<=?~xX^9ohikdegpby{`uamn/-,&C"']%)+*\>";

	ASSERT_STR(expected_d,distance);
}

CTEST(distance_suite, EMPTY_KEY)
{
	char str[] = "aaaaa";
	int key;
	
	int distance = crpt(str,key);

	double expected_d = 1;

	ASSERT_DBL_NEAR(expected_d,distance);
}

CTEST(distance_suite, EMPTY_STR)
{
	char str[] = "";
	int key = 3;
	int distance = crpt(str,key);

	double expected_d = 1;

	ASSERT_DBL_NEAR(expected_d,distance);
}
//decrypt
CTEST(distance_suite, NO_ERROR_DECRYPT)
{	
	char str[] = "2107654;:3(.rtfqwzvjlsX^$8<=?~xX^9ohikdegpby{`uamn/-,&C"']%)+*\>";
	int key = 3;
	
	char distance = crpt(str,key);

	char expected_d = "1234567890+-qwertyuiop[]';?><}{[]:lkjhgfdsazxcvbnm,./%@!$^&*()_=";

	ASSERT_STR(expected_d,distance);
}
