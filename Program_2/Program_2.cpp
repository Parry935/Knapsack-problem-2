// Pepaś Dominik - 11:00

#include "pch.h"
#include "Head.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	string nazwa_piku;
	int M_max = 0;
	vector<string> przedmiot;
	vector <int> masa;
	vector <int> cena;
	int ilosc = 0;

	cout << "Podaj nazwe pliku z ktorego chcesz odczytac dane: " << endl;
	cin >> nazwa_piku;

	odczyt_z_pliku(M_max, przedmiot, masa, cena, ilosc, nazwa_piku);

	programowanie_dynamiczne(M_max, przedmiot, masa, cena, ilosc);


	return 0;
}

