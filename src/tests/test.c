#include "s21_tests.h"

START_TEST(is_less) {
  ck_assert_int_eq(TRUE, s21_is_less(middle, max));
  ck_assert_int_eq(FALSE, s21_is_less(max, middle));
  ck_assert_int_eq(TRUE, s21_is_less(middle_fractions, middle));
  ck_assert_int_eq(TRUE, s21_is_less(middle_minus, middle));
  ck_assert_int_eq(FALSE, s21_is_less(null_minus, null));
}
END_TEST

START_TEST(is_less_or_equal) {
  ck_assert_int_eq(FALSE, s21_is_less_or_equal(middle, null));
  ck_assert_int_eq(TRUE, s21_is_less_or_equal(middle_minus, null));
  ck_assert_int_eq(TRUE, s21_is_less_or_equal(max_minus, middle));
  ck_assert_int_eq(FALSE, s21_is_less_or_equal(middle, middle_fractions));
  ck_assert_int_eq(TRUE, s21_is_less_or_equal(null, null_minus));
}
END_TEST

START_TEST(is_greater) {
  ck_assert_int_eq(TRUE, s21_is_greater(middle, null));
  ck_assert_int_eq(FALSE, s21_is_greater(middle, max));
  ck_assert_int_eq(TRUE, s21_is_greater(middle, max_minus));
  ck_assert_int_eq(TRUE, s21_is_greater(middle_fractions, middle_minus));
  ck_assert_int_eq(FALSE, s21_is_greater(middle_minus, null));
}
END_TEST

START_TEST(is_greater_or_equal) {
  ck_assert_int_eq(TRUE, s21_is_greater_or_equal(max, middle));
  ck_assert_int_eq(FALSE, s21_is_greater_or_equal(middle, max));
  ck_assert_int_eq(TRUE, s21_is_greater_or_equal(null, max_minus));
  ck_assert_int_eq(FALSE, s21_is_greater_or_equal(middle_fractions, middle));
  ck_assert_int_eq(TRUE, s21_is_greater_or_equal(null_minus, null));
}
END_TEST

START_TEST(is_equal) {
  ck_assert_int_eq(FALSE, s21_is_equal(middle, max));
  ck_assert_int_eq(FALSE, s21_is_equal(middle, middle_fractions));
  ck_assert_int_eq(TRUE, s21_is_equal(null, null_minus));
}
END_TEST

START_TEST(is_not_equal) {
  ck_assert_int_eq(TRUE, s21_is_not_equal(middle, middle_fractions));
  ck_assert_int_eq(TRUE, s21_is_not_equal(middle, max));
  ck_assert_int_eq(FALSE, s21_is_not_equal(null, null_minus));
}
END_TEST

