#include "fixedpoint.test.h"

// case 3.14
void		test_fxp_ldouble_get_int_part_case1(void)
{
	printf(KYEL "test_fxp_ldouble_get_int_part_case1\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 1;
	mantissa = 0xc8f5c28f5c28f800;

	fxp_ldouble_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_ldouble_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 1,
		"fxp_ldouble_get_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x03,
		"fxp_ldouble_get_int_part : int_part.num.data[0]"
	);

	fxp_del(&int_part);
}

// case 12345.6789
void		test_fxp_ldouble_get_int_part_case2(void)
{
	printf(KYEL "test_fxp_ldouble_get_int_part_case2\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 13;
	mantissa = 0xc0e6b7318fc50800;

	fxp_ldouble_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_ldouble_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 2,
		"fxp_ldouble_get_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x39,
		"fxp_ldouble_get_int_part : int_part.num.data[0]"
	);

	test(
		int_part.num.data[1] == 0x30,
		"fxp_ldouble_get_int_part : int_part.num.data[1]"
	);

	fxp_del(&int_part);
}

// case compact 123000.6789
void		test_fxp_ldouble_get_int_part_case3(void)
{
	printf(KYEL "test_fxp_ldouble_get_int_part_case3\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 16;
	mantissa = 0xf03c56e631f8a000;

	fxp_ldouble_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_ldouble_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 3,
		"fxp_ldouble_get_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x78,
		"fxp_ldouble_get_int_part : int_part.num.data[0]"
	);

	test(
		int_part.num.data[1] == 0xe0,
		"fxp_ldouble_get_int_part : int_part.num.data[1]"
	);
	test(
		int_part.num.data[2] == 0x01,
		"fxp_ldouble_get_int_part : int_part.num.data[2]"
	);

	fxp_del(&int_part);
}

// case 0
void		test_fxp_ldouble_get_int_part_case4(void)
{
	printf(KYEL "test_fxp_ldouble_get_int_part_case4\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -4;
	mantissa = 0xfcd35a858793e000;

	fxp_ldouble_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_ldouble_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fxp_ldouble_get_int_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}

// case big 1234512345123451234512345.12345
void		test_fxp_ldouble_get_int_part_case5(void)
{
	printf(KYEL "test_fxp_ldouble_get_int_part_case5\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;
	unsigned char		expected[11] = {
		0x00, 0x00, 0x00, 0x30,
		0x0d, 0x2b, 0x5f, 0x0c,
		0x6b, 0x05, 0x01
	};

	fxp_init(&int_part);
	exponent = 80;
	mantissa = 0x82b5862f95869800;

	fxp_ldouble_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_ldouble_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 11,
		"fxp_ldouble_get_int_part : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == expected[i],
			"fxp_ldouble_get_int_part : int_part.num.data[i]"
		);

	fxp_del(&int_part);
}

// case small 0.00000000000000000000000000000000000000000000012345
void		test_fxp_ldouble_get_int_part_case6(void)
{
	printf(KYEL "test_fxp_ldouble_get_int_part_case6\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -153;
	mantissa = 0xb46c20e8517c5800;

	fxp_ldouble_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_ldouble_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fxp_ldouble_get_int_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}
