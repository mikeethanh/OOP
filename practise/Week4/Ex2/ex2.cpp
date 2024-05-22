#include<iostream>
using namespace std;

class SoPhuc {
private: 
    int phanThuc;
    int PhanAo;

public:
    SoPhuc() : phanThuc(0), PhanAo(0) {};
    SoPhuc(int a, int b) : phanThuc(a), PhanAo(b) {};

    friend ostream& operator<<(ostream&, const SoPhuc&);
    friend istream& operator>>(istream&, SoPhuc&);
    SoPhuc operator+(SoPhuc);
    SoPhuc operator-(SoPhuc);
    SoPhuc operator*(SoPhuc);
    SoPhuc operator/(SoPhuc);
};

ostream& operator<<(ostream& os, const SoPhuc& v) {
    os << v.phanThuc << " " << v.PhanAo;
    return os;
}

istream& operator>>(istream& is, SoPhuc& v) {
    is >> v.phanThuc >> v.PhanAo;
    return is;
}

SoPhuc SoPhuc::operator+(SoPhuc v) {
    SoPhuc res;
    res.phanThuc = this->phanThuc + v.phanThuc;
    res.PhanAo = this->PhanAo + v.PhanAo;
    return res;
}

SoPhuc SoPhuc::operator-(SoPhuc v) {
    SoPhuc res;
    res.phanThuc = this->phanThuc - v.phanThuc;
    res.PhanAo = this->PhanAo - v.PhanAo;
    return res;
}

SoPhuc SoPhuc::operator*(SoPhuc v) {
    SoPhuc res;
    res.phanThuc = this->phanThuc * v.phanThuc - this->PhanAo * v.PhanAo;
    res.PhanAo = this->phanThuc * v.PhanAo + this->PhanAo * v.phanThuc;
    return res;
}

SoPhuc SoPhuc::operator/(SoPhuc v) {
    SoPhuc res;
    int denominator = v.phanThuc * v.phanThuc + v.PhanAo * v.PhanAo;
    res.phanThuc = (this->phanThuc * v.phanThuc + this->PhanAo * v.PhanAo) / denominator;
    res.PhanAo = (this->PhanAo * v.phanThuc - this->phanThuc * v.PhanAo) / denominator;
    return res;
}

int main() {
    SoPhuc p1(1, 2);
    SoPhuc p2(1, 2);
    SoPhuc p3(1, 2);
    SoPhuc p4(1, 2);
    SoPhuc res = ((p1 + p2) / (p3 + p4)) * p4;
    cout << res << endl;
    return 0;
}
