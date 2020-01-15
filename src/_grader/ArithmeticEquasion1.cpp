#include <iostream>

using namespace std;

int main() {
	string equasion;
	cin >> equasion;
	int n;
	cin >> n;
	const string parenthesis(n, '(');
	while (n--) {
		equasion += ')';
		string next_comm;
		string next_val;
		cin >> next_comm >> next_val;
		equasion += " " + next_comm + " " + next_val;
	}
	cout << parenthesis << equasion << endl;
	return 0;
}