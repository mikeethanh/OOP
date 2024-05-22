#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class DaThuc {
private:
    int Bac; 
    vector<double> HeSo;
public:
    DaThuc() : Bac(0) {}
    DaThuc(int Bac, vector<double> HeSo) : Bac(Bac), HeSo(HeSo) {}
    // getter, setter
    void setBac(int Bac) {
        this->Bac = Bac;
    }
    int getBac() {
        return this->Bac;    
    }
    
    vector<double> getHeSo() {
        return HeSo;
    }
    // h�m nh?p m?t da th?c
    void nhap() {
        cout << "- Nhap he so cua Da Thuc: "; 
        cin >> Bac;
        cout << "- Nhap he so cua da thuc: " <<endl; 
        for(int i = 0; i <= Bac; i++) {
            double temp; 
            cout << "Nhap he so bac " << i << ": ";
            cin >> temp;  
            HeSo.push_back(temp);
        }
    }
    
    // h�m xu?t m?t da th?c
    void xuat() {
        cout << "( ";
        for(int i = 0; i <= Bac; i++) {
            cout << HeSo[i] << " ";
        }
        cout << ")";
    }
    
    // h�m t�nh gi� tr? c?a da th?c
    double tinhGiaTri(double x) {
        double res = 0.0;
        for(int i = 0; i <= Bac; i++) {
            res += (HeSo[i] * pow(x, i));
        }
        return res;
    }
};

int main() {
    double x;
    cout << "+ Nhap so thuc x: "; 
    cin >> x; 
    DaThuc dt;
    dt.nhap();
    cout << "+ Cac he so cua Da Thuc la : ";
    dt.xuat();
    //in da thuc
    vector<double> heSo = dt.getHeSo();
    cout << "+ Da thuc : ";
    for(int i = dt.getBac(); i >= 0; i--) {
    if(heSo[i] != 0) {
        if (i == dt.getBac()) {
            if (heSo[i] < 0) cout << "-";
        } else {
            if (heSo[i] > 0) cout << " + ";
            else cout << " - ";
        }
        
        if (abs(heSo[i]) != 1 || i == 0) cout << abs(heSo[i]);
        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }
    }
}

    cout << "\nGia tri cua da thuc tai x = " << x << " la: " << dt.tinhGiaTri(x);
    
    return 0;
}