START_TEST(add) {
  int output = s21_add(middle, middle_fractions, &temp_res);
  ck_assert_int_eq(TRUE,
                   s21_is_equal(res_middle_add_middle_fractions, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_add(middle, middle, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_middle_add_middle, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_add(middle, max_minus, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_middle_add_max_minus, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_add(middle_minus, middle_minus, &temp_res);
  ck_assert_int_eq(TRUE,
                   s21_is_equal(res_middle_minus_add_middle_minus, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_add(middle_fractions, middle_fractions, &temp_res);
  ck_assert_int_eq(
      TRUE, s21_is_equal(res_middle_fractions_add_middle_fractions, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_add(max, max, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(TRUE, output);
  output = s21_add(max_minus, max_minus, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(TWO, output);
}
END_TEST

START_TEST(sub) {
  int output = s21_sub(max_minus, middle_minus, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_middle_add_max_minus, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_sub(max, middle, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_max_sub_middle, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_sub(middle_fractions, middle_minus, &temp_res);
  ck_assert_int_eq(TRUE,
                   s21_is_equal(res_middle_add_middle_fractions, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_sub(max_minus, max, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(TWO, output);
  output = s21_sub(max, middle_minus, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(TRUE, output);
  output = s21_sub(max_minus, middle, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(TWO, output);
}
END_TEST

START_TEST(mul) {
  int output = s21_mul(middle_fractions, middle_fractions, &temp_res);
  ck_assert_int_eq(
      TRUE, s21_is_equal(res_middle_fraction_mul_middle_fraction, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_mul(middle_fractions, null, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_mul(middle_fractions, middle_fractions_minus, &temp_res);
  ck_assert_int_eq(
      TRUE,
      s21_is_equal(res_middle_fraction_mul_middle_fraction_minus, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_mul(middle, middle, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(TRUE, output);
  output = s21_mul(middle_minus, middle, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(TWO, output);
}
END_TEST

START_TEST(div) {
  int output = s21_div(max, middle, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_max_div_middle, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_div(middle, max, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_middle_div_max, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_div(max, null, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(null, temp_res));
  ck_assert_int_eq(THREE, output);
  output = s21_div(max_minus, middle, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_max_minus_div_middle, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_div(max, middle_minus, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_max_minus_div_middle, temp_res));
  ck_assert_int_eq(FALSE, output);
}
END_TEST

START_TEST(mod) {
  int output = s21_mod(max, middle, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_max_mod_middle, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_mod(middle, max, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(middle, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_mod(tmp, tmp_2, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_tmp_mod_tmp_2, temp_res));
  ck_assert_int_eq(FALSE, output);
  s21_decimal tmp = {{1234, 0, 0, 131072}};
  s21_decimal tmp_2 = {{5678, 0, 0, 196608}};
  s21_decimal res = {{984, 0, 0, 196608}};
  output = s21_mod(tmp, tmp_2, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res, temp_res));
  ck_assert_int_eq(FALSE, output);
}
END_TEST

START_TEST(from_int_to_decimal_decimal_to_int) {
  int res = 0;
  int temp_plus = 2147483647;
  int temp_minus = -2147483647;
  int output = s21_from_int_to_decimal(temp_plus, &temp_res);
  ck_assert_int_eq(FALSE, output);
  output = s21_from_decimal_to_int(temp_res, &res);
  ck_assert_int_eq(temp_plus, res);
  ck_assert_int_eq(FALSE, output);
  output = s21_from_int_to_decimal(temp_minus, &temp_res);
  ck_assert_int_eq(FALSE, output);
  output = s21_from_decimal_to_int(temp_res, &res);
  ck_assert_int_eq(temp_minus, res);
  ck_assert_int_eq(FALSE, output);
}
END_TEST

START_TEST(from_float_to_decimal_decimal_to_float) {
  float res = 0;
  float temp_plus = 2147483.647;
  float temp_minus = -2147483.647;
  float res_plus = 2147484.;
  float res_minus = -2147484.0;

  int output = s21_from_float_to_decimal(temp_plus, &temp_res);
  ck_assert_int_eq(FALSE, output);
  output = s21_from_decimal_to_float(temp_res, &res);
  ck_assert_float_eq(res_plus, res);
  ck_assert_int_eq(FALSE, output);
  output = s21_from_float_to_decimal(temp_minus, &temp_res);
  ck_assert_int_eq(FALSE, output);
  output = s21_from_decimal_to_float(temp_res, &res);
  ck_assert_float_eq(res_minus, res);
  ck_assert_int_eq(FALSE, output);
  output = s21_from_float_to_decimal((temp_plus * 10), &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_from_float_to_decimal, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_from_decimal_to_float(tmp_float, &res);
  ck_assert_float_eq(21474840.0, res);
  ck_assert_int_eq(FALSE, output);
}
END_TEST

START_TEST(floor_) {
  int output = s21_floor(middle_fractions, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_floor_middle_fractions, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_floor(middle_fractions_minus, &temp_res);
  ck_assert_int_eq(TRUE,
                   s21_is_equal(res_floor_middle_fractions_minus, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_floor(floor_num, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_floor, temp_res));
  ck_assert_int_eq(FALSE, output);
}
END_TEST

START_TEST(round_) {
  int output = s21_round(middle_fractions, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_floor_middle_fractions, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_round(middle_fractions_minus, &temp_res);
  ck_assert_int_eq(TRUE,
                   s21_is_equal(res_round_middle_fractions_minus, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_round(round_num, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_round, temp_res));
  ck_assert_int_eq(FALSE, output);
}
END_TEST

START_TEST(truncate) {
  int output = s21_truncate(middle_fractions, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(res_floor_middle_fractions, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_truncate(middle_fractions_minus, &temp_res);
  ck_assert_int_eq(TRUE,
                   s21_is_equal(res_round_middle_fractions_minus, temp_res));
  ck_assert_int_eq(FALSE, output);
}
END_TEST

START_TEST(negate) {
  int output = s21_negate(max_minus, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(max, temp_res));
  ck_assert_int_eq(FALSE, output);
  output = s21_negate(max, &temp_res);
  ck_assert_int_eq(TRUE, s21_is_equal(max_minus, temp_res));
  ck_assert_int_eq(FALSE, output);
}
END_TEST

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void) {
  Suite *T = suite_create(BLUE "S21_DECIMAL TEST" RESET);
  TCase *TC = tcase_create(GREEN " CHECK ________ " RESET);
  SRunner *SR = srunner_create(T);
  int output;
  suite_add_tcase(T, TC);

  tcase_add_test(TC, add);
  tcase_add_test(TC, sub);
  tcase_add_test(TC, mul);
  tcase_add_test(TC, div);
  tcase_add_test(TC, mod);
  tcase_add_test(TC, floor_);
  tcase_add_test(TC, round_);
  tcase_add_test(TC, negate);
  tcase_add_test(TC, truncate);
  tcase_add_test(TC, is_less);
  tcase_add_test(TC, is_equal);
  tcase_add_test(TC, is_greater);
  tcase_add_test(TC, is_not_equal);
  tcase_add_test(TC, is_less_or_equal);
  tcase_add_test(TC, is_greater_or_equal);
  tcase_add_test(TC, from_int_to_decimal_decimal_to_int);
  tcase_add_test(TC, from_float_to_decimal_decimal_to_float);

  ///////////////

  ///////////

  srunner_run_all(SR, CK_VERBOSE);
  output = srunner_ntests_failed(SR);
  srunner_free(SR);

  return output;
}
