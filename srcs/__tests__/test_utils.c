#include "fixedpoint.test.h"

void		test(int res, const char *msg)
{
	if (!res)
	{
		printf(KRED "[FAILED] " KNRM);
		printf("%s\n", msg);
	}
}
