#include <bits/stdc++.h>
using namespace std;

class ToaDo {
    private:
    double HoanhDo;
    double TungDo;
    public:
    //constructor
    ToaDo(): HoanhDo(0.0), TungDo(0.0) {};
    ToaDo(double hd, double td) : HoanhDo(hd), TungDo(td) {};

    //gettter , setter
    double getHoanhDo() {
        return this->HoanhDo;
    }
    double getTungDo() {
        return this->TungDo;
    }
    double setHoanhDo(double hd) {
        this->HoanhDo = hd;
    }
    double setTungDo(double td) {
        this->TungDo = td;
    } 
    //method Nhap:
    void nhap() {
        cout << "- Nhap hoanh do: ";
        cin >> this->HoanhDo;
        cout << "- Nhap tung do:";
        cin >> this->TungDo;
    }
    // xuat toa do :
    void xuat() {
        cout << "( " << this->HoanhDo << " , " << this->TungDo << " )" <<endl;
    }

    // method tinh khoang cach den goc toa do : 
    double tinhKhoangCach() {
        return sqrt(this->HoanhDo * this->HoanhDo + this->TungDo * this->TungDo);
    }
};

//xay dung class DiemMau dan xuat class ToaDo
class DiemMau : public ToaDo {
    private:
    int color;
    public:
    DiemMau() {};
    DiemMau(int color): color(color){};
    //gettter , setter :
    void setColor(int color) {
        this->color = color;
    }
    int getColor() {
        return this->color;
    }
    //ke thua method nhap, xuat;
    void nhap() {
        ToaDo::nhap();
        cout << "- Nhap mau (1 - Do, 2 - Vang, 3 - Xanh) : ";
        cin >>this->color;
    }
    
    void xuat() {
        ToaDo :: xuat();
        string mauCuaDiem;
        cout << "Mau cua diem : ";
        if(this->color == 1) {
            mauCuaDiem = "Do";
            cout << mauCuaDiem <<endl;
        } else if (this->color == 2) {
            mauCuaDiem = "Vang";
            cout << mauCuaDiem <<endl;
        }else {
            mauCuaDiem = "Xanh";
            cout << mauCuaDiem <<endl;
        }
    }

};
int main() {
    //nhap thong tin cho n Diem 
    int n ; 
    cout << "+ Nhap thong tin cho n Diem: ";
    cin >> n;
    vector<DiemMau> listDiem;
    for(int i = 0 ; i < n ; i++) {
        cout << "+ Diem " << i + 1 <<endl;
        DiemMau diem;
        diem.nhap();
        listDiem.push_back(diem);
    }
    //xuat thong tin cho n Diem
    cout << "+ Danh sach cac diem do la : " <<endl; 
    for(int i = 0 ; i < n ; i++) {
        listDiem[i].xuat();
    }

    //thong ke so diem moi mau : 
    int soDiemDo = 0 ; 
    int soDiemVang = 0 ; 
    int soDiemXanh = 0 ; 
    for(int i = 0 ; i < n ; i++) {
        if(listDiem[i].getColor() == 1) {
            soDiemDo++;
        }else if (listDiem[i].getColor() == 2) {
            soDiemVang++;
        }else {
            soDiemXanh++;
        }
    }
    cout << "So diem Vang : " << soDiemVang << endl;
    cout << "So diem Xanh : " << soDiemXanh << endl;
    cout << "So Diem Do : " << soDiemDo <<endl;
    //tim cac diem co khoang cach lon nhat den goc toa do 
    for(int i = 0 ; i < n - 1; i++) {
        for(int j = 0 ; j < n - 1 - i; j++) {
            if(listDiem[j].tinhKhoangCach() < listDiem[j + 1].tinhKhoangCach()) {
                swap(listDiem[j], listDiem[j + 1]);
            }
        }
    }
    for(int i = 0 ; i < n ; i++) {
        cout << "+ Diem " << i + 1 <<endl;
        listDiem[i].xuat();
    }
    
}