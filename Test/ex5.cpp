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

    // Hàm nhập vector
    void nhapVector() {
        cout << "Nhap so chieu cua vector: ";
        cin >> n;

        tp.resize(n);

        cout << "Nhap gia tri cho cac thanh phan cua vector:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Nhap thanh phan thu " << i << ": ";
            cin >> tp[i];
        }
    }

    // Hàm xuất vector
    void xuatVector() const {
        cout << "Vector: [";
        for (int i = 0; i < n; ++i) {
            cout << tp[i];
            if (i < n - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }

    // Hàm cộng hai vector
    Vector congVector(const Vector& other) const {
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

    // Hàm trừ hai vector
    Vector truVector(const Vector& other) const {
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

    // Hàm tích vô hướng hai vector
    double tichVoHuong(const Vector& other) const {
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
    v1.nhapVector();
    cout << "Nhap vector v2:\n";
    v2.nhapVector();

    // In vector v1, v2
    cout << "In vector v1:\n";
    v1.xuatVector();
    cout << "In vector v2:\n";
    v2.xuatVector();

    // Cộng hai vector
    Vector v3 = v1.congVector(v2);
    cout << "Vector v1 + v2:\n";
    v3.xuatVector();

    // Trừ hai vector
    Vector v4 = v1.truVector(v2);
    cout << "Vector v1 - v2:\n";
    v4.xuatVector();

    // Tích vô hướng hai vector
    double dotProduct = v1.tichVoHuong(v2);
    cout << "Tich vo huong cua v1 va v2 la: " << dotProduct << endl;

    return 0;
}
