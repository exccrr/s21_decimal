#include "s21_add_functions.h"

/**
 * Записывает в result результат округления и приведения к типу decimal значения
 * long decimal
 * @param result указатель на decimal
 * @param value long decimal
 * @return код выполнения фуннкции(0 - OK,
 *             1 - число слишком велико или равно бесконечности,
 *             2 - число слишком мало или равно отрицательной бесконечности)
 * */
int s21_round_result(s21_decimal *result, s21_decimal_long value) {
  s21_decimal_long temp_int = {0};
  int sign = s21_get_sign(*result);
  int bit_depth = s21_bits_len(value), output = 0;
  int scale = s21_get_the_scale(*result);
  memcpy(temp_int.bits, value.bits, sizeof(value.bits));
  s21_truncate_modules(&temp_int, scale);
  int bit_depth_truncate = s21_bits_len(temp_int);

  if (bit_depth && (bit_depth_truncate <= 96)) {
    s21_truncate_nulls(&value, result);
    if (s21_get_the_scale(*result) == 1) {
      bit_depth = s21_rounding(&value, result, 96, 2);
    } else {
      bit_depth = s21_rounding(&value, result, 96, 0);
    }
  }
  if (sign) s21_set_bit_true(result, 127);
  if (bit_depth > 96 || bit_depth_truncate > 96) {
    memset(value.bits, 0, sizeof(value.bits));
    output = s21_get_sign(*result) ? 2 : 1;
  }
  memcpy(result->bits, value.bits, (sizeof(uint) * 3));

  return output;
}
