#include "s21_add_functions.h"

void s21_parse_mul(s21_decimal_long tmp_val_1, s21_decimal_long tmp_val_2,
                   s21_decimal_long *tmp_res, s21_decimal value_1,
                   s21_decimal value_2, s21_decimal *result) {
  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);
  int scale_1 = s21_get_the_scale(value_1);
  int scale_2 = s21_get_the_scale(value_2);

  if (scale_1 >= scale_2) {
    s21_set_the_scale(result, (scale_1 + scale_2));
  } else {
    s21_set_the_scale(result, (scale_2 + scale_1));
  }

  if (sign_1 != sign_2) s21_set_bit_true(result, 127);
  s21_mul_modules(tmp_val_1, tmp_val_2, tmp_res);
}
