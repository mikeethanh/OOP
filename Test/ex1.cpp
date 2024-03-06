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

    // Getter, setter
    int getNumerator() const {
        return this->numerator;
    }

    int getDenominator() const {
        return this->denominator;
    }

    void setNumerator(int numerator) {
        this->numerator = numerator;
    }

    void setDenominator(int denominator) {
        this->denominator = denominator;
    }

    void compact() {
        int commonFactor = ucln(this->numerator, this->denominator);
        this->numerator /= commonFactor;
        this->denominator /= commonFactor;
    }

    void input() {
        int x, y;
        cout << "nhap tu so: ";
        cin >> x;
        cout << "nhap mau so: ";
        cin >> y;
        setNumerator(x);
        setDenominator(y);
        compact();
    }

    void print() const {
        cout << "phan so : " << this->numerator << "/" << this->denominator << endl;
    }

    fraction sum(const fraction& other) const {
        fraction result;
        result.setDenominator(this->denominator * other.getDenominator());
        result.setNumerator(this->numerator * other.getDenominator() + other.getNumerator() * this->denominator);
        return result;
    }

    fraction subtraction(const fraction& other) const {
        fraction result;
        result.setNumerator(this->numerator * other.getDenominator() - other.getNumerator() * this->denominator);
        result.setDenominator(this->denominator * other.getDenominator());
        return result;
    }
};

int main() {
    fraction p1, p2, p3, p4;

    p1.input();
    p2.input();
    p3.input();
    p4.input();

    // Example of using the sum and print methods
    fraction sumResult = p1.sum(p2);
    cout << "Tong cua p1 va p2 la: ";
    sumResult.print();

    return 0;
}
