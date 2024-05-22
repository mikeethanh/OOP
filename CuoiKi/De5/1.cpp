#include<bits/stdc++.h>
using namespace std;

class Diem {
    private:
        float HoanhDo;
        float TungDo;
    public: 
        void nhap() {
            cout << "Nhap vao hoanh do : ";
            cin >> HoanhDo;
            cout << "Nhap vao tung do: ";
            cin >> TungDo;
        }
        
        void xuat() {
            cout << "(" << HoanhDo << " ; " << TungDo << ") ";
        }
        
        float tinhDD(Diem temp) {
            float res = 0 ;
            res = sqrt(pow((temp.HoanhDo - HoanhDo),2) + pow((temp.TungDo - TungDo),2));
            return res;    
        }
};

int main() {
    int n;
    cout << "Nhap vao n diem: ";
    cin >> n;
    vector<Diem> list;
    for(int i = 0 ; i < n ; i++) {
        Diem temp;
        temp.nhap();
        list.push_back(temp);
    }
    
    for(int i = 0 ; i < n ; i++) {
        list[i].xuat();
    }
    
    float res = 0 ; 
    for(int i = 1; i < n - 1; i++ ) {
        res += list[i].tinhDD(list[i + 1]);
    }
    res += list[n - 1].tinhDD(list[0]);
    cout << res;
}