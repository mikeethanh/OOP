#include<bits/stdc++.h> 
using namespace std;

class PS {
    private: 
        int TuSo;
        int MauSo;
    public: 
        void nhap() {
            cout << "Nhap tu so : ";
            cin >> TuSo;
            while(true) {
                cout << "Nhap mau so : ";
                cin >> MauSo;
                if(MauSo != 0) break;
            }
        }
        
        void xuat() {
            cout << TuSo << "/"<< MauSo <<endl;    
        }
        
        int ucln(int TuSo, int MauSo) {
            while(MauSo != 0) {
                int temp = MauSo; 
                MauSo = TuSo % MauSo;
                TuSo = temp;
            }
            return TuSo;
        }
        void rutgon() {
            int uclnh = ucln(TuSo,MauSo);
            TuSo /= uclnh;
            MauSo /= uclnh;
        }
        PS operator+(PS temp) {
            PS res ; 
            res.TuSo = temp.TuSo * this->MauSo + this->TuSo * temp.MauSo;
            res.MauSo = temp.MauSo * this->MauSo;
            res.rutgon();
            return res;
        }
        
};

int main() {
    PS a;
    PS b;
    a.nhap();
    b.nhap();
    a.xuat();
    b.xuat();
    PS res = a + b;
    res.xuat();
}