#include "s21_add_functions.h"

/**
 * Возвращает результат битового сдвига в лево на 1 значения long decimal
 * @param value long decimal
 * @return long decimal
 * */
s21_decimal_long s21_lshift_out(s21_decimal_long value) {
  s21_decimal_long tmp;
  memcpy(tmp.bits, value.bits, sizeof(value));
  s21_lshift(&tmp);
  return tmp;
}
