#include<iostream> 
using namespace std;

class A {
    int a1;
    int *a2;
    public:
    void xuat() {
        cout << a1 << " " << *a2 << endl;
    }
    A() {
        cout << "\nham tao k doi";
        a1 = 0;
        a2 = new int ; 
        *a2 = 50;
    }

    A(int x , int y) {
        cout << "\nham tao co doi" << endl;
        a1 = x ;
        a2 = new int ; 
        *a2 = y;
    }

    ~A() {
        if(a2) delete a2;
        cout << "\nhuy" << endl;
    }

    A(const A& ob) {
        cout << "\nham tao sao chep" << endl;
    }

    void operator=(const A& ob) {
        cout << "\ntoan tu gan";
        a1 = ob.a1;
        a2 = new int;
        *a2 = *(ob.a2);
    }
    void biendoi(){
        a1++;
        *(a2)=10000;
    }
};
int main() {
    A ob2(3,-4);
   A ob1; 
   ob1=ob2;
   ob1.xuat();
   ob2.xuat();
   ob2.biendoi();
   cout<<"bien doi: "<<endl;
   ob1.xuat();
   ob2.xuat();
}