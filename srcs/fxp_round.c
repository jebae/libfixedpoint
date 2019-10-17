#include "fixedpoint.h"

static int		handle_fail(t_bigint *bcd)
{
	ft_memdel((void **)&bcd->data);
	return (FXP_FAIL);
}

static void		set_zero_below_pos(t_bigint *bcd, size_t pos)
{
	while (pos)
	{
		bcd_set_digit(bcd, pos - 1, 0);
		pos--;
	}
}

static int		roundup(t_bigint *bcd, size_t pos, size_t len)
{
	unsigned char	digit;
	unsigned char	carry;
	size_t			i;

	if ((digit = bcd_get_digit(bcd, pos - 1)) >= 5)
	{
		carry = 1;
		i = pos;
		while (i < len && carry > 0)
		{
			digit = bcd_get_digit(bcd, i) + carry;
			bcd_set_digit(bcd, i, digit % 10);
			carry = digit / 10;
			i++;
		}
		if (carry > 0)
		{
			if (len & 1)
				bcd_set_digit(bcd, len, 1);
			else if (bi_push(bcd, 0x01) == BI_FAIL)
				return (FXP_FAIL);
		}
	}
	set_zero_below_pos(bcd, pos);
	return (FXP_SUCCESS);
}

int				fxp_round(t_fixedpoint *fxp, long long r, t_fixedpoint *res)
{
	long long		len;
	long long		pos;
	t_bigint		bcd;

	if (bi_new(&bcd, 1, BI_SIGN_POSITIVE) == BI_FAIL)
		return (FXP_FAIL);
	if (bi_double_dabble(&fxp->num, &bcd) == BI_FAIL)
		return (handle_fail(&bcd));
	len = bcd_len(&bcd);
	pos = -(r + fxp->e);
	if (pos > len)
		bi_erase(&bcd);
	else if (pos > 0)
	{
		if (roundup(&bcd, pos, len) == FXP_FAIL)
			return (handle_fail(&bcd));
	}
	if (bcd.occupied == 0)
		res->e = 0;
	else
		res->e = fxp->e + bcd_rm_trailing_zero(&bcd);
	if (bi_rev_double_dabble(&bcd, &res->num) == BI_FAIL)
		return (handle_fail(&bcd));
	ft_memdel((void **)&bcd.data);
	return (FXP_SUCCESS);
}
