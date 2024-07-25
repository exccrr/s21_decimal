#include "s21_add_functions.h"

int s21_parse_float(s21_decimal *tmp_src, float *dst, int sign) {
  int exp = 0;
  s21_decimal_long temp = {0};
  memcpy(temp.bits, tmp_src->bits, (sizeof(uint) * 3));
  while (temp.bits[0]) {
    s21_truncate_modules(&temp, 1);
    exp++;
  }
  exp = exp - 8;
  memcpy(temp.bits, tmp_src->bits, (sizeof(uint) * 3));
  s21_truncate_modules(&temp, exp);
  if ((temp.bits[0] % 10) >= 5) {
    temp.bits[0] = (temp.bits[0] / 10) + 1;
  } else {
    temp.bits[0] /= 10;
  }
  *dst = temp.bits[0];
  *dst *= powf(10, (float)(exp + 1));
  if (sign) *dst *= -1;

  return (exp + 1) ? 0 : 1;
}
