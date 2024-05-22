#include<bits/stdc++.h> 
using namespace std;

class Hang {
    private: 
        string MaHang;
        string TenHang;
        int SoLuong;
        int DonGia;
    public:
        Hang() {
            MaHang = "";
            TenHang = "";
            SoLuong = 0;
            DonGia = 0;
        }
        Hang(string MH,string TH,int SL,int DG) {
            MaHang = MH;
            TenHang = TH;
            SoLuong = SL;
            DonGia = DG;
        }
        
        string getMaHang(){
            return MaHang;    
        }
        
        string getTenHang() {
            return TenHang;
        }
        
        int getSoLuong() {
            return SoLuong;
        }
        
        int getDonGia() {
            return DonGia;
        }
        
        void nhap() {
            cout << "Nhap Ma Hang : ";
            cin >> MaHang;
            cout << "Nhap Ten Hang : ";
            cin.ignore();
            getline(cin,TenHang);
            cout << "Nhap So Luong : ";
            cin >> SoLuong;
            cout << "Nhap Don Gia : ";
            cin >> DonGia;
        }
        
        void xuat() {
            cout << " -Ma Hang : " << MaHang;
            cout <<" -Ten Hang: " << TenHang;
            cout << " -SoLuong: " << SoLuong;
            cout << "- Don Gia: " << DonGia;
        }
};

class MayGiat : public Hang {
    private:
        float SoCan; 
    public:   
        void nhap() {
            Hang::nhap();
            cout << "Nhap so can(kg): ";
            cin >> SoCan;
        }
        float getSoCan() {
            return SoCan;
        }
        void xuat() {
            Hang::xuat();
            cout << " -So can : "<<SoCan;
            cout << endl;
        }
};

int main(){
    vector<MayGiat> list;
    int n ; 
    cout << "Nhap vao so may giat: ";
    cin >> n ; 
    for(int i = 0 ; i < n ; i++) {
        MayGiat temp;
        temp.nhap();
        list.push_back(temp);
    }
    
    for(int i = 0 ;  i < n ; i++) {
        list[i].xuat();    
    }
    
    string MaHoacTen = "";
    cout << "Nhap vao ten hang or ma hang : ";
    cin.ignore();
    getline(cin,MaHoacTen);
    
    for(int i = 0; i < n ; i++) {
        if(list[i].getMaHang() == MaHoacTen || list[i].getTenHang() == MaHoacTen) {
            list[i].xuat();
            break;
        }
    }
    //
    int minPrice = list[0].getSoLuong() * list[0].getDonGia();
    int index = 0;
    for(int i = 1 ; i < n ; i++) {
        if((list[i].getDonGia() * list[i].getSoLuong()) < minPrice && list[i].getSoCan() >= 6) {
            list[i].xuat();
            index = 1;
            break;
        }
    }
    
}
