//
// Created by tim on 11/27/24.
//

#include <string.h>
#include <stdlib.h>
#include "alrogithm.h"

int evaluate_solution(int* sol, const int* coinValues, int nCoinTypes, int target) {
	// Penalize invalid solutions
	// TODO try doing repair instead if we have time
	if (!is_valid_solution(sol, coinValues, nCoinTypes, target)) return -1;
	return num_of_coins_used(sol, nCoinTypes);
}
void generate_neighbor(int* sol, int* newSol, int solSize) {
	memcpy(newSol, sol, solSize * sizeof(int));
	// TODO
}

int hill_climbing(int* sol, Data data, int nIter) {
	int* newSol = malloc(data.coin_types_n * sizeof(int));
	if (newSol == NULL) return -1;

	int cost = evaluate_solution(sol, data.coin_values_in_cents, data.coin_types_n, data.target_sum_in_cents);

	for (int i = 0; i < nIter; i++) {
		generate_neighbor(sol, newSol, data.coin_types_n);

		int costNeighbor = evaluate_solution(newSol, data.coin_values_in_cents, data.coin_types_n, data.target_sum_in_cents);
		if (costNeighbor <= cost) {
			cost = costNeighbor;
			memcpy(sol, newSol, data.coin_types_n * sizeof(int));
		}
	}

	free(newSol);
	return cost;
}