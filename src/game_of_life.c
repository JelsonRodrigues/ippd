#include "./include/game_of_life.h"

uint8_t terrain[ROWS][COLUMNS];
bool initialized_buffer = false;

int32_t min(int32_t a, int32_t b) { 
  return a < b ? a : b;
}

int32_t max(int32_t a, int32_t b) { 
  return a > b ? a : b;
}

void initialize_state() {
  srand(time(NULL));

  #pragma omp parallel for collapse(2)
  for (size_t i = 0; i < ROWS; ++i) {
    for (size_t j = 0; j < COLUMNS; ++j) {
      terrain[i][j] = rand() % 2;
    }
  }
}

void update_state(){
  if (!initialized_buffer) {
    initialize_state();
    initialized_buffer = true;
  }

  #pragma omp parallel for collapse(2)
  for (uint32_t i = 0; i < ROWS; ++i) {
    for (uint32_t j = 0; j < COLUMNS; ++j) {
      uint32_t sum = 0;

      for (uint32_t k = max(0, i-1); k < (uint32_t) min(ROWS, i + 2); ++k) {
        for (uint32_t l = max(0, j-1); l < (uint32_t) min(ROWS, j + 2); ++l) {
          sum += terrain[k][l];
        }  
      }
      
      terrain[i][j] = sum == 2 || 
                      sum == 3 ||
                      sum == 4;
      
    }
  }

}
void print_state() {
  for (uint32_t i = 0; i < ROWS; ++i) {
    for (uint32_t j = 0; j < COLUMNS; ++j) {
      printf("%1d ", terrain[i][j]);
    }
    printf("\n");
  }
}