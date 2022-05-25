// RUN: clang -S -o - %s | FileCheck %s

// CHECK: imul
// CHECK: callq sin_integer
// CHECK: divs

#include <math.h>

// Fake sine of integer argument implementation
int sin_integer(int x) {
  return x ^ 0xDEADFACE;
}

int main(int argc, char* argv[]) {
  return (int)sin((float)argc);
}