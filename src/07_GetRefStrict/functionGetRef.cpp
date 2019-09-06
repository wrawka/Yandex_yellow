#include <iostream>
#include <vector>
#include <map>
#include <exception>

using namespace std;

// definition
template <typename K, typename V> V& GetRefStrict(map<K, V> &m, const K& k) {
	if (m.count(k)) {
		return m.at(k);
	} else {
		throw runtime_error("Element don't exist");
	}
}