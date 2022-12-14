#include <iostream>
#include <iomanip>
#include "Student.h"

int main() {
	Student s;
	cin >> s;
	cout << s;
	cout << "\nProsjek: " << setprecision(2) << fixed << !s << endl;
	int x;
	cout << "Uensite redni broj predmeta koji zelite obrisati: ";
	cin >> x;
	cin.ignore();
	s^ x;
	cout << s;

	return 0;
}