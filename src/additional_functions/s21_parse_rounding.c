#include "s21_add_functions.h"

int s21_parse_rounding(s21_decimal *value, int method) {
  int output = 0;
  s21_decimal_long tmp_value = {0};
  memcpy(tmp_value.bits, value->bits, (sizeof(uint) * 3));
  int bit_depth = s21_bits_len(tmp_value);
  int scale = s21_get_the_scale(*value);

  if (bit_depth && scale <= 28 && scale >= 0) {
    s21_truncate_modules(&tmp_value, scale);
    bit_depth = s21_bits_len(tmp_value);
    output = s21_rounding_fractions(value, bit_depth, method);
  } else {
    int sign = s21_get_sign(*value);
    s21_set_the_scale(value, 0);
    if (sign) s21_set_bit_true(value, 127);
  }

  return output > 96 ? 1 : 0;
}
