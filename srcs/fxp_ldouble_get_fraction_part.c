/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxp_ldouble_get_fraction_part.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:43:43 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:43:44 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixedpoint.h"

static int		handle_fail(t_fixedpoint *fxp)
{
	fxp_del(fxp);
	return (FXP_FAIL);
}

static void		get_sum(
	t_fixedpoint *sum,
	unsigned long long mantissa,
	size_t num_bits
)
{
	size_t		i;
	size_t		j;

	num_bits = (num_bits > 64) ? 64 : num_bits;
	j = num_bits / 8;
	i = 0;
	while (i < j)
	{
		bi_push(&sum->num, mantissa & 0xff);
		mantissa >>= 8;
		i++;
	}
	j = num_bits % 8;
	while (j > 0)
	{
		bi_set_bit(&sum->num, i * 8 + j - 1, (mantissa >> (j - 1)) & 1);
		j--;
	}
}

int				fxp_ldouble_get_fraction_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *fraction_part
)
{
	size_t			size;
	size_t			num_bits;
	t_fixedpoint	recip;

	fxp_init(&recip);
	num_bits = (exponent < 63) ? (63 - exponent) : 0;
	size = (num_bits % BI_UNIT_BITS)
		? num_bits / BI_UNIT_BITS + 1
		: num_bits / BI_UNIT_BITS;
	size = (size > 1) ? size : 1;
	if (bi_memalloc(&fraction_part->num, size) == BI_FAIL)
		return (handle_fail(&recip));
	if (fxp_get_reciprocal(&recip, num_bits) == FXP_FAIL)
		return (handle_fail(&recip));
	get_sum(fraction_part, mantissa, num_bits);
	if (fxp_mul_fxp(fraction_part, &recip, fraction_part, 0) == FXP_FAIL)
		return (handle_fail(&recip));
	fxp_del(&recip);
	return (FXP_SUCCESS);
}
