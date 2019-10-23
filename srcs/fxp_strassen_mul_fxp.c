#include "fixedpoint.h"

int		fxp_strassen_mul_fxp(
	t_fixedpoint *a,
	t_fixedpoint *b,
	t_fixedpoint *c,
	int compact
)
{
	if (bi_strassen_mul_bi(&a->num, &b->num, &c->num) == BI_FAIL)
		return (FXP_FAIL);
	c->e = a->e + b->e;
	if (compact && fxp_compact(c) == FXP_FAIL)
		return (FXP_FAIL);
	return (FXP_SUCCESS);
}
