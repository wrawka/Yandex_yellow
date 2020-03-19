/*
 * Date.cpp
 *
 *  Created on: 13 февр. 2020 г.
 *      Author: A.Lebedev
 */
#include "date.h"
#include <iomanip>
#include <stdexcept>

using namespace std;

// конструктор выбрасывает исключение, если его аргументы некорректны
Date::Date(int new_year = 1970, int new_month = 1, int new_day = 1) {
//год может быть любым
  year = new_year;

//проверка значения месяца
  if (new_month > 12 || new_month < 1) {
    throw logic_error("Month value is invalid: " + to_string(new_month));
  }
  month = new_month;

//проверка значения дня
  if (new_day > 31 || new_day < 1) {
    throw logic_error("Day value is invalid: " + to_string(new_day));
  }
  day = new_day;
}

int Date::GetYear() const 	{ return year; }
int Date::GetMonth() const 	{ return month; }
int Date::GetDay() const 	{ return day; }


ostream& operator<< (ostream& out, const Date& date) {
	  out << setw(4) << setfill('0') << date.year << "-" <<
			 setw(2) << setfill('0') << date.month << "-" <<
			 setw(2) << setfill('0') << date.day;
	  return out;
}

Date ParseDate(const string& date) {
  istringstream date_stream(date);
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);
  ok = ok && date_stream.eof();

  if (!ok) {
    throw logic_error("Wrong date format: " + date);
  }
  return Date(year, month, day);
}
