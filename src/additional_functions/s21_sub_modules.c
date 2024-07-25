#include "s21_add_functions.h"

/**
 * Записывает в result результат вычитания value_1 из value_2
 * @param value_1 long decimal
 * @param value_2 long decimal
 * @param result указатель на long decimal
 * */
void s21_sub_modules(s21_decimal_long value_1, s21_decimal_long value_2,
                     s21_decimal_long *result) {
  s21_decimal_long temp;
  memcpy(temp.bits, value_2.bits, sizeof(value_2));
  s21_neg(&temp);
  s21_add_modules(value_1, temp, result);
}
