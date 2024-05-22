#include<bits/stdc++.h>
using namespace std;

class MT {
    private:
        int n;
        int m;
        vector<vector<float>> PhanTu;
    public: 
        MT() {
            n = 0;
        }
        
        void nhap() {
            cout << "Nhap so hang cua ma tran: ";
            cin >>m;
            cout << "Nhap so cot cua ma tran: ";
            cin >> n;
            PhanTu.resize(m,vector<float>(n));
            for(int i = 0 ; i < m ; i++) {
                for(int j = 0 ; j < n; j++) {
                    cin >> PhanTu[i][j];
                }
            }
        }
        
        void xuat() {
            for(int i = 0 ; i < m ; i++) {
                for(int j = 0 ; j < n;j++) {
                    cout << PhanTu[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    MT a;
    a.nhap();
    a.xuat();
}