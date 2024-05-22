#include<iostream> 
using namespace std;

class hcn {
    private:
        int a;
        int b;
    public:
        hcn(int a, int b) : a(a), b(b){};
        int Shcn1();
        friend int Shcn2(const hcn&);
};

int hcn::Shcn1() {
    int res = a * b; 
    return res;
}

int Shcn2(const hcn& x) {
    int res = x.a * x.b;  
    return res;
}

int main() {
    hcn a(3,4);
    
    int res1 = a.Shcn1();
    cout << res1 << endl;

    int res2 = Shcn2(a);
    cout << res2 << endl;

    return 0;
}
