#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class zadanie62 {
	ifstream plik8;
	ifstream plik10;
	ofstream wyniki;
	
	public:
		zadanie62();
		~zadanie62();
		void zadanie1();
		void zadanie2();
		void zadanie3();
		
};

zadanie62::zadanie62() {
	plik8.open("liczby1.txt");
	plik10.open("liczby2.txt");
	wyniki.open("wyniki.txt");
	
	if(plik8.good()) {
		while(!plik8.eof()) {
			
		}
	}
}
void zadanie62::zadanie1() {
	int x;
	int min;
	int max;
	if(plik8.good()) {
		plik8>>x;
		max = x;
		min = x;
		while(!plik8.eof()) {
			plik8>>x;
			if(x>max) {
				max = x;
			}else {
				if(x<min) {
					min = x;
				}
			}
		}
	}
	cout<<"Zadanie 1.\nmin: "<<min<<"\nmax: "<<max<<"\n\n";
	wyniki<<"Zadanie 1.\nmin: "<<min<<"\nmax: "<<max<<"\n\n";
}

void zadanie62::zadanie2() {
	int pierwszy[15];
	int ilosc[15];
	int x, y;
	int max=0;
	int maxi;
	int i=1;
	if(plik10.good()) {
		ilosc[i]=1;
		while(!plik10.eof()) {
			if(ilosc[i]==1) {
				plik10>>pierwszy[i]>>y;
			}
			plik10>>x;
			if(x>y) {
				ilosc[i]++;
				y = x;
			}else {
				if(ilosc[i]>max) {
					max = ilosc[i];
					maxi = i;
					i++;
					ilosc[i]=1;
				}
			}
		}
	}
	cout<<"Zadanie 2.\npierwszy element: "<<pierwszy[maxi]<<"\nilosc: "<<max<<"\n\n";
	wyniki<<"Zadanie 2.\npierwszy element: "<<pierwszy[maxi]<<"\nilosc: "<<max<<"\n\n";
}

void zadanie62::zadanie3() {
	int dzies;
	int x;
	int i;
	int oct;
	int a=0;
	int b=0;
	if(plik10.good() && plik8.good()) {
		while(!plik10.eof() && !plik8.eof()) {
			int y=0;
			dzies = getline(plik10, );
			plik8>>x;
			
			while(x!=0)
	        {
                oct = oct + (x%10) * pow(8, y);
                y++;
                x=x/10;
	        }
	        cout<<dzies<<" "<<oct<<"\n";
			if(dzies==oct) {
				a++;
			}else{
				if(oct>dzies) {
					b++;
				}
			}
		}
	}
	cout<<"Zadanie 3.\na) "<<a<<"\nb) "<<b<<"\n\n";
	wyniki<<"Zadanie 3.\na) "<<a<<"\nb) "<<b<<"\n\n";
}

zadanie62::~zadanie62() {
	plik8.close();
	plik10.close();
	wyniki.close();
}

int main(int argc, char** argv) {
	zadanie62 z;
	z.zadanie1();
	z.zadanie2();
	z.zadanie3();
	return 0;
}
