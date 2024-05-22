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

    // Getter, setter
    int getTuSo() const {
        return this->tuSo;
    }

    int getMauSo() const {
        return this->mauSo;
    }

    void setTuSo(int tuSo) {
        this->tuSo = tuSo;
    }

    void setMauSo(int mauSo) {
        this->mauSo = mauSo;
    }

    void toiGian() {
        int uocChungLonNhat = ucln(this->tuSo, this->mauSo);
        this->tuSo /= uocChungLonNhat;
        this->mauSo /= uocChungLonNhat;
    }

    void nhap() {
        int x, y;
        cout << "Nhap tu so: ";
        cin >> x;
        cout << "Nhap mau so: ";
        cin >> y;
        setTuSo(x);
        setMauSo(y);
        toiGian();
    }

    void in() const {
        cout << "Phan so: " << this->tuSo << "/" << this->mauSo << endl;
    }

    phanSo tong(const phanSo& other) const {
        phanSo ketQua;
        ketQua.setMauSo(this->mauSo * other.getMauSo());
        ketQua.setTuSo(this->tuSo * other.getMauSo() + other.getTuSo() * this->mauSo);
        return ketQua;
    }

    phanSo hieu(const phanSo& other) const {
        phanSo ketQua;
        ketQua.setTuSo(this->tuSo * other.getMauSo() - other.getTuSo() * this->mauSo);
        ketQua.setMauSo(this->mauSo * other.getMauSo());
        return ketQua;
    }
};

int main() {
    phanSo p1, p2, p3, p4;

    p1.nhap();
    p2.nhap();
    p3.nhap();
    p4.nhap();

    // Ví dụ về việc sử dụng phương thức tong và in
    phanSo ketQuaTong = p1.tong(p2);
    cout << "Tong cua p1 va p2 la: ";
    ketQuaTong.in();

    return 0;
}
