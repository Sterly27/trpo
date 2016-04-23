#include "../thirdparty/ctest.h"
#include "../src/crypt_func.h"

CTEST_SKIP(distance_suite, NO_ERROR)
{	
	char *str = "aaaaa";
	int key = 3;
	
	int distance = crpt(str,key);

	double expected_d = 0;

	ASSERT_DBL_NEAR(expected_d,distance);
}

CTEST(distance_suite, ERROR)
{
	char *str;
	int key;
	
	int distance = crpt(str,key);

	double expected_d = -1;

	ASSERT_DBL_NEAR(expected_d,distance);
}

CTEST(distance_suite, EMPTY)
{
	char *str;
	int key = 3;
	int distance = crpt((char*)str,key);

	double expected_d = 1;

	ASSERT_DBL_NEAR(expected_d,distance);
}
