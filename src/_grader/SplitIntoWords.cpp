#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> out;
    auto it = begin(s);
    while (it != end(s)) {
        auto space = find(it, end(s), ' ');
        out.push_back({it, space});
        if (space != end(s)) {
            it = space + 1;
        } else {
            it = space;
        }
    }
    return out;
}