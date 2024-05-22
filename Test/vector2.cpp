#include<iostream>
#include<vector>
using namespace std;

class Vector {
private:
    int n; // số chiều của vector
    vector<double> tp; // vector chứa các giá trị thành phần

public:
    // Hàm tạo không tham số
    Vector() {
        n = 0;
    }

    // Hàm tạo có tham số
    Vector(int dim, const vector<double>& values) : n(dim), tp(values) {}

    // Hàm hủy
    ~Vector() {}

    // Toán tử nhập
    friend istream& operator>>(istream& in, Vector& vec) {
        cout << "Nhap so chieu cua vector: ";
        in >> vec.n;

        vec.tp.resize(vec.n);

        cout << "Nhap gia tri cho cac thanh phan cua vector:\n";
        for (int i = 0; i < vec.n; ++i) {
            cout << "Nhap thanh phan thu " << i << ": ";
            in >> vec.tp[i];
        }

        return in;
    }

    // Toán tử xuất
    friend ostream& operator<<(ostream& out, const Vector& vec) {
        out << "Vector: [";
        for (int i = 0; i < vec.n; ++i) {
            out << vec.tp[i];
            if (i < vec.n - 1) {
                out << ", ";
            }
        }
        out << "]\n";

        return out;
    }

    // Toán tử cộng hai vector
    Vector operator+(const Vector& other) const {
        if (n != other.n) {
            cerr << "Khong the cong hai vector khac chieu!\n";
            return Vector();
        }

        vector<double> result_values(n);
        for (int i = 0; i < n; ++i) {
            result_values[i] = tp[i] + other.tp[i];
        }

        return Vector(n, result_values);
    }

    // Toán tử trừ hai vector
    Vector operator-(const Vector& other) const {
        if (n != other.n) {
            cerr << "Khong the tru hai vector khac chieu!\n";
            return Vector();
        }

        vector<double> result_values(n);
        for (int i = 0; i < n; ++i) {
            result_values[i] = tp[i] - other.tp[i];
        }

        return Vector(n, result_values);
    }

    // Toán tử tích vô hướng hai vector
    double operator*(const Vector& other) const {
        if (n != other.n) {
            cerr << "Khong the tinh tich vo huong cua hai vector khac chieu!\n";
            return 0;
        }

        double result = 0;
        for (int i = 0; i < n; ++i) {
            result += tp[i] * other.tp[i];
        }

        return result;
    }
};

int main() {
    // Nhập vector v1, v2
    Vector v1, v2;
    cout << "Nhap vector v1:\n";
    cin >> v1;
    cout << "Nhap vector v2:\n";
    cin >> v2;

    // In vector v1, v2
    cout << "In vector v1:\n" << v1;
    cout << "In vector v2:\n" << v2;

    // Cộng hai vector
    Vector v3 = v1 + v2;
    cout << "Vector v1 + v2:\n" << v3;

    // Trừ hai vector
    Vector v4 = v1 - v2;
    cout << "Vector v1 - v2:\n" << v4;

    // Tích vô hướng hai vector
    double dotProduct = v1 * v2;
    cout << "Tich vo huong cua v1 va v2 la: " << dotProduct << endl;

    return 0;
}
