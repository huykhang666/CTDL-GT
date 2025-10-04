#include <iostream>
#include <cmath>
using namespace std;

class phanSo {
private:
    int tu, mau;

    void rutGon() {
        if(tu == 0) {
            mau = 1;
            return;
        }
        int a = abs(tu);
        int b = abs(mau);
        while(a != b) {
            if(a > b) a -= b;
            else b -= a;
        }
        int u = a;
        tu /= u;
        mau /= u;
        if(mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

public:
    phanSo(int t = 0, int m = 1);

    friend istream& operator >> (istream &is, phanSo &ps);
    friend ostream& operator << (ostream &os, const phanSo &ps);

    phanSo operator + (const phanSo &ps);
    phanSo operator - (const phanSo &ps);
    phanSo operator * (const phanSo &ps);
    phanSo operator / (const phanSo &ps);
    bool operator == (const phanSo &ps);
};

phanSo::phanSo(int t, int m) {
    tu = t;
    mau = m;
    rutGon();
}

istream& operator >> (istream &is, phanSo &ps) {
    cout << "Nhap tu: "; is >> ps.tu;
    do {
        cout << "Nhap mau: "; is >> ps.mau;
        if(ps.mau == 0) cout << "Mau so phai khac 0!\n";
    } while(ps.mau == 0);
    ps.rutGon();
    return is;
}

ostream& operator << (ostream &os, const phanSo &ps) {
	if(ps.mau == 1) {
		os << ps.tu;
	}else {
		os << ps.tu << " / " << ps.mau;
	}
  
    return os;
}

phanSo phanSo::operator + (const phanSo &ps) {
    phanSo t(tu * ps.mau + mau * ps.tu, mau * ps.mau);
    t.rutGon();
    return t;
}

phanSo phanSo::operator - (const phanSo &ps) {
    phanSo t(tu * ps.mau - mau * ps.tu, mau * ps.mau);
    t.rutGon();
    return t;
}

phanSo phanSo::operator * (const phanSo &ps) {
    phanSo t(tu * ps.tu, mau * ps.mau);
    t.rutGon();
    return t;
}

phanSo phanSo::operator / (const phanSo &ps) {
    if(ps.tu == 0) {
        cout << "Loi: chia cho 0!\n";
        return phanSo(0,1);
    }
    phanSo t(tu * ps.mau, mau * ps.tu);
    t.rutGon();
    return t;
}

bool phanSo::operator == (const phanSo &ps) {
    return tu * ps.mau == mau * ps.tu;
}

int main() {
    phanSo a, b, tong, hieu, tich, thuong;
    cin >> a >> b;

    tong = a + b;
    hieu = a - b;
    tich = a * b;
    thuong = a / b;

    cout << "Phan so a: " << a << endl;
    cout << "Phan so b: " << b << endl;
    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    cout << "Thuong: " << thuong << endl;

    if(a == b) cout << "Hai phan so bang nhau";
    else cout << "Hai phan so khac nhau";

    return 0;
}
