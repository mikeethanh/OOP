#include <iostream>
#include <string>
using namespace std;

class giaydep {
private:
    string magiay;
    string hangsx;
    int size;
    string color;
    double gia;
public:
    // Default constructor
    giaydep() : magiay(""), hangsx(""), size(0), color(""), gia(0) {}

    // Parameterized constructor
    giaydep(string ma, string hsx, int co, string mau, double gia) : magiay(ma), hangsx(hsx), size(co), color(mau), gia(gia) {}

    // Member functions
    void nhap() {
        cout << "Nhap thong tin cua giay" << endl;
        cin.ignore(); // Ignore newline character in buffer
        cout << "Ma giay: ";
        getline(cin, magiay);
        cout << "Hang san xuat: ";
        getline(cin, hangsx);
        cout << "Size: ";
        cin >> size;
        cout << "Mau: ";
        cin.ignore(); // Ignore newline character in buffer
        getline(cin, color);
        cout << "Gia: ";
        cin >> gia;
    }

    void xuat() const {
        cout << "Ma giay: " << magiay << endl;
        cout << "Hang san xuat: " << hangsx << endl;
        cout << "Size: " << size << endl;
        cout << "Mau: " << color << endl;
        cout << "Gia: " << gia << endl;
    }

    string getHangsx() const { return hangsx; }
    string getMagiay() const { return magiay; }
    int getSize() const { return size; }
    double getGia() const { return gia; }
    string getColor() const { return color; }
};

int main() {
    int n;
    cout << "Nhap so luong giay: ";
    cin >> n;
    cout << "So giay co la: " << n << endl;

    giaydep a[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho giay thu " << i + 1 << endl;
        a[i].nhap();
    }

    // Theo size
    int size;
    cout << "Nhap size can tim: ";
    cin >> size;
    cout << "Cac giay co size " << size << " la:" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].getSize() == size) {
            a[i].xuat();
        }
    }

    // Theo color
    string cl;
    cout << "Nhap mau can tim: ";
    cin.ignore(); // Ignore newline character in buffer
    getline(cin, cl);
    cout << "Cac giay co mau " << cl << " la:" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].getColor() == cl) {
            a[i].xuat();
        }
    }

    // Theo hang
    string h;
    cout << "Nhap hang san xuat can tim: ";
    getline(cin, h);
    cout << "Cac giay cua hang " << h << " la:" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].getHangsx() == h) {
            a[i].xuat();
        }
    }

    // Theo gia
    double g;
    cout << "Nhap gia duoi: ";
    cin >> g;
    cout << "Cac giay co gia duoi " << g << " la:" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].getGia() < g) {
            a[i].xuat();
        }
    }

    return 0;
}
