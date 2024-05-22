#include<bits/stdc++.h>
using namespace std;

class Nguoi {
    private:
        string HoTen;
        int Tuoi;
    public: 
        void nhap() {
            cout << "Nhap vao ho va ten: ";
            cin.ignore();
            getline(cin,HoTen);
            cout << "Nhap vao tuoi: ";
            cin>> Tuoi;
        }
        
        void xuat() {
            cout << " -Ho va Ten: " << HoTen << " -Tuoi: " << Tuoi;
        }
};

class QLNV : public Nguoi {
    private: 
        float snct;
        float Luong;
    public: 
        float getsnct() {
            return snct;
        }
        
        void nhap() {
            Nguoi::nhap();
            cout << "Nhap vao so nam con gtac: ";
            cin >> snct;
            cout << "Nhap vao luong: ";
            cin >> Luong;
        }
        
        void xuat() {
            Nguoi::xuat();
            cout << " -So nam cong tac: " << snct << " -Luong: " << Luong<<endl;
        }
};

bool cmp(QLNV a, QLNV b) {
    return a.getsnct() > b.getsnct();
}
int main() {
    int n;
    cout << "Nhap vao sp nhan vien: ";
    cin >> n;
    vector<QLNV> list;
    for(int i = 0 ; i < n;i++) {
        QLNV temp;
        temp.nhap();
        list.push_back(temp);
    }
    
    for(int i = 0 ; i < n ; i++) {
        list[i].xuat();
    }
    
    sort(list.begin() , list.end(), cmp);
    for(int i = 0 ; i < n ; i++) {
        list[i].xuat();
    }
}