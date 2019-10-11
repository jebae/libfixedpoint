#include "fixedpoint.h"

int		fxp_mul_fxp(t_fixpedpoint *a, t_fixpedpoint *b, t_fixpedpoint *c)
{
	if (bi_mul_bi(&(a->num), &(b->num)) == BI_FAIL)
		return (FXP_FAIL);
	// 
}
