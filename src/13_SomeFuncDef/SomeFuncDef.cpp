#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
	return x + y;
}

string Reverse(string s) {
	auto first = s.begin();
	auto last = s.end();
	while ((first!=last)&&(first!=--last)) {
	    iter_swap (first,last);
	    ++first;
	}
	return s;	  
}

void Sort(vector<int>& nums) {
	sort (nums.begin(), nums.end());
}