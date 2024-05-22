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
            cout << "Nhap Ma Hang : ";
            cin >> MaHang;
            cout << "Nhap Ten Hang : ";
            cin.ignore();
            getline(cin,TenHang);
            cout << "Nhap Xuat Xu : ";
            getline(cin,XuatXu);
            cout << "Nhap Loai Hang: ";
            setLoaiHang();
            cout << "Nhap So Luong: ";
            cin >> SoLuong;
        }
        
        void xuat() {
            cout << " -Ma Hang : " << MaHang << " -Ten Hang: " << TenHang << " -Xuat Xu: " << XuatXu <<" -LoaiHang: "<< LoaiHang<< " -So Luong : "<< SoLuong;
        }
        void setLoaiHang() {
            cin >> LoaiHang;
            while(true) {
                if(LoaiHang == 1 || LoaiHang == 2 || LoaiHang == 3) {
                    break;
                }else {
                    cout << "loai hang ko hop le, Nhap lai!"<<endl;
                    cin >> LoaiHang;
                }
            }
        }
        
        int getLoaiHang() {
            return LoaiHang;
        }
};

class DienTu : public QLH {
    private: 
        int tgbh;
    public:
        void nhap(){
            QLH::nhap();
            cout << "nhap vao tgbh: ";
            cin >> tgbh;
        }
        
        void xuat() {
            QLH::xuat();
            cout << " -tgbh: " << tgbh<<endl;
        }
        int gettgbh() {
            return tgbh; 
        }
        
};

int main() {
    int n ; 
    cout << "Nhap vao n do dieu tu: ";
    cin >>n;
    vector<DienTu> list;
    for(int i = 0 ; i < n ; i++) {
        DienTu temp;
        temp.nhap();
        list.push_back(temp);
    }
    
    for(int i = 0 ; i < n ; i++) {
        list[i].xuat();
    }
}