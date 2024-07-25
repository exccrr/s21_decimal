#ifndef SRC_S21_STRUCTURES_H_
#define SRC_S21_STRUCTURES_H_

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define S21_INFINITY 1.0 / 0.0
#define MAX 79228162514264337593543950335.0F
#define MIN -79228162514264337593543950335.0F

typedef unsigned int uint;

typedef struct {
  uint bits[4];
} s21_decimal;

typedef struct {
  uint bits[7];
} s21_decimal_long;

#endif  // SRC_S21_STRUCTURES_H_
