#include<iostream>
using namespace std;

class Vector {
public: 
    int dim;  // số chiều
    float *elem;
    friend istream& operator>>(istream&, Vector&);
    friend ostream& operator<<(ostream&, const Vector&);
    float operator*(const Vector&);
    Vector operator*(const int&);
    Vector operator+(const Vector&);
};

istream& operator>>(istream& is, Vector& v) {
    cout << "Nhap so chieu: ";
    is >> v.dim;
    v.elem = new float[v.dim];
    for (int i = 0; i < v.dim; i++) {
        cout << "Nhap tp thu " << i + 1 << ": ";
        is >> v.elem[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Vector& x) {
    os << "(";
    for (int i = 0; i < x.dim - 1; i++) {
        os << x.elem[i] << ",";
    }
    os << x.elem[x.dim - 1] << ")";
    return os;
}

float Vector::operator*(const Vector& v) {
    float s = 0;
    int min_dim = (dim < v.dim) ? dim : v.dim;
    for (int i = 0; i < min_dim; i++) {
        s += elem[i] * v.elem[i];
    }
    return s;
}

Vector Vector::operator*(const int& k) {
    Vector result;
    result.dim = dim;
    result.elem = new float[dim];
    for (int i = 0; i < dim; i++) {
        result.elem[i] = elem[i] * k;
    }
    return result;
}

Vector Vector::operator+(const Vector& v) {
    Vector result;
    int min_dim = (dim < v.dim) ? dim : v.dim;
    int max_dim = (dim > v.dim) ? dim : v.dim;
    result.dim = max_dim;
    result.elem = new float[max_dim];
    for (int i = 0; i < min_dim; i++) {
        result.elem[i] = elem[i] + v.elem[i];
    }
    for (int i = min_dim; i < max_dim; i++) {
        if (max_dim == dim) {
            result.elem[i] = elem[i];
        } else {
            result.elem[i] = v.elem[i];
        }
    }
    return result;
}

int main() {
    Vector u, v, t;
    int k;
    cin >> u >> v >> t;
    cout << u << endl << v << endl << t << endl;
    cout << "u + v: " << u + v << endl;
    cout << "u * v: " << t * v << endl;
    cout << "Nhap nguyen K";
    cin >> k;
    cout << "u * k: " << u * k << endl;
    return 0;
}
