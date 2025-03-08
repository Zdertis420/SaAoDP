#include "utilities.hpp"
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <vector>

Stats delFirstMetod(std::vector<char> &x, int &n, int key) {
  Stats stats = {0, 0, 0};
  auto start = std::chrono::high_resolution_clock::now();

  int i = 0;
  while (i < n) {
    stats.comps++;
    if (x[i] == key) {
      stats.comps++;
      for (int j = i; j < n - 1; ++j) {
        stats.comps++;
        x[j] = x[j + 1];
        stats.movs++;
      }
      n--;
    } else {
      i++;
    }
  }

  auto stop = std::chrono::high_resolution_clock::now();
  stats.time =
      std::chrono::duration_cast<std::chrono::milliseconds>(stop - start)
          .count();

  return stats;
}

Stats delOtherMetod(std::vector<char> &x, int &n, int key) {
  Stats stats = {0, 0, 0};
  auto start = std::chrono::high_resolution_clock::now();

  int j = 0;
  for (int i = 0; i < n; ++i) {
    stats.comps++;
    x[j] = x[i];
    stats.movs++;
    if (x[i] != key) {
      stats.comps++;
      j++;
    }
  }

  if (n > 0 && x[0] == key) {
    stats.comps++;
    n = 0;
  } else {
    n = j;
  }
  auto stop = std::chrono::high_resolution_clock::now();

  stats.time =
      std::chrono::duration_cast<std::chrono::milliseconds>(stop - start)
          .count();

  return stats;
}

int main() {
  std::vector<char> arr1;
  int n;

  scanf("%d", &n);

  fillarr_static(arr1, n, 'b');

  std::vector<char> arr2(arr1);

  int n1 = arr1.size();
  int key1 = 'b';

  Stats stats1 = delFirstMetod(arr1, n1, key1);
  Stats stats2 = delOtherMetod(arr2, n1, key1);

  prstats(stats1);

  printf("\n\n");

  prstats(stats2);

  return 0;
}
