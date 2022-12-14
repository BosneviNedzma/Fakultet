#pragma once
#include <vector>
#include "Predmet.h"

using namespace std;
enum Godina{prva=1, druga, treca, cetvrta, peta};

class Student {
private:
	char ime[20], prezime[30];
	int brIndeksa;
	vector<Predmet>predmeti;
	Godina godina;

public:
	Student();
	Student(const char* i, const char* p, int b, Godina g);
	Student(const Student& s);
	void setIme();
	void setPrezime();
	void setBrIndeksa();
	void setGodina();
	void setPredmet();
	char* getIme();
	char* getPrezime();
	int getBrIndeksa();
	Godina getGodina();
	vector<Predmet>& getPredmeti();
	friend istream& operator>>(istream& stream, Student& s);
	friend ostream& operator<<(ostream& stream, Student& s);
	void operator++();
	void operator++(int);
	friend float operator!(Student& s);
	void operator^(int n);
	static string getGodinaString(Godina x) {
		switch (x) {
		case prva:
			return "Prva.\n";
		case druga:
			return "Druga.\n";
		case treca:
			return "Treca.\n";
		case cetvrta:
			return "Cetvrta.\n";
		case peta:
			return "Peta.\n";
		case default:
			return "Diplomirao.\n";
		
		}
		~Student() = default;
	}
};
