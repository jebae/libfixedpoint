#include "fixedpoint.test.h"

// 3.14 * 0.029
void		test_fxp_mul_fxp_case1(void)
{
	printf(KYEL "test_fxp_mul_fxp_case1\n" KNRM);
	t_fixedpoint	a;
	t_fixedpoint	b;
	t_fixedpoint	c;
	int				res;

	fxp_new(&a, 1, BI_SIGN_POSITIVE);
	fxp_new(&b, 1, BI_SIGN_POSITIVE);
	fxp_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&(a.num), 0x3a);
	bi_push(&(a.num), 0x01);
	bi_push(&(b.num), 0x1d);
	a.e = -2;
	b.e = -3;

	res = fxp_mul_fxp(&a, &b, &c);

	test(
		res == FXP_SUCCESS,
		"fxp_mul_fxp : return value"
	);

	test(
		c.num.sign == BI_SIGN_POSITIVE,
		"fxp_mul_fxp : c.num.sign"
	);

	test(
		c.num.occupied == 2,
		"fxp_mul_fxp : c.num.occupied"
	);

	test(
		c.num.data[0] == 0x92,
		"fxp_mul_fxp : c.num.occupied"
	);

	test(
		c.num.data[1] == 0x23,
		"fxp_mul_fxp : c.num.occupied"
	);

	test(
		c.e == -5,
		"fxp_mul_fxp : c.e"
	);

	free(a.num.data);
	free(b.num.data);
	free(c.num.data);
}

// 0.031415929821 * 0.00000000112345
void		test_fxp_mul_fxp_case2(void)
{
	printf(KYEL "test_fxp_mul_fxp_case2\n" KNRM);
	t_fixedpoint	a;
	t_fixedpoint	b;
	t_fixedpoint	c;
	int				res;
	unsigned char	expected[7] = { 0x55, 0x2c, 0x77, 0xbe, 0xfd, 0x89, 0x0c };

	fxp_new(&a, 1, BI_SIGN_POSITIVE);
	fxp_new(&b, 1, BI_SIGN_POSITIVE);
	fxp_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&(a.num), 0xdd);
	bi_push(&(a.num), 0x0b);
	bi_push(&(a.num), 0x89);
	bi_push(&(a.num), 0x50);
	bi_push(&(a.num), 0x07);
	bi_push(&(b.num), 0xd9);
	bi_push(&(b.num), 0xb6);
	bi_push(&(b.num), 0x01);
	a.e = -12;
	b.e = -14;

	res = fxp_mul_fxp(&a, &b, &c);

	test(
		res == FXP_SUCCESS,
		"fxp_mul_fxp : return value"
	);

	test(
		c.num.sign == BI_SIGN_POSITIVE,
		"fxp_mul_fxp : c.num.sign"
	);

	test(
		c.num.occupied == 7,
		"fxp_mul_fxp : c.num.occupied"
	);

	for (size_t i=0; i < c.num.occupied; i++)
		test(
			c.num.data[i] == expected[i],
			"fxp_mul_fxp : c.num.data[i]"
		);

	test(
		c.e == -26,
		"fxp_mul_fxp : c.e"
	);

	free(a.num.data);
	free(b.num.data);
	free(c.num.data);
}

