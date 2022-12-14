#pragma once
#include <istream>

using namespace std;

class Predmet {
private:
	char naziv[50];
	int ocjena;

public:
	Predmet();
	Predmet(const char* n, int o);
	Predmet(const Predmet& p);
	void setNaziv();
	void setOcjena();
	char* getNaziv();
	int getOcjena();
	friend istream& operator>>(istream& stream, Predmet& p);
	friend ostream& operator<<(ostream& stream, Predmet& p);
	~Predmet() = default;
};