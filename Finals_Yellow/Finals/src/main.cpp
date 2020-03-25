#include "database.h"
#include "date.h"
#include "node.h"
#include "condition_parser.h"
#include "test_runner.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

string ParseEvent(istream& is) {
  //TODO: Реализуйте эту функцию
	string output;
	while (is) {
		string temp;
		is >> temp;
		output += temp;

	}
	return output;
}

void TestAll();

/*
 * test main() starts here
 */
//int main() {
//
//	return 0;
//}
/*
 * test main() ends here
 */

int main() {
  TestAll();

  Database db;

  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "Add") {
      const auto date = ParseDate(is);
      const auto event = ParseEvent(is);
      db.Add(date, event);
    } else if (command == "Print") {
      db.Print(cout);
    } else if (command == "Del") {
      auto condition = ParseCondition(is);
      auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
      };
      int count = db.RemoveIf(predicate);
      cout << "Removed " << count << " entries" << endl;
    } else if (command == "Find") {
      auto condition = ParseCondition(is);
      auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
      };

      const auto entries = db.FindIf(predicate);
      for (const auto& entry : entries) {
        cout << entry << endl;
      }
      cout << "Found " << entries.size() << " entries" << endl;
    } else if (command == "Last") {
      try {
          cout << db.Last(ParseDate(is)) << endl;
      } catch (invalid_argument&) {
          cout << "No entries" << endl;
      }
    } else if (command.empty()) {
      continue;
    } else {
      throw logic_error("Unknown command: " + command);
    }
  }

  return 0;
}

//void TestDate() {
//	{
//		istringstream is("2000-12-13");
//		Date d(2000, 12, 13);
//		Date a = ParseDate(is);
//		bool b = a == d;
//		string s = "";
//		Assert(ParseDate(is) == d, "Some error text");
//
//	}
//}

//void TestParseEvent() {
//  {
//    istringstream is("event");
//    AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
//  }
//  {
//    istringstream is("   sport event ");
//    AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
//  }
//  {
//    istringstream is("  first event  \n  second event");
//    vector<string> events;
//    events.push_back(ParseEvent(is));
//    events.push_back(ParseEvent(is));
//    AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
//  }
//}

//void TestAll() {
//  TestRunner tr;
//  tr.RunTest(TestDate, "TestDate");
//  tr.RunTest(TestParseEvent, "TestParseEvent");
//  tr.RunTest(TestParseCondition, "TestParseCondition");
//}
