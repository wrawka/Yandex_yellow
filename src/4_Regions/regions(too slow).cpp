#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

bool operator==(const Region& lhs, const Region& rhs) {
	auto lhs_t = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
	auto rhs_t = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
	return lhs_t == rhs_t;
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	int max = (!regions.empty());
	auto start = regions.begin();
	for (auto& region : regions) {
		int entries = count (start, regions.end(), region);
		if (max < entries) {
			max = entries;
		}
		start++;
	}
	return max;
}