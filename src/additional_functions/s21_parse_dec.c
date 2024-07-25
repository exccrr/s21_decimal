#include "s21_add_functions.h"

void s21_parse_dec(float tmp_src, float src, s21_decimal *dst) {
  int exp = s21_get_exponent(tmp_src);
  tmp_src /= powf(10, (float)exp);
  dst->bits[0] = (int)tmp_src;
  if ((dst->bits[0] % 10) >= 5) {
    dst->bits[0] = (dst->bits[0] / 10) + 1;
  } else {
    dst->bits[0] /= 10;
  }
  s21_decimal tmp = {{10, 0, 0, 0}};
  for (int i = 0; i < (exp + 1); i++) s21_mul(*dst, tmp, dst);
  if (src < 0) s21_set_bit_true(dst, 127);
}
