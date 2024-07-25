#include "s21_add_functions.h"

void s21_div_parsing(s21_decimal_long const_null, s21_decimal_long val,
                     s21_decimal_long *mod, s21_decimal_long *res,
                     s21_decimal *result) {
  int tmp_scale = s21_get_the_scale(*result);
  while (!s21_is_equal_modules(*mod, const_null) && (tmp_scale <= 31)) {
    while (s21_is_less_modules(*mod, val) && (tmp_scale <= 31)) {
      tmp_scale = tmp_scale + 1;
      s21_normalize(res, 1);
      s21_normalize(mod, 1);
    }
    s21_decimal_long tmp_res_div = {0}, tmp_res_mod = {0};
    s21_div_modules(*mod, val, &tmp_res_div);
    s21_add_modules(*res, tmp_res_div, res);
    s21_mod_modules(*mod, val, &tmp_res_mod);
    memcpy(mod->bits, tmp_res_mod.bits, sizeof(mod->bits));
    s21_set_the_scale(result, tmp_scale);
  }
}
