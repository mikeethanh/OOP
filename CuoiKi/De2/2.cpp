#include<bits/stdc++.h> 
using namespace std;

class MatHang {
    private: 
        string MaHang;
        string TenHang;
        string NhaSanXuat;
        int SoLuong;
        int DonGia;
    public:
        MatHang() {
            MaHang = "";
            TenHang = "";
            NhaSanXuat = "";
            SoLuong = 0;
            DonGia = 0;
        }
        
        MatHang(string mh,string th,string nsx,int sl,int dg) {
            MaHang = mh;
            TenHang = th;
            NhaSanXuat = nsx;
            SoLuong = sl;
            DonGia = dg;
        }
        
        void nhap() {
            cout << "Nhap vap ma hang : ";
            cin >> MaHang;
            cout << "Nhap ten hang: ";
            cin.ignore();
            getline(cin,MatHang);
            cout << "Nhap vao nha san xuat : ";
            getline(cin,NhaSanXuat);
            cout << "Nhap vao so luong: ";
            cin >> SoLuong;
            cout << "Nhap vao son gia: ";
            cin >> DonGia;
        }
        
        void xuat() {
            cout << " -Ma Hang: " << MaHang << " -Ten Hang: " << TenHang << " -Nha san xuat: " << NhaSanXuat << " -So Luong: " << SoLuong << " -Don gia: " << DonGia;
        }
};

class MayTinh : public MatHang {
    private: 
        string CPU;
        string HeDieuHanh;
        float TrongLuong;
    public: 
        void nhap() {
            MatHang::nhap();
            cout << "Nhap vao CPU: ";
            cin >> CPU;
            cout << "NHap vao He dieu hanh: ";
            cin >> HeDieuHanh;
            cout << "Nhap trong luong: ";
            cin >> TrongLuong;
        }
        
        void xuat() {
            MatHang::xuat();
            cout << " -CPU: " << CPU << " -He Dieu Hanh: " << HeDieuHanh << " -Trong Luong: " << TrongLuong <<endl;
        }
};

int main() {
    int n ;
    cout << "Nhap vap so May tinh: ";
    cin >> n;
    vector<MayTinh> list;
    for(int i = 0 ; i < n ; i++) {
        MayTinh temp;
        temp.nhap();
        list.push_back(temp);
    }
    
    for(int i = 0 ; i < n;i++) {
        list[i].xuat();
    }
    
}