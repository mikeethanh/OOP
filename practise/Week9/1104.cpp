#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MonHoc{
    protected: 
        string mamon;
        string tenMon;
        int stc;
    public:
    MonHoc() {
        mamon = "";
        tenMon = "";
        stc = 0;
    }
    MonHoc(string mamon, int stc){
        this->mamon = mamon;
        this->stc = stc;
    }
    void nhap(){
        cout << "Nhap ma mon: ";
        cin.ignore();
        getline(cin, mamon);
        cout << "Nhap so tin chi: ";
        cin >> stc;
    }
    void xuat(){
        cout <<"Ten mon: " << tenMon << ", So tin chi: " << stc << endl;
    }

    void genTenMon() {
        if(mamon == "1") {
            tenMon = "OOP";
        } else if(mamon == "2") {
            tenMon = "thuat toan";
        } else if(mamon == "3") {
            tenMon = "java";
        } else {
            tenMon = "ko co ten mon hoc do";
        }
    }
};

class HopDong: public MonHoc{
    private:
        string cccd;
        string ht;
        string trinhdo;
        string tenLop;
        string ngaybatdau;
        string ngayketthuc;
    public:
        HopDong() {
            cccd = "";
            ht = "";
            trinhdo = "";
            tenLop = "";
            ngaybatdau = "";
            ngayketthuc = "";
        }

        void nhap(){
            MonHoc::nhap();
            cout << "Nhap can cuoc cong dan: ";
            cin.ignore();
            getline(cin, cccd);
            cout << "Nhap ho ten: ";
            getline(cin, ht);
            cout << "Nhap trinh do: ";
            getline(cin, trinhdo);
            cout << "Nhap ten lop: ";
            getline(cin, tenLop);
            cout << "Nhap ngay bat dau: ";
            getline(cin, ngaybatdau);
            cout << "Nhap ngay ket thuc: ";
            getline(cin, ngayketthuc);
        }
        void xuat(){
            MonHoc::genTenMon();
            MonHoc::xuat();
            cout << "Can cuoc cong dan: " << cccd << ", Ho ten: " << ht << ", Trinh do: " << trinhdo << ", Ten lop: " << tenLop << ", Ngay bat dau: " << ngaybatdau << ", Ngay ket thuc: " << ngayketthuc << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong giao vien: ";
    cin >> n;
    vector<HopDong> list;
    for(int i = 0; i < n; i++){
        cout << "Nhap giao vien thu " << i + 1 << ":\n";
        HopDong gv1;
        gv1.nhap();
        list.push_back(gv1);
    }
    cout << "Danh sach giao vien:\n";
    for(int i = 0; i < n; i++){
        cout << "Giao vien thu " << i + 1 << ":\n";
        list[i].xuat();
    }
    return 0;
}
