
#include "phone_number.h"
#include <stdexcept>
#include <sstream>


PhoneNumber::PhoneNumber(const string &international_number) {
	stringstream s;
	s << international_number;
	if (s.get() != '+') {
		throw invalid_argument("Number should start with a plus sign");
	}
	getline(s, country_code_,  '-');
	getline(s, city_code_,  '-');
	getline(s, local_number_);
	if (country_code_.size() == 0 || city_code_.size() == 0 || local_number_.size() == 0) {
		throw invalid_argument("Part of the number is missing");
	}
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ +	"-" + local_number_;
}

