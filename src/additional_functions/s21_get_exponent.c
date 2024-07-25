#include "s21_add_functions.h"

/**
 * Функция получения степени десятки
 * @param value число из которого надо получить экспоненту
 * @return чило степени десятки при приведении float к > 1
 * */
int s21_get_exponent(float value) {
  int exp = 0;
  while (value >= 1) {
    value /= 10;
    exp++;
  }
  return (exp - 8);
}
