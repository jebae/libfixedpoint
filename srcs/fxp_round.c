/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxp_round.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:09:41 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:09:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixedpoint.h"

static int		handle_fail(t_bigint *bcd)
{
	ft_memdel((void **)&bcd->data);
	return (FXP_FAIL);
}

int				fxp_round(t_fixedpoint *fxp, long long r, t_fixedpoint *res)
{
	long long		len;
	long long		pos;
	t_bigint		bcd;

	bi_init(&bcd);
	if (bi_double_dabble(&fxp->num, &bcd) == BI_FAIL)
		return (handle_fail(&bcd));
	len = bcd_len(&bcd);
	pos = -(r + fxp->e);
	if (pos > len)
		bi_erase(&bcd);
	else if (pos > 0)
	{
		if (bcd_round(&bcd, pos, &bcd) == BI_FAIL)
			return (handle_fail(&bcd));
	}
	if (bcd.occupied == 0)
		res->e = 0;
	else
		res->e = fxp->e + bcd_rm_trailing_zero(&bcd);
	if (bi_rev_double_dabble(&bcd, &res->num) == BI_FAIL)
		return (handle_fail(&bcd));
	bi_del(&bcd);
	return (FXP_SUCCESS);
}
