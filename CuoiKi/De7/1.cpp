#include<bits/stdc++.h> 
using namespace std;

class Diem {
    private:
        float x; 
        float y;
    public:
        Diem() {
            this->x = 0 ; 
            this->y = 0;
        }
        Diem(int x , int y) {
            this->x = x ; 
            this->y = y;
        }
        //getter 
        float getX(){
            return this->x;
        }
        
        float getY(){
            return this->y;
        }
        friend ostream&  operator<< (ostream& out, Diem& temp) {
            out << "(" << temp.x << "," << temp.y << ")";
            return out;
        }
        
        friend istream& operator >> (istream& in, Diem& temp) {
            cout << "Nhap x : " ;
            in >> temp.x;
            cout << "Nhay y : " ;
            in >> temp.y;
            return in;
        }
        //tinh khoanch cach tu 1 diem den goc toa do 
        float TinhKC() {
            float res = 0 ; 
            res = sqrt(pow(x,2) + pow(y,2));
            return res;    
        }
        
        
};
int main() {
    int n ; 
    cout << "Nhap n diem : ";
    cin >> n;
    vector<Diem> listDiem; 
    for(int i = 0 ; i < n ; i++) {
        Diem temp ; 
        cin >> temp;
        listDiem.push_back(temp);
    }
    for(int i = 0 ; i < n ; i++) {
        cout << listDiem[i];
    }
    
    //y2:
    float res = 0 ; 
    for(int i = 0 ; i < n ; i++) {
        res += listDiem[i].TinhKC();
    }
    cout << "Tong khoach cach tat ca cac diem den goc toa do la : " << res << endl;
    
    //y3: 
    float minPointDistacne = listDiem[0].TinhKC();
    Diem minPoint = listDiem[0];
    for(int i = 1 ; i < n ; i++) {
        if(listDiem[i].TinhKC() < minPointDistance) {
            minPoint = listDiem[i];
        }
    }
    cout << "Diem: " << minPoint<<endl;
}
