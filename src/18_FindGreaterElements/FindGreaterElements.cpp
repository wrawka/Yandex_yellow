#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#include "FindGreaterElements.h"

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> out;
    auto border_it = find_if(begin(elements), end(elements), [border](T element) {return element > border;});
    for (auto it = border_it; it != end(elements); it++) {
        out.push_back(*it);
    }
    return out;
}