#include "s21_add_functions.h"

/**
 * Возвращает значения бита отвечающего за знак поданного числа
 * @param value decimal
 * @return int значение 31 бита
 * */
int s21_get_sign(s21_decimal value) { return (value.bits[3] & 2147483648); }
