#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main () {
	uint64_t vol = 0;
    int n; // block qty
    int r; // material density
	cin >> n >> r;

	while (n--) { // calculating total volume
		int w, h, d;
		cin >> w >> h >> d;
		// should/could have been an overflow in grader, but still passed
		// expected solution is make a static_cast<int64_t> (w * h * d)
		vol += w * h * d; 
	}
	// printing full mass
	cout << vol * r << endl;
	return 0;
}
