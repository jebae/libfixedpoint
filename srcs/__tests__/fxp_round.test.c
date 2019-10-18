#include "fixedpoint.test.h"

// case 3.14, round 1
void		test_fxp_round_case1(void)
{
	printf(KYEL "test_fxp_round_case1\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x3a);
	bi_push(&(fxp.num), 0x01);
	fxp.e = -2;

	res = fxp_round(&fxp, 1, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -1,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x1f,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.999, round 1
void		test_fxp_round_case2(void)
{
	printf(KYEL "test_fxp_round_case2\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0xe7);
	bi_push(&(fxp.num), 0x03);
	fxp.num.sign = BI_SIGN_NEGATIVE;
	fxp.e = -3;

	res = fxp_round(&fxp, 1, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.sign == fxp.num.sign,
		"fxp_round : rounded.num.sign"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x01,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.999, round 2
void		test_fxp_round_case3(void)
{
	printf(KYEL "test_fxp_round_case3\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0xe7);
	bi_push(&(fxp.num), 0x03);
	fxp.e = -3;

	res = fxp_round(&fxp, 2, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x01,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.999, round 3
void		test_fxp_round_case4(void)
{
	printf(KYEL "test_fxp_round_case4\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0xe7);
	bi_push(&(fxp.num), 0x03);
	fxp.e = -3;

	res = fxp_round(&fxp, 3, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -3,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 2,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0xe7,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0x03,
		"fxp_round : rounded.num.data[1]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.999, round 0
void		test_fxp_round_case5(void)
{
	printf(KYEL "test_fxp_round_case5\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0xe7);
	bi_push(&(fxp.num), 0x03);
	fxp.e = -3;

	res = fxp_round(&fxp, 0, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x01,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.0009999, round 7
void		test_fxp_round_case6(void)
{
	printf(KYEL "test_fxp_round_case6\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x0f);
	bi_push(&(fxp.num), 0x27);
	fxp.e = -7;

	res = fxp_round(&fxp, 7, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -7,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 2,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x0f,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0x27,
		"fxp_round : rounded.num.data[1]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.0009999, round 6
void		test_fxp_round_case7(void)
{
	printf(KYEL "test_fxp_round_case7\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x0f);
	bi_push(&(fxp.num), 0x27);
	fxp.e = -7;

	res = fxp_round(&fxp, 6, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -3,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x01,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.0009999, round 3
void		test_fxp_round_case8(void)
{
	printf(KYEL "test_fxp_round_case8\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x0f);
	bi_push(&(fxp.num), 0x27);
	fxp.e = -7;

	res = fxp_round(&fxp, 3, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -3,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x01,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.0009999, round 2
void		test_fxp_round_case9(void)
{
	printf(KYEL "test_fxp_round_case9\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x0f);
	bi_push(&(fxp.num), 0x27);
	fxp.e = -7;

	res = fxp_round(&fxp, 2, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 0,
		"fxp_round : rounded.num.occupied"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.0009999, round 0
void		test_fxp_round_case10(void)
{
	printf(KYEL "test_fxp_round_case10\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x0f);
	bi_push(&(fxp.num), 0x27);
	fxp.e = -7;

	res = fxp_round(&fxp, 0, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 0,
		"fxp_round : rounded.num.occupied"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.000898989, round 8
void		test_fxp_round_case11(void)
{
	printf(KYEL "test_fxp_round_case11\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0xad);
	bi_push(&(fxp.num), 0xb7);
	bi_push(&(fxp.num), 0x0d);
	fxp.e = -9;

	res = fxp_round(&fxp, 8, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -8,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 3,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x2b,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0x5f,
		"fxp_round : rounded.num.data[1]"
	);

	test(
		rounded.num.data[2] == 0x01,
		"fxp_round : rounded.num.data[2]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.000898989, round 7
void		test_fxp_round_case12(void)
{
	printf(KYEL "test_fxp_round_case12\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0xad);
	bi_push(&(fxp.num), 0xb7);
	bi_push(&(fxp.num), 0x0d);
	fxp.e = -9;

	res = fxp_round(&fxp, 7, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -6,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 2,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x83,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0x03,
		"fxp_round : rounded.num.data[1]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.0009999, round 8
void		test_fxp_round_case13(void)
{
	printf(KYEL "test_fxp_round_case13\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x0f);
	bi_push(&(fxp.num), 0x27);
	fxp.e = -7;

	res = fxp_round(&fxp, 8, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -7,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 2,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x0f,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0x27,
		"fxp_round : rounded.num.data[1]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.0009999, round 9
void		test_fxp_round_case14(void)
{
	printf(KYEL "test_fxp_round_case14\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x0f);
	bi_push(&(fxp.num), 0x27);
	fxp.e = -7;

	res = fxp_round(&fxp, 9, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -7,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 2,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x0f,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0x27,
		"fxp_round : rounded.num.data[1]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 123.0009999, round 5
void		test_fxp_round_case15(void)
{
	printf(KYEL "test_fxp_round_case15\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x8f);
	bi_push(&(fxp.num), 0x76);
	bi_push(&(fxp.num), 0x50);
	bi_push(&(fxp.num), 0x49);
	fxp.e = -7;

	res = fxp_round(&fxp, 5, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -3,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 3,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x79,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0xe0,
		"fxp_round : rounded.num.data[1]"
	);

	test(
		rounded.num.data[2] == 0x01,
		"fxp_round : rounded.num.data[2]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 123.0009999, round 3
void		test_fxp_round_case16(void)
{
	printf(KYEL "test_fxp_round_case16\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x8f);
	bi_push(&(fxp.num), 0x76);
	bi_push(&(fxp.num), 0x50);
	bi_push(&(fxp.num), 0x49);
	fxp.e = -7;

	res = fxp_round(&fxp, 3, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -3,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 3,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x79,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0xe0,
		"fxp_round : rounded.num.data[1]"
	);

	test(
		rounded.num.data[2] == 0x01,
		"fxp_round : rounded.num.data[2]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 123.0009999, round 2
void		test_fxp_round_case17(void)
{
	printf(KYEL "test_fxp_round_case17\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x8f);
	bi_push(&(fxp.num), 0x76);
	bi_push(&(fxp.num), 0x50);
	bi_push(&(fxp.num), 0x49);
	fxp.e = -7;

	res = fxp_round(&fxp, 2, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x7b,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 99.9999999, round 6
void		test_fxp_round_case18(void)
{
	printf(KYEL "test_fxp_round_case18\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0xff);
	bi_push(&(fxp.num), 0xc9);
	bi_push(&(fxp.num), 0x9a);
	bi_push(&(fxp.num), 0x3b);
	fxp.e = -7;

	res = fxp_round(&fxp, 6, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 2,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x01,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 99.9999999, round 7
void		test_fxp_round_case19(void)
{
	printf(KYEL "test_fxp_round_case19\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0xff);
	bi_push(&(fxp.num), 0xc9);
	bi_push(&(fxp.num), 0x9a);
	bi_push(&(fxp.num), 0x3b);
	fxp.e = -7;

	res = fxp_round(&fxp, 7, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == -7,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 4,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0xff,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0xc9,
		"fxp_round : rounded.num.data[1]"
	);

	test(
		rounded.num.data[2] == 0x9a,
		"fxp_round : rounded.num.data[2]"
	);

	test(
		rounded.num.data[3] == 0x3b,
		"fxp_round : rounded.num.data[3]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 12345.0, round 3
void		test_fxp_round_case20(void)
{
	printf(KYEL "test_fxp_round_case20\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x39);
	bi_push(&(fxp.num), 0x30);
	fxp.e = 0;

	res = fxp_round(&fxp, 3, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 2,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x39,
		"fxp_round : rounded.num.data[0]"
	);

	test(
		rounded.num.data[1] == 0x30,
		"fxp_round : rounded.num.data[1]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0
void		test_fxp_round_case21(void)
{
	printf(KYEL "test_fxp_round_case21\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	rounded.num.sign = BI_SIGN_NEGATIVE;

	res = fxp_round(&fxp, 3, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.sign == BI_SIGN_POSITIVE,
		"fxp_round : rounded.num.sign"
	);

	test(
		rounded.num.occupied == 0,
		"fxp_round : rounded.num.occupied"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 123.0009999, round -1
void		test_fxp_round_case22(void)
{
	printf(KYEL "test_fxp_round_case22\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x8f);
	bi_push(&(fxp.num), 0x76);
	bi_push(&(fxp.num), 0x50);
	bi_push(&(fxp.num), 0x49);
	fxp.e = -7;

	res = fxp_round(&fxp, -1, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 1,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x0c,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 123.0009999, round -2
void		test_fxp_round_case23(void)
{
	printf(KYEL "test_fxp_round_case23\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x8f);
	bi_push(&(fxp.num), 0x76);
	bi_push(&(fxp.num), 0x50);
	bi_push(&(fxp.num), 0x49);
	fxp.e = -7;

	res = fxp_round(&fxp, -2, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 2,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x01,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 123.0009999, round -3
void		test_fxp_round_case24(void)
{
	printf(KYEL "test_fxp_round_case24\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x8f);
	bi_push(&(fxp.num), 0x76);
	bi_push(&(fxp.num), 0x50);
	bi_push(&(fxp.num), 0x49);
	fxp.e = -7;

	res = fxp_round(&fxp, -3, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 0,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 0,
		"fxp_round : rounded.num.occupied"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 789770.0, round -3
void		test_fxp_round_case25(void)
{
	printf(KYEL "test_fxp_round_case25\n" KNRM);
	t_fixedpoint	fxp;
	t_fixedpoint	rounded;
	int				res;

	fxp_init(&fxp);
	fxp_init(&rounded);
	bi_push(&(fxp.num), 0x81);
	bi_push(&(fxp.num), 0x34);
	bi_push(&(fxp.num), 0x01);
	fxp.e = 1;

	res = fxp_round(&fxp, -3, &rounded);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		rounded.e == 4,
		"fxp_round : rounded.e"
	);

	test(
		rounded.num.occupied == 1,
		"fxp_round : rounded.num.occupied"
	);

	test(
		rounded.num.data[0] == 0x4f,
		"fxp_round : rounded.num.data[0]"
	);

	fxp_del(&fxp);
	fxp_del(&rounded);
}

// case 0.000898989, round 7 (mutable)
void		test_fxp_round_case26(void)
{
	printf(KYEL "test_fxp_round_case26\n" KNRM);
	t_fixedpoint	fxp;
	int				res;

	fxp_init(&fxp);
	bi_push(&(fxp.num), 0xad);
	bi_push(&(fxp.num), 0xb7);
	bi_push(&(fxp.num), 0x0d);
	fxp.e = -9;

	res = fxp_round(&fxp, 7, &fxp);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		fxp.e == -6,
		"fxp_round : fxp.e"
	);

	test(
		fxp.num.occupied == 2,
		"fxp_round : fxp.num.occupied"
	);

	test(
		fxp.num.data[0] == 0x83,
		"fxp_round : fxp.num.data[0]"
	);

	test(
		fxp.num.data[1] == 0x03,
		"fxp_round : fxp.num.data[1]"
	);

	fxp_del(&fxp);
}

// case 123.0009999, round 5 (mutable)
void		test_fxp_round_case27(void)
{
	printf(KYEL "test_fxp_round_case27\n" KNRM);
	t_fixedpoint	fxp;
	int				res;

	fxp_init(&fxp);
	bi_push(&(fxp.num), 0x8f);
	bi_push(&(fxp.num), 0x76);
	bi_push(&(fxp.num), 0x50);
	bi_push(&(fxp.num), 0x49);
	fxp.e = -7;

	res = fxp_round(&fxp, 5, &fxp);

	test(
		res == FXP_SUCCESS,
		"fxp_round : return value"
	);

	test(
		fxp.e == -3,
		"fxp_round : fxp.e"
	);

	test(
		fxp.num.occupied == 3,
		"fxp_round : fxp.num.occupied"
	);

	test(
		fxp.num.data[0] == 0x79,
		"fxp_round : fxp.num.data[0]"
	);

	test(
		fxp.num.data[1] == 0xe0,
		"fxp_round : fxp.num.data[1]"
	);

	test(
		fxp.num.data[2] == 0x01,
		"fxp_round : fxp.num.data[2]"
	);

	fxp_del(&fxp);
}
