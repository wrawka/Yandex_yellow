template <typename T>
void VectorPrint(vector<T> v) {
	auto delim = " "; // set delimeter here
	cout << "Vector contains: ";
	for (T out : v) {
		if (out != v.at(0)) {
			cout << delim;
		}
		 cout << out;
	}
	cout << endl;
}