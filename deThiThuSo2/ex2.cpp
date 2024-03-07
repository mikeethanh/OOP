#include <iostream>
#include <vector>

class Hang {
protected:
    std::string maHang;
    std::string tenHang;
    int soLuong;
    double donGia;

public:
    Hang() : maHang(""), tenHang(""), soLuong(0), donGia(0.0) {}

    void nhap() {
        std::cin.ignore();
        std::cout << "Nhap ma hang: ";
        std::getline(std::cin, maHang);
        std::cout << "Nhap ten hang: ";
        std::getline(std::cin, tenHang);
        std::cout << "Nhap so luong: ";
        std::cin >> soLuong;
        std::cout << "Nhap don gia: ";
        std::cin >> donGia;
    }

    void xuat() const {
        std::cout << "Ma hang: " << maHang << ", Ten hang: " << tenHang << ", So luong: " << soLuong
                  << ", Don gia: " << donGia << std::endl;
    }

    const std::string& getMaHang() const {
        return maHang;
    }

    const std::string& getTenHang() const {
        return tenHang;
    }

    int getSoLuong() const {
        return soLuong;
    }

    double getDonGia() const {
        return donGia;
    }
};

class MayGiat : public Hang {
private:
    double soCan;

public:
    MayGiat() : soCan(0.0) {}

    void nhap() {
        Hang::nhap();
        std::cout << "Nhap so can (kg): ";
        std::cin >> soCan;
    }

    void xuat() const {
        Hang::xuat();
        std::cout << "So can (kg): " << soCan << std::endl;
    }

    double getSoCan() const {
        return soCan;
    }
};

int main() {
    int n;
    std::cout << "Nhap so luong may giat: ";
    std::cin >> n;

    std::vector<MayGiat> danhSachMayGiat;

    // Nhập thông tin cho n đối tượng của lớp MayGiat
    for (int i = 0; i < n; ++i) {
        MayGiat mayGiat;
        std::cout << "Nhap thong tin cho may giat thu " << i + 1 << ":\n";
        mayGiat.nhap();
        danhSachMayGiat.push_back(mayGiat);
    }

    // Tìm thông tin về một loại máy giặt bất kỳ (có mã hàng hoặc tên hàng được nhập từ bàn phím)
    std::string maHangCanTim;
    std::cin.ignore();
    std::cout << "Nhap ma hang hoac ten hang can tim: ";
    std::getline(std::cin, maHangCanTim);

    for (const auto& mayGiat : danhSachMayGiat) {
        if (mayGiat.getMaHang() == maHangCanTim || mayGiat.getTenHang() == maHangCanTim) {
            std::cout << "Tim thay thong tin may giat:\n";
            mayGiat.xuat();
            break;
        }
    }

    // In danh sách các máy giặt loại từ 6 kg trở lên mà có giá rẻ nhất
    double giaReNhat = -1; // Giá trị không hợp lệ ban đầu
    for (const auto& mayGiat : danhSachMayGiat) {
        if (mayGiat.getSoCan() >= 6 && (giaReNhat == -1 || mayGiat.getDonGia() < giaReNhat)) {
            giaReNhat = mayGiat.getDonGia();
        }
    }

    if (giaReNhat != -1) {
        std::cout << "Danh sach may giat loai tu 6 kg tro len co gia re nhat:\n";
        for (const auto& mayGiat : danhSachMayGiat) {
            if (mayGiat.getSoCan() >= 6 && mayGiat.getDonGia() == giaReNhat) {
                mayGiat.xuat();
            }
        }
    } else {
        std::cout << "Khong co may giat loai tu 6 kg tro len trong danh sach.\n";
    }

    return 0;
}
