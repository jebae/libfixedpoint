/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxp_double_get_int_part.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:43:35 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:43:36 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixedpoint.h"

int			fxp_double_get_int_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
)
{
	size_t		size;

	size = (exponent > 0) ? (1 + exponent) : 1;
	size = (size % BI_UNIT_BITS)
		? size / BI_UNIT_BITS + 1
		: size / BI_UNIT_BITS;
	if (bi_memalloc(&int_part->num, size) == BI_FAIL)
		return (FXP_FAIL);
	mantissa >>= 52 - ft_max_int(ft_min_int(exponent, 52), -1);
	while (mantissa)
	{
		bi_push(&int_part->num, mantissa & 0xff);
		mantissa >>= 8;
	}
	if (exponent > 52)
		bi_left_shift(&int_part->num, exponent - 52, &int_part->num);
	return (FXP_SUCCESS);
}
