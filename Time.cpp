#include<iostream>
using namespace std;

class Time {
	private:
		int hours,minutes,second;
		void normalize();
	public:
		Time(int hours=0,int minutes=0,int second=0);
		Time operator + (int sec);
		Time& operator ++ ();
		Time operator ++(int);
		friend istream& operator >> (istream &is, Time &t);
		friend ostream& operator << (ostream &os, Time &t);
};

void Time::normalize() {
	if(second >=60) {
		minutes += second / 60;
		second %= 60;
	}
	
	if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        hours %= 24;
    }
}

Time::Time(int hours, int minutes, int second) {
	this->hours = hours;
	this->minutes = minutes;
	this->second = second;
	this->normalize();
}

Time Time::operator +(int sec) {
	Time tmp(hours, minutes,second);
	tmp.second += sec;
	tmp.normalize();
	return tmp;
}

Time& Time::operator ++() {
	second++;
	normalize();
	return *this;
}

Time Time::operator ++(int) {
	Time tmp = *this;
	second++;
	normalize();
	return tmp;
}

istream& operator >> (istream &is,Time &t) {
	cout<<"Nhap gio: "; is>>t.hours;
	cout<<"Nhap phut: "; is>>t.minutes;
	cout<<"Nhap giay: "; is>>t.second;
	t.normalize();
	return is;
}

ostream& operator << (ostream &os,Time &t) {
	os << (t.hours < 10 ? "0" : "") << t.hours << ":"
	   << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
	   << (t.second < 10 ? "0" : "") << t.second;
	return os;
}

int main() {
	Time t1;
    cin >> t1;

    cout << "Thoi gian vua nhap: " << t1 << endl;

    Time t2 = t1 + 75; 
    cout << "Cong 75 giay: " << t2 << endl;

    ++t1; 
    cout << "Tang 1 giay: " << t1 << endl;

    t1++; 
    cout << "Tang 1 giay: " << t1 << endl;

    return 0;
}