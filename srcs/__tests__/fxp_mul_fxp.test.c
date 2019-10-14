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

// case mutable (a = c) 0.031415929821 * 0.00000000112345
void		test_fxp_mul_fxp_case6(void)
{
	printf(KYEL "test_fxp_mul_fxp_case6\n" KNRM);
	t_fixedpoint	a;
	t_fixedpoint	b;
	int				res;
	unsigned char	expected[7] = { 0x55, 0x2c, 0x77, 0xbe, 0xfd, 0x89, 0x0c };

	fxp_new(&a, 1, BI_SIGN_POSITIVE);
	fxp_new(&b, 1, BI_SIGN_POSITIVE);
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

	res = fxp_mul_fxp(&a, &b, &a);

	test(
		res == FXP_SUCCESS,
		"fxp_mul_fxp : return value"
	);

	test(
		a.num.sign == BI_SIGN_POSITIVE,
		"fxp_mul_fxp : a.num.sign"
	);

	test(
		a.num.occupied == 7,
		"fxp_mul_fxp : a.num.occupied"
	);

	for (size_t i=0; i < a.num.occupied; i++)
		test(
			a.num.data[i] == expected[i],
			"fxp_mul_fxp : a.num.data[i]"
		);

	test(
		a.e == -26,
		"fxp_mul_fxp : a.e"
	);

	free(a.num.data);
	free(b.num.data);
}

// case mutable (b = c) 0.031415929821 * 0.00000000112345
void		test_fxp_mul_fxp_case7(void)
{
	printf(KYEL "test_fxp_mul_fxp_case7\n" KNRM);
	t_fixedpoint	a;
	t_fixedpoint	b;
	int				res;
	unsigned char	expected[7] = { 0x55, 0x2c, 0x77, 0xbe, 0xfd, 0x89, 0x0c };

	fxp_new(&a, 1, BI_SIGN_POSITIVE);
	fxp_new(&b, 1, BI_SIGN_POSITIVE);
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

	res = fxp_mul_fxp(&a, &b, &b);

	test(
		res == FXP_SUCCESS,
		"fxp_mul_fxp : return value"
	);

	test(
		b.num.sign == BI_SIGN_POSITIVE,
		"fxp_mul_fxp : b.num.sign"
	);

	test(
		b.num.occupied == 7,
		"fxp_mul_fxp : b.num.occupied"
	);

	for (size_t i=0; i < b.num.occupied; i++)
		test(
			b.num.data[i] == expected[i],
			"fxp_mul_fxp : b.num.data[i]"
		);

	test(
		b.e == -26,
		"fxp_mul_fxp : b.e"
	);

	free(a.num.data);
	free(b.num.data);
}

// case 2^-56 * mantissa 1111100110101000000000000110111000011010000000010011
void		test_fxp_mul_fxp_case8(void)
{
	printf(KYEL "test_fxp_mul_fxp_case8\n" KNRM);
	t_fixedpoint	recip;
	t_fixedpoint	one_half;
	t_fixedpoint	sum;
	t_bigint		bcd;
	unsigned char	mantissa[7] = {
		0x13, 0xa0, 0xe1, 0x06,
		0x80, 0x9a, 0x1f
	};

	fxp_new(&recip, 1, BI_SIGN_POSITIVE);
	fxp_new(&sum, 1, BI_SIGN_POSITIVE);
	fxp_new(&one_half, 1, BI_SIGN_POSITIVE);

	bi_push(&recip.num, 1);
	bi_push(&one_half.num, 5);
	one_half.e = -1;

	for (size_t i=0; i < 56; i++)
		fxp_mul_fxp(&recip, &one_half, &recip);

	bi_double_dabble(&recip.num, &bcd);
	printf("recip : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0xf) + '0');
	}
	printf("\n");

	for (size_t i=0; i < 7; i++)
		bi_push(&sum.num, mantissa[i]);

	bi_double_dabble(&sum.num, &bcd);
	printf("sum : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0xf) + '0');
	}
	printf("\n");

	fxp_mul_fxp(&sum, &recip, &sum);

	bi_double_dabble(&sum.num, &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0xf) + '0');
	}
	printf("\n");


	free(recip.num.data);
	free(one_half.num.data);
	free(sum.num.data);
	free(bcd.data);
}
