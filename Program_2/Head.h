#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;

//funkcja odczytuj�ca dane wej�ciowe z pliku tekstowego
int odczyt_z_pliku(int &M_max, vector<string>&przedmiot, vector<int>&masa, vector<int>&cena, int &ilosc, string nazwa_pliku);

//funkcja rozwi�zuj�ca problem plecakwy za pomoc� programowania dynamicznego
int programowanie_dynamiczne(int &M_max, vector<string>&przedmiot, vector<int>&masa, vector<int>&cena, int &ilosc);

#endif
