template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
	string st = prefix;
	RandomIt it = lower_bound(range_begin, range_end, st);
	if (it == range_end) {
		return {it, it};
	}
	++(*prev(st.end()));
	return make_pair(it, lower_bound(it, range_end, st));
}