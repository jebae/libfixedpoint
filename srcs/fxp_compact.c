/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxp_compact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:09:32 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:09:59 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixedpoint.h"

static int		handle_fail(t_bigint *bcd)
{
	bi_del(bcd);
	return (FXP_FAIL);
}

int				fxp_compact(t_fixedpoint *fxp)
{
	size_t		shift;
	t_bigint	bcd;

	bi_init(&bcd);
	if (bi_double_dabble(&fxp->num, &bcd) == BI_FAIL)
		return (handle_fail(&bcd));
	shift = bcd_rm_trailing_zero(&bcd);
	if (bi_rev_double_dabble(&bcd, &(fxp->num)) == BI_FAIL)
		return (handle_fail(&bcd));
	if (fxp->num.occupied == 0)
		fxp->e = 0;
	else
		fxp->e += shift;
	bi_del(&bcd);
	return (FXP_SUCCESS);
}
