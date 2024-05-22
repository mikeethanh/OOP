#include<iostream>
#include<vector>
#include<algorithm> // for std::min
using namespace std;

class MaTran {
private:
    int n; // cấp của ma trận
    vector<vector<int>> tp; // vector chứa các phần tử của ma trận

public:
    // Hàm tạo không tham số
    MaTran() {
        n = 0;
    }

    // Hàm hủy
    ~MaTran() {}

    // Hàm nhập ma trận
    void nhapMaTran() {
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

    // Hàm in ma trận
    void inMaTran() const {
        cout << "Ma tran:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << tp[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Hàm tính tổng các phần tử của ma trận
    friend int tongCacPhanTu(const MaTran& mt);

    // Hàm tìm giá trị nhỏ nhất của ma trận
    friend int giaTriNhoNhat(const MaTran& mt);
};

int tongCacPhanTu(const MaTran& mt) {
    int sum = 0;
    for (int i = 0; i < mt.n; ++i) {
        for (int j = 0; j < mt.n; ++j) {
            sum += mt.tp[i][j];
        }
    }
    return sum;
}

int giaTriNhoNhat(const MaTran& mt) {
    int minValue = mt.tp[0][0];
    for (int i = 0; i < mt.n; ++i) {
        for (int j = 0; j < mt.n; ++j) {
            minValue = min(minValue, mt.tp[i][j]);
        }
    }
    return minValue;
}

int main() {
    // Nhập ma trận
    MaTran mt;
    mt.nhapMaTran();

    // In ma trận
    mt.inMaTran();

    // Tính tổng các phần tử của ma trận
    int sum = tongCacPhanTu(mt);
    cout << "Tong cac phan tu cua ma tran la: " << sum << endl;

    // Tìm giá trị nhỏ nhất của ma trận
    int minValue = giaTriNhoNhat(mt);
    cout << "Gia tri nho nhat cua ma tran la: " << minValue << endl;

    return 0;
}
