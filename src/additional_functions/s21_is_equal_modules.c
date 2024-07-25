#include "s21_add_functions.h"

/**
 * Возвращает результат сравнеия двух long decimal
 * @param value_1 long decimal
 * @param value_2 long decimal
 * @return int 1 если value_1 = value_2, инче 0
 * */
int s21_is_equal_modules(s21_decimal_long value_1, s21_decimal_long value_2) {
  return value_1.bits[6] == value_2.bits[6] &&
         value_1.bits[5] == value_2.bits[5] &&
         value_1.bits[4] == value_2.bits[4] &&
         value_1.bits[3] == value_2.bits[3] &&
         value_1.bits[2] == value_2.bits[2] &&
         value_1.bits[1] == value_2.bits[1] &&
         value_1.bits[0] == value_2.bits[0];
}
