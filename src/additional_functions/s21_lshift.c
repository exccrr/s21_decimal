#include "s21_add_functions.h"

/**
 * Битовый сдвиг в лево на 1 значения long decimal
 * @param value указатель на long decimal
 * */
void s21_lshift(s21_decimal_long *value) {
  int64_t carry = 0, temp = 0;
  for (int i = 0; i < 7; i++) {
    temp = ((int64_t)value->bits[i] & (1 << 31)) >>
           31;  // Выделить старший разряд (перенос)
    value->bits[i] <<= 1;  // Сдвинуть влево и установить
    value->bits[i] |= carry;  // старый перенос в младший разряд
    carry = temp;             // Запомнить новый перенос
  }
}
