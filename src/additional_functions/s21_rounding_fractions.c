#include "s21_add_functions.h"

/**
 * Функция округления
 * @param result указатель на decimal
 * @param bits int количество битов
 * @param method int номер способа округления округления
 * */
int s21_rounding_fractions(s21_decimal *value, int bits, int method) {
  s21_decimal_long tmp_value = {0};
  int sign = s21_get_sign(*value);
  memcpy(tmp_value.bits, value->bits, (sizeof(uint) * 3));

  switch (method) {
    case -1:
      s21_truncate_nulls(&tmp_value, value);
      if (sign) s21_set_bit_true(value, 127);
      s21_rounding(&tmp_value, value, bits, method);
      break;
    case 0:
      s21_rounding(&tmp_value, value, bits, method);
      break;
    case 1:
      s21_truncate_nulls(&tmp_value, value);
      s21_rounding(&tmp_value, value, bits, method);
      break;
  }

  memcpy(value->bits, tmp_value.bits, (sizeof(uint) * 3));
  if (sign) s21_set_bit_true(value, 127);

  return s21_bits_len(tmp_value);
}
