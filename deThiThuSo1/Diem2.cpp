#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Diem {
private:
    double hoanhDo;
    double tungDo;

public:
    Diem() : hoanhDo(0.0), tungDo(0.0) {}

    friend istream& operator>>(istream& is, Diem& diem) {
        cout << "Nhap hoanh do: ";
        is >> diem.hoanhDo;
        cout << "Nhap tung do: ";
        is >> diem.tungDo;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Diem& diem) {
        os << "(" << diem.hoanhDo << ", " << diem.tungDo << ")";
        return os;
    }

    double tinhKhoangCachDenGoc() const {
        return sqrt(hoanhDo * hoanhDo + tungDo * tungDo);
    }

    double getHoanhDo() const {
        return hoanhDo;
    }

    double getTungDo() const {
        return tungDo;
    }
};

int main() {
    int n;
    cout << "Nhap so luong diem: ";
    cin >> n;

    vector<Diem> danhSachDiem;

    // Nhập tọa độ n điểm trên mặt phẳng
    for (int i = 0; i < n; ++i) {
        Diem diem;
        cout << "Nhap toa do cho diem thu " << i + 1 << ":\n";
        cin >> diem;
        danhSachDiem.push_back(diem);
    }

    // Tính tổng khoảng cách từ tất cả các điểm vừa nhập đến gốc tọa độ
    double tongKhoangCach = 0.0;
    for (const auto& diem : danhSachDiem) {
        tongKhoangCach += diem.tinhKhoangCachDenGoc();
    }

    cout << "Tong khoang cach tu tat ca cac diem den goc toa do: " << tongKhoangCach << endl;

    // Tìm một điểm ở gần gốc tọa độ nhất
    double khoangCachNhoNhat = INT16_MAX;
    Diem diemGanNhat;

    for (const auto& diem : danhSachDiem) {
        double khoangCach = diem.tinhKhoangCachDenGoc();
        if (khoangCach < khoangCachNhoNhat) {
            khoangCachNhoNhat = khoangCach;
            diemGanNhat = diem;
        }
    }

    cout << "Diem gan nhat den goc toa do: " << diemGanNhat << endl;

    return 0;
}
