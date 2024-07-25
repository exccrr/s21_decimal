#include "s21_add_functions.h"

/**
 * Записывает в decimal показатель степени, который указывает степень 10 для
 * разделения целого числа.
 * @param value long decimal
 * @return int значение степени
 * */
void s21_set_the_scale(s21_decimal *value, int scale) {
  value->bits[3] = ((value->bits[3] + scale) << 16);
}
