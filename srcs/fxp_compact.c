#include "fixedpoint.h"

static int		handle_fail(t_bigint *bcd)
{
	ft_memdel((void **)&(bcd->data));
	return (FXP_FAIL);
}

int     		fxp_compact(t_fixedpoint *fxp)
{
	size_t		i;
	size_t		shift;
	t_bigint	bcd;
	
	if (bi_new(&bcd, 1, BI_SIGN_POSITIVE) == BI_FAIL)
		return (FXP_FAIL);
	if (bi_double_dabble(&(fxp->num), &bcd) == BI_FAIL)
		return (handle_fail(&bcd));
	shift = 0;
	i = 0;
	while (i < bcd.occupied && (bcd.data[i] & 0x0f) == 0)
	{
		shift += 1;
		if (bcd.data[i] != 0)
			break ;
		shift += 1;
		i++;
	}
	bi_right_shift(&bcd, shift * 4, &bcd);
	if (bi_rev_double_dabble(&bcd, &(fxp->num)) == BI_FAIL)
		return (handle_fail(&bcd));
	if (fxp->num.occupied == 0)
		fxp->e = 0;
	else
		fxp->e += shift;
	ft_memdel((void **)&bcd.data);	
	return (FXP_SUCCESS);
}
