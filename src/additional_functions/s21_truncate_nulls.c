#include "s21_add_functions.h"

/**
 * Записывает в result показатель степени, который указывает степень 10, после
 * сокращения нулей в конце. А в long decimal целая часть без лишних нулей в
 * конце
 * @param value указатель на long decimal
 * @param result указатель на long decimal
 * */
void s21_truncate_nulls(s21_decimal_long *value, s21_decimal *result) {
  s21_decimal_long temp = {0}, ten = {0};
  ten.bits[0] = 10;
  int result_int = s21_get_the_scale(*result);
  s21_mod_modules(*value, ten, &temp);
  while (!temp.bits[0] && result_int) {
    result_int--;
    s21_truncate_modules(value, 1);
    memset(temp.bits, 0, sizeof(temp.bits));
    s21_mod_modules(*value, ten, &temp);
  }
  s21_set_the_scale(result, result_int);
}
