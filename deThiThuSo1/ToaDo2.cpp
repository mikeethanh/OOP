#include <iostream>
#include <cmath>
#include <vector>

class Toado {
private:
    double hoanhDo;
    double tungDo;

public:
    Toado() : hoanhDo(0.0), tungDo(0.0) {}

    void nhap() {
        std::cout << "Nhap hoanh do: ";
        std::cin >> hoanhDo;
        std::cout << "Nhap tung do: ";
        std::cin >> tungDo;
    }

    void xuat() const {
        std::cout << "Toa do: (" << hoanhDo << ", " << tungDo << ")\n";
    }

    double tinhKhoangCach() const {
        return std::sqrt(hoanhDo * hoanhDo + tungDo * tungDo);
    }
};

class DiemMau : public Toado {
private:
    int mau;

public:
    DiemMau() : mau(0) {}

    void nhap() {
        Toado::nhap();
        do {
            std::cout << "Nhap mau (1-Do, 2-Vang, 3-Xanh): ";
            std::cin >> mau;
        } while (mau < 1 || mau > 3);
    }

    void xuat() const {
        Toado::xuat();
        std::string tenMau;
        switch (mau) {
            case 1:
                tenMau = "Do";
                break;
            case 2:
                tenMau = "Vang";
                break;
            case 3:
                tenMau = "Xanh";
                break;
            default:
                tenMau = "Khong xac dinh";
        }
        std::cout << "Mau: " << tenMau << std::endl;
    }

    int getMau() const {
        return mau;
    }
};

int main() {
    int n;
    std::cout << "Nhap so diem: ";
    std::cin >> n;

    std::vector<DiemMau> danhSachDiem;

    // Nhập thông tin cho n điểm
    for (int i = 0; i < n; ++i) {
        DiemMau diemMau;
        std::cout << "Nhap thong tin cho diem thu " << i + 1 << ":\n";
        diemMau.nhap();
        danhSachDiem.push_back(diemMau);
    }

    // Thống kê số điểm mỗi màu
    int soDiemDo = 0, soDiemVang = 0, soDiemXanh = 0;

    for (const auto& diemMau : danhSachDiem) {
        switch (diemMau.getMau()) {
            case 1:
                soDiemDo++;
                break;
            case 2:
                soDiemVang++;
                break;
            case 3:
                soDiemXanh++;
                break;
        }
    }

    std::cout << "Thong ke so diem moi mau:\n";
    std::cout << "Do: " << soDiemDo << " diem\n";
    std::cout << "Vang: " << soDiemVang << " diem\n";
    std::cout << "Xanh: " << soDiemXanh << " diem\n";

    // Tìm các điểm có khoảng cách lớn nhất đến gốc tọa độ
    double maxKhoangCach = 0.0;

    for (const auto& diemMau : danhSachDiem) {
        double khoangCach = diemMau.tinhKhoangCach();
        if (khoangCach > maxKhoangCach) {
            maxKhoangCach = khoangCach;
        }
    }

    std::cout << "Cac diem co khoang cach lon nhat den goc toa do:\n";
    for (const auto& diemMau : danhSachDiem) {
        if (diemMau.tinhKhoangCach() == maxKhoangCach) {
            diemMau.xuat();
        }
    }

    return 0;
}
