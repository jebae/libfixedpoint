/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedpoint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:07:58 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:08:48 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDPOINT_H
# define FIXEDPOINT_H

# include "bigint.h"
# include "libft.h"
# include <stdio.h>

# define FXP_SUCCESS		0
# define FXP_FAIL			1

typedef struct	s_fixedpoint
{
	t_bigint	num;
	long long	e;
}				t_fixedpoint;

void			fxp_init(t_fixedpoint *fxp);
void			fxp_del(t_fixedpoint *fxp);
int				fxp_compact(t_fixedpoint *fxp);
int				fxp_mul_fxp(
	t_fixedpoint *a,
	t_fixedpoint *b,
	t_fixedpoint *c,
	int compact
);
int				fxp_strassen_mul_fxp(
	t_fixedpoint *a,
	t_fixedpoint *b,
	t_fixedpoint *c,
	int compact
);
int				fxp_round(t_fixedpoint *fxp, long long r, t_fixedpoint *res);
int				fxp_double_get_int_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
);
int				fxp_get_reciprocal(t_fixedpoint *recip, size_t num_bits);
int				fxp_double_get_fraction_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *fraction_part
);
int				fxp_ldouble_get_int_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
);
int				fxp_ldouble_get_fraction_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *fraction_part
);

#endif