// -0.031415929821 * 0.00000000112345
void		test_fxp_mul_fxp_case3(void)
{
	printf(KYEL "test_fxp_mul_fxp_case3\n" KNRM);
	t_fixedpoint	a;
	t_fixedpoint	b;
	t_fixedpoint	c;
	int				res;
	unsigned char	expected[7] = { 0x55, 0x2c, 0x77, 0xbe, 0xfd, 0x89, 0x0c };

	fxp_new(&a, 1, BI_SIGN_NEGATIVE);
	fxp_new(&b, 1, BI_SIGN_POSITIVE);
	fxp_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&(a.num), 0xdd);
	bi_push(&(a.num), 0x0b);
	bi_push(&(a.num), 0x89);
	bi_push(&(a.num), 0x50);
	bi_push(&(a.num), 0x07);
	bi_push(&(b.num), 0xd9);
	bi_push(&(b.num), 0xb6);
	bi_push(&(b.num), 0x01);
	a.e = -12;
	b.e = -14;

	res = fxp_mul_fxp(&a, &b, &c);

	test(
		res == FXP_SUCCESS,
		"fxp_mul_fxp : return value"
	);

	test(
		c.num.sign == BI_SIGN_NEGATIVE,
		"fxp_mul_fxp : c.num.sign"
	);

	test(
		c.num.occupied == 7,
		"fxp_mul_fxp : c.num.occupied"
	);

	for (size_t i=0; i < c.num.occupied; i++)
		test(
			c.num.data[i] == expected[i],
			"fxp_mul_fxp : c.num.data[i]"
		);

	test(
		c.e == -26,
		"fxp_mul_fxp : c.e"
	);

	free(a.num.data);
	free(b.num.data);
	free(c.num.data);
}

// 12345678.0 * 98765.0 (compact needed)
void		test_fxp_mul_fxp_case4(void)
{
	printf(KYEL "test_fxp_mul_fxp_case4\n" KNRM);
	t_fixedpoint	a;
	t_fixedpoint	b;
	t_fixedpoint	c;
	int				res;
	unsigned char	expected[5] = { 0xbf, 0x05, 0xb8, 0x63, 0x1c };

	fxp_new(&a, 1, BI_SIGN_NEGATIVE);
	fxp_new(&b, 1, BI_SIGN_POSITIVE);
	fxp_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&(a.num), 0x4e);
	bi_push(&(a.num), 0x61);
	bi_push(&(a.num), 0xbc);
	bi_push(&(b.num), 0xcd);
	bi_push(&(b.num), 0x81);
	bi_push(&(b.num), 0x01);
	a.e = 0;
	b.e = 0;

	res = fxp_mul_fxp(&a, &b, &c);

	test(
		res == FXP_SUCCESS,
		"fxp_mul_fxp : return value"
	);

	test(
		c.num.sign == BI_SIGN_NEGATIVE,
		"fxp_mul_fxp : c.num.sign"
	);

	test(
		c.num.occupied == 5,
		"fxp_mul_fxp : c.num.occupied"
	);

	for (size_t i=0; i < c.num.occupied; i++)
		test(
			c.num.data[i] == expected[i],
			"fxp_mul_fxp : c.num.data[i]"
		);

	test(
		c.e == 1,
		"fxp_mul_fxp : c.e"
	);

	free(a.num.data);
	free(b.num.data);
	free(c.num.data);
}

// case compact (10000000 * 0.6780000)
void		test_fxp_mul_fxp_case5(void)
{
	printf(KYEL "test_fxp_mul_fxp_case5\n" KNRM);
	t_fixedpoint	a;
	t_fixedpoint	b;
	t_fixedpoint	c;
	int				res;

	fxp_new(&a, 1, BI_SIGN_POSITIVE);
	fxp_new(&b, 1, BI_SIGN_POSITIVE);
	fxp_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&(a.num), 0x80);
	bi_push(&(a.num), 0x96);
	bi_push(&(a.num), 0x98);
	bi_push(&(b.num), 0x60);
	bi_push(&(b.num), 0x74);
	bi_push(&(b.num), 0x67);
	a.e = 0;
	b.e = -7;

	res = fxp_mul_fxp(&a, &b, &c);

	test(
		res == FXP_SUCCESS,
		"fxp_mul_fxp : return value"
	);

	test(
		c.num.sign == BI_SIGN_POSITIVE,
		"fxp_mul_fxp : c.num.sign"
	);

	test(
		c.num.occupied == 2,
		"fxp_mul_fxp : c.num.occupied"
	);

	test(
		c.num.data[0] == 0xa6,
		"fxp_mul_fxp : c.num.data[0]"
	);

	test(
		c.num.data[1] == 0x02,
		"fxp_mul_fxp : c.num.data[1]"
	);

	test(
		c.e == 4,
		"fxp_mul_fxp : c.e"
	);

	free(a.num.data);
	free(b.num.data);
	free(c.num.data);
}
