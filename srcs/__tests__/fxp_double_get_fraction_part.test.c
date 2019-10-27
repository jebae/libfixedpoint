#include "fixedpoint.test.h"

// case 3.14
void		test_fxp_double_get_fraction_part_case1(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case1\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);
	exponent = 1;
	mantissa = 0x191eb851eb851f;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);

	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.60f\n", 3.14);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 12345.6789
void		test_fxp_double_get_fraction_part_case2(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case2\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);
	exponent = 13;	mantissa = 0x181cd6e631f8a1;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);

	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.60f\n", 12345.6789);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 123000.6789
void		test_fxp_double_get_fraction_part_case3(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case3\n" KNRM);
	short				exponent;	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);

	exponent = 16;
	mantissa = 0x1e078adcc63f14;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);
	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.60f\n", 123000.6789);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 12345.0
void		test_fxp_double_get_fraction_part_case4(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case4\n" KNRM);
	short				exponent;	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);

	exponent = 13;
	mantissa = 0x181c8000000000;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);

	printf("fraction_part.num.occupied : %zu\n", fraction_part.num.occupied);
	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.60f\n", 12345.0);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.123451234512345123451234512345
void		test_fxp_double_get_fraction_part_case5(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case5\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);
	exponent = -4;
	mantissa = 0x1f9a8006e1a013;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);
	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.60f\n", 0.123451234512345123451234512345);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.00000000000000000000000000000012345
void		test_fxp_double_get_fraction_part_case6(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case6\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);
	exponent = -103;
	mantissa = 0x1407e9919234d8;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);
	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.160f\n", 0.00000000000000000000000000000012345);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.123451234512345123451234512345, precision 4
void		test_fxp_double_get_fraction_part_case7(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case7\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);
	exponent = -4;
	mantissa = 0x1f9a8006e1a013;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);
	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.4f\n", 0.123451234512345123451234512345);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.00000000000000000000000000000012345, precision 34
void		test_fxp_double_get_fraction_part_case8(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case8\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);
	exponent = -103;
	mantissa = 0x1407e9919234d8;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);
	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.34f\n", 0.00000000000000000000000000000012345);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 3.9999999999
void		test_fxp_double_get_fraction_part_case9(void)
{
	printf(KYEL "test_fxp_double_get_fraction_part_case9\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	bi_init(&bcd);
	fxp_init(&fraction_part);
	exponent = 1;
	mantissa = 0x1ffffffffc9064;

	fxp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	bi_double_dabble(&fraction_part.num, &bcd);
	printf("result : ");
	for (size_t i=bcd_len(&bcd); i > 0; i--)
		printf("%c", bcd_get_digit(&bcd, i - 1) + '0');
	printf("\n");
	printf("expect : %.6f\n", 3.9999999999);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

