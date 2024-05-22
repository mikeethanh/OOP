#include<bits/stdc++.h>
using namespace std;

class Hang {
    private:
        string maHang; 
        string tenHang; 
        int soLuong; 
        double donGia;
    public:
        Hang(): soLuong(0), donGia(0.0) {};
        Hang(string maHang, string tenHang, int soLuong, int donGia) : maHang(maHang), tenHang(tenHang), soLuong(soLuong), donGia(donGia) {};
        //method nhap xuat
        void nhap() {
            cin.ignore();
            cout << "Nhap ma Hang : ";
            getline(cin, maHang);
            cout << "Nhap ten Hang : ";
            getline(cin, tenHang);
            cout << "Nhap so luong : ";
            cin >> soLuong;
            cout << "Nhap don gia : ";
            cin >> donGia;
        }
        
        void xuat() {
            cout << "- Ma hang: " << maHang <<endl;
            cout << "- Ten hang: " << tenHang <<endl;
            cout << "- So luong: " << soLuong <<endl;
            cout << "- Don Gia: " << donGia <<endl;
            
        }

       string getTenHang() {
            return tenHang;
        }

        string getMaHang() {
            return maHang;
        }

};

class MayGiat : public Hang {
    private:
        double soCan;
    public: 
        MayGiat(): soCan(0.0) {};
        void nhap() {
            Hang::nhap();
            cout << "Nhap so can: ";
            cin >> soCan;
        }  
        
        void xuat() {
            Hang::xuat();
            cout << "- So can: " << soCan <<endl;    
        }
};
int main() {
    cout << "+ Nhap thong tin ve n may giat: ";
    int n ; 
    cin >> n ;
    vector<MayGiat> listMayGiat ; 
    for(int i = 0 ; i < n ; i++) {
        cout << "May giat thu "<< i + 1<< ": " <<endl;
        MayGiat mg; 
        mg.nhap();
        listMayGiat.push_back(mg);    
    }
    
    for(int i = 0 ; i < n ; i++) {
        listMayGiat[i].xuat();    
    }
    //tim cac thong tin ve moi loai may giat bat ki : 
    string thongTin ; 
    cout <<"Nhap thong tin ve ma Hang or Ten Hang: ";
    cin.ignore();
    getline(cin, thongTin);
    for(int i = 0 ; i < n ; i++ ) {
        if(listMayGiat[i].getMaHang() == thongTin || listMayGiat[i].getTenHang() == thongTin ) {
                listMayGiat[i].xuat();
            }    
    }  
}
