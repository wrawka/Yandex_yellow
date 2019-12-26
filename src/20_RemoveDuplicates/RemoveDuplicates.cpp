#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
//	int i = 0;
	auto it = begin(elements);
	while (it != end(elements)) {
//		cout << "Item " << i++ << ": " << *it;
		if (count(begin(elements), end(elements), *it) > 1) {
			elements.erase(it);
//			cout << " is removed";
		} else {
			it++;
		}
//		cout << endl;
	}
}