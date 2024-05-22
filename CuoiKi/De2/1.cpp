#include<bits/stdc++.h> 
using namespace std;

class PS {
    private: 
        int TuSo;
        int MauSo;
    public: 
        PS() {
            TuSo = 0;
            MauSo = 1;
        }
        PS(int x, int y) {
            TuSo = x;
            MauSo = y;
        }
        void nhap() {
            cout << "Nhap vao tu so : ";
            cin >> TuSo;
            cout << "Nhap vao mau so: ";
            cin >> MauSo;
        }
        
        int ucln(int tuso , int mauso) {
            while(mauso != 0) {
                int temp = mauso;
                mauso = tuso % mauso;
                tuso = temp;
            }
            return tuso;
        }
        
        void rutgon() {
            int uclnhat = ucln(TuSo,MauSo);
            TuSo /= uclnhat;
            MauSo /= uclnhat;
        }
        
        PS operator*(PS temp) {
            PS res;
            res.TuSo = TuSo * temp.TuSo;
            res.MauSo = MauSo * temp.MauSo;
            res.rutgon();
            return res;
        }
        
        friend ostream& operator<<(ostream& out, PS temp) {
            temp.rutgon();
            out << temp.TuSo << "/" << temp.MauSo<<endl;
            return out;
        }
};

int main() {
    PS p1(4,2);
    PS p2;
    p2.nhap();
    cout << p1;
    cout << p2;
    PS res = p1 * p2;
    cout << res;
}