#include "fixedpoint.h"

int		fxp_init(t_fixedpoint *fxp, size_t size)
{
	if (bi_init(&(fxp->num), size) == BI_FAIL)
		return (FXP_FAIL);
	fxp->e = 0;
	return (FXP_SUCCESS);
}
