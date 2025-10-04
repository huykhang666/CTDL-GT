#include <iostream>
using namespace std;

class Diem {
private:
    float toan;
    float ly;
    float hoa;

public:
    Diem(float t = 0, float l = 0, float h = 0);

    Diem operator + (const Diem &d);
    Diem operator / (float n);
    bool operator >= (const Diem &d);

    friend ostream& operator << (ostream &os, const Diem &d);
    friend istream& operator >> (istream &is, Diem &d);
};

Diem::Diem(float t, float l, float h) {
    toan = t;
    ly = l;
    hoa = h;
}

Diem Diem::operator + (const Diem &d) {
    return Diem(toan + d.toan, ly + d.ly, hoa + d.hoa);
}

Diem Diem::operator / (float n) {
    return Diem(toan / n, ly / n, hoa / n);
}

bool Diem::operator >= (const Diem &d) {
    return (toan + ly + hoa) >= (d.toan + d.ly + d.hoa);
}

ostream& operator << (ostream &os, const Diem &d) {
    os << "Toan: " << d.toan << ", Ly: " << d.ly << ", Hoa: " << d.hoa;
    return os;
}

istream& operator >> (istream &is, Diem &d) {
    cout << "Nhap diem Toan: "; is >> d.toan;
    cout << "Nhap diem Ly: "; is >> d.ly;
    cout << "Nhap diem Hoa: "; is >> d.hoa;
    return is;
}

int main() {
    Diem d1, d2;
    cin >> d1;
    cin >> d2;

    Diem tong = d1 + d2;
    cout << tong << endl;

    Diem trungBinh = tong / 2;
    cout << trungBinh << endl;

    if (d1 >= d2)
        cout << "Hoc sinh 1 co tong diem >= hoc sinh 2" << endl;
    else
        cout << "Hoc sinh 1 co tong diem < hoc sinh 2" << endl;

    return 0;
}
