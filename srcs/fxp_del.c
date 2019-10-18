#include "fixedpoint.h"

void		fxp_del(t_fixedpoint *fxp)
{
	bi_del(&fxp->num);
}