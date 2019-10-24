/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxp_mul_fxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:09:39 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:09:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixedpoint.h"

int		fxp_mul_fxp(
	t_fixedpoint *a,
	t_fixedpoint *b,
	t_fixedpoint *c,
	int compact
)
{
	if (bi_mul_bi(&a->num, &b->num, &c->num) == BI_FAIL)
		return (FXP_FAIL);
	c->e = a->e + b->e;
	if (compact && fxp_compact(c) == FXP_FAIL)
		return (FXP_FAIL);
	return (FXP_SUCCESS);
}
