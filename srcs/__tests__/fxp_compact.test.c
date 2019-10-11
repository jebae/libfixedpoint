#include "fixedpoint.test.h"

void		test_fxp_compact_case1(void)
{
	printf(KYEL "test_fxp_compact_case1\n" KNRM);
	t_fixedpoint	fxp;
	int				res;

	fxp_new(&fxp, 1, BI_SIGN_NEGATIVE);

    bi_push(&(fxp.num), 0x1c);
    bi_push(&(fxp.num), 0x6a);
    bi_push(&(fxp.num), 0x01);

    res = fxp_compact(&fxp);

    test(
        res == FXP_SUCCESS,
        "fxp_compact : return value"
    );

    test(
        fxp.e == 2,
        "fxp_compact : fxp.e"
    );

    test(
        fxp.num.sign == BI_SIGN_NEGATIVE,
        "fxp_compact : num.sign"
    );

    test(
        fxp.num.occupied == 2,
        "fxp_compact : num.occupied"
    );

    test(
        fxp.num.data[0] == 0x9f,
        "fxp_compact : num.data[0]"
    );

    test(
        fxp.num.data[1] == 0x03,
        "fxp_compact : num.data[1]"
    );

	free(fxp.num.data);
}

// case 0 in middle (e.g. 80060)
void		test_fxp_compact_case2(void)
{
	printf(KYEL "test_fxp_compact_case2\n" KNRM);
	t_fixedpoint	fxp;
	int				res;

	fxp_new(&fxp, 1, BI_SIGN_POSITIVE);

    bi_push(&(fxp.num), 0xbc);
    bi_push(&(fxp.num), 0x38);
    bi_push(&(fxp.num), 0x01);

    res = fxp_compact(&fxp);

    test(
        res == FXP_SUCCESS,
        "fxp_compact : return value"
    );

    test(
        fxp.e == 1,
        "fxp_compact : fxp.e"
    );

    test(
        fxp.num.sign == BI_SIGN_POSITIVE,
        "fxp_compact : num.sign"
    );

    test(
        fxp.num.occupied == 2,
        "fxp_compact : num.occupied"
    );

    test(
        fxp.num.data[0] == 0x46,
        "fxp_compact : num.data[0]"
    );

    test(
        fxp.num.data[1] == 0x1f,
        "fxp_compact : num.data[1]"
    );

	free(fxp.num.data);
}

// case no compact
void		test_fxp_compact_case3(void)
{
	printf(KYEL "test_fxp_compact_case3\n" KNRM);
	t_fixedpoint	fxp;
	int				res;
    unsigned char   data[4] = { 0x2f, 0xa3, 0xc5, 0x04 };

	fxp_new(&fxp, 1, BI_SIGN_POSITIVE);

    for (int i=0; i < 4; i++)
        bi_push(&(fxp.num), data[i]);

    res = fxp_compact(&fxp);

    test(
        fxp.e == 0,
        "fxp_compact : fxp.e"
    );

    test(
        res == FXP_SUCCESS,
        "fxp_compact : return value"
    );

    test(
        fxp.num.sign == BI_SIGN_POSITIVE,
        "fxp_compact : num.sign"
    );

    test(
        fxp.num.occupied == 4,
        "fxp_compact : num.occupied"
    );

    for (int i=0; i < 4; i++)
        test(
            fxp.num.data[i] == data[i],
            "fxp_compact : num.data[i]"
        );

	free(fxp.num.data);
}

// case 0
void		test_fxp_compact_case4(void)
{
	printf(KYEL "test_fxp_compact_case4\n" KNRM);
	t_fixedpoint	fxp;
	int				res;

	fxp_new(&fxp, 1, BI_SIGN_NEGATIVE);

    res = fxp_compact(&fxp);

    test(
        res == FXP_SUCCESS,
        "fxp_compact : return value"
    );

    test(
        fxp.e == 0,
        "fxp_compact : fxp.e"
    );

    test(
        fxp.num.sign == BI_SIGN_POSITIVE,
        "fxp_compact : num.sign"
    );

    test(
        fxp.num.occupied == 0,
        "fxp_compact : num.occupied"
    );

	free(fxp.num.data);
}

