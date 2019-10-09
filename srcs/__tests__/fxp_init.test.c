#include "fixedpoint.test.h"

void		test_fxp_init_case1(void)
{
	printf(KYEL "test_fxp_init_case1\n" KNRM);
	t_fixedpoint	fxp;
	size_t			size;
	char			sign;
	int				res;

	sign = BI_SIGN_POSITIVE;
	size = 16;
	fxp_new(&fxp, 2, sign);
	fxp.e = 1;
	res = fxp_init(&fxp, size);

	test(
		res == FXP_SUCCESS,
		"fxp_init : return value"
	);

	test(
		fxp.num.size == size,
		"fxp_init : fxp.num.size"
	);

	test(
		fxp.e == 0,
		"fxp_init : fxp.e"
	);

	free(fxp.num.data);
}
