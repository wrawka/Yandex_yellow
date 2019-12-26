template <typename RandomIt>
	void MergeSort(RandomIt range_begin, RandomIt range_end) {
	size_t range = range_end - range_begin;
	if (range < 2) {
		return;//	Если диапазон содержит меньше 2 элементов, выйти из функции
	}

//	Создать вектор, содержащий все элементы текущего диапазона
	vector<typename RandomIt::value_type> v(range_begin, range_end);

//	Разбить вектор на три равные части
//	Вызвать функцию MergeSort от каждой части вектора
	range /= 3;

	auto one3rd = begin(v) + range;
	auto two3rd = begin(v) + (range * 2);

	MergeSort(begin(v), one3rd);
	MergeSort(one3rd, two3rd);
	MergeSort(two3rd, end(v));

//	Слить первые две трети вектора с помощью алгоритма merge,
//	сохранив результат во временный вектор с помощью back_inserter
	vector<typename RandomIt::value_type> v_temp;
	merge(begin(v), one3rd, one3rd, two3rd, back_inserter(v_temp));

//	Слить временный вектор из предыдущего пункта с последней третью вектора из п. 2,
//	записав полученный отсортированный диапазон вместо исходного.
	merge(begin(v_temp), end(v_temp), two3rd, end(v), range_begin);
}