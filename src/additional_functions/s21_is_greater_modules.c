#include "s21_add_functions.h"

/**
 * Возвращает результат сравнеия двух long decimal
 * @param value_1 long decimal
 * @param value_2 long decimal
 * @return int 1 если value_1 > value_2, инче 0
 * */
int s21_is_greater_modules(s21_decimal_long value_1, s21_decimal_long value_2) {
  int res = 0;

  for (int i = 6; i >= 0; i--) {
    if (value_1.bits[i] > value_2.bits[i]) {
      res = 1;
      break;
    } else if (value_1.bits[i] < value_2.bits[i]) {
      break;
    }
  }

  return res;
}
