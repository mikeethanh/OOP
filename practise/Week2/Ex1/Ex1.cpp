#include<iostream> 
using namespace std;

class bike {
    private: 
        string hangXe; 
        string height; 
        string type;
        string prices;
        int rate ;
    public: 
    void input();
    void print();
    string gethangXe();
    string getheight();
    string getype();
    string getprices();
    int getType();
};

void bike:: input() {
    cout << "Nhap hang xe";
    getline(cin,this->hangXe);
    cout << "nhap height" ; 
    getline(cin,this->height); 
    cout << "nhap type" ; 
    getline(cin,this->type);
    cout << "nhap price" ; 
    getline(cin,this->prices);
    cout << "nhap rate" ; 
    cin >> this->rate;
}

void bike:: print() {
    cout << this->hangXe << endl;
    cout << this->height << endl;
    cout << this->type << endl;
    cout << this->prices << endl;
    cout << this->rate << endl;
}

string bike::gethangXe() {
    return this->hangXe;
}

string bike::getheight() {
    return this->height;
}

string bike::getype() {
    return this->type;
}

string bike::getprices() {
    return this->prices;
}

int bike::getType() {
    return this->rate;
}

int main() {
    //bike bike1 ;
    //bike1.input();
    //bike1.print();

    //su dung con tro doi tuong 
    bike *bike2 = new bike; 
    bike2->input();
    bike2->print();

    delete bike2;
}