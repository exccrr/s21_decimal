#include "s21_add_functions.h"

/**
 * Установка 1 в n-ый бит значения decimal
 * @param value указатель на decimal
 * @param pos int
 * */
void s21_set_bit_true(s21_decimal *value, int pos) {
  value->bits[pos / 32] |= (1 << (pos % 32));
}
