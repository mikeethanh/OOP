#include <iostream>
#include <cmath>
#include <vector>

class Diem {
private:
    double hoanhDo;
    double tungDo;

public:
    Diem() : hoanhDo(0.0), tungDo(0.0) {}

    friend std::istream& operator>>(std::istream& is, Diem& diem) {
        std::cout << "Nhap hoanh do: ";
        is >> diem.hoanhDo;
        std::cout << "Nhap tung do: ";
        is >> diem.tungDo;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Diem& diem) {
        os << "(" << diem.hoanhDo << ", " << diem.tungDo << ")";
        return os;
    }

    double tinhKhoangCachDenGoc() const {
        return std::sqrt(hoanhDo * hoanhDo + tungDo * tungDo);
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
    std::cout << "Nhap so luong diem: ";
    std::cin >> n;

    std::vector<Diem> danhSachDiem;

    // Nhập tọa độ n điểm trên mặt phẳng
    for (int i = 0; i < n; ++i) {
        Diem diem;
        std::cout << "Nhap toa do cho diem thu " << i + 1 << ":\n";
        std::cin >> diem;
        danhSachDiem.push_back(diem);
    }

    // Tính tổng khoảng cách từ tất cả các điểm vừa nhập đến gốc tọa độ
    double tongKhoangCach = 0.0;
    for (const auto& diem : danhSachDiem) {
        tongKhoangCach += diem.tinhKhoangCachDenGoc();
    }

    std::cout << "Tong khoang cach tu tat ca cac diem den goc toa do: " << tongKhoangCach << std::endl;

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

    std::cout << "Diem gan nhat den goc toa do: " << diemGanNhat << std::endl;

    return 0;
}
