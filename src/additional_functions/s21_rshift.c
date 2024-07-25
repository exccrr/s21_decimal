#include "s21_add_functions.h"

/**
 * Битовый сдвиг в право на 1 значения long decimal
 * @param value указатель на long decimal
 * */
void s21_rshift(s21_decimal_long *value) {
  int64_t carry = 0, temp = 0;
  carry = (((int64_t)value->bits[6] & (1 << 31)) != 0);
  for (int i = 6; i >= 0; i--) {
    temp = (int64_t)value->bits[i] & 1;  // Выделить младший разряд (перенос)
    value->bits[i] >>= 1;  // Сдвинуть вправо и установить
    value->bits[i] |= carry << 31;  // старый перенос в старший разряд
    carry = temp;  // Запомнить новый перенос
  }
}
