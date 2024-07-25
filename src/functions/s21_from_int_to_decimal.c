#include "../additional_functions/s21_add_functions.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int output = 1;
  int tmp_src = src;

  if (dst != NULL) {
    memset(dst->bits, 0, sizeof(dst->bits));
    if (tmp_src & (1 << 31)) {
      s21_set_bit_true(dst, 127);
      tmp_src = (~tmp_src) + 1;
    }
    dst->bits[0] = tmp_src;
    output = (dst->bits[0] != (uint)tmp_src) ? 1 : 0;
  }

  return output;
}
