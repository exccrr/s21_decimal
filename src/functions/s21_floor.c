#include "../additional_functions/s21_add_functions.h"

/**
 * Функция округления указанного decimal числа до ближайшего целого числа в
 * сторону отрицательной бесконечности.
 * @param value decimal
 * @param result указатель на decimal
 * @return код выполнения функции  0 - ОК
 *                                 1 - ошибка вычисления
 */
int s21_floor(s21_decimal value, s21_decimal *result) {
  int output = 1;
  if (result != NULL) {
    memcpy(result->bits, value.bits, sizeof(value.bits));
    output = s21_parse_rounding(result, -1);
  }

  return output;
}
