#include <iostream>
#include <vector>
using namespace std;
class Polynomial {
private:
    int degree;
    vector<double> coefficients;

public:
    Polynomial() {
        degree = 0;
    }

    void input() {
        cout << "Nhập bậc của đa thức: ";
        cin >> degree;

        cout << "Nhập các hệ số của đa thức (bắt đầu từ hệ số bậc cao nhất):\n";
        for (int i = degree; i >= 0; --i) {
            double coef;
            cout << "Hệ số bậc " << i << ": ";
            cin >> coef;
            coefficients.push_back(coef);
        }
    }

    void print() const {
        cout << "Đa thức: ";
        for (int i = degree; i >= 0; --i) {
            cout << coefficients[i];
            if (i > 0) {
                cout << "x^" << i << " + ";
            }
        }
        cout << endl;
    }

    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        result.degree = max(degree, other.degree);

        for (int i = 0; i <= result.degree; ++i) {
            double coef = (i <= degree ? coefficients[i] : 0) + (i <= other.degree ? other.coefficients[i] : 0);
            result.coefficients.push_back(coef);
        }

        return result;
    }

    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial derivative() const {
        Polynomial result;
        result.degree = max(0, degree - 1);

        for (int i = 1; i <= result.degree + 1; ++i) {
            double coef = coefficients[i] * i;
            result.coefficients.push_back(coef);
        }

        return result;
    }
};

int main() {
    Polynomial P, Q;
    double d;

    cout << "Nhập đa thức P:\n";
    P.input();
    cout << "Nhập đa thức Q:\n";
    Q.input();

    cout << "\nIn đa thức P:\n";
    P.print();
    cout << "\nIn đa thức Q:\n";
    Q.print();

    Polynomial sum = P.add(Q);
    cout << "\nĐa thức P + Q:\n";
    sum.print();

    cout << "\nNhập số thực d để tính P(d) + Q'(d): ";
    cin >> d;

    double result = P.evaluate(d) + Q.derivative().evaluate(d);
    cout << "\nP(" << d << ") + Q'(" << d << ") = " << result << endl;

    return 0;
}
