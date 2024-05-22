#include<iostream>
#include<string>
using namespace std;

class xemay{
    string hangxe;
    string tenxe;
    string sokhung;
    int dt;
    double giaxe;
    public:
        xemay(){
            this->hangxe="";
            this->tenxe ="";
            this->sokhung="";
            this->dt=0;
            this->giaxe=0.0;
        }
        xemay(string hangxe, string tenxe, string sokhung, int dt, double giaxe){
            this->hangxe = hangxe;
            this->tenxe = tenxe;
            this->sokhung = sokhung;
            this->dt= dt;
            this-> giaxe = giaxe;
        }
        string gethangxe(){
            return this->hangxe;
        }
        string gettenxe(){
            return this->tenxe;
        }
        string getsokhung(){
            return this-> sokhung;
        }
        int getdt(){
            return this -> dt;
        }
        double getgiaxe(){
            return this -> giaxe;
        }
        void sethangxe(string hangxe){
            hangxe = hangxe;
        }
        void settenxe(string tenxe){
            tenxe = tenxe;
        }
        void setsokhung(string sokhung){
            sokhung=sokhung;
        }
        void setdt(int dt){
            dt = dt;
        }
        void setgiaxe(double giaxe){
            giaxe = giaxe;
        }
        void nhap(){
            cout<<"Nhap hang xe: ";
            getline(cin,hangxe);
            cout<<"Nhap ten xe: ";
            getline(cin,tenxe);
            cout<<"Nhap so khung: ";
            getline(cin,sokhung);
            cout<<"Nhap dung tich xi lanh: ";
            cin>>dt;
        }
        void in(){
            cout<<"Hang xe: "<<hangxe<<endl;
            cout<<"Ten xe: "<<tenxe<<endl;
            cout<<"So khung: "<<sokhung<<endl;
            cout<<"Dung tich xilanh: "<<dt<<endl;
        }
};
int main(){
    xemay XeMay[10] ;
    for(int i=0;i<10;i++){
        XeMay[i].nhap();
    }
    giabinhquan(XeMay);
    timxe(XeMay);

}
void giabinhquan(xemay a[10]){
    double sum50,sum70,sum110,sum150,sum;
    for(int i=0;i<a.size();i++){
        if(a[i].getdt()==50){
            sum50+=a[i].getgiaxe();
        }
        else if(a[i].getdt()==70){
            sum70+=a[i].getgiaxe();
        }
        else if(a[i].getdt()==110){
            sum110+=a[i].getgiaxe();
        }
        else if(a[i].getdt()==150){
            sum150+=a[i].getgiaxe();
        }

    }
    cout<<"gia binh quan xe dung tich 50: "<<sum50<<endl;
    cout<<"gia binh quan xe dung tich 70: "<<sum70<<endl;
    cout<<"gia binh quan xe dung tich 110: "<<sum110<<endl;
    cout<<"gia binh quan xe dung tich 150: "<<sum150<<endl;
    cout<<"gia binh quan tat ca xe: "<<sum<<endl;
}
void timxe(xemay a[10]){
    double x;
    string hang;
    getline(cin, hang);
    cout<<"nhap gia tien: ";
    cin>>x;
    cout<<endl;
    int dem=0;
    for(int i=0; i<10; i++){
        if(a[i].gethangxe()==hang&&a[i].getgiaxe()==x){
            dem++;
            a[i].in();
        }
    } 
    cout<<"co "<<dem<<" xe thoa man.";
}