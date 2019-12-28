template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix) {
	string st = {prefix};
	RandomIt it = lower_bound(range_begin, range_end, st);
	++st[0];
	return make_pair (it, upper_bound(it, range_end, st));
}