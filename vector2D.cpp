#include<iostream>
using namespace std;

class Vector {
	private:
		float x,y;
	public:
		Vector(float x = 0, float y = 0);
		friend istream& operator >> (istream &is, Vector &vt);
		friend ostream& operator << (ostream &os, Vector &vt);
		Vector operator + (Vector &vt);
		Vector operator - (Vector &vt);
		float operator * (Vector &vt);
		bool operator == (Vector &vt);
};

Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
}

istream& operator >> (istream &is, Vector &vt) {
	cout<<"Nhap x: "; is>>vt.x;
	cout<<"Nhap y: "; is>>vt.y;
	return is;
}

ostream& operator << (ostream &os, Vector &vt) {
	os<<"("<<vt.x<<" , "<<vt.y<<")";
	return os;
}

Vector Vector::operator +(Vector &vt)  {
	return Vector(x + vt.x, y + vt.y);
}

Vector Vector::operator -(Vector &vt)  {
	return Vector(x - vt.x, y - vt.y);
}

float Vector::operator *(Vector &vt)  {
	return x * vt.x + y * vt.y;
}

bool Vector::operator ==(Vector &vt)  {
	return x == vt.x && y == vt.y;
}

int main() {
	Vector v1,v2;
	cout<<"Nhap vector v1: \n"; cin>> v1;
	cout<<"Nhap vector v2: \n"; cin>> v2;
	
	Vector tong = v1 + v2;
	cout<<"v1 + v2 = "<<tong<<endl;
	
	Vector hieu = v1 - v2;
	cout<<"v1 - v2 = "<<hieu<<endl;
	
	Vector tichVoHuong = v1 * v2;
	cout<<"v1 * v2 = "<<tichVoHuong<<endl;
	
	bool bangNhau = (v1 == v2);
	cout << "v1 " << (bangNhau ? "bang" : "khong bang") << " v2" << endl;

}