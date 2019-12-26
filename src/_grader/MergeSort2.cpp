template <typename RandomIt>
	void MergeSort(RandomIt range_begin, RandomIt range_end) {
	auto range = range_end - range_begin;
	if (range < 2) {
		return;//	Если диапазон содержит меньше 2 элементов, выйти из функции
	}

//	Создать вектор, содержащий все элементы текущего диапазона.
	vector<typename RandomIt::value_type> v(range_begin, range_end);

//	Разбить вектор на две равные части
//	Вызвать функцию MergeSort от каждой половины вектора
	range /= 2;
	MergeSort(begin(v), begin(v) + range);
	MergeSort(begin(v) + range, end(v));
	
//	С помощью алгоритма merge слить отсортированные половины, 
//	записав полученный отсортированный диапазон вместо исходного	
	merge(begin(v), begin(v) + range, begin(v) + range, end(v), range_begin);

}