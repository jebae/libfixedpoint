/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxp_double_get_fraction_part.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:43:32 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:43:33 by jebae            ###   ########.fr       */
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

	num_bits = (num_bits > 53) ? 53 : num_bits;
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

int				fxp_get_reciprocal(t_fixedpoint *recip, size_t num_bits)
{
	size_t			i;
	t_bigint		temp;

	if (bi_push(&recip->num, 1) == BI_FAIL)
		return (FXP_FAIL);
	if (num_bits == 0)
		return (FXP_SUCCESS);
	bi_init(&temp);
	i = 0;
	while (i < num_bits)
	{
		if (bi_copy(&temp, &recip->num) == BI_FAIL ||
			bi_left_shift(&recip->num, 2, &recip->num) == BI_FAIL ||
			bi_add_bi(&recip->num, &temp, &recip->num) == BI_FAIL)
		{
			bi_del(&temp);
			return (FXP_FAIL);
		}
		i++;
	}
	recip->e -= (long long)num_bits;
	bi_del(&temp);
	return (FXP_SUCCESS);
}

int				fxp_double_get_fraction_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *fraction_part
)
{
	size_t			size;
	size_t			num_bits;
	t_fixedpoint	recip;

	fxp_init(&recip);
	num_bits = (exponent < 52) ? (52 - exponent) : 0;
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
