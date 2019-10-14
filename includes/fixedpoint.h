#ifndef FIXEDPOINT_H
# define FIXEDPOINT_H

# include "bigint.h"
# include "libft.h"

# define FXP_SUCCESS		0
# define FXP_FAIL			1

typedef struct			s_fixedpoint
{
	t_bigint	num;
	long long	e;
}						t_fixedpoint;

int			fxp_new(t_fixedpoint *fxp, size_t size, char sign);
int			fxp_init(t_fixedpoint *fxp, size_t size);
int     	fxp_compact(t_fixedpoint *fxp);
int			fxp_mul_fxp(t_fixedpoint *a, t_fixedpoint *b, t_fixedpoint *c);

#endif
