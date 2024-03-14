//lop dan xuat nhanvien-bienche-hopdong
#include"bits/stdc++.h"
using namespace std;
class NhanVien{
    int manv;
    string hoten;
public:
    void nhap(){
        cout << "nhap ma nhan vien: ";
        cin >> manv;
        cout << "nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
    }
    void xuat(){
        cout << "ma nhan vien: " << manv << " ho ten: " << hoten;
    }
};
class BienChe : public NhanVien{
    float hsl;
    int snct;
public:
    void nhap(){
        NhanVien::nhap();
        cout << "so nam cong tac: ";
        cin >> snct;
        cout << "he so luong: ";
        cin >> hsl;
    }

    void xuat(){
        NhanVien::xuat();
        cout << " so nam cong tac: " << snct << " he so luong: " << hsl;
    }
};
class HopDong : public BienChe{
    int ngaycong;
    float tiencong;
public:
    void nhap(){
        BienChe::nhap();
        cout << "nhap ngay cong: ";
        cin >> ngaycong;
        cout << "nhap tien cong: ";
        cin >> tiencong;
    }
    void xuat(){
        BienChe::xuat();
        cout << " ngay cong:  " << ngaycong << " tien cong: " << tiencong;
    }
};
int main(){
	HopDong hd;
	hd.nhap();
	hd.xuat();	
}

