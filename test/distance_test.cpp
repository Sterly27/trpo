#include "../thirdparty/ctest.h"
#include "../src/crypt_func.h"

CTEST_SKIP(distance_suite, NO_ERROR)
{	
	char str[] = "1234567890+-qwertyuiop[]';?><}{[]:lkjhgfdsazxcvbnm,./%@!$^&*()_=";
	int key = 3;
	
	char distance = crpt(str,key);

	char expected_d = "1234567890+-1234567890[]';?><}{[]:ntboqvrflmihgedc,./%@!$^&*()_=";

	ASSERT_STR(expected_d,distance);
}

CTEST(distance_suite, EMPTY_KEY)
{
	char str[] = "aaaaa";
	int key;
	
	int distance = crpt(str,key);

	double expected_d = 0;

	ASSERT_DBL_NEAR(expected_d,distance);
}

CTEST(distance_suite, EMPTY_STR)
{
	char str[] = "";
	int key = 3;
	int distance = crpt(str,key);

	double expected_d = 0;

	ASSERT_DBL_NEAR(expected_d,distance);
}
