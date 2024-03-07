#include <iostream>
#include <vector>
#include <algorithm>

class NhanVien {
protected:
    int maNV;
    std::string hoTen;
    int namSinh;

public:
    NhanVien() : maNV(0), hoTen(""), namSinh(0) {}

    void nhap() {
        std::cout << "Nhap ma nhan vien: ";
        std::cin >> maNV;
        std::cout << "Nhap ho ten nhan vien: ";
        std::cin.ignore();
        std::getline(std::cin, hoTen);
        std::cout << "Nhap nam sinh: ";
        std::cin >> namSinh;
    }

    void xuat() const {
        std::cout << "Ma nhan vien: " << maNV << ", Ho ten: " << hoTen << ", Nam sinh: " << namSinh << std::endl;
    }

    int getMaNV() const {
        return maNV;
    }

    void setMaNV(int ma) {
        maNV = ma;
    }

    const std::string& getHoTen() const {
        return hoTen;
    }

    void setHoTen(const std::string& ten) {
        hoTen = ten;
    }

    int getNamSinh() const {
        return namSinh;
    }

    void setNamSinh(int nam) {
        namSinh = nam;
    }

    virtual float tinhLuong() const = 0; // Hàm ảo pure virtual
};

class HopDong : public NhanVien {
private:
    long tienCong;
    int ngayCong;

public:
    HopDong() : tienCong(0), ngayCong(0) {}

    void nhap() {
        NhanVien::nhap();
        std::cout << "Nhap tien cong: ";
        std::cin >> tienCong;
        std::cout << "Nhap so ngay cong: ";
        std::cin >> ngayCong;
    }

    void xuat() const {
        NhanVien::xuat();
        std::cout << "Tien cong: " << tienCong << ", Ngay cong: " << ngayCong << std::endl;
    }

    float tinhLuong() const {
        return tienCong * ngayCong;
    }

    // Overloaded equality operator to compare with a string
    bool operator==(const std::string& otherName) const {
        return getHoTen() == otherName;
    }

    long getTienCong() const {
        return tienCong;
    }

    void setTienCong(long tien) {
        tienCong = tien;
    }

    int getNgayCong() const {
        return ngayCong;
    }

    void setNgayCong(int ngay) {
        ngayCong = ngay;
    }
};

int main() {
    int n;
    std::cout << "Nhap so luong nhan vien: ";
    std::cin >> n;

    std::vector<HopDong> danhSachNV;

    // Nhập thông tin cho các nhân viên hợp đồng
    for (int i = 0; i < n; ++i) {
        HopDong nv;
        std::cout << "Nhap thong tin cho nhan vien thu " << i + 1 << ":\n";
        nv.nhap();
        danhSachNV.push_back(nv);
    }

    // Tính tổng tiền lương cho các nhân viên hợp đồng
    long tongLuong = 0;
    for (const auto& nv : danhSachNV) {
        tongLuong += nv.tinhLuong();
    }

    std::cout << "Tong tien luong cho tat ca nhan vien: " << tongLuong << std::endl;

    // Tìm nhân viên theo tên
    std::string tenCanTim;
    std::cout << "Nhap ten nhan vien can tim: ";
    std::cin.ignore();
    std::getline(std::cin, tenCanTim);

    auto it = std::find_if(danhSachNV.begin(), danhSachNV.end(), [&tenCanTim](const HopDong& nv) {
        return nv == tenCanTim;
    });

    if (it != danhSachNV.end()) {
        std::cout << "Nhan vien co ten " << tenCanTim << " ton tai.\n";
    } else {
        std::cout << "Khong tim thay nhan vien co ten " << tenCanTim << ".\n";
    }

    // Tìm nhân viên hợp đồng trẻ nhất
    auto nvTreNhat = std::min_element(danhSachNV.begin(), danhSachNV.end(), [](const HopDong& a, const HopDong& b) {
        return a.getNamSinh() < b.getNamSinh();
    });

    if (nvTreNhat != danhSachNV.end()) {
        std::cout << "Nhan vien tre nhat la:\n";
        nvTreNhat->xuat();
    }

    // Sắp xếp danh sách theo thứ tự giảm dần của lương
    std::sort(danhSachNV.begin(), danhSachNV.end(), [](const HopDong& a, const HopDong& b) {
        return a.tinhLuong() > b.tinhLuong();
    });

    // In danh sách nhân viên hợp đồng theo thứ tự giảm dần của lương
    std::cout << "Danh sach nhan vien hop dong theo thu tu giam dan cua luong:\n";
    for (const auto& nv : danhSachNV) {
        nv.xuat();
    }

    return 0;
}
