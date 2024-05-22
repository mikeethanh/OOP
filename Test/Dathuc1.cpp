#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm> // Include algorithm for std::max
using namespace std;

class Dathuc {
private:
    int bac;
    vector<double> hs; // vector chứa các hệ số của đa thức

public:
    // Hàm tạo không tham số
    Dathuc() {
        bac = 0;
        hs.push_back(0);
    }

    // Hàm tạo có tham số
    Dathuc(int b, vector<double> h) : bac(b), hs(h) {}

    // Hàm hủy
    ~Dathuc() {}

    // Hàm nhập đa thức
    void nhapDaThuc() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;

        hs.resize(bac + 1);

        cout << "Nhap cac he so cua da thuc:\n";
        for (int i = 0; i <= bac; ++i) {
            cout << "Nhap he so bac " << i << ": ";
            cin >> hs[i];
        }
    }

    // Hàm in đa thức
    void inDaThuc() const {
        cout << "Da thuc: ";
        for (int i = bac; i >= 0; --i) {
            if (hs[i] != 0) {
                if (i < bac) {
                    cout << (hs[i] > 0 ? " + " : " - ");
                }
                if (i == 0 || (i > 0 && hs[i] != 1 && hs[i] != -1)) {
                    cout << abs(hs[i]);
                }
                if (i > 0) {
                    cout << "x";
                }
                if (i > 1) {
                    cout << "^" << i;
                }
            }
        }
        cout << endl;
    }

    // Tính giá trị đa thức tại x0
    double tinhDaThucTai(double x0) const {
        double result = 0;
        double x_pow = 1;

        for (int i = 0; i <= bac; ++i) {
            result += hs[i] * x_pow;
            x_pow *= x0;
        }

        return result;
    }

    // Hàm cộng 2 đa thức
    Dathuc operator+(const Dathuc& other) const {
        int max_bac = max(bac, other.bac);
        vector<double> result_hs(max_bac + 1, 0);

        for (int i = 0; i <= max_bac; ++i) {
            if (i <= bac) result_hs[i] += hs[i];
            if (i <= other.bac) result_hs[i] += other.hs[i];
        }

        return Dathuc(max_bac, result_hs);
    }

    friend Dathuc operator-(const Dathuc& dt1, const Dathuc& dt2);
};

// Định nghĩa hàm friend cho toán tử trừ hai đa thức
Dathuc operator-(const Dathuc& dt1, const Dathuc& dt2) {
    int max_bac = max(dt1.bac, dt2.bac);
    vector<double> result_hs(max_bac + 1, 0);

    for (int i = 0; i <= max_bac; ++i) {
        if (i <= dt1.bac) result_hs[i] += dt1.hs[i];
        if (i <= dt2.bac) result_hs[i] -= dt2.hs[i];
    }

    return Dathuc(max_bac, result_hs);
}

int main() {
    // Nhập đa thức P, Q
    Dathuc P, Q;
    cout << "Nhap da thuc P:\n";
    P.nhapDaThuc();
    cout << "Nhap da thuc Q:\n";
    Q.nhapDaThuc();

    // In đa thức P, Q, P+Q, P-Q
    cout << "In da thuc P:\n";
    P.inDaThuc();
    cout << "In da thuc Q:\n";
    Q.inDaThuc();
    cout << "In da thuc P+Q:\n";
    (P + Q).inDaThuc();
    cout << "In da thuc P-Q:\n";
    (P - Q).inDaThuc();

    // Nhập d1, d2 và tính biểu thức S
    double d1, d2;
    cout << "Nhap d1: ";
    cin >> d1;
    cout << "Nhap d2: ";
    cin >> d2;

    // Tính biểu thức S = 1 / (P(d1) - Q(d2))
    double result_S = 1 / (P.tinhDaThucTai(d1) - Q.tinhDaThucTai(d2));

    // Hiển thị kết quả
    cout << "Gia tri bieu thuc S = 1 / (P(d1) - Q(d2)) la: " << result_S << endl;

    return 0;
}
