#include <iostream>
#include <fstream>

using namespace std;

class zadanie1{
	ifstream we;
	ofstream wy;
	
	public:
		zadanie1();
		~zadanie1();
		void wczytaj();
};

zadanie1::zadanie1() {
	we.open("dane_ulamki.txt");
	wy.open("wyniki_ulamki.txt");
}

void zadanie1::wczytaj() {
 	double licznik, mianownik;
 	double min, min_licznik, min_mianownik;
	if(we.good()) {
		we>>licznik;
		we>>mianownik;	
		min = licznik/mianownik;
		min_licznik = licznik;
		min_mianownik = mianownik;
		while(!we.eof()) {
			we>>licznik;
			we>>mianownik;	
			if(licznik/mianownik<min) {
				min = licznik/mianownik;
				min_licznik = licznik;
				min_mianownik = mianownik;
			}
			if(licznik/mianownik==min) {
				if(mianownik<=min_mianownik) {
					min_licznik = licznik;
					min_mianownik = mianownik;
				}
			}
		}
		cout<<"Zadanie 65.1: "<<min_licznik<<" "<<min_mianownik;
		wy<<"Zadanie 65.1: "<<min_licznik<<" "<<min_mianownik;
	}
}
	
zadanie1::~zadanie1() {
	we.close();
	wy.close();
}

int main(int argc, char** argv) {
	zadanie1 z1;
	z1.wczytaj();
	
	return 0;
}
