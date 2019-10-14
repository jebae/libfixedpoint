#include "fixedpoint.h"

int		fxp_mul_fxp(t_fixedpoint *a, t_fixedpoint *b, t_fixedpoint *c)
{
	if (bi_mul_bi(&(a->num), &(b->num), &(c->num)) == BI_FAIL)
		return (FXP_FAIL);
	c->e = a->e + b->e;
	if (fxp_compact(c) == FXP_FAIL)
		return (FXP_FAIL);
	return (FXP_SUCCESS);
}
