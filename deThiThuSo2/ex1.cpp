#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

class DaThuc {
private:
    int bac;
    vector<float> hs;

public:
    // Hàm tạo không tham số
    DaThuc() : bac(0) {}

    // Hàm tạo có tham số
    DaThuc(int b, vector<float>& heSo) : bac(b), hs(heSo) {}

    // Hàm hủy
    ~DaThuc() {}

    // Hàm nhập đa thức
    void nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;

        hs.resize(bac + 1);

        cout << "Nhap cac he so cua da thuc:\n";
        for (int i = 0; i <= bac; ++i) {
            cout << "He so thu " << i << ": ";
            cin >> hs[i];
        }
    }

    // Hàm in ra các hệ số của đa thức
    void inDaThuc() {
        cout << "Da thuc: ";
        for (int i = 0 ; i < hs.size(); ++i) {
            cout << "he so thu" << i +1 <<   ": "  <<hs[i];
        }
        cout << endl;
    }

    // Hàm tính giá trị của đa thức tại x
    float tinhGiaTri(float x) {
        float giaTri = 0.0f;
        for (int i = 0; i <= bac; ++i) {
            giaTri += hs[i] * pow(x, i);
        }
        return giaTri;
    }
};

int main() {
    int bac;
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;

    vector<float> heSo(bac + 1);

    cout << "Nhap cac he so cua da thuc:\n";
    for (int i = 0; i <= bac; ++i) {
        cout << "He so thu " << i << ": ";
        cin >> heSo[i];
    }

    float x;
    cout << "Nhap gia tri x: ";
    cin >> x;

    DaThuc daThuc(bac, heSo);

    // In đa thức
    daThuc.inDaThuc();

    // Tính giá trị của đa thức tại x và in ra màn hình
    float giaTri = daThuc.tinhGiaTri(x);
    cout << "Gia tri cua da thuc tai x = " << x << " la: " << giaTri << std::endl;

    return 0;
}
