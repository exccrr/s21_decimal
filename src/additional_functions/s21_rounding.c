#include "s21_add_functions.h"

/**
 * Функции округления
 * @param value указатель на long decimal
 * @param result указатель на decimal
 * @param bits int количество битов
 * @param method int номер способа округления округления
 * */
int s21_rounding(s21_decimal_long *value, s21_decimal *result, int bits,
                 int method) {
  int bit_depth = s21_bits_len(*value);
  int sign = s21_get_sign(*result);
  int scale = s21_get_the_scale(*result);
  s21_decimal_long const_ten = {0}, const_one = {0};
  const_one.bits[0] = 1, const_ten.bits[0] = 10;
  s21_decimal_long temp_fractions = {0};
  memcpy(temp_fractions.bits, value->bits, sizeof(value->bits));

  while ((bit_depth > bits && scale) || scale > 28) {
    scale--;
    s21_decimal_long temp_res = {0};
    s21_mod_modules(temp_fractions, const_ten, &temp_res);
    s21_truncate_modules(value, 1);
    s21_truncate_modules(&temp_fractions, 1);
    bit_depth = s21_bits_len(*value);

    if (temp_res.bits[0] >= 5 && method == 0) {
      if (bit_depth <= bits && scale <= 28)
        s21_add_modules(*value, const_one, value);
    } else if (temp_res.bits[0] && method == -1) {
      if (sign && bit_depth <= bits && !scale)
        s21_add_modules(*value, const_one, value);
    } else if (temp_res.bits[0] >= 5 && method == 1) {
      if (bit_depth <= bits && !scale)
        s21_add_modules(*value, const_one, value);
    }
    if (temp_res.bits[0] >= 5 &&
        (!scale || (bit_depth <= bits && scale <= 28)) && method == 2) {
      temp_res.bits[0] = 0;
      s21_mod_modules(*value, const_ten, &temp_res);
      if (temp_res.bits[0] % 2) s21_add_modules(*value, const_one, value);
    }
    temp_res.bits[0] = 0;
    bit_depth = s21_bits_len(*value);
  }
  s21_set_the_scale(result, scale);

  return bit_depth;
}
