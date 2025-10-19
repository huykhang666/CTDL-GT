#include<iostream>
using namespace std;

class maTran {
	private:
		int **data, dong, cot;
	public:
		maTran();
		maTran(int dong, int cot);
		maTran(const maTran &mt);
		~maTran();
		void nhap();
		void xuat();
		bool laMaTranVuong();
		bool laMaTranDoiXung();
		int dinhThuc();
		maTran operator + (const maTran &mt);
		maTran operator - (const maTran &mt);
		maTran operator * (const maTran &mt);
		bool operator == (const maTran &mt);
		maTran operator = (const maTran &mt);
};

maTran::maTran() : dong(0), cot(0), data(NULL) {}

maTran::maTran(int dong, int cot) {
	this->dong = dong;
	this->cot = cot;
	
	data = new int*[dong];
	for(int i = 0; i < this->dong;i++) {
		data[i] = new int[cot];
		for(int j=0; j < this->cot;j++) {
			data[i][j] = 0;
		}
	}
}

maTran::maTran(const maTran &mt) {
	dong = mt.dong;
	cot = mt.cot;
	
	data = new int*[dong];
	
	for(int i=0;i<dong;i++) {
		data[i] = new int[cot];
		for(int j=0;j<cot;j++) {
			data[i][j] = mt.data[i][j];
		}
	}
}

maTran::~maTran() {
	for(int i=0;i < dong;i++) {
		delete [] data[i];
	}
	delete [] data;
	
	cout<<"Da huy ma tran"<<endl;
}

void maTran::nhap() {
	for(int i=0;i<dong;i++) {
		for(int j=0;j<cot;j++) {
			cout<<"data["<<i<<"]["<<j<<"]: ";
			cin>>data[i][j];
		}
	}	
}

void maTran::xuat() {
	for(int i=0;i<dong;i++) {
		for(int j=0;j<cot;j++) {
			cout<<data[i][j]<<"  ";
		}
		cout<<endl;
	}	
}

bool maTran::laMaTranVuong() {
	return this->dong == this->cot;
}

bool maTran::laMaTranDoiXung() {
	if(! maTran::laMaTranVuong()) return false;
	
	for(int i=0;i<dong;i++) {
		for(int j=i+1;j<cot;j++) {
			if(data[i][j] != data[j][i]) {
				return false;
			}
		}
	}
	return true;
}

int maTran::dinhThuc() {
	if (dong != cot) {
        throw std::invalid_argument("Chi tinh dinh thuc cho ma tran vuong");
    }
	
	if(dong == 1) return data[0][0];
	
	if(dong == 2) return data[0][0]*data[1][1] - data[0][1]*data[1][0];
	
	int det = 0;
	for (int j = 0; j < cot; j++) {
        maTran minorMat(dong - 1, cot - 1);
        for (int r = 1; r < dong; r++) {
            int cIndex = 0;
            for (int c = 0; c < cot; c++) {
                if (c == j) continue; 
                minorMat.data[r - 1][cIndex] = data[r][c];
                cIndex++;
            }
        }
        det += ((j % 2 == 0 ? 1 : -1) * data[0][j] * minorMat.dinhThuc());
    }
}

maTran maTran::operator +(const maTran &mt) {
	if(dong != mt.dong || cot != mt.cot) {
    	throw std::invalid_argument("Kích thước ma trận không khớp");
	}
	
	maTran sum(dong,cot);
	for(int i=0;i<dong;i++) {
		for(int j=0;j<cot;j++) {
			sum.data[i][j] = data[i][j] + mt.data[i][j]; 
		}
	}
	return sum;
}

maTran maTran::operator -(const maTran &mt) {
	if(cot != mt.dong) {
    	throw std::invalid_argument("Kích thước ma trận không khớp");
	}
	
	maTran sum(dong,cot);
	for(int i=0;i<dong;i++) {
		for(int j=0;j<cot;j++) {
			sum.data[i][j] = data[i][j] - mt.data[i][j];
		}
	}
	return sum;
}

maTran maTran::operator *(const maTran &mt) {
	if(dong != mt.dong || cot != mt.cot) {
    	throw std::invalid_argument("Kích thước ma trận không khớp");
	}
	
	maTran tich(dong,mt.cot);
	for(int i=0;i<dong;i++) {
		for(int j=0;j<mt.cot;j++) {
			tich.data[i][j] = 0;
			for(int k=0;k<cot;k++) {
				tich.data[i][j] += data[i][k] * mt.data[k][j];
			}
		}
	}
	return tich;
}

maTran maTran::operator =(const maTran &mt) {
	if(this == &mt) return *this;
	for(int i=0;i<dong;i++) {
		delete[] data[i];
	}
	delete[] data;
	
	dong = mt.dong;
	cot = mt.cot;
	
	data = new int*[dong];
	
	for(int i=0;i<dong;i++) {
		data[i] = new int[cot];
		for(int j=0;j<cot;j++) {
			data[i][j] = mt.data[i][j];
		}
	}
	return *this;
}

bool maTran::operator ==(const maTran &mt) {
	if(dong !=mt.dong || cot != mt.cot) {
		return false;
	}
	
	for(int i=0;i<dong;i++) {
		for(int j=0;j<cot;j++) {
			if(data[i][j] != mt.data[i][j])
				return false;
		}
	}
	return true;
} 

int main() {
	maTran a(2,2);
	a.nhap();
	a.xuat();
	a.dinhThuc()
;	maTran b(2,2);
	b.nhap();
	b.xuat();
	maTran c;
	c = a+b;
	c.xuat();
	maTran d= a-b;
	d.xuat();
	maTran e=a*b;
	e.xuat();
}