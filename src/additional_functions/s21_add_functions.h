#ifndef SRC_S21_ADD_FUNCTIONS_H_
#define SRC_S21_ADD_FUNCTIONS_H_

#include "../s21_decimal.h"
#include "s21_structures.h"

void s21_parse_add(s21_decimal_long, s21_decimal_long, s21_decimal_long *,
                   s21_decimal, s21_decimal, s21_decimal *);
void s21_parse_sub(s21_decimal_long, s21_decimal_long, s21_decimal_long *,
                   s21_decimal, s21_decimal, s21_decimal *);
void s21_parse_mul(s21_decimal_long, s21_decimal_long, s21_decimal_long *,
                   s21_decimal, s21_decimal, s21_decimal *);
void s21_parse_div(s21_decimal_long, s21_decimal_long, s21_decimal_long *,
                   s21_decimal, s21_decimal, s21_decimal *);
void s21_add_modules(s21_decimal_long, s21_decimal_long, s21_decimal_long *);
void s21_sub_modules(s21_decimal_long, s21_decimal_long, s21_decimal_long *);
void s21_mul_modules(s21_decimal_long, s21_decimal_long, s21_decimal_long *);
void s21_div_modules(s21_decimal_long, s21_decimal_long, s21_decimal_long *);
void s21_mod_modules(s21_decimal_long, s21_decimal_long, s21_decimal_long *);
void s21_div_parsing(s21_decimal_long, s21_decimal_long, s21_decimal_long *,
                     s21_decimal_long *, s21_decimal *);
void s21_normalize_add_modules(s21_decimal_long *, s21_decimal_long *,
                               s21_decimal *, int, int);
void s21_normalize_div_modules(s21_decimal_long *, s21_decimal_long *,
                               s21_decimal *, int, int);
int s21_rounding(s21_decimal_long *value, s21_decimal *result, int bits,
                 int method);
int s21_rounding_fractions(s21_decimal *value, int bits, int method);
int s21_is_greater_or_equal_modules(s21_decimal_long, s21_decimal_long);
int s21_is_greater_modules(s21_decimal_long, s21_decimal_long);
int s21_is_equal_modules(s21_decimal_long, s21_decimal_long);
int s21_is_less_modules(s21_decimal_long, s21_decimal_long);
void s21_normalize(s21_decimal_long *value, int scale_diff);
void s21_set_n_bit_true(s21_decimal_long *value, int pos);
s21_decimal_long s21_lshift_out(s21_decimal_long value);
void s21_truncate_nulls(s21_decimal_long *, s21_decimal *);
int s21_parse_float(s21_decimal *tmp_src, float *dst, int sign);
void s21_parse_dec(float tmp_src, float src, s21_decimal *dst);
void s21_truncate_modules(s21_decimal_long *, int);
void s21_set_bit_false(s21_decimal *value, int pos);
void s21_set_bit_true(s21_decimal *value, int pos);
int s21_parse_rounding(s21_decimal *, int method);
int s21_round_result(s21_decimal *, s21_decimal_long);
void s21_set_the_scale(s21_decimal *value, int scale);
int s21_get_the_scale(s21_decimal value);
int s21_bits_len(s21_decimal_long value);
int s21_get_sign(s21_decimal value);
void s21_rshift(s21_decimal_long *num);
void s21_lshift(s21_decimal_long *num);
void s21_neg(s21_decimal_long *num);
int s21_get_exponent(float value);

/*
заполнение в decimal:
___________________________________________________________________
    11111111 11111111 11111111 11111111 -> s21_decimal.bits[2] - старшие биты
    11111111 11111111 11111111 11111111 -> s21_decimal.bits[1] - средние биты
    11111111 11111111 11111111 11111111 -> s21_decimal.bits[0] - младшие биты
    10000000 00010100 00000000 00000000 -> s21_decimal.bits[3] - знак =
'-'(0b10000000) и коэффициент = 20(0b00010100)
____________________________________________________________________
{   11111111 11111111 11111111 11111111 -> s21_decimal.bits[2] - старшие
    11111111 11111111 11111111 11111111 -> s21_decimal.bits[1] - средние
    11111111 11111111 11111111 11111111 -> s21_decimal.bits[0] - младшие
} == 79228162514264337593543950335 (full)
_____________________________________________________________________
{   11111111 11111111 11111111 11111111 -> s21_decimal.bits[2]
    00000000 00000000 00000000 00000000 -> s21_decimal.bits[1]
    00000000 00000000 00000000 00000000 -> s21_decimal.bits[0]
} == 79228162495817593519834398720
_____________________________________________________________________
{   00000000 00000000 00000000 00000000 -> Здесь могла бы быть Ваша реклама!)
    00000000 00000000 00000000 00000000
    11111111 11111111 11111111 11111111 -> s21_decimal.bits[0]
{ == 4294967295
______________________________________________________________________
{   00000000 00000000 00000000 00000000
    11111111 11111111 11111111 11111111 -> s21_decimal.bits[1]
    00000000 00000000 00000000 00000000
} == 18446744069414584320
 */
#endif  // SRC_S21_ADD_FUNCTIONS_H_
