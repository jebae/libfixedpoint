#ifndef FIXEDPOINT_TEST_H
# define FIXEDPOINT_TEST_H

# include "fixedpoint.h"
# include <stdio.h>

void		test(int res, const char *msg);

/*
** test memory management
*/
void		test_fxp_new_case1(void);
void		test_fxp_init_case1(void);

/*
** test fxp_mul_fxp
*/
void		test_fxp_mul_fxp_case1(void);
void		test_fxp_mul_fxp_case2(void);
void		test_fxp_mul_fxp_case3(void);
void		test_fxp_mul_fxp_case4(void);

#endif
