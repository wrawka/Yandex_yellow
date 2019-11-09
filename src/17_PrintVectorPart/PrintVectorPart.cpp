//#include "PrintVectorPart.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	// auto out = find_if(numbers.begin(), numbers.end(), [](const int& num) {return num < 0;});
	// //cout << *--out;
	// for (auto it = out; it > numbers.begin(); it--) {
	// 	cout << " " << *it;
	// }
	vector<int> out;
	for (auto num : numbers) {
		if (num >= 0) {
			out.push_back(num);
		} else {
			break;
		}
	}
	reverse(begin(out), end(out));
	for (auto o : out) {
		// if (o != out.at(0)) {
		// 	cout << " ";
		// }
		cout << o << " ";
	}
}