// case positive e
void		test_fxp_compact_case5(void)
{
	printf(KYEL "test_fxp_compact_case5\n" KNRM);
	t_fixedpoint	fxp;
	int				res;

	fxp_new(&fxp, 1, BI_SIGN_NEGATIVE);

    bi_push(&(fxp.num), 0x1c);
    bi_push(&(fxp.num), 0x6a);
    bi_push(&(fxp.num), 0x01);
    fxp.e = 2;

    res = fxp_compact(&fxp);

    test(
        res == FXP_SUCCESS,
        "fxp_compact : return value"
    );

    test(
        fxp.e == 4,
        "fxp_compact : fxp.e"
    );

    test(
        fxp.num.sign == BI_SIGN_NEGATIVE,
        "fxp_compact : num.sign"
    );

    test(
        fxp.num.occupied == 2,
        "fxp_compact : num.occupied"
    );

    test(
        fxp.num.data[0] == 0x9f,
        "fxp_compact : num.data[0]"
    );

    test(
        fxp.num.data[1] == 0x03,
        "fxp_compact : num.data[1]"
    );

	free(fxp.num.data);
}

// case negative e (0.00123000)
void		test_fxp_compact_case6(void)
{
	printf(KYEL "test_fxp_compact_case6\n" KNRM);
	t_fixedpoint	fxp;
	int				res;

	fxp_new(&fxp, 1, BI_SIGN_NEGATIVE);

    bi_push(&(fxp.num), 0x78);
    bi_push(&(fxp.num), 0xe0);
    bi_push(&(fxp.num), 0x01);
    fxp.e = -8;

    res = fxp_compact(&fxp);

    test(
        res == FXP_SUCCESS,
        "fxp_compact : return value"
    );

    test(
        fxp.e == -5,
        "fxp_compact : fxp.e"
    );

    test(
        fxp.num.sign == BI_SIGN_NEGATIVE,
        "fxp_compact : num.sign"
    );

    test(
        fxp.num.occupied == 1,
        "fxp_compact : num.occupied"
    );

    test(
        fxp.num.data[0] == 0x7b,
        "fxp_compact : num.data[0]"
    );

	free(fxp.num.data);
}

// case big (100200300400500600000)
void		test_fxp_compact_case7(void)
{
	printf(KYEL "test_fxp_compact_case7\n" KNRM);
	t_fixedpoint	fxp;
	int				res;
    unsigned char   expected[7] = {
        0x03, 0x8f, 0x51, 0x01, 0x1e, 0x1a, 0x8e
    };

	fxp_new(&fxp, 1, BI_SIGN_POSITIVE);

    bi_push(&(fxp.num), 0xc0);
    bi_push(&(fxp.num), 0xec);
    bi_push(&(fxp.num), 0x44);
    bi_push(&(fxp.num), 0x8f);
    bi_push(&(fxp.num), 0x54);
    bi_push(&(fxp.num), 0xfa);
    bi_push(&(fxp.num), 0x8e);
    bi_push(&(fxp.num), 0x6e);
    bi_push(&(fxp.num), 0x05);
    fxp.e = -8;

    res = fxp_compact(&fxp);

    test(
        res == FXP_SUCCESS,
        "fxp_compact : return value"
    );

    test(
        fxp.e == -3,
        "fxp_compact : fxp.e"
    );

    test(
        fxp.num.sign == BI_SIGN_POSITIVE,
        "fxp_compact : num.sign"
    );

    test(
        fxp.num.occupied == 7,
        "fxp_compact : num.occupied"
    );

    for (size_t i=fxp.num.occupied; i > 0; i--)
        test(
            fxp.num.data[i - 1] == expected[7 - i],
            "fxp_compact : num.data[i]"
        );

	free(fxp.num.data);
}