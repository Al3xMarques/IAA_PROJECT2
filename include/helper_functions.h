//
// Created by tim on 11/24/24.
//

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <math.h>

#include "common-defines.h"
#include "data.h"
#include <stdbool.h>


int cents_from_euros(const float euros);
int solution_target_diff(const int* solution, const Data* data);

int num_of_coins_used(const int* solution, const Data* data);
bool is_valid_solution(const int* solution, const Data* data);


#endif //HELPER_FUNCTIONS_H
