#include<iostream>
using namespace std;
class maTran {
	private:
		float a[2][2];
	public:
		maTran();
		friend istream& operator >> (istream &is, maTran &mt);
		friend ostream& operator << (ostream &os, maTran &mt);
		maTran operator + (maTran &mt);
		maTran operator * (maTran &mt);
};

maTran::maTran() {
	for(int i = 0;i<2;i++) {
		for(int j=0;j<2;j++) {
			a[i][j] = 0;
		}
	}
}

istream& operator >> (istream &is, maTran &mt) {
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			cout<<"Nhap a["<<i<<"]"<<"["<<j<<"]: ";
			is>>mt.a[i][j];
		}
	}
	return is;
}

ostream& operator << (ostream &os, maTran &mt) {
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			os<<mt.a[i][j]<<" ";
		}
		os<<endl;
	}
	return os;
}

maTran maTran::operator +(maTran &mt) {
	maTran t;
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			t.a[i][j] = a[i][j] + mt.a[i][j];
		}
	}
	return t;
}

maTran maTran::operator *(maTran &mt) {
	maTran t;
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			t.a[i][j] = 0;
			for(int k=0;k<2;k++) {
				t.a[i][j] += a[i][k] * mt.a[k][j];
			}
		}
	}
	return t;
}

int main() {
	maTran a,b;
	cin>>a>>b;
	maTran tong = a + b;
	maTran tich = a * b;
	cout<<"Ma tran a: \n"<<a;
	cout<<"Ma tran b: \n"<<b;
	cout<<"Tong 2 ma tran la: \n"<<tong;
	cout<<"Tich 2 ma tran la: \n"<<tich;
	return 0;
	
}