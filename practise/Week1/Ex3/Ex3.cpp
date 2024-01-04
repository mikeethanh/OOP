#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class KhaoSat {
protected:
    string Ten;
    int STV; // Số thành viên
    double Dientich; // Diện tích ở

public:
    //constructor:
    KhaoSat() {}
    KhaoSat(string ten, int stv, double dientich) : Ten(ten), STV(stv), Dientich(dientich) {}

    //getter setter
    string getTen() const {
        return Ten;
    }
    void setTen(string ten) {
        Ten = ten;
    }

    int getSTV() const {
        return STV;
    }

    void setSTV(int stv) {
        STV = stv;
    }

    double getDientich() const {
        return Dientich;
    }

    void setDientich(double dientich) {
        Dientich = dientich;
    }

    double tinhMatDo() const {
        if (STV != 0) {
            return Dientich / STV;
        }
        return 0;
    }
};

//Lớp KhaoSatTinh được khai báo là lớp dẫn xuất (hay con) của lớp KhaoSat. 
//Điều này có nghĩa là lớp KhaoSatTinh kế thừa tất cả các thành phần (thuộc tính 
//và phương thức) từ lớp KhaoSat.
class KhaoSatTinh : public KhaoSat {
private:
    string Tinh; // Tỉnh thành

public:
    KhaoSatTinh() {}

    //gọi hàm khởi tạo của lớp cha KhaoSat và khởi tạo thuộc tính Tinh của lớp KhaoSatTinh.
    KhaoSatTinh(string ten, int stv, double dientich, string tinh) : KhaoSat(ten, stv, dientich), Tinh(tinh) {}

    string getTinh() const {
        return Tinh;
    }
    void setTinh(string tinh) {
        Tinh = tinh;
    }
};

class QuanLyKhaoSat {
private:
    vector<KhaoSatTinh> danhSachKhaoSat;

public:

    //them 1 ho vao de khao sat 
    void themKhaoSat(const KhaoSatTinh &khaoSat) {
        danhSachKhaoSat.push_back(khaoSat);
    }

    //so sanh 
    void soSanhHocLeVaHocChan() {
        int hocLe = 0, hocChan = 0;
        for (const auto &khaoSat : danhSachKhaoSat) {
            if (khaoSat.getSTV() % 2 == 0) {
                hocChan++;
            } else {
                hocLe++;
            }
        }

        if (hocLe == 0 || hocChan == 0) {
            cout << "Khong du so lieu so sanh." << endl;
        } else {
            cout << "So hoc le: " << hocLe << ", So hoc chan: " << hocChan << endl;
        }
    }

    void timChuHoMatDoLonNhat() {
        double maxMatDo = 0;
        //duyệt từng hộ , so sánh mật độ của từng hộ
        for (const auto &khaoSat : danhSachKhaoSat) {
            maxMatDo = max(maxMatDo, khaoSat.tinhMatDo());
        }

        cout << "Chu ho co mat do lon nhat: " << endl;
        //duỵet từng hộ và tìm chủ hộ có mật độ lớn nhất 
        for (const auto &khaoSat : danhSachKhaoSat) {
            if (khaoSat.tinhMatDo() == maxMatDo) {
                cout << "Ten: " << khaoSat.getTen() << ", Mat do: " << khaoSat.tinhMatDo() << endl;
            }
        }
    }


    void inThongTinHoHNMatDuoi4() {
        cout << "Thong tin ve gia dinh o HN co mat do duoi 4: " << endl;
        for (const auto &khaoSat : danhSachKhaoSat) {
            if (khaoSat.getTinh() == "HN" && khaoSat.tinhMatDo() < 4) {
                cout << "Ten: " << khaoSat.getTen() << ", STV: " << khaoSat.getSTV() << ", Dien tich: " << khaoSat.getDientich() << endl;
            }
        }
    }
};

int main() {
    QuanLyKhaoSat quanLy;

    // Thêm các dữ liệu khảo sát
    quanLy.themKhaoSat(KhaoSatTinh("Nguyen A", 3, 15.6, "HN"));
    quanLy.themKhaoSat(KhaoSatTinh("Tran B", 4, 25.0, "HP"));
    quanLy.themKhaoSat(KhaoSatTinh("Le C", 2, 8.5, "HN"));
    quanLy.themKhaoSat(KhaoSatTinh("Pham D", 5, 30.2, "ND"));
    quanLy.themKhaoSat(KhaoSatTinh("Hoang E", 6, 22.8, "HN"));

    // Thực hiện các yêu cầu
    quanLy.soSanhHocLeVaHocChan();
    quanLy.timChuHoMatDoLonNhat();
    quanLy.inThongTinHoHNMatDuoi4();

    return 0;
}
