#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

bool operator<(const Region& lhs, const Region& rhs) {
	auto lhs_t = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
	auto rhs_t = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
	return lhs_t < rhs_t;
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	if (regions.empty()) {
		return 0;
	}
	int max = 1;
	map<Region, int> entries;
	for (auto& region : regions) {
		entries[region]++;
	}
	for (auto& entry : entries) {
		if (entry.second > max) {
			max = entry.second;
		}
	}
	return max;
}
