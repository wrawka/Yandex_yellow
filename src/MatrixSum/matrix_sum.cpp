#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
class Matrix {
public:
    Matrix() {
        num_rows = 0;
        num_cols = 0;
    }
    Matrix(int r, int c) {
        Reset(r, c);
    }
    /* void CheckRange(const int& r, const int& c) const {
        if (r >= num_rows || c >= num_cols || c < 0 || r < 0) {
            throw out_of_range("Looking over the fence");
        }
    } */
    void Reset(int r, int c) {
        if (c < 0 || r < 0) {
            throw out_of_range("Matrix size is negative");
        }
        if (c == 0 || r ==0) {
            c = r = 0;
        }
        num_rows = r;
        num_cols = c;
        matrix.assign(r, vector<int>(c));
    }
    int At(int r, int c) const {
        // CheckRange(r, c);
        return matrix.at(r).at(c);
    }
    int& At(int r, int c) {
        // CheckRange(r, c);
        return matrix.at(r).at(c);
    }
    int GetNumRows() const {
        return num_rows;
    }
    int GetNumColumns() const {
        return num_cols;
    }
private:
    int num_rows;
    int num_cols;
    vector<vector<int>> matrix;
};
// * оператор ввода для класса Matrix из потока istream
istream& operator>>(istream& in, Matrix& value) {
    int r;
    int c;
    in >> r >> c;
    value.Reset(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            in >> value.At(i, j);
        }
    }
    return in;
}
// * оператор вывода класса Matrix в поток ostream
ostream& operator<<(ostream& out, const Matrix& value) {
    int c = value.GetNumColumns();
    int r = value.GetNumRows();
    out << c << " " << r << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            out << value.At(i, j) << " ";
        }
        out << endl;
    }
    return out;
}
// * оператор проверки на равенство двух объектов класса Matrix
bool operator==(const Matrix& lhs, const Matrix& rhs) {
    const int columns = lhs.GetNumColumns();
    const int rows = lhs.GetNumRows();
    if (columns!= rhs.GetNumColumns() || rows != rhs.GetNumRows()) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (lhs.At(i, j) != rhs.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}
// * оператор сложения двух объектов класса Matrix
Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    Matrix sum;
    const int columns = lhs.GetNumColumns();
    const int rows = lhs.GetNumRows();
    if (columns == rhs.GetNumColumns() && rows == rhs.GetNumRows()) {
        sum.Reset(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                sum.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
            }
        }
    } else {
        throw invalid_argument("Wrong matrix size to do sum");
    }
    return sum;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    try {
        cout << one.At(1, 2);
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }
    return 0;
}
