#include<bits/stdc++.h>
using namespace std;

class DaThuc {
    private:
        int Bac ; 
        vector<float> HeSo;
    public: 
        void nhap() {
            cout << "Nhap bac cua da thuc : ";
            cin >> Bac;
            HeSo.resize(Bac  + 5);
            cout << "Nhap cac he so cua da thuc (tu bac cao nhat den bac thap nhat): "<<endl;
            for(int i = Bac; i >= 0; i--) {
                cout << "He so: ";
                cin >> HeSo[i];
            }
        }
        
        void xuat() {
            cout << "( ";
            for(int i = Bac; i >= 0; i--) {
                cout << HeSo[i] << " ";
            }
            cout << " )"<<endl;
        }
        float tinhGT(float x) {
            float res = 0 ;
            for(int i = Bac; i > 0; i--) {
                res += HeSo[i] * pow(x,i);
            }
            res += HeSo[0];
            return res;
        }
};

int main() {
    DaThuc dt;
    dt.nhap();
    dt.xuat();
    float x ; 
    cout << "Nhap vao so thuc x : ";
    cin >> x;
    
    //tinh gia tri cua da thuc tai x
    float res = dt.tinhGT(x);
    cout << res;

    //in len man hinh da thuc vua nhap :
    
}