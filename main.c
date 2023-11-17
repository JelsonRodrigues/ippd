// #include "src/include/fibonacci.h"
#include "src/include/game_of_life.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t main() {

  // uint8_t n = 0;
  // if (scanf("%hhd", &n) == 0) {
  //   printf("ERROR reading n Value\n");
  // }

  // printf("FIBO: %hhd = %ld\n", n, run_parallel_fibonacci(n));


  #define GAME_OF_LIFE_ITERATIONS 4

  #pragma omp parallel 
  {
    #pragma omp single
    {
      for (size_t i = 0; i < GAME_OF_LIFE_ITERATIONS; ++i){
        printf("Iteration %lu\n", i);
        update_state();
        print_state();
      }
    }
  }

  return EXIT_SUCCESS;
}