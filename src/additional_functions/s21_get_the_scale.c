#include "s21_add_functions.h"

/**
 * Возвращает показатель степени, который указывает степень 10 для деления
 * целого числа.
 * @param value long decimal
 * @return int значение степени
 * */
int s21_get_the_scale(s21_decimal value) {
  return ((value.bits[3] << 8) >> 24);
}
