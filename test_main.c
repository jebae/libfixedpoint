#include "fixedpoint.test.h"

int		main(void)
{
	// memory management
	test_fxp_new_case1();
	test_fxp_init_case1();

	// fxp_compact
	test_fxp_compact_case1();
	test_fxp_compact_case2();
	test_fxp_compact_case3();
	test_fxp_compact_case4();
	test_fxp_compact_case5();
	test_fxp_compact_case6();
	test_fxp_compact_case7();

	// fxp_mul_fxp
	test_fxp_mul_fxp_case1();
	test_fxp_mul_fxp_case2();
	test_fxp_mul_fxp_case3();
	test_fxp_mul_fxp_case4();
	test_fxp_mul_fxp_case5();
	test_fxp_mul_fxp_case6();
	test_fxp_mul_fxp_case7();
	test_fxp_mul_fxp_case8();
	// while (1);
}
