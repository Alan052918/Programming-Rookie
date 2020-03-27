#include "equilibrium.h"

int TrivialEquilibrium(int arr[], int n) {
  int left_sum, right_sum;
  for (int i = 0; i < n; ++i) {
    left_sum = 0;
    for (int j = 0; j < i; ++j) left_sum += arr[j];
    right_sum = 0;
    for (int j = i + 1; j < n; ++j) right_sum += arr[j];
    if (left_sum == right_sum) return i;
  }
  return -1;
}

int AdvancedEquilibrium(int arr[], int n) {
  int left_sum = 0;
  int right_sum = 0;
  for (int i = 0; i < n; ++i) right_sum += arr[i];
  for (int i = 0; i < n; ++i) {
    right_sum -= arr[i];
    if (left_sum == right_sum) return i;
    left_sum += arr[i];
  }
  return -1;
}
