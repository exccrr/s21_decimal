#include "../additional_functions/s21_add_functions.h"

/**
 * Записывает в res результат деления value_1 на value_2
 * @param res указатель на decimal
 * @param value_1 decimal
 * @param value_2 decimal
 * @return код выполнения фуннкции(0 - OK,
 *             1 - число слишком велико или равно бесконечности,
 *             2 - число слишком мало или равно отрицательной бесконечности
 *             3 - деление на 0)
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int output = 0;
  s21_decimal_long tmp_val_1 = {0}, tmp_val_2 = {0};
  s21_decimal_long tmp_res = {0}, tmp_mod = {0}, const_null = {0};

  if (result != NULL) {
    memset(result->bits, 0, sizeof(result->bits));
    memcpy(tmp_val_1.bits, value_1.bits, (sizeof(uint) * 3));
    memcpy(tmp_val_2.bits, value_2.bits, (sizeof(uint) * 3));

    if (!s21_is_equal_modules(tmp_val_2, const_null)) {
      int scale_1 = s21_get_the_scale(value_1);
      int scale_2 = s21_get_the_scale(value_2);
      if (scale_1 < 39 && scale_2 < 39) {
        s21_parse_div(tmp_val_1, tmp_val_2, &tmp_res, value_1, value_2, result);
        int sign = s21_get_sign(*result);
        s21_normalize_div_modules(&tmp_val_1, &tmp_val_2, result, scale_1,
                                  scale_2);
        s21_mod_modules(tmp_val_1, tmp_val_2, &tmp_mod);
        s21_div_parsing(const_null, tmp_val_2, &tmp_mod, &tmp_res, result);
        if (sign) s21_set_bit_true(result, 127);
        output = s21_round_result(result, tmp_res);
      }
    } else {
      output = 3;
    }
  }

  return output;
}
