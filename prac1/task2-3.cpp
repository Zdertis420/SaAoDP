#include "utilities.hpp"
#include <chrono>
#include <csignal>
#include <stdio.h>
#include <utility>
#include <vector>

Stats selection_sort(std::vector<int> &arr, int n, bool asc = true) {
  Stats stats = {0, 0, 0};

  if (asc) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i) {
      stats.comps++;

      int min_index = i;

      for (int j = i + 1; j < n; ++j) {
        stats.comps++;
        if (arr[j] < arr[min_index]) {
          stats.comps++;
          min_index = j;
        }
      }

      std::swap(arr[i], arr[min_index]);
      stats.movs++;
    }

    auto stop = std::chrono::high_resolution_clock::now();

    stats.time =
        std::chrono::duration_cast<std::chrono::milliseconds>(stop - start)
            .count();
  } else {
	 auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i) {
      stats.comps++;

      int max_index = i;

      for (int j = i + 1; j < n; ++j) {
        stats.comps++;
        if (arr[j] > arr[max_index]) {
          stats.comps++;
          max_index = j;
        }
      }

      std::swap(arr[i], arr[max_index]);
      stats.movs++;
    }

    auto stop = std::chrono::high_resolution_clock::now();

    stats.time =
        std::chrono::duration_cast<std::chrono::milliseconds>(stop - start)
            .count();

  }



  return stats;
}

int main() {
  std::vector<int> arr;
  int n;

  scanf("%d", &n);

  fillarr_asc(arr, n);

  printf("Unsorted array:\n");
  prarr(arr);
  printf("\n\n");

  Stats stats = selection_sort(arr, n);

  printf("Sorted array:\n");
  prarr(arr);
  printf("\n\n");

  prstats(stats);

  return 0;
}
