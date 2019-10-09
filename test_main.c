#include "fixedpoint.test.h"

int		main(void)
{
	// memory management
	test_fxp_new_case1();
	test_fxp_init_case1();

	// fxp_mul_fxp
	test_fxp_mul_fxp_case1();
	test_fxp_mul_fxp_case2();
	test_fxp_mul_fxp_case3();
	test_fxp_mul_fxp_case4();
}
