#include<iostream>
#include<vector>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<double>> elements;

public:
    // Hàm tạo không tham số
    Matrix() : rows(0), cols(0) {}

    // Hàm tạo có tham số
    Matrix(int r, int c, const vector<vector<double>>& elems) : rows(r), cols(c), elements(elems) {}

    // Hàm hủy
    ~Matrix() {}

    // Toán tử nhập
    friend istream& operator>>(istream& in, Matrix& mat) {
        cout << "Nhap so hang cua ma tran: ";
        in >> mat.rows;
        cout << "Nhap so cot cua ma tran: ";
        in >> mat.cols;

        mat.elements.resize(mat.rows, vector<double>(mat.cols, 0));

        cout << "Nhap cac phan tu cua ma tran:\n";
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                cout << "Nhap phan tu hang " << i << ", cot " << j << ": ";
                in >> mat.elements[i][j];
            }
        }

        return in;
    }

    // Toán tử xuất
    friend ostream& operator<<(ostream& out, const Matrix& mat) {
        cout << "Ma tran:\n";
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                out << mat.elements[i][j] << "\t";
            }
            out << endl;
        }

        return out;
    }

    // Toán tử cộng hai ma trận
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Khong the cong hai ma tran khac kich thuoc!\n";
            return Matrix();
        }

        vector<vector<double>> result_elements(rows, vector<double>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result_elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }

        return Matrix(rows, cols, result_elements);
    }
};

int main() {
    // Nhập ma trận A, B
    Matrix A, B;
    cout << "Nhap ma tran A:\n";
    cin >> A;
    cout << "Nhap ma tran B:\n";
    cin >> B;

    // In ma trận A, B
    cout << "In ma tran A:\n" << A;
    cout << "In ma tran B:\n" << B;

    // Cộng hai ma trận
    Matrix C = A + B;
    cout << "Ma tran A + B:\n" << C;

    return 0;
}
