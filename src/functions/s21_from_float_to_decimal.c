#include <stdbool.h>

#include "../additional_functions/s21_add_functions.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int output = 1;
  int scale = 0;
  int bit_depth = 0;

  memset(dst->bits, 0, sizeof(dst->bits));
  if (!isinf(src) && !isinf(-src) && (src <= MAX && src >= MIN) &&
      dst != NULL) {
    float tmp_src = src;

    if (tmp_src < 0) tmp_src /= -1;
    while (tmp_src > (int)tmp_src) {
      tmp_src *= 10;
      scale += 1;
    }
    int tmp_int = (int)tmp_src;
    for (; tmp_int; bit_depth++) tmp_int >>= 1;
    while (bit_depth > 23 && scale) {
      scale -= 1;
      bit_depth = 0;
      int temp = (int)tmp_src;
      int mod = temp % 10;
      tmp_src = tmp_src / 10;
      tmp_int = tmp_src;
      for (; tmp_int; bit_depth++) tmp_int >>= 1;
      if (mod >= 5 && bit_depth <= 23) tmp_src += 1;
    }
    if (bit_depth <= 23) {
      dst->bits[0] = (int)tmp_src;
      s21_set_the_scale(dst, scale);
      if (src < 0) s21_set_bit_true(dst, 127);
    } else {
      s21_parse_dec(tmp_src, src, dst);
    }
    output = 0;
  }

  return output;
}

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {
//   int return_val = 0;
//   // s21_decl_to_null(dst);
//   memset(dst->bits, 0, sizeof(dst->bits));
//   if (fabs(src) < powl(10.0, -1 * 28)) {
//     return_val = 1;
//     // dst->state = S21_NULL;
//   } else if (src >= powl(2.0, 96)) {
//     return_val = 1;
//     // dst->state = S21_PLUS_INF;
//   } else if (src <= powl(2.0, 96) * (-1)) {
//     return_val = 1;
//     // dst->state = S21_MINUS_INF;
//   } else {
//     // s21_decl_to_null(dst);
//     memset(dst->bits, 0, sizeof(dst->bits));
//     int scale = 0;
//     if (src < 0.0)
//       // s21_set_sign(dst, 1);
//       s21_set_bit_true(dst, 127);
//     src = fabsl(src);
//     for(; !(int)src && scale < 28; src *=10)  // normalize
//         scale++;
//     int i = 0;
//     for (; src < powl(2.0, 96) && scale < 28 && i < 7; i++) {
//       src *= (long double)10.0;
//       scale++;
//     }
//     for (i = 0; src >= powl(10.0, -1 * (7 + 1)) && i < 96; i++) {
//       src = floorl(src) / 2;
//       if (src - floorl(src) > powl(10.0, -1 * (7 + 1))) {
//         s21_set_bit_true(dst, i);
//       }
//     }
//     s21_set_the_scale(dst, scale);
//     // dst->state = S21_NORMAL;
//   }
//   return return_val;
// }

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {
//   int codeError = 0;
//   if (!isinf(src) && isnan(src)) {
//     codeError = 1;
//   } else if (dst) {
//     int sign = 0;
//     if (src < 0) {
//       src = -src;
//       sign = 1;
//     }
//     long int new = (long int)src;
//     long int mantiss = 0;
//     while (src - ((float)new / (long int)(pow(10, mantiss))) != 0) {
//       mantiss++;
//       new = src *(long int)(pow(10, mantiss));
//     }
//     // s21_decimal_init(dst);
//     memset(dst->bits, 0, sizeof(dst->bits));
//     bool temp[96] = {0};
//     int m = 0;
//     // printf("%ld\n", new);
//     while (new >= 1) {
//       if (new % 2 == 1) {
//         temp[m] = 1;
//       }
//       m++;
//       new /= 2;
//     }
//     int k = 95;
//     for (int i = 2; i >= 0; i--) {
//       for (int j = 31; j >= 0; j--) {
//         dst->bits[i] = (dst->bits[i] << 1) + temp[k--];
//       }
//     }

//     if (sign) {
//       dst->bits[3] |= (1 << 31);
//     }
//     dst->bits[3] += mantiss << 16;
//   } else {
//     codeError = 1;
//   }
//   return codeError;
// }
