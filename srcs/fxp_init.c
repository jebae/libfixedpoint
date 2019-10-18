#include "fixedpoint.h"

void		fxp_init(t_fixedpoint *fxp)
{
	bi_init(&fxp->num);
	fxp->e = 0;
}
