#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Person {

public:

	// добавить факт изменения фамилии на first_name в год year
    void ChangeFirstName(int year, const string& first_name) {
    	storage_first[year] = first_name;
    }

    // добавить факт изменения фамилии на last_name в год year
    void ChangeLastName(int year, const string& last_name) {
         storage_last[year] = last_name;
    }

    // получить имя и фамилию по состоянию на конец года year
    string GetFullName(int year) {

        string current_firstname = LastKnownChange(storage_first, year);
        string current_lastname = LastKnownChange(storage_last, year);

        if (current_firstname.empty() && current_lastname.empty()) {
            return "Incognito";
        } else if (current_lastname.empty()) {
            return current_firstname + " with unknown last name";
        } else if (current_firstname.empty()) {
            return current_lastname + " with unknown first name";
        } else {
            return current_firstname + " " + current_lastname;
        }
    }

    // получить все имена и фамилии по состоянию на конец года year
    string GetFullNameWithHistory(int year) {

        string current_firstname = LastKnownChange(storage_first, year);
        string current_lastname = LastKnownChange(storage_last, year);

        if (current_firstname.empty() && current_lastname.empty()) {
            return "Incognito";
        } else if (current_lastname.empty()) {
            return current_firstname + ListOf(storage_first, year) + " with unknown last name";
        } else if (current_firstname.empty()) {
            return current_lastname + ListOf(storage_last, year) + " with unknown first name";
        } else {
            return current_firstname + ListOf(storage_first, year) + " "
            + current_lastname + ListOf(storage_last, year);
        }
    }

    void PrintAll() {
    		cout << "Names history: \n";
    		for (const auto& out : storage_first) {
    			cout << "Year: " << out.first << " name: " + out.second << endl;
    		}
    		cout << ListOf(storage_first, 4000);
    		cout << "Names history: \n";
    		for (const auto& out : storage_last) {
    			cout << "Year: " << out.first << " last name: " + out.second << endl;
    		}
    		cout << ListOf(storage_last, 4000);

    }

private:

    map<int, string> storage_first;   // хранилище под Год : Имя
    map<int, string> storage_last;    // хранилище под Год : Фамилия

    string LastKnownChange(const map<int, string> &source, const int &year) { // последнее изменение к году 'year'
        string output;
    	auto what = source.upper_bound(year);
    	if (what != source.begin()) {
    		what = prev(what);
    	}
    	if ((*what).first <= year) {
    		output = (*what).second;
    	}
        return output;
    }

    string ListOf(const map<int, string> &source, const int &year) {
        string current_value = LastKnownChange(source, year);
        vector<string> old_values = {""};
        old_values.clear();
        string output = "";
        for (pair<int, string> o : source) {
            if (o.first < year && o.second != old_values.front()) {
               old_values.insert(old_values.begin(), o.second);
            }
        }
        if (old_values.front() == current_value) {
        	old_values.erase(old_values.begin());
        }
//      punctuation wrapper below
        if (!old_values.empty()) {
            output = " (";
        }
        for (auto it = old_values.begin(); it != old_values.end(); it++) {
            output += *it;
            if (it == old_values.end() - 1) {
                output += ")";
            } else {
                output += ", ";
            }
        }
        return output;
    }
};