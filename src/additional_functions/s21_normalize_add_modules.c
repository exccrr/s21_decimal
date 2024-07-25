#include "s21_add_functions.h"

void s21_normalize_add_modules(s21_decimal_long *value_1,
                               s21_decimal_long *value_2, s21_decimal *result,
                               int scale_1, int scale_2) {
  if (scale_1 >= scale_2) {
    s21_set_the_scale(result, scale_1);
    s21_normalize(value_2, (scale_1 - scale_2));
  } else {
    s21_set_the_scale(result, scale_2);
    s21_normalize(value_1, (scale_2 - scale_1));
  }
}
