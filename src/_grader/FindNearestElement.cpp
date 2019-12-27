set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
	auto check = numbers.lower_bound(border);
	if (numbers.empty()) {
		return check;
	}

	int right = abs(*check - border);
	int left = abs(border - *prev(check));

	if (right >= left || check == numbers.end()) {
		return prev(check);
	} else {
		return check;
	}
}
