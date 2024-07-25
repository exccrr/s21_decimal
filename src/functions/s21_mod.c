#include "../additional_functions/s21_add_functions.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int output = 0;
  s21_decimal_long res_multiply = {0};
  s21_decimal_long res_division = {0};
  s21_decimal_long tmp_val_1 = {0}, tmp_val_2 = {0}, tmp_res = {0};
  s21_decimal_long const_null = {0};

  if (result != NULL) {
    memset(result->bits, 0, sizeof(result->bits));
    memcpy(tmp_val_1.bits, value_1.bits, (sizeof(uint) * 3));
    memcpy(tmp_val_2.bits, value_2.bits, (sizeof(uint) * 3));

    if (!s21_is_equal_modules(tmp_val_2, const_null)) {
      s21_parse_div(tmp_val_1, tmp_val_2, &res_division, value_1, value_2,
                    result);
      int sign = s21_get_sign(*result);
      s21_set_the_scale(result, 0);
      if (sign) s21_set_bit_true(result, 127);
      s21_parse_mul(res_division, tmp_val_2, &res_multiply, *result, value_2,
                    result);
      s21_parse_sub(tmp_val_1, res_multiply, &tmp_res, value_1, *result,
                    result);
      output = s21_round_result(result, tmp_res);
    } else {
      output = 3;
    }
  }

  return output;
}
