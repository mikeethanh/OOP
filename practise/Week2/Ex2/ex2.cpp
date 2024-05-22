#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
class Polynomial {
private:
    int degree;
    vector<double> coefficients;

public:
    // constructor
    Polynomial() {
        degree = 0;
    }
    // hsm nhap
    void input() {
        cout << "Nhap bac cua da thuc"; // nhap vao bac 
        cin >> degree;

        cout << "NHap he so cua da thuc:\n";
        for (int i = degree; i >= 0; --i) {
            double coef;
            cout << "he so bac" << i << ": "; // nha nhap vao he so
            cin >> coef;
            coefficients.push_back(coef);
        }
    }

    void print() const {
        cout << "Da thuc: ";
        for (int i = degree; i >= 0; --i) {
            cout << coefficients[i];
            if (i > 0) {
                cout << "x^" << i << " + ";
            }
        }
        cout << endl;
    }
    

     double evaluate(double x) {
        double result = 0.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    double sub(const Polynomial& other,int x) {
        Polynomial result; // luu da thuc sau khi tru
        double res = 0.02; // luu ket qua 
        result.degree = max(degree, other.degree);

        for (int i = 0; i <= result.degree; ++i) {
            double coef = (i <= degree ? coefficients[i] : 0) - (i <= other.degree ? other.coefficients[i] : 0);
            result.coefficients.push_back(coef);
        }

        for (int i = 0; i <= result.degree; ++i) {
            res += result.coefficients[i] * pow(x, i);
        }
        return res;
    }

   
};

int main() {
    Polynomial P, Q;
    double d;

    cout << "Nhap da thuc P:\n";
    P.input();
    cout << "Nhap da thuc Q:\n";
    Q.input();

    cout << "\nIn da thuc P:\n";
    P.print();
    cout << "\nIn dad thuc Q:\n";
    Q.print();

    double res = P.sub(Q,5);
    cout << "\nda thuc P - Q:\n";
    cout << res;
    

}
