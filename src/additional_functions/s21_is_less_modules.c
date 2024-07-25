#include "s21_add_functions.h"

/**
 * Возвращает результат сравнеия двух long decimal
 * @param value_1 long decimal
 * @param value_2 long decimal
 * @return int 1 если value_1 <= value_2, инче 0
 * */
int s21_is_less_modules(s21_decimal_long value_1, s21_decimal_long value_2) {
  return (!(s21_is_greater_modules(value_1, value_2) ||
            s21_is_equal_modules(value_1, value_2)));
}
