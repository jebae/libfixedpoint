#ifndef FIXEDPOINT_H
# define FIXEDPOINT_H

# include "bigint.h"

# define FXP_SUCCESS		0
# define FXP_FAIL			1

typedef struct			s_fixedpoint
{
	t_bigint	num;
	long long	e;
}						t_fixedpoint;

int			fxp_new(t_fixedpoint *fxp, size_t size, char sign);
int			fxp_init(t_fixedpoint *fxp, size_t size);

#endif
