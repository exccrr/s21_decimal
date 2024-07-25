#ifndef SRC_TESTS_S21_TESTS_H_
#define SRC_TESTS_S21_TESTS_H_

#include <check.h>

#include "../s21_decimal.h"

#define FALSE 0
#define TRUE 1
#define TWO 2
#define THREE 3

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\e[0;94m"

#define MAX_INT 2147483647   // 0b01111111111111111111111111111111
#define MAX_UINT 4294967295  // 0b11111111111111111111111111111111
#define MINUS 2147483648     // 0b10000000000000000000000000000000
#define EXPONENT_20 1310720  // 0b00000000000101000000000000000000

/// =============== VARIABLES ===============
s21_decimal max = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
s21_decimal middle = {{MAX_INT, MAX_INT, MAX_INT, 0}};
s21_decimal null = {{0, 0, 0, 0}};
s21_decimal null_minus = {{0, 0, 0, MINUS}};
s21_decimal middle_minus = {{MAX_INT, MAX_INT, MAX_INT, MINUS}};
s21_decimal max_minus = {{MAX_UINT, MAX_UINT, MAX_UINT, MINUS}};
s21_decimal middle_fractions = {{MAX_INT, MAX_INT, MAX_INT, EXPONENT_20}};
s21_decimal middle_fractions_minus = {
    {MAX_INT, MAX_INT, MAX_INT, (EXPONENT_20 | MINUS)}};
s21_decimal round_num = {{4560000, 0, 0, 327680}};
s21_decimal floor_num = {{0, 0, 0, MAX_INT}};
s21_decimal tmp = {{15, 0, 0, MINUS}};
s21_decimal tmp_2 = {{4, 0, 0, 0}};
s21_decimal tmp_float = {{214748413, 0, 0, 0b00000000000000010000000000000000}};

/// ===============   RESULTS  ===============
s21_decimal temp_res = {{0, 0, 0, 0}};
// =============== ARITHMETIC FUNCTIONS ===============
s21_decimal res_middle_add_middle_fractions = {
    {2543624459, 2147483647, 2147483647, 0}};
s21_decimal res_middle_add_middle = {{4294967294, 4294967294, 4294967294, 0}};
s21_decimal res_middle_minus_add_middle_minus = {
    {4294967294, 4294967294, 4294967294, MINUS}};
s21_decimal res_middle_fractions_add_middle_fractions = {
    {4294967294, 4294967294, 4294967294, EXPONENT_20}};
s21_decimal res_middle_add_max_minus = {
    {2147483648, 2147483648, 2147483648, MINUS}};
s21_decimal res_max_sub_middle = {{2147483648, 2147483648, 2147483648, 0}};
s21_decimal res_middle_fraction_sub_middle_fraction = {
    {20482339, 3303706602, 142724, 0}};
s21_decimal res_middle_fraction_mul_middle_fraction = {
    {3034176889, 3892122324, 850705916, 720896}};
s21_decimal res_middle_fraction_mul_middle_fraction_minus = {
    {3034176889, 3892122324, 850705916, (720896 | MINUS)}};
s21_decimal res_max_div_middle = {{495533628, 3169427839, 1084202172, 1835008}};
s21_decimal res_middle_div_max = {{1489344416, 250255873, 271050543, 1835008}};
s21_decimal res_max_minus_div_middle = {
    {495533628, 3169427839, 1084202172, (1835008 | MINUS)}};
s21_decimal res_max_mod_middle = {{1, 1, 1, 0}};
s21_decimal res_tmp_mod_tmp_2 = {{3, 0, 0, MINUS}};
// =========== CONVERSION & OTHER FUNCTIONS ============
s21_decimal res_floor_middle_fractions = {{396140812, 0, 0, 0}};
s21_decimal res_floor_middle_fractions_minus = {{396140813, 0, 0, MINUS}};
s21_decimal res_round_middle_fractions_minus = {{396140812, 0, 0, MINUS}};
s21_decimal res_round = {{46, 0, 0, 0}};
s21_decimal res_floor = {{0, 0, 0, MINUS}};
s21_decimal res_from_float_to_decimal = {{21474840, 0, 0, 0}};

#endif  // SRC_TESTS_S21_TESTS_H_
