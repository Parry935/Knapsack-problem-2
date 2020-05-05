#include "pch.h"
#include "Head.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

int odczyt_z_pliku(int & M_max, vector<string>&przedmiot, vector<int>& masa, vector<int>& cena, int & ilosc, string nazwa_pliku)
{
	fstream file;
	file.open(nazwa_pliku.c_str(), ios::in);
	if (file.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
		exit(0);
	}


	file >> M_max;
	string  linia;
	int dana;

	while (!file.eof()) //wykonuj dopóki plik nie jest pusty
	{

		file >> linia;
		przedmiot.push_back(linia);

		file >> dana;
		masa.push_back(dana);

		file >> dana;
		cena.push_back(dana);


		ilosc++;
	}

	file.close();

	return 0;
}


int programowanie_dynamiczne(int & M_max, vector<string>&przedmiot, vector<int>& masa, vector<int>& cena, int & ilosc)
{
	vector<vector<int>> Pij(ilosc+1, vector<int>(M_max+1, 0)); //stworzenie tablicy P_ij wype³nionej zerami
	vector<vector<int>> Qij(ilosc+1, vector<int>(M_max+1, 0)); //stworzenie tablicy Q_ij wype³nionej zerami

	for (int i = 1; i < ilosc+1; i++) //pêtla wykonuj¹ca siê po wszystkich przedmiotach
	{
		for (int j = 1; j < M_max+1; j++) //pêtla wykonuj¹ca siê po wszystkich wagach
		{
				if (masa[i-1] <= j) //sprawdzenie czy masa przedmiotu jest mniejsza lub równa od okreœlonej wagi
				{
					if (Pij[i - 1][j] < Pij[i][j - masa[i-1]] + cena[i-1]) //sprawdzenie czy upakowanie z nowym przedmiotem jest najelpsze
					{
						Pij[i][j] = Pij[i][j - masa[i-1]] + cena[i-1];  //jeœli tak, zmieñ najlepsze upakowanie
						Qij[i][j] = i;
					}

					else
					{
							Pij[i][j] = Pij[i - 1][j];  //jeœli nie, pozostaw najlepsze upakowanie
							Qij[i][j] = Qij[i - 1][j];
					}

				}

				else
				{
						Pij[i][j] = Pij[i - 1][j];  //jeœli przedmiot nie mieœci siê w okreœlonej wadze pozostaw najlepsze upakowanie
						Qij[i][j] = Qij[i - 1][j];
				}


		}

	}

	//wypisanie tablicy P_ij i Q_ij
	
	cout << endl << "TABLICA P_ij: " << endl << endl;

	cout << "  J       ";

	for (int i = 0; i < M_max; i++)
	{
			if (i + 1 < 10)
				cout << i + 1 << "    ";

			if (i + 1 >= 10)
				cout << i + 1 << "   ";
	}

	cout << endl << "I" << endl << endl << "     ";
		
	
	for (int i = 0; i < ilosc+1; i++)
	{
		if (i != 0)
		{
			if (i + 1 < 10)
				cout << i << "    ";

			if (i + 1 >= 10)
				cout << i << "   ";
		}

		for (int j = 0; j < M_max+1; j++)
		{
			if (Pij[i][j] < 10)
				cout << Pij[i][j] << "    ";

			if (Pij[i][j] >=10 && Pij[i][j] < 100)
				cout << Pij[i][j] << "   ";

			if (Pij[i][j] >= 100)
				cout << Pij[i][j] << "  ";
			 
		}
		cout << endl;
	}

	
	cout << endl << endl << "TABLICA Q_ij: " << endl << endl;

	cout << "  J       ";

	for (int i = 0; i < M_max ; i++)
	{
		if (i + 1 < 10)
			cout << i + 1 << "    ";

		if (i + 1 >= 10)
			cout << i + 1 << "   ";
	}

	cout << endl << "I" << endl << endl << "     ";

	for (int i = 0; i < ilosc+1; i++)
	{
		if (i != 0)
		{
			if (i + 1 < 10)
				cout << i << "    ";

			if (i + 1 >= 10)
				cout << i << "   ";
		}

		for (int j = 0; j < M_max + 1; j++)
		{
			if (Qij[i][j] < 10)
				cout << Qij[i][j] << "    ";

			if (Qij[i][j] >= 10 && Qij[i][j] < 100)
				cout << Qij[i][j] << "   ";

			if (Qij[i][j] >= 100)
				cout << Qij[i][j] << "  ";

		}
		cout << endl;
	}
	
	return 0;
}
