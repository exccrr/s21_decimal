#include "s21_add_functions.h"

/**
 * Записывает в result произведение value_1 и value_2
 * @param value_1 long decimal
 * @param value_2 long decimal
 * @param result указатель на long decimal
 * */
void s21_mul_modules(s21_decimal_long value_1, s21_decimal_long value_2,
                     s21_decimal_long *result) {
  s21_decimal_long temp_1, temp_2;
  memcpy(temp_1.bits, value_1.bits, sizeof(value_1));
  memcpy(temp_2.bits, value_2.bits, sizeof(value_2));
  for (int t = 0; t < (7 * 32); t++) {
    if (temp_2.bits[0] & 1) {
      s21_add_modules(*result, temp_1, result);
    }
    s21_lshift(&temp_1);
    s21_rshift(&temp_2);
  }
}
