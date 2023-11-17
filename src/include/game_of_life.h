#pragma once
#include <omp.h>
#include "stdio.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 32
#define COLUMNS 32

void update_state();
void print_state();
