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

int RootsByD(double a, double b, double c) {
	int d = b * b - 4 * a * c;
	    if (d > 0) {
	        return 2;
	    } else if (d == 0) {
	        return 1;
	    }
	    return 0;
}

int GetDistinctRealRootCount(double a, double b, double c) {
    if (a == 0) {
    	if (b == 0) {
    		// (a == 0, b == 0, c != 0) => n == 1, x == 0
    		return 0;
    	} else {
    		// (a == 0, b != 0, c) => n == 1, x == 0 | x == -c/b
    		return 1;
    	}
    } else if (b == 0) {
    	if (c == 0) {
    		// (a != 0, b == 0, c == 0) => n == 1, x == 0
    		return 1;
    	} else if (c > 0){
    		// (a != 0, b == 0, c != 0) => n == 2, x^2 == sqrt(-c/a)
    		return 0;
    	} else {
    		return 2;
    	}
    } else if (c == 0) {
    	// (a != 0, b != 0, c == 0) => n == 2, D > 0
    	return 2;
    }
    // (a != 0, b != 0, c != 0) => D == ?
    return RootsByD(a, b, c);
}

void ZeroCases() {
    Assert(GetDistinctRealRootCount(0, 0, 3) == 0, "a = 0, b = 0, c != 0");
    Assert(GetDistinctRealRootCount(0, 5, 3) == 1, "a = 0, b != 0, c != 0");
    Assert(GetDistinctRealRootCount(0, 5, 0) == 1, "a = 0, b != 0, c = 0");
    Assert(GetDistinctRealRootCount(7, 0, 3) == 0, "a != 0, b = 0, c > 0");
    Assert(GetDistinctRealRootCount(7, 0, -3) == 2, "a != 0, b = 0, c < 0");
    Assert(GetDistinctRealRootCount(7, 0, 0) == 1, "a != 0, b = 0, c = 0");
    Assert(GetDistinctRealRootCount(7, 5, 0) == 2, "a != 0, b != 0, c = 0");
}

void DCases() {
    Assert(GetDistinctRealRootCount(7, 5, 3) == 0, "D < 0");
    Assert(GetDistinctRealRootCount(1, 4, 4) == 1, "D = 0");
    Assert(GetDistinctRealRootCount(1, 5, 3) == 2, "D > 0");
}


int main() {
    TestRunner runner;
    runner.RunTest(ZeroCases, "Test for zeros for arguments");
    runner.RunTest(DCases, "Test for non-zeros for arguments");
    return 0;
}
