#include "s21_add_functions.h"

/**
 * Инвертирует поданный long decimal
 * @param value указатель на long decimal
 * */
void s21_neg(s21_decimal_long *value) {
  int64_t temp = 0, carry = 1;
  for (int i = 0; i < 7; i++)
    value->bits[i] = ~value->bits[i];  // Инвертирование всех разрядов
  for (int t = 0; t < 7; t++) {
    value->bits[t] = temp = (int64_t)value->bits[t] + carry;
    carry = (temp & 4294967296) >> 32;
  }
}
