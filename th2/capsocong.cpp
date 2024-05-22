#include<bits/stdc++.h>
using namespace std;

class dayNguyen{
	int n;
	double *a;
public:
	friend void nhap(dayNguyen &p){
		cin>>p.n;
		p.a = new double[p.n];
		for(int i=0;i<p.n;i++) cin>>p.a[i];
	}
	friend ostream& operator << (ostream &out, const dayNguyen &p){
		for(int i=0;i<p.n;i++) out<<p.a[i]<<" ";
		return out;
	}
	friend void thongKe(dayNguyen p){
		int count = 0;
		for(int i=0;i<p.n;i++){
			if(p.a[i] + p.a[i+2] == 2*p.a[i+1]){
				count++;
			}
		}
		cout<<count;
	} 
};

int main()
{
	dayNguyen A;
	nhap(A);
	cout<<A<<endl;
	thongKe(A);
}

