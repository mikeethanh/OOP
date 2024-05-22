#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class MaTran {
private:
    int cap;
    vector<vector<int>> maTran;

public:
    // Constructor
    MaTran(int cap) : cap(cap) {
        maTran.resize(cap, vector<int>(cap));
    }

     // Hàm tạo mặc định: nhập ma trận vuông từ bàn phím
    MaTran() {
        cout << "Nhap cap cua ma tran: ";
        cin >> n;

        tp.resize(n, vector<int>(n));

        cout << "Nhap cac phan tu cua ma tran:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "Nhap phan tu thu [" << i << "][" << j << "]: ";
                cin >> tp[i][j];
            }
        }
    }

    // Overload input and output operators
    friend istream& operator>>(istream& in, MaTran& mat) {
        cout << "Nhập các phần tử của ma trận:\n";
        for (int i = 0; i < mat.cap; ++i) {
            for (int j = 0; j < mat.cap; ++j) {
                cout << "Nhập phần tử thứ [" << i << "][" << j << "]: ";
                in >> mat.maTran[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const MaTran& mat) {
        out << "Ma trận:\n";
        for (int i = 0; i < mat.cap; ++i) {
            for (int j = 0; j < mat.cap; ++j) {
                out << mat.maTran[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // Tìm giá trị lớn nhất trong ma trận
    int timGiaTriLonNhat() const {
        int maxVal = maTran[0][0];
        for (int i = 0; i < cap; ++i) {
            for (int j = 0; j < cap; ++j) {
                if (maTran[i][j] > maxVal) {
                    maxVal = maTran[i][j];
                }
            }
        }
        return maxVal;
    }

    // Tính trung bình cộng các phần tử lẻ nằm phía trên đường chéo chính
    double tinhTrungBinhLeTrenCheoChinh() const {
        int dem = 0;
        int tong = 0;
        for (int i = 0; i < cap; ++i) {
            for (int j = i + 1; j < cap; ++j) {
                if (maTran[i][j] % 2 != 0) {
                    ++dem;
                    tong += maTran[i][j];
                }
            }
        }
        if (dem == 0) return 0; // Tránh chia cho không
        return static_cast<double>(tong) / dem;
    }
};

int main() {
    int cap;
    cout << "Nhập cấp của ma trận vuông: ";
    cin >> cap;

    // Tạo ma trận A
    MaTran A(cap);
    cout << "Nhập ma trận A:\n";
    cin >> A;

    // Tạo ma trận B
    MaTran B(cap);
    cout << "Nhập ma trận B:\n";
    cin >> B;

    // In ma trận A và B
    cout << "Ma trận A:\n" << A;
    cout << "Ma trận B:\n" << B;

    // Tính giá trị lớn nhất của ma trận A và B
    int maxA = A.timGiaTriLonNhat();
    int maxB = B.timGiaTriLonNhat();
    cout << "Giá trị lớn nhất của ma trận A: " << maxA << endl;
    cout << "Giá trị lớn nhất của ma trận B: " << maxB << endl;

    // Tính biểu thức 23122021 / (MaxA + MaxB)
    double bieuThuc1 = 23122021.0 / (maxA + maxB);
    cout << "Giá trị biểu thức 23122021 / (MaxA + MaxB) là: " << bieuThuc1 << endl;

    // Tính trung bình cộng các phần tử lẻ nằm phía trên đường chéo chính của ma trận A và B
    double tbA = A.tinhTrungBinhLeTrenCheoChinh();
    double tbB = B.tinhTrungBinhLeTrenCheoChinh();
    cout << "Trung bình cộng các phần tử lẻ phía trên đường chéo chính của ma trận A: " << tbA << endl;
    cout << "Trung bình cộng các phần tử lẻ phía trên đường chéo chính của ma trận B: " << tbB << endl;

    // Tính căn bậc 2 của (tbA - tbB)
    double ketQua = sqrt(abs(tbA - tbB));
    cout << "Căn bậc hai của (tbA - tbB) là: " << ketQua << endl;

    return 0;
}
