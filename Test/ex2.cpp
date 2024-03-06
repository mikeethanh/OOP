#include<iostream>
using namespace std;

class fraction {
private:
    int numerator;
    int denominator;

public:
    fraction() {
        numerator = 0;
        denominator = 1;
    }

    fraction(const fraction& other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    int ucln(int num, int denom) {
        while (denom != 0) {
            int temp = denom;
            denom = num % denom;
            num = temp;
        }
        return num;
    }

    void compact() {
        int commonFactor = ucln(numerator, denominator);
        numerator /= commonFactor;
        denominator /= commonFactor;
    }

    // Input and output operators
    friend ostream& operator<<(ostream& out, const fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    friend istream& operator>>(istream& in, fraction& f) {
        cout << "Nhap tu so: ";
        in >> f.numerator;
        cout << "Nhap mau so: ";
        in >> f.denominator;
        f.compact();
        return in;
    }

    // Addition operator
    fraction operator+(const fraction& other) const {
        fraction result;
        result.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
        result.denominator = this->denominator * other.denominator;
        result.compact();
        return result;
    }

    // Subtraction operator
    fraction operator-(const fraction& other) const {
        fraction result;
        result.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
        result.denominator = this->denominator * other.denominator;
        result.compact();
        return result;
    }

    // Multiplication operator
    fraction operator*(const fraction& other) const {
        fraction result;
        result.numerator = this->numerator * other.numerator;
        result.denominator = this->denominator * other.denominator;
        result.compact();
        return result;
    }

    // Division operator
    fraction operator/(const fraction& other) const {
        fraction result;
        result.numerator = this->numerator * other.denominator;
        result.denominator = this->denominator * other.numerator;
        result.compact();
        return result;
    }
};

int main() {
    fraction p1, p2, p3, p4;

    // Input values for p1, p2, p3, and p4
    cout << "Nhap gia tri cho p1: ";
    cin >> p1;

    cout << "Nhap gia tri cho p2: ";
    cin >> p2;

    cout << "Nhap gia tri cho p3: ";
    cin >> p3;

    cout << "Nhap gia tri cho p4: ";
    cin >> p4;

    // Calculate the expression: (p1 + p2) / (p3 + p4) * p1
    fraction sum_p1_p2 = p1 + p2;
    fraction sum_p3_p4 = p3 + p4;
    fraction result = sum_p1_p2 / sum_p3_p4 * p1;

    // Display the result
    cout << "Gia tri bieu thuc (p1 + p2)/(p3 + p4) * p1 la: " << result << endl;

    return 0;
}
