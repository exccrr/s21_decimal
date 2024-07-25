#include "../additional_functions/s21_add_functions.h"

/**
 * Функция записывает в result целые цифры указанного decimal числа; любые
 * дробные цифры отбрасываются, включая конечные нули
 * @param value decimal
 * @param result указатель на decimal
 * @return код выполнения функции  0 - ОК
 *                                 1 - ошибка вычисления
 */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int output = 1;
  s21_decimal_long tmp_val = {0};
  int sign = s21_get_sign(value);
  int scale = s21_get_the_scale(value);

  if (result != NULL) {
    if (scale <= 28 && scale >= 0) {
      memset(result->bits, 0, sizeof(result->bits));
      memcpy(tmp_val.bits, value.bits, (sizeof(uint) * 3));
      s21_truncate_modules(&tmp_val, scale);
      if (sign) s21_set_bit_true(result, 127);
      output = s21_round_result(result, tmp_val);
    } else {
      output = 0;
      memcpy(result->bits, value.bits, (sizeof(uint) * 3));
      if (sign) s21_set_bit_true(result, 127);
    }
  }

  return output ? 1 : output;
}
