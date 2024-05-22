#include<bits/stdc++.h> 
using namespace std;

class Hang {
    private: 
        string MaHang;
        string TenHang;
        int SoLuong;
        int DonGia;
    public:
        Hang(string MH,string TH,int SL,int DG) {
            MaHang = MH;
            TenHang = TH;
            SoLuong = SL;
            DonGia = DG;
        }
        
        
        void nhap() {
            cout << "Nhap Ma Hang : ";
            cin >> MaHang;
            cout << "Nhap Ten Hang : ";
            getline(cin,TenHang);
            cout << "Nhap So Luong : ";
            cin >> SoLuong;
            cout << "Nhap Don Gia : ";
            cin >> DonGia;
        }
        
        void << xuat() {
            cout << " -Ma Hang : " << MaHang;
            cout <<" -Ten Hang: " << TenHang;
            cout << " -SoLuong: " << SoLuong;
            cout << "- Don Gia: " << DonGia;
            cout << endl;
        }
};


int main(){
    vector<Hang> list;
    int n ; 
    cin >> n ; 
    for(int i = 0 ; i < n ; i++) {
        cin >> 
    }
}
