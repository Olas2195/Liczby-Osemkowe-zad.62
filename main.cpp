#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class zadanie2{
	ifstream we;
	vector <string> obraz;
	
	public:
		zadanie2();
		~zadanie2();
		void wczytaj();
		vector <int> rozklad(int);
		bool nieskracalne(vector <int>, vector<int>);
};

zadanie2::zadanie2() {
	we.open("dane_ulamki.txt");
}

void zadanie2::wczytaj() {
	vector <int> czynniki1;
	vector <int> czynniki2;
 	int liczba1, liczba2;
 	int ilosc_nieskracalne=0;
	if(we.good()) {
		while(!we.eof()) {
			we>>liczba1;
			czynniki1 = rozklad(liczba1);
			we>>liczba2;
			czynniki2 = rozklad(liczba2);	
			if(nieskracalne(czynniki1, czynniki2)) {
				ilosc_nieskracalne++;
			}
		}
		cout<<"Zadanie 65.2: "<<ilosc_nieskracalne<<"\n";
	}
}
	
vector <int> zadanie2::rozklad(int liczba) {
	vector <int> czynniki;
		for (int i=2; i<=liczba; i++) {
	   		while (liczba%i == 0) {
	        	liczba/=i;
	        	czynniki.push_back(i);
	    	}
	 	}
	return czynniki;
}

bool zadanie2::nieskracalne(vector <int> czynniki1, vector <int> czynniki2) {
	for (int i=0; i<czynniki1.size(); i++) {
		for (int j=0; j<czynniki2.size(); j++) {
			if(czynniki1[i]==czynniki2[j]) {
				return false;
			}
		}
	}
	return true;
}

zadanie2::~zadanie2() {
	we.close();
}

int main(int argc, char** argv) {
	zadanie2 z2;
	z2.wczytaj();
	
	return 0;
}

