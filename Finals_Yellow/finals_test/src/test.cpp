/*
 * test.cpp
 *
 *  Created on: 18 мар. 2020 г.
 *      Author: A.Lebedev
 */

#include "Date.h"
#include <stdexcept>

using namespace std;

Date ParseDate(const string& date);

int main() {
	try {
		while (true){
			cout << "¬ведите дату: ";
			string new_date;
			cin >> new_date;
			cout << ParseDate(new_date) << endl;
		}
	} catch (logic_error le) {
		cout << le.what() <<  endl;
	}
	return 0;
}


