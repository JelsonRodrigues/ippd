#include "include/teste.h"

void parallel_print(){
  int32_t i;
  #pragma omp parallel private(i)
  {
    #pragma omp for schedule(static,4)
    for(i=0; i<10; ++i) {
      int32_t thread_num = omp_get_thread_num();
      printf("%d, thread_num:%d\n", i, thread_num);
    }
  }
}