#include "./include/fibonacci.h"

int64_t fibonacci(uint8_t n) {
  int64_t a, b;
  if (n < 2) return n;
  
  #pragma omp task shared(a, n)
  {
    a = fibonacci(n-2);
  }

  #pragma omp task shared(b, n)
  {
    b = fibonacci(n-1);
  }

  #pragma omp taskwait
  return a + b;
}

int64_t run_parallel_fibonacci(uint8_t n){
  int64_t result = 0;
  #pragma omp parallel shared(result, n)
  {
    #pragma omp single
    {
      result = fibonacci(n);
    }
  }

  return result;
}