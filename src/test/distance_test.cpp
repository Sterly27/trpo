#include "../../thirdparty/ctest.h"
#include "../crypt.h"
//crypt
CTEST ( distance_suite, NO_ERROR_CRYPT )
{	
	char str[] = "qwertyuiopasdfghjklzxcvbnm1234567890";
	int key = 3;
	
	crpt(str, key);

	char expected_d[] = "tzhuw|xlrsdvgijkmno}{fyeqp456789:;<3";

	assert_str(expected_d, str, "a", 1);
}

CTEST ( distance_suite, EMPTY_KEY )
{
	char str[] = "aaaaa";
    int key = 0;
	
	int distance = crpt(str,key);

	double expected_d = 1;

	ASSERT_DBL_NEAR(expected_d, distance);
}

CTEST ( distance_suite, EMPTY_STR )
{
	char str[] = "";
	int key = 3;
	int distance = crpt(str, key);

	double expected_d = 1;

	ASSERT_DBL_NEAR(expected_d, distance);
}
//decrypt
CTEST ( distance_suite, NO_ERROR_DECRYPT )
{	
	char str[] = "tzhuw|xlrsdvgijkmno}{fyeqp456789:;<3";
	int key = 3;
	
	decrpt(str, key);

	char expected_d[] = "qwertyuiopasdfghjklzxcvbnm1234567890";

	assert_str(expected_d, str, "a", 1);
}
