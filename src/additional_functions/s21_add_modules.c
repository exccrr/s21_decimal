#include "s21_add_functions.h"

/**
 * Записывает в result результат сложения value_1 с value_2
 * @param value_1 long decimal
 * @param value_2 long decimal
 * @param result указатель на long decimal
 * */
void s21_add_modules(s21_decimal_long value_1, s21_decimal_long value_2,
                     s21_decimal_long *result) {
  int64_t temp = 0, carry = 0;  // Временная переменная и разряд переноса
  s21_decimal_long tmp;
  memcpy(tmp.bits, value_1.bits, sizeof(value_1));
  for (int i = 0; i < 7; i++) {
    result->bits[i] = temp = (int64_t)tmp.bits[i] + value_2.bits[i] + carry;
    carry = temp >> 32;  // Оставляем только перенос в следующий разряд
  }
}
