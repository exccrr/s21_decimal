#include "s21_add_functions.h"

void s21_parse_add(s21_decimal_long tmp_val_1, s21_decimal_long tmp_val_2,
                   s21_decimal_long *tmp_res, s21_decimal value_1,
                   s21_decimal value_2, s21_decimal *result) {
  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);
  int scale_1 = s21_get_the_scale(value_1);
  int scale_2 = s21_get_the_scale(value_2);

  if (scale_1 < 39 && scale_2 < 39) {
    s21_normalize_add_modules(&tmp_val_1, &tmp_val_2, result, scale_1, scale_2);
    if (sign_1 == sign_2) {
      s21_add_modules(tmp_val_1, tmp_val_2, tmp_res);
      if (sign_1) s21_set_bit_true(result, 127);
    } else if (s21_is_greater_or_equal_modules(tmp_val_1, tmp_val_2)) {
      s21_sub_modules(tmp_val_1, tmp_val_2, tmp_res);
      if (sign_1) s21_set_bit_true(result, 127);
    } else {
      s21_sub_modules(tmp_val_2, tmp_val_1, tmp_res);
      if (sign_2) s21_set_bit_true(result, 127);
    }
  }
}
