#include <stddef.h>
#include <stdio.h>

#include "equilibrium.h"

void PrintArray(int arr[], size_t n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
}

int main() {
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	size_t arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Trivial  | equilibrium index: %d\n", TrivialEquilibrium(arr, arr_size));
	printf("Advanced | equilibrium index: %d\n", AdvancedEquilibrium(arr, arr_size));

	getchar();
}
