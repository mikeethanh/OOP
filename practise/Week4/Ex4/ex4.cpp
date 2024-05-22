#include <iostream>
#include <vector>
#include <algorithm> // Để sử dụng std::sort
using namespace std;

class ThiSinh {
private:
    string ten;
    float diem;

public:
    ThiSinh() : ten(""), diem(0.0) {}
    ThiSinh(string ten, float diem) : ten(ten), diem(diem) {}

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& os, const ThiSinh& ts) {
        os << "Ten: " << ts.ten << ", Diem: " << ts.diem;
        return os;
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& is, ThiSinh& ts) {
        cout << "Nhap ten thi sinh: ";
        is >> ts.ten;
        cout << "Nhap diem thi sinh: ";
        is >> ts.diem;
        return is;
    }

    // Toán tử so sánh <
    friend bool operator<(const ThiSinh& ts1, const ThiSinh& ts2) {
        return ts1.diem > ts2.diem; // Sắp xếp giảm dần theo điểm
    }

    // Toán tử so sánh >
    friend bool operator>(const ThiSinh& ts1, const ThiSinh& ts2) {
        return ts1.diem < ts2.diem; // Sắp xếp tăng dần theo điểm
    }
};

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;

    vector<ThiSinh> danhSach;

    for (int i = 0; i < n; ++i) {
        ThiSinh ts;
        cin >> ts; // Sử dụng toán tử nhập >>
        danhSach.push_back(ts);
    }

    // Sắp xếp danh sách giảm dần theo điểm
    sort(danhSach.begin(), danhSach.end());

    // In ra danh sách đã sắp xếp
    cout << "Danh sach thi sinh theo thu tu giam dan diem:\n";
    for (const ThiSinh& ts : danhSach) {
        cout << ts << endl; // Sử dụng toán tử xuất <<
    }

    return 0;
}
