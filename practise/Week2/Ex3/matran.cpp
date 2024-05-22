#include<iostream> 
using namespace std;

class matrix {
    private:
    int **a;
    int n;
    public:
    
    //constructor:
     matrix(int size) {
        n = size;
        a = new int*[n];
        for (int i = 0; i < n; ++i) {
            a[i] = new int[n];
        }
    }
    //methods:
    void input() {
        cout << "Enter the elements of the matrix: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    void sumOfElem() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum = sum + a[i][j];
            }
        }
        cout << "The sum of the elements of the matrix is: " << sum << endl;
    }

    void maxElem() {
        int max = a[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > max) {
                    max = a[i][j];
                }
            }
        }
        cout << "The maximum element of the matrix is: " << max << endl;
    }

    void minElme() {
        int min = a[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < min) {
                    min = a[i][j];
                }
            }
        }
        cout << "The minimum element of the matrix is: " << min << endl;
    }

    // nhap x dem so phan tu ben tren duong cheo chinh
    int countX(int x) {
        int count = 0 ; 
        for(int i = 0 ; i < n ; i++) {
            for(int j = i; j < n-i ; j++) {
                if(a[i][j] > x) {
                    count++;
                }
            }
        }
        return count;
    }

    //mul 2 ma tran
    matrix mulMatrix(const matrix& other) {
        matrix res(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < n; k++){
                    res.a[i][j] += a[i][k] * other.a[k][j];
                }
            }
        }
        return res;
    }
};

int main() {
    int size;
    cout << "Enter the size of the matrix: " << endl;
    cin >> size;
    matrix a(size) ;
    a.input();
    a.print();
    a.sumOfElem();
    a.maxElem();
    a.minElme();
    a.countX(3);
    matrix b(size);
    b.input();
    b.print();
    a.mulMatrix(b).print();
}