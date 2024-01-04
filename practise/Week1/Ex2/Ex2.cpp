#include <iostream>
#include <cmath>
using namespace std;

class Elip {
private:
    double a;
    double b;

public:
    // Constructor
    Elip(double aVal, double bVal) : a(aVal), b(bVal) {}

    // Method to calculate the area of the Elip
    double calcArea() {
        return M_PI * a * b;
    }

    // Method to check if it's a circle (hình tròn)
    bool isCircle() {
        return (a == b);
    }

    // Getters for a and b
    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }
};

int main() {
    int n;
    cout << "Nhap so luong elip: ";
    cin >> n;

    Elip **elips = new Elip *[n]; // Cấp phát bộ nhớ động cho mảng chứa các đối tượng Elip

    // Nhập thông tin về các elip từ người dùng
    for (int i = 0; i < n; ++i) {
        double a, b;
        cout << "Nhap ban kinh a cho elip " << i + 1 << ": ";
        cin >> a;
        cout << "Nhap ban kinh b cho elip " << i + 1 << ": ";
        cin >> b;

        elips[i] = new Elip(a, b); // Tạo đối tượng Elip và lưu trữ trong mảng
    }

    // Xuất thông tin của các elip
    cout << "\nThong tin cac elip:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elip " << i + 1 << ": a = " << elips[i]->getA() << ", b = " << elips[i]->getB() << endl;
    }

    // Tìm elip có diện tích lớn nhất trong các hình tròn
    double maxArea = -1;
    int maxAreaIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (elips[i]->isCircle()) {
            double area = elips[i]->calcArea();
            if (area > maxArea) {
                maxArea = area;
                maxAreaIndex = i;
            }
        }
    }

    // Xuất thông tin về elip có diện tích lớn nhất trong các hình tròn
    if (maxAreaIndex != -1) {
        cout << "\nElip co dien tich lon nhat trong cac hinh tron: Elip " << maxAreaIndex + 1 << endl;
    } else {
        cout << "\nKhong ton tai elip hinh tron.\n";
    }

    // Kiểm tra dãy các elip có tạo thành dãy tăng dần theo a và giảm dần theo b không
    bool increasingA = true;
    bool decreasingB = true;
    for (int i = 1; i < n; ++i) {
        if (elips[i]->getA() <= elips[i - 1]->getA()) {
            increasingA = false;
        }
        if (elips[i]->getB() >= elips[i - 1]->getB()) {
            decreasingB = false;
        }
    }

    if (increasingA && decreasingB) {
        cout << "\nDãy các elip tạo thành dãy tăng dần theo a và giảm dần theo b.\n";
    } else {
        cout << "\nDãy các elip không tạo thành dãy tăng dần theo a và giảm dần theo b.\n";
    }

    // Giải phóng bộ nhớ cấp phát động
    for (int i = 0; i < n; ++i) {
        delete elips[i];
    }
    delete[] elips;

    return 0;
}
