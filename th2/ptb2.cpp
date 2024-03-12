#include <iostream>
#include <cmath> // For sqrt function
using namespace std;

class ptb2 {
private:
    double a, b, c;

public:
    // Constructor with default values
    ptb2(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}

    // Friend function to overload operator<<
    friend ostream& operator<<(ostream& out, const ptb2& pt) {
        out << "a: " << pt.a << ", b: " << pt.b << ", c: " << pt.c;
        return out;
    }

    // Friend function to solve the quadratic equation
    friend void tinhptb2(const ptb2& pt) {
        double delta = pt.b * pt.b - 4 * pt.a * pt.c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem";
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep: x = " << -pt.b / (2 * pt.a);
        } else {
            double x1 = (-pt.b + sqrt(delta)) / (2 * pt.a);
            double x2 = (-pt.b - sqrt(delta)) / (2 * pt.a);
            cout << "Phuong trinh co 2 nghiem phan biet: x1 = " << x1 << ", x2 = " << x2;
        }
    }
};

int main() {
    ptb2 p1(1, 2, 3);
    ptb2 p2(2, 3, 4);
    ptb2 p3(4, 5, 6);

    cout << "Phuong trinh p1: " << p1 << endl;
    tinhptb2(p1);
    cout << endl;

    cout << "Phuong trinh p2: " << p2 << endl;
    tinhptb2(p2);
    cout << endl;

    cout << "Phuong trinh p3: " << p3 << endl;
    tinhptb2(p3);
    cout << endl;

    return 0;
}
