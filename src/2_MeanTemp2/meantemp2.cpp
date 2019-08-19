#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void printVector(const vector<int32_t>& v) {
	for (auto out : v) {
		cout << out << " ";
	}
    cout << endl;
}

int main () {
	int64_t sum = static_cast<int64_t>(0);
    int32_t n;
	cin >> n;
	vector<int32_t> data(n);
    vector<int32_t> out;

	// filling the raw vector
	for (int32_t& readings : data) {
        cin >> readings;
        sum += readings;
    }

	int32_t mean = sum / n;
	// checking each day against mean temp.
	for (auto i = 0; i < n; i++) {
		if (data[i] > mean) {
			out.push_back(i);
		}
	}

	cout << out.size() << endl;
	printVector(out);
	return 0;
}
