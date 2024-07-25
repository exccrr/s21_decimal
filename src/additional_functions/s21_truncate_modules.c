#include "s21_add_functions.h"

/**
 * Возвращает целые цифры указанного long decimal числа
 * @param value указатель на long decimal
 * @param scale int
 * */
void s21_truncate_modules(s21_decimal_long *value, int scale) {
  s21_decimal_long value_const = {0}, temp = {0};
  value_const.bits[0] = 10;
  memcpy(temp.bits, value->bits, sizeof(value->bits));

  for (int i = 0; i < scale; i++) {
    memset(value->bits, 0, sizeof(value->bits));
    s21_div_modules(temp, value_const, value);
    memcpy(temp.bits, value->bits, sizeof(value->bits));
  }
}
