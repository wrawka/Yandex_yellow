#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& str) {
	for (size_t i = 0; i <= str.size() / 2; i++) {
			if (str[i] != str[str.size() - i - 1]) {
				return false;
			}
		}
	return true;
}

void TestPalindrom() {
	//Test true
	Assert(IsPalindrom("madam"), "madam is polindrom");
	Assert(IsPalindrom("assa"), "assa is polindrom");
	Assert(IsPalindrom("As0sA"), "As0sA is polindrom");
	Assert(IsPalindrom("a"), "a is polindrom");
	Assert(IsPalindrom(""), "empty string is polindrom");

	//Test false
	Assert(!IsPalindrom("mastam"), "mastam isn't polindrom");
	Assert(!IsPalindrom("Mom"), "Mom isn't polindrom");
	Assert(!IsPalindrom("assa "), "'assa ' isn't polindrom");
	Assert(!IsPalindrom("assat"), "'assat' isn't polindrom");
	Assert(!IsPalindrom("0assa"), "'0assa' isn't polindrom");
	Assert(!IsPalindrom("0assa1"), "'0assa1' isn't polindrom");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestPalindrom, "Test for palindrom");
  return 0;
}
