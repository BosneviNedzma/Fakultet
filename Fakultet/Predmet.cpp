#include "Predmet.h"
#include <iostream>
#include <cstring>
using namespace std;

Predmet::Predmet() {

}

Predmet::Predmet(const char* n, int o) {
	strcpy(this->naziv, n);
	this->ocjena = o;
}

void Predmet::setOcjena() {
	cout << "Unesite ocjenu: ";
	cin >> this->ocjena;
	cin.ignore();
}

istream &operator>>(istream& ostream, Predmet& p) {
	p.setNaziv();
	p.setOcjena();
	return stream;
}

ostream& operator<<(ostream& stream, Predmet& p) {
	stream << p.getNaziv() << " - (" << p.getOcjena() << ")";
	return stream;
}

Predmet::Predmet(const Predmet& p) {
	strcpy(this->naziv, p.naziv);
	this->ocjena = p.ocjena;
}

