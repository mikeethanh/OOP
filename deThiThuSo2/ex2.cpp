#include <iostream>
#include <vector>
using namespace std;

class Hang {
protected:
    string maHang;
    string tenHang;
    int soLuong;
    double donGia;

public:
    Hang() : maHang(""), tenHang(""), soLuong(0), donGia(0.0) {}

    void nhap() {
        cin.ignore();
        cout << "Nhap ma hang: ";
        getline(cin, maHang);
        cout << "Nhap ten hang: ";
        getline(cin, tenHang);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    void xuat() {
        cout << "Ma hang: " << maHang << ", Ten hang: " << tenHang << ", So luong: " << soLuong
                  << ", Don gia: " << donGia << endl;
    }

    const string getMaHang() {
        return maHang;
    }

    const string getTenHang() {
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
        cout << "Nhap so can (kg): ";
        cin >> soCan;
    }

    void xuat() {
        Hang::xuat();
        cout << "So can (kg): " << soCan << endl;
    }

    double getSoCan() {
        return soCan;
    }
};

int main() {
    int n;
    cout << "Nhap so luong may giat: ";
    cin >> n;

    vector<MayGiat> danhSachMayGiat;

    // Nhập thông tin cho n đối tượng của lớp MayGiat
    for (int i = 0; i < n; ++i) {
        MayGiat mayGiat;
        cout << "Nhap thong tin cho may giat thu " << i + 1 << ":\n";
        mayGiat.nhap();
        danhSachMayGiat.push_back(mayGiat);
    }

    // Tìm thông tin về một loại máy giặt bất kỳ (có mã hàng hoặc tên hàng được nhập từ bàn phím)
    string maHangCanTim;
    cin.ignore();
    cout << "Nhap ma hang hoac ten hang can tim: ";
    getline(cin, maHangCanTim);

    for (const auto& mayGiat : danhSachMayGiat) {
        if (mayGiat.getMaHang() == maHangCanTim || mayGiat.getTenHang() == maHangCanTim) {
            cout << "Tim thay thong tin may giat:\n";
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
        cout << "Danh sach may giat loai tu 6 kg tro len co gia re nhat:\n";
        for (const auto& mayGiat : danhSachMayGiat) {
            if (mayGiat.getSoCan() >= 6 && mayGiat.getDonGia() == giaReNhat) {
                mayGiat.xuat();
            }
        }
    } else {
        cout << "Khong co may giat loai tu 6 kg tro len trong danh sach.\n";
    }

    return 0;
}
