#include <iostream>

using namespace std;

int main() {
	string last_comm = {};
	string equasion;
	cin >> equasion;
	int n;
	cin >> n;
	string parenthesis = {};
	while (n--) {
		string next_comm;
		string next_val;
		cin >> next_comm >> next_val;
		if ((next_comm == "*" || next_comm == "/")
				&& (last_comm == "+" || last_comm == "-")) {
			equasion += ')';
			parenthesis += '(';
		}
		equasion += " " + next_comm + " " + next_val;
		last_comm = next_comm;
	}
	cout << parenthesis << equasion << endl;
	return 0;
}