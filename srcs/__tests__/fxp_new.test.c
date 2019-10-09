#include "fixedpoint.test.h"

void		test_fxp_new_case1(void)
{
	printf(KYEL "test_fxp_new_case1\n" KNRM);
	t_fixedpoint	fxp;
	size_t			size;
	char			sign;
	int				res;

	sign = BI_SIGN_POSITIVE;
	size = 3;
	res = fxp_new(&fxp, size, sign);

	test(
		res == FXP_SUCCESS,
		"fxp_new : return value"
	);

	test(
		fxp.num.size == size,
		"fxp_new : fxp.num.size"
	);

	test(
		fxp.num.sign == sign,
		"fxp_new : fxp.num.sign"
	);

	test(
		fxp.e == 0,
		"fxp_new : fxp.e"
	);

	free(fxp.num.data);
}
