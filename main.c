#include "src/include/fibonacci.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t main() {

  uint8_t n = 0;
  if (scanf("%hhd", &n) == 0) {
    printf("ERROR reading n Value\n");
  }

  int64_t result = 0;
  #pragma omp parallel shared(result, n)
  {
    #pragma omp single
    {
      result = fibonacci(n);
    }
  }

  printf("FIBO: %hhd = %ld\n", n, result);
  return EXIT_SUCCESS;
}