#include "fixedpoint.h"

int		fxp_new(t_fixedpoint *fxp, size_t size, char sign)
{
	if (bi_new(&(fxp->num), size, sign) == BI_FAIL)
		return (FXP_FAIL);
	fxp->e = 0;
	return (FXP_SUCCESS);
}
