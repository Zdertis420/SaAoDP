#include "utilities.hpp"
#include <chrono>
#include <stdio.h>
#include <vector>

Stats bubble_sort(std::vector<int> &x, int &n, bool asc = true) {
  Stats stats = {0, 0, 0};

  if (asc) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i) {
      stats.comps++;
      for (int j = 0; j < n - i - 1; ++j) {
        stats.comps++;
        if (x[j] > x[j + 1]) {
          stats.comps++;
          int temp = x[j];
          x[j] = x[j + 1];
          x[j + 1] = temp;
          stats.movs++;
          stats.movs++;
        }
      }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    stats.time =
        std::chrono::duration_cast<std::chrono::milliseconds>(stop - start)
            .count();
  } else {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i) {
      stats.comps++;
      for (int j = 0; j < n - i - 1; ++j) {
        stats.comps++;
        if (x[j] < x[j + 1]) {
          stats.comps++;
          int temp = x[j];
          x[j] = x[j + 1];
          x[j + 1] = temp;
          stats.movs++;
          stats.movs++;
        }
      }
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

	fillarr_random(arr, n);

	printf("Unsorted array:\n");
	prarr(arr);

	printf("\n\n");

	Stats stats = bubble_sort(arr, n);

	printf("Sorted array:\n");
	prarr(arr);

	printf("\n\n");

	prstats(stats);

	return 0; 
}
