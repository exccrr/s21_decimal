#include "s21_add_functions.h"

/*
 * Возвращает количество значащих битов в переданном long decimal
 * @param value long decimal
 * @return int количество битов
 *
 * */

int s21_bits_len(s21_decimal_long value) {
  int res = 0;
  s21_decimal_long null = {0};
  s21_decimal_long temp_value;
  memcpy(temp_value.bits, value.bits, sizeof(value.bits));

  while (!s21_is_equal_modules(temp_value, null)) {
    s21_rshift(&temp_value);
    res++;
  }

  return res;
}
