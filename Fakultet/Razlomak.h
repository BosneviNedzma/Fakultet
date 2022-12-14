#pragma once
#include <iostream>

class Razlomak {
private:
	int brojnik, nazivnik;

public:
	Razlomak() { this->brojnik = 0; this->nazivnik = 1; }
	Razlomak(int a, int b) {
		this->brojnik = a;
		if (b == 0) {
			b = 1;
			cout << "Nazivnik ne moze biti nula!\n";
			cout << "Nazivnik je postavljen da bude 1!\n";
		}
		this->nazivnik = b;
	}
	Razlomak(int a) { this->brojnik = 1; this->nazivnik = 1 }
	void setBrojnik() {
		cout << "Unesite brojnik: ";
		cin >> this->brojnik;
	}

	void setNazivnik() {
		do {
			cout << "Unesite nazivnik: ";
			cin >> this->nazivnik;
		} while (this->nazivnik == 0);
	}
	int getBrojnik() {
		return this->brojnik;
	}

	int getNazivnik() {
		return this->nazivnik;
	}

	void pojednostavni() {
		int a, b;
		a = abs(this->brojnik);
		b = abs(this->nazivnik);
		while (a != b) {
			if (a > b) {
				a -= b;
			}
			else {
				b -= a;
			}
		}
		this->brojnik /= a;
		this->nazivnik /= a;
		if (this->nazivnik < 0) {
			this->brojnik *= -1;
			this->nazivnik *= -1;
		}
	}

	friend istream& operator>>(istream& stream, Razlomak& r) {
		r.setBrojnik();
		r.setNazivnik();
		return stream;
	}

	friend ostream& operator<<(ostream& stream, Razlomak& r) {
		r.pojednostavni();
		stream << r.getBrojnik() << "/" << r.getNazivnik();
		return stream;
	}
	Razlomak& operator= (const Razlomak& r) {
		this->brojnik = r.brojnik;
		this->nazivnik = r.nazivnik;
		return *this:
	}

	friend Razlomak operator+(Razlomak& r1, Razlomak& r2) {
		Razlomak rez;
		rez.nazivnik = r1.nazivnik * r2.nazivnik;
		rez.brojnik = r1.brojnik * r2.nazivnik + r2.brojnik * r1.nazivnik;
		rez.pojednostavni();
		return rez;
	}

	friend Razlomak operator-(Razlomak& r1, Razlomak& r2) {
		Razlomak rez;
		rez.nazivnik = r1.nazivnik * r2.nazivnik;
		rez.brojnik = r1.brojnik * r2.nazivnik - r2.brojnik * r1.nazivnik;
		rez.pojednostavni();
		return rez;
	}
	void operator++() {
		this->brojnik++;
	}

	void operator++(int) {
		this->brojnik += 5;
	}

	Razlomak operator!() {
		Razlomak rez;
		rez.brojnik = this->nazivnik;
		rez.nazivnik = this->brojnik;
		rez.pojednostavni();
		return rez;
	}

	~Razlomak() = default;
};
