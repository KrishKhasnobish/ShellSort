#include <assert.h>
#include <stdio.h>
#include "shell-sort.h"
#include "cs136-trace.h"

// === HELPER FUNCTIONS =======================================================

// array_print(arr, len) outputs the content of the array arr.
// requires: len must be positive
// effects:  produces output
// time:     O(n)
static void array_print(const int *arr, int len) {
  assert(arr);
  assert(len > 0);
  printf("[%d", *arr);
  for (const int *p = arr + 1; p < arr + len; ++p) {
    printf(", %d", *p);
  }
  printf("]\n");
}

// === MODULE FUNCTIONS =======================================================

// shell_sort(arr, len) sorts the array arr in ascending order.
// requires: len must be positive
// effects:  mutates arr[]
// time:     O(n^2)
void shell_sort(int arr[], int len) {
  assert(arr);
  assert(len > 0);
  array_print(arr, len);
  int n = ((len / 4) * 2) + 1;
  while (n >= 1) {
    for (int j = 0; (j + n) <= len - 1; j++) {
      if (arr[j + n] < arr[j]) {
        int temp = arr[j];
        arr[j] = arr[j + n];
        arr[j + n] = temp;
        for (int k = j; k - n >= 0; k -= n) {
          if (arr[k] >= arr[k - n]) {
            break;
          } else {
            int temp2 = arr[k - n];
            arr[k - n] = arr[k];
            arr[k] = temp2;
          }
        }
      }
    }
    array_print(arr, len);
    if (n == 1) {
      break;
    } else {
    n = ((n / 4) * 2) + 1;
    }
  }
}
