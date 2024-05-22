#include<iostream>
#include<cmath>
using namespace std;

class TinhS {
private:
    int a, b, c, d, r; 
public:
    TinhS() : a(0), b(0), c(0), d(0), r(0) {};
    TinhS(int a, int b, int c) : a(a), b(b), c(c), d(0), r(0) {};

    //triangle
    float tinhDienTich(int a, int b, int c) {
        float s = (float)(a + b + c) / 2;
        float S = sqrt(s * (s - a) * (s - b) * (s - c));
        return S;
    }

    //rectangle
    int tinhDienTich(int a, int b) {
        return a * b;
    }

    //square
    int tinhDienTich(int a) {
        return a * a;
    }


    //circle
    float tinhDienTich() {
        return M_PI * r * r;
    }
};

int main() {
    cout << "Menu" << endl;
    cout << "1: S tam giac" << endl;
    cout << "2: S chu nhat" << endl;
    cout << "3: S vuong" << endl;
    cout << "4: S tron" << endl;
    cout << "Nhap lua chon: ";
    
    int choice;
    cin >> choice;

    TinhS hinh;

    switch (choice) {
    case 1:
        int a, b, c;
        cout << "Nhap cac canh tam giac: ";
        cin >> a >> b >> c;
        cout << "Dien tich tam giac: " << hinh.tinhDienTich(a, b, c) << endl;
        break;

    case 2:
        int d, e;
        cout << "Nhap cac canh chu nhat: ";
        cin >> d >> e;
        cout << "Dien tich chu nhat: " << hinh.tinhDienTich(d, e) << endl;
        break;

    case 3:
        int f;
        cout << "Nhap canh hinh vuong: ";
        cin >> f;
        cout << "Dien tich hinh vuong: " << hinh.tinhDienTich(f) << endl;
        break;

    case 4:
        int r;
        cout << "Nhap ban kinh hinh tron: ";
        cin >> r;
        cout << "Dien tich hinh tron: " << hinh.tinhDienTich() << endl;
        break;

    default:
        cout << "Lua chon khong hop le." << endl;
    }

    return 0;
}
