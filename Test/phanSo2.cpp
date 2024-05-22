#include<iostream>
using namespace std;

class phanSo {
private:
    int tuSo;
    int mauSo;

public:
    phanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    phanSo(const phanSo& other) {
        this->tuSo = other.tuSo;
        this->mauSo = other.mauSo;
    }

    int ucln(int num, int denom) {
        while (denom != 0) {
            int temp = denom;
            denom = num % denom;
            num = temp;
        }
        return num;
    }

    void toiGian() {
        int uocChungLonNhat = ucln(tuSo, mauSo);
        tuSo /= uocChungLonNhat;
        mauSo /= uocChungLonNhat;
    }

    // Toán tử nhập và xuất
    friend ostream& operator<<(ostream& out, const phanSo& f) {
        out << f.tuSo << "/" << f.mauSo;
        return out;
    }

    friend istream& operator>>(istream& in, phanSo& f) {
        cout << "Nhap tu so: ";
        in >> f.tuSo;
        cout << "Nhap mau so: ";
        in >> f.mauSo;
        f.toiGian();
        return in;
    }

    // Toán tử cộng
    phanSo operator+(const phanSo& other) const {
        phanSo ketQua;
        ketQua.tuSo = this->tuSo * other.mauSo + other.tuSo * this->mauSo;
        ketQua.mauSo = this->mauSo * other.mauSo;
        ketQua.toiGian();
        return ketQua;
    }

    // Toán tử trừ
    phanSo operator-(const phanSo& other) const {
        phanSo ketQua;
        ketQua.tuSo = this->tuSo * other.mauSo - other.tuSo * this->mauSo;
        ketQua.mauSo = this->mauSo * other.mauSo;
        ketQua.toiGian();
        return ketQua;
    }

    // Toán tử nhân
    phanSo operator*(const phanSo& other) const {
        phanSo ketQua;
        ketQua.tuSo = this->tuSo * other.tuSo;
        ketQua.mauSo = this->mauSo * other.mauSo;
        ketQua.toiGian();
        return ketQua;
    }

    // Toán tử chia
    phanSo operator/(const phanSo& other) const {
        phanSo ketQua;
        ketQua.tuSo = this->tuSo * other.mauSo;
        ketQua.mauSo = this->mauSo * other.tuSo;
        ketQua.toiGian();
        return ketQua;
    }
};

int main() {
    phanSo p1, p2, p3, p4;

    // Nhập giá trị cho p1, p2, p3, và p4
    cout << "Nhap gia tri cho p1: ";
    cin >> p1;

    cout << "Nhap gia tri cho p2: ";
    cin >> p2;

    cout << "Nhap gia tri cho p3: ";
    cin >> p3;

    cout << "Nhap gia tri cho p4: ";
    cin >> p4;

    // Tính giá trị biểu thức: (p1 + p2) / (p3 + p4) * p1
    phanSo tong_p1_p2 = p1 + p2;
    phanSo tong_p3_p4 = p3 + p4;
    phanSo ketQua = tong_p1_p2 / tong_p3_p4 * p1;

    // Hiển thị kết quả
    cout << "Gia tri bieu thuc (p1 + p2)/(p3 + p4) * p1 la: " << ketQua << endl;

    return 0;
}
