#include<bits/stdc++.h> 
using namespace std;

class DaThuc {
    private:
        int Bac;
        vector<float> HeSo;
    public: 
        friend istream& operator>>(istream& in, DaThuc& temp) {
            cout << "Nhap bac cua da thuc: ";
            in >> temp.Bac;
            temp.HeSo.resize(temp.Bac + 5);
            cout << "Nhap cac he so tu bac cao nhat den bac thap nhat : " << endl;
            for(int i = temp.Bac ; i >= 0; i--) {
                cout << "He so: ";
                cin >> temp.HeSo[i];
            }
            return in;
        }
        
        void xuat() {
            cout << HeSo[0];
            for(int i = 1; i <= Bac; i++) {
                cout << "+";
                if(i == 1) {
                    cout << HeSo[i] << "x";
                }else {
                    cout << HeSo[i] << "x^" << i;
                }
            }
        }
        
        friend float tinhDT(float x,DaThuc& temp) {
            float res = 0;
            for(int i = temp.Bac; i > 0; i--) {
                res += temp.HeSo[i] * pow(x,i);
            }
            res += temp.HeSo[0];
            return res;
        }
        
        float timDT(float x) {
            float res = 2021;
            for(int i = Bac; i > 0; i--) {
                res += HeSo[i] * pow(x,i);
            }
            res += HeSo[0];
            res = res * x;
            return res;
        }
};

int main() {
    DaThuc d;
    cin >>d;
    d.xuat();
    float x;
    cin >> x;
    float res1 = tinhDT(x,d);
    cout << res1;
    float res2 = d.timDT(x);
    cout << res2;
}