#include <iostream>

class Polynomial {
private:
    int n;      // Bậc của đa thức
    float *hs;  // Mảng các hệ số của đa thức

public:
    // Hàm tạo
    Polynomial(int degree = 0) {
        n = degree;
        hs = new float[n + 1];
        for (int i = 0; i <= n; ++i) {
            hs[i] = 0.0f;
        }
    }

    // Hàm hủy
    ~Polynomial() {
        delete[] hs;
    }

    // Hàm tạo sao chép
    Polynomial(const Polynomial& other) {
        n = other.n;
        hs = new float[n + 1];
        for (int i = 0; i <= n; ++i) {
            hs[i] = other.hs[i];
        }
    }

    // Phương thức toán tử gán
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] hs;
            n = other.n;
            hs = new float[n + 1];
            for (int i = 0; i <= n; ++i) {
                hs[i] = other.hs[i];
            }
        }
        return *this;
    }

    // Hàm nhập đa thức
    void inputPolynomial() {
        std::cout << "Nhập bậc của đa thức: ";
        std::cin >> n;
        hs = new float[n + 1];
        std::cout << "Nhập các hệ số của đa thức:\n";
        for (int i = 0; i <= n; ++i) {
            std::cout << "Hệ số của x^" << i << ": ";
            std::cin >> hs[i];
        }
    }

    // Phương thức toán tử cộng 2 đa thức
    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = std::max(n, other.n);
        Polynomial result(maxDegree);
        for (int i = 0; i <= maxDegree; ++i) {
            if (i <= n) {
                result.hs[i] += hs[i];
            }
            if (i <= other.n) {
                result.hs[i] += other.hs[i];
            }
        }
        return result;
    }

    // Hàm bạn tính giá trị của đa thức tại d
    float evaluate(float d) const {
        float value = 0.0f;
        for (int i = 0; i <= n; ++i) {
            value += hs[i] * pow(d, i);
        }
        return value;
    }
};

int main() {
    Polynomial P, Q;
    float d;
    
    std::cout << "Nhập đa thức P:\n";
    P.inputPolynomial();
    std::cout << "Nhập đa thức Q:\n";
    Q.inputPolynomial();
    std::cout << "Nhập số thực d: ";
    std::cin >> d;

    Polynomial sum = P + Q;
    float result = sum.evaluate(d);

    std::cout << "Tổng của P và Q là:\n";
    // In ra đa thức tổng sum nếu cần
    std::cout << "Giá trị của (P+Q)(" << d << ") là: " << result << std::endl;

    return 0;
}