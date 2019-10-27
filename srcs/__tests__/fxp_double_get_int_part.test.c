#include "fixedpoint.test.h"

// case 3.14
void		test_fxp_double_get_int_part_case1(void)
{
	printf(KYEL "test_fxp_double_get_int_part_case1\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 1;
	mantissa = 0x191eb851eb851f;

	fxp_double_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_double_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 1,
		"fxp_double_get_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x03,
		"fxp_double_get_int_part : int_part.num.data[0]"
	);

	fxp_del(&int_part);
}

// case 12345.6789
void		test_fxp_double_get_int_part_case2(void)
{
	printf(KYEL "test_fxp_double_get_int_part_case2\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 13;
	mantissa = 0x181cd6e631f8a1;

	fxp_double_get_int_part(exponent, mantissa, &int_part);
	
	test(
		int_part.e == 0,
		"fxp_double_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 2,
		"fxp_double_get_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x39,
		"fxp_double_get_int_part : int_part.num.data[0]"
	);

	test(
		int_part.num.data[1] == 0x30,
		"fxp_double_get_int_part : int_part.num.data[1]"
	);

	fxp_del(&int_part);
}

// case 123000.6789 with carry
void		test_fxp_double_get_int_part_case3(void)
{
	printf(KYEL "test_fxp_double_get_int_part_case3\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;

	fxp_double_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_double_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 3,
		"fxp_double_get_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x78,
		"fxp_double_get_int_part : int_part.num.data[0]"
	);

	test(
		int_part.num.data[1] == 0xe0,
		"fxp_double_get_int_part : int_part.num.data[1]"
	);
	test(
		int_part.num.data[2] == 0x01,
		"fxp_double_get_int_part : int_part.num.data[2]"
	);

	fxp_del(&int_part);
}

// case 0
void		test_fxp_double_get_int_part_case4(void)
{
	printf(KYEL "test_fxp_double_get_int_part_case4\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -4;
	mantissa = 0x1f9add37c1215e;

	fxp_double_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_double_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fxp_double_get_int_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}

// case big 1234512345123451234512345.12345
void		test_fxp_double_get_int_part_case5(void)
{
	printf(KYEL "test_fxp_double_get_int_part_case5\n" KNRM);
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
	mantissa = 0x1056b0c5f2b0d3;

	fxp_double_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_double_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 11,
		"fxp_double_get_int_part : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == expected[i],
			"fxp_double_get_int_part : int_part.num.data[i]"
		);

	fxp_del(&int_part);
}

// case small 0.00000000000000000000000000000000000000000000012345
void		test_fxp_double_get_int_part_case6(void)
{
	printf(KYEL "test_fxp_double_get_int_part_case6\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -153;
	mantissa = 0x168d841d0a2f8B;

	fxp_double_get_int_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fxp_double_get_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fxp_double_get_int_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}
