#include<bits/stdc++.h>
using namespace std;

class DaThuc{
    private:
        int Bac;
        vector<float> HeSo;
    public:
        DaThuc() {
            Bac = 0;
        }
        
        DaThuc(int Bac) {
            HeSo.resize(Bac + 5);
            cout << "Nhap he so cuar da thuc tu bac cao nhat den bac thap nhat : " << endl;
            for(int i = Bac; i >= 0 ; i--) {
                cout << "He so: ";
                cin >> HeSo[i];
            }
        }
        
        void nhap() {
            cout << "Nhap bac cua da thuc: ";
            cin >> Bac;
            HeSo.resize(Bac + 5);
            for(int i = Bac; i >= 0 ; i--) {
                cout << "He so: ";
                cin >> HeSo[i];
            }
        }
        
        void xuat1() {
            cout << HeSo[0];
            for(int i = 1; i <= Bac; i++) {
                    cout << "+";                
                cout << HeSo[i] << "x^" << i;
            }
        }

        void xuat2() {
            cout << HeSo[Bac] << "x^"<<Bac;
            for(int i = Bac - 1; i > 0 ; i--) {
                    cout << "+";            
                cout << HeSo[i] << "x^" << i;
            }
            if(HeSo[0] > 0) {
                    cout << "+";
                }else {
                    cout << "-";
                }
                cout << abs(HeSo[0]);
            
        }
        float tinhDT(float x) {
            float res = 0 ; 
            for(int i = Bac; i > 0 ; i--) {
                res += HeSo[i] * pow(x,i);
            }        
            res += HeSo[0];
            return res;
        }
};

int main() {
    DaThuc dt;
    dt.nhap();
    dt.xuat1();
    dt.xuat2();
    float x;
    cout << "\nNhap x ";
    cin >> x;
    float res = dt.tinhDT(x);
    cout << res;
}