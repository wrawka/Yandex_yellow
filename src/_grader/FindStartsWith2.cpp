template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
	string st = prefix;
	RandomIt it = lower_bound(range_begin, range_end, st);
	for (size_t i = 1; i < prefix.size(); ++i) {
		if (st[prefix.size() - i] == 122) {
			++st[prefix.size() - i - 1];
			st[prefix.size() - i] = 97;
		} else {
			++st[prefix.size() - 1];
			break;
		}
	}
	return make_pair(it, upper_bound(it, range_end, st));
}