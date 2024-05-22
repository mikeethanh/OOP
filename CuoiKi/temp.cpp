#include<bits/stdc++.h>
using namespace std;

class QLH {
    private: 
        string MaHang;
        string TenHang;
        string XuatXu;
        int LoaiHang;
        int SoLuong;
    public: 
        void nhap() {
            cout << "Nhap ma hang : ";
            cin >> MaHang;
            cout << "Nhap ten hang: ";
            cin.ignore();
            getline(cin,TenHang);
            cout <<"Nhap xuat xu: ";
            cin.ignore();
            getline(cin,XuatXu);
            cout << "Nhap loai hang: ";
            cin >> LoaiHang;
            setLoaiHang();
            cout <<"Nhap so luong: ";
            cin >> SoLuong;
        }
        
        void xuat() {
            cout << " -Ma Hang: " <<MaHang << " -TenHang" << " -Xuat xu: "<< XuatXu << " -LoaiHang: " << LoaiHang << " -SoLuong: "<< SoLuong; 
        }
        void setLoaiHang() {
            while(true) {
                if(LoaiHang == 1 || LoaiHang == 2 || LoaiHang == 3) {
                    break;
                }else {
                    cout << "Loai hang khong hop le, nhap lai!";
                    cin >>LoaiHang;
                }
            }
        }
};

class DienTu : public QLH {
    private: 
        int tgbh;
    public:
        void nhap() {
            QLH::nhap();
            cout << "Nhap tgbh: ";
            cin >>tgbh;
        }
        
        void xuat() {
            QLH::xuat();
            cout << " -tgbh: " << tgbh<<endl;
        }
};

int main() {
    int n ; 
    cout << "Nhap vao so hang dien tu : ";
    cin >> n ; 
    vector<DienTu> list;
    for(int i = 0 ; i < n ; i++ ) {
        DienTu temp;
        temp.nhap();
        list.push_back(temp);
    }
    
    for(int i = 0; i < n ; i++) {
        list[i].xuat();
    }
}