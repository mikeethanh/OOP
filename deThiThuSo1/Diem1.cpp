#include<bits/stdc++.h>
using namespace std;

class Diem {
    private:
    double HoanhDo;
    double TungDo;
    public:
    //contructor
    Diem(): HoanhDo(0.0), TungDo(0.0) {};
    Diem(double HoanhDo, double TungDo) : HoanhDo(HoanhDo), TungDo(TungDo) {};

    //getter setter
    double getHoanhDo() {
        return this->HoanhDo;
    }
    double getTungDo() {
        return this->TungDo;
    }
    void setHoanhDo(double HoanhDo) {
        this->HoanhDo = HoanhDo;
    }
    void setTungDo(double TungDo) {
        this->TungDo = TungDo;
    }
    //operator
    friend istream& operator>>(istream& in, Diem& diem) {
        cout << "Nhap tung do: ";
        in >>diem.TungDo;
        cout << "Nhap hoanh do: ";
        in >> diem.HoanhDo;
        return in;
    }

    friend ostream& operator<<(ostream& out , Diem& diem) {
        out << "( " << diem.TungDo << " , " << diem.HoanhDo << " )" <<endl;
        return out;
    }

    //phuong thuc tinh khoang cach tu 1 diem den goc toa do 
    double tinhKc() {
        double res = 0.0;
        res = sqrt(pow(this->HoanhDo,2) + pow(this->TungDo,2));
        return res;
    }
};

int main() {
    //nhap toa do n diem tren mat phang
    cout << "Nhap so diem: ";
    int n;
    cin >> n; 
    vector<Diem> listDiem;
    for(int i = 0 ; i < n ; i++) {
        cout << "+ DIEM: " << i + 1 << endl;
        Diem diem;
        cin >> diem;
        listDiem.push_back(diem);
    }

    //in danh sach cac diem: 
    cout <<"+ Danh sach cac diem:" << endl;
    for(int i = 0 ; i < n; i++) {
        cout << listDiem[i] << endl;
    }
    //tinh tong khoach cach cac diem vua nhap den goc toa do 
    double res = 0.0;
    for(int i = 0 ; i < n ; i++) {
        res += listDiem[i].tinhKc();
    }
    cout << "+ Tong khoang tu cac diem den goc toa do la : " << res << endl;

    //tim mot diem o gan goc toa do nhat : 
    double minDistance = INT16_MAX ; 
    Diem minDiem ; 
    for(int i = 0 ; i < listDiem.size() ; i++) {
        if(listDiem[i].tinhKc() < minDistance) {
            minDiem = listDiem[i];
        }
    }
    cout << "+ Diem gan goc toa do nhat la :";
    cout << minDiem << endl;
}
