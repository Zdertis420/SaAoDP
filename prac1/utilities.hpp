#include <vector>


void fillarr_random(std::vector<char>& x, int& n);

void fillarr_random(std::vector<int>& x, int& n);

void fillarr_static(std::vector<char>& x, int& n, char key);

void fillarr_static(std::vector<int>& x, int& n, char key);

void fillarr_asc(std::vector<int>& x, int& n);

void fillarr_desc(std::vector<int> &x, int n);

void prarr(std::vector<char>& x);

void prarr(std::vector<int>& x);

struct Stats {
	unsigned long long comps;
	unsigned long long movs;
	unsigned long long time;
};

void prstats(Stats stats);
