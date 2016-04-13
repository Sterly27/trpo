#include <ctest.h>
#include <crypt_func.h>

CTEST(distance_suite, NO_ERROR)
{
	const char *str = "aaaaa";
	const int key = 3;
	
	const int distance = crpt(str,key);

	const double expected_d = 0;

	ASSERT_DBL_NEAR(expected_d,distance);
}

CTEST(distance_suite, ERROR)
{
	const char *str;
	const int key;
	
	const int distance = crpt(str,key);

	const double expected_d = -1;

	ASSERT_DBL_NEAR(expected_d,distance);
}

CTEST(distance_suite, EMPTY)
{
	const char *str;
	const int key = 3;
	
	const int distance = crpt(str,key);

	const double expected_d = 1;

	ASSERT_DBL_NEAR(expected_d,distance);
}
