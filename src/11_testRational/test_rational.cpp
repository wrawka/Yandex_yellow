#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cassert>

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

/*
class Rational {

public:
    Rational() {
        // конструктор по-умолчанию
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        // конструктор
        if (denominator == 0) {
    		throw invalid_argument("Invalid argument");
    	}
        int bcd = BCD(numerator, denominator);
        num = numerator / bcd;
        den = denominator / bcd;
    }

    int Numerator() const {
        // возврат числителя
    	if (num * den < 0 && num > 0) {
    		return -num;
    	} else {
    		return num;
    	}
    }

    int Denominator() const {
        // возврат знаменателя
        return abs(den);
    }

private:
    int BCD(int a, int b) { // наибольший общий делитель по Евклиду
        while (abs(a) > 0 && abs(b) > 0) {
		    if (abs(a) > abs(b)) {
			    a %= b;
		    } else {
			    b %= a;
		    }
	    }
	    return a + b;
    }

    long int num; // мусорный числитель
    long int den; // мусорный знаменатель
};
*/

/*
 * TestDefault():
 * Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1
 */
void TestDefault() {
	Rational rational;
	AssertEqual(rational.Numerator(), 0, "Default numerator is 0");
	AssertEqual(rational.Denominator(), 1, "Default denominator is 1");
}

/*
 * TestCast():
 * При конструировании объекта класса Rational с параметрами p и q
 * должно выполняться сокращение дроби p/q
 */
void TestCast() {
	{
	Rational rational(3,9);
	AssertEqual(rational.Numerator(), 1, "Cast numerator 3/9 is 1");
	AssertEqual(rational.Denominator(), 3, "Cast denominator 3/9 is 3");
	}

	{
	Rational rational(-5,-20);
	AssertEqual(rational.Numerator(), 1, "Cast numerator -5/-20 is 1");
	AssertEqual(rational.Denominator(), 4, "Cast denominator -5/-20 is 4");
	}
}

/*
 * TestNegative():
 * Если дробь p/q отрицательная, то объект Rational(p, q)
 * должен иметь отрицательный числитель и положительный знаменатель.
 *
 * Если дробь p/q положительная, то объект Rational(p, q)
 * должен иметь положительные числитель и знаменатель
 * (обратите внимание на случай Rational(-2, -3))
 */
void TestNegative() {
	{
	Rational rational(4,-9);
	AssertEqual(rational.Numerator(), -4, "Cast numerator 4/-9 is -4");
	AssertEqual(rational.Denominator(), 9, "Cast denominator 4/-9 is 9");
	}

	{
	Rational rational(-3,5);
	AssertEqual(rational.Numerator(), -3, "Cast numerator -3/5 is -3");
	AssertEqual(rational.Denominator(), 5, "Cast denominator -3/5 is 5");
	}
}

/*
 * TestNullNum():
 * Если числитель дроби равен нулю, то знаменатель должен быть равен 1
 */
void TestNullNum() {
	{
	Rational rational(0,9);
	AssertEqual(rational.Numerator(), 0, "Cast numerator 0/9 is 0");
	AssertEqual(rational.Denominator(), 1, "Cast denominator 0/9 is 1");
	}

	{
	Rational rational(0,-9);
	AssertEqual(rational.Numerator(), 0, "Cast numerator 0/-9 is 0");
	AssertEqual(rational.Denominator(), 1, "Cast denominator 0/-9 is 1");
	}


}

int main() {
  TestRunner runner;
  runner.RunTest(TestDefault, "Test default constructor");
  runner.RunTest(TestCast, "Test cast");
  runner.RunTest(TestNegative, "Test negative");
  runner.RunTest(TestNullNum, "Test null numerator");
  return 0;
}
