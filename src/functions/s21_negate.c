#include "../additional_functions/s21_add_functions.h"

/**
 * Записывает в result инверсию поданного decimal
 * @param value decimal
 * @param result указатель на decimal
 * @return код выполнения функции  0 - ОК
 *                                 1 - ошибка вычисления
 */
int s21_negate(s21_decimal value, s21_decimal *result) {
  int output = 1;
  if (result != NULL) {
    int sign = s21_get_sign(value);
    memcpy(result->bits, value.bits, sizeof(value.bits));
    sign ? s21_set_bit_false(result, 127) : s21_set_bit_true(result, 127);
    output = (sign == s21_get_sign(*result));
  }

  return output;
}
