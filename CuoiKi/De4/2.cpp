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
        MatHang(){
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
            cout << "Nhap ma hang : ";
            cin >> MaHang;
            cout << "Nhap ten hang : ";
            cin.ignore();
            getline(cin,TenHang);
            cout << "Nhap nha san xuat: ";
            getline(cin,NhaSanXuat);
            cout << "Nhap so luong : ";
            cin >> SoLuong;
            cout << "Nhap don gia : ";
            cin >> DonGia;        
        }
        
        void xuat() {
            cout << " -Ma Hang : " << MaHang << " -Ten Hang: " << TenHang << " -Nha San Xuat: " << NhaSanXuat << " -So Luong: " << SoLuong << " -DonGia: " << DonGia ;
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
            cout << "Nhap vao CPU : ";
            cin >> CPU;
            cout << "Nhap vao trong luong: ";
            cin >> TrongLuong;
            cout << "Nhap vao He Dieu Hanh: ";
            cin >> HeDieuHanh;
            while(true) {
                if(HeDieuHanh == "Window" || HeDieuHanh == "Linux") {
                    break;
                } else {
                    cin >> HeDieuHanh;                
                }
            }
        }
        
        void xuat() {
            MatHang :: xuat();
            cout << " -CPU: " << CPU << " -Trong luong: " << TrongLuong << " -HeDieuHanh: " << HeDieuHanh<<endl;
        }
};

int main() {
    int n ;
    cout << "Nhap so doi tuong : ";
    cin >> n;
    vector<MayTinh> list;
    for(int i = 0 ; i < n ; i++) {
        MayTinh temp;
        temp.nhap();
        list.push_back(temp);
    }
    
    for(int i = 0 ; i < n ; i++ ) {
        list[i].xuat();
    }
}