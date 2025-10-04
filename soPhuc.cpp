#include<iostream>
using namespace std;

class soPhuc {
	private:
		float thuc,ao;
	public:
		friend istream& operator >> (istream &is, soPhuc &sp);
		friend ostream& operator << (ostream &os, soPhuc &sp);
		soPhuc();
		soPhuc operator + (soPhuc &sp);
		soPhuc operator - (soPhuc &sp);
		soPhuc operator * (soPhuc &sp);
		soPhuc operator / (soPhuc &sp);
};

istream& operator >> (istream &is, soPhuc &sp) {
	cout<<"Nhap thuc: "; is>>sp.thuc;
	cout<<"Nhap ao: "; is>>sp.ao;
	return is;
}

ostream& operator << (ostream &os, soPhuc &sp) {
	os<<sp.thuc<<" + "<<sp.ao<<"i";
	return os;
}

soPhuc::soPhuc() {
	thuc = 0;
	ao = 0;
}

soPhuc soPhuc::operator +(soPhuc &sp) {
	soPhuc t;
	t.thuc = this->thuc + sp.thuc;
	t.ao = this->ao + sp.ao;
	return t;
}

soPhuc soPhuc::operator -(soPhuc &sp) {
	soPhuc t;
	t.thuc = this->thuc - sp.thuc;
	t.ao = this->ao - sp.ao;
	return t;
}

soPhuc soPhuc::operator *(soPhuc &sp) {
	soPhuc t;
	t.thuc = this->thuc * sp.thuc - this->ao * sp.ao;
	t.ao = this->thuc * sp.ao + this->ao * sp.thuc;
	return t;
}

soPhuc soPhuc::operator /(soPhuc &sp) {
	soPhuc t;
	float mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
	if(mau == 0) {
		cout<<"Loi: chia cho 0\n";
		return soPhuc();
	}
	t.thuc = (this->thuc * sp.thuc + this->ao * sp.ao) / mau;
	t.ao = (this->thuc * sp.ao - this->ao * sp.thuc) / mau;
	return t;
}

int main() {
	soPhuc a,b,tong,hieu,tich,thuong;
	cin>>a>>b;
	tong = a + b;
	hieu = a - b;
	tich = a * b;
	thuong = a / b;
	cout<<"Tong hai so phuc la: "<<tong<<endl;
	cout<<"Hieu hai so phuc la: "<<hieu<<endl;
	cout<<"Tich hai so phuc la: "<<tich<<endl;
	cout<<"Thuong hai so phuc la: "<<thuong<<endl;
	return 0;
}