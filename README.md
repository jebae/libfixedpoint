# libfixedpoint

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/be6b26e1588446088a5cc5ec0d1d8955)](https://www.codacy.com/manual/jebae/libfixedpoint?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jebae/libfixedpoint&amp;utm_campaign=Badge_Grade)

C library **libfixedpoint** is made to handle fixed point decimal(not floating point).

<br><br>

## Requirements

This library is using [libft](https://github.com/jebae/libft) and [libbigint](https://github.com/jebae/libbigint)

```
# download libft
git clone https://github.com/jebae/libft.git

# download libbigint
git clone https://github.com/jebae/libbigint.git

# directory structure
root/
  libft/
  libbigint/
  libfixedpoint/
```

Instead of put libft and libbigint in same path with libfixedpoint, you can modify [Makefile](./Makefile) macro `LIBFT_PATH = ../libft`, `BIGINT_PATH = ../libbigint` with your path.

<br><br>

## Installation

```
make
```

<br><br>

## Usage

### struct

```c
typedef struct	s_fixedpoint
{
	t_bigint	num;
	long long	e;
}		t_fixedpoint;
```

`num` is decimal number and `e` is exponent of 10. For example 3.14 which is 314 x 10^(-2) can be saved as below.

```c
t_fixedpoint fxp;

bi_push(&fxp.num, 0x3a);
bi_push(&fxp.num, 0x01);
fxp.e = -2;
```

<br>

### Memory

```c
void fxp_init(t_fixedpoint *fxp);
void fxp_del(t_fixedpoint *fxp);
```

`fxp_init` initialize `num` which is `t_bigint` struct and `e` as 0.

`fxp_del` free memory and initiailize it.

<br><br>

### Operation

```c
int fxp_compact(t_fixedpoint *fxp);
```

`fxp_compact` is made to economize memory removing trailing zeros. 
3.140000 is 3140000 x 10^(-6). This is saved in `t_fixedpoint` with 0x2fe9a0 as `num` and -6 as `e`. After compacting fixed point is saved with 0x13a as `num` and -2 as `e`. It returns `FXP_FAIL` if there is error from memory allocating else `FXP_SUCCESS`.

<br>

```c
int fxp_mul_fxp(
	t_fixedpoint *a,
	t_fixedpoint *b,
	t_fixedpoint *c,
	int compact
);
```

`fxp_mul_fxp` follows `a * b = c`. If `compact` is 0, no compacting to result `c`. It returns `FXP_FAIL` if there is error from memory allocating else `FXP_SUCCESS`.

<br>

```c
int fxp_round(t_fixedpoint *fxp, long long r, t_fixedpoint *res);
```

`fxp_round` follows `round(fxp, r) = res`. It returns `FXP_FAIL` if there is error from memory allocating else `FXP_SUCCESS`.

<br><br>

## Seperating `double`, `long double`

```c
// double
int fxp_double_get_int_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
);

int fxp_double_get_fraction_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *fraction_part
);

// long double
int fxp_ldouble_get_int_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
);

int fxp_ldouble_get_fraction_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *fraction_part
);
```

`fxp_double_get_int_part` and `fxp_ldouble_get_int_part` get only integer part from `mantissa` and `exponent`. Result is assigned in `int_part`. It returns `FXP_FAIL` if there is error from memory allocating else `FXP_SUCCESS`.

`fxp_double_get_fraction_part` and `fxp_ldouble_get_fraction_part` get only fraction part from `mantissa` and `exponent`. Result is assigned in `fraction_part`. It returns `FXP_FAIL` if there is error from memory allocating else `FXP_SUCCESS`.
Seperating mantissa and exponent can be done easily. ([example](https://github.com/jebae/ft_printf/blob/master/srcs/parse_percent/float/float_utils.c))