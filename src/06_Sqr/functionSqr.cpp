#include <iostream>
#include <vector>
#include <map>

using namespace std;

// declaration
template <typename T> T Sqr(const T &x);
template <typename T> vector<T> Sqr(const vector<T> &v);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second> &p);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value> &m);

// definition
template <typename T> T Sqr(const T &x) {
	return x * x;
}
template <typename T> vector<T> Sqr(const vector<T> &v) {
	vector<T> out;
	for (auto e : v) {
		out.push_back(Sqr(e));
	}
	return out;
}

template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second> &p) {
	pair<First, Second> out;
	out = {Sqr(p.first), Sqr(p.second)};
	return out;
}

template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value> &m) {
	map<Key, Value> out;
	for (auto e : m) {
		out[e.first] = Sqr(e.second);
	}
	return out;
}