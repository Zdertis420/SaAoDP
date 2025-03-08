#include "utilities.hpp"
#include <cstdlib>
#include <ctime>
#include <random>
#include <stdio.h>
#include <vector>

void fillarr_random(std::vector<char> &x, int &n) {
  x.resize(n);

  static std::mt19937 generator(std::time(0));
  std::uniform_int_distribution<char> distribution('a', 'z');

  for (int i = 0; i < n; ++i) {
    x[i] = distribution(generator);
  }
}

void fillarr_random(std::vector<int> &x, int &n) {
  x.resize(n);

  srand(time(0));

  for (int i = 0; i < n; ++i) {
    x[i] = rand() % 100;
  }
}

void fillarr_static(std::vector<char> &x, int &n, char key) {
  x.resize(n);

  for (int i = 0; i < n; ++i) {
    x[i] = key;
  }
}

void fillarr_static(std::vector<int> &x, int &n, int key) {
  x.resize(n);

  for (int i = 0; i < n; ++i) {
    x[i] = key;
  }
}

void fillarr_asc(std::vector<int> &x, int &n) {
  x.resize(n);

  for (int i = 0; i < n; ++i) {
    x[i] = i;
  }
}

void fillarr_desc(std::vector<int> &x, int n) {
  x.resize(n);
  for (int i = 0; i < n; ++i) {
    x[i] = n - i - 1;
  }
}

void prarr(std::vector<char> &x) {
  for (char c : x) {
    printf("%c\n", c);
  }
}

void prarr(std::vector<int> &x) {
  for (int n : x) {
    printf("%d ", n);
  }
  printf("\n");
}

void prstats(Stats stats) {
  printf("Stats\n---------------------\n");
  printf("Time: %u\n", stats.time);
  printf("Comps: %u\n", stats.comps);
  printf("Movs: %u\n", stats.movs);
  printf("Total: %u\n", stats.movs + stats.comps);
}
